/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

#define RINGBUF_SIZE_TX    2000
#define RINGBUF_SIZE_RX 	 20
#define RX_MAX_MESSAGE_LEN		 50
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

//TX
volatile uint8_t USART_ringbuf_tx[RINGBUF_SIZE_TX];
volatile uint32_t USART_readidx_tx = 0;	//ukazuje na n�sleduj�c� k odesl�n� (klidne i zatim nenaplnenou)
volatile uint32_t USART_writeidx_tx = 0; //ukazuje na prvn� volnou pozici v bufferu Tx pro z�pis
volatile uint32_t USART_ToSend = 0;
char send[50];

// RX
uint8_t  USART_ringbuf_rx[RINGBUF_SIZE_RX][RX_MAX_MESSAGE_LEN];
volatile uint32_t USART_writeidx_rx = 0; //ukazuje na prvn� volnou pozici v bufferu Rx pro z�pis
volatile uint32_t USART_readBuff_rx = 0;	//ukazuje na n�sleduj�c� buffer k parsovani (klidne i zatim nenaplnenou)
volatile uint32_t USART_writeBuff_rx = 0;//ukazuje na prvn� voln� buffer Rx pro z�pis
volatile uint32_t USART_ToParse = 0;  // number of messages (null ending chars) to parse


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
// ------TX-----------
void USART_puts(USART_TypeDef* USARTx, char *s)
{		
	while(*s)
	{
		if (USART_ToSend < RINGBUF_SIZE_TX)
		{
			USART_ringbuf_tx[USART_writeidx_tx] = *s;
			USART_writeidx_tx++;
			USART_ToSend++;
			s++;
			if (USART_writeidx_tx >= RINGBUF_SIZE_TX) USART_writeidx_tx = 0;
		}
		else 
		{
			// Buffer je pln�
		}
//		// wait until data register is empty
//		while( !(USARTx->ISR & 0x00000040) ); 
//		USART_SendData(USARTx, *s);
//		*s++;
	}	
	if (!USART_GetITStatus(USART3, USART_IT_TXE)) 
	{											
		USART_ITConfig(USART3, USART_IT_TXE, ENABLE);
	}
}

void USART_puts_len(USART_TypeDef* USARTx, char *s, int len)
{
	while(len > 0)
	{
		if (USART_ToSend < RINGBUF_SIZE_TX)
		{
			USART_ringbuf_tx[USART_writeidx_tx] = *s;
			USART_writeidx_tx++;
			USART_ToSend++;
			s++;
			len--;
			if (USART_writeidx_tx >= RINGBUF_SIZE_TX) USART_writeidx_tx = 0;
			
		}
		else 
		{
			// Buffer je pln�
		}
//		// wait until data register is empty
//		while( !(USARTx->ISR & 0x00000040) ); 
//		USART_SendData(USARTx, *s);
//		*s++;
	}	
	if (!USART_GetITStatus(USART3, USART_IT_TXE)) 
	{											
		USART_ITConfig(USART3, USART_IT_TXE, ENABLE);
	}
}

void USART_byte_sended(void)
{
	if (USART_ToSend > 0)
	{
		USART_SendData(USART3, USART_ringbuf_tx[USART_readidx_tx]);
		USART_ToSend--;
		USART_readidx_tx++;
		if (USART_readidx_tx >= RINGBUF_SIZE_TX) USART_readidx_tx = 0; 
	}
	else
	{
		USART_ITConfig(USART3, USART_IT_TXE, DISABLE);
	}
}

// ------RX------------
void USART_byte_received(uint8_t data)
{
	if (USART_ToParse < RINGBUF_SIZE_RX)
	{
		USART_ringbuf_rx[USART_writeBuff_rx][USART_writeidx_rx++] = data;
		if (USART_writeidx_rx >= RX_MAX_MESSAGE_LEN) 
		{
			USART_writeidx_rx = 0;
			//ERROR - longer message then maximal
		}
		if (data == '\n' || data == '\r') //message separator
		{
			USART_ToParse++;
			USART_writeidx_rx = 0;	
			USART_writeBuff_rx++;				
			if (USART_writeBuff_rx >= RINGBUF_SIZE_RX) USART_writeBuff_rx = 0;
		}
	}
	else
	{
		// error - ALL Rx buffers are full
	}
}

void USART_manage_RX(void)
{
	uint32_t msgLen;
	if (USART_ToParse > 0)
	{
		msgLen = USART_Protocol_RX_Parse(&(USART_ringbuf_rx[USART_readBuff_rx][0]));
		if (msgLen > 0)
		{
			USART_ToParse--;
			USART_readBuff_rx++;
			if (USART_readBuff_rx >= RINGBUF_SIZE_RX) USART_readBuff_rx = 0;
		}
	}
}
