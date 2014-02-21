/* Includes ------------------------------------------------------------------*/
#include "stm32f3_discovery.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void USART_puts(USART_TypeDef* USARTx, char *s);
void USART_byte_sended(void);
/* Exported variables ------------------------------------------------------- */
extern char send[50];
