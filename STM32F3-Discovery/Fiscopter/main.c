/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "init.h"
#include "system_control.h"
#include "stm32f3_discovery.h"
#include "math.h"
#include "usart.h"
#include "PID.h"
#include "PID.h"

/* Private typedef -----------------------------------------------------------*/
GPIO_InitTypeDef        GPIO_InitStructure;
/* Private define ------------------------------------------------------------*/
#define PI                         (float)     3.14159265f
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
char send[50];
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

float MagBuffer[3] = {0.0f}, AccBuffer[3] = {0.0f}, Buffer[3] = {0.0f};
uint8_t Xval, Yval, Zval = 0x00;
__IO uint32_t UserButtonPressed = 0;
__IO uint8_t DataReady = 0;
__IO uint8_t PrevXferComplete = 1;
__IO uint32_t USBConnectTimeOut = 100;

float fNormAcc,fSinRoll,fCosRoll,fSinPitch,fCosPitch = 0.0f, RollAng = 0.0f, PitchAng = 0.0f;
float fTiltedX,fTiltedY = 0.0f;
float Xrot, Yrot, Zrot, Xrot2, Yrot2, Zrot2 = 0.00f;
float gyrXangle, gyrYangle, gyrZangle = 90.0f;
float accXangle, accYangle, accZangle = 0.0f;

float time, loop_time, last_loop_time = 0.000000f;
int32_t counter, counter_old, loop_start_time, curr_time; 

uint8_t u = 0;

int micros;
int reload_gyro = 1000;
int gyro_cnt;
int millis;
void calib(void);

/**
  * @brief  Main program.
  * @param  None 
  * @retval None
  */
int main(void)
{  
  //int cnt = 2000;
	//calib();
	init_ALL();
	SetTunings(0.5,0.4,0.3);
	/*STM_EVAL_LEDOn(LED8);
	ESC_SetPower(1,4000);
	Delay(3000);
	STM_EVAL_LEDOff(LED8);
	ESC_SetPower(1,2000);
	Delay(2000);
	ESC_SetPower(1,3);
	Delay(3000);

while(1)
{
	if(cnt < 3000)
		{
			cnt ++;
			ESC_SetPower(1,cnt);
			ESC_SetPower(2,cnt);
			ESC_SetPower(3,cnt);
			Delay(10);
		}else
		{
			ESC_SetPower(1,0);
			ESC_SetPower(2,0);
			ESC_SetPower(3,0);
		}
		
}
		*/
		gyrXangle = 0.0f;
		gyrYangle = 0.0f;
		gyrZangle = 0.0f;
		while (1)
    {    
			Acc_ReadAcc(AccBuffer);
      
			for(u=0;u<3;u++) AccBuffer[u] /= 100.0f;
      
      fNormAcc = sqrt((AccBuffer[0]*AccBuffer[0])+(AccBuffer[1]*AccBuffer[1])+(AccBuffer[2]*AccBuffer[2]));
      
			if(gyro_cnt > reload_gyro)
			{
				gyrXangle = Xrot - 1;
				gyrYangle = Yrot - 1;
				gyro_cnt = 0;
			}
			
			
			
			  /* Read Gyro Angular data */
			Gyro_ReadAngRate(Buffer);
         
			
			gyrXangle = gyrXangle + ((Buffer[0]*time));
			gyrYangle = gyrYangle + ((Buffer[1]*time));
			gyrZangle = gyrZangle + ((Buffer[2]*time));
			
			
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
			
			
			accXangle = ((acos(AccBuffer[0]/fNormAcc))*180/PI)-90;
			accYangle = ((acos(AccBuffer[1]/fNormAcc))*180/PI)-90;
			accZangle = ((acos(AccBuffer[2]/fNormAcc))*180/PI)-90;
			
			
			
			Xrot2 = kalmanCalculate(accXangle, Buffer[0], time);
			Yrot2 = kalmanCalculate(accYangle, Buffer[1], time);
			Zrot2 = kalmanCalculate(accZangle, Buffer[2], time);
			
			Xrot = 0.98 *(Xrot+Buffer[0]*time) + 0.02*accXangle;
			Yrot = 0.98 *(Yrot+Buffer[1]*time) + 0.02*accYangle;
			Zrot = 0.98 *(Zrot+Buffer[2]*time) + 0.02*accZangle;
			
			
			sprintf(send, "|%f|%f|%f|%f|%f|%f|%f|%f|%f|\n", Xrot, Yrot, Zrot, accXangle, accYangle, accZangle, gyrXangle, gyrYangle, gyrZangle);
			//sprintf(send, "|%f|%f|%f|%f|%f|%f|%f|%f|%f|\n", Xrot, Yrot, Zrot, AccBuffer[0], AccBuffer[1], AccBuffer[2], gyrXangle, gyrYangle, gyrZangle);
			USART_puts(USART2, send); 
     
			/*curr_time = TIM3->CNT;
			if(curr_time > loop_start_time)
			{
				loop_time = (curr_time - loop_start_time)*0.00000005;
			}else
			{
				loop_time = (50000-curr_time - loop_start_time)*0.00000005;
			}
			loop_start_time = TIM3->CNT;
			
		*/
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
			counter = TIM3->CNT;
			if(counter > counter_old)
			{
				time = (counter-counter_old)*0.0000005;
				millis += (counter-counter_old)*0.0005;
			}else if(counter < counter_old)
			{
				time = (50000-counter_old+counter)*0.0000005;
				millis += (50000-counter_old+counter)*0.0005;
			}
			//Delay(5);
			counter_old = TIM3->CNT;
			gyro_cnt++;
			/*if(millis > 5000)
			{
				delete_it();
				millis = 0;
				Output = 0;
				Input = 0;
			}*/
				
		}

}

void calib()
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);
  
  /* Configure PE14 and PE15 in output pushpull mode */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	GPIOE->BSRR = 15;
	Delay(2);
	GPIOE->BRR = 15;
	Delay(3000);
	GPIOE->BSRR = 15;
	Delay(1);
	GPIOE->BRR = 15;
	Delay(1000);
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
