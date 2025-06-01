/*
 * led.c
 *
 *  Created on: May 30, 2025
 *      Author: goato
 */
#include<stdint.h>

void led_init_all(void)
{

	uint32_t *pClkCtrlReg = (uint32_t*)0x40023830;
	uint32_t *pPortDModeReg = (uint32_t*)0x40020C00;

	// Enable the clock for GPIOD peripheral in the AHB1ENR (SET the 3rd bit position)
	*pClkCtrlReg |= (1 << 3);

	// Configure the mode of IO pin as ouput
	// Clear the 24th-31st bit position (CLEAR)
	*pPortDModeReg &= ~(0xFF << 24);

	// Make the 24th, 26th, 28th and 30th bit as 1 (SET)
	*pPortDModeReg |= (0x55 << 24);
}

void led_on(uint8_t led_no)
{
	uint32_t *pPortDOutReg = (uint32_t*)0x40020C14;
	*pPortDOutReg |= (1 << led_no);
}

void led_off(uint8_t led_no)
{
	uint32_t *pPortDOutReg = (uint32_t*)0x40020C14;
	*pPortDOutReg &= ~(1 << led_no);
}
