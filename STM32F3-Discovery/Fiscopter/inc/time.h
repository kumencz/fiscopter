/* Includes ------------------------------------------------------------------*/
#include "stm32f3_discovery.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void Delay(__IO uint32_t nTime);
void Delay_tick(__IO uint32_t nCount);
void TimingDelay_Decrement(void);
void Period_timer_increment(void);
void period_time_check_flags(void);
void tim_1ms_loop(void);
void tim_10ms_loop(void);
void tim_100ms_loop(void);
void tim_1000ms_loop(void);
/* Exported variables ------------------------------------------------------- */
