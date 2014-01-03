/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint16_t M1_speed, M2_speed, M3_speed, M4_speed;


void ESC_SetPower(uint16_t channel,int lenght) //!!!!! minimum = 0, maximum = 10000 !!!!!
{
	lenght = (lenght * ESC_koef) + ESC_min;
  if (channel == 1)
  {
		//TIM_SetCompare1(TIM1, lenght);
    TIM3->CCR1 = lenght;
  }
  else if (channel == 2)
  {
		//TIM_SetCompare2(TIM1, lenght);
		TIM3->CCR2 = lenght;
  }
  else if (channel == 3)
  {
		//TIM_SetCompare3(TIM1, lenght);
		TIM3->CCR3 = lenght;
  }
  else if (channel == 4)
  {
		//TIM_SetCompare4(TIM1, lenght);
		TIM3->CCR4 = lenght;
  }
}
void ESC_Calibrate_All(void)
{
	//set motors to maximum performance
	STM_EVAL_LEDOn(LED8);
	ESC_SetPower(1,0);
	ESC_SetPower(2,0);
	ESC_SetPower(3,0);
	ESC_SetPower(4,0);
	Delay(500);
	//set motors to minimum performance
	ESC_SetPower(1,10000);
	ESC_SetPower(2,10000);
	ESC_SetPower(3,10000);
	ESC_SetPower(4,10000);
	Delay(500);
	STM_EVAL_LEDOff(LED8);
	
	ESC_SetPower(1,0);
	ESC_SetPower(2,0);
	ESC_SetPower(3,0);
	ESC_SetPower(4,0);
	Delay(4000);
}

  void ESC_recompute(void)
{
	ESC_SetPower(1, (M1_speed + x_out + y_out));
	ESC_SetPower(2, (M2_speed + x_out + y_out_neg));
	ESC_SetPower(3, (M3_speed + x_out_neg + y_out_neg));
	ESC_SetPower(4, (M4_speed + x_out_neg + y_out));
}

