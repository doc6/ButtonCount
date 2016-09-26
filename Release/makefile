################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ButtonCount.lss \

FLASH_IMAGE += \
ButtonCount.hex \

EEPROM_IMAGE += \
ButtonCount.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: ButtonCount.elf secondary-outputs

# Tool invocations
ButtonCount.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ButtonCount.map -mmcu=atmega328p -o "ButtonCount.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ButtonCount.lss: ButtonCount.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ButtonCount.elf  >"ButtonCount.lss"
	@echo 'Finished building: $@'
	@echo ' '

ButtonCount.hex: ButtonCount.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ButtonCount.elf  "ButtonCount.hex"
	@echo 'Finished building: $@'
	@echo ' '

ButtonCount.eep: ButtonCount.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex ButtonCount.elf  "ButtonCount.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ButtonCount.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p ButtonCount.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ButtonCount.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
