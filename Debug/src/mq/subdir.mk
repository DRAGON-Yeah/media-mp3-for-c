################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/mq/IPCMQ.c 

OBJS += \
./src/mq/IPCMQ.o 

C_DEPS += \
./src/mq/IPCMQ.d 


# Each subdirectory must supply rules for building sources it contributes
src/mq/%.o: ../src/mq/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


