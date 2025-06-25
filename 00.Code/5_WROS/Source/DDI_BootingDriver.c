
#include "../../4_Library/Include/general.h"

#include "../../5_WROS/Include/WROS.h"
#include "../../5_WROS/Include/a34m41x.h"
#include "../../5_WROS/Include/DDI_BootingDriver.h"
#include "../../5_WROS/Include/DDI_RegisterDriver.h"




void Init_WDT_Register(void);


struct SMR_Register		SMR_Registers;
struct SRCR_Register		SRCR_Registers;
struct WUER_Register		WUER_Registers;
struct WUSR_Register		WUSR_Registers;
struct RSER_Register		RSER_Registers;
struct RSSR_Register		RSSR_Registers;
struct PRER1_Register		PRER1_Registers;
struct PRER2_Register		PRER2_Registers;
struct PER1_Register		PER1_Registers;
struct PER2_Register		PER2_Registers;
struct PCER1_Register		PCER1_Registers;
struct PCER2_Register		PCER2_Registers;
struct CSCR_Register		CSCR_Registers;
struct SCCR_Register		SCCR_Registers;
struct CMR_Register		CMR_Registers;
struct COR_Register		COR_Registers;
struct NMICR_Register		NMICR_Registers;
struct NMISR_Register		NMISR_Registers;
struct PLLCON_Register		PLLCON_Registers;
struct VDCCON_Register		VDCCON_Registers;
struct LVICR_Register		LVICR_Registers;
struct LVISR_Register		LVISR_Registers;
struct LVRCR_Register		LVRCR_Registers;
struct MCCR1_Register		MCCR1_Registers;
struct MCCR2_Register		MCCR2_Registers;
struct MCCR3_Register		MCCR3_Registers;
struct MCCR4_Register		MCCR4_Registers;
struct MCCR5_Register		MCCR5_Registers;
struct MCCR6_Register		MCCR6_Registers;
struct MCCR7_Register		MCCR7_Registers;
struct SYSTEN_Register		SYSTEN_Registers;






void Init_SCU_Register(void);


struct MR1_Register		MR1_Registers;
struct MR2_Register		MR2_Registers;
struct CR_Register		CR_Registers;
struct PRCR_Register	PRCR_Registers;
struct DER_Register		DER_Registers;
struct STR_Register		STR_Registers;
struct IER_Register		IER_Registers;
struct ISR_Register		ISR_Registers;
struct ICR_Register		ICR_Registers;
struct ODR_Register		ODR_Registers;
struct IDR_Register		IDR_Registers;
struct BSR_Register		BSR_Registers;
struct BCR_Register		BCR_Registers;

void Init_GPIO_Register(void);
void Init_GPIO_PA(void);
void Init_GPIO_PB(void);
void Init_GPIO_PC(void);
void Init_GPIO_PD(void);
void Init_GPIO_PE(void);
void Init_GPIO_PF(void);
void Init_GPIO_PG(void);


struct CR1_Register		CR1_Registers;
struct CR2_Register		CR2_Registers;
struct PRS_Register		PRS_Registers;
struct GRA_Register		GRA_Registers;
struct GRB_Register		GRB_Registers;
struct CNT_Register		CNT_Registers;
struct SR_Register		SR_Registers;
struct TIMER_IER_Register	TIMER_IER_Registers;
struct TRGPNT_Register		TRGPNT_Registers;
struct SYNC_Register		SYNC_Registers;




void Init_Timer_Register(void);
void Init_Timer_0(void);



void Init_UART_Register(void);
void Init_UART_0(void);
void Init_UART_1(void);
void Init_UART_2(void);
void Init_UART_3(void);
void Init_UART_4(void);
void Init_UART_5(void);


void Init_IIC_Register(void);
void Init_IIC_0(void);





struct MR_Register		MR_Registers;
struct OLR_Register		OLR_Registers;
struct FOLR_Register		FOLR_Registers;
struct PRD_Register		PRD_Registers;
struct DUH_Register		DUH_Registers;
struct DVH_Register		DVH_Registers;
struct DWH_Register		DWH_Registers;
struct DUL_Register		DUL_Registers;
struct DVL_Register		DVL_Registers;
struct DWL_Register		DWL_Registers;
struct MPWM_CR1_Register		MPWM_CR1_Registers;
struct MPWM_CR2_Register		MPWM_CR2_Registers;
struct MPWM_SR_Register		MPWM_SR_Registers;
struct MPWM_IER_Register		MPWM_IER_Registers;
struct MPWM_CNT_Register		MPWM_CNT_Registers;
struct DTR_Register		DTR_Registers;
struct PCR_Register		PCR_Registers;
struct PSR_Register		PSR_Registers;
struct OCR_Register		OCR_Registers;
struct OSR_Register		OSR_Registers;
struct ATRm_Register		ATRm_Registers;





void Init_PWM_Register(void);
void Init_PWM_0(void);



#define CLOCK_DELAY	0x80
#define PLL_STARTUP_TIMEOUT  1000 		// flash wait 7 -> over 500us


//*********************************************初始化MICOM
void DDI_BootMicom(void)
{
	__disable_interrupt();


	Init_SCU_Register();	// OK	ING

	Init_WDT_Register();	// TBD...	搁置

	Init_GPIO_Register();	// OK

	Init_Timer_Register();	// OK

	Init_UART_Register();	// TBD...	搁置

	//Init_FLASH_Register();

	Init_IIC_Register();

	Init_PWM_Register();	// TBD...

	/*
	API_TMRB_Init(TB0);
	API_TMRB_Init(TB1);
	API_TMRB_Init(TB2);
	API_TMRB_Init(TB3);
	API_TMRB_Init(TB4);
	API_TMRB_Init(TB5);
	API_TMRB_Init(TB6);
	API_TMRB_Init(TB7);
	API_TMRB_Init(TB8);
	API_TMRB_Init(TB9);
	API_PMD_Init(PMD0);
	API_PMD_Init(PMD1);

	API_ADC_Init(ADA);
	API_ADC_Init(ADB);

	*/


	__enable_interrupt();
}

void Init_WDT_Register(void)
{
    // WDT Access Enable
    WDT->AEN = 0xA55A;
    // WDT Disable
    WDT->CON = 0;
}

void Init_SCU_Register(void)
{


	WROS_SCU->SYSTEN_register.SYSTEN = 0x57;
	WROS_SCU->SYSTEN_register.SYSTEN = 0x75;


	CSCR_Registers.LSICON	= SET;
	CSCR_Registers.HSICON	= SET;
//	CSCR_Registers.LSECON	= SET;
	CSCR_Registers.HSECON	= SET;
	WROS_SCU->CSCR_register 	= CSCR_Registers;


#if defined(_120Mhz)

	// about 1ms delay, The delay value may vary depending on the user's circuit environment
	for(uint32_t i = 0; i < CLOCK_DELAY; i++);

	SCCR_Registers.MCLKSEL		= HSI;	// 32Mhz	// PLL HSE HSI
	SCCR_Registers.PLLPREDIV	= 2;	// 1/4
	SCCR_Registers.PLLCLKSEL	= 0;
	SCCR_Registers.PCLKDIV		= 0;
	WROS_SCU->SCCR_register 	= SCCR_Registers;


	PLLCON_Registers.PLLEN		= 1;
	WROS_SCU->PLLCON_register	= PLLCON_Registers;
	__NOP(); __NOP(); __NOP(); __NOP(); __NOP();    // Delay for stabilization

	PLLCON_Registers.OUTDIV 	= 0;	// P
	PLLCON_Registers.POSTDIV2	= 0;	// N2
	PLLCON_Registers.POSTDIV1	= 59;	// N1
	PLLCON_Registers.PREDIV 	= 3;	// R
	PLLCON_Registers.PLLMODE 	= 0;
	PLLCON_Registers.BYPASSB	= 1;
	PLLCON_Registers.PLLEN		= 1;
	PLLCON_Registers.PLLRSTB	= 1;
	PLLCON_Registers.CTRLOTP	= 6;
	PLLCON_Registers.PLLRSTB	= SET;
	WROS_SCU->PLLCON_register	= PLLCON_Registers;

	uint32_t startup_counter = PLL_STARTUP_TIMEOUT * 4;		// HSI-32Mhz * 4

	while(--startup_counter);

	/* Check the PLLCON State */
	while((WROS_SCU->PLLCON_register.PLLLOCK) == 0);

	SCCR_Registers.PLLCLKSEL	= 0;
	SCCR_Registers.PCLKDIV		= 0;
	SCCR_Registers.MCLKSEL		= PLL;	// 32Mhz	// PLL HSE HSI
	WROS_SCU->SCCR_register 	= SCCR_Registers;

	// Flash Wait 7
	CFMC->CONF = 7;

#elif	defined(_32Mhz)

	SCCR_Registers.PLLCLKSEL	= 0;
	SCCR_Registers.PCLKDIV		= 0;
	SCCR_Registers.MCLKSEL		= HSI;	// 32Mhz	// PLL HSE HSI
	WROS_SCU->SCCR_register 	= SCCR_Registers;

#elif	defined(_8Mhz)

	SCCR_Registers.PLLCLKSEL	= 0;
	SCCR_Registers.PCLKDIV		= 2;
	SCCR_Registers.MCLKSEL		= HSI;	// 32Mhz	// PLL HSE HSI
	WROS_SCU->SCCR_register 	= SCCR_Registers;


#else
	SCCR_Registers.PLLCLKSEL	= 0;
	SCCR_Registers.PCLKDIV		= 0;
	SCCR_Registers.MCLKSEL		= HSE;	// 32Mhz	// PLL HSE HSI
	WROS_SCU->SCCR_register 	= SCCR_Registers;

#endif

	// PER1
	PER1_Registers.GPIOA	= SET;
	PER1_Registers.GPIOB	= SET;
	PER1_Registers.GPIOC	= SET;
	PER1_Registers.GPIOD	= SET;
	PER1_Registers.GPIOE	= SET;
	PER1_Registers.GPIOF	= SET;
	PER1_Registers.GPIOG	= SET;
	PER1_Registers.TIMER0	= SET;
	// PCER1
	PCER1_Registers.GPIOA	= SET;
	PCER1_Registers.GPIOB	= SET;
	PCER1_Registers.GPIOC	= SET;
	PCER1_Registers.GPIOD	= SET;
	PCER1_Registers.GPIOE	= SET;
	PCER1_Registers.GPIOF	= SET;
	PCER1_Registers.GPIOG	= SET;
	PCER1_Registers.TIMER0	= SET;
	// PER2
	PER2_Registers.SPI0		= SET;
	PER2_Registers.I2C0		= SET;
	PER2_Registers.MPWM0	= SET;
	PER2_Registers.UART2	= SET;
	PER2_Registers.ADC0		= SET;
	// PCER2
	PCER2_Registers.SPI0	= SET;
	PCER2_Registers.I2C0	= SET;
	PCER2_Registers.MPWM0	= SET;
	PCER2_Registers.UART2	= SET;
	PCER2_Registers.ADC0 	= SET;


	CMR_Registers.HSEMNT	= SET;

	COR_Registers.CLKODIV	= 0;
	COR_Registers.CLKOEN	= SET;
	COR_Registers.CLKOINSEL	= PLL;		// PLL Clock


	MCCR3_Registers.TIMER04CDIV = 1;
	MCCR3_Registers.TIMER04CSEL = PLL;

	MCCR7_Registers.UARTCDIV = 1;
	MCCR7_Registers.UARTCSEL = PLL;


	WROS_SCU->PER1_register		= PER1_Registers;
	WROS_SCU->PER2_register		= PER2_Registers;
	WROS_SCU->PCER1_register	= PCER1_Registers;
	WROS_SCU->PCER2_register	= PCER2_Registers;

	WROS_SCU->CMR_register		= CMR_Registers;
	WROS_SCU->COR_register		= COR_Registers;
	WROS_SCU->MCCR3_register	= MCCR3_Registers;
	WROS_SCU->MCCR7_register	= MCCR7_Registers;
}

void Init_GPIO_Register(void)
{
	WROS_PORTEN->PORTEN_register.PORTEN	= 0x15;
	WROS_PORTEN->PORTEN_register.PORTEN	= 0x51;

	Init_GPIO_PA();
	Init_GPIO_PB();
	Init_GPIO_PC();
	Init_GPIO_PD();
	Init_GPIO_PE();
	Init_GPIO_PF();
	Init_GPIO_PG();
}

void Init_Timer_Register()
{
	Init_Timer_0();
}

void Init_UART_Register()
{
	//Init_UART_0();
	//Init_UART_1();
	Init_UART_2();
	//Init_UART_3();
	//Init_UART_4();
	//Init_UART_5();
}

void Init_IIC_Register()
{

	Init_IIC_0();
}

void Init_PWM_Register(void)
{
	Init_PWM_0();
}
/*****************************************************************
******************************************************************
******************************************************************
*****************************************************************/
void Init_GPIO_PA()
{
	// PA	0
	MR1_Registers.P0MUX	= CLR;
	CR_Registers.P0		= CLR;
	PRCR_Registers.PUE0	= CLR;
	DER_Registers.PDE0	= CLR;
	STR_Registers.PST0	= CLR;
	IER_Registers.PIE0	= CLR;
	ISR_Registers.PIS0	= CLR;
	ICR_Registers.PIC0	= CLR;
	ODR_Registers.POD0	= CLR;
	IDR_Registers.PID0	= CLR;
	BSR_Registers.BSD0	= CLR;
	BCR_Registers.BCD0	= CLR;

	// PA	1
	MR1_Registers.P1MUX	= CLR;
	CR_Registers.P1		= CLR;
	PRCR_Registers.PUE1	= CLR;
	DER_Registers.PDE1	= CLR;
	STR_Registers.PST1	= CLR;
	IER_Registers.PIE1	= CLR;
	ISR_Registers.PIS1	= CLR;
	ICR_Registers.PIC1	= CLR;
	ODR_Registers.POD1	= CLR;
	IDR_Registers.PID1	= CLR;
	BSR_Registers.BSD1	= CLR;
	BCR_Registers.BCD1	= CLR;

	// PA	2
	MR1_Registers.P2MUX	= CLR;
	CR_Registers.P2		= CLR;
	PRCR_Registers.PUE2	= CLR;
	DER_Registers.PDE2	= CLR;
	STR_Registers.PST2	= CLR;
	IER_Registers.PIE2	= CLR;
	ISR_Registers.PIS2	= CLR;
	ICR_Registers.PIC2	= CLR;
	ODR_Registers.POD2	= CLR;
	IDR_Registers.PID2	= CLR;
	BSR_Registers.BSD2	= CLR;
	BCR_Registers.BCD2	= CLR;

	// PA	3
	MR1_Registers.P3MUX	= CLR;
	CR_Registers.P3		= CLR;
	PRCR_Registers.PUE3	= CLR;
	DER_Registers.PDE3	= CLR;
	STR_Registers.PST3	= CLR;
	IER_Registers.PIE3	= CLR;
	ISR_Registers.PIS3	= CLR;
	ICR_Registers.PIC3	= CLR;
	ODR_Registers.POD3	= CLR;
	IDR_Registers.PID3	= CLR;
	BSR_Registers.BSD3	= CLR;
	BCR_Registers.BCD3	= CLR;

	// PA	4
	MR1_Registers.P4MUX	= CLR;
	CR_Registers.P4		= CLR;
	PRCR_Registers.PUE4	= CLR;
	DER_Registers.PDE4	= CLR;
	STR_Registers.PST4	= CLR;
	IER_Registers.PIE4	= CLR;
	ISR_Registers.PIS4	= CLR;
	ICR_Registers.PIC4	= CLR;
	ODR_Registers.POD4	= CLR;
	IDR_Registers.PID4	= CLR;
	BSR_Registers.BSD4	= CLR;
	BCR_Registers.BCD4	= CLR;

	// PA	5
	MR1_Registers.P5MUX	= CLR;
	CR_Registers.P5		= CLR;
	PRCR_Registers.PUE5	= CLR;
	DER_Registers.PDE5	= CLR;
	STR_Registers.PST5	= CLR;
	IER_Registers.PIE5	= CLR;
	ISR_Registers.PIS5	= CLR;
	ICR_Registers.PIC5	= CLR;
	ODR_Registers.POD5	= CLR;
	IDR_Registers.PID5	= CLR;
	BSR_Registers.BSD5	= CLR;
	BCR_Registers.BCD5	= CLR;

	// PA	6
	MR1_Registers.P6MUX	= CLR;
	CR_Registers.P6		= CLR;
	PRCR_Registers.PUE6	= CLR;
	DER_Registers.PDE6	= CLR;
	STR_Registers.PST6	= CLR;
	IER_Registers.PIE6	= CLR;
	ISR_Registers.PIS6	= CLR;
	ICR_Registers.PIC6	= CLR;
	ODR_Registers.POD6	= CLR;
	IDR_Registers.PID6	= CLR;
	BSR_Registers.BSD6	= CLR;
	BCR_Registers.BCD6	= CLR;

	// PA	7
	MR1_Registers.P7MUX	= CLR;
	CR_Registers.P7		= CLR;
	PRCR_Registers.PUE7	= CLR;
	DER_Registers.PDE7	= CLR;
	STR_Registers.PST7	= CLR;
	IER_Registers.PIE7	= CLR;
	ISR_Registers.PIS7	= CLR;
	ICR_Registers.PIC7	= CLR;
	ODR_Registers.POD7	= CLR;
	IDR_Registers.PID7	= CLR;
	BSR_Registers.BSD7	= CLR;
	BCR_Registers.BCD7	= CLR;

	// PA	8
	MR2_Registers.P8MUX	= CLR;
	CR_Registers.P8		= CLR;
	PRCR_Registers.PUE8	= CLR;
	DER_Registers.PDE8	= CLR;
	STR_Registers.PST8	= CLR;
	IER_Registers.PIE8	= CLR;
	ISR_Registers.PIS8	= CLR;
	ICR_Registers.PIC8	= CLR;
	ODR_Registers.POD8	= CLR;
	IDR_Registers.PID8	= CLR;
	BSR_Registers.BSD8	= CLR;
	BCR_Registers.BCD8	= CLR;

	// PA	9
	MR2_Registers.P9MUX	= CLR;
	CR_Registers.P9		= CLR;
	PRCR_Registers.PUE9	= CLR;
	DER_Registers.PDE9	= CLR;
	STR_Registers.PST9	= CLR;
	IER_Registers.PIE9	= CLR;
	ISR_Registers.PIS9	= CLR;
	ICR_Registers.PIC9	= CLR;
	ODR_Registers.POD9	= CLR;
	IDR_Registers.PID9	= CLR;
	BSR_Registers.BSD9	= CLR;
	BCR_Registers.BCD9	= CLR;

	// PA	10
	MR2_Registers.P10MUX= CLR;
	CR_Registers.P10	= CLR;
	PRCR_Registers.PUE10= CLR;
	DER_Registers.PDE10	= CLR;
	STR_Registers.PST10	= CLR;
	IER_Registers.PIE10	= CLR;
	ISR_Registers.PIS10	= CLR;
	ICR_Registers.PIC10	= CLR;
	ODR_Registers.POD10	= CLR;
	IDR_Registers.PID10	= CLR;
	BSR_Registers.BSD10	= CLR;
	BCR_Registers.BCD10	= CLR;

	// PA	11
	MR2_Registers.P11MUX= CLR;
	CR_Registers.P11	= CLR;
	PRCR_Registers.PUE11= CLR;
	DER_Registers.PDE11	= CLR;
	STR_Registers.PST11	= CLR;
	IER_Registers.PIE11	= CLR;
	ISR_Registers.PIS11	= CLR;
	ICR_Registers.PIC11	= CLR;
	ODR_Registers.POD11	= CLR;
	IDR_Registers.PID11	= CLR;
	BSR_Registers.BSD11	= CLR;
	BCR_Registers.BCD11	= CLR;

	// PA	12
	MR2_Registers.P12MUX= CLR;
	CR_Registers.P12	= CLR;
	PRCR_Registers.PUE12= CLR;
	DER_Registers.PDE12	= CLR;
	STR_Registers.PST12	= CLR;
	IER_Registers.PIE12	= CLR;
	ISR_Registers.PIS12	= CLR;
	ICR_Registers.PIC12	= CLR;
	ODR_Registers.POD12	= CLR;
	IDR_Registers.PID12	= CLR;
	BSR_Registers.BSD12	= CLR;
	BCR_Registers.BCD12	= CLR;

	// PA	13
	MR2_Registers.P13MUX= CLR;
	CR_Registers.P13	= CLR;
	PRCR_Registers.PUE13= CLR;
	DER_Registers.PDE13	= CLR;
	STR_Registers.PST13	= CLR;
	IER_Registers.PIE13	= CLR;
	ISR_Registers.PIS13	= CLR;
	ICR_Registers.PIC13	= CLR;
	ODR_Registers.POD13	= CLR;
	IDR_Registers.PID13	= CLR;
	BSR_Registers.BSD13	= CLR;
	BCR_Registers.BCD13	= CLR;

	// PA	14
	MR2_Registers.P14MUX= CLR;
	CR_Registers.P14	= CLR;
	PRCR_Registers.PUE14= CLR;
	DER_Registers.PDE14	= CLR;
	STR_Registers.PST14	= CLR;
	IER_Registers.PIE14	= CLR;
	ISR_Registers.PIS14	= CLR;
	ICR_Registers.PIC14	= CLR;
	ODR_Registers.POD14	= CLR;
	IDR_Registers.PID14	= CLR;
	BSR_Registers.BSD14	= CLR;
	BCR_Registers.BCD14	= CLR;

	// PA	15
	MR2_Registers.P15MUX= CLR;
	CR_Registers.P15	= CLR;
	PRCR_Registers.PUE15= CLR;
	DER_Registers.PDE15	= CLR;
	STR_Registers.PST15	= CLR;
	IER_Registers.PIE15	= CLR;
	ISR_Registers.PIS15	= CLR;
	ICR_Registers.PIC15	= CLR;
	ODR_Registers.POD15	= CLR;
	IDR_Registers.PID15	= CLR;
	BSR_Registers.BSD15	= CLR;
	BCR_Registers.BCD15	= CLR;


	WROS_PA->MR1_register	= MR1_Registers;
	WROS_PA->MR2_register	= MR2_Registers;
	WROS_PA->CR_register	= CR_Registers;
	WROS_PA->PRCR_register	= PRCR_Registers;
	WROS_PA->DER_register	= DER_Registers;
	WROS_PA->STR_register	= STR_Registers;
	WROS_PA->IER_register	= IER_Registers;
	WROS_PA->ISR_register	= ISR_Registers;
	WROS_PA->ICR_register	= ICR_Registers;
	WROS_PA->ODR_register	= ODR_Registers;
	WROS_PA->IDR_register	= IDR_Registers;
	WROS_PA->BSR_register	= BSR_Registers;
	WROS_PA->BCR_register	= BCR_Registers;
}

void Init_GPIO_PB()
{

	// PB	0
	MR1_Registers.P0MUX	= CLR;
	CR_Registers.P0		= CLR;
	PRCR_Registers.PUE0	= CLR;
	DER_Registers.PDE0	= CLR;
	STR_Registers.PST0	= CLR;
	IER_Registers.PIE0	= CLR;
	ISR_Registers.PIS0	= CLR;
	ICR_Registers.PIC0	= CLR;
	ODR_Registers.POD0	= CLR;
	IDR_Registers.PID0	= CLR;
	BSR_Registers.BSD0	= CLR;
	BCR_Registers.BCD0	= CLR;

	// PB	1
	MR1_Registers.P1MUX	= CLR;
	CR_Registers.P1		= CLR;
	PRCR_Registers.PUE1	= CLR;
	DER_Registers.PDE1	= CLR;
	STR_Registers.PST1	= CLR;
	IER_Registers.PIE1	= CLR;
	ISR_Registers.PIS1	= CLR;
	ICR_Registers.PIC1	= CLR;
	ODR_Registers.POD1	= CLR;
	IDR_Registers.PID1	= CLR;
	BSR_Registers.BSD1	= CLR;
	BCR_Registers.BCD1	= CLR;

	// PB	2
	MR1_Registers.P2MUX	= CLR;
	CR_Registers.P2		= CLR;
	PRCR_Registers.PUE2	= CLR;
	DER_Registers.PDE2	= CLR;
	STR_Registers.PST2	= CLR;
	IER_Registers.PIE2	= CLR;
	ISR_Registers.PIS2	= CLR;
	ICR_Registers.PIC2	= CLR;
	ODR_Registers.POD2	= CLR;
	IDR_Registers.PID2	= CLR;
	BSR_Registers.BSD2	= CLR;
	BCR_Registers.BCD2	= CLR;

	// PB	3
	MR1_Registers.P3MUX	= CLR;
	CR_Registers.P3		= CLR;
	PRCR_Registers.PUE3	= CLR;
	DER_Registers.PDE3	= CLR;
	STR_Registers.PST3	= CLR;
	IER_Registers.PIE3	= CLR;
	ISR_Registers.PIS3	= CLR;
	ICR_Registers.PIC3	= CLR;
	ODR_Registers.POD3	= CLR;
	IDR_Registers.PID3	= CLR;
	BSR_Registers.BSD3	= CLR;
	BCR_Registers.BCD3	= CLR;

	// PB	4
	MR1_Registers.P4MUX	= CLR;
	CR_Registers.P4		= CLR;
	PRCR_Registers.PUE4	= CLR;
	DER_Registers.PDE4	= CLR;
	STR_Registers.PST4	= CLR;
	IER_Registers.PIE4	= CLR;
	ISR_Registers.PIS4	= CLR;
	ICR_Registers.PIC4	= CLR;
	ODR_Registers.POD4	= CLR;
	IDR_Registers.PID4	= CLR;
	BSR_Registers.BSD4	= CLR;
	BCR_Registers.BCD4	= CLR;

	// PB	5
	MR1_Registers.P5MUX	= CLR;
	CR_Registers.P5		= CLR;
	PRCR_Registers.PUE5	= CLR;
	DER_Registers.PDE5	= CLR;
	STR_Registers.PST5	= CLR;
	IER_Registers.PIE5	= CLR;
	ISR_Registers.PIS5	= CLR;
	ICR_Registers.PIC5	= CLR;
	ODR_Registers.POD5	= CLR;
	IDR_Registers.PID5	= CLR;
	BSR_Registers.BSD5	= CLR;
	BCR_Registers.BCD5	= CLR;

	// PB	6
	MR1_Registers.P6MUX	= CLR;
	CR_Registers.P6		= CLR;
	PRCR_Registers.PUE6	= CLR;
	DER_Registers.PDE6	= CLR;
	STR_Registers.PST6	= CLR;
	IER_Registers.PIE6	= CLR;
	ISR_Registers.PIS6	= CLR;
	ICR_Registers.PIC6	= CLR;
	ODR_Registers.POD6	= CLR;
	IDR_Registers.PID6	= CLR;
	BSR_Registers.BSD6	= CLR;
	BCR_Registers.BCD6	= CLR;

	// PB	7
	MR1_Registers.P7MUX	= CLR;
	CR_Registers.P7		= CLR;
	PRCR_Registers.PUE7	= CLR;
	DER_Registers.PDE7	= CLR;
	STR_Registers.PST7	= CLR;
	IER_Registers.PIE7	= CLR;
	ISR_Registers.PIS7	= CLR;
	ICR_Registers.PIC7	= CLR;
	ODR_Registers.POD7	= CLR;
	IDR_Registers.PID7	= CLR;
	BSR_Registers.BSD7	= CLR;
	BCR_Registers.BCD7	= CLR;

	// PB	8
	MR2_Registers.P8MUX	= CLR;
	CR_Registers.P8		= CLR;
	PRCR_Registers.PUE8	= CLR;
	DER_Registers.PDE8	= CLR;
	STR_Registers.PST8	= CLR;
	IER_Registers.PIE8	= CLR;
	ISR_Registers.PIS8	= CLR;
	ICR_Registers.PIC8	= CLR;
	ODR_Registers.POD8	= CLR;
	IDR_Registers.PID8	= CLR;
	BSR_Registers.BSD8	= CLR;
	BCR_Registers.BCD8	= CLR;

	// PB	9
	MR2_Registers.P9MUX	= CLR;
	CR_Registers.P9		= CLR;
	PRCR_Registers.PUE9	= CLR;
	DER_Registers.PDE9	= CLR;
	STR_Registers.PST9	= CLR;
	IER_Registers.PIE9	= CLR;
	ISR_Registers.PIS9	= CLR;
	ICR_Registers.PIC9	= CLR;
	ODR_Registers.POD9	= CLR;
	IDR_Registers.PID9	= CLR;
	BSR_Registers.BSD9	= CLR;
	BCR_Registers.BCD9	= CLR;

	// PB	10
	MR2_Registers.P10MUX= CLR;
	CR_Registers.P10	= CLR;
	PRCR_Registers.PUE10= CLR;
	DER_Registers.PDE10	= CLR;
	STR_Registers.PST10	= CLR;
	IER_Registers.PIE10	= CLR;
	ISR_Registers.PIS10	= CLR;
	ICR_Registers.PIC10	= CLR;
	ODR_Registers.POD10	= CLR;
	IDR_Registers.PID10	= CLR;
	BSR_Registers.BSD10	= CLR;
	BCR_Registers.BCD10	= CLR;

	// PB	11
	MR2_Registers.P11MUX= CLR;
	CR_Registers.P11	= CLR;
	PRCR_Registers.PUE11= CLR;
	DER_Registers.PDE11	= CLR;
	STR_Registers.PST11	= CLR;
	IER_Registers.PIE11	= CLR;
	ISR_Registers.PIS11	= CLR;
	ICR_Registers.PIC11	= CLR;
	ODR_Registers.POD11	= CLR;
	IDR_Registers.PID11	= CLR;
	BSR_Registers.BSD11	= CLR;
	BCR_Registers.BCD11	= CLR;

	// PB	12
	MR2_Registers.P12MUX= CLR;
	CR_Registers.P12	= CLR;
	PRCR_Registers.PUE12= CLR;
	DER_Registers.PDE12	= CLR;
	STR_Registers.PST12	= CLR;
	IER_Registers.PIE12	= CLR;
	ISR_Registers.PIS12	= CLR;
	ICR_Registers.PIC12	= CLR;
	ODR_Registers.POD12	= CLR;
	IDR_Registers.PID12	= CLR;
	BSR_Registers.BSD12	= CLR;
	BCR_Registers.BCD12	= CLR;

	// PB	13
	MR2_Registers.P13MUX= CLR;
	CR_Registers.P13	= CLR;
	PRCR_Registers.PUE13= CLR;
	DER_Registers.PDE13	= CLR;
	STR_Registers.PST13	= CLR;
	IER_Registers.PIE13	= CLR;
	ISR_Registers.PIS13	= CLR;
	ICR_Registers.PIC13	= CLR;
	ODR_Registers.POD13	= CLR;
	IDR_Registers.PID13	= CLR;
	BSR_Registers.BSD13	= CLR;
	BCR_Registers.BCD13	= CLR;

	// PB	14
	MR2_Registers.P14MUX= CLR;
	CR_Registers.P14	= CLR;
	PRCR_Registers.PUE14= CLR;
	DER_Registers.PDE14	= CLR;
	STR_Registers.PST14	= CLR;
	IER_Registers.PIE14	= CLR;
	ISR_Registers.PIS14	= CLR;
	ICR_Registers.PIC14	= CLR;
	ODR_Registers.POD14	= CLR;
	IDR_Registers.PID14	= CLR;
	BSR_Registers.BSD14	= CLR;
	BCR_Registers.BCD14	= CLR;

	// PB	15
	MR2_Registers.P15MUX= CLR;
	CR_Registers.P15	= CLR;
	PRCR_Registers.PUE15= CLR;
	DER_Registers.PDE15	= CLR;
	STR_Registers.PST15	= CLR;
	IER_Registers.PIE15	= CLR;
	ISR_Registers.PIS15	= CLR;
	ICR_Registers.PIC15	= CLR;
	ODR_Registers.POD15	= CLR;
	IDR_Registers.PID15	= CLR;
	BSR_Registers.BSD15	= CLR;
	BCR_Registers.BCD15	= CLR;


	WROS_PB->MR1_register	= MR1_Registers;
	WROS_PB->MR2_register	= MR2_Registers;
	WROS_PB->CR_register	= CR_Registers;
	WROS_PB->PRCR_register	= PRCR_Registers;
	WROS_PB->DER_register	= DER_Registers;
	WROS_PB->STR_register	= STR_Registers;
	WROS_PB->IER_register	= IER_Registers;
	WROS_PB->ISR_register	= ISR_Registers;
	WROS_PB->ICR_register	= ICR_Registers;
	WROS_PB->ODR_register	= ODR_Registers;
	WROS_PB->IDR_register	= IDR_Registers;
	WROS_PB->BSR_register	= BSR_Registers;
	WROS_PB->BCR_register	= BCR_Registers;
}

void Init_GPIO_PC()
{

	// PC	0
	MR1_Registers.P0MUX	= Func_3;
	CR_Registers.P0		= Input;
	PRCR_Registers.PUE0	= CLR;
	DER_Registers.PDE0	= CLR;
	STR_Registers.PST0	= CLR;
	IER_Registers.PIE0	= CLR;
	ISR_Registers.PIS0	= CLR;
	ICR_Registers.PIC0	= CLR;
	ODR_Registers.POD0	= CLR;
	IDR_Registers.PID0	= CLR;
	BSR_Registers.BSD0	= CLR;
	BCR_Registers.BCD0	= CLR;

	// PC	1
	MR1_Registers.P1MUX	= Func_3;
	CR_Registers.P1		= Input;
	PRCR_Registers.PUE1	= CLR;
	DER_Registers.PDE1	= CLR;
	STR_Registers.PST1	= CLR;
	IER_Registers.PIE1	= CLR;
	ISR_Registers.PIS1	= CLR;
	ICR_Registers.PIC1	= CLR;
	ODR_Registers.POD1	= CLR;
	IDR_Registers.PID1	= CLR;
	BSR_Registers.BSD1	= CLR;
	BCR_Registers.BCD1	= CLR;

	// PC	2
	MR1_Registers.P2MUX	= CLR;
	CR_Registers.P2		= CLR;
	PRCR_Registers.PUE2	= CLR;
	DER_Registers.PDE2	= CLR;
	STR_Registers.PST2	= CLR;
	IER_Registers.PIE2	= CLR;
	ISR_Registers.PIS2	= CLR;
	ICR_Registers.PIC2	= CLR;
	ODR_Registers.POD2	= CLR;
	IDR_Registers.PID2	= CLR;
	BSR_Registers.BSD2	= CLR;
	BCR_Registers.BCD2	= CLR;

	// PC	3
	MR1_Registers.P3MUX	= CLR;
	CR_Registers.P3		= CLR;
	PRCR_Registers.PUE3	= CLR;
	DER_Registers.PDE3	= CLR;
	STR_Registers.PST3	= CLR;
	IER_Registers.PIE3	= CLR;
	ISR_Registers.PIS3	= CLR;
	ICR_Registers.PIC3	= CLR;
	ODR_Registers.POD3	= CLR;
	IDR_Registers.PID3	= CLR;
	BSR_Registers.BSD3	= CLR;
	BCR_Registers.BCD3	= CLR;

	// PC	4
	MR1_Registers.P4MUX	= CLR;
	CR_Registers.P4		= CLR;
	PRCR_Registers.PUE4	= CLR;
	DER_Registers.PDE4	= CLR;
	STR_Registers.PST4	= CLR;
	IER_Registers.PIE4	= CLR;
	ISR_Registers.PIS4	= CLR;
	ICR_Registers.PIC4	= CLR;
	ODR_Registers.POD4	= CLR;
	IDR_Registers.PID4	= CLR;
	BSR_Registers.BSD4	= CLR;
	BCR_Registers.BCD4	= CLR;

	// PC	5
	MR1_Registers.P5MUX	= Func_0;
	CR_Registers.P5		= Input;
	PRCR_Registers.PUE5	= CLR;
	DER_Registers.PDE5	= CLR;
	STR_Registers.PST5	= CLR;
	IER_Registers.PIE5	= CLR;
	ISR_Registers.PIS5	= CLR;
	ICR_Registers.PIC5	= CLR;
	ODR_Registers.POD5	= CLR;
	IDR_Registers.PID5	= CLR;
	BSR_Registers.BSD5	= CLR;
	BCR_Registers.BCD5	= CLR;

	// PC	6
	MR1_Registers.P6MUX	= Func_0;
	CR_Registers.P6		= Input;
	PRCR_Registers.PUE6	= CLR;
	DER_Registers.PDE6	= CLR;
	STR_Registers.PST6	= CLR;
	IER_Registers.PIE6	= CLR;
	ISR_Registers.PIS6	= CLR;
	ICR_Registers.PIC6	= CLR;
	ODR_Registers.POD6	= CLR;
	IDR_Registers.PID6	= CLR;
	BSR_Registers.BSD6	= CLR;
	BCR_Registers.BCD6	= CLR;

	// PC	7
	MR1_Registers.P7MUX	= CLR;
	CR_Registers.P7		= CLR;
	PRCR_Registers.PUE7	= CLR;
	DER_Registers.PDE7	= CLR;
	STR_Registers.PST7	= CLR;
	IER_Registers.PIE7	= CLR;
	ISR_Registers.PIS7	= CLR;
	ICR_Registers.PIC7	= CLR;
	ODR_Registers.POD7	= CLR;
	IDR_Registers.PID7	= CLR;
	BSR_Registers.BSD7	= CLR;
	BCR_Registers.BCD7	= CLR;

	// PC	8
	MR2_Registers.P8MUX	= CLR;
	CR_Registers.P8		= CLR;
	PRCR_Registers.PUE8	= CLR;
	DER_Registers.PDE8	= CLR;
	STR_Registers.PST8	= CLR;
	IER_Registers.PIE8	= CLR;
	ISR_Registers.PIS8	= CLR;
	ICR_Registers.PIC8	= CLR;
	ODR_Registers.POD8	= CLR;
	IDR_Registers.PID8	= CLR;
	BSR_Registers.BSD8	= CLR;
	BCR_Registers.BCD8	= CLR;

	// PC	9
	MR2_Registers.P9MUX	= CLR;
	CR_Registers.P9		= CLR;
	PRCR_Registers.PUE9	= CLR;
	DER_Registers.PDE9	= CLR;
	STR_Registers.PST9	= CLR;
	IER_Registers.PIE9	= CLR;
	ISR_Registers.PIS9	= CLR;
	ICR_Registers.PIC9	= CLR;
	ODR_Registers.POD9	= CLR;
	IDR_Registers.PID9	= CLR;
	BSR_Registers.BSD9	= CLR;
	BCR_Registers.BCD9	= CLR;

	// PC	10
	MR2_Registers.P10MUX= Func_3;
	CR_Registers.P10	= Input;
	PRCR_Registers.PUE10= CLR;
	DER_Registers.PDE10	= CLR;
	STR_Registers.PST10	= CLR;
	IER_Registers.PIE10	= CLR;
	ISR_Registers.PIS10	= CLR;
	ICR_Registers.PIC10	= CLR;
	ODR_Registers.POD10	= CLR;
	IDR_Registers.PID10	= CLR;
	BSR_Registers.BSD10	= CLR;
	BCR_Registers.BCD10	= CLR;

	// PC	11
	MR2_Registers.P11MUX= CLR;
	CR_Registers.P11	= CLR;
	PRCR_Registers.PUE11= CLR;
	DER_Registers.PDE11	= CLR;
	STR_Registers.PST11	= CLR;
	IER_Registers.PIE11	= CLR;
	ISR_Registers.PIS11	= CLR;
	ICR_Registers.PIC11	= CLR;
	ODR_Registers.POD11	= CLR;
	IDR_Registers.PID11	= CLR;
	BSR_Registers.BSD11	= CLR;
	BCR_Registers.BCD11	= CLR;

	// PC	12
	MR2_Registers.P12MUX= Func_7;
	CR_Registers.P12	= CLR;
	PRCR_Registers.PUE12= CLR;
	DER_Registers.PDE12	= CLR;
	STR_Registers.PST12	= CLR;
	IER_Registers.PIE12	= CLR;
	ISR_Registers.PIS12	= CLR;
	ICR_Registers.PIC12	= CLR;
	ODR_Registers.POD12	= CLR;
	IDR_Registers.PID12	= CLR;
	BSR_Registers.BSD12	= CLR;
	BCR_Registers.BCD12	= CLR;

	// PC	13
	MR2_Registers.P13MUX= Func_7;
	CR_Registers.P13	= CLR;
	PRCR_Registers.PUE13= CLR;
	DER_Registers.PDE13	= CLR;
	STR_Registers.PST13	= CLR;
	IER_Registers.PIE13	= CLR;
	ISR_Registers.PIS13	= CLR;
	ICR_Registers.PIC13	= CLR;
	ODR_Registers.POD13	= CLR;
	IDR_Registers.PID13	= CLR;
	BSR_Registers.BSD13	= CLR;
	BCR_Registers.BCD13	= CLR;

	// PC	14
	MR2_Registers.P14MUX= CLR;
	CR_Registers.P14	= CLR;
	PRCR_Registers.PUE14= CLR;
	DER_Registers.PDE14	= CLR;
	STR_Registers.PST14	= CLR;
	IER_Registers.PIE14	= CLR;
	ISR_Registers.PIS14	= CLR;
	ICR_Registers.PIC14	= CLR;
	ODR_Registers.POD14	= CLR;
	IDR_Registers.PID14	= CLR;
	BSR_Registers.BSD14	= CLR;
	BCR_Registers.BCD14	= CLR;

	// PC	15
	MR2_Registers.P15MUX= CLR;
	CR_Registers.P15	= CLR;
	PRCR_Registers.PUE15= CLR;
	DER_Registers.PDE15	= CLR;
	STR_Registers.PST15	= CLR;
	IER_Registers.PIE15	= CLR;
	ISR_Registers.PIS15	= CLR;
	ICR_Registers.PIC15	= CLR;
	ODR_Registers.POD15	= CLR;
	IDR_Registers.PID15	= CLR;
	BSR_Registers.BSD15	= CLR;
	BCR_Registers.BCD15	= CLR;

	// PC	15
	WROS_PC->MR1_register	=  MR1_Registers;
	WROS_PC->MR2_register	=  MR2_Registers;
	WROS_PC->CR_register	=  CR_Registers;
	WROS_PC->PRCR_register	=  PRCR_Registers;
	WROS_PC->DER_register	=  DER_Registers;
	WROS_PC->STR_register	=  STR_Registers;
	WROS_PC->IER_register	=  IER_Registers;
	WROS_PC->ISR_register	=  ISR_Registers;
	WROS_PC->ICR_register	=  ICR_Registers;
	WROS_PC->ODR_register	=  ODR_Registers;
	WROS_PC->IDR_register	=  IDR_Registers;
	WROS_PC->BSR_register	=  BSR_Registers;
	WROS_PC->BCR_register	=  BCR_Registers;
}

void Init_GPIO_PD()
{

	// PD	0
	MR1_Registers.P0MUX = CLR;
	CR_Registers.P0 	= CLR;
	PRCR_Registers.PUE0 = CLR;
	DER_Registers.PDE0	= CLR;
	STR_Registers.PST0	= CLR;
	IER_Registers.PIE0	= CLR;
	ISR_Registers.PIS0	= CLR;
	ICR_Registers.PIC0	= CLR;
	ODR_Registers.POD0	= CLR;
	IDR_Registers.PID0	= CLR;
	BSR_Registers.BSD0	= CLR;
	BCR_Registers.BCD0	= CLR;

	// PD	1
	MR1_Registers.P1MUX = CLR;
	CR_Registers.P1 	= CLR;
	PRCR_Registers.PUE1 = CLR;
	DER_Registers.PDE1	= CLR;
	STR_Registers.PST1	= CLR;
	IER_Registers.PIE1	= CLR;
	ISR_Registers.PIS1	= CLR;
	ICR_Registers.PIC1	= CLR;
	ODR_Registers.POD1	= CLR;
	IDR_Registers.PID1	= CLR;
	BSR_Registers.BSD1	= CLR;
	BCR_Registers.BCD1	= CLR;

	// PD	2
	MR1_Registers.P2MUX = CLR;
	CR_Registers.P2 	= CLR;
	PRCR_Registers.PUE2 = CLR;
	DER_Registers.PDE2	= CLR;
	STR_Registers.PST2	= CLR;
	IER_Registers.PIE2	= CLR;
	ISR_Registers.PIS2	= CLR;
	ICR_Registers.PIC2	= CLR;
	ODR_Registers.POD2	= CLR;
	IDR_Registers.PID2	= CLR;
	BSR_Registers.BSD2	= CLR;
	BCR_Registers.BCD2	= CLR;

	// PD	3
	MR1_Registers.P3MUX = CLR;
	CR_Registers.P3 	= CLR;
	PRCR_Registers.PUE3 = CLR;
	DER_Registers.PDE3	= CLR;
	STR_Registers.PST3	= CLR;
	IER_Registers.PIE3	= CLR;
	ISR_Registers.PIS3	= CLR;
	ICR_Registers.PIC3	= CLR;
	ODR_Registers.POD3	= CLR;
	IDR_Registers.PID3	= CLR;
	BSR_Registers.BSD3	= CLR;
	BCR_Registers.BCD3	= CLR;

	// PD	4
	MR1_Registers.P4MUX = CLR;
	CR_Registers.P4 	= CLR;
	PRCR_Registers.PUE4 = CLR;
	DER_Registers.PDE4	= CLR;
	STR_Registers.PST4	= CLR;
	IER_Registers.PIE4	= CLR;
	ISR_Registers.PIS4	= CLR;
	ICR_Registers.PIC4	= CLR;
	ODR_Registers.POD4	= CLR;
	IDR_Registers.PID4	= CLR;
	BSR_Registers.BSD4	= CLR;
	BCR_Registers.BCD4	= CLR;

	// PD	5
	MR1_Registers.P5MUX = CLR;
	CR_Registers.P5 	= CLR;
	PRCR_Registers.PUE5 = CLR;
	DER_Registers.PDE5	= CLR;
	STR_Registers.PST5	= CLR;
	IER_Registers.PIE5	= CLR;
	ISR_Registers.PIS5	= CLR;
	ICR_Registers.PIC5	= CLR;
	ODR_Registers.POD5	= CLR;
	IDR_Registers.PID5	= CLR;
	BSR_Registers.BSD5	= CLR;
	BCR_Registers.BCD5	= CLR;

	// PD	6
	MR1_Registers.P6MUX = CLR;
	CR_Registers.P6 	= CLR;
	PRCR_Registers.PUE6 = CLR;
	DER_Registers.PDE6	= CLR;
	STR_Registers.PST6	= CLR;
	IER_Registers.PIE6	= CLR;
	ISR_Registers.PIS6	= CLR;
	ICR_Registers.PIC6	= CLR;
	ODR_Registers.POD6	= CLR;
	IDR_Registers.PID6	= CLR;
	BSR_Registers.BSD6	= CLR;
	BCR_Registers.BCD6	= CLR;

	// PD	7
	MR1_Registers.P7MUX = CLR;
	CR_Registers.P7 	= CLR;
	PRCR_Registers.PUE7 = CLR;
	DER_Registers.PDE7	= CLR;
	STR_Registers.PST7	= CLR;
	IER_Registers.PIE7	= CLR;
	ISR_Registers.PIS7	= CLR;
	ICR_Registers.PIC7	= CLR;
	ODR_Registers.POD7	= CLR;
	IDR_Registers.PID7	= CLR;
	BSR_Registers.BSD7	= CLR;
	BCR_Registers.BCD7	= CLR;

	// PD	8
	MR2_Registers.P8MUX = CLR;
	CR_Registers.P8 	= CLR;
	PRCR_Registers.PUE8 = CLR;
	DER_Registers.PDE8	= CLR;
	STR_Registers.PST8	= CLR;
	IER_Registers.PIE8	= CLR;
	ISR_Registers.PIS8	= CLR;
	ICR_Registers.PIC8	= CLR;
	ODR_Registers.POD8	= CLR;
	IDR_Registers.PID8	= CLR;
	BSR_Registers.BSD8	= CLR;
	BCR_Registers.BCD8	= CLR;

	// PD	9
	MR2_Registers.P9MUX = CLR;
	CR_Registers.P9 	= CLR;
	PRCR_Registers.PUE9 = CLR;
	DER_Registers.PDE9	= CLR;
	STR_Registers.PST9	= CLR;
	IER_Registers.PIE9	= CLR;
	ISR_Registers.PIS9	= CLR;
	ICR_Registers.PIC9	= CLR;
	ODR_Registers.POD9	= CLR;
	IDR_Registers.PID9	= CLR;
	BSR_Registers.BSD9	= CLR;
	BCR_Registers.BCD9	= CLR;

	// PD	10
	MR2_Registers.P10MUX= CLR;
	CR_Registers.P10	= CLR;
	PRCR_Registers.PUE10= CLR;
	DER_Registers.PDE10 = CLR;
	STR_Registers.PST10 = CLR;
	IER_Registers.PIE10 = CLR;
	ISR_Registers.PIS10 = CLR;
	ICR_Registers.PIC10 = CLR;
	ODR_Registers.POD10 = CLR;
	IDR_Registers.PID10 = CLR;
	BSR_Registers.BSD10 = CLR;
	BCR_Registers.BCD10 = CLR;

	// PD	11
	MR2_Registers.P11MUX= CLR;
	CR_Registers.P11	= CLR;
	PRCR_Registers.PUE11= CLR;
	DER_Registers.PDE11 = CLR;
	STR_Registers.PST11 = CLR;
	IER_Registers.PIE11 = CLR;
	ISR_Registers.PIS11 = CLR;
	ICR_Registers.PIC11 = CLR;
	ODR_Registers.POD11 = CLR;
	IDR_Registers.PID11 = CLR;
	BSR_Registers.BSD11 = CLR;
	BCR_Registers.BCD11 = CLR;

	// PD	12
	MR2_Registers.P12MUX= CLR;
	CR_Registers.P12	= CLR;
	PRCR_Registers.PUE12= CLR;
	DER_Registers.PDE12 = CLR;
	STR_Registers.PST12 = CLR;
	IER_Registers.PIE12 = CLR;
	ISR_Registers.PIS12 = CLR;
	ICR_Registers.PIC12 = CLR;
	ODR_Registers.POD12 = CLR;
	IDR_Registers.PID12 = CLR;
	BSR_Registers.BSD12 = CLR;
	BCR_Registers.BCD12 = CLR;

	// PD	13
	MR2_Registers.P13MUX= CLR;
	CR_Registers.P13	= CLR;
	PRCR_Registers.PUE13= CLR;
	DER_Registers.PDE13 = CLR;
	STR_Registers.PST13 = CLR;
	IER_Registers.PIE13 = CLR;
	ISR_Registers.PIS13 = CLR;
	ICR_Registers.PIC13 = CLR;
	ODR_Registers.POD13 = CLR;
	IDR_Registers.PID13 = CLR;
	BSR_Registers.BSD13 = CLR;
	BCR_Registers.BCD13 = CLR;

	// PD	14
	MR2_Registers.P14MUX= CLR;
	CR_Registers.P14	= CLR;
	PRCR_Registers.PUE14= CLR;
	DER_Registers.PDE14 = CLR;
	STR_Registers.PST14 = CLR;
	IER_Registers.PIE14 = CLR;
	ISR_Registers.PIS14 = CLR;
	ICR_Registers.PIC14 = CLR;
	ODR_Registers.POD14 = CLR;
	IDR_Registers.PID14 = CLR;
	BSR_Registers.BSD14 = CLR;
	BCR_Registers.BCD14 = CLR;

	// PD	15
	MR2_Registers.P15MUX= CLR;
	CR_Registers.P15	= CLR;
	PRCR_Registers.PUE15= CLR;
	DER_Registers.PDE15 = CLR;
	STR_Registers.PST15 = CLR;
	IER_Registers.PIE15 = CLR;
	ISR_Registers.PIS15 = CLR;
	ICR_Registers.PIC15 = CLR;
	ODR_Registers.POD15 = CLR;
	IDR_Registers.PID15 = CLR;
	BSR_Registers.BSD15 = CLR;
	BCR_Registers.BCD15 = CLR;

	// PD	15
	WROS_PD->MR1_register	=  MR1_Registers;
	WROS_PD->MR2_register	=  MR2_Registers;
	WROS_PD->CR_register	=  CR_Registers;
	WROS_PD->PRCR_register	=  PRCR_Registers;
	WROS_PD->DER_register	=  DER_Registers;
	WROS_PD->STR_register	=  STR_Registers;
	WROS_PD->IER_register	=  IER_Registers;
	WROS_PD->ISR_register	=  ISR_Registers;
	WROS_PD->ICR_register	=  ICR_Registers;
	WROS_PD->ODR_register	=  ODR_Registers;
	WROS_PD->IDR_register	=  IDR_Registers;
	WROS_PD->BSR_register	=  BSR_Registers;
	WROS_PD->BCR_register	=  BCR_Registers;


}

void Init_GPIO_PE()
{


	// PE	0
	MR1_Registers.P0MUX = CLR;
	CR_Registers.P0 	= CLR;
	PRCR_Registers.PUE0 = CLR;
	DER_Registers.PDE0	= CLR;
	STR_Registers.PST0	= CLR;
	IER_Registers.PIE0	= CLR;
	ISR_Registers.PIS0	= CLR;
	ICR_Registers.PIC0	= CLR;
	ODR_Registers.POD0	= CLR;
	IDR_Registers.PID0	= CLR;
	BSR_Registers.BSD0	= CLR;
	BCR_Registers.BCD0	= CLR;

	// PE	1
	MR1_Registers.P1MUX = CLR;
	CR_Registers.P1 	= CLR;
	PRCR_Registers.PUE1 = CLR;
	DER_Registers.PDE1	= CLR;
	STR_Registers.PST1	= CLR;
	IER_Registers.PIE1	= CLR;
	ISR_Registers.PIS1	= CLR;
	ICR_Registers.PIC1	= CLR;
	ODR_Registers.POD1	= CLR;
	IDR_Registers.PID1	= CLR;
	BSR_Registers.BSD1	= CLR;
	BCR_Registers.BCD1	= CLR;

	// PE	2
	MR1_Registers.P2MUX = CLR;
	CR_Registers.P2 	= CLR;
	PRCR_Registers.PUE2 = CLR;
	DER_Registers.PDE2	= CLR;
	STR_Registers.PST2	= CLR;
	IER_Registers.PIE2	= CLR;
	ISR_Registers.PIS2	= CLR;
	ICR_Registers.PIC2	= CLR;
	ODR_Registers.POD2	= CLR;
	IDR_Registers.PID2	= CLR;
	BSR_Registers.BSD2	= CLR;
	BCR_Registers.BCD2	= CLR;

	// PE	3
	MR1_Registers.P3MUX = Func_0;
	CR_Registers.P3 	= OD_Output;
	PRCR_Registers.PUE3 = CLR;
	DER_Registers.PDE3	= CLR;
	STR_Registers.PST3	= CLR;
	IER_Registers.PIE3	= CLR;
	ISR_Registers.PIS3	= CLR;
	ICR_Registers.PIC3	= CLR;
	ODR_Registers.POD3	= CLR;
	IDR_Registers.PID3	= CLR;
	BSR_Registers.BSD3	= CLR;
	BCR_Registers.BCD3	= CLR;

	// PE	4
	MR1_Registers.P4MUX	= Func_0;
	CR_Registers.P4		= OD_Output;
	PRCR_Registers.PUE4 = CLR;
	DER_Registers.PDE4	= CLR;
	STR_Registers.PST4	= CLR;
	IER_Registers.PIE4	= CLR;
	ISR_Registers.PIS4	= CLR;
	ICR_Registers.PIC4	= CLR;
	ODR_Registers.POD4	= CLR;
	IDR_Registers.PID4	= CLR;
	BSR_Registers.BSD4	= CLR;
	BCR_Registers.BCD4	= CLR;

	// PE	5
	MR1_Registers.P5MUX = CLR;
	CR_Registers.P5 	= CLR;
	PRCR_Registers.PUE5 = CLR;
	DER_Registers.PDE5	= CLR;
	STR_Registers.PST5	= CLR;
	IER_Registers.PIE5	= CLR;
	ISR_Registers.PIS5	= CLR;
	ICR_Registers.PIC5	= CLR;
	ODR_Registers.POD5	= CLR;
	IDR_Registers.PID5	= CLR;
	BSR_Registers.BSD5	= CLR;
	BCR_Registers.BCD5	= CLR;

	// PE	6
	MR1_Registers.P6MUX = CLR;
	CR_Registers.P6 	= CLR;
	PRCR_Registers.PUE6 = CLR;
	DER_Registers.PDE6	= CLR;
	STR_Registers.PST6	= CLR;
	IER_Registers.PIE6	= CLR;
	ISR_Registers.PIS6	= CLR;
	ICR_Registers.PIC6	= CLR;
	ODR_Registers.POD6	= CLR;
	IDR_Registers.PID6	= CLR;
	BSR_Registers.BSD6	= CLR;
	BCR_Registers.BCD6	= CLR;

	// PE	7
	MR1_Registers.P7MUX = CLR;
	CR_Registers.P7 	= CLR;
	PRCR_Registers.PUE7 = CLR;
	DER_Registers.PDE7	= CLR;
	STR_Registers.PST7	= CLR;
	IER_Registers.PIE7	= CLR;
	ISR_Registers.PIS7	= CLR;
	ICR_Registers.PIC7	= CLR;
	ODR_Registers.POD7	= CLR;
	IDR_Registers.PID7	= CLR;
	BSR_Registers.BSD7	= CLR;
	BCR_Registers.BCD7	= CLR;

	// PE	8
	MR2_Registers.P8MUX = CLR;
	CR_Registers.P8 	= CLR;
	PRCR_Registers.PUE8 = CLR;
	DER_Registers.PDE8	= CLR;
	STR_Registers.PST8	= CLR;
	IER_Registers.PIE8	= CLR;
	ISR_Registers.PIS8	= CLR;
	ICR_Registers.PIC8	= CLR;
	ODR_Registers.POD8	= CLR;
	IDR_Registers.PID8	= CLR;
	BSR_Registers.BSD8	= CLR;
	BCR_Registers.BCD8	= CLR;

	// PE	9
	MR2_Registers.P9MUX = CLR;
	CR_Registers.P9 	= CLR;
	PRCR_Registers.PUE9 = CLR;
	DER_Registers.PDE9	= CLR;
	STR_Registers.PST9	= CLR;
	IER_Registers.PIE9	= CLR;
	ISR_Registers.PIS9	= CLR;
	ICR_Registers.PIC9	= CLR;
	ODR_Registers.POD9	= CLR;
	IDR_Registers.PID9	= CLR;
	BSR_Registers.BSD9	= CLR;
	BCR_Registers.BCD9	= CLR;

	// PE	10
	MR2_Registers.P10MUX= CLR;
	CR_Registers.P10	= CLR;
	PRCR_Registers.PUE10= CLR;
	DER_Registers.PDE10 = CLR;
	STR_Registers.PST10 = CLR;
	IER_Registers.PIE10 = CLR;
	ISR_Registers.PIS10 = CLR;
	ICR_Registers.PIC10 = CLR;
	ODR_Registers.POD10 = CLR;
	IDR_Registers.PID10 = CLR;
	BSR_Registers.BSD10 = CLR;
	BCR_Registers.BCD10 = CLR;

	// PE	11
	MR2_Registers.P11MUX= Func_0;
	CR_Registers.P11	= OD_Output;
	PRCR_Registers.PUE11= CLR;
	DER_Registers.PDE11 = CLR;
	STR_Registers.PST11 = CLR;
	IER_Registers.PIE11 = CLR;
	ISR_Registers.PIS11 = CLR;
	ICR_Registers.PIC11 = CLR;
	ODR_Registers.POD11 = CLR;
	IDR_Registers.PID11 = CLR;
	BSR_Registers.BSD11 = CLR;
	BCR_Registers.BCD11 = CLR;

	// PE	12
	MR2_Registers.P12MUX= Func_0;
	CR_Registers.P12	= OD_Output;
	PRCR_Registers.PUE12= CLR;
	DER_Registers.PDE12 = CLR;
	STR_Registers.PST12 = CLR;
	IER_Registers.PIE12 = CLR;
	ISR_Registers.PIS12 = CLR;
	ICR_Registers.PIC12 = CLR;
	ODR_Registers.POD12 = CLR;
	IDR_Registers.PID12 = CLR;
	BSR_Registers.BSD12 = CLR;
	BCR_Registers.BCD12 = CLR;

	// PE	13
	MR2_Registers.P13MUX= CLR;
	CR_Registers.P13	= CLR;
	PRCR_Registers.PUE13= CLR;
	DER_Registers.PDE13 = CLR;
	STR_Registers.PST13 = CLR;
	IER_Registers.PIE13 = CLR;
	ISR_Registers.PIS13 = CLR;
	ICR_Registers.PIC13 = CLR;
	ODR_Registers.POD13 = CLR;
	IDR_Registers.PID13 = CLR;
	BSR_Registers.BSD13 = CLR;
	BCR_Registers.BCD13 = CLR;

	// PE	14
	MR2_Registers.P14MUX= CLR;
	CR_Registers.P14	= CLR;
	PRCR_Registers.PUE14= CLR;
	DER_Registers.PDE14 = CLR;
	STR_Registers.PST14 = CLR;
	IER_Registers.PIE14 = CLR;
	ISR_Registers.PIS14 = CLR;
	ICR_Registers.PIC14 = CLR;
	ODR_Registers.POD14 = CLR;
	IDR_Registers.PID14 = CLR;
	BSR_Registers.BSD14 = CLR;
	BCR_Registers.BCD14 = CLR;

	// PE	15
	MR2_Registers.P15MUX= CLR;
	CR_Registers.P15	= CLR;
	PRCR_Registers.PUE15= CLR;
	DER_Registers.PDE15 = CLR;
	STR_Registers.PST15 = CLR;
	IER_Registers.PIE15 = CLR;
	ISR_Registers.PIS15 = CLR;
	ICR_Registers.PIC15 = CLR;
	ODR_Registers.POD15 = CLR;
	IDR_Registers.PID15 = CLR;
	BSR_Registers.BSD15 = CLR;
	BCR_Registers.BCD15 = CLR;

	// PE	15
	WROS_PE->MR1_register	=  MR1_Registers;
	WROS_PE->MR2_register	=  MR2_Registers;
	WROS_PE->CR_register	=  CR_Registers;
	WROS_PE->PRCR_register	=  PRCR_Registers;
	WROS_PE->DER_register	=  DER_Registers;
	WROS_PE->STR_register	=  STR_Registers;
	WROS_PE->IER_register	=  IER_Registers;
	WROS_PE->ISR_register	=  ISR_Registers;
	WROS_PE->ICR_register	=  ICR_Registers;
	WROS_PE->ODR_register	=  ODR_Registers;
	WROS_PE->IDR_register	=  IDR_Registers;
	WROS_PE->BSR_register	=  BSR_Registers;
	WROS_PE->BCR_register	=  BCR_Registers;

}


void Init_GPIO_PF()
{

	// PF	0
	MR1_Registers.P0MUX	= CLR;
	CR_Registers.P0		= CLR;
	PRCR_Registers.PUE0	= CLR;
	DER_Registers.PDE0	= CLR;
	STR_Registers.PST0	= CLR;
	IER_Registers.PIE0	= CLR;
	ISR_Registers.PIS0	= CLR;
	ICR_Registers.PIC0	= CLR;
	ODR_Registers.POD0	= CLR;
	IDR_Registers.PID0	= CLR;
	BSR_Registers.BSD0	= CLR;
	BCR_Registers.BCD0	= CLR;

	// PF	1
	MR1_Registers.P1MUX	= CLR;
	CR_Registers.P1		= CLR;
	PRCR_Registers.PUE1	= CLR;
	DER_Registers.PDE1	= CLR;
	STR_Registers.PST1	= CLR;
	IER_Registers.PIE1	= CLR;
	ISR_Registers.PIS1	= CLR;
	ICR_Registers.PIC1	= CLR;
	ODR_Registers.POD1	= CLR;
	IDR_Registers.PID1	= CLR;
	BSR_Registers.BSD1	= CLR;
	BCR_Registers.BCD1	= CLR;

	// PF	2
	MR1_Registers.P2MUX	= CLR;
	CR_Registers.P2		= CLR;
	PRCR_Registers.PUE2	= CLR;
	DER_Registers.PDE2	= CLR;
	STR_Registers.PST2	= CLR;
	IER_Registers.PIE2	= CLR;
	ISR_Registers.PIS2	= CLR;
	ICR_Registers.PIC2	= CLR;
	ODR_Registers.POD2	= CLR;
	IDR_Registers.PID2	= CLR;
	BSR_Registers.BSD2	= CLR;
	BCR_Registers.BCD2	= CLR;

	// PF	3
	MR1_Registers.P3MUX	= CLR;
	CR_Registers.P3		= CLR;
	PRCR_Registers.PUE3	= CLR;
	DER_Registers.PDE3	= CLR;
	STR_Registers.PST3	= CLR;
	IER_Registers.PIE3	= CLR;
	ISR_Registers.PIS3	= CLR;
	ICR_Registers.PIC3	= CLR;
	ODR_Registers.POD3	= CLR;
	IDR_Registers.PID3	= CLR;
	BSR_Registers.BSD3	= CLR;
	BCR_Registers.BCD3	= CLR;

	// PF	4
	MR1_Registers.P4MUX	= Func_0;
	CR_Registers.P4		= OD_Output;
	PRCR_Registers.PUE4	= CLR;
	DER_Registers.PDE4	= CLR;
	STR_Registers.PST4	= CLR;
	IER_Registers.PIE4	= CLR;
	ISR_Registers.PIS4	= CLR;
	ICR_Registers.PIC4	= CLR;
	ODR_Registers.POD4	= CLR;
	IDR_Registers.PID4	= CLR;
	BSR_Registers.BSD4	= CLR;
	BCR_Registers.BCD4	= CLR;

	// PF	5
	MR1_Registers.P5MUX	= Func_0;
	CR_Registers.P5		= OD_Output;
	PRCR_Registers.PUE5	= CLR;
	DER_Registers.PDE5	= CLR;
	STR_Registers.PST5	= CLR;
	IER_Registers.PIE5	= CLR;
	ISR_Registers.PIS5	= CLR;
	ICR_Registers.PIC5	= CLR;
	ODR_Registers.POD5	= CLR;
	IDR_Registers.PID5	= CLR;
	BSR_Registers.BSD5	= CLR;
	BCR_Registers.BCD5	= CLR;

	// PF	6
	MR1_Registers.P6MUX	= Func_0;
	CR_Registers.P6		= OD_Output;
	PRCR_Registers.PUE6	= CLR;
	DER_Registers.PDE6	= CLR;
	STR_Registers.PST6	= CLR;
	IER_Registers.PIE6	= CLR;
	ISR_Registers.PIS6	= CLR;
	ICR_Registers.PIC6	= CLR;
	ODR_Registers.POD6	= CLR;
	IDR_Registers.PID6	= CLR;
	BSR_Registers.BSD6	= CLR;
	BCR_Registers.BCD6	= CLR;

	// PF	7
	MR1_Registers.P7MUX	= Func_0;
	CR_Registers.P7		= OD_Output;
	PRCR_Registers.PUE7	= CLR;
	DER_Registers.PDE7	= CLR;
	STR_Registers.PST7	= CLR;
	IER_Registers.PIE7	= CLR;
	ISR_Registers.PIS7	= CLR;
	ICR_Registers.PIC7	= CLR;
	ODR_Registers.POD7	= CLR;
	IDR_Registers.PID7	= CLR;
	BSR_Registers.BSD7	= CLR;
	BCR_Registers.BCD7	= CLR;

	// PF	8
	MR2_Registers.P8MUX	= CLR;
	CR_Registers.P8		= CLR;
	PRCR_Registers.PUE8	= CLR;
	DER_Registers.PDE8	= CLR;
	STR_Registers.PST8	= CLR;
	IER_Registers.PIE8	= CLR;
	ISR_Registers.PIS8	= CLR;
	ICR_Registers.PIC8	= CLR;
	ODR_Registers.POD8	= CLR;
	IDR_Registers.PID8	= CLR;
	BSR_Registers.BSD8	= CLR;
	BCR_Registers.BCD8	= CLR;

	// PF	9
	MR2_Registers.P9MUX	= CLR;
	CR_Registers.P9		= CLR;
	PRCR_Registers.PUE9	= CLR;
	DER_Registers.PDE9	= CLR;
	STR_Registers.PST9	= CLR;
	IER_Registers.PIE9	= CLR;
	ISR_Registers.PIS9	= CLR;
	ICR_Registers.PIC9	= CLR;
	ODR_Registers.POD9	= CLR;
	IDR_Registers.PID9	= CLR;
	BSR_Registers.BSD9	= CLR;
	BCR_Registers.BCD9	= CLR;

	// PF	10
	MR2_Registers.P10MUX= CLR;
	CR_Registers.P10	= CLR;
	PRCR_Registers.PUE10= CLR;
	DER_Registers.PDE10	= CLR;
	STR_Registers.PST10	= CLR;
	IER_Registers.PIE10	= CLR;
	ISR_Registers.PIS10	= CLR;
	ICR_Registers.PIC10	= CLR;
	ODR_Registers.POD10	= CLR;
	IDR_Registers.PID10	= CLR;
	BSR_Registers.BSD10	= CLR;
	BCR_Registers.BCD10	= CLR;

	// PF	11
	MR2_Registers.P11MUX= CLR;
	CR_Registers.P11	= CLR;
	PRCR_Registers.PUE11= CLR;
	DER_Registers.PDE11	= CLR;
	STR_Registers.PST11	= CLR;
	IER_Registers.PIE11	= CLR;
	ISR_Registers.PIS11	= CLR;
	ICR_Registers.PIC11	= CLR;
	ODR_Registers.POD11	= CLR;
	IDR_Registers.PID11	= CLR;
	BSR_Registers.BSD11	= CLR;
	BCR_Registers.BCD11	= CLR;

	// PF	12
	MR2_Registers.P12MUX= CLR;
	CR_Registers.P12	= CLR;
	PRCR_Registers.PUE12= CLR;
	DER_Registers.PDE12	= CLR;
	STR_Registers.PST12	= CLR;
	IER_Registers.PIE12	= CLR;
	ISR_Registers.PIS12	= CLR;
	ICR_Registers.PIC12	= CLR;
	ODR_Registers.POD12	= CLR;
	IDR_Registers.PID12	= CLR;
	BSR_Registers.BSD12	= CLR;
	BCR_Registers.BCD12	= CLR;

	// PF	13
	MR2_Registers.P13MUX= CLR;
	CR_Registers.P13	= CLR;
	PRCR_Registers.PUE13= CLR;
	DER_Registers.PDE13	= CLR;
	STR_Registers.PST13	= CLR;
	IER_Registers.PIE13	= CLR;
	ISR_Registers.PIS13	= CLR;
	ICR_Registers.PIC13	= CLR;
	ODR_Registers.POD13	= CLR;
	IDR_Registers.PID13	= CLR;
	BSR_Registers.BSD13	= CLR;
	BCR_Registers.BCD13	= CLR;

	// PF	14
	MR2_Registers.P14MUX= CLR;
	CR_Registers.P14	= CLR;
	PRCR_Registers.PUE14= CLR;
	DER_Registers.PDE14	= CLR;
	STR_Registers.PST14	= CLR;
	IER_Registers.PIE14	= CLR;
	ISR_Registers.PIS14	= CLR;
	ICR_Registers.PIC14	= CLR;
	ODR_Registers.POD14	= CLR;
	IDR_Registers.PID14	= CLR;
	BSR_Registers.BSD14	= CLR;
	BCR_Registers.BCD14	= CLR;

	// PF	15
	MR2_Registers.P15MUX= CLR;
	CR_Registers.P15	= CLR;
	PRCR_Registers.PUE15= CLR;
	DER_Registers.PDE15	= CLR;
	STR_Registers.PST15	= CLR;
	IER_Registers.PIE15	= CLR;
	ISR_Registers.PIS15	= CLR;
	ICR_Registers.PIC15	= CLR;
	ODR_Registers.POD15	= CLR;
	IDR_Registers.PID15	= CLR;
	BSR_Registers.BSD15	= CLR;
	BCR_Registers.BCD15	= CLR;

	// PF	15
	WROS_PF->MR1_register	=  MR1_Registers;
	WROS_PF->MR2_register	=  MR2_Registers;
	WROS_PF->CR_register	=  CR_Registers;
	WROS_PF->PRCR_register	=  PRCR_Registers;
	WROS_PF->DER_register	=  DER_Registers;
	WROS_PF->STR_register	=  STR_Registers;
	WROS_PF->IER_register	=  IER_Registers;
	WROS_PF->ISR_register	=  ISR_Registers;
	WROS_PF->ICR_register	=  ICR_Registers;
	WROS_PF->ODR_register	=  ODR_Registers;
	WROS_PF->IDR_register	=  IDR_Registers;
	WROS_PF->BSR_register	=  BSR_Registers;
	WROS_PF->BCR_register	=  BCR_Registers;

}

void Init_GPIO_PG()
{

	// PG	0
	MR1_Registers.P0MUX	= CLR;
	CR_Registers.P0		= CLR;
	PRCR_Registers.PUE0	= CLR;
	DER_Registers.PDE0	= CLR;
	STR_Registers.PST0	= CLR;
	IER_Registers.PIE0	= CLR;
	ISR_Registers.PIS0	= CLR;
	ICR_Registers.PIC0	= CLR;
	ODR_Registers.POD0	= CLR;
	IDR_Registers.PID0	= CLR;
	BSR_Registers.BSD0	= CLR;
	BCR_Registers.BCD0	= CLR;

	// PG	1
	MR1_Registers.P1MUX	= CLR;
	CR_Registers.P1		= CLR;
	PRCR_Registers.PUE1	= CLR;
	DER_Registers.PDE1	= CLR;
	STR_Registers.PST1	= CLR;
	IER_Registers.PIE1	= CLR;
	ISR_Registers.PIS1	= CLR;
	ICR_Registers.PIC1	= CLR;
	ODR_Registers.POD1	= CLR;
	IDR_Registers.PID1	= CLR;
	BSR_Registers.BSD1	= CLR;
	BCR_Registers.BCD1	= CLR;

	// PG	2
	MR1_Registers.P2MUX	= CLR;
	CR_Registers.P2		= CLR;
	PRCR_Registers.PUE2	= CLR;
	DER_Registers.PDE2	= CLR;
	STR_Registers.PST2	= CLR;
	IER_Registers.PIE2	= CLR;
	ISR_Registers.PIS2	= CLR;
	ICR_Registers.PIC2	= CLR;
	ODR_Registers.POD2	= CLR;
	IDR_Registers.PID2	= CLR;
	BSR_Registers.BSD2	= CLR;
	BCR_Registers.BCD2	= CLR;

	// PG	3
	MR1_Registers.P3MUX	= CLR;
	CR_Registers.P3		= CLR;
	PRCR_Registers.PUE3	= CLR;
	DER_Registers.PDE3	= CLR;
	STR_Registers.PST3	= CLR;
	IER_Registers.PIE3	= CLR;
	ISR_Registers.PIS3	= CLR;
	ICR_Registers.PIC3	= CLR;
	ODR_Registers.POD3	= CLR;
	IDR_Registers.PID3	= CLR;
	BSR_Registers.BSD3	= CLR;
	BCR_Registers.BCD3	= CLR;

	// PG	4
	MR1_Registers.P4MUX	= CLR;
	CR_Registers.P4		= CLR;
	PRCR_Registers.PUE4	= CLR;
	DER_Registers.PDE4	= CLR;
	STR_Registers.PST4	= CLR;
	IER_Registers.PIE4	= CLR;
	ISR_Registers.PIS4	= CLR;
	ICR_Registers.PIC4	= CLR;
	ODR_Registers.POD4	= CLR;
	IDR_Registers.PID4	= CLR;
	BSR_Registers.BSD4	= CLR;
	BCR_Registers.BCD4	= CLR;

	// PG	5
	MR1_Registers.P5MUX	= CLR;
	CR_Registers.P5		= CLR;
	PRCR_Registers.PUE5	= CLR;
	DER_Registers.PDE5	= CLR;
	STR_Registers.PST5	= CLR;
	IER_Registers.PIE5	= CLR;
	ISR_Registers.PIS5	= CLR;
	ICR_Registers.PIC5	= CLR;
	ODR_Registers.POD5	= CLR;
	IDR_Registers.PID5	= CLR;
	BSR_Registers.BSD5	= CLR;
	BCR_Registers.BCD5	= CLR;

	// PG	6
	MR1_Registers.P6MUX	= CLR;
	CR_Registers.P6		= CLR;
	PRCR_Registers.PUE6	= CLR;
	DER_Registers.PDE6	= CLR;
	STR_Registers.PST6	= CLR;
	IER_Registers.PIE6	= CLR;
	ISR_Registers.PIS6	= CLR;
	ICR_Registers.PIC6	= CLR;
	ODR_Registers.POD6	= CLR;
	IDR_Registers.PID6	= CLR;
	BSR_Registers.BSD6	= CLR;
	BCR_Registers.BCD6	= CLR;

	// PG	7
	MR1_Registers.P7MUX	= CLR;
	CR_Registers.P7		= CLR;
	PRCR_Registers.PUE7	= CLR;
	DER_Registers.PDE7	= CLR;
	STR_Registers.PST7	= CLR;
	IER_Registers.PIE7	= CLR;
	ISR_Registers.PIS7	= CLR;
	ICR_Registers.PIC7	= CLR;
	ODR_Registers.POD7	= CLR;
	IDR_Registers.PID7	= CLR;
	BSR_Registers.BSD7	= CLR;
	BCR_Registers.BCD7	= CLR;

	// PG	8
	MR2_Registers.P8MUX	= CLR;
	CR_Registers.P8		= CLR;
	PRCR_Registers.PUE8	= CLR;
	DER_Registers.PDE8	= CLR;
	STR_Registers.PST8	= CLR;
	IER_Registers.PIE8	= CLR;
	ISR_Registers.PIS8	= CLR;
	ICR_Registers.PIC8	= CLR;
	ODR_Registers.POD8	= CLR;
	IDR_Registers.PID8	= CLR;
	BSR_Registers.BSD8	= CLR;
	BCR_Registers.BCD8	= CLR;

	// PG	9
	MR2_Registers.P9MUX	= CLR;
	CR_Registers.P9		= CLR;
	PRCR_Registers.PUE9	= CLR;
	DER_Registers.PDE9	= CLR;
	STR_Registers.PST9	= CLR;
	IER_Registers.PIE9	= CLR;
	ISR_Registers.PIS9	= CLR;
	ICR_Registers.PIC9	= CLR;
	ODR_Registers.POD9	= CLR;
	IDR_Registers.PID9	= CLR;
	BSR_Registers.BSD9	= CLR;
	BCR_Registers.BCD9	= CLR;

	// PG	10
	MR2_Registers.P10MUX= CLR;
	CR_Registers.P10	= CLR;
	PRCR_Registers.PUE10= CLR;
	DER_Registers.PDE10	= CLR;
	STR_Registers.PST10	= CLR;
	IER_Registers.PIE10	= CLR;
	ISR_Registers.PIS10	= CLR;
	ICR_Registers.PIC10	= CLR;
	ODR_Registers.POD10	= CLR;
	IDR_Registers.PID10	= CLR;
	BSR_Registers.BSD10	= CLR;
	BCR_Registers.BCD10	= CLR;

	// PG	11
	MR2_Registers.P11MUX= CLR;
	CR_Registers.P11	= CLR;
	PRCR_Registers.PUE11= CLR;
	DER_Registers.PDE11	= CLR;
	STR_Registers.PST11	= CLR;
	IER_Registers.PIE11	= CLR;
	ISR_Registers.PIS11	= CLR;
	ICR_Registers.PIC11	= CLR;
	ODR_Registers.POD11	= CLR;
	IDR_Registers.PID11	= CLR;
	BSR_Registers.BSD11	= CLR;
	BCR_Registers.BCD11	= CLR;

	// PG	12
	MR2_Registers.P12MUX= CLR;
	CR_Registers.P12	= CLR;
	PRCR_Registers.PUE12= CLR;
	DER_Registers.PDE12	= CLR;
	STR_Registers.PST12	= CLR;
	IER_Registers.PIE12	= CLR;
	ISR_Registers.PIS12	= CLR;
	ICR_Registers.PIC12	= CLR;
	ODR_Registers.POD12	= CLR;
	IDR_Registers.PID12	= CLR;
	BSR_Registers.BSD12	= CLR;
	BCR_Registers.BCD12	= CLR;

	// PG	13
	MR2_Registers.P13MUX= CLR;
	CR_Registers.P13	= CLR;
	PRCR_Registers.PUE13= CLR;
	DER_Registers.PDE13	= CLR;
	STR_Registers.PST13	= CLR;
	IER_Registers.PIE13	= CLR;
	ISR_Registers.PIS13	= CLR;
	ICR_Registers.PIC13	= CLR;
	ODR_Registers.POD13	= CLR;
	IDR_Registers.PID13	= CLR;
	BSR_Registers.BSD13	= CLR;
	BCR_Registers.BCD13	= CLR;

	// PG	14
	MR2_Registers.P14MUX= CLR;
	CR_Registers.P14	= CLR;
	PRCR_Registers.PUE14= CLR;
	DER_Registers.PDE14	= CLR;
	STR_Registers.PST14	= CLR;
	IER_Registers.PIE14	= CLR;
	ISR_Registers.PIS14	= CLR;
	ICR_Registers.PIC14	= CLR;
	ODR_Registers.POD14	= CLR;
	IDR_Registers.PID14	= CLR;
	BSR_Registers.BSD14	= CLR;
	BCR_Registers.BCD14	= CLR;

	// PG	15
	MR2_Registers.P15MUX= CLR;
	CR_Registers.P15	= CLR;
	PRCR_Registers.PUE15= CLR;
	DER_Registers.PDE15	= CLR;
	STR_Registers.PST15	= CLR;
	IER_Registers.PIE15	= CLR;
	ISR_Registers.PIS15	= CLR;
	ICR_Registers.PIC15	= CLR;
	ODR_Registers.POD15	= CLR;
	IDR_Registers.PID15	= CLR;
	BSR_Registers.BSD15	= CLR;
	BCR_Registers.BCD15	= CLR;

	// PG	15
	WROS_PG->MR1_register	=  MR1_Registers;
	WROS_PG->MR2_register	=  MR2_Registers;
	WROS_PG->CR_register	=  CR_Registers;
	WROS_PG->PRCR_register	=  PRCR_Registers;
	WROS_PG->DER_register	=  DER_Registers;
	WROS_PG->STR_register	=  STR_Registers;
	WROS_PG->IER_register	=  IER_Registers;
	WROS_PG->ISR_register	=  ISR_Registers;
	WROS_PG->ICR_register	=  ICR_Registers;
	WROS_PG->ODR_register	=  ODR_Registers;
	WROS_PG->IDR_register	=  IDR_Registers;
	WROS_PG->BSR_register	=  BSR_Registers;
	WROS_PG->BCR_register	=  BCR_Registers;

}

void Init_Timer_0()
{
	CR2_Registers.TCLR			= SET;
	WROS_TIER_0->CR2_register	= CR2_Registers;
	CR2_Registers.TCLR			= CLR;
	WROS_TIER_0->CR2_register	= CR2_Registers;

	CR1_Registers.TRGMOD		= 0;
	CR1_Registers.UAO			= 0;
	CR1_Registers.MODE			= 0;
	CR1_Registers.CKSEL			= 0;

	PRS_Registers.PRS			= 0;
	GRA_Registers.GRA			= 1100;
	CNT_Registers.CNT			= 0;
	TIMER_IER_Registers.MAIE			= SET;
	CR2_Registers.TEN			= SET;

	WROS_TIER_0->CR1_register		= CR1_Registers;
	WROS_TIER_0->PRS_register		= PRS_Registers;
	WROS_TIER_0->GRA_register		= GRA_Registers;
	WROS_TIER_0->CNT_register		= CNT_Registers;
	WROS_TIER_0->TIMER_IER_register		= TIMER_IER_Registers;
	WROS_TIER_0->CR2_register		= CR2_Registers;







	NVIC_SetPriority(TIMER0_IRQn, 3);
	NVIC_EnableIRQ(TIMER0_IRQn);
}


void Init_UART_0()
{
	WROS_UART_0->THR_register.DATA_Buffer		= CLR;

	WROS_UART_0->UART_IER_register.DRIE			= SET;
	WROS_UART_0->UART_IER_register.THREIE		= SET;
	WROS_UART_0->UART_IER_register.RLSIE			= CLR;
	WROS_UART_0->UART_IER_register.TXEIE			= CLR;
	WROS_UART_0->UART_IER_register.DRXIEN		= CLR;
	WROS_UART_0->UART_IER_register.DTXIEN		= CLR;

	//WROS_UART_0->IIR_register.

	WROS_UART_0->LCR_register.DLEN			= 3;	// 8 bit data
	WROS_UART_0->LCR_register.STOPBIT		= 0;
	WROS_UART_0->LCR_register.PEN			= 0;	// Disables parity.
	WROS_UART_0->LCR_register.BREAK			= 0;

	WROS_UART_0->DCR_register.TXINV			= 0;	// normal Tx data.
	WROS_UART_0->DCR_register.RXINV			= 0;	// normal Rx data.

	//WROS_UART_0->LSR_register.

	WROS_UART_0->BDR_register.BDR			= 19;

	WROS_UART_0->BFR_registers.BFR			= 136;

	WROS_UART_0->IDTR_register.WAITVAL		= 4;
	WROS_UART_0->IDTR_register.DMS			= 1;
	WROS_UART_0->IDTR_register.SMS			= 1;

	NVIC_EnableIRQ(UART0_IRQn);
}

void Init_UART_1()
{

	WROS_UART_1->THR_register.DATA_Buffer		= CLR;

	WROS_UART_1->UART_IER_register.DRIE			= SET;
	WROS_UART_1->UART_IER_register.THREIE		= SET;
	WROS_UART_1->UART_IER_register.RLSIE			= CLR;
	WROS_UART_1->UART_IER_register.TXEIE			= CLR;
	WROS_UART_1->UART_IER_register.DRXIEN		= CLR;
	WROS_UART_1->UART_IER_register.DTXIEN		= CLR;

	//WROS_UART_1->IIR_register.

	WROS_UART_1->LCR_register.DLEN			= 3;	// 8 bit data
	WROS_UART_1->LCR_register.STOPBIT		= 0;
	WROS_UART_1->LCR_register.PEN			= 0;	// Disables parity.
	WROS_UART_1->LCR_register.BREAK			= 0;

	WROS_UART_1->DCR_register.TXINV			= 0;	// normal Tx data.
	WROS_UART_1->DCR_register.RXINV			= 0;	// normal Rx data.

	//WROS_UART_1->LSR_register.

	WROS_UART_1->BDR_register.BDR			= 19;

	WROS_UART_1->BFR_registers.BFR			= 136;

	WROS_UART_1->IDTR_register.WAITVAL		= 4;
	WROS_UART_1->IDTR_register.DMS			= 1;
	WROS_UART_1->IDTR_register.SMS			= 1;

	NVIC_EnableIRQ(UART1_IRQn);
}
void Init_UART_2()
{
	UINT8 XX;
	XX 	=		WROS_UART_2->RBR;
	WROS_UART_2->THR_register.DATA_Buffer		= CLR;

	WROS_UART_2->UART_IER_register.DRIE			= CLR;
	//WROS_UART_2->IER_register.THREIE		= SET;
	WROS_UART_2->UART_IER_register.RLSIE			= CLR;
	WROS_UART_2->UART_IER_register.TXEIE			= CLR;
	WROS_UART_2->UART_IER_register.DRXIEN		= CLR;
	WROS_UART_2->UART_IER_register.DTXIEN		= CLR;

	//WROS_UART_2->IIR_register.

	WROS_UART_2->LCR_register.DLEN			= 3;	// 8 bit data
	WROS_UART_2->LCR_register.STOPBIT		= 0;
	WROS_UART_2->LCR_register.PEN			= 0;	// Disables parity.
	WROS_UART_2->LCR_register.BREAK			= 0;

	WROS_UART_2->DCR_register.TXINV			= 0;	// normal Tx data.
	WROS_UART_2->DCR_register.RXINV			= 0;	// normal Rx data.

	//WROS_UART_2->LSR_register.

	WROS_UART_2->BDR_register.BDR			= 19;

	WROS_UART_2->BFR_registers.BFR			= 136;

	WROS_UART_2->IDTR				= 0xC0;

	NVIC_SetPriority(UART2_IRQn, 4);
	NVIC_EnableIRQ(UART2_IRQn);
}
void Init_UART_3()
{

	WROS_UART_3->THR_register.DATA_Buffer		= CLR;

	WROS_UART_3->UART_IER_register.DRIE			= SET;
	WROS_UART_3->UART_IER_register.THREIE		= SET;
	WROS_UART_3->UART_IER_register.RLSIE			= CLR;
	WROS_UART_3->UART_IER_register.TXEIE			= CLR;
	WROS_UART_3->UART_IER_register.DRXIEN		= CLR;
	WROS_UART_3->UART_IER_register.DTXIEN		= CLR;

	//WROS_UART_3->IIR_register.

	WROS_UART_3->LCR_register.DLEN			= 3;	// 8 bit data
	WROS_UART_3->LCR_register.STOPBIT		= 0;
	WROS_UART_3->LCR_register.PEN			= 0;	// Disables parity.
	WROS_UART_3->LCR_register.BREAK			= 0;

	WROS_UART_3->DCR_register.TXINV			= 0;	// normal Tx data.
	WROS_UART_3->DCR_register.RXINV			= 0;	// normal Rx data.

	//WROS_UART_3->LSR_register.

	WROS_UART_3->BDR_register.BDR			= 19;

	WROS_UART_3->BFR_registers.BFR			= 136;

	WROS_UART_3->IDTR_register.WAITVAL		= 4;
	WROS_UART_3->IDTR_register.DMS			= 1;
	WROS_UART_3->IDTR_register.SMS			= 1;

	NVIC_EnableIRQ(UART3_IRQn);
}
void Init_UART_4()
{

	WROS_UART_4->THR_register.DATA_Buffer		= CLR;

	WROS_UART_4->UART_IER_register.DRIE			= SET;
	WROS_UART_4->UART_IER_register.THREIE		= SET;
	WROS_UART_4->UART_IER_register.RLSIE			= CLR;
	WROS_UART_4->UART_IER_register.TXEIE			= CLR;
	WROS_UART_4->UART_IER_register.DRXIEN		= CLR;
	WROS_UART_4->UART_IER_register.DTXIEN		= CLR;

	//WROS_UART_4->IIR_register.

	WROS_UART_4->LCR_register.DLEN			= 3;	// 8 bit data
	WROS_UART_4->LCR_register.STOPBIT		= 0;
	WROS_UART_4->LCR_register.PEN			= 0;	// Disables parity.
	WROS_UART_4->LCR_register.BREAK			= 0;

	WROS_UART_4->DCR_register.TXINV			= 0;	// normal Tx data.
	WROS_UART_4->DCR_register.RXINV			= 0;	// normal Rx data.

	//WROS_UART_4->LSR_register.

	WROS_UART_4->BDR_register.BDR			= 19;

	WROS_UART_4->BFR_registers.BFR			= 136;

	WROS_UART_4->IDTR_register.WAITVAL		= 4;
	WROS_UART_4->IDTR_register.DMS			= 1;
	WROS_UART_4->IDTR_register.SMS			= 1;

	NVIC_EnableIRQ(UART4_IRQn);
}

void Init_UART_5()
{

	WROS_UART_5->THR_register.DATA_Buffer		= CLR;

	WROS_UART_5->UART_IER_register.DRIE			= SET;
	WROS_UART_5->UART_IER_register.THREIE		= SET;
	WROS_UART_5->UART_IER_register.RLSIE			= CLR;
	WROS_UART_5->UART_IER_register.TXEIE			= CLR;
	WROS_UART_5->UART_IER_register.DRXIEN		= CLR;
	WROS_UART_5->UART_IER_register.DTXIEN		= CLR;

	//WROS_UART_5->IIR_register.

	WROS_UART_5->LCR_register.DLEN			= 3;	// 8 bit data
	WROS_UART_5->LCR_register.STOPBIT		= 0;
	WROS_UART_5->LCR_register.PEN			= 0;	// Disables parity.
	WROS_UART_5->LCR_register.BREAK			= 0;

	WROS_UART_5->DCR_register.TXINV			= 0;	// normal Tx data.
	WROS_UART_5->DCR_register.RXINV			= 0;	// normal Rx data.

	//WROS_UART_5->LSR_register.

	WROS_UART_5->BDR_register.BDR			= 19;

	WROS_UART_5->BFR_registers.BFR			= 136;

	WROS_UART_5->IDTR_register.WAITVAL		= 4;
	WROS_UART_5->IDTR_register.DMS			= 1;
	WROS_UART_5->IDTR_register.SMS			= 1;

	NVIC_EnableIRQ(UART5_IRQn);
}


void Init_IIC_0()
{
	WROS_I2C_0->I2C_CR_register.START	= 1;
	//WROS_I2C_0->CR_register.STOP	= 1;
	WROS_I2C_0->I2C_CR_register.ACKEN	= 1;
	WROS_I2C_0->I2C_CR_register.INTEN	= 1;
	WROS_I2C_0->I2C_CR_register.INTDEL	= 3;



/*
	WROS_I2C_0->DR_register		= 0;
	WROS_I2C_0->SR_register		= 0;
	WROS_I2C_0->SAR_register	= 0;
	WROS_I2C_0->CR_register.INTEN		= 0;
	WROS_I2C_0->CR_register.START		= 0;
	WROS_I2C_0->SCLL_register	= 0;
	WROS_I2C_0->SCLH_register	= 0;
	WROS_I2C_0->SDAH_register	= 0;
*/
}


void Init_PWM_0()
{
//      SCU_MPEM_SCCR()                         // 120Mhz / 2 => 60Mhz
//      API_MPWM_Peri_Init();
//      TBD     SCU->PER2,      SCU->PCER2

    
  
  
  
	MPWM_CR1_Registers.PWMEN	= 1;    // PWM ENABLE

	MPWM_CR2_Registers.PSTART	= 0;    // 
        
        
	MR_Registers.MOTORB		= 0;    // 0: motor mode
	MR_Registers.UAO		= 0;    // 0: update are performed at designated timings                1: after 2 PWM clocks
	MR_Registers.TUP		= 1;    // 0: No updated                1: every period match
	MR_Registers.BUP		= 0;    // 0: No updated                1: every bottom match
	MR_Registers.MCHMOD		= 2;    // 0: 2-ch symmetric            1: 1-ch asymmetric              2: 1-ch symmetric
	MR_Registers.UPDOWN     	= 1;    // 0: PWM UP count              1: PWM UP/DOWN


	FOLR_Registers.WHFL		= 0;
	FOLR_Registers.VHFL		= 0;
	FOLR_Registers.UHFL		= 0;
	FOLR_Registers.WLFL		= 0;
	FOLR_Registers.VLFL		= 0;
	FOLR_Registers.ULFL		= 0;

//	PRD_Registers.PERIOD		= (uint16_t)((60000000UL / (PWM_HZ * 2)) - 1);

	DTR_Registers.DT		= 0x3C; // 2 usec => 0.000002 * 60000000UL / 2 = 60 = 0x3C
	DTR_Registers.DTCLK		= 0;    // 0: CLK / 2
	DTR_Registers.DTMDSEL		= 1;    // 
	DTR_Registers.PSHRT		= 0;    // 
	DTR_Registers.DTEN		= 1;    // DT EN
        
	PCR_Registers.UHPROTM		= 0;
	OCR_Registers.UHOVIN		= 0;
        
	PSR_Registers.UHPROT		= 0;
	OSR_Registers.UHOVIN		= 0;
        
//      PWM_ADC_Set_ADC_Trigger();        
//      TBD
        
        
        
        
        
        
        
        
        
        
	MPWM_IER_Registers.ULIE		= 1;
	MPWM_IER_Registers.VLIE		= 0;
	MPWM_IER_Registers.WLIE		= 0;
	MPWM_IER_Registers.UHIE		= 0;
	MPWM_IER_Registers.VHIE		= 0;
	MPWM_IER_Registers.WHIE		= 0;
	MPWM_IER_Registers.BOTIE        = 0;
	MPWM_IER_Registers.PRDIE        = 0;
        
//      U_PHASE_DUTY                    = 0;
//      V_PHASE_DUTY                    = 0;
//      W_PHASE_DUTY                    = 0;
        
        
	MR_Registers.UAO             	= 1;
	WROS_MPWM_0->MR_register	= MR_Registers;
	MR_Registers.UAO             	= 0;
	WROS_MPWM_0->MR_register	= MR_Registers;
        
//      DDI_Motor_Mode(BREAK);
//      TBD
//      UINT8 ulFORReg32 = 0;
//      UINT8 ulPSRReg32 = 0xCA00;
//      ulFORReg32 = (BREAK >> 8) & 0x00FF;
//      ulPSRReg32 |= (BREAK) & 0x00FF;
//      PWM0->FOLR = ulFORReg32;
//      PWM0->PSR = ulPSRReg32;
        
        
        
        
	OLR_Registers.ULL		= 1;
	OLR_Registers.VLL       	= 1;
	OLR_Registers.WLL		= 1;
	OLR_Registers.UHL		= 1;
	OLR_Registers.VHL		= 1;
	OLR_Registers.WHL		= 1;
	OLR_Registers.DOLUL		= 0;
	OLR_Registers.DOLVL		= 0;
	OLR_Registers.DOLWL		= 0;
	OLR_Registers.DOLUH		= 0;
	OLR_Registers.DOLVH     	= 0;
	OLR_Registers.DOLWH		= 0;
        
        
        
	MPWM_SR_Registers.DUHIF 	= 1;
	MPWM_SR_Registers.DVHIF 	= 1;
	MPWM_SR_Registers.DWHIF 	= 1;
	MPWM_SR_Registers.DULIF 	= 1;
	MPWM_SR_Registers.DVLIF 	= 1;
	MPWM_SR_Registers.DWLIF 	= 1;
	MPWM_SR_Registers.PRDUIF 	= 1;
	MPWM_SR_Registers.BOTUIF 	= 1;
        
        
        
        
 /*       
	DUH_Registers.DUTY_UH		= 0;
	DVH_Registers.DUTY_VH		= 0;
	DWH_Registers.DUTY_WH		= 0;
	DUL_Registers.DUTY_UL		= 0;
	DVL_Registers.DUTY_VL		= 0;
	DWL_Registers.DUTY_WL		= 0;




	MPWM_CNT_Registers.CNT		= 0;


	ATRm_Registers.ATCNT		= 1;
*/        
        
        
        
        

	WROS_MPWM_0->MR_register	= MR_Registers;
	WROS_MPWM_0->OLR_register	= OLR_Registers;
	WROS_MPWM_0->FOLR_register	= FOLR_Registers;
	WROS_MPWM_0->PRD_register	= PRD_Registers;

	WROS_MPWM_0->DUH_register	= DUH_Registers;
	WROS_MPWM_0->DVH_register	= DVH_Registers;
	WROS_MPWM_0->DWH_register	= DWH_Registers;
	WROS_MPWM_0->DUL_register	= DUL_Registers;
	WROS_MPWM_0->DVL_register	= DVL_Registers;
	WROS_MPWM_0->DWL_register	= DWL_Registers;

	WROS_MPWM_0->MPWM_CR1_register	= MPWM_CR1_Registers;
	WROS_MPWM_0->MPWM_CR2_register	= MPWM_CR2_Registers;

//	WROS_MPWM_0->MPWM_SR_register	= MPWM_SR_Registers;
	WROS_MPWM_0->MPWM_IER_register	= MPWM_IER_Registers;
//	WROS_MPWM_0->MPWM_CNT_register	= MPWM_CNT_Registers;

	WROS_MPWM_0->DTR_register	= DTR_Registers;
	WROS_MPWM_0->PCR_register	= PCR_Registers;
	WROS_MPWM_0->PSR_register	= PSR_Registers;
	WROS_MPWM_0->OCR_register	= OCR_Registers;
	WROS_MPWM_0->OSR_register	= OSR_Registers;
	WROS_MPWM_0->ATRm_register	= ATRm_Registers;

        
//	NVIC_EnableIRQ(MPWM0U_IRQn);
        
	MPWM_CR2_Registers.PSTART	= 1;    // start PWM
	WROS_MPWM_0->MPWM_CR2_register	= MPWM_CR2_Registers;
        
        
        
}




