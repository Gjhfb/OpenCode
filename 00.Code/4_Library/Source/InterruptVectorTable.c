






#define InterruptMark

#include "../../2_Process/Include/Cmp_Onboarding.h"

#include "../../4_Library/Include/Int.h"
#include "../../4_Library/Include/Lib_SensingADC.h"

#include "../../5_WROS/Include/WROS.h"

#include "../../6_Vablesource/Include/Vable_ModelInformation.h"

//extern void Mid_500usBaseTimer(void);
extern void MWI_UART_DispStartUartInterrupt(char,char);
extern void MWI_UART_PCStartUartInterrupt(char,char);

UINT8 gucWdt_Nmi_Count = 0;



//void     Reset_IRQHandler             ()        // Reset IRQHandler
//{}
void     NMI_IRQHandler(void)        // NMI IRQHandler
{
	gucWdt_Nmi_Count++;
	if(gucWdt_Nmi_Count >= 5)
	{
		//API_WDT_RESET_Init();
	}
	else
	{
		//API_WDT_Set_WdtClr();
	}

}
/*
void HardFault_IRQHandler(void)         // Hard Fault IRQHandler
{}
void MemManage_IRQHandler(void)         // MPU Fault IRQHandler
{}
void BusFault_IRQHandler(void)          // Bus Fault IRQHandler
{}
void UsageFault_IRQHandler(void)        // Usage Fault IRQHandler
{}
void SVCall_IRQHandler(void)            // SVCall IRQHandler
{}
void DebugMonitor_IRQHandler(void)      // Debug Monitor IRQHandler
{}
void PendSV_IRQHandler(void)            // PendSV IRQHandler
{}
void SysTick_IRQHandler(void)           // SysTick IRQHandler
{}
void LVI_IRQHandler(void)               // Low Voltage Indicator IRQHandler
{}
void SYSCLKFAIL_IRQHandler(void)        // System Clock Fail IRQHandler
{}
void HSEFAIL_IRQHandler(void)           // High-Speed External Clock Fail IRQHandler
{}
void LSEFAIL_IRQHandler(void)           // Low-Speed External Clock Fail IRQHandler
{}
void WDT_IRQHandler(void)               // Watchdog Timer IRQHandler
{

}
void FRT0_IRQHandler(void)              // Free-Running Timer 0 IRQHandler
{}
void FRT1_IRQHandler(void)              // Free-Running Timer 1 IRQHandler
{}
void CFMC_IRQHandler(void)              // Code Flash Memory Controller IRQHandler
{}
void DFMC_IRQHandler(void)              // Data Flash Memory Controller IRQHandler
{}

*/

void TIMER0_IRQHandler(void)            // Timer 0 IRQHandler
{
	WROS_TIER_0->SR	= 7;
	WROS_TIER_0->CNT_register.CNT			= CLR;

	WROS_Base_Timer();
}

void TIMER1_IRQIRQIRQHandler(void)            // Timer 1 IRQIRQHandler
{}
void TIMER2_IRQIRQHandler(void)            // Timer 2 IRQIRQHandler
{}
void TIMER3_IRQIRQHandler(void)            // Timer 3 IRQIRQHandler
{}
void TIMER4_IRQIRQHandler(void)            // Timer 4 IRQIRQHandler
{}
void TIMER5_IRQIRQHandler(void)            // Timer 5 IRQIRQHandler
{}
void TIMER6_IRQIRQHandler(void)            // Timer 6 IRQIRQHandler
{}
void TIMER7_IRQIRQHandler(void)            // Timer 7 IRQIRQHandler
{}
void TIMER8_IRQIRQHandler(void)            // Timer 8 IRQIRQHandler
{}
void TIMER9_IRQIRQHandler(void)            // Timer 9 IRQIRQHandler
{}
void RNG_IRQIRQHandler(void)               // Random Number Generator IRQHandler
{}
void AES128_IRQHandler(void)            // AES-128 IRQHandler
{}
void CEIO_IRQHandler(void)              // Crypto Engine I/O IRQHandler
{}
void GPIOA_IRQHandler(void)             // GPIO A IRQHandler
{}
void GPIOB_IRQHandler(void)             // GPIO B IRQHandler
{}
void GPIOC_IRQHandler(void)             // GPIO C IRQHandler
{}

void GPIOD_IRQHandler(void)             // GPIO D IRQHandler
{}
void GPIOE_IRQHandler(void)             // GPIO E IRQHandler
{}
void GPIOF_IRQHandler(void)             // GPIO F IRQHandler
{}
void GPIOG_IRQHandler(void)             // GPIO G IRQHandler
{}
void MPWM0PROT_IRQHandler(void)         // MPWM 0 Protection IRQHandler
{}
void MPWM0OVV_IRQHandler(void)          // MPWM 0 Overvoltage IRQHandler
{}
void MPWM0U_IRQHandler(void)            // MPWM 0 Phase U IRQHandler
{}
void MPWM0V_IRQHandler(void)            // MPWM 0 Phase V IRQHandler
{}
void MPWM0W_IRQHandler(void)            // MPWM 0 Phase W IRQHandler
{}
void MPWM1PROT_IRQHandler(void)         // MPWM 1 Protection IRQHandler
{}
void MPWM1OVV_IRQHandler(void)          // MPWM 1 Overvoltage IRQHandler
{}
void MPWM1U_IRQHandler(void)            // MPWM 1 Phase U IRQHandler
{}
void MPWM1V_IRQHandler(void)            // MPWM 1 Phase V IRQHandler
{}
void MPWM1W_IRQHandler(void)            // MPWM 1 Phase W IRQHandler
{}
void SPI0_IRQHandler(void)              // SPI 0 IRQHandler
{}
void SPI1_IRQHandler(void)              // SPI 1 IRQHandler
{}
void SPI2_IRQHandler(void)              // SPI 2 IRQHandler
{}
void I2C0_IRQHandler(void)              // I2C 0 IRQHandler
{}
void I2C1_IRQHandler(void)              // I2C 1 IRQHandler
{}
void UART0_IRQHandler(void)             // UART 0 IRQHandler
{}
void UART1_IRQHandler(void)             // UART 1 IRQHandler
{
}
void UART2_IRQHandler(void)             // UART 2 IRQHandler
{

 	//WROS_UART_4->THR_register.DATA_Buffer		= 0xC8;
	//WROS_UART_2->THR_register.DATA_Buffer		= 0xC8;

	static UINT16 UART2_DelayLoop = 0;
	UART2_DelayLoop++;
}
void UART3_IRQHandler(void)             // UART 3 IRQHandler
{
}
void UART4_IRQHandler(void)             // UART 4 IRQHandler
{
}
void UART5_IRQHandler(void)             // UART 5 IRQHandler
{}
void CAN_IRQIRQHandler(void)
{}
void ADC0_IRQIRQHandler(void)
{}
void ADC1_IRQIRQHandler(void)
{}
void ADC2_IRQIRQHandler(void)
{}
void COMP0_IRQIRQHandler(void)
{}
void COMP1_IRQIRQHandler(void)
{}
void COMP2_IRQIRQHandler(void)
{}
void COMP3_IRQIRQHandler(void)
{}
void CRC_IRQIRQHandler(void)
{}












/*
void     INTRX0_IRQIRQHandler         ()        // 6:	Serial reception (channel 0)
{
	MWI_UART_DispStartUartInterrupt(gunCommOper, 0x01);
}
void     INTTX0_IRQIRQHandler         ()        // 7:	Serial transmit (channel 0)
{
	MWI_UART_DispStartUartInterrupt(gunCommOper, 0x02);
}
void     INTTB41_IRQIRQHandler        ()        // 25:	16bit TMRB4 compare match detection 1
{
	VC_Get_Vdc();
}
void     INTTB51_IRQIRQHandler        ()        // 27:	16bit TMRB5 compare match detection 1
{
	MWI_INT_Timer0();
}
void     INTRX2_IRQIRQHandler         ()        // 40:	Serial reception (channel 2)
{
	MWI_UART_PCStartUartInterrupt(Jig2PCComm, 0x01);
}
void     INTTX2_IRQIRQHandler         ()        // 41:	Serial transmit (channel 2)
{
	MWI_UART_PCStartUartInterrupt(Jig2PCComm, 0x02);
}
*/
