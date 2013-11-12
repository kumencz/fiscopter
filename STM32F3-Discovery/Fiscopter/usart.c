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
#define RINGBUF_SIZE 50
volatile uint8_t USART1_ringbuf[RINGBUF_SIZE];
volatile uint32_t USART1_readidx = 0;
volatile uint32_t USART1_writeidx = 0;

void USART_puts(USART_TypeDef* USARTx, char *s)
{
	while(*s){
		// wait until data register is empty
		while( !(USARTx->ISR & 0x00000040) ); 
		USART_SendData(USARTx, *s);
		*s++;
	}
}

