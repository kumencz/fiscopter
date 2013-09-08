/* Includes ------------------------------------------------------------------*/
#include "init.h"
#include "main.h"
#include "pwm.h"
#include "stm32f30x.h"


/* Private typedef -----------------------------------------------------------*/
GPIO_InitTypeDef GPIO_InitStructure_PWM;
GPIO_InitTypeDef GPIO_InitStructure_Motor;
TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure_PWM;
TIM_OCInitTypeDef TIM_OCInitStructure_PWM;
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void init_ALL(void);
void init_discovery_board(void);
void init_SysTick(void);
void init_PWM(void);
void init_PWM_GPIO(void);
void init_PWM_Timer(int period);
void init_motor(void);
void init_motor_GPIO(void);
/* Private functions ---------------------------------------------------------*/


void init_ALL(void)
{
	init_discovery_board();
	init_SysTick();
	init_PWM();
}

void init_discovery_board(void)
{
	/* Initialize LEDs and User Button available on STM32F3-Discovery board */
  /*STM_EVAL_LEDInit(LED3);
  STM_EVAL_LEDInit(LED4);
  STM_EVAL_LEDInit(LED5);
  STM_EVAL_LEDInit(LED6);
  STM_EVAL_LEDInit(LED7);
  STM_EVAL_LEDInit(LED8);
  STM_EVAL_LEDInit(LED9);
  STM_EVAL_LEDInit(LED10);
	
	STM_EVAL_LEDOn(LED10);*/
  
  STM_EVAL_PBInit(BUTTON_USER, BUTTON_MODE_GPIO);
}


void init_SysTick(void)
{
	if (SysTick_Config(SystemCoreClock / 1000))
  { 
    /* Capture error */ 
    while (1);
  }
}

void init_PWM(void)
{
	init_PWM_GPIO();
	init_PWM_Timer(10000);
	PWM_SetDC(1,0);
  PWM_SetDC(2,0);
  PWM_SetDC(3,0);
	PWM_SetDC(4,0);
}
void init_PWM_GPIO(void)
{
/* TIM3 clock enable */
  //RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

  /* GPIOC and GPIOB clock enable */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);
  
  /* GPIOC Configuration: TIM3 CH1 (PC6) and TIM3 CH2 (PC7) */
  //GPIO_InitStructure_PWM.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure_PWM.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_11 | GPIO_Pin_13 | GPIO_Pin_14;
  GPIO_InitStructure_PWM.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure_PWM.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure_PWM.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure_PWM.GPIO_PuPd = GPIO_PuPd_UP ;
  GPIO_Init(GPIOE, &GPIO_InitStructure_PWM); 

  /* Connect TIM3 pins to AF2 */  
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource9, GPIO_AF_2);
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource11, GPIO_AF_2); 
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource13, GPIO_AF_2);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource14, GPIO_AF_2);



}
void init_PWM_Timer(int period)
{
	uint16_t PrescalerValue = 0;
  /* -----------------------------------------------------------------------
    TIM3 Configuration: generate 4 PWM signals with 4 different duty cycles.
    
    In this example TIM3 input clock (TIM3CLK) is set to 2 * APB1 clock (PCLK1), 
    since APB1 prescaler is different from 1.   
      TIM3CLK = 2 * PCLK1  
      PCLK1 = HCLK / 4 
      => TIM3CLK = HCLK / 2 = SystemCoreClock /2
          
    To get TIM3 counter clock at 28 MHz, the prescaler is computed as follows:
       Prescaler = (TIM3CLK / TIM3 counter clock) - 1
       Prescaler = ((SystemCoreClock /2) /28 MHz) - 1
                                              
    To get TIM3 output clock at 30 KHz, the period (ARR)) is computed as follows:
       ARR = (TIM3 counter clock / TIM3 output clock) - 1
           = 665

    Note: 
     SystemCoreClock variable holds HCLK frequency and is defined in system_stm32f4xx.c file.
     Each time the core clock (HCLK) changes, user had to call SystemCoreClockUpdate()
     function to update SystemCoreClock variable value. Otherwise, any configuration
     based on this variable will be incorrect.    
  ----------------------------------------------------------------------- */  

  /* Compute the prescaler value */
  //PrescalerValue = (uint16_t) ((SystemCoreClock /2) / 1000000) - 1;
	
	int clk = 72e6; // 72MHz -> system core clock. This is default on the stm32f3 discovery
	int tim_freq = 2e6; // in Hz (2MHz) Base frequency of the pwm timer
	PrescalerValue = ((clk / tim_freq) - 1);

  /* Time base configuration */
  TIM_TimeBaseStructure_PWM.TIM_Period = period;
  TIM_TimeBaseStructure_PWM.TIM_Prescaler = PrescalerValue;
  TIM_TimeBaseStructure_PWM.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure_PWM.TIM_CounterMode = TIM_CounterMode_Up;

  TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure_PWM);

  /* PWM1 Mode configuration: Channel1 */
  TIM_OCInitStructure_PWM.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OCInitStructure_PWM.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure_PWM.TIM_Pulse = 0;
  TIM_OCInitStructure_PWM.TIM_OCPolarity = TIM_OCPolarity_High;

  TIM_OC1Init(TIM1, &TIM_OCInitStructure_PWM);

  TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);

  /* PWM1 Mode configuration: Channel2 */
  TIM_OCInitStructure_PWM.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure_PWM.TIM_Pulse = 0;

  TIM_OC2Init(TIM1, &TIM_OCInitStructure_PWM);
  TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);

  /* PWM1 Mode configuration: Channel3 */
  TIM_OCInitStructure_PWM.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure_PWM.TIM_Pulse = 0;

  TIM_OC3Init(TIM1, &TIM_OCInitStructure_PWM);
  TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);
	
	/* PWM1 Mode configuration: Channel4 */
  TIM_OCInitStructure_PWM.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure_PWM.TIM_Pulse = 0;

  TIM_OC3Init(TIM1, &TIM_OCInitStructure_PWM);
  TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);


  TIM_ARRPreloadConfig(TIM1, ENABLE);
	
	TIM_CtrlPWMOutputs(TIM1, ENABLE);
	
	  /* TIM1 enable counter */
  TIM_Cmd(TIM1, ENABLE);
}
