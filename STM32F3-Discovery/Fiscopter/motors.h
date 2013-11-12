/* Includes ------------------------------------------------------------------*/
#include "stm32f3_discovery.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void ESC_SetPower(uint16_t channel,uint16_t lenght);
void ESC_Calibrate_All(void);
/* Exported variables ------------------------------------------------------- */
extern float ESC_SetPower_MIN;
extern float ESC_SetPower_MAX;