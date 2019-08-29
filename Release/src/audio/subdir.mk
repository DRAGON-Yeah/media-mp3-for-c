################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/audio/audioplayer.c \
../src/audio/cmdutils.c \
../src/audio/strutils.c 

OBJS += \
./src/audio/audioplayer.o \
./src/audio/cmdutils.o \
./src/audio/strutils.o 

C_DEPS += \
./src/audio/audioplayer.d \
./src/audio/cmdutils.d \
./src/audio/strutils.d 


# Each subdirectory must supply rules for building sources it contributes
src/audio/%.o: ../src/audio/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


