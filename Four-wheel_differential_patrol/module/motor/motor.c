#include "motor.h"
#include "bsp_motor.h"

/*     
	   MOTOR4(out3)   *********   motor3(out4)
		  *                           *
		  *                           *
		  *                           *
		  *						      *
       motor1(out1)   *********   motor2(out2)
*/

/***************** BSP 电机初始化***********************/
void motor_init()
{
	bsp_motor_init();
	motor_pwm_set(MOTOR1, 15);
	motor_pwm_set(MOTOR2, 15);
	motor_pwm_set(MOTOR3, 15);
	motor_pwm_set(MOTOR4, 15);
}

void motor_pwm_set(unsigned char motor_id, short int pwm)
{
	pwm = (pwm >  100)? 100 : (pwm < -100)? -100 : pwm;  

    switch (motor_id)
    {
        case MOTOR1:
        {
            bsp_motor1_pwm_set(pwm);
        }break;
        case MOTOR2:
        {
            bsp_motor2_pwm_set(pwm);
        }break;
        case MOTOR3:
        {
            bsp_motor3_pwm_set(pwm);
        }break;
        case MOTOR4:
        {
            bsp_motor4_pwm_set(pwm);
        }break;
        default:
        {  
        
        }break;
    }
}

void car_go_ahead(unsigned char speed)
{
    motor_pwm_set(MOTOR1, speed);
    motor_pwm_set(MOTOR2, speed);
    motor_pwm_set(MOTOR3, speed);
    motor_pwm_set(MOTOR4, speed);
}

void car_go_back(unsigned char speed)
{
    motor_pwm_set(MOTOR1, -speed);
    motor_pwm_set(MOTOR2, -speed);
    motor_pwm_set(MOTOR3, -speed);
    motor_pwm_set(MOTOR4, -speed);
}


void car_trans_right(unsigned char speed)
{
    motor_pwm_set(MOTOR1, -speed);
    motor_pwm_set(MOTOR2, speed);
    motor_pwm_set(MOTOR3, -speed);
    motor_pwm_set(MOTOR4, speed);
}

void car_trans_left(unsigned char speed)
{
    motor_pwm_set(MOTOR1, speed);
    motor_pwm_set(MOTOR2, -speed);
    motor_pwm_set(MOTOR3, speed);
    motor_pwm_set(MOTOR4, -speed);
}

void car_turn_left(unsigned char speed)
{
    motor_pwm_set(MOTOR1, -speed);
    motor_pwm_set(MOTOR2, speed);
    motor_pwm_set(MOTOR3, speed);
    motor_pwm_set(MOTOR4, -speed);
}

void car_turn_right(unsigned char speed)
{
    motor_pwm_set(MOTOR1, speed);
    motor_pwm_set(MOTOR2, -speed);
    motor_pwm_set(MOTOR3, -speed);
    motor_pwm_set(MOTOR4, speed);
}

