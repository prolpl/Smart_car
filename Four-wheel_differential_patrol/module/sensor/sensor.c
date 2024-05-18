#include "sensor.h"
#include "bsp_sensor_gpio.h"

/*---------------------------------------------------
传感器分布如下图（对应硬件left -> right
程序根据传感器的分布将车身偏离轨迹位置定义出8个区域，
0为红外管检测到黑线，此时电路板上红外对应的指示灯灭
1为未检测到黑线

Area  SENSOR0  SENSOR1   SENSOR2   SENSOR3   
 3 		1        0         1         1			
 2		1        1         1         1
 1		0        1         1         1           
 4		1        0         0         1          
 5      1        1         0         1       
 6      1        1         1         1
 7      1        1         1         0
-----------------------------------------------------*/ 
/***************adc模块初始化**********************/
void sensor_init()
{
	bsp_sensor_gpio_init();
}
/*************** adc模块初始化**********************/
unsigned char sensor_state_get(unsigned char adc_id)
{
	unsigned char sensor_sta;
	
	switch (adc_id)
	{
		case SENSOR_ADC0:
		{
			sensor_sta = bsp_sensor0_get();
		}break;
		case SENSOR_ADC1:
		{
			sensor_sta = bsp_sensor1_get();
		}break;
		case SENSOR_ADC2:
		{
			sensor_sta = bsp_sensor2_get();
		}break;
		case SENSOR_ADC3:
		{
			sensor_sta = bsp_sensor3_get();
		}break;
		default :
		{
			sensor_sta = 1;
		}break;
	}
	
	return sensor_sta;
}
