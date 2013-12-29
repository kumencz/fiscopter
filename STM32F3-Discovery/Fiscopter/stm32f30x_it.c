/* Includes ------------------------------------------------------------------*/
#include "stm32f30x_it.h"
#include "main.h"
#include "init.h"
#include "usart.h"
#include "time.h"
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
char *s1;
char *rs;
char *ps;
char strr;
static uint16_t cnt2 = 0; // USART2 input string length

extern __IO uint32_t UserButtonPressed;
__IO uint32_t i =0;
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
		STM_EVAL_LEDToggle(LED6);
		/* check if the received character is not the LF character (used to determine end of string) 
		 * or the if the maximum string length has been been reached 
		 */
		if( (t != '\n') && (cnt2 < MAX_STRLEN) ){ 
			received_string2[cnt2] = t;
			cnt2++;
		}
		else{ // otherwise reset the character counter and print the received string
			//received_string2[cnt2] = '\0';
			cnt2 = 0;
			//STM_EVAL_LEDOn(LED3);
			rs = received_string2;	
			s1 = "Router";		
			
			i = strcmp(s1, rs);		
			if(i == 0)					 
			{							
				USART_puts(USART2, "STM32F3\n");							
				STM_EVAL_LEDOn(LED4);
			} 
			
			//USART_puts(USART3, received_string3);
		
			/*ps = strtok(rs,"|");		
			
			while (ps != NULL)	
			{							 

					
					s1 = "c";		
					i = strcmp(s1, ps);		
					if(i == 0)					 
					{										
								ps = strtok (NULL, "/");
								while (ps != NULL)	
								{
									sscanf (ps, "%d", &candle[cnt]);
 									ps = strtok (NULL, "/");	
									cnt++;
								}
								if(first_candle == 1)
								{
									candle_saw = 1;
									candle_position(candle [0],candle [1]);
									STM_EVAL_LEDOn(LED6);
								}else first_candle = 1;
								cnt = 0;
					}
					s1 = "cn";		
					i = strcmp(s1, ps);		
					if(i == 0)					 
					{										
								candle_saw = 0;
								first_candle = 0;
								STM_EVAL_LEDOff(LED6);
					}
					ps = strtok (NULL, "|");	 
			}		*/
			
		}
	}
}
void EXTI0_IRQHandler(void)
{ 
  if ((EXTI_GetITStatus(USER_BUTTON_EXTI_LINE) == SET)&&(STM_EVAL_PBGetState(BUTTON_USER) != RESET))
  {
    /* Delay */
    for(i=0; i<0x7FFFF; i++);
    
    /* Wait for SEL button to be pressed  */
    while(STM_EVAL_PBGetState(BUTTON_USER) != RESET); 
    /* Delay */
    for(i=0; i<0x7FFFF; i++);
    UserButtonPressed++;
    
    if (UserButtonPressed > 0x1)
    {
      UserButtonPressed = 0x0;
    }
    
    /* Clear the EXTI line pending bit */
    EXTI_ClearITPendingBit(USER_BUTTON_EXTI_LINE);
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

