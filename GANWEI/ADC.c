#include "ADC.h"
unsigned int adc_getValue(void)
{
    unsigned int gAdcResult = 0;

    //使能ADC转换
    DL_ADC12_enableConversions(ADC12_FOLLOW_LINE_INST);
    //软件触发ADC开始转换
    DL_ADC12_startConversion(ADC12_FOLLOW_LINE_INST);

    //如果当前状态 不是 空闲状态
    while (DL_ADC12_getStatus(ADC12_FOLLOW_LINE_INST) != DL_ADC12_STATUS_CONVERSION_IDLE );

    //清除触发转换状态
    DL_ADC12_stopConversion(ADC12_FOLLOW_LINE_INST);
    //失能ADC转换
    DL_ADC12_disableConversions(ADC12_FOLLOW_LINE_INST);

    //获取数据
    gAdcResult = DL_ADC12_getMemResult(ADC12_FOLLOW_LINE_INST, ADC12_FOLLOW_LINE_ADCMEM_ADC_Channel0);

    return gAdcResult;
}