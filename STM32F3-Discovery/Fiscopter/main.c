/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "init.h"
#include "programs.h"
#include "usart.h"
#include "PID.h"
#include "motors.h"
#include "time.h"
#include "imu.h"
#include "stm32f3_discovery.h"
#include "math.h"

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
	
	
	//----------calibrate ESC---------------
	STM_EVAL_LEDOn(LED8);
	ESC_Calibrate_All();
	STM_EVAL_LEDOff(LED8);
	//----------calibrate ESC---------------
	
	//----------motor test---------------
	//STM_EVAL_LEDOn(LED9);
  //test_motors(1000);
	//STM_EVAL_LEDOff(LED9);
	//----------motor test---------------
	
	//SetTunings(0.5,0.4,0.3);
	read_imu();
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
