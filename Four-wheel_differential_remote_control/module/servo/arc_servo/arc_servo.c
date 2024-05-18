#include "arc_servo.h"
#include "bsp_arc_servo.h"

//servo paramter init, pwm, left_limit, middle, right_limit
struct SERVO_PARAM arc_servo = {1500,800,1500,2200};
int16_t arc_servo_offset = 0;
/*****************¶æ»ú³õÊ¼»¯****************/
void arc_servo_init()
{	
	bsp_arc_servo_init();
	arc_servo_pwm_set(arc_servo.middle);
}

void arc_servo_pwm_set(uint16_t pwm)
{
	int16_t pwm_temp = pwm + arc_servo_offset;
	
	if (pwm_temp > arc_servo.right_limit + arc_servo_offset)
	{
		pwm_temp = arc_servo.right_limit + arc_servo_offset;
	}
	else if (pwm_temp < arc_servo.left_limit + arc_servo_offset)
	{
		pwm_temp = arc_servo.left_limit + arc_servo_offset;
	}
	
	if (pwm_temp < 0)
	{
		return;
	}
	
	arc_servo.pwm = pwm_temp;
	bsp_arc_servo_high_tim_set(arc_servo.pwm);
}

uint16_t arc_servo_pwm_param_get(uint8_t servo_param)
{
	uint16_t param_value = 0;

	if (servo_param == SERVO_MIDDLE)
	{
		param_value = arc_servo.middle;
	}
	else if (servo_param == SERVO_LEFT_LIMIT)
	{
		param_value = arc_servo.left_limit;
	}
	else if(servo_param == SERVO_RIGHT_LIMIT)
	{
		param_value = arc_servo.right_limit;
	}
	else
	{
		param_value = arc_servo.middle;
	}
	
	return param_value;
}

void arc_servo_pwm_run()
{
	bsp_arc_servo_pwm_run();
}
