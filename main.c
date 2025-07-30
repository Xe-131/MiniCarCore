#include "ti_msp_dl_config.h"
#include "motor.h"
#include "interrupt.h"
#include "pid.h"
#include "follow_line.h"
#include "mpu6050.h"
#include "angle.h"
#include "gw_hardware_iic.h"
#include "xe_uart.h"
#include "clock.h"

// 模式选择
// #define ANGLE_MODE
#define FOLLOW_LINE_MODE

// 里程
float   distance_left	= 0;
float   distance_right	= 0;
float	distance_mid    = 0;
// 圈数
uint8_t circle_num      = 0;
#define CIRCLE_LENTH 3800

int main(void)
{
    SYSCFG_DL_init();
    // systick
    SysTick_Init();
    // 开启测速的外部中断
    NVIC_EnableIRQ(GPIO_MULTIPLE_GPIOB_INT_IRQN);
    // 开启TIMER_PID 中断
    NVIC_EnableIRQ(TIMER_PID_INST_INT_IRQN);
    // TIMER_PID 
    DL_Timer_setLoadValue(TIMER_PID_INST, TIMER_PID_PERIOD / 10.0);
    DL_TimerG_startCounter(TIMER_PID_INST);
    // TIMER_GENERAL 中断
    NVIC_EnableIRQ(TIMER_GENERAL_INST_INT_IRQN);
    // TIMER_GENERAL 开始计时
    DL_Timer_setLoadValue(TIMER_GENERAL_INST, TIMER_GENERAL_PERIOD / 10.0);
    DL_Timer_startCounter(TIMER_GENERAL_INST);

#ifdef ANGLE_MODE
    // MPU6050
    MPU6050_Init();
#endif

    // 电机
    Set_Duty(LEFT, 0);
    Set_Duty(RIGHT, 0);
    Motor_Off();

    // PID
    pid_init(&pid_motor_left, DELTA_PID, 0.12, 0.003, 0.00);
    pid_init(&pid_motor_right, DELTA_PID, 0.12, 0.003, 0.000);
    pid_init(&pid_angle, POSITION_PID, 15, 0.3, 0);
    // reset_pid(&pid_motor_left);
    // reset_pid(&pid_motor_right);
    set_target_speed(LEFT, 0);
    set_target_speed(RIGHT, 0);   

    // 连接灰度传感器
	UART_send_string(UART_BLUEUART_INST, "hello_world!\r\n");
	while(Ping()){
		mspm0_delay_ms(1);
		UART_send_string(UART_BLUEUART_INST, "Ping Faild Try Again!\r\n");
	}
	UART_send_string(UART_BLUEUART_INST, "Ping Succseful!\r\n");

#ifdef ANGLE_MODE
            mspm0_delay_ms(1000*20);
            angle_init  = angle;
            set_target_angle(90);
#endif

    // // 等待10s 设置圈数
    // mspm0_delay_ms(1000*10);
    // Motor_On();
    // DL_GPIO_setPins(GPIO_BLUELED_PORT, GPIO_BLUELED_PIN_0_PIN);
    // mspm0_delay_ms(1000);
    // DL_GPIO_clearPins(GPIO_BLUELED_PORT, GPIO_BLUELED_PIN_0_PIN);
    // mspm0_delay_ms(1000);
    // DL_GPIO_setPins(GPIO_BLUELED_PORT, GPIO_BLUELED_PIN_0_PIN);
    // mspm0_delay_ms(1000);
    // DL_GPIO_clearPins(GPIO_BLUELED_PORT, GPIO_BLUELED_PIN_0_PIN);
    // mspm0_delay_ms(1000);

    while (1) {

        // if(S2_flag == 1){
        //     S2_flag  = 0;
        // }


        // 速度角度PID 计算
        if(pid_timer_flag == 1){
            pid_timer_flag  = 0;

#ifdef ANGLE_MODE
            // 角度闭环：改变target_speed
            angle_pid_controal(0);
#endif

#ifdef FOLLOW_LINE_MODE
            if(distance_mid > (circle_num * CIRCLE_LENTH)){
                Motor_Off();
            }
            else{
                // 巡线：改变target_speed
                follow_line(800);
            }
#endif
            // 速度PID：拟合target_speed
            speed_pid_controal();  
            
        }
        if(flag_1s == 1){
            flag_1s         = 0;

            // UART_send_string(UART_BLUEUART_INST, "BBB\r\n");

        }
        if(flag_100ms == 1){
            flag_100ms      = 0;

            // UART_send_float(UART_BLUEUART_INST, now_speed_left);
            // UART_send_float(UART_BLUEUART_INST, now_speed_right);
            // UART_send_float(UART_BLUEUART_INST, now_angle);
            UART_send_int(UART_BLUEUART_INST, circle_num);
            UART_send_float(UART_BLUEUART_INST, distance_mid);
        }

    }
}