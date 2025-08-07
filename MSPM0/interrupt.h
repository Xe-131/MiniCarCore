#ifndef _INTERRUPT_H_
#define _INTERRUPT_H_

// ms
# define TIMER_PID_PERIOD 10
# define TIMER_GENERAL_PERIOD 100

// 中断flag
extern uint8_t pid_timer_flag;
extern uint8_t flag_100ms;
extern uint8_t flag_1s; 
extern uint8_t S2_flag;

#endif  