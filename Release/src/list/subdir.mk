################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/list/PlayLinkedList.c 

OBJS += \
./src/list/PlayLinkedList.o 

C_DEPS += \
./src/list/PlayLinkedList.d 


# Each subdirectory must supply rules for building sources it contributes
src/list/%.o: ../src/list/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


