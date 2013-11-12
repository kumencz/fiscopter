/* Includes ------------------------------------------------------------------*/
#include "stm32f3_discovery.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void Gyro_ReadAngRate (float* pfData);
void Acc_ReadAcc(float* pfData);
void Compass_ReadMag (float* pfData);
float kalmanCalculate(float newAngle, float newRate,float looptime);
uint32_t LSM303DLHC_TIMEOUT_UserCallback(void);
uint32_t L3GD20_TIMEOUT_UserCallback(void);
/* Exported variables ------------------------------------------------------- */
