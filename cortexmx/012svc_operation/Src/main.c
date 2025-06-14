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

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <stdio.h>

uint32_t add_number(int x, int y)
{
	int32_t res;
	__asm("SVC #36");
	__asm("MOV %0, R0": "=r"(res) ::);
	return res;
}

uint32_t sub_number(int x, int y)
{
	int32_t res;
	__asm("SVC #37");
	__asm("MOV %0, R0": "=r"(res) ::);
	return res;
}

uint32_t mul_number(int x, int y)
{
	int32_t res;
	__asm("SVC #38");
	__asm("MOV %0, R0": "=r"(res) ::);
	return res;
}

uint32_t div_number(int x, int y)
{
	int32_t res;
	__asm("SVC #39");
	__asm("MOV %0, R0": "=r"(res) ::);
	return res;
}


int main(void)
{
	int32_t res;

	res = add_number(69, 9);
	printf("Add result is: %ld\n", res);

	res = sub_number(69, 9);
	printf("Sub result is: %ld\n", res);

	res = mul_number(69, 9);
	printf("Mul result is: %ld\n", res);

	res = div_number(69, 9);
	printf("Div result is: %ld\n", res);

    for(;;);
}

__attribute__((naked)) void SVC_Handler(void)
{
	__asm("MRS R0, MSP");
	__asm("B SVC_Handler_c");
}

void SVC_Handler_c(uint32_t *pBaseOfStackFrame)
{
	printf("in SVC handler\n");
	//1. get main stack point address
	uint8_t *pReturn_addr = (uint8_t*)pBaseOfStackFrame[6];

	//2. decrement the return address by 2 to opcode of the SVC instruction in the program memory
	pReturn_addr -= 2;

	//3. get the svc number(LSB of the opcode)
	uint8_t svc_nubmer = *pReturn_addr;

	printf("SVC number is: %d\n", svc_nubmer);

	int32_t res;
	int16_t arg0, arg1;

	arg0 = pBaseOfStackFrame[0];
	arg1 = pBaseOfStackFrame[1];

	switch(svc_nubmer)
	{
	case 36:
		res = arg0 + arg1;
		break;
	case 37:
		res = arg0 - arg1;
		break;
	case 38:
		res = arg0 * arg1;
		break;
	case 39:
		res = arg0 / arg1;
		break;
	default:
		printf("invalid nvc number");
	}

	pBaseOfStackFrame[0] = res;
}
