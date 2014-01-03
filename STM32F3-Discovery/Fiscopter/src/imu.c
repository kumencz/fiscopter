/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define L3G_Sensitivity_250dps     (float)    114.285f        /*!< gyroscope sensitivity with 250 dps full scale [LSB/dps] */
#define L3G_Sensitivity_500dps     (float)    57.1429f        /*!< gyroscope sensitivity with 500 dps full scale [LSB/dps] */
#define L3G_Sensitivity_2000dps    (float)    14.285f	        /*!< gyroscope sensitivity with 2000 dps full scale [LSB/dps] */

#define LSM_Acc_Sensitivity_2g     (float)     1.0f            /*!< accelerometer sensitivity with 2 g full scale [LSB/mg] */
#define LSM_Acc_Sensitivity_4g     (float)     0.5f            /*!< accelerometer sensitivity with 4 g full scale [LSB/mg] */
#define LSM_Acc_Sensitivity_8g     (float)     0.25f           /*!< accelerometer sensitivity with 8 g full scale [LSB/mg] */
#define LSM_Acc_Sensitivity_16g    (float)     0.0834f         /*!< accelerometer sensitivity with 12 g full scale [LSB/mg] */

#define PI                         (float)     3.14159265f
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
float MagBuffer[3] = {0.00f}, AccBuffer[3] = {0.00f}, Buffer[3] = {0.00f};
int Xval, Yval, Zval = 0x00;
__IO uint32_t UserButtonPressed = 0;

float fNormAcc,fNormMag,fSinRoll,YawAng = 0.0f, RollAng = 0.0f, PitchAng = 0.0f;
float Xrot, Yrot, Zrot;
float gyrXangle, gyrYangle, gyrZangle;
float accXangle, accYangle, accZangle;
float magXangle, magYangle, magZangle;

float time;
long int counter, counter_old; 

int u = 0;

int reload_gyro = 1000;
int gyro_cnt;
int millis;




void Gyro_ReadAngRate (float* pfData)
{
  uint8_t tmpbuffer[6] ={0};
  int16_t RawData[3] = {0};
  uint8_t tmpreg = 0;
  float sensitivity = 0;
  int i =0;

  L3GD20_Read(&tmpreg,L3GD20_CTRL_REG4_ADDR,1);
  
  L3GD20_Read(tmpbuffer,L3GD20_OUT_X_L_ADDR,6);
  
  /* check in the control register 4 the data alignment (Big Endian or Little Endian)*/
  if(!(tmpreg & 0x40))
  {
    for(i=0; i<3; i++)
    {
      RawData[i]=(int16_t)(((uint16_t)tmpbuffer[2*i+1] << 8) + tmpbuffer[2*i]);
    }
  }
  else
  {
    for(i=0; i<3; i++)
    {
      RawData[i]=(int16_t)(((uint16_t)tmpbuffer[2*i] << 8) + tmpbuffer[2*i+1]);
    }
  }
  
  /* Switch the sensitivity value set in the CRTL4 */
  switch(tmpreg & 0x30)
  {
  case 0x00:
    sensitivity=L3G_Sensitivity_250dps;
    break;
    
  case 0x10:
    sensitivity=L3G_Sensitivity_500dps;
    break;
    
  case 0x20:
    sensitivity=L3G_Sensitivity_2000dps;
    break;
  }
  /* divide by sensitivity */
  for(i=0; i<3; i++)
  {
    pfData[i]=(float)RawData[i]/sensitivity;
  }
}


void Acc_ReadAcc(float* pfData)
{
  int16_t pnRawData[3];
  uint8_t ctrlx[2];
  uint8_t accbuffer[6], cDivider;
  uint8_t i = 0;
  float LSM_Acc_Sensitivity = LSM_Acc_Sensitivity_2g;
  
  /* Read the register content */
  LSM303DLHC_Read(ACC_I2C_ADDRESS, LSM303DLHC_CTRL_REG4_A, ctrlx,2);
  LSM303DLHC_Read(ACC_I2C_ADDRESS, LSM303DLHC_OUT_X_L_A, accbuffer, 6);
   
  if(ctrlx[1]&0x40)
    cDivider=64;
  else
    cDivider=16;

  /* check in the control register4 the data alignment*/
  if(!(ctrlx[0] & 0x40) || (ctrlx[1] & 0x40)) /* Little Endian Mode or FIFO mode */
  {
    for(i=0; i<3; i++)
    {
      pnRawData[i]=((int16_t)((uint16_t)accbuffer[2*i+1] << 8) + accbuffer[2*i])/cDivider;
    }
  }
  else /* Big Endian Mode */
  {
    for(i=0; i<3; i++)
      pnRawData[i]=((int16_t)((uint16_t)accbuffer[2*i] << 8) + accbuffer[2*i+1])/cDivider;
  }
  /* Read the register content */
  LSM303DLHC_Read(ACC_I2C_ADDRESS, LSM303DLHC_CTRL_REG4_A, ctrlx,2);


  if(ctrlx[1]&0x40)
  {
    /* FIFO mode */
    LSM_Acc_Sensitivity = 0.25;
  }
  else
  {
    /* normal mode */
    /* switch the sensitivity value set in the CRTL4*/
    switch(ctrlx[0] & 0x30)
    {
    case LSM303DLHC_FULLSCALE_2G:
      LSM_Acc_Sensitivity = LSM_Acc_Sensitivity_2g;
      break;
    case LSM303DLHC_FULLSCALE_4G:
      LSM_Acc_Sensitivity = LSM_Acc_Sensitivity_4g;
      break;
    case LSM303DLHC_FULLSCALE_8G:
      LSM_Acc_Sensitivity = LSM_Acc_Sensitivity_8g;
      break;
    case LSM303DLHC_FULLSCALE_16G:
      LSM_Acc_Sensitivity = LSM_Acc_Sensitivity_16g;
      break;
    }
  }

  /* Obtain the mg value for the three axis */
  for(i=0; i<3; i++)
  {
    pfData[i]=(float)pnRawData[i]/LSM_Acc_Sensitivity;
  }

}


void Compass_ReadMag (float* pfData)
{
  static uint8_t buffer[6] = {0};
  uint8_t CTRLB = 0;
  uint16_t Magn_Sensitivity_XY = 0, Magn_Sensitivity_Z = 0;
  uint8_t i =0;
  LSM303DLHC_Read(MAG_I2C_ADDRESS, LSM303DLHC_CRB_REG_M, &CTRLB, 1);
  
  LSM303DLHC_Read(MAG_I2C_ADDRESS, LSM303DLHC_OUT_X_H_M, buffer, 1);
  LSM303DLHC_Read(MAG_I2C_ADDRESS, LSM303DLHC_OUT_X_L_M, buffer+1, 1);
  LSM303DLHC_Read(MAG_I2C_ADDRESS, LSM303DLHC_OUT_Y_H_M, buffer+2, 1);
  LSM303DLHC_Read(MAG_I2C_ADDRESS, LSM303DLHC_OUT_Y_L_M, buffer+3, 1);
  LSM303DLHC_Read(MAG_I2C_ADDRESS, LSM303DLHC_OUT_Z_H_M, buffer+4, 1);
  LSM303DLHC_Read(MAG_I2C_ADDRESS, LSM303DLHC_OUT_Z_L_M, buffer+5, 1);
  /* Switch the sensitivity set in the CRTLB*/
  switch(CTRLB & 0xE0)
  {
  case LSM303DLHC_FS_1_3_GA:
    Magn_Sensitivity_XY = LSM303DLHC_M_SENSITIVITY_XY_1_3Ga;
    Magn_Sensitivity_Z = LSM303DLHC_M_SENSITIVITY_Z_1_3Ga;
    break;
  case LSM303DLHC_FS_1_9_GA:
    Magn_Sensitivity_XY = LSM303DLHC_M_SENSITIVITY_XY_1_9Ga;
    Magn_Sensitivity_Z = LSM303DLHC_M_SENSITIVITY_Z_1_9Ga;
    break;
  case LSM303DLHC_FS_2_5_GA:
    Magn_Sensitivity_XY = LSM303DLHC_M_SENSITIVITY_XY_2_5Ga;
    Magn_Sensitivity_Z = LSM303DLHC_M_SENSITIVITY_Z_2_5Ga;
    break;
  case LSM303DLHC_FS_4_0_GA:
    Magn_Sensitivity_XY = LSM303DLHC_M_SENSITIVITY_XY_4Ga;
    Magn_Sensitivity_Z = LSM303DLHC_M_SENSITIVITY_Z_4Ga;
    break;
  case LSM303DLHC_FS_4_7_GA:
    Magn_Sensitivity_XY = LSM303DLHC_M_SENSITIVITY_XY_4_7Ga;
    Magn_Sensitivity_Z = LSM303DLHC_M_SENSITIVITY_Z_4_7Ga;
    break;
  case LSM303DLHC_FS_5_6_GA:
    Magn_Sensitivity_XY = LSM303DLHC_M_SENSITIVITY_XY_5_6Ga;
    Magn_Sensitivity_Z = LSM303DLHC_M_SENSITIVITY_Z_5_6Ga;
    break;
  case LSM303DLHC_FS_8_1_GA:
    Magn_Sensitivity_XY = LSM303DLHC_M_SENSITIVITY_XY_8_1Ga;
    Magn_Sensitivity_Z = LSM303DLHC_M_SENSITIVITY_Z_8_1Ga;
    break;
  }
  
  for(i=0; i<2; i++)
  {
    pfData[i]=(float)((int16_t)(((uint16_t)buffer[2*i] << 8) + buffer[2*i+1])*1000)/Magn_Sensitivity_XY;
  }
  pfData[2]=(float)((int16_t)(((uint16_t)buffer[4] << 8) + buffer[5])*1000)/Magn_Sensitivity_Z;
}






uint32_t LSM303DLHC_TIMEOUT_UserCallback(void)
{
  return 0;
}
uint32_t L3GD20_TIMEOUT_UserCallback(void)
{
  return 0;
}

//Kalmanov filtr - asi nefunguje jak má :) potrebuje predelat
//------------------------------------------
/*float Q_angle  =  0.001; //0.001
float Q_gyro   =  0.003;  //0.003
float R_angle  =  0.03;  //0.03

float x_angle = 0;
float x_bias = 0;
float P_00 = 0, P_01 = 0, P_10 = 0, P_11 = 0;
float dt, y, S;
float K_0, K_1;

float kalmanCalculate(float newAngle, float newRate,float looptime)
{
    dt = looptime/1000000;
    x_angle += dt * (newRate - x_bias);
    P_00 +=  - dt * (P_10 + P_01) + Q_angle * dt;
    P_01 +=  - dt * P_11;
    P_10 +=  - dt * P_11;
    P_11 +=  + Q_gyro * dt;

    y = newAngle - x_angle;
    S = P_00 + R_angle;
    K_0 = P_00 / S;
    K_1 = P_10 / S;

    x_angle +=  K_0 * y;
    x_bias  +=  K_1 * y;
    P_00 -= K_0 * P_00;
    P_01 -= K_0 * P_01;
    P_10 -= K_1 * P_00;
    P_11 -= K_1 * P_01;

		return x_angle;
}*/

void read_imu(void)
{
	gyrXangle = 0.0f;
	gyrYangle = 0.0f;
	gyrZangle = 0.0f;
		
	while (1)
    {    
			if(gyro_cnt > reload_gyro)
			{
				gyrXangle = Xrot - 1;
				gyrYangle = Yrot - 1;
				gyro_cnt = 0;
			}
			
			
			/* Read Acc */
			Acc_ReadAcc(AccBuffer);
			for(u=0;u<3;u++) AccBuffer[u] /= 100.0f;
      fNormAcc = sqrt((AccBuffer[0]*AccBuffer[0])+(AccBuffer[1]*AccBuffer[1])+(AccBuffer[2]*AccBuffer[2]));
      
			accXangle = ((acos(AccBuffer[0]/fNormAcc))*180/PI)-90;
			accYangle = ((acos(AccBuffer[1]/fNormAcc))*180/PI)-90;
			accZangle = ((acos(AccBuffer[2]/fNormAcc))*180/PI)-90;
			
			/* Read Gyro */
			Gyro_ReadAngRate(Buffer);
         
			gyrXangle = gyrXangle + ((Buffer[0]*time));
			gyrYangle = gyrYangle + ((Buffer[1]*time));
			gyrZangle = gyrZangle + ((Buffer[2]*time));
			
			/* Read Mag */
			Compass_ReadMag(MagBuffer);
			
			/* Filter */
			Xrot = 0.98 *(Xrot+Buffer[0]*time) + 0.02*accXangle;
			Yrot = 0.98 *(Yrot+Buffer[1]*time) + 0.02*accYangle;
			Zrot = 0.98 *(Zrot+Buffer[2]*time) + 0.02*(gyrZangle/2);
			
			
		/*	if(gyrXangle > 180)
			{
				accXangle = 360 - (acos(AccBuffer[0]/fNormAcc))*180/PI ;
				if(gyrXangle > 270)
				{
					accXangle = -90-(acos(AccBuffer[0]/fNormAcc))*180/PI;
					gyrXangle = gyrXangle - 270;
				}
			}else if(gyrXangle < 0)
			{
				accXangle = -(acos(AccBuffer[0]/fNormAcc))*180/PI ;
				if(gyrXangle < -90)
				{
					accXangle = 90+(acos(AccBuffer[0]/fNormAcc))*180/PI;
					gyrXangle = 90+(gyrXangle + 90);
				}
			}else
			{
				accXangle = (acos(AccBuffer[0]/fNormAcc))*180/PI;
			}
			*/
			
			
			
			if(gyrYangle > 180)
			{
				accYangle = (360 - (acos(AccBuffer[1]/fNormAcc))*180/PI) ;
				if(gyrXangle > accXangle && gyrXangle > 335)
				{
					accYangle = 360+(acos(AccBuffer[1]/fNormAcc))*180/PI;
				}
			}
			else 
			{
				accYangle = (acos(AccBuffer[1]/fNormAcc))*180/PI;
			}
			
			


			
			sprintf(send, "|%f|%f|%f|%f|%f|%f|%f|%f|%f|\n", Xrot, Yrot, gyrZangle, MagBuffer[0], MagBuffer[1], MagBuffer[2], gyrXangle, gyrYangle, gyrZangle);
			//sprintf(send, "|%f|%f|%f|%f|%f|%f|%f|%f|%f|\n", Xrot, Yrot, Zrot, AccBuffer[0], AccBuffer[1], AccBuffer[2], gyrXangle, gyrYangle, gyrZangle);
			USART_puts(USART2, send); 
  
			/////PID
			/*
			if(UserButtonPressed != 0x00)
			{
				Setpoint = 50;
			}else
			{
				Setpoint = 0;
			}
			//if(Setpoint == Output)delete_it();
			Input = Output/1.5f;
			Compute();
			sprintf(send, "|%f|%f|%f|%f|%f|%f|%f|%f|%f|\n", Input, Output, Setpoint, accXangle, accYangle, accZangle, gyrXangle, gyrYangle, gyrZangle);
			USART_puts(USART2, send);			
			*/
			
			counter = TIM4->CNT;
			if(counter > counter_old)
			{
				time = (counter-counter_old)*0.0000005;
			}else if(counter < counter_old)
			{
				time = (50000-counter_old+counter)*0.0000005;
			}
			//Delay(5);
			counter_old = TIM4->CNT;
			gyro_cnt++;				
		}
	
}
