#include "remote_control.h"
#include "arm_servo.h"
#include "arc_servo.h"
#include "motor.h"
#include "time.h"
#include "ps2.h"

#define UNIT_SERVO  20
uint8_t key_id;
uint8_t cur_ps2_mode, last_ps2_mode;
unsigned long int arml_pwm;
unsigned long int arml_middle;
unsigned long int arml_left_limit;
unsigned long int arml_right_limit;

unsigned long int armr_pwm;
unsigned long int armr_middle;
unsigned long int armr_left_limit;
unsigned long int armr_right_limit;

unsigned long int armu_pwm;
unsigned long int armu_middle;
unsigned long int armu_left_limit;
unsigned long int armu_right_limit;

void remote_control_init()
{
	cur_ps2_mode  = PSB_LOSE;
	last_ps2_mode = PSB_LOSE;
	
	time_init();
	
	PS2_Init();
	motor_init();
	arm_servo_init();
	
	arml_pwm         = arm_servo_pwm_param_get(SERVO_LEFT, SERVO_MIDDLE);
	arml_middle      = arm_servo_pwm_param_get(SERVO_LEFT, SERVO_MIDDLE);
	arml_left_limit  = arm_servo_pwm_param_get(SERVO_LEFT, SERVO_LEFT_LIMIT);
	arml_right_limit = arm_servo_pwm_param_get(SERVO_LEFT, SERVO_RIGHT_LIMIT);
	
	armr_pwm         = arm_servo_pwm_param_get(SERVO_RIGHT, SERVO_MIDDLE);
	armr_middle      = arm_servo_pwm_param_get(SERVO_RIGHT, SERVO_MIDDLE);
	armr_left_limit  = arm_servo_pwm_param_get(SERVO_RIGHT, SERVO_LEFT_LIMIT);
	armr_right_limit = arm_servo_pwm_param_get(SERVO_RIGHT, SERVO_RIGHT_LIMIT);
	
	armu_pwm         = arm_servo_pwm_param_get(SERVO_UP, SERVO_MIDDLE);
	armu_middle      = arm_servo_pwm_param_get(SERVO_UP, SERVO_MIDDLE);
	armu_left_limit  = arm_servo_pwm_param_get(SERVO_UP, SERVO_LEFT_LIMIT);
	armu_right_limit = arm_servo_pwm_param_get(SERVO_UP, SERVO_RIGHT_LIMIT);	
	
	car_go_ahead(0);
}

uint8_t key_test = 0;
void remote_control_run()
{
	time_run();    //do not close

	if (time_flag20ms_request())
	{

		uint8_t key_num;
		
		key_num = ps2_key_serch();
		cur_ps2_mode = ps2_mode_get();
		if (last_ps2_mode != cur_ps2_mode)
		{
			car_go_ahead(0);
			
			arml_pwm = arml_middle;
			armr_pwm = armr_middle;
			armu_pwm = armu_middle;
			arm_up_pwm_set(armu_middle);
			arm_left_pwm_set(arml_middle);
			arm_right_pwm_set(armr_middle);
		}
		last_ps2_mode = cur_ps2_mode;
		
		if(cur_ps2_mode == PSB_REDLIGHT_MODE)
		{
		
			unsigned char ps2_lx, ps2_ly, ps2_rx, ps2_ry;

			//差速电机控制
			ps2_lx = ps2_get_anolog_data(PSS_LX);
			ps2_ly = ps2_get_anolog_data(PSS_LY);	

			if (ps2_ly == 0x00)
			{	
				car_go_ahead(35);				
			}
			else if (ps2_ly == 0XFF)
			{
				car_go_back(35);	
			}
			else if (ps2_lx == 0x00)
			{
				car_turn_left(35); 
			}
			else if (ps2_lx == 0XFF)
			{
				car_turn_right(35); 
			}
			else
			{
				car_go_ahead(0);
			}


			//机械臂控制
			ps2_rx = ps2_get_anolog_data(PSS_RX);	
			ps2_ry = ps2_get_anolog_data(PSS_RY);	
			if ((ps2_rx == 0X00) && (arml_pwm > arml_left_limit))
			{
				arml_pwm -= UNIT_SERVO;		
				arm_left_pwm_set(arml_pwm);
			}
			else if ((ps2_rx == 0XFF) && (arml_pwm < arml_right_limit))
			{
				arml_pwm += UNIT_SERVO;	
				arm_left_pwm_set(arml_pwm);
			}
			else if((ps2_ry == 0XFF) && (armr_pwm > armr_left_limit))
			{
				armr_pwm -= UNIT_SERVO;
				arm_right_pwm_set(armr_pwm);	
			}
			else if ((ps2_ry == 0X00) && (armr_pwm < armr_right_limit))
			{
				armr_pwm += UNIT_SERVO;	
				arm_right_pwm_set(armr_pwm);
			}
			
			if (ps2_get_key_state(PSB_R1))
			{
				if (armu_pwm < armu_right_limit)
				{
					armu_pwm += UNIT_SERVO;
					arm_up_pwm_set(armu_pwm);
				}
			}
			else if (ps2_get_key_state(PSB_R2))
			{
				if (armu_pwm > armu_left_limit)
				{
					armu_pwm -= UNIT_SERVO;
					arm_up_pwm_set(armu_pwm);
				}
			}
		}
		else if (cur_ps2_mode == PSB_GREENLIGHT_MODE)
		{
			if (key_num != 0)
			{
				//前进后退控制
				if (ps2_get_key_state(PSB_PAD_UP))
				{   
					car_go_ahead(35); 
				}
				else if(ps2_get_key_state(PSB_PAD_DOWN))           
				{
					car_go_back(35);
				}
				else if ((ps2_get_key_state(PSB_PAD_LEFT)) || (ps2_get_key_state(PSB_L1)))
				{
					car_turn_left(35);
				}
				else if ((ps2_get_key_state(PSB_PAD_RIGHT)) || (ps2_get_key_state(PSB_L2)))
				{
					car_turn_right(35);
				}
				else
				{
					car_go_ahead(0); 
				}
				
				//机械臂舵机控制		
				if(ps2_get_key_state(PSB_GREEN))
				{
					if (armr_pwm < armr_right_limit)
					{
						armr_pwm += UNIT_SERVO;
						arm_right_pwm_set(armr_pwm);
					}
				}
				else if (ps2_get_key_state(PSB_RED))
				{	
					if (arml_pwm < arml_right_limit)
					{
						arml_pwm += UNIT_SERVO;
						arm_left_pwm_set(arml_pwm);
					}
				}
				else if (ps2_get_key_state(PSB_BLUE))
				{
					if (armr_pwm > armr_left_limit)
					{
						armr_pwm -= UNIT_SERVO;
						arm_right_pwm_set(armr_pwm);	
					}
				}
				else if (ps2_get_key_state(PSB_PINK))
				{
					if (arml_pwm > arml_left_limit)
					{
						arml_pwm -= UNIT_SERVO;
						arm_left_pwm_set(arml_pwm);
					}
				}
				else if (ps2_get_key_state(PSB_R1))
				{
					if (armu_pwm < armu_right_limit)
					{
						armu_pwm += UNIT_SERVO;
						arm_up_pwm_set(armu_pwm);
					}
				}
				else if (ps2_get_key_state(PSB_R2))
				{
					if (armu_pwm > armu_left_limit)
					{
						armu_pwm -= UNIT_SERVO;
						arm_up_pwm_set(armu_pwm);
					}
				}
			}
			else
			{
				car_go_ahead(0); 
			}
		}
		else
		{
			car_go_ahead(0);
			
			arml_pwm = arml_middle;
			armr_pwm = armr_middle;
			armu_pwm = armu_middle;
			arm_up_pwm_set(armu_middle);
			arm_left_pwm_set(arml_middle);
			arm_right_pwm_set(armr_middle);				
		}
	}
}        

