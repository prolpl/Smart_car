#include "find_line.h"
#include "sensor.h"
#include "motor.h"
#include "time.h"

#define CAR_SPEED  40
unsigned char  now_area,last_area;    

void find_line_init()
{
	time_init();
	sensor_init();
	motor_init();		
}

void find_line_run()
{
	time_run();    //do not close

	if (time_flag20ms_request())
	{
		unsigned char SENSOR0, SENSOR1, SENSOR2, SENSOR3;
	
		SENSOR0 = sensor_state_get(SENSOR_ADC0);
		SENSOR1 = sensor_state_get(SENSOR_ADC1);   
		SENSOR2 = sensor_state_get(SENSOR_ADC2);
		SENSOR3 = sensor_state_get(SENSOR_ADC3);  
		
		//Area 0,车身完全偏离跑道 向左打大角
	    if (!SENSOR0 && SENSOR1 && SENSOR2 && SENSOR3)
		{
			now_area = 0;
			car_turn_left(CAR_SPEED);
		}
		//Area 2,传感器检测到左小弯，向左打小角
		else if (SENSOR0 && !SENSOR1 && SENSOR2 && SENSOR3)
		{
			now_area = 2;
			car_turn_left(CAR_SPEED);
		}
		//Area 3,传感器检测到直线
		else if (SENSOR0 && !SENSOR1 && !SENSOR2 && SENSOR3)
		{
			now_area = 3;
			car_go_ahead(CAR_SPEED - 10);
		}
		//Area 4,传感器检测到右小弯，向右打小角
		else if (SENSOR0 && SENSOR1 && !SENSOR2 && SENSOR3)
		{
			now_area = 4;
			car_turn_right(CAR_SPEED);
		}
		//Area 6,车身完全偏离跑到， 向右打大角
		else if (SENSOR0 && SENSOR1 && SENSOR2 && !SENSOR3)
		{
			now_area = 6;
			car_turn_right(CAR_SPEED);
		}
		else if (SENSOR0 && SENSOR1 && SENSOR2 && SENSOR3)
		{
			//Area 1,传感器检测到左大弯，向左打大角
			if (last_area == 2)
			{
				now_area = 1;
				car_turn_left(CAR_SPEED);
			}
			//Area 5,传感器检测到右大弯，向右打大角
			else if (last_area == 4)
			{
				now_area = 5;
				car_turn_right(CAR_SPEED);
			}
		}
		last_area = now_area;		
    }        

}

