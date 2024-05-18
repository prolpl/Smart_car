#include "sensor.h"
#include "bsp_sensor_gpio.h"

/*---------------------------------------------------
�������ֲ�����ͼ����ӦӲ���lleft -> right��
������ݴ������ķֲ�������ƫ��켣λ�ö����8������
0Ϊ����ܼ�⵽���ߣ���ʱ��·���Ϻ����Ӧ��ָʾ����
1Ϊδ��⵽����

Area  SENSOR0  SENSOR1   SENSOR2   SENSOR3   
 3 		1        0         1         1			
 2		1        1         1         1
 1		0        1         1         1           
 4		1        0         0         1          
 5      1        1         0         1       
 6      1        1         1         1
 7      1        1         1         0
-----------------------------------------------------*/ 
/***************adcģ���ʼ��**********************/
void sensor_init()
{
	bsp_sensor_gpio_init();
}
/*************** adcģ���ʼ��**********************/
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
