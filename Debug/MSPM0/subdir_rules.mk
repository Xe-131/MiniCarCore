################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
MSPM0/%.o: ../MSPM0/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/APPLICATION/TIccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/Xe-131/workspace_ccstheia/2025X/UART" -I"C:/Users/Xe-131/workspace_ccstheia/2025X/MSPM0" -I"C:/Users/Xe-131/workspace_ccstheia/2025X/MPU6050" -I"C:/Users/Xe-131/workspace_ccstheia/2025X/GANWEI" -I"C:/Users/Xe-131/workspace_ccstheia/2025X/motor" -I"C:/Users/Xe-131/workspace_ccstheia/2025X" -I"C:/Users/Xe-131/workspace_ccstheia/2025X/Debug" -I"C:/APPLICATION/ti_SDK/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/APPLICATION/ti_SDK/mspm0_sdk_2_04_00_06/source" -gdwarf-3 -MMD -MP -MF"MSPM0/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


