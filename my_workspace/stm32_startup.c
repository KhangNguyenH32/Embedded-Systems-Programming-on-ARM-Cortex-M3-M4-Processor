#include<stdint.h>

#define SRAM_START 0x20000000U
#define SRAM_SIZE (128U * 1024U) //128KB
#define SRAM_END ((SRAM_START) + (SRAM_SIZE))

#define STACK_START SRAM_END

extern uint32_t	_etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _la_data;
extern uint32_t _sbss;
extern uint32_t _ebss;

//prototype of main

int main(void);

void __libc_init_array(void);

/* function prototypes of STM32F407x system exception and IRQ handlers */

void Reset_Handler(void);

void NMI_Handler 					(void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler 			(void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler 					(void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler   				(void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler  				(void) __attribute__ ((weak, alias("Default_Handler")));
void WWDG_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void PVD_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));             
void TAMP_STAMP_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));      
void RTC_WKUP_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));                               
void RCC_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));             
void EXTI0_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI1_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI2_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI3_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI4_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void DMA1_Stream0_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream1_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream2_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream3_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream4_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream5_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream6_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void ADC_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));             
void CAN1_TX_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void CAN1_RX0_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));        
void CAN1_RX1_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));        
void CAN1_SCE_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));        
void EXTI9_5_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void TIM1_BRK_TIM9_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));   
void TIM1_UP_TIM10_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));   
void TIM1_TRG_COM_TIM11_IRQHandler 	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void TIM2_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));            
void TIM3_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));            
void TIM4_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));            
void I2C1_EV_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void I2C1_ER_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void I2C2_EV_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void I2C2_ER_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void SPI1_IRQHandler  				(void) __attribute__ ((weak, alias("Default_Handler")));           
void SPI2_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));            
void USART1_IRQHandler  			(void) __attribute__ ((weak, alias("Default_Handler")));         
void USART2_IRQHandler  			(void) __attribute__ ((weak, alias("Default_Handler")));        
void USART3_IRQHandler   			(void) __attribute__ ((weak, alias("Default_Handler")));        
void EXTI15_10_IRQHandler   		(void) __attribute__ ((weak, alias("Default_Handler")));     
void RTC_Alarm_IRQHandler    		(void) __attribute__ ((weak, alias("Default_Handler")));    
void OTG_FS_WKUP_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler"))); 
void TIM8_BRK_TIM12_IRQHandler   	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_UP_TIM13_IRQHandler    	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_TRG_COM_TIM14_IRQHandler 	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_CC_IRQHandler          	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream7_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void FSMC_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void SDIO_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM5_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void SPI3_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void UART4_IRQHandler            	(void) __attribute__ ((weak, alias("Default_Handler")));
void UART5_IRQHandler            	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM6_DAC_IRQHandler         	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM7_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream0_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream1_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream2_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream3_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream4_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void ETH_IRQHandler              	(void) __attribute__ ((weak, alias("Default_Handler")));
void ETH_WKUP_IRQHandler         	(void) __attribute__ ((weak, alias("Default_Handler")));
void CAN2_TX_IRQHandler          	(void) __attribute__ ((weak, alias("Default_Handler")));
void CAN2_RX0_IRQHandler         	(void) __attribute__ ((weak, alias("Default_Handler")));
void CAN2_RX1_IRQHandler         	(void) __attribute__ ((weak, alias("Default_Handler")));
void CAN2_SCE_IRQHandler         	(void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_FS_IRQHandler           	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream5_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream6_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream7_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void USART6_IRQHandler           	(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C3_EV_IRQHandler          	(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C3_ER_IRQHandler          	(void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_EP1_OUT_IRQHandler   	(void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_EP1_IN_IRQHandler    	(void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_WKUP_IRQHandler      	(void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_IRQHandler           	(void) __attribute__ ((weak, alias("Default_Handler")));
void DCMI_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void CRYP_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void HASH_RNG_IRQHandler         	(void) __attribute__ ((weak, alias("Default_Handler")));
void FPU_IRQHandler              	(void) __attribute__ ((weak, alias("Default_Handler"))); 

uint32_t vectors[] __attribute__((section(".isr_vector"))) = {
	STACK_START,                    // Initial Stack Pointer
	(uint32_t)&Reset_Handler,       // Reset Handler
	(uint32_t)&NMI_Handler,         // NMI Handler
	(uint32_t)&HardFault_Handler,   // Hard Fault Handler
	(uint32_t)&MemManage_Handler,   // MPU Fault Handler
	(uint32_t)&BusFault_Handler,    // Bus Fault Handler
	(uint32_t)&UsageFault_Handler,  // Usage Fault Handler
	0,                              // Reserved
	0,                              // Reserved
	0,                              // Reserved
	0,                              // Reserved
	(uint32_t)&SVC_Handler,         // SVCall Handler
	(uint32_t)&DebugMon_Handler,    // Debug Monitor Handler
	0,                              // Reserved
	(uint32_t)&PendSV_Handler,      // PendSV Handler
	(uint32_t)&SysTick_Handler,     // SysTick Handler

	// External Interrupts (IRQ 0 - 81 for STM32F407)
	(uint32_t)&WWDG_IRQHandler,                // IRQ 0
	(uint32_t)&PVD_IRQHandler,                 // IRQ 1
	(uint32_t)&TAMP_STAMP_IRQHandler,          // IRQ 2
	(uint32_t)&RTC_WKUP_IRQHandler,            // IRQ 3
	(uint32_t)&RCC_IRQHandler,                 // IRQ 4
	(uint32_t)&EXTI0_IRQHandler,               // IRQ 5
	(uint32_t)&EXTI1_IRQHandler,               // IRQ 6
	(uint32_t)&EXTI2_IRQHandler,               // IRQ 7
	(uint32_t)&EXTI3_IRQHandler,               // IRQ 8
	(uint32_t)&EXTI4_IRQHandler,               // IRQ 9
	(uint32_t)&DMA1_Stream0_IRQHandler,        // IRQ 10
	(uint32_t)&DMA1_Stream1_IRQHandler,        // IRQ 11
	(uint32_t)&DMA1_Stream2_IRQHandler,        // IRQ 12
	(uint32_t)&DMA1_Stream3_IRQHandler,        // IRQ 13
	(uint32_t)&DMA1_Stream4_IRQHandler,        // IRQ 14
	(uint32_t)&DMA1_Stream5_IRQHandler,        // IRQ 15
	(uint32_t)&DMA1_Stream6_IRQHandler,        // IRQ 16
	(uint32_t)&ADC_IRQHandler,                 // IRQ 17
	(uint32_t)&CAN1_TX_IRQHandler,             // IRQ 18
	(uint32_t)&CAN1_RX0_IRQHandler,            // IRQ 19
	(uint32_t)&CAN1_RX1_IRQHandler,            // IRQ 20
	(uint32_t)&CAN1_SCE_IRQHandler,            // IRQ 21
	(uint32_t)&EXTI9_5_IRQHandler,             // IRQ 22
	(uint32_t)&TIM1_BRK_TIM9_IRQHandler,       // IRQ 23
	(uint32_t)&TIM1_UP_TIM10_IRQHandler,       // IRQ 24
	(uint32_t)&TIM1_TRG_COM_TIM11_IRQHandler,  // IRQ 25
	(uint32_t)&TIM1_CC_IRQHandler,             // IRQ 26
	(uint32_t)&TIM2_IRQHandler,                // IRQ 27
	(uint32_t)&TIM3_IRQHandler,                // IRQ 28
	(uint32_t)&TIM4_IRQHandler,                // IRQ 29
	(uint32_t)&I2C1_EV_IRQHandler,             // IRQ 30
	(uint32_t)&I2C1_ER_IRQHandler,             // IRQ 31
	(uint32_t)&I2C2_EV_IRQHandler,             // IRQ 32
	(uint32_t)&I2C2_ER_IRQHandler,             // IRQ 33
	(uint32_t)&SPI1_IRQHandler,                // IRQ 34
	(uint32_t)&SPI2_IRQHandler,                // IRQ 35
	(uint32_t)&USART1_IRQHandler,              // IRQ 36
	(uint32_t)&USART2_IRQHandler,              // IRQ 37
	(uint32_t)&USART3_IRQHandler,              // IRQ 38
	(uint32_t)&EXTI15_10_IRQHandler,           // IRQ 39
	(uint32_t)&RTC_Alarm_IRQHandler,           // IRQ 40
	(uint32_t)&OTG_FS_WKUP_IRQHandler,         // IRQ 41
	(uint32_t)&TIM8_BRK_TIM12_IRQHandler,      // IRQ 42
	(uint32_t)&TIM8_UP_TIM13_IRQHandler,       // IRQ 43
	(uint32_t)&TIM8_TRG_COM_TIM14_IRQHandler,  // IRQ 44
	(uint32_t)&TIM8_CC_IRQHandler,             // IRQ 45
	(uint32_t)&DMA1_Stream7_IRQHandler,        // IRQ 46
	(uint32_t)&FSMC_IRQHandler,                // IRQ 47
	(uint32_t)&SDIO_IRQHandler,                // IRQ 48
	(uint32_t)&TIM5_IRQHandler,                // IRQ 49
	(uint32_t)&SPI3_IRQHandler,                // IRQ 50
	(uint32_t)&UART4_IRQHandler,               // IRQ 51
	(uint32_t)&UART5_IRQHandler,               // IRQ 52
	(uint32_t)&TIM6_DAC_IRQHandler,            // IRQ 53
	(uint32_t)&TIM7_IRQHandler,                // IRQ 54
	(uint32_t)&DMA2_Stream0_IRQHandler,        // IRQ 55
	(uint32_t)&DMA2_Stream1_IRQHandler,        // IRQ 56
	(uint32_t)&DMA2_Stream2_IRQHandler,        // IRQ 57
	(uint32_t)&DMA2_Stream3_IRQHandler,        // IRQ 58
	(uint32_t)&DMA2_Stream4_IRQHandler,        // IRQ 59
	(uint32_t)&ETH_IRQHandler,                 // IRQ 60
	(uint32_t)&ETH_WKUP_IRQHandler,            // IRQ 61
	(uint32_t)&CAN2_TX_IRQHandler,             // IRQ 62
	(uint32_t)&CAN2_RX0_IRQHandler,            // IRQ 63
	(uint32_t)&CAN2_RX1_IRQHandler,            // IRQ 64
	(uint32_t)&CAN2_SCE_IRQHandler,            // IRQ 65
	(uint32_t)&OTG_FS_IRQHandler,              // IRQ 66
	(uint32_t)&DMA2_Stream5_IRQHandler,        // IRQ 67
	(uint32_t)&DMA2_Stream6_IRQHandler,        // IRQ 68
	(uint32_t)&DMA2_Stream7_IRQHandler,        // IRQ 69
	(uint32_t)&USART6_IRQHandler,              // IRQ 70
	(uint32_t)&I2C3_EV_IRQHandler,             // IRQ 71
	(uint32_t)&I2C3_ER_IRQHandler,             // IRQ 72
	(uint32_t)&OTG_HS_EP1_OUT_IRQHandler,      // IRQ 73
	(uint32_t)&OTG_HS_EP1_IN_IRQHandler,       // IRQ 74
	(uint32_t)&OTG_HS_WKUP_IRQHandler,         // IRQ 75
	(uint32_t)&OTG_HS_IRQHandler,              // IRQ 76
	(uint32_t)&DCMI_IRQHandler,                // IRQ 77
	(uint32_t)&CRYP_IRQHandler,                // IRQ 78
	(uint32_t)&HASH_RNG_IRQHandler,            // IRQ 79
	(uint32_t)&FPU_IRQHandler                  // IRQ 80
};
void Reset_Handler(void)
{
	//copy .data section to SRAM_END
	uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata;
	
	uint8_t *pDst = (uint8_t*)&_sdata; //sram
	uint8_t *pSrc = (uint8_t*)&_la_data; //flash
		
	for(uint32_t i = 0; i < size; i++)
	{
		*pDst++ = *pSrc++;
	}
	//Init the .bss section to zero in SRAM
	size = (uint32_t)&_ebss - (uint32_t)&_sbss;
	pDst = (uint8_t*)&_sbss;
	for(uint32_t i = 0; i < size; i++)
	{
		*pDst++ = 0;
	}
	
	__libc_init_array();

	main();
}

void Default_Handler(void)
{
	while(1);
}
