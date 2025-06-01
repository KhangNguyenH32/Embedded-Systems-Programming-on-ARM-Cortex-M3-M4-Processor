/*
 * main.h
 *
 *  Created on: May 29, 2025
 *      Author: goato
 */

#ifndef MAIN_H_
#define MAIN_H_

#define MAX_TASKS 5

//some stack memory calculations
#define SIZE_TASK_STACK 1024U
#define SIZE_SCHED_STACK 1024U

#define SRAM_START 0x20000000U
#define SIZE_SRAM ((128)*(1024))
#define SRAM_END ((SRAM_START) + (SIZE_SRAM))

#define IDLE_STACK_START SRAM_END
#define T1_STACK_START ((IDLE_STACK_START) - (SIZE_TASK_STACK))
#define T2_STACK_START ((T1_STACK_START) - (SIZE_TASK_STACK))
#define T3_STACK_START ((T2_STACK_START) - (SIZE_TASK_STACK))
#define T4_STACK_START ((T3_STACK_START) - (SIZE_TASK_STACK))
#define SCHED_STACK_START ((T4_STACK_START) - (SIZE_SCHED_STACK))

#define TICK_HZ 1000U

#define HSI_CLOCK 16000000U
#define SYSICK_TIM_CLK HSI_CLOCK

#define SYSTICK_CSR_ENABLE_Msk (1U << 0)
#define SYSTICK_CSR_TICKINT_Msk (1U << 1)
#define SYSTICK_CSR_CLKSOURCE_Msk (1U << 2)

#define DUMMY_XPSR 0x01000000U

#define SHCRSR_MEMFAULTENA_Msk (1u << 16)
#define SHCRSR_BUSFAULTENA_Msk (1u << 17)
#define SHCRSR_USGFAULTENA_Msk (1u << 18)

#define ICSR_PENDSV_Msk (1U << 28)

#define TASK_READY_STATE 0x00
#define TASK_BLOCKED_STATE 0XFF

#define INTERRUPT_DISABLE() do{__asm volatile("MOV R0, #0x1"); __asm volatile("MSR PRIMASK, R0");} while(0)
#define INTERRUPT_ENABLE() do{__asm volatile("MOV R0, #0x0"); __asm volatile("MSR PRIMASK, R0");} while(0)

#endif /* MAIN_H_ */
