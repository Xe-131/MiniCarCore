#ifndef __FOLLOW_LINE_h_
#define __FOLLOW_LINE_h_

#include "No_Mcu_Ganv_Grayscale_Sensor_Config.h"
#include "ti_msp_dl_config.h"

extern No_MCU_Sensor sensor;
extern unsigned char Digtal;
extern unsigned short white[8];
extern unsigned short black[8];

void LED_blink();
void Calibration_threshold();
float calc_position_error(uint8_t digital);
void follow_line(float base_speed);
#endif