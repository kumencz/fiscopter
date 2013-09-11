/* Includes ------------------------------------------------------------------*/
#include "stm32f30x_it.h"
#include "main.h"
#include "init.h"
#include "system_control.h"
#include "usart.h"
#include "stm32f30x_conf.h"
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stm32f30x.h>
#include <stm32f30x_usart.h>


/* Private typedef -----------------------------------------------------------*/
#define MAX_STRLEN 50 //maximum string length
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
///USARTS:::::::::::::::::::::::::::::::::::::::
char received_string2[MAX_STRLEN+1];
char received_string3[MAX_STRLEN+1];
char *rs;
static uint16_t cnt2 = 0; // USART2 input string length

extern __IO uint32_t UserButtonPressed;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
  TimingDelay_Decrement();
}

void USART2_IRQHandler(void)
{
	// check if the USART3 receive interrupt flag was set
	if( USART_GetITStatus(USART2, USART_IT_RXNE) ){
		
		char t = (USART_ReceiveData(USART2) & 0x7F); // the character from the USART3 data register is saved in t
		STM_EVAL_LEDOn(LED6);
		/* check if the received character is not the LF character (used to determine end of string) 
		 * or the if the maximum string length has been been reached 
		 */
		if( (t != '\n') && (cnt2 < MAX_STRLEN) ){ 
			received_string2[cnt2] = t;
			cnt2++;
		}
		else{ // otherwise reset the character counter and print the received string
			received_string2[cnt2] = '\0';
			cnt2 = 0;
			//STM_EVAL_LEDOn(LED3);

			rs = received_string2;				
		}
	}
}

/******************************************************************************/
/*                 STM32F30x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f30x.s).                                            */
/******************************************************************************/
/**
  * @brief  This function handles EXTI0_IRQ Handler.
  * @param  None
  * @retval None
  */

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

