################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cJson/cJSON.c 

OBJS += \
./src/cJson/cJSON.o 

C_DEPS += \
./src/cJson/cJSON.d 


# Each subdirectory must supply rules for building sources it contributes
src/cJson/%.o: ../src/cJson/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


