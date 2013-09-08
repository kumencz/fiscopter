/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "init.h"
#include "pwm.h"
#include "delay.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
#define BSRR_VAL 0xC000
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
GPIO_InitTypeDef        GPIO_InitStructure;
void calib(void);

/**
  * @brief  Main program.
  * @param  None 
  * @retval None
  */
int main(void)
{  
  int cnt = 2000;
	//calib();
	init_ALL();
	
	PWM_SetDC(1,4000);
	Delay(3000);
	PWM_SetDC(1,2000);
	Delay(2000);
	PWM_SetDC(1,3);
	Delay(3000);

while(1)
{
	if(cnt < 3000)
		{
			cnt ++;
			PWM_SetDC(1,cnt);
			PWM_SetDC(2,cnt);
			PWM_SetDC(3,cnt);
			Delay(10);
		}else
		{
			PWM_SetDC(1,0);
			PWM_SetDC(2,0);
			PWM_SetDC(3,0);
		}
		
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
