/*
 * Copyright (c) 2023, Texas Instruments Incorporated
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
 *  ============ ti_msp_dl_config.c =============
 *  Configured MSPM0 DriverLib module definitions
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */

#include "ti_msp_dl_config.h"

DL_TimerA_backupConfig gPWM_MOTORBackup;
DL_TimerA_backupConfig gTIMER_PIDBackup;
DL_TimerG_backupConfig gTIMER_GENERALBackup;

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform any initialization needed before using any board APIs
 */
SYSCONFIG_WEAK void SYSCFG_DL_init(void)
{
    SYSCFG_DL_initPower();
    SYSCFG_DL_GPIO_init();
    /* Module-Specific Initializations*/
    SYSCFG_DL_SYSCTL_init();
    SYSCFG_DL_PWM_MOTOR_init();
    SYSCFG_DL_TIMER_PID_init();
    SYSCFG_DL_TIMER_GENERAL_init();
    SYSCFG_DL_UART_BLUEUART_init();
    SYSCFG_DL_ADC12_FOLLOW_LINE_init();
    /* Ensure backup structures have no valid state */
	gPWM_MOTORBackup.backupRdy 	= false;
	gTIMER_PIDBackup.backupRdy 	= false;
	gTIMER_GENERALBackup.backupRdy 	= false;


}
/*
 * User should take care to save and restore register configuration in application.
 * See Retention Configuration section for more details.
 */
SYSCONFIG_WEAK bool SYSCFG_DL_saveConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerA_saveConfiguration(PWM_MOTOR_INST, &gPWM_MOTORBackup);
	retStatus &= DL_TimerA_saveConfiguration(TIMER_PID_INST, &gTIMER_PIDBackup);
	retStatus &= DL_TimerG_saveConfiguration(TIMER_GENERAL_INST, &gTIMER_GENERALBackup);

    return retStatus;
}


SYSCONFIG_WEAK bool SYSCFG_DL_restoreConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerA_restoreConfiguration(PWM_MOTOR_INST, &gPWM_MOTORBackup, false);
	retStatus &= DL_TimerA_restoreConfiguration(TIMER_PID_INST, &gTIMER_PIDBackup, false);
	retStatus &= DL_TimerG_restoreConfiguration(TIMER_GENERAL_INST, &gTIMER_GENERALBackup, false);

    return retStatus;
}

SYSCONFIG_WEAK void SYSCFG_DL_initPower(void)
{
    DL_GPIO_reset(GPIOA);
    DL_GPIO_reset(GPIOB);
    DL_TimerA_reset(PWM_MOTOR_INST);
    DL_TimerA_reset(TIMER_PID_INST);
    DL_TimerG_reset(TIMER_GENERAL_INST);
    DL_UART_Main_reset(UART_BLUEUART_INST);
    DL_ADC12_reset(ADC12_FOLLOW_LINE_INST);

    DL_GPIO_enablePower(GPIOA);
    DL_GPIO_enablePower(GPIOB);
    DL_TimerA_enablePower(PWM_MOTOR_INST);
    DL_TimerA_enablePower(TIMER_PID_INST);
    DL_TimerG_enablePower(TIMER_GENERAL_INST);
    DL_UART_Main_enablePower(UART_BLUEUART_INST);
    DL_ADC12_enablePower(ADC12_FOLLOW_LINE_INST);
    delay_cycles(POWER_STARTUP_DELAY);
}

SYSCONFIG_WEAK void SYSCFG_DL_GPIO_init(void)
{

    DL_GPIO_initPeripheralOutputFunction(GPIO_PWM_MOTOR_C2_IOMUX,GPIO_PWM_MOTOR_C2_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_PWM_MOTOR_C2_PORT, GPIO_PWM_MOTOR_C2_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_PWM_MOTOR_C3_IOMUX,GPIO_PWM_MOTOR_C3_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_PWM_MOTOR_C3_PORT, GPIO_PWM_MOTOR_C3_PIN);

    DL_GPIO_initPeripheralOutputFunction(
        GPIO_UART_BLUEUART_IOMUX_TX, GPIO_UART_BLUEUART_IOMUX_TX_FUNC);
    
	DL_GPIO_initPeripheralInputFunctionFeatures(
		 GPIO_UART_BLUEUART_IOMUX_RX, GPIO_UART_BLUEUART_IOMUX_RX_FUNC,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GPIO_SWICH_PIN_S2_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalOutput(GPIO_LED_PIN_LED_IOMUX);

    DL_GPIO_initDigitalOutput(GPIO_MOTOR_PIN_STSNDBY_IOMUX);

    DL_GPIO_initDigitalOutputFeatures(GPIO_MOTOR_PIN_LEFT_DIRECT_1_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);

    DL_GPIO_initDigitalOutputFeatures(GPIO_MOTOR_PIN_LEFT_DIRECT_2_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);

    DL_GPIO_initDigitalOutputFeatures(GPIO_MOTOR_PIN_RIGHT_DIRECT_1_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);

    DL_GPIO_initDigitalOutputFeatures(GPIO_MOTOR_PIN_RIGHT_DIRECT_2_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN,
		 DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GPIO_ENCODER_LEFT_PIN_EA_LEFT_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GPIO_ENCODER_LEFT_PIN_EB_LEFT_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GPIO_ENCODER_RIGHT_PIN_EA_RIGHT_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(GPIO_ENCODER_RIGHT_PIN_EB_RIGHT_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalOutput(GPIO_FOLLOW_LINE_PIN_GPIO_FOLLOW_LINE_0_IOMUX);

    DL_GPIO_initDigitalOutput(GPIO_FOLLOW_LINE_PIN_GPIO_FOLLOW_LINE_1_IOMUX);

    DL_GPIO_initDigitalOutput(GPIO_FOLLOW_LINE_PIN_GPIO_FOLLOW_LINE_2_IOMUX);

    DL_GPIO_clearPins(GPIO_LED_PORT, GPIO_LED_PIN_LED_PIN);
    DL_GPIO_enableOutput(GPIO_LED_PORT, GPIO_LED_PIN_LED_PIN);
    DL_GPIO_clearPins(GPIOB, GPIO_MOTOR_PIN_STSNDBY_PIN |
		GPIO_MOTOR_PIN_LEFT_DIRECT_1_PIN |
		GPIO_MOTOR_PIN_LEFT_DIRECT_2_PIN |
		GPIO_MOTOR_PIN_RIGHT_DIRECT_1_PIN |
		GPIO_MOTOR_PIN_RIGHT_DIRECT_2_PIN |
		GPIO_FOLLOW_LINE_PIN_GPIO_FOLLOW_LINE_0_PIN |
		GPIO_FOLLOW_LINE_PIN_GPIO_FOLLOW_LINE_1_PIN |
		GPIO_FOLLOW_LINE_PIN_GPIO_FOLLOW_LINE_2_PIN);
    DL_GPIO_enableOutput(GPIOB, GPIO_MOTOR_PIN_STSNDBY_PIN |
		GPIO_MOTOR_PIN_LEFT_DIRECT_1_PIN |
		GPIO_MOTOR_PIN_LEFT_DIRECT_2_PIN |
		GPIO_MOTOR_PIN_RIGHT_DIRECT_1_PIN |
		GPIO_MOTOR_PIN_RIGHT_DIRECT_2_PIN |
		GPIO_FOLLOW_LINE_PIN_GPIO_FOLLOW_LINE_0_PIN |
		GPIO_FOLLOW_LINE_PIN_GPIO_FOLLOW_LINE_1_PIN |
		GPIO_FOLLOW_LINE_PIN_GPIO_FOLLOW_LINE_2_PIN);
    DL_GPIO_setLowerPinsPolarity(GPIOB, DL_GPIO_PIN_12_EDGE_FALL);
    DL_GPIO_setUpperPinsPolarity(GPIOB, DL_GPIO_PIN_21_EDGE_FALL |
		DL_GPIO_PIN_17_EDGE_FALL);
    DL_GPIO_clearInterruptStatus(GPIOB, GPIO_SWICH_PIN_S2_PIN |
		GPIO_ENCODER_LEFT_PIN_EA_LEFT_PIN |
		GPIO_ENCODER_RIGHT_PIN_EA_RIGHT_PIN);
    DL_GPIO_enableInterrupt(GPIOB, GPIO_SWICH_PIN_S2_PIN |
		GPIO_ENCODER_LEFT_PIN_EA_LEFT_PIN |
		GPIO_ENCODER_RIGHT_PIN_EA_RIGHT_PIN);

}


static const DL_SYSCTL_SYSPLLConfig gSYSPLLConfig = {
    .inputFreq              = DL_SYSCTL_SYSPLL_INPUT_FREQ_16_32_MHZ,
	.rDivClk2x              = 3,
	.rDivClk1               = 0,
	.rDivClk0               = 0,
	.enableCLK2x            = DL_SYSCTL_SYSPLL_CLK2X_ENABLE,
	.enableCLK1             = DL_SYSCTL_SYSPLL_CLK1_DISABLE,
	.enableCLK0             = DL_SYSCTL_SYSPLL_CLK0_DISABLE,
	.sysPLLMCLK             = DL_SYSCTL_SYSPLL_MCLK_CLK2X,
	.sysPLLRef              = DL_SYSCTL_SYSPLL_REF_SYSOSC,
	.qDiv                   = 9,
	.pDiv                   = DL_SYSCTL_SYSPLL_PDIV_2
};
SYSCONFIG_WEAK void SYSCFG_DL_SYSCTL_init(void)
{

	//Low Power Mode is configured to be SLEEP0
    DL_SYSCTL_setBORThreshold(DL_SYSCTL_BOR_THRESHOLD_LEVEL_0);
    DL_SYSCTL_setFlashWaitState(DL_SYSCTL_FLASH_WAIT_STATE_2);

    
	DL_SYSCTL_setSYSOSCFreq(DL_SYSCTL_SYSOSC_FREQ_BASE);
	/* Set default configuration */
	DL_SYSCTL_disableHFXT();
	DL_SYSCTL_disableSYSPLL();
    DL_SYSCTL_configSYSPLL((DL_SYSCTL_SYSPLLConfig *) &gSYSPLLConfig);
    DL_SYSCTL_setULPCLKDivider(DL_SYSCTL_ULPCLK_DIV_2);
    DL_SYSCTL_setMCLKSource(SYSOSC, HSCLK, DL_SYSCTL_HSCLK_SOURCE_SYSPLL);

}


/*
 * Timer clock configuration to be sourced by  / 2 (40000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   40000000 Hz = 40000000 Hz / (2 * (0 + 1))
 */
static const DL_TimerA_ClockConfig gPWM_MOTORClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_2,
    .prescale = 0U
};

static const DL_TimerA_PWMConfig gPWM_MOTORConfig = {
    .pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN,
    .period = 4000,
    .isTimerWithFourCC = true,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_PWM_MOTOR_init(void) {

    DL_TimerA_setClockConfig(
        PWM_MOTOR_INST, (DL_TimerA_ClockConfig *) &gPWM_MOTORClockConfig);

    DL_TimerA_initPWMMode(
        PWM_MOTOR_INST, (DL_TimerA_PWMConfig *) &gPWM_MOTORConfig);

    // Set Counter control to the smallest CC index being used
    DL_TimerA_setCounterControl(PWM_MOTOR_INST,DL_TIMER_CZC_CCCTL2_ZCOND,DL_TIMER_CAC_CCCTL2_ACOND,DL_TIMER_CLC_CCCTL2_LCOND);

    DL_TimerA_setCaptureCompareOutCtl(PWM_MOTOR_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERA_CAPTURE_COMPARE_2_INDEX);

    DL_TimerA_setCaptCompUpdateMethod(PWM_MOTOR_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERA_CAPTURE_COMPARE_2_INDEX);
    DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST, 4000, DL_TIMER_CC_2_INDEX);

    DL_TimerA_setCaptureCompareOutCtl(PWM_MOTOR_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERA_CAPTURE_COMPARE_3_INDEX);

    DL_TimerA_setCaptCompUpdateMethod(PWM_MOTOR_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERA_CAPTURE_COMPARE_3_INDEX);
    DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST, 4000, DL_TIMER_CC_3_INDEX);

    DL_TimerA_enableClock(PWM_MOTOR_INST);


    
    DL_TimerA_setCCPDirection(PWM_MOTOR_INST , DL_TIMER_CC2_OUTPUT | DL_TIMER_CC3_OUTPUT );


}



/*
 * Timer clock configuration to be sourced by LFCLK /  (4096 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   99.90243902439025 Hz = 4096 Hz / (8 * (40 + 1))
 */
static const DL_TimerA_ClockConfig gTIMER_PIDClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_LFCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale    = 40U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * TIMER_PID_INST_LOAD_VALUE = (500 ms * 99.90243902439025 Hz) - 1
 */
static const DL_TimerA_TimerConfig gTIMER_PIDTimerConfig = {
    .period     = TIMER_PID_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_ONE_SHOT,
    .startTimer = DL_TIMER_STOP,
};

SYSCONFIG_WEAK void SYSCFG_DL_TIMER_PID_init(void) {

    DL_TimerA_setClockConfig(TIMER_PID_INST,
        (DL_TimerA_ClockConfig *) &gTIMER_PIDClockConfig);

    DL_TimerA_initTimerMode(TIMER_PID_INST,
        (DL_TimerA_TimerConfig *) &gTIMER_PIDTimerConfig);
    DL_TimerA_enableInterrupt(TIMER_PID_INST , DL_TIMERA_INTERRUPT_ZERO_EVENT);
    DL_TimerA_enableClock(TIMER_PID_INST);





}

/*
 * Timer clock configuration to be sourced by LFCLK /  (4096 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   99.90243902439025 Hz = 4096 Hz / (8 * (40 + 1))
 */
static const DL_TimerG_ClockConfig gTIMER_GENERALClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_LFCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale    = 40U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * TIMER_GENERAL_INST_LOAD_VALUE = (20s * 99.90243902439025 Hz) - 1
 */
static const DL_TimerG_TimerConfig gTIMER_GENERALTimerConfig = {
    .period     = TIMER_GENERAL_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_ONE_SHOT,
    .startTimer = DL_TIMER_STOP,
};

SYSCONFIG_WEAK void SYSCFG_DL_TIMER_GENERAL_init(void) {

    DL_TimerG_setClockConfig(TIMER_GENERAL_INST,
        (DL_TimerG_ClockConfig *) &gTIMER_GENERALClockConfig);

    DL_TimerG_initTimerMode(TIMER_GENERAL_INST,
        (DL_TimerG_TimerConfig *) &gTIMER_GENERALTimerConfig);
    DL_TimerG_enableInterrupt(TIMER_GENERAL_INST , DL_TIMERG_INTERRUPT_ZERO_EVENT);
    DL_TimerG_enableClock(TIMER_GENERAL_INST);





}



static const DL_UART_Main_ClockConfig gUART_BLUEUARTClockConfig = {
    .clockSel    = DL_UART_MAIN_CLOCK_BUSCLK,
    .divideRatio = DL_UART_MAIN_CLOCK_DIVIDE_RATIO_1
};

static const DL_UART_Main_Config gUART_BLUEUARTConfig = {
    .mode        = DL_UART_MAIN_MODE_NORMAL,
    .direction   = DL_UART_MAIN_DIRECTION_TX_RX,
    .flowControl = DL_UART_MAIN_FLOW_CONTROL_NONE,
    .parity      = DL_UART_MAIN_PARITY_NONE,
    .wordLength  = DL_UART_MAIN_WORD_LENGTH_8_BITS,
    .stopBits    = DL_UART_MAIN_STOP_BITS_ONE
};

SYSCONFIG_WEAK void SYSCFG_DL_UART_BLUEUART_init(void)
{
    DL_UART_Main_setClockConfig(UART_BLUEUART_INST, (DL_UART_Main_ClockConfig *) &gUART_BLUEUARTClockConfig);

    DL_UART_Main_init(UART_BLUEUART_INST, (DL_UART_Main_Config *) &gUART_BLUEUARTConfig);
    /*
     * Configure baud rate by setting oversampling and baud rate divisors.
     *  Target baud rate: 115200
     *  Actual baud rate: 115190.78
     */
    DL_UART_Main_setOversampling(UART_BLUEUART_INST, DL_UART_OVERSAMPLING_RATE_16X);
    DL_UART_Main_setBaudRateDivisor(UART_BLUEUART_INST, UART_BLUEUART_IBRD_40_MHZ_115200_BAUD, UART_BLUEUART_FBRD_40_MHZ_115200_BAUD);



    DL_UART_Main_enable(UART_BLUEUART_INST);
}

/* ADC12_FOLLOW_LINE Initialization */
static const DL_ADC12_ClockConfig gADC12_FOLLOW_LINEClockConfig = {
    .clockSel       = DL_ADC12_CLOCK_SYSOSC,
    .divideRatio    = DL_ADC12_CLOCK_DIVIDE_8,
    .freqRange      = DL_ADC12_CLOCK_FREQ_RANGE_24_TO_32,
};
SYSCONFIG_WEAK void SYSCFG_DL_ADC12_FOLLOW_LINE_init(void)
{
    DL_ADC12_setClockConfig(ADC12_FOLLOW_LINE_INST, (DL_ADC12_ClockConfig *) &gADC12_FOLLOW_LINEClockConfig);
    DL_ADC12_configConversionMem(ADC12_FOLLOW_LINE_INST, ADC12_FOLLOW_LINE_ADCMEM_ADC_Channel0,
        DL_ADC12_INPUT_CHAN_0, DL_ADC12_REFERENCE_VOLTAGE_VDDA, DL_ADC12_SAMPLE_TIMER_SOURCE_SCOMP0, DL_ADC12_AVERAGING_MODE_DISABLED,
        DL_ADC12_BURN_OUT_SOURCE_DISABLED, DL_ADC12_TRIGGER_MODE_AUTO_NEXT, DL_ADC12_WINDOWS_COMP_MODE_DISABLED);
    DL_ADC12_setPowerDownMode(ADC12_FOLLOW_LINE_INST,DL_ADC12_POWER_DOWN_MODE_MANUAL);
    DL_ADC12_setSampleTime0(ADC12_FOLLOW_LINE_INST,0);
    DL_ADC12_enableConversions(ADC12_FOLLOW_LINE_INST);
}

