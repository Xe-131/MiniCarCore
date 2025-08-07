#include "ti_msp_dl_config.h"
#include "motor.h"
#include "interrupt.h"
#include "pid.h"
#include "follow_line.h"
#include "xe_uart.h"
#include "clock.h"
#include "No_Mcu_Ganv_Grayscale_Sensor_Config.h"

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

    // 电机
    Set_Duty(LEFT, 0);
    Set_Duty(RIGHT, 0);
    Motor_Off();

    // PID
    pid_init(&pid_motor_left, DELTA_PID, 0.12, 0.003, 0.00);
    pid_init(&pid_motor_right, DELTA_PID, 0.12, 0.003, 0.000);
    reset_pid(&pid_motor_left);
    reset_pid(&pid_motor_right);
    set_target_speed(LEFT, 0);
    set_target_speed(RIGHT, 0);   

    // 初始化灰度传感器
    No_MCU_Ganv_Sensor_Init_Frist(&sensor);
    No_Mcu_Ganv_Sensor_Task_Without_tick(&sensor);
    // 将灰度传感器依次放在白底和黑底上
    Calibration_threshold();
	No_MCU_Ganv_Sensor_Init(&sensor,white,black);

    // 打开电机
    Motor_On();
    while (1) {

        // 速度角度PID 计算
        if(pid_timer_flag == 1){
            pid_timer_flag  = 0;

 
            // 巡线：改变target_speed
            follow_line(550);
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
        }

    }
}

