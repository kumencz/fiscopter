/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "init.h"
#include "motors.h"
#include "time.h"
#include "stm32f3_discovery.h"
#include "stm32f30x.h"
#include <stm32f30x_usart.h>

/* Private typedef -----------------------------------------------------------*/
GPIO_InitTypeDef GPIO_InitStructure_PWM;
GPIO_InitTypeDef GPIO_InitStructure_Motor;
GPIO_InitTypeDef GPIO_InitStruct_USART2; // USART2 GPIO pins -> TX, RX
TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure_PWM;
TIM_OCInitTypeDef TIM_OCInitStructure_PWM;
TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure_IMU;
USART_InitTypeDef USART_InitStruct_USART2; // USART2 initilization
NVIC_InitTypeDef NVIC_InitStructure_USART2; // configure NVIC (nested vector interrupt controller)
/* Private define ------------------------------------------------------------*/
#define ESC_update_freq 200   // !!!!min:100 max:200 !!!!
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void init_ALL(void);
void init_discovery_board(void);
void init_SysTick(void);
void init_Button(void);
void init_ESC(void);
void init_ESC_GPIO(void);
void init_ESC_Timer(int period);
void init_motor(void);
void init_motor_GPIO(void);
void init_gyro(void);
void init_acc_mag(void);
void init_timer(void);
void init_USART2(uint32_t baudrate);
/* Private functions ---------------------------------------------------------*/
/* Private variables ------------------------------------------------------- */
float ESC_min;
float ESC_koef;
int period;

void init_ALL(void)
{
	init_discovery_board();
	init_SysTick();
	init_Button();
	init_ESC();
	init_gyro();
	init_acc_mag();
	init_timer();
	init_USART2(115200);
}

void init_discovery_board(void)
{
	/* Initialize LEDs and User Button available on STM32F3-Discovery board */
  STM_EVAL_LEDInit(LED3);
  STM_EVAL_LEDInit(LED4);
  STM_EVAL_LEDInit(LED5);
  STM_EVAL_LEDInit(LED6);
  STM_EVAL_LEDInit(LED7);
  STM_EVAL_LEDInit(LED8);
  STM_EVAL_LEDInit(LED9);
  STM_EVAL_LEDInit(LED10);
	
	//STM_EVAL_LEDOn(LED10);
  
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

void init_Button(void)
{
	STM_EVAL_PBInit(BUTTON_USER, BUTTON_MODE_EXTI);
}
void init_ESC(void)
{
	int ESC_cycle_time;
	float ESC_max;
	float ESC_lenght = 1;
	
	period = 5000000 / ESC_update_freq;
	ESC_cycle_time = 1 / 5000000 * period;
	ESC_min = (period * 0.001) / ESC_cycle_time;
	ESC_max = (period * 0.002) / ESC_cycle_time;
	ESC_lenght = ESC_max - ESC_min;
	ESC_koef = 10000 / ESC_lenght;
	
	init_ESC_GPIO();
	init_ESC_Timer(period);
	ESC_SetPower(1,0);
  ESC_SetPower(2,0);
  ESC_SetPower(3,0);
	ESC_SetPower(4,0);
	//ESC_Calibrate_All();
}
void init_ESC_GPIO(void)
{
/* TIM3 clock enable */
  //RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

  /* GPIOC and GPIOB clock enable */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
  
  /* GPIOC Configuration: TIM3 CH1 (PC6) and TIM3 CH2 (PC7) */
  GPIO_InitStructure_PWM.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	//GPIO_InitStructure_PWM.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_11 | GPIO_Pin_13 | GPIO_Pin_14;
  GPIO_InitStructure_PWM.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure_PWM.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure_PWM.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure_PWM.GPIO_PuPd = GPIO_PuPd_UP ;
  GPIO_Init(GPIOC, &GPIO_InitStructure_PWM); 

  /* Connect TIM3 pins to AF2 */  
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_2);
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_2); 
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource8, GPIO_AF_2);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource9, GPIO_AF_2);



}
void init_ESC_Timer(int period)
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
	PrescalerValue = (uint16_t) (SystemCoreClock / 5000000) - 1;

  /* Time base configuration */
  TIM_TimeBaseStructure_PWM.TIM_Period = period;
  TIM_TimeBaseStructure_PWM.TIM_Prescaler = PrescalerValue;
  TIM_TimeBaseStructure_PWM.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure_PWM.TIM_CounterMode = TIM_CounterMode_Up;

  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure_PWM);

  /* PWM1 Mode configuration: Channel1 */
  TIM_OCInitStructure_PWM.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OCInitStructure_PWM.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure_PWM.TIM_Pulse = 0;
  TIM_OCInitStructure_PWM.TIM_OCPolarity = TIM_OCPolarity_High;

  TIM_OC1Init(TIM3, &TIM_OCInitStructure_PWM);

  TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);

  /* PWM1 Mode configuration: Channel2 */
  TIM_OCInitStructure_PWM.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure_PWM.TIM_Pulse = 0;

  TIM_OC2Init(TIM3, &TIM_OCInitStructure_PWM);
  TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);

  /* PWM1 Mode configuration: Channel3 */
  TIM_OCInitStructure_PWM.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure_PWM.TIM_Pulse = 0;

  TIM_OC3Init(TIM3, &TIM_OCInitStructure_PWM);
  TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	/* PWM1 Mode configuration: Channel4 */
  TIM_OCInitStructure_PWM.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure_PWM.TIM_Pulse = 0;

  TIM_OC3Init(TIM3, &TIM_OCInitStructure_PWM);
  TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);


  TIM_ARRPreloadConfig(TIM3, ENABLE);
	
	TIM_CtrlPWMOutputs(TIM3, ENABLE);
	
	  /* TIM3 enable counter */
  TIM_Cmd(TIM3, ENABLE);
}

void init_gyro(void)
{
  L3GD20_InitTypeDef L3GD20_InitStructure;
  L3GD20_FilterConfigTypeDef L3GD20_FilterStructure;
  
  /* Configure Mems L3GD20 */
  L3GD20_InitStructure.Power_Mode = L3GD20_MODE_ACTIVE;
  L3GD20_InitStructure.Output_DataRate = L3GD20_OUTPUT_DATARATE_1;
  L3GD20_InitStructure.Axes_Enable = L3GD20_AXES_ENABLE;
  L3GD20_InitStructure.Band_Width = L3GD20_BANDWIDTH_1;
  L3GD20_InitStructure.BlockData_Update = L3GD20_BlockDataUpdate_Continous;
  L3GD20_InitStructure.Endianness = L3GD20_BLE_LSB;
  L3GD20_InitStructure.Full_Scale = L3GD20_FULLSCALE_500; 
  L3GD20_Init(&L3GD20_InitStructure);
   
	L3GD20_FilterStructure.HighPassFilter_Mode_Selection =L3GD20_HPM_NORMAL_MODE_RES;
  L3GD20_FilterStructure.HighPassFilter_CutOff_Frequency = L3GD20_HPFCF_0;
  L3GD20_FilterConfig(&L3GD20_FilterStructure) ;
  
  L3GD20_FilterCmd(L3GD20_HIGHPASSFILTER_ENABLE);
}
void init_acc_mag(void)
{
  LSM303DLHCMag_InitTypeDef LSM303DLHC_InitStructure;
  LSM303DLHCAcc_InitTypeDef LSM303DLHCAcc_InitStructure;
  LSM303DLHCAcc_FilterConfigTypeDef LSM303DLHCFilter_InitStructure;
  
  /* Configure MEMS magnetometer main parameters: temp, working mode, full Scale and Data rate */
  LSM303DLHC_InitStructure.Temperature_Sensor = LSM303DLHC_TEMPSENSOR_DISABLE;
  LSM303DLHC_InitStructure.MagOutput_DataRate =LSM303DLHC_ODR_30_HZ ;
  LSM303DLHC_InitStructure.MagFull_Scale = LSM303DLHC_FS_8_1_GA;
  LSM303DLHC_InitStructure.Working_Mode = LSM303DLHC_CONTINUOS_CONVERSION;
  LSM303DLHC_MagInit(&LSM303DLHC_InitStructure);
  
   /* Fill the accelerometer structure */
  LSM303DLHCAcc_InitStructure.Power_Mode = LSM303DLHC_NORMAL_MODE;
  LSM303DLHCAcc_InitStructure.AccOutput_DataRate = LSM303DLHC_ODR_50_HZ;
  LSM303DLHCAcc_InitStructure.Axes_Enable= LSM303DLHC_AXES_ENABLE;
  LSM303DLHCAcc_InitStructure.AccFull_Scale = LSM303DLHC_FULLSCALE_2G;
  LSM303DLHCAcc_InitStructure.BlockData_Update = LSM303DLHC_BlockUpdate_Continous;
  LSM303DLHCAcc_InitStructure.Endianness=LSM303DLHC_BLE_LSB;
  LSM303DLHCAcc_InitStructure.High_Resolution=LSM303DLHC_HR_ENABLE;
  /* Configure the accelerometer main parameters */
  LSM303DLHC_AccInit(&LSM303DLHCAcc_InitStructure);
  
  /* Fill the accelerometer LPF structure */
  LSM303DLHCFilter_InitStructure.HighPassFilter_Mode_Selection =LSM303DLHC_HPM_NORMAL_MODE;
  LSM303DLHCFilter_InitStructure.HighPassFilter_CutOff_Frequency = LSM303DLHC_HPFCF_16;
  LSM303DLHCFilter_InitStructure.HighPassFilter_AOI1 = LSM303DLHC_HPF_AOI1_DISABLE;
  LSM303DLHCFilter_InitStructure.HighPassFilter_AOI2 = LSM303DLHC_HPF_AOI2_DISABLE;

  /* Configure the accelerometer LPF main parameters */
  LSM303DLHC_AccFilterConfig(&LSM303DLHCFilter_InitStructure);
}
void init_timer(void)
{
	
	uint16_t PrescalerValue = 0;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	PrescalerValue = (uint16_t) ((SystemCoreClock /2) / 1000000) - 1;

  /* Time base configuration */
  TIM_TimeBaseStructure_IMU.TIM_Period = 1000000/20; //20x za vterinu se napln?cel?citac(max:65534)(nastaven:50000)
  TIM_TimeBaseStructure_IMU.TIM_Prescaler = PrescalerValue;
  TIM_TimeBaseStructure_IMU.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure_IMU.TIM_CounterMode = TIM_CounterMode_Up;

  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure_IMU);
	
	TIM_ARRPreloadConfig(TIM4, ENABLE);
  /* TIM3 enable counter */
  TIM_Cmd(TIM4, ENABLE);
}

void init_USART2(uint32_t baudrate)
{
	/* enable APB2 peripheral clock for USART2 
	 * note that only USART2 and USART6 are connected to APB2
	 * the other USARTs are connected to APB1
	 */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	
	/* enable the peripheral clock for the pins used by 
	 * USART2, PB6 for TX and PB7 for RX
	 */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	
	/* This sequence sets up the TX and RX pins 
	 * so they work correctly with the USART2 peripheral
	 */
	GPIO_InitStruct_USART2.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3; // Pins 2 (TX) and 3 (RX) are used
	GPIO_InitStruct_USART2.GPIO_Mode = GPIO_Mode_AF;			 // the pins are configured as alternate function so the USART peripheral has access to them
	GPIO_InitStruct_USART2.GPIO_Speed = GPIO_Speed_50MHz;		// this defines the IO speed and has nothing to do with the baudrate!
	GPIO_InitStruct_USART2.GPIO_OType = GPIO_OType_PP;			// this defines the output type as push pull mode (as opposed to open drain)
	GPIO_InitStruct_USART2.GPIO_PuPd = GPIO_PuPd_UP;			// this activates the pullup resistors on the IO pins
	GPIO_Init(GPIOA, &GPIO_InitStruct_USART2);					// now all the values are passed to the GPIO_Init() function which sets the GPIO registers
	
	/* The RX and TX pins are now connected to their AF
	 * so that the USART2 can take over control of the 
	 * pins
	 */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_7); //
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_7);
	
	/* Now the USART_InitStruct is used to define the 
	 * properties of USART2 
	 */
	USART_InitStruct_USART2.USART_BaudRate = baudrate;				// the baudrate is set to the value we passed into this init function
	USART_InitStruct_USART2.USART_WordLength = USART_WordLength_8b;// we want the data frame size to be 8 bits (standard)
	USART_InitStruct_USART2.USART_StopBits = USART_StopBits_1;		// we want 1 stop bit (standard)
	USART_InitStruct_USART2.USART_Parity = USART_Parity_No;		// we don't want a parity bit (standard)
	USART_InitStruct_USART2.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // we don't want flow control (standard)
	USART_InitStruct_USART2.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; // we want to enable the transmitter and the receiver
	USART_Init(USART2, &USART_InitStruct_USART2);					// again all the properties are passed to the USART_Init function which takes care of all the bit setting
	
	
	/* Here the USART2 receive interrupt is enabled
	 * and the interrupt controller is configured 
	 * to jump to the USART2_IRQHandler() function
	 * if the USART2 receive interrupt occurs
	 */
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE); // enable the USART2 receive interrupt 
	
	NVIC_InitStructure_USART2.NVIC_IRQChannel = USART2_IRQn;		 // we want to configure the USART2 interrupts
	NVIC_InitStructure_USART2.NVIC_IRQChannelPreemptionPriority = 0;// this sets the priority group of the USART2 interrupts
	NVIC_InitStructure_USART2.NVIC_IRQChannelSubPriority = 0;		 // this sets the subpriority inside the group
	NVIC_InitStructure_USART2.NVIC_IRQChannelCmd = ENABLE;			 // the USART2 interrupts are globally enabled
	NVIC_Init(&NVIC_InitStructure_USART2);							 // the properties are passed to the NVIC_Init function which takes care of the low level stuff	

	// finally this enables the complete USART2 peripheral
	USART_Cmd(USART2, ENABLE);
}
