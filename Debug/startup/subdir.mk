################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/svc.s 

C_SRCS += \
../startup/boot_multicore_slave.c \
../startup/startup_lpc55s69_cm33_core0.c 

OBJS += \
./startup/boot_multicore_slave.o \
./startup/startup_lpc55s69_cm33_core0.o \
./startup/svc.o 

C_DEPS += \
./startup/boot_multicore_slave.d \
./startup/startup_lpc55s69_cm33_core0.d 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DCPU_LPC55S69JBD100_cm33_core0 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/media/linux_win7_exchange/Programmation/Nxp/projet_os_enib/board" -I"/media/linux_win7_exchange/Programmation/Nxp/projet_os_enib/source" -I"/media/linux_win7_exchange/Programmation/Nxp/projet_os_enib" -I"/media/linux_win7_exchange/Programmation/Nxp/projet_os_enib/drivers" -I"/media/linux_win7_exchange/Programmation/Nxp/projet_os_enib/device" -I"/media/linux_win7_exchange/Programmation/Nxp/projet_os_enib/CMSIS" -I"/media/linux_win7_exchange/Programmation/Nxp/projet_os_enib/utilities" -I"/media/linux_win7_exchange/Programmation/Nxp/projet_os_enib/component/serial_manager" -I"/media/linux_win7_exchange/Programmation/Nxp/projet_os_enib/component/lists" -I"/media/linux_win7_exchange/Programmation/Nxp/projet_os_enib/component/uart" -I"/media/linux_win7_exchange/Programmation/Nxp/projet_os_enib/startup" -I"/projet_os_enib/kernel" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -D__REDLIB__ -Wa,-mimplicit-it=always -I"/media/linux_win7_exchange/Programmation/Nxp/projet_os_enib/board" -I"/media/linux_win7_exchange/Programmation/Nxp/projet_os_enib/source" -I"/media/linux_win7_exchange/Programmation/Nxp/projet_os_enib" -I"/media/linux_win7_exchange/Programmation/Nxp/projet_os_enib/drivers" -I"/media/linux_win7_exchange/Programmation/Nxp/projet_os_enib/device" -I"/media/linux_win7_exchange/Programmation/Nxp/projet_os_enib/CMSIS" -I"/media/linux_win7_exchange/Programmation/Nxp/projet_os_enib/utilities" -I"/media/linux_win7_exchange/Programmation/Nxp/projet_os_enib/component/serial_manager" -I"/media/linux_win7_exchange/Programmation/Nxp/projet_os_enib/component/lists" -I"/media/linux_win7_exchange/Programmation/Nxp/projet_os_enib/component/uart" -I"/media/linux_win7_exchange/Programmation/Nxp/projet_os_enib/startup" -g3 -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -specs=redlib.specs -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


