/* Includes ------------------------------------------------------------------*/
#include "stm32f3_discovery.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void Compute(float x_err, float y_err);
void SetTunings(float Kp, float Ki, float Kd);
extern float Input, Output, Setpoint; 
void delete_it(void);
/* Exported variables ------------------------------------------------------- */
extern float x_out, x_out_neg;
extern float y_out, y_out_neg;