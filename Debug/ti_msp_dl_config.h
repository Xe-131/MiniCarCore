/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3507

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     80000000



/* Defines for PWM_MOTOR */
#define PWM_MOTOR_INST                                                     TIMA0
#define PWM_MOTOR_INST_IRQHandler                               TIMA0_IRQHandler
#define PWM_MOTOR_INST_INT_IRQN                                 (TIMA0_INT_IRQn)
#define PWM_MOTOR_INST_CLK_FREQ                                         40000000
/* GPIO defines for channel 2 */
#define GPIO_PWM_MOTOR_C2_PORT                                             GPIOB
#define GPIO_PWM_MOTOR_C2_PIN                                      DL_GPIO_PIN_0
#define GPIO_PWM_MOTOR_C2_IOMUX                                  (IOMUX_PINCM12)
#define GPIO_PWM_MOTOR_C2_IOMUX_FUNC                 IOMUX_PINCM12_PF_TIMA0_CCP2
#define GPIO_PWM_MOTOR_C2_IDX                                DL_TIMER_CC_2_INDEX
/* GPIO defines for channel 3 */
#define GPIO_PWM_MOTOR_C3_PORT                                             GPIOB
#define GPIO_PWM_MOTOR_C3_PIN                                     DL_GPIO_PIN_13
#define GPIO_PWM_MOTOR_C3_IOMUX                                  (IOMUX_PINCM30)
#define GPIO_PWM_MOTOR_C3_IOMUX_FUNC                 IOMUX_PINCM30_PF_TIMA0_CCP3
#define GPIO_PWM_MOTOR_C3_IDX                                DL_TIMER_CC_3_INDEX



/* Defines for TIMER_PID */
#define TIMER_PID_INST                                                   (TIMA1)
#define TIMER_PID_INST_IRQHandler                               TIMA1_IRQHandler
#define TIMER_PID_INST_INT_IRQN                                 (TIMA1_INT_IRQn)
#define TIMER_PID_INST_LOAD_VALUE                                          (49U)
/* Defines for TIMER_GENERAL */
#define TIMER_GENERAL_INST                                               (TIMG6)
#define TIMER_GENERAL_INST_IRQHandler                           TIMG6_IRQHandler
#define TIMER_GENERAL_INST_INT_IRQN                             (TIMG6_INT_IRQn)
#define TIMER_GENERAL_INST_LOAD_VALUE                                    (1997U)



/* Defines for UART_BLUEUART */
#define UART_BLUEUART_INST                                                 UART2
#define UART_BLUEUART_INST_FREQUENCY                                    40000000
#define UART_BLUEUART_INST_IRQHandler                           UART2_IRQHandler
#define UART_BLUEUART_INST_INT_IRQN                               UART2_INT_IRQn
#define GPIO_UART_BLUEUART_RX_PORT                                         GPIOB
#define GPIO_UART_BLUEUART_TX_PORT                                         GPIOB
#define GPIO_UART_BLUEUART_RX_PIN                                 DL_GPIO_PIN_16
#define GPIO_UART_BLUEUART_TX_PIN                                 DL_GPIO_PIN_15
#define GPIO_UART_BLUEUART_IOMUX_RX                              (IOMUX_PINCM33)
#define GPIO_UART_BLUEUART_IOMUX_TX                              (IOMUX_PINCM32)
#define GPIO_UART_BLUEUART_IOMUX_RX_FUNC               IOMUX_PINCM33_PF_UART2_RX
#define GPIO_UART_BLUEUART_IOMUX_TX_FUNC               IOMUX_PINCM32_PF_UART2_TX
#define UART_BLUEUART_BAUD_RATE                                         (115200)
#define UART_BLUEUART_IBRD_40_MHZ_115200_BAUD                               (21)
#define UART_BLUEUART_FBRD_40_MHZ_115200_BAUD                               (45)





/* Defines for ADC12_FOLLOW_LINE */
#define ADC12_FOLLOW_LINE_INST                                              ADC0
#define ADC12_FOLLOW_LINE_INST_IRQHandler                         ADC0_IRQHandler
#define ADC12_FOLLOW_LINE_INST_INT_IRQN                          (ADC0_INT_IRQn)
#define ADC12_FOLLOW_LINE_ADCMEM_ADC_Channel0                      DL_ADC12_MEM_IDX_0
#define ADC12_FOLLOW_LINE_ADCMEM_ADC_Channel0_REF         DL_ADC12_REFERENCE_VOLTAGE_VDDA
#define ADC12_FOLLOW_LINE_ADCMEM_ADC_Channel0_REF_VOLTAGE_V                                     3.3
#define GPIO_ADC12_FOLLOW_LINE_C0_PORT                                     GPIOA
#define GPIO_ADC12_FOLLOW_LINE_C0_PIN                             DL_GPIO_PIN_27



/* Port definition for Pin Group GPIO_SWICH */
#define GPIO_SWICH_PORT                                                  (GPIOB)

/* Defines for PIN_S2: GPIOB.21 with pinCMx 49 on package pin 20 */
// groups represented: ["GPIO_ENCODER_LEFT","GPIO_ENCODER_RIGHT","GPIO_SWICH"]
// pins affected: ["PIN_EA_LEFT","PIN_EA_RIGHT","PIN_S2"]
#define GPIO_MULTIPLE_GPIOB_INT_IRQN                            (GPIOB_INT_IRQn)
#define GPIO_MULTIPLE_GPIOB_INT_IIDX            (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define GPIO_SWICH_PIN_S2_IIDX                              (DL_GPIO_IIDX_DIO21)
#define GPIO_SWICH_PIN_S2_PIN                                   (DL_GPIO_PIN_21)
#define GPIO_SWICH_PIN_S2_IOMUX                                  (IOMUX_PINCM49)
/* Port definition for Pin Group GPIO_LED */
#define GPIO_LED_PORT                                                    (GPIOA)

/* Defines for PIN_LED: GPIOA.25 with pinCMx 55 on package pin 26 */
#define GPIO_LED_PIN_LED_PIN                                    (DL_GPIO_PIN_25)
#define GPIO_LED_PIN_LED_IOMUX                                   (IOMUX_PINCM55)
/* Port definition for Pin Group GPIO_MOTOR */
#define GPIO_MOTOR_PORT                                                  (GPIOB)

/* Defines for PIN_STSNDBY: GPIOB.1 with pinCMx 13 on package pin 48 */
#define GPIO_MOTOR_PIN_STSNDBY_PIN                               (DL_GPIO_PIN_1)
#define GPIO_MOTOR_PIN_STSNDBY_IOMUX                             (IOMUX_PINCM13)
/* Defines for PIN_LEFT_DIRECT_1: GPIOB.2 with pinCMx 15 on package pin 50 */
#define GPIO_MOTOR_PIN_LEFT_DIRECT_1_PIN                         (DL_GPIO_PIN_2)
#define GPIO_MOTOR_PIN_LEFT_DIRECT_1_IOMUX                       (IOMUX_PINCM15)
/* Defines for PIN_LEFT_DIRECT_2: GPIOB.6 with pinCMx 23 on package pin 58 */
#define GPIO_MOTOR_PIN_LEFT_DIRECT_2_PIN                         (DL_GPIO_PIN_6)
#define GPIO_MOTOR_PIN_LEFT_DIRECT_2_IOMUX                       (IOMUX_PINCM23)
/* Defines for PIN_RIGHT_DIRECT_1: GPIOB.8 with pinCMx 25 on package pin 60 */
#define GPIO_MOTOR_PIN_RIGHT_DIRECT_1_PIN                        (DL_GPIO_PIN_8)
#define GPIO_MOTOR_PIN_RIGHT_DIRECT_1_IOMUX                      (IOMUX_PINCM25)
/* Defines for PIN_RIGHT_DIRECT_2: GPIOB.9 with pinCMx 26 on package pin 61 */
#define GPIO_MOTOR_PIN_RIGHT_DIRECT_2_PIN                        (DL_GPIO_PIN_9)
#define GPIO_MOTOR_PIN_RIGHT_DIRECT_2_IOMUX                      (IOMUX_PINCM26)
/* Port definition for Pin Group GPIO_ENCODER_LEFT */
#define GPIO_ENCODER_LEFT_PORT                                           (GPIOB)

/* Defines for PIN_EA_LEFT: GPIOB.12 with pinCMx 29 on package pin 64 */
#define GPIO_ENCODER_LEFT_PIN_EA_LEFT_IIDX                  (DL_GPIO_IIDX_DIO12)
#define GPIO_ENCODER_LEFT_PIN_EA_LEFT_PIN                       (DL_GPIO_PIN_12)
#define GPIO_ENCODER_LEFT_PIN_EA_LEFT_IOMUX                      (IOMUX_PINCM29)
/* Defines for PIN_EB_LEFT: GPIOB.19 with pinCMx 45 on package pin 16 */
#define GPIO_ENCODER_LEFT_PIN_EB_LEFT_PIN                       (DL_GPIO_PIN_19)
#define GPIO_ENCODER_LEFT_PIN_EB_LEFT_IOMUX                      (IOMUX_PINCM45)
/* Port definition for Pin Group GPIO_ENCODER_RIGHT */
#define GPIO_ENCODER_RIGHT_PORT                                          (GPIOB)

/* Defines for PIN_EA_RIGHT: GPIOB.17 with pinCMx 43 on package pin 14 */
#define GPIO_ENCODER_RIGHT_PIN_EA_RIGHT_IIDX                (DL_GPIO_IIDX_DIO17)
#define GPIO_ENCODER_RIGHT_PIN_EA_RIGHT_PIN                     (DL_GPIO_PIN_17)
#define GPIO_ENCODER_RIGHT_PIN_EA_RIGHT_IOMUX                    (IOMUX_PINCM43)
/* Defines for PIN_EB_RIGHT: GPIOB.18 with pinCMx 44 on package pin 15 */
#define GPIO_ENCODER_RIGHT_PIN_EB_RIGHT_PIN                     (DL_GPIO_PIN_18)
#define GPIO_ENCODER_RIGHT_PIN_EB_RIGHT_IOMUX                    (IOMUX_PINCM44)
/* Port definition for Pin Group GPIO_FOLLOW_LINE */
#define GPIO_FOLLOW_LINE_PORT                                            (GPIOB)

/* Defines for PIN_GPIO_FOLLOW_LINE_0: GPIOB.20 with pinCMx 48 on package pin 19 */
#define GPIO_FOLLOW_LINE_PIN_GPIO_FOLLOW_LINE_0_PIN             (DL_GPIO_PIN_20)
#define GPIO_FOLLOW_LINE_PIN_GPIO_FOLLOW_LINE_0_IOMUX            (IOMUX_PINCM48)
/* Defines for PIN_GPIO_FOLLOW_LINE_1: GPIOB.26 with pinCMx 57 on package pin 28 */
#define GPIO_FOLLOW_LINE_PIN_GPIO_FOLLOW_LINE_1_PIN             (DL_GPIO_PIN_26)
#define GPIO_FOLLOW_LINE_PIN_GPIO_FOLLOW_LINE_1_IOMUX            (IOMUX_PINCM57)
/* Defines for PIN_GPIO_FOLLOW_LINE_2: GPIOB.27 with pinCMx 58 on package pin 29 */
#define GPIO_FOLLOW_LINE_PIN_GPIO_FOLLOW_LINE_2_PIN             (DL_GPIO_PIN_27)
#define GPIO_FOLLOW_LINE_PIN_GPIO_FOLLOW_LINE_2_IOMUX            (IOMUX_PINCM58)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_MOTOR_init(void);
void SYSCFG_DL_TIMER_PID_init(void);
void SYSCFG_DL_TIMER_GENERAL_init(void);
void SYSCFG_DL_UART_BLUEUART_init(void);
void SYSCFG_DL_ADC12_FOLLOW_LINE_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
