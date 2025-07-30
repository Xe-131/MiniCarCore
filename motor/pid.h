#ifndef __PID_h_
#define __PID_h_

#include "ti_msp_dl_config.h"

// #define MAX_DUTY 100
// #define MIN_DUTY -100

typedef struct
{
	float target;	
	float now;
	float error[3];	
	float p,i,d;
	float pout;
	float dout;
	float iout;
	float out;   
	
	uint32_t pid_mode;
}pid_t;

// 编码器计数
extern int encode_cnt_left;
extern int encode_cnt_right;
// 实时速度 mm/s
extern float now_speed_left;
extern float now_speed_right;

extern pid_t pid_motor_left;
extern pid_t pid_motor_right;

// extern pid_t pid_distance;

enum
{
  POSITION_PID = 0,  
  DELTA_PID,         
};

void pid_init(pid_t *pid, uint32_t pid_mode, float p, float i, float d);
float pid_calculate(pid_t *pid, float now, float target);
void speed_pid_controal(void);
void reset_pid(pid_t* pid);
float get_angle_error(float target, float current);
float limit_float(float value, float min, float max);
void set_target_speed(uint8_t side, float speed);


#endif