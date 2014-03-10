/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "string.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
uint32_t USART_Protocol_RX_Parse(uint8_t * message)
{
	if (!memcmp(message, "CHECK_LIVE", 10))
	{
		USART_puts(USART3, "LIVE_OK\n");
		return 10 + USART_RemoveToNewLine(message + 10);
	}
	else if (!memcmp(message, "START_ESC_CALIBRATE", 19)) //"START_ESC_CALIBRATE"
	{
		USART_puts(USART3, "ESC calibrating ...\n");
		ESC_Calibrate_All();		
		return 19 + USART_RemoveToNewLine(message + 19 );
	}
	else if (!memcmp(message, "SET_RPM", 7)) //"SET_RPM "
	{
		USART_puts(USART3, "WHAT_IS_RPM? :-D\n");
		return 7 + USART_RemoveToNewLine(message + 7);
	}
	else
	{		
		USART_puts(USART3, "UNKNOW_MESSAGE\n");
		return 1;
	}
	return 0;
}

uint32_t USART_RemoveToNewLine(uint8_t * message)
{
	uint8_t * msg = message;
	while (*msg != '\n' && *msg != '\r')
	{
		msg++;
	}
	while (*msg == '\n' || *msg == '\r')
	{
		msg++;
	}
	return msg - message;
}
