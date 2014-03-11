/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "string.h"
#include  "stdlib.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
uint32_t USART_Protocol_RX_Parse(uint8_t * message)
{
	uint8_t* message2;
	float KI;
	float KP;
	float KD;
	if (!memcmp(message, "P_CHECK_LIVE", 12))
	{
		USART_puts(USART3, "K_LIVE_OK\n");
		return 12 + USART_RemoveToNewLine(message + 12);
	}
	else if (!memcmp(message, "P_START_ESC_CALIBRATE", 21)) //"START_ESC_CALIBRATE"
	{
		USART_puts(USART3, "K_ESC_CALIBRATED\n");
		ESC_Calibrate_All();		
		return 21 + USART_RemoveToNewLine(message + 21 );
	}
	else if (!memcmp(message, "P_SET_RPM", 9)) //"SET_RPM "
	{
		M1_speed = strtol (message+9,&message2,10);
		M2_speed = strtol (message2,&message2,10);
		M3_speed = strtol (message2,&message2,10);
		M4_speed = strtol (message2,&message2,10);
		USART_puts(USART3, "K_RPM_SETTED!\n");
		return 15 + USART_RemoveToNewLine(message + 15);
	}
	else if (!memcmp(message, "P_SET_PID", 9)) //"SET_PID "
	{
		KP = strtof (message+9,&message2);
		KI = strtof (message2, &message2);
		KD = strtof (message2, &message2);
		SetTunings (KP,KI,KD);
		USART_puts(USART3, "K_PID_SETTED!\n");
		return 1;
	}
	else if (!memcmp(message, "P_SET_WANTED", 12)) //"SET_WANTED "
	{
		x_wanted = strtof (message+12,&message2);
		y_wanted = strtof (message2, &message2);
		USART_puts(USART3, "K_WANTED_SETTED!\n");
		return 1;
	}
	else
	{		
		USART_puts(USART3, "K_UNKNOW_MESSAGE\n");
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
