/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void USART_puts(USART_TypeDef* USARTx, char *s);
void USART_puts_len(USART_TypeDef* USARTx, char *s, int len);
void USART_byte_sended(void);
void USART_manage_RX(void);
void USART_byte_received(uint8_t data);
/* Exported variables ------------------------------------------------------- */
extern char send[50];
