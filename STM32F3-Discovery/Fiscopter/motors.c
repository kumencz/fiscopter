/* Includes ------------------------------------------------------------------*/
#include "motors.h"
#include "main.h"
#include "time.h"
#include "stm32f30x.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define ESC_min_pulse_ms 1
#define ESC_max_pulse_lenght 2
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/


void ESC_SetPower(uint16_t channel,uint16_t lenght)
{
	
  if (channel == 1)
  {
		//TIM_SetCompare1(TIM1, lenght);
    TIM1->CCR1 = lenght;
  }
  else if (channel == 2)
  {
		//TIM_SetCompare2(TIM1, lenght);
		TIM1->CCR2 = lenght;
  }
  else if (channel == 3)
  {
		//TIM_SetCompare3(TIM1, lenght);
		TIM1->CCR3 = lenght;
  }
  else 
  {
		//TIM_SetCompare4(TIM1, lenght);
		TIM1->CCR4 = lenght;
  }
}
void ESC_Calibrate_All(void)
{
	//set motors to maximum performance
	STM_EVAL_LEDOn(LED8);
	ESC_SetPower(1,4000);
	ESC_SetPower(2,4000);
	ESC_SetPower(3,4000);
	ESC_SetPower(4,4000);
	Delay(3000);
	//set motors to minimum performance
	STM_EVAL_LEDOff(LED8);
	ESC_SetPower(1,4000);
	ESC_SetPower(2,4000);
	ESC_SetPower(3,4000);
	ESC_SetPower(4,4000);
	Delay(2000);
}

