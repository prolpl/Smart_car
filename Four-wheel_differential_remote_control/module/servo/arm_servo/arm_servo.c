#include "arm_servo.h"
#include "bsp_arm_servo.h"

//servo paramter init, pwm, left_limit, middle, right_limit
struct SERVO_PARAM arm_left  = {1700,1300,1700,2500};
struct SERVO_PARAM arm_right = {1900,1300,1900,2500};
struct SERVO_PARAM arm_up    = {1800,1400,1800,2200};

int16_t arm_left_offset = 0;
int16_t arm_right_offset = 0;
int16_t arm_up_offset = 0;
/*****************舵机初始化****************/
void arm_servo_init()
{	
	bsp_arm_servo_init();
	arm_left_pwm_set(arm_left.middle);
	arm_right_pwm_set(arm_right.middle);
	arm_up_pwm_set(arm_up.middle);
}
/*****************舵机初始化****************/

void arm_left_pwm_set(uint16_t pwm)
{
	int16_t pwm_temp = pwm + arm_left_offset;
	
	if (pwm_temp > arm_left.right_limit + arm_left_offset)
	{
		pwm_temp = arm_left.right_limit + arm_left_offset;
	}
	else if (pwm_temp < arm_left.left_limit + arm_left_offset)
	{
		pwm_temp = arm_left.left_limit + arm_left_offset;
	}
	
	if (pwm_temp < 0)
	{
		return;
	}
	
	arm_left.pwm = pwm_temp;
	bsp_arm_left_high_tim_set(arm_left.pwm);
}

void arm_right_pwm_set(uint16_t pwm)
{
	int16_t pwm_temp = pwm + arm_right_offset;
	
	if (pwm_temp > arm_right.right_limit + arm_right_offset)
	{
		pwm_temp = arm_right.right_limit + arm_right_offset;
	}
	else if (pwm_temp < arm_right.left_limit + arm_right_offset)
	{
		pwm_temp = arm_right.left_limit + arm_right_offset;
	}
	
	if (pwm_temp < 0)
	{
		return;
	}
	
	arm_right.pwm = pwm_temp;
	bsp_arm_right_high_tim_set(arm_right.pwm);
}

void arm_up_pwm_set(uint16_t pwm)
{
	int16_t pwm_temp = pwm + arm_up_offset;
	
	if (pwm_temp > arm_up.right_limit + arm_up_offset)
	{
		pwm_temp = arm_up.right_limit + arm_up_offset;
	}
	else if (pwm_temp < arm_up.left_limit + arm_up_offset)
	{
		pwm_temp = arm_up.left_limit + arm_up_offset;
	}
	
	if (pwm_temp < 0)
	{
		return;
	}
	
	arm_up.pwm = pwm_temp;
	bsp_arm_up_high_tim_set(arm_up.pwm);
}

void arm_servo_pwm_run()
{
	bsp_arm_servo_pwm_run();
}

uint16_t arm_servo_pwm_param_get(uint8_t servo_id,uint8_t servo_param)
{
	uint16_t param_value = 0;
	switch(servo_id)
	{
		case SERVO_LEFT:
		{
			if (servo_param == SERVO_MIDDLE)
			{
				param_value = arm_left.middle;
			}
			else if (servo_param == SERVO_LEFT_LIMIT)
			{
				param_value = arm_left.left_limit;
			}
			else if(servo_param == SERVO_RIGHT_LIMIT)
			{
				param_value = arm_left.right_limit;
			}
			else
			{
				param_value = arm_left.middle;
			}
		}break;
		case SERVO_RIGHT:
		{
			if (servo_param == SERVO_MIDDLE)
			{
				param_value = arm_right.middle;
			}
			else if (servo_param == SERVO_LEFT_LIMIT)
			{
				param_value = arm_right.left_limit;
			}
			else if(servo_param == SERVO_RIGHT_LIMIT)
			{
				param_value = arm_right.right_limit;
			}
			else
			{
				param_value = arm_right.middle;
			}		
		}break;
		case SERVO_UP:
		{
			if (servo_param == SERVO_MIDDLE)
			{
				param_value = arm_up.middle;
			}
			else if (servo_param == SERVO_LEFT_LIMIT)
			{
				param_value = arm_up.left_limit;
			}
			else if(servo_param == SERVO_RIGHT_LIMIT)
			{
				param_value = arm_up.right_limit;
			}
			else
			{
				param_value = arm_up.middle;
			}		
		}break;
		default:
		{
			
		}break;
	}
	
	return param_value;
}
