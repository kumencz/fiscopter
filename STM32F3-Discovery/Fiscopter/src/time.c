/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "PID.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint32_t TIM_1MS_COUNTER;
uint32_t TIM_10MS_COUNTER;
uint32_t TIM_100MS_COUNTER;
uint32_t TIM_1000MS_COUNTER;

uint8_t TIM_1MS_FLAG;
uint8_t TIM_10MS_FLAG;
uint8_t TIM_100MS_FLAG;
uint8_t TIM_1000MS_FLAG;
static __IO uint32_t TimingDelay;


void Delay(__IO uint32_t nTime)
{ 
  TimingDelay = nTime;

  while(TimingDelay != 0);
}

void Delay_tick(__IO uint32_t nCount)
{
	while(nCount--)
  {
  }
}

void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
}


void Period_timer_increment(void) //called each 1ms
{
	TIM_1MS_COUNTER++;
	TIM_10MS_COUNTER++;
	TIM_100MS_COUNTER++;
	TIM_1000MS_COUNTER++;
	
	if (TIM_1MS_COUNTER >= 1)
	{
		TIM_1MS_COUNTER = 0;
		TIM_1MS_FLAG = 1;
	}		
	if (TIM_10MS_COUNTER >= 10)
	{
		TIM_10MS_COUNTER = 0;
		TIM_10MS_FLAG = 1;
	}				
	if (TIM_100MS_COUNTER >= 100)
	{
		TIM_100MS_COUNTER = 0;
		TIM_100MS_FLAG = 1;
	}		
	if (TIM_1000MS_COUNTER >= 1000)
	{
		TIM_1000MS_COUNTER = 0;
		TIM_1000MS_FLAG = 1;
	}
}

void period_time_check_flags(void)
{
	if (TIM_1MS_FLAG) tim_1ms_loop();
	if (TIM_10MS_FLAG) tim_10ms_loop();
	if (TIM_100MS_FLAG) tim_100ms_loop();
	if (TIM_1000MS_FLAG) tim_1000ms_loop();
}

void tim_1ms_loop(void)
{
	TIM_1MS_FLAG = 0;

}

void tim_10ms_loop(void)
{
	TIM_10MS_FLAG = 0;	
	read_imu();
	Compute(x_wanted-RollAng,y_wanted-PitchAng);
	ESC_recompute();  //Recompute motor speeds
}

void tim_100ms_loop(void)
{ 
	TIM_100MS_FLAG = 0;
	if (live != 1)
		live_fail();
	live =0;	 
}

void tim_1000ms_loop(void)
{
	TIM_1000MS_FLAG = 0;
	STM_EVAL_LEDToggle(LED5);
}
