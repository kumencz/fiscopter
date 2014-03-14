/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define MAX_REGULATOR_ACTION 1000
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

float x_wanted = 0;
float y_wanted = 0;


float x_out, x_out_neg;
float x_errSum, x_lastErr;
float x_dErr;

float y_out, y_out_neg;
float y_errSum, y_lastErr;
float y_dErr;

float kp, ki, kd;

void Compute(float x_err, float y_err)
{
	//---------------------- x axis -------------------------------------------------
  /*Compute all the working error variables*/
  x_dErr = x_err - x_lastErr;
	x_errSum += x_err;
  /*Compute PID Output*/
  x_out = kp * x_err + ki * x_errSum + kd * x_dErr;
	if(x_out > MAX_REGULATOR_ACTION)
	{
		x_out = MAX_REGULATOR_ACTION;
		//omezení integracní slozky
		x_errSum -= x_err;
	}
	if(x_out < -MAX_REGULATOR_ACTION) 
	{
		x_out = -MAX_REGULATOR_ACTION;
		//omezení integracní slozky
		x_errSum -= x_err;
	}
	x_out_neg = x_out * -1;
  /*Remember some variables for next time*/
  x_lastErr = x_err;
	
	//---------------------- y axis -------------------------------------------------
	  /*Compute all the working error variables*/
  y_dErr = y_err - y_lastErr;
	y_errSum += y_err;
  /*Compute PID Output*/
  y_out = kp * x_err + ki * y_errSum + kd * y_dErr;
	if(y_out > MAX_REGULATOR_ACTION)
	{
		y_out = MAX_REGULATOR_ACTION;
		//omezení integracní slozky
		y_errSum -= y_err;
	}
	if(y_out < -MAX_REGULATOR_ACTION) 
	{
		y_out = -MAX_REGULATOR_ACTION;
		//omezení integracní slozky
		y_errSum -= y_err;
	}
	y_out_neg = y_out * -1;
  /*Remember some variables for next time*/
  y_lastErr = y_err;
	
}
  
void SetTunings(float Kp, float Ki, float Kd)
{
   kp = Kp;
   ki = Ki;
   kd = Kd;
}
void delete_it(void)
{
//	errSum = 0, lastErr = 0;
}
