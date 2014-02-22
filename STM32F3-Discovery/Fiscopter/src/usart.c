/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

#define RINGBUF_SIZE_TX    200
#define RINGBUF_SIZE_RX 	 200
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

//TX
volatile uint8_t USART_ringbuf_tx[RINGBUF_SIZE_TX];
volatile uint32_t USART_readidx_tx = 0;	//ukazuje na následující k odeslání (klidne i zatim nenaplnenou)
volatile uint32_t USART_writeidx_tx = 0; //ukazuje na první volnou pozici v bufferu Tx pro zápis
volatile uint32_t USART_ToSend = 0;
char send[50];

// RX
volatile uint8_t  USART_ringbuf_rx[RINGBUF_SIZE_RX];
volatile uint32_t USART_readidx_rx = 0;	//ukazuje na následující k parsovani (klidne i zatim nenaplnenou)
volatile uint32_t USART_writeidx_rx = 0; //ukazuje na první volnou pozici v bufferu Rx pro zápis
volatile uint32_t USART_ToParse = 0;  // number of messages (null ending chars) to parse
volatile uint32_t USART_InBufferCounter = 0; // pocet byte v bufferu

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
// ------TX-----------
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

// ------RX------------
void USART_byte_received(uint8_t data)
{
	if (USART_InBufferCounter < RINGBUF_SIZE_RX)
	{
		USART_ringbuf_rx[USART_writeidx_rx++] = data;
		if (USART_writeidx_rx >= RINGBUF_SIZE_RX) USART_writeidx_rx = 0;
		USART_InBufferCounter++;
		if (data == '\0') //message separator
		{
			USART_ToParse++;
		}
	}
	else
	{
		// error - Rx buffer full
	}
}

void USART_manage_RX(void)
{
	uint32_t msgLen;
	if (USART_ToParse > 0)
	{
		msgLen = USART_Protocol_RX_Parse(&USART_ringbuf_rx[USART_readidx_rx]);
		if (msgLen > 0)
		{
			USART_ToParse--;
			USART_InBufferCounter -= msgLen;
			USART_readidx_rx += msgLen;
		}
	}
}
