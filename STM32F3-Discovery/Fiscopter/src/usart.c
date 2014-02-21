/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
#define RINGBUF_SIZE_TX 50
volatile uint8_t USART_ringbuf_tx[RINGBUF_SIZE_TX];
volatile uint32_t USART_readidx_tx = 0;	//ukazuje na následující k odeslání (klidne i zatim nenaplnenou)
volatile uint32_t USART_writeidx_tx = 0; //ukazuje na první volnou pozici v bufferu Tx pro zápis
volatile uint32_t USART_ToSend = 0;
char send[50];

void USART_puts(USART_TypeDef* USARTx, char *s)
{
	uint8_t USART_StartSendFlag = RESET;
	if (USART_ToSend == 0) USART_StartSendFlag = SET;
		
	while(*s)
	{
		if (USART_ToSend < RINGBUF_SIZE_TX)
		{
			USART_ringbuf_tx[USART_writeidx_tx] = *s;
			USART_writeidx_tx++;
			USART_ToSend++;
			if (USART_writeidx_tx >= RINGBUF_SIZE_TX) USART_writeidx_tx = 0;
			if (USART_StartSendFlag) 
			{				
				USART_SendData(USART2, USART_ringbuf_tx[USART_readidx_tx]);
				USART_readidx_tx++;
				if (USART_readidx_tx >= RINGBUF_SIZE_TX) USART_readidx_tx = 0; 
			}
		}
		else 
		{
			// Buffer je plný
		}
//		// wait until data register is empty
//		while( !(USARTx->ISR & 0x00000040) ); 
//		USART_SendData(USARTx, *s);
//		*s++;
	}
}

void USART_byte_sended(void)
{
	USART_ToSend--;
	if (USART_ToSend > 0)
	{
		USART_SendData(USART2, USART_ringbuf_tx[USART_readidx_tx]);
		USART_readidx_tx++;
		if (USART_readidx_tx >= RINGBUF_SIZE_TX) USART_readidx_tx = 0; 
	}
}

