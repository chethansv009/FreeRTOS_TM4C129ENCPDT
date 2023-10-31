################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Core/src/%.obj: ../Core/src/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/freeRtos/workspace/FreeRTOS_project" --include_path="D:/freeRtos/workspace/FreeRTOS_project/Core/Inc" --include_path="D:/freeRtos/workspace/FreeRTOS_project/Driverlib" --include_path="D:/freeRtos/workspace/FreeRTOS_project/inc" --include_path="D:/freeRtos/workspace/FreeRTOS_project/ThirdParty/FreeRTOS/Source/include" --include_path="D:/freeRtos/workspace/FreeRTOS_project/ThirdParty/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --define=ccs="ccs" --define=PART_TM4C129ENCPDT -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Core/src/$(basename $(<F)).d_raw" --obj_directory="Core/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


