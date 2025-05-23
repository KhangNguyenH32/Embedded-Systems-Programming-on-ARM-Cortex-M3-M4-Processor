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

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
#if 0
    __asm volatile("LDR R1, =#0x20001000");
    __asm volatile("LDR R2, =#0x20001004");
    __asm volatile("LDR R0, [R1]");
    __asm volatile("LDR R1, [R2]");
    __asm volatile("ADD R0, R0, R1");
    __asm volatile("STR R0, [R2]");
#endif

    int val = 50;
    __asm volatile("MOV R0, %0": : "r"(val));

    int control_reg;
    //read CONTROL register to control_reg
    __asm volatile("MRS %0, CONTROL": "=r"(control_reg));

    int p1, *p2;

    p2 = (int*)0x20000002;

    __asm volatile("LDR %0, [%1]": "=r"(p1): "r"(p2));

    for(;;);
}
