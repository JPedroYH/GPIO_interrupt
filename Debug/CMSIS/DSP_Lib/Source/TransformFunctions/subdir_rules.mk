################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
CMSIS/DSP_Lib/Source/TransformFunctions/%.obj: ../CMSIS/DSP_Lib/Source/TransformFunctions/%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Juan Pedro Yanez/workspace_v10/GPIO_interrupt" --include_path="C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/include" --define=ccs="ccs" --define=PART_TM4C1294NCPDT -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="CMSIS/DSP_Lib/Source/TransformFunctions/$(basename $(<F)).d_raw" --obj_directory="CMSIS/DSP_Lib/Source/TransformFunctions" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


