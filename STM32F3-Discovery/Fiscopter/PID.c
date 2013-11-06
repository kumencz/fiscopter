/* Includes ------------------------------------------------------------------*/
#include "pid.h"
#include "main.h"
#include "stm32f30x.h"
#include "system_control.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/



unsigned long lastTime;
float Input, Output, Setpoint;
float errSum, lastErr;
float kp, ki, kd;
unsigned long now;
float timeChange, error, dErr ;

void Compute()
{
   /*How long since we last calculated*/
   now = millis;
   timeChange = (double)(now - lastTime);
  
   /*Compute all the working error variables*/
   error = Setpoint - Input;
   dErr = (error - lastErr) / timeChange;
	 errSum += (error * timeChange);
  
   /*Compute PID Output*/
   Output = kp * error + ki * errSum + kd * dErr;
	if(Output > 100) Output = 100;
	if(Output < 0) Output = 0;
  
   /*Remember some variables for next time*/
   lastErr = error;
   lastTime = now;
	//Delay(5);
}
  
void SetTunings(float Kp, float Ki, float Kd)
{
   kp = Kp;
   ki = Ki;
   kd = Kd;
}
void delete_it(void)
{
	errSum = 0, lastErr = 0;
}
