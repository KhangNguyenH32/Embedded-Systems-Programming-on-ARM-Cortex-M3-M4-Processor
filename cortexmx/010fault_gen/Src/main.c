/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void UsageFault_Handler_c(uint32_t *pMSP);


int main(void)
{
    //1. enable all configurable exceptions like usage fault, mem manage fault and bus fault

	uint32_t *pSHCRS = (uint32_t*)0xE000ED24;

	*pSHCRS |= (1 << 16); //mem manage
	*pSHCRS |= (1 << 17); //bus fault
	*pSHCRS |= (1 << 18); //usage fault

	//3. lets force the processor to execute some undefined instruction
	uint32_t *pSRAM = (uint32_t*)0x20010000;
	*pSRAM = 0xFFFFFFFF;

	void (*some_address)(void);

	some_address = (void*)0x20010001;

	some_address();

	//4. analyze the fault

	for(;;);
}

void HardFault_Handler(void)
{
	printf("Exception: HardFault\n");
	while(1);
}

void MemManage_Handler(void)
{
	printf("Exception: MemManage\n");
	while(1);
}

void BusFault_Handler(void)
{
	printf("Exception: BusFault\n");
	while(1);
}

__attribute__((naked)) void UsageFault_Handler(void)
{
	//here we extracted the value of msp which happens to be the
	//base address of the stack frame(thread mode) which got saved during the exception entry
	//from thread mode to handler mode
	__asm("MRS r0, MSP");
	__asm("B UsageFault_Handler_c");
}

void UsageFault_Handler_c(uint32_t *pBaseStackFrame)
{
	uint32_t *pUFSR = (uint32_t*)0xE000ED2A;
	printf("Exception: UsageFault\n");
	printf("UFSR = %lx\n",(*pUFSR) & 0xFFFF);
	printf("pBaseStackFrame = %p\n", pBaseStackFrame);
	printf("Value of R0 = %lx\n", pBaseStackFrame[0]);
	printf("Value of R1 = %lx\n", pBaseStackFrame[1]);
	printf("Value of R2 = %lx\n", pBaseStackFrame[2]);
	printf("Value of R3 = %lx\n", pBaseStackFrame[3]);
	printf("Value of R12 = %lx\n", pBaseStackFrame[4]);
	printf("Value of LR = %lx\n", pBaseStackFrame[5]);
	printf("Value of PC = %lx\n", pBaseStackFrame[6]);
	printf("Value of XPSR = %lx\n", pBaseStackFrame[7]);
	while(1);
}
