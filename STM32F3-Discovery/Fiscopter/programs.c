/* Includes ------------------------------------------------------------------*/
#include "programs.h"
#include "main.h"
#include "motors.h"
#include "time.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
int cnt = 2000;

void test_motors(int max_torgue)
{
	while(cnt < max_torgue)
	{
		if(cnt < max_torgue-1)
		{
			cnt ++;
			ESC_SetPower(1,cnt);
			ESC_SetPower(2,cnt);
			ESC_SetPower(3,cnt);
			ESC_SetPower(4,cnt);
			Delay(10);
		}else
		{
			ESC_SetPower(1,0);
			ESC_SetPower(2,0);
			ESC_SetPower(3,0);
			ESC_SetPower(4,0);
			Delay(3000);
		}
	}
}
