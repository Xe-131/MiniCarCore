################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-248725855: ../2025X.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/APPLICATION/TIccs2011/ccs/utils/sysconfig_1.24.0/sysconfig_cli.bat" --script "C:/Users/Xe-131/workspace_ccstheia/2025X/2025X.syscfg" -o "." -s "C:/APPLICATION/ti_SDK/mspm0_sdk_2_04_00_06/.metadata/product.json" -s "C:/APPLICATION/ti_SDK/mspm0_sdk_2_04_00_06/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

device_linker.cmd: build-248725855 ../2025X.syscfg
device.opt: build-248725855
device.cmd.genlibs: build-248725855
ti_msp_dl_config.c: build-248725855
ti_msp_dl_config.h: build-248725855
Event.dot: build-248725855

%.o: ./%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/APPLICATION/TIccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/Xe-131/workspace_ccstheia/2025X/UART" -I"C:/Users/Xe-131/workspace_ccstheia/2025X/MSPM0" -I"C:/Users/Xe-131/workspace_ccstheia/2025X/MPU6050" -I"C:/Users/Xe-131/workspace_ccstheia/2025X/GANWEI" -I"C:/Users/Xe-131/workspace_ccstheia/2025X/motor" -I"C:/Users/Xe-131/workspace_ccstheia/2025X" -I"C:/Users/Xe-131/workspace_ccstheia/2025X/Debug" -I"C:/APPLICATION/ti_SDK/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/APPLICATION/ti_SDK/mspm0_sdk_2_04_00_06/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_mspm0g350x_ticlang.o: C:/APPLICATION/ti_SDK/mspm0_sdk_2_04_00_06/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/APPLICATION/TIccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/Xe-131/workspace_ccstheia/2025X/UART" -I"C:/Users/Xe-131/workspace_ccstheia/2025X/MSPM0" -I"C:/Users/Xe-131/workspace_ccstheia/2025X/MPU6050" -I"C:/Users/Xe-131/workspace_ccstheia/2025X/GANWEI" -I"C:/Users/Xe-131/workspace_ccstheia/2025X/motor" -I"C:/Users/Xe-131/workspace_ccstheia/2025X" -I"C:/Users/Xe-131/workspace_ccstheia/2025X/Debug" -I"C:/APPLICATION/ti_SDK/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/APPLICATION/ti_SDK/mspm0_sdk_2_04_00_06/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/APPLICATION/TIccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/Xe-131/workspace_ccstheia/2025X/UART" -I"C:/Users/Xe-131/workspace_ccstheia/2025X/MSPM0" -I"C:/Users/Xe-131/workspace_ccstheia/2025X/MPU6050" -I"C:/Users/Xe-131/workspace_ccstheia/2025X/GANWEI" -I"C:/Users/Xe-131/workspace_ccstheia/2025X/motor" -I"C:/Users/Xe-131/workspace_ccstheia/2025X" -I"C:/Users/Xe-131/workspace_ccstheia/2025X/Debug" -I"C:/APPLICATION/ti_SDK/mspm0_sdk_2_04_00_06/source/third_party/CMSIS/Core/Include" -I"C:/APPLICATION/ti_SDK/mspm0_sdk_2_04_00_06/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


