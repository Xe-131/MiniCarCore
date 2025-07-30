#include "pid.h"
#include "motor.h"
#include "angle.h"
#include "mpu6050.h"

// 目标角度: 
static float	target_angle	= 0;
// 初始angle
float           angle_init      = 0;
// PID 对象
pid_t pid_angle;

/**
 * @brief   输入角度的偏差，输出左右轮子速度设置值
 * @return  无
 */
void angle_pid_controal(float base_speed){
	float   angle_pid_value;

	// 计算角度PID: 输入角度差，输出速度值
	angle_pid_value         = pid_calculate(&pid_angle, now_angle, target_angle);

	// 设置duty
	set_target_speed(LEFT, base_speed - angle_pid_value);
	set_target_speed(RIGHT, base_speed + angle_pid_value);
}

/**
 * @brief   改变目标角度
 * @param   angle 角度值，范围在[0, 360)
 * @return  无
 */
void set_target_angle(float angle){
	angle = limit_float(angle, 0, 359.99);

	target_angle	= angle;
}