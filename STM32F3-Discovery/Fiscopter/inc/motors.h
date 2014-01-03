/* Includes ------------------------------------------------------------------*/
#include "stm32f3_discovery.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void ESC_SetPower(uint16_t channel,int lenght);
void ESC_Calibrate_All(void);
void ESC_recompute(void);
/* Exported variables ------------------------------------------------------- */
extern uint16_t M1_speed, M2_speed, M3_speed, M4_speed;
