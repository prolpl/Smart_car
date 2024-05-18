#ifndef MOTOR_H
#define MOTOR_H

typedef enum
{
    MOTOR1 = 0,
    MOTOR2,
    MOTOR3,
    MOTOR4,
}e_motor_type;

#ifdef __cplusplus
extern "C" {
#endif
    
    void motor_init(void);

    void motor_pwm_set(unsigned char motor_id, short int pwm);

	void car_go_ahead(unsigned char speed);

	void car_go_back(unsigned char speed);

	void car_turn_left(unsigned char speed);

	void car_turn_right(unsigned char speed);

	void car_trans_left(unsigned char speed);

	void car_trans_right(unsigned char speed);
	
	void car_trans_back_left(unsigned char speed);

	void car_trans_back_right(unsigned char speed);
	
	void car_trans_forward_left(unsigned char speed);

	void car_trans_forward_right(unsigned char speed);
	
#ifdef __cplusplus
}
#endif

#endif


