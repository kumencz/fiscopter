/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "string.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint8_t USART_RX_MSGS[3][50] = 
{
	"CHECK_LIVE\0", //;
	"START_ESC_CALIBRATE\0",
	"SET_RPM "
};
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
uint32_t USART_Protocol_RX_Parse(uint8_t *message)
{
	if (memcmp(message, USART_RX_MSGS[0], 11))//"CHECK_LIVE\0"
	{
		return 11;
	}
	else if (memcmp(message, USART_RX_MSGS[1], 20)) //"START_ESC_CALIBRATE\0"
	{
		return 20;
	}
	else if (memcmp(message, USART_RX_MSGS[1], 8)) //"SET_RPM "
	{
		return 8;
	}
	return 0;
}
