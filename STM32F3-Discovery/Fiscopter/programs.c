/* Includes ------------------------------------------------------------------*/
#include "programs.h"
#include "main.h"
#include "motors.h"
#include "time.h"
#include "usart.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
int cnt = 0;


void test_motors(int max_torgue)
{
	cnt = 0;
	while(cnt < max_torgue)
	{
		sprintf(send, "hhh: %d\n",cnt);
		USART_puts(USART2, send); 
		
		if(cnt < max_torgue-1)
		{
			STM_EVAL_LEDOn(LED3);
			cnt = cnt + 5;
			ESC_SetPower(1,cnt);
			ESC_SetPower(2,cnt);
			ESC_SetPower(3,cnt);
			ESC_SetPower(4,cnt);
			Delay(10);
		}else
		{
			STM_EVAL_LEDOff(LED3);
			ESC_SetPower(1,0);
			ESC_SetPower(2,0);
			ESC_SetPower(3,0);
			ESC_SetPower(4,0);
			Delay(3000);
		}
	}
}
