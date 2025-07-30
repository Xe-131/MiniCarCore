#ifndef __ANGLE_h_
#define __ANGLE_h_

#include "ti_msp_dl_config.h"


// 初始angle角
extern float	angle_init;
// 实时角度
#define now_angle  (fmod((angle - angle_init + 360.0f), 360.0f))
// PID 对象
extern pid_t pid_angle;

void angle_pid_controal(float base_speed);
void set_target_angle(float angle);

#endif