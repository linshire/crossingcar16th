################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/BaseSw/iLLD/TC26B/Tricore/Gtm/Atom/Timer/IfxGtm_Atom_Timer.c 

OBJS += \
./Libraries/BaseSw/iLLD/TC26B/Tricore/Gtm/Atom/Timer/IfxGtm_Atom_Timer.o 

COMPILED_SRCS += \
./Libraries/BaseSw/iLLD/TC26B/Tricore/Gtm/Atom/Timer/IfxGtm_Atom_Timer.src 

C_DEPS += \
./Libraries/BaseSw/iLLD/TC26B/Tricore/Gtm/Atom/Timer/IfxGtm_Atom_Timer.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/BaseSw/iLLD/TC26B/Tricore/Gtm/Atom/Timer/%.src: ../Libraries/BaseSw/iLLD/TC26B/Tricore/Gtm/Atom/Timer/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D__CPU__=tc26xb -I"D:\infineon_workplace\TCTCC\CODE" -I"D:\infineon_workplace\TCTCC\Libraries" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\_Build" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\_Impl" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\_Lib" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\_Lib\DataHandling" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\_Lib\InternalMux" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\_PinMap" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Asclin" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Asclin\Asc" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Asclin\Lin" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Asclin\Spi" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Asclin\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Ccu6" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Ccu6\Icu" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Ccu6\PwmBc" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Ccu6\PwmHl" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Ccu6\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Ccu6\Timer" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Ccu6\TimerWithTrigger" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Ccu6\TPwm" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Cif" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Cif\Cam" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Cif\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Cpu" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Cpu\CStart" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Cpu\Irq" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Cpu\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Cpu\Trap" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Dma" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Dma\Dma" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Dma\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Dsadc" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Dsadc\Dsadc" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Dsadc\Rdc" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Dsadc\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Dts" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Dts\Dts" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Dts\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Emem" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Emem\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Eray" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Eray\Eray" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Eray\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Eth" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Eth\Phy_Pef7071" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Eth\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Fce" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Fce\Crc" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Fce\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Fft" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Fft\Fft" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Fft\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Flash" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Flash\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Gpt12" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Gpt12\IncrEnc" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Gpt12\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm\Atom" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm\Atom\Pwm" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm\Atom\PwmHl" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm\Atom\Timer" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm\Tim" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm\Tim\In" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm\Tom" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm\Tom\Pwm" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm\Tom\PwmHl" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm\Tom\Timer" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm\Trig" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Hssl" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Hssl\Hssl" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Hssl\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\I2c" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\I2c\I2c" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\I2c\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Iom" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Iom\Driver" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Iom\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Msc" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Msc\Msc" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Msc\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Mtu" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Mtu\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Multican" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Multican\Can" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Multican\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Port" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Port\Io" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Port\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Psi5" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Psi5\Psi5" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Psi5\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Psi5s" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Psi5s\Psi5s" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Psi5s\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Qspi" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Qspi\SpiMaster" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Qspi\SpiSlave" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Qspi\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Scu" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Scu\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Sent" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Sent\Sent" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Sent\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Smu" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Smu\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Src" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Src\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Stm" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Stm\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Stm\Timer" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Vadc" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Vadc\Adc" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\iLLD\TC26B\Tricore\Vadc\Std" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\Infra" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\Infra\Platform" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\Infra\Platform\Tricore" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\Infra\Platform\Tricore\Compilers" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\Infra\Sfr" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\Infra\Sfr\TC26B" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\Infra\Sfr\TC26B\_Reg" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\Service" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\Service\CpuGeneric" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\Service\CpuGeneric\_Utilities" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\Service\CpuGeneric\If" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\Service\CpuGeneric\If\Ccu6If" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\Service\CpuGeneric\StdIf" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\Service\CpuGeneric\SysSe" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\Service\CpuGeneric\SysSe\Bsp" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\Service\CpuGeneric\SysSe\Comm" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\Service\CpuGeneric\SysSe\General" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\Service\CpuGeneric\SysSe\Math" -I"D:\infineon_workplace\TCTCC\Libraries\BaseSw\Service\CpuGeneric\SysSe\Time" -I"D:\infineon_workplace\TCTCC\Libraries\doc" -I"D:\infineon_workplace\TCTCC\Libraries\seekfree_libraries" -I"D:\infineon_workplace\TCTCC\Libraries\seekfree_libraries\common" -I"D:\infineon_workplace\TCTCC\Libraries\seekfree_peripheral" -I"D:\infineon_workplace\TCTCC\USER" -I"D:/infineon_workplace/TCTCC/Libraries" --iso=99 --c++14 --language=+volatile --anachronisms --fp-model=3 --fp-model=c --fp-model=f --fp-model=l --fp-model=n --fp-model=r --fp-model=z -O2 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -o "$@"  "$<"  -cs --dep-file=$(@:.src=.d) --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

Libraries/BaseSw/iLLD/TC26B/Tricore/Gtm/Atom/Timer/%.o: ./Libraries/BaseSw/iLLD/TC26B/Tricore/Gtm/Atom/Timer/%.src
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '


