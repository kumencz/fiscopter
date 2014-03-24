/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
uint32_t USART_Protocol_RX_Parse(uint8_t *message);
uint32_t USART_RemoveToNewLine(uint8_t * message);
void live_fail(void);
/* Exported variables ------------------------------------------------------- */
extern int live;
extern int total_stop;
