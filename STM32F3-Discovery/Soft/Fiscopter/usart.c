/* Includes ------------------------------------------------------------------*/
#include "usart.h"
#include "stm32f30x.h"
#include <stm32f30x_usart.h>
#include <string.h>
#include <stdio.h>

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void USART_puts(USART_TypeDef* USARTx, volatile char *s){

	/*while(*s){
		// wait until data register is empty
		while( !(USARTx->SR & 0x00000040) ); 
		USART_SendData(USARTx, *s);
		*s++;
	}*/
	
	/* Put character on the serial line */
  /*  USART2->TDR = (ch & (uint16_t)0x01FF);


    // Loop until transmit data register is empty 
    while ((USART2->ISR & USART_FLAG_TXE) == (uint16_t) RESET);


    return ch;*/
}


