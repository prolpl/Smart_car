#ifndef SENSOR_H
#define SENSOR_H

typedef enum
{
    SENSOR_ADC0 = 0,
    SENSOR_ADC1,
    SENSOR_ADC2,
    SENSOR_ADC3,
}e_adc_type;

#ifdef __cplusplus
extern "C" {
#endif

    void sensor_init(void);
        
	unsigned char sensor_state_get(unsigned char adc_id);
	
#ifdef __cplusplus
}
#endif

#endif
