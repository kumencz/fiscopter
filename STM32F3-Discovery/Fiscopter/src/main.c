/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define PI   (float)  3.14159265f
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void test(void);
/* Private functions ---------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/


void calib(void);

/**
  * @brief  Main program.
  * @param  None 
  * @retval None
  */
int main(void)
{  
	
	init_ALL();
	USART_puts(USART2, "System initialized\n");
	Delay(3000);
	
	//----------calibrate ESC---------------
	USART_puts(USART2, "ESC calibrating ...\n");
	ESC_Calibrate_All();
	
	/*USART_puts(USART2, "Test motors: 8000\n");
	while(1)
	{
		test_motors(8000);
	}*/
//	read_imu();
	//----------calibrate ESC---------------
	
	//----------motor test---------------
	//STM_EVAL_LEDOn(LED9);
  //test_motors(1000);
	//STM_EVAL_LEDOff(LED9);
	//----------motor test---------------
	
	//SetTunings(0.5,0.4,0.3);
//	read_imu();
	SetTunings(20, 50, 10);
	M1_speed = 3000;
	M2_speed = 3000;
	M3_speed = 3000; 
	M4_speed = 3000;
	ESC_recompute();
	/* ------ infinity loop ---------- */
	while (1)
	{
		period_time_check_flags();
		//read_imu();
	}
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
