################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/twitcrusader.c 

OBJS += \
./src/twitcrusader.o 

C_DEPS += \
./src/twitcrusader.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -DICONS_DIR=\""/Development/Workspace/ClientTwitter-TwitCrusader/src/img"\" -o"$@" "$<" `pkg-config --cflags --libs gtk+-2.0 oauth libxml-2.0`
	@echo 'Finished building: $<'
	@echo ' '

