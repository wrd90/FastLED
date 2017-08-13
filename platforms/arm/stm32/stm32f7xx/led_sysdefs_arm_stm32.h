#ifndef __INC_LED_SYSDEFS_ARM_STM32F7XX_H
#define __INC_LED_SYSDEFS_ARM_STM32F7XX_H

//#define FASTLED_NAMESPACE_BEGIN namespace NSFastLED {
//#define FASTLED_NAMESPACE_END }
//#define FASTLED_USING_NAMESPACE using namespace NSFastLED;
#include "myFastPin.h"

typedef uint8_t byte;
typedef uint8_t boolean;

uint32_t millis(void)
{
	return (HAL_GetTick()*1000U);
}

uint32_t micros(void)
{
	return HAL_GetTick();
}

void delayMicroseconds(uint32_t auWaitTime)
{
	uint32_t uStartTime = micros();
	uint32_t uEndTime = uStartTime + auWaitTime;

	while(micros() < uEndTime);
}
#define FASTLED_ARM

#ifndef INTERRUPT_THRESHOLD
#define INTERRUPT_THRESHOLD 1
#endif

// Default to allowing interrupts
#ifndef FASTLED_ALLOW_INTERRUPTS
#define FASTLED_ALLOW_INTERRUPTS 1
#endif

#if FASTLED_ALLOW_INTERRUPTS == 1
#define FASTLED_ACCURATE_CLOCK
#endif

// reusing/abusing cli/sei defs for due
#define cli()  __disable_irq(); __disable_fault_irq();
#define sei() __enable_irq(); __enable_fault_irq();

// pgmspace definitions
#define PROGMEM
#define pgm_read_dword(addr) (*(const unsigned long *)(addr))
#define pgm_read_dword_near(addr) pgm_read_dword(addr)

// Default to NOT using PROGMEM here
#ifndef FASTLED_USE_PROGMEM
#define FASTLED_USE_PROGMEM 0
#endif

// data type defs
typedef volatile       uint32_t RoReg; /**< Read only 32-bit register (volatile const unsigned int) */
typedef volatile       uint32_t RwReg; /**< Read-Write 32-bit register (volatile unsigned int) */

//#define FASTLED_NO_PINMAP

#define F_CPU 216000000

#endif
