/* Includes ------------------------------------------------------------------*/
#include "stm32f3_discovery.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void Compute(void);
void SetTunings(float Kp, float Ki, float Kd);
extern float Input, Output, Setpoint; 
void delete_it(void);
/* Exported variables ------------------------------------------------------- */
