#include "ti_msp_dl_config.h"
#include "interrupt.h"
#include "clock.h"
#include "pid.h"
#include "xe_uart.h"
#include "mpu6050.h"
// #include "ring_buffer.h"

// SysTick 中断，每隔1ms 发送一次
void SysTick_Handler(void)
{
    tick_ms++;
}

// S2 
uint8_t S2_flag = 0;
extern uint8_t circle_num;
void GROUP1_IRQHandler(void)
{
    // uint32_t gpioA  = DL_GPIO_getEnabledInterruptStatus(GPIOA, GPIO_ENCODER_RIGHT_PIN_EA_RIGHT_PIN);
    // uint32_t gpioB  = DL_GPIO_getEnabledInterruptStatus(GPIOB, GPIO_ENCODER_LEFT_PIN_EA_LEFT_PIN | GPIO_MPU6050_PIN_INT_PIN | GPIO_SWICH_PIN_S2_PIN);

    uint32_t gpioB  = DL_GPIO_getEnabledInterruptStatus(GPIOB, GPIO_ENCODER_LEFT_PIN_EA_LEFT_PIN | GPIO_ENCODER_RIGHT_PIN_EA_RIGHT_PIN | GPIO_SWICH_PIN_S2_PIN | GPIO_MPU6050_PIN_INT_PIN);

    // 编码器right 中断
    if(gpioB & GPIO_ENCODER_RIGHT_PIN_EA_RIGHT_PIN){
        if (!DL_GPIO_readPins(GPIO_ENCODER_RIGHT_PORT, GPIO_ENCODER_RIGHT_PIN_EB_RIGHT_PIN)) {
            encode_cnt_right--;  
        }
        else {
            encode_cnt_right++;
        }
        DL_GPIO_clearInterruptStatus(GPIOB, GPIO_ENCODER_RIGHT_PIN_EA_RIGHT_PIN);
    }

    // 编码器left 中断
    if(gpioB & GPIO_ENCODER_LEFT_PIN_EA_LEFT_PIN){
        if (!DL_GPIO_readPins(GPIO_ENCODER_LEFT_PORT, GPIO_ENCODER_LEFT_PIN_EB_LEFT_PIN)) {
            encode_cnt_left++;   
        }
        else {
            encode_cnt_left--; 
        }
        DL_GPIO_clearInterruptStatus(GPIOB, GPIO_ENCODER_LEFT_PIN_EA_LEFT_PIN);
    }

    // MPU6050 中断
    if(gpioB & GPIO_MPU6050_PIN_INT_PIN){
        Read_Quad();
        DL_GPIO_clearInterruptStatus(GPIOB, GPIO_MPU6050_PIN_INT_PIN);
    }

    // S2 中断
    if(gpioB & GPIO_SWICH_PIN_S2_PIN){
        S2_flag = 1;

        // 软件消抖
        delay_cycles(CPUCLK_FREQ*0.02);
        // 圈数
        circle_num++;
        if(circle_num >= 5){
            circle_num = 5;
        }
        DL_GPIO_clearInterruptStatus(GPIOB, GPIO_SWICH_PIN_S2_PIN);
    }

}

// TIMA1
// 定时清空编码器计数器，并计算实时速度
uint8_t pid_timer_flag = 0;
void TIMER_PID_INST_IRQHandler(void){
    switch (DL_TimerG_getPendingInterrupt(TIMER_PID_INST)) {
        // 清零中断位
        case DL_TIMER_IIDX_ZERO:

                DL_TimerG_stopCounter(TIMER_PID_INST);
                DL_Timer_setLoadValue(TIMER_PID_INST, TIMER_PID_PERIOD / 10.0);
                DL_TimerG_startCounter(TIMER_PID_INST);

                pid_timer_flag    = 1;
            break;
        default:
            break;
    }
}

// // 简单一次性定时：用于等待MPU6050
// uint8_t into_wihle_flag = 0;
// void TIMER_INTOWHILE_INST_IRQHandler(void){
//     switch (DL_TimerG_getPendingInterrupt(TIMER_INTOWHILE_INST)) {
//         // 清零中断位
//         case DL_TIMER_IIDX_ZERO:
//                 DL_TimerG_stopCounter(TIMER_INTOWHILE_INST);

//                 into_wihle_flag = 1;
//             break;
//         default:
//             break;
//     }
// }

// 通用定时
uint8_t flag_100ms  = 0;
uint8_t flag_1s     = 0;
void TIMER_GENERAL_INST_IRQHandler(void){
    static uint8_t count_100ms = 0;

    switch (DL_TimerG_getPendingInterrupt(TIMER_GENERAL_INST)) {
        // 清零中断位
        case DL_TIMER_IIDX_ZERO:
                DL_TimerG_stopCounter(TIMER_GENERAL_INST);
                DL_Timer_setLoadValue(TIMER_GENERAL_INST, TIMER_GENERAL_PERIOD / 10.0);
                DL_TimerG_startCounter(TIMER_GENERAL_INST);

                count_100ms++;

                flag_100ms     = 1;
                if(count_100ms == 10){
                    flag_1s = 1;
                    // 清零
                    count_100ms = 0;
                }
            break;
        default:
            break;
    }
}

// // UART_MAVLINK 接收中断
// // 读取数据写到缓冲区里面
// void UART_MAVLINK_INST_IRQHandler(void)
// {
//     switch (DL_UART_Main_getPendingInterrupt(UART_MAVLINK_INST)) {
//         case DL_UART_MAIN_IIDX_RX:
//         {
//             uint8_t data        = DL_UART_Main_receiveData(UART_MAVLINK_INST);
//             RingBuffer_Write(&uart_mavlink_rx_buffer, data);

//             break;
//         }
//         default:
//             break;
//     }
// }

// // UART_PC 接收中断
// // 读取数据写到缓冲区里面
// void UART_PC_INST_IRQHandler(void)
// {
//     switch (DL_UART_Main_getPendingInterrupt(UART_PC_INST)) {
//         case DL_UART_MAIN_IIDX_RX:
//         {
//             uint8_t data        = DL_UART_Main_receiveData(UART_PC_INST);
//             RingBuffer_Write(&uart_pc_rx_buffer, data);
//             break;
//         }
//         default:
//             break;
//     }
// }

void NMI_Handler(void)
{
    __BKPT();
}

void HardFault_Handler(void)
{
    __BKPT();
}

void SVC_Handler(void)
{
    __BKPT();
}

void PendSV_Handler(void)
{
    __BKPT();
}

void GROUP0_IRQHandler(void)
{
    __BKPT();
}

void TIMG8_IRQHandler(void)
{
    __BKPT();
}

void UART3_IRQHandler(void)
{
    __BKPT();
}

void ADC0_IRQHandler(void)
{
    __BKPT();
}

void ADC1_IRQHandler(void)
{
    __BKPT();
}

void CANFD0_IRQHandler(void)
{
    __BKPT();
}

void DAC0_IRQHandler(void)
{
    __BKPT();
}

void SPI0_IRQHandler(void)
{
    __BKPT();
}

void SPI1_IRQHandler(void)
{
    __BKPT();
}


void UART2_IRQHandler(void)
{
    __BKPT();
}




void TIMA0_IRQHandler(void)
{
    __BKPT();
}



void TIMG7_IRQHandler(void)
{
    __BKPT();
}

void TIMG12_IRQHandler(void)
{
    __BKPT();
}

void I2C0_IRQHandler(void)
{
    __BKPT();
}

void I2C1_IRQHandler(void)
{
    __BKPT();
}

void AES_IRQHandler(void)
{
    __BKPT();
}

void RTC_IRQHandler(void)
{
    __BKPT();
}

void DMA_IRQHandler(void)
{
    __BKPT();
}