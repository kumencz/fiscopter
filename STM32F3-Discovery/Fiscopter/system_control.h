/* Includes ------------------------------------------------------------------*/
#include "stm32f3_discovery.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void ESC_SetPower(uint16_t channel,uint16_t dutycycle);
void Delay(__IO uint32_t nTime);
void Delay_tick(__IO uint32_t nCount);
void TimingDelay_Decrement(void);
void Gyro_ReadAngRate (float* pfData);
void Acc_ReadAcc(float* pfData);
void Compass_ReadMag (float* pfData);
uint32_t LSM303DLHC_TIMEOUT_UserCallback(void);
uint32_t L3GD20_TIMEOUT_UserCallback(void);
float kalmanCalculate(float newAngle, float newRate,float looptime);
/* Exported variables ------------------------------------------------------- */
extern float ESC_SetPower_MIN;
extern float ESC_SetPower_MAX;
