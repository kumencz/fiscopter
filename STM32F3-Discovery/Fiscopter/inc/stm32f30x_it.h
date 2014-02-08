/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F30X_IT_H
#define __STM32F30X_IT_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "stm32f30x.h"
#include "stm32f3_discovery.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);

extern __IO uint32_t UserButtonPressed;

#ifdef __cplusplus
}
#endif

#endif /* __STM32F30X_IT_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
