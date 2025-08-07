
#include "follow_line.h"
#include "pid.h"
#include "motor.h"
#include "xe_uart.h"
#include "clock.h"
#include "string.h"

static int8_t sensor_weights[8] = {-2, -2, -2, -1, 1, 2, 2, 2};
#define TURN_RATE 0.30

No_MCU_Sensor sensor;
unsigned char Digtal;
unsigned short white[8]={773,835,1173,1154,1130,1118,934,994};
unsigned short black[8]={412,362,606,656,593,503,681,718};


void LED_blink(){
    DL_GPIO_setPins(GPIO_LED_PORT, GPIO_LED_PIN_LED_PIN);
    mspm0_delay_ms(1000 * 0.5);
    DL_GPIO_clearPins(GPIO_LED_PORT, GPIO_LED_PIN_LED_PIN);
    mspm0_delay_ms(1000 * 0.5);
}

// 初始化后使用
void Calibration_threshold(){
    unsigned char rx_buff[256]={0};
    unsigned short Anolog[8]={0};

    mspm0_delay_ms(1000 * 5);
    Get_Anolog_Value(&sensor,Anolog);
    white[0] = Anolog[0];
    white[1] = Anolog[1];
    white[2] = Anolog[2];
    white[3] = Anolog[3];
    white[4] = Anolog[4];
    white[5] = Anolog[5];
    white[6] = Anolog[6];
    white[7] = Anolog[7];

    sprintf((char *)rx_buff,"Anolog %d-%d-%d-%d-%d-%d-%d-%d\r\n",Anolog[0],Anolog[1],Anolog[2],Anolog[3],Anolog[4],Anolog[5],Anolog[6],Anolog[7]);
    UART_send_string(UART_BLUEUART_INST, (char*)rx_buff);
    // LED
    LED_blink();

    mspm0_delay_ms(1000 * 5);
    Get_Anolog_Value(&sensor,Anolog);
    black[0] = Anolog[0];
    black[1] = Anolog[1];
    black[2] = Anolog[2];
    black[3] = Anolog[3];
    black[4] = Anolog[4];
    black[5] = Anolog[5];
    black[6] = Anolog[6];
    black[7] = Anolog[7];

    sprintf((char *)rx_buff,"Anolog %d-%d-%d-%d-%d-%d-%d-%d\r\n",Anolog[0],Anolog[1],Anolog[2],Anolog[3],Anolog[4],Anolog[5],Anolog[6],Anolog[7]);
    UART_send_string(UART_BLUEUART_INST, (char*)rx_buff);
    // LED
    LED_blink();
}


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


unsigned char rx_buff[256]={0};
void follow_line(float base_speed)
{
    static int last_direction = 0; // -1=左偏, 1=右偏

    No_Mcu_Ganv_Sensor_Task_Without_tick(&sensor);
    //获取传感器数字量结果
    Digtal=Get_Digtal_For_User(&sensor);

    // 在线内正常跑
    if (Digtal != 255) {
        float error = calc_position_error(Digtal); // 偏差值
        last_direction = (error > 0) ? 1 : ((error < 0) ? -1 : last_direction);// 本次方向

        float Kp = 70.0f;          // 比例系数，可调节
        float turn = Kp * error;   // 简单的P控制

        float left_speed  = base_speed + turn;
        float right_speed = base_speed - turn;

        set_target_speed(LEFT, left_speed);
        set_target_speed(RIGHT, right_speed);
    }
    // 循迹模块出线，执行转弯逻辑
    else{
        // 左转
        if(last_direction == -1){
            set_target_speed(LEFT, (-base_speed)*TURN_RATE + 200);
            set_target_speed(RIGHT, base_speed*TURN_RATE + 200); 
        }
        // 右转
        else if(last_direction == 1){
            set_target_speed(LEFT, base_speed*TURN_RATE + 200);
            set_target_speed(RIGHT, (-base_speed)*TURN_RATE + 200); 
        }

    }
}





