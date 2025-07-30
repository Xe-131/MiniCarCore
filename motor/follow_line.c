#include "follow_line.h"
#include "pid.h"
#include "gw_hardware_iic.h"
#include "motor.h"
#include "xe_uart.h"

// basespee = 800
int8_t sensor_weights[8] = {-10, -5, -3, -1, 1, 3, 5, 10};
#define TURN_RATE 0.5

// basespee = 1500
// int8_t sensor_weights[8] = {-5, -3, -2, -1, 1, 2, 3, 5};
// #define TURN_RATE 0.1

float calc_position_error(uint8_t digital)
{
    int sum_weight = 0;
    int count = 0;

    for (int i = 0; i < 8; i++) {
        if (((digital >> i) & 0x01) == 0) { // 说明这个传感器检测到黑线
            sum_weight += sensor_weights[i];
            count++;
        }
    }

    if (count == 0) {
        return 0.0;  // 所有传感器都没检测到黑线，说明可能偏离了轨道
    }

    return (float)sum_weight / count;
}


void follow_line(float base_speed)
{
    static int last_direction = 0; // -1=左偏, 1=右偏

    uint8_t Digtal = IIC_Get_Digtal(); // 获取传感器状态
    // 在线内正常跑
    if (Digtal != 255) {
        float error = calc_position_error(Digtal); // 偏差值
        last_direction = (error > 0) ? 1 : ((error < 0) ? -1 : last_direction);// 本次方向

        float Kp = 100.0f;          // 比例系数，可调节
        float turn = Kp * error;   // 简单的P控制

        float left_speed  = base_speed + turn;
        float right_speed = base_speed - turn;

        set_target_speed(LEFT, left_speed);
        set_target_speed(RIGHT, right_speed);
    }
    // 在线外，回到线内
    else{
        if(last_direction == 1){
            set_target_speed(LEFT, base_speed*TURN_RATE);
            set_target_speed(RIGHT, (-base_speed)*TURN_RATE);  
        }
        else if(last_direction == -1){
            set_target_speed(LEFT, (-base_speed)*TURN_RATE);
            set_target_speed(RIGHT, base_speed*TURN_RATE);  
        }
        else{
            set_target_speed(LEFT, 0);
            set_target_speed(RIGHT, 0);  
        }
    }

    // // 要左转
    // if(Digtal & 0b10000000)
    // // 要右转

}


