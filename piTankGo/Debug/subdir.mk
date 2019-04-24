################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../fsm.c \
../kbhit.c \
../piTankGo_1.c \
../player.c \
../servo_basico.c \
../teclado_TL04.c \
../tmr.c \
../torreta.c 

OBJS += \
./fsm.o \
./kbhit.o \
./piTankGo_1.o \
./player.o \
./servo_basico.o \
./teclado_TL04.o \
./tmr.o \
./torreta.o 

C_DEPS += \
./fsm.d \
./kbhit.d \
./piTankGo_1.d \
./player.d \
./servo_basico.d \
./teclado_TL04.d \
./tmr.d \
./torreta.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -I/home/enrique/wiringPi/wiringPi -I/home/enrique/eclipse-include/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


