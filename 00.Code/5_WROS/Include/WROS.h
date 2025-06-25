

#include "../../4_Library/Include/general.h"


#ifndef WROS_H
#define WROS_H


/* =========================================================================================================================== */
/* ================                                Interrupt Number Definition                                ================ */
/* =========================================================================================================================== */

typedef enum {
/* =======================================  ARM Cortex-M4 Specific Interrupt Numbers  ======================================== */
  Reset_IRQn                = -15,              /*!< -15  Reset Vector, invoked on Power up and warm reset                     */
  NonMaskableInt_IRQn       = -14,              /*!< -14  Non maskable Interrupt, cannot be stopped or preempted               */
  HardFault_IRQn            = -13,              /*!< -13  Hard Fault, all classes of Fault                                     */
  MemoryManagement_IRQn     = -12,              /*!< -12  Memory Management, MPU mismatch, including Access Violation and No Match */
  BusFault_IRQn             = -11,              /*!< -11  Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory related Fault*/
  UsageFault_IRQn           = -10,              /*!< -10  Usage Fault, i.e. Undef Instruction, Illegal State Transition        */
  SVCall_IRQn               =  -5,              /*!< -5 System Service Call via SVC instruction                                */
  DebugMonitor_IRQn         =  -4,              /*!< -4 Debug Monitor                                                          */
  PendSV_IRQn               =  -2,              /*!< -2 Pendable request for system service                                    */
  SysTick_IRQn              =  -1,              /*!< -1 System Tick Timer                                                      */
/* ==========================================  a34m41x Specific Interrupt Numbers  =========================================== */
  LVI_IRQn                  =   0,              /*!< 0  LVI                                                                    */
  SYSCLKFAIL_IRQn           =   1,              /*!< 1  SYSCLKFAIL                                                             */
  HSEFAIL_IRQn              =   2,              /*!< 2  HSEFAIL                                                                */
  LSEFAIL_IRQn              =   3,              /*!< 3  LSEFAIL                                                                */
  WDT_IRQn                  =   6,              /*!< 6  WDT                                                                    */
  FRT0_IRQn                 =   8,              /*!< 8  FRT0                                                                   */
  FRT1_IRQn                 =   9,              /*!< 9  FRT1                                                                   */
  CFMC_IRQn                 =  11,              /*!< 11 CFMC                                                                   */
  DFMC_IRQn                 =  12,              /*!< 12 DFMC                                                                   */
  TIMER0_IRQn               =  15,              /*!< 15 TIMER0                                                                 */
  TIMER1_IRQn               =  16,              /*!< 16 TIMER1                                                                 */
  TIMER2_IRQn               =  17,              /*!< 17 TIMER2                                                                 */
  TIMER3_IRQn               =  18,              /*!< 18 TIMER3                                                                 */
  TIMER4_IRQn               =  19,              /*!< 19 TIMER4                                                                 */
  TIMER5_IRQn               =  20,              /*!< 20 TIMER5                                                                 */
  TIMER6_IRQn               =  21,              /*!< 21 TIMER6                                                                 */
  TIMER7_IRQn               =  22,              /*!< 22 TIMER7                                                                 */
  TIMER8_IRQn               =  23,              /*!< 23 TIMER8                                                                 */
  TIMER9_IRQn               =  24,              /*!< 24 TIMER9                                                                 */
  RNG_IRQn                  =  27,              /*!< 27 RNG                                                                    */
  AES128_IRQn               =  28,              /*!< 28 AES128                                                                 */
  QEI0_IRQn                 =  31,              /*!< 31 QEI0                                                                   */
  QEI1_IRQn                 =  32,              /*!< 32 QEI1                                                                   */
  GPIOA_IRQn                =  36,              /*!< 36 GPIOA                                                                  */
  GPIOB_IRQn                =  37,              /*!< 37 GPIOB                                                                  */
  GPIOC_IRQn                =  38,              /*!< 38 GPIOC                                                                  */
  GPIOD_IRQn                =  39,              /*!< 39 GPIOD                                                                  */
  GPIOE_IRQn                =  40,              /*!< 40 GPIOE                                                                  */
  GPIOF_IRQn                =  41,              /*!< 41 GPIOF                                                                  */
  GPIOG_IRQn                =  42,              /*!< 42 GPIOG                                                                  */
  MPWM0PROT_IRQn            =  45,              /*!< 45 MPWM0PROT                                                              */
  MPWM0OVV_IRQn             =  46,              /*!< 46 MPWM0OVV                                                               */
  MPWM0U_IRQn               =  47,              /*!< 47 MPWM0U                                                                 */
  MPWM0V_IRQn               =  48,              /*!< 48 MPWM0V                                                                 */
  MPWM0W_IRQn               =  49,              /*!< 49 MPWM0W                                                                 */
  MPWM1PROT_IRQn            =  50,              /*!< 50 MPWM1PROT                                                              */
  MPWM1OVV_IRQn             =  51,              /*!< 51 MPWM1OVV                                                               */
  MPWM1U_IRQn               =  52,              /*!< 52 MPWM1U                                                                 */
  MPWM1V_IRQn               =  53,              /*!< 53 MPWM1V                                                                 */
  MPWM1W_IRQn               =  54,              /*!< 54 MPWM1W                                                                 */
  SPI0_IRQn                 =  55,              /*!< 55 SPI0                                                                   */
  SPI1_IRQn                 =  56,              /*!< 56 SPI1                                                                   */
  SPI2_IRQn                 =  57,              /*!< 57 SPI2                                                                   */
  I2C0_IRQn                 =  60,              /*!< 60 I2C0                                                                   */
  I2C1_IRQn                 =  61,              /*!< 61 I2C1                                                                   */
  UART0_IRQn                =  63,              /*!< 63 UART0                                                                  */
  UART1_IRQn                =  64,              /*!< 64 UART1                                                                  */
  UART2_IRQn                =  65,              /*!< 65 UART2                                                                  */
  UART3_IRQn                =  66,              /*!< 66 UART3                                                                  */
  UART4_IRQn                =  67,              /*!< 67 UART4                                                                  */
  UART5_IRQn                =  68,              /*!< 68 UART5                                                                  */
  CAN_IRQn                  =  71,              /*!< 71 CAN                                                                    */
  ADC0_IRQn                 =  74,              /*!< 74 ADC0                                                                   */
  ADC1_IRQn                 =  75,              /*!< 75 ADC1                                                                   */
  ADC2_IRQn                 =  76,              /*!< 76 ADC2                                                                   */
  COMP0_IRQn                =  79,              /*!< 79 COMP0                                                                  */
  COMP1_IRQn                =  80,              /*!< 80 COMP1                                                                  */
  COMP2_IRQn                =  81,              /*!< 81 COMP2                                                                  */
  COMP3_IRQn                =  82,              /*!< 82 COMP3                                                                  */
  CRC_IRQn                  =  85               /*!< 85 CRC                                                                    */
} IRQn_Type;



/* =========================================================================================================================== */
/* ================                           Processor and Core Peripheral Section                           ================ */
/* =========================================================================================================================== */

/* ===========================  Configuration of the ARM Cortex-M4 Processor and Core Peripherals  =========================== */
#define __CM4_REV                 0x0001U       /*!< CM4 Core Revision                                                         */
#define __NVIC_PRIO_BITS               4        /*!< Number of Bits used for Priority Levels                                   */
#define __Vendor_SysTickConfig         0        /*!< Set to 1 if different SysTick Config is used                              */
#define __MPU_PRESENT                  1        /*!< MPU present or not                                                        */
#define __FPU_PRESENT                  1        /*!< FPU present or not                                                        */


/** @} */ /* End of group Configuration_of_CMSIS */


#include "core_cm4.h"                           /*!< ARM Cortex-M4 processor and core peripherals                              */




typedef struct {                                /*!< (@ 0x4000F000) CHIPCONFIG Structure                                       */
  __I  uint32_t  VENDORI;                     /*!< (@ 0x00000000) Vendor ID Register                                         */
  __I  uint32_t  CHIPI;                       /*!< (@ 0x00000004) Chip ID Register                                           */
  __I  uint32_t  REVN;                        /*!< (@ 0x00000008) Revision Number Register                                   */
} WROS_NVIC_Type;                              /*!< Size = 12 (0xc)                                                           */












































/* ========================================  Start of section using anonymous unions  ======================================== */
#if defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
  #pragma clang diagnostic ignored "-Wgnu-anonymous-struct"
  #pragma clang diagnostic ignored "-Wnested-anon-types"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_peripherals
  * @{
  */



/* =========================================================================================================================== */
/* ================                                        CHIPCONFIG                                         ================ */
/* =========================================================================================================================== */


/**
  * @brief Chip Configuration Data (CHIPCONFIG)
  */

typedef struct {                                /*!< (@ 0x4000F000) CHIPCONFIG Structure                                       */
  __I  uint32_t  VENDORID;                     /*!< (@ 0x00000000) Vendor ID Register                                         */
  __I  uint32_t  CHIPID;                       /*!< (@ 0x00000004) Chip ID Register                                           */
  __I  uint32_t  REVNR;                        /*!< (@ 0x00000008) Revision Number Register                                   */
} CHIPCONFIG_Type;                              /*!< Size = 12 (0xc)                                                           */



typedef struct {                                /*!< (@ 0x40000000) SCU Structure                                              */
  __I  uint32_t  RESERVED;
  __IO uint32_t  SMR;                          /*!< (@ 0x00000004) System Mode Register                                       */
  __IO uint32_t  SRCR;                         /*!< (@ 0x00000008) System reset control Register                              */
  __I  uint32_t  RESERVED1;
  __IO uint32_t  WUER;                         /*!< (@ 0x00000010) Wake-up Source Setting Register                            */
  __I  uint32_t  WUSR;                         /*!< (@ 0x00000014) Wake-up Source Status Register                             */
  __IO uint32_t  RSER;                         /*!< (@ 0x00000018) Reset Source Setting Register                              */
  __IO uint32_t  RSSR;                         /*!< (@ 0x0000001C) Reset Source Status Register                               */
  __IO uint32_t  PRER1;                        /*!< (@ 0x00000020) Peripheral Reset Setting Register1                         */
  __IO uint32_t  PRER2;                        /*!< (@ 0x00000024) Peripheral Reset Setting Register2                         */
  __IO uint32_t  PER1;                         /*!< (@ 0x00000028) Peripheral Enable Register1                                */
  __IO uint32_t  PER2;                         /*!< (@ 0x0000002C) Peripheral Enable Register2                                */
  __IO uint32_t  PCER1;                        /*!< (@ 0x00000030) Peripheral Clock Enable Register1                          */
  __IO uint32_t  PCER2;                        /*!< (@ 0x00000034) Peripheral Clock Enable Register2                          */
  __I  uint32_t  RESERVED2[2];
  __IO uint32_t  CSCR;                         /*!< (@ 0x00000040) Clock Source Control Register                              */
  __IO uint32_t  SCCR;                         /*!< (@ 0x00000044) System clock control register                              */
  __IO uint32_t  CMR;                          /*!< (@ 0x00000048) Clock Monitoring Register                                  */
  __I  uint32_t  RESERVED3;
  __IO uint32_t  COR;                          /*!< (@ 0x00000050) Clock Output Setting Register                              */
  __IO uint32_t  NMICR;                        /*!< (@ 0x00000054) NMI Control Register                                       */
  __IO uint32_t  NMISR;                        /*!< (@ 0x00000058) NMI Status Register                                        */
  __I  uint32_t  RESERVED4;
  __IO uint32_t  PLLCON;                       /*!< (@ 0x00000060) PLL Control Register                                       */
  __IO uint32_t  VDCCON;                       /*!< (@ 0x00000064) VDC Control Register                                       */
  __IO uint32_t  LVICR;                        /*!< (@ 0x00000068) Low Voltage Indicator Control Register                     */
  __IO uint32_t  LVISR;                        /*!< (@ 0x0000006C) Low Voltage Indicator Status Register                      */
  __IO uint32_t  LVRCR;                        /*!< (@ 0x00000070) Low Voltage Reset Control Register                         */
  __I  uint32_t  RESERVED5[3];
  __IO uint32_t  EOSCR;                        /*!< (@ 0x00000080) External Oscillator Control Register                       */
  __I  uint32_t  RESERVED6[3];
  __IO uint32_t  MCCR1;                        /*!< (@ 0x00000090) MISC Clock Control Register1                               */
  __IO uint32_t  MCCR2;                        /*!< (@ 0x00000094) MISC Clock Control Register2                               */
  __IO uint32_t  MCCR3;                        /*!< (@ 0x00000098) MISC Clock Control Register3                               */
  __IO uint32_t  MCCR4;                        /*!< (@ 0x0000009C) MISC Clock Control Register4                               */
  __IO uint32_t  MCCR5;                        /*!< (@ 0x000000A0) MISC Clock Control Register5                               */
  __IO uint32_t  MCCR6;                        /*!< (@ 0x000000A4) MISC Clock Control Register6                               */
  __IO uint32_t  MCCR7;                        /*!< (@ 0x000000A8) MISC Clock Control Register7                               */
  __I  uint32_t  RESERVED7[17];
  __IO uint32_t  SYSTEN;                       /*!< (@ 0x000000F0) System Access Key Register                                 */
} SCU_Type;                                     /*!< Size = 244 (0xf4)                                                         */



typedef struct	// SCU
{
	UINT32 RESERVED_0;
	// SCU 寄存器结构体
	union
	{
		UINT32 SMR;                 // 系统模式寄存�?(偏移: 0x0004)
		struct SMR_Register
		{
			// SMR
			UINT8 Reserved_0            : 4;
			UINT8 PREVMODE				: 2;
			UINT8 Reserved_1            : 2;
			UINT8 VDCAON	            : 1;	// 8	VDC enablement in deep-sleep mode
			UINT8 LSIAON				: 1;	// 9	LSI enablement in deep-sleep mode
			UINT8 HSIAON				: 1;	// 10	HSI enablement in deep-sleep mode
			UINT8 PLLAON				: 1;	// 11	PLL enablement in deep-sleep mode
			UINT8 HSEAON				: 1;	// 12	HSE enablement in deep-sleep mode
			UINT8 LSEAON				: 1;	// 13	LSE enablement in deep-sleep mode
		} SMR_register;
	};

    union
    {
        UINT32 SRCR;                // 系统复位控制寄存�?(偏移: 0x0008)
		struct SRCR_Register
        {
            // SRCR
            UINT8 SWRST					: 1;	// 0	Internal soft reset activation bit (check RSER[5] for reset)
            UINT8 Reserved_0			: 3;	// 1-3
            UINT8 STBYO					: 1;	// 4	Inversion selection for the STBYO pin’s output
        } SRCR_register;
    };

	UINT32 RESERVED_1;

    union
    {
        UINT32 WUER;                // 唤醒源使能寄存器 (偏移: 0x0010)
		struct WUER_Register
        {
            // WUER
            UINT8 LVIWUE				: 1;	// 0	低电压指示唤醒使�?(�?0)
            UINT8 WDTWUE				: 1;	// 1	看门狗定时器唤醒使能 (�?1)
            UINT8 FRT0WUE            	: 1;	// 2	自由运行定时器唤醒使�?(�?2)
            UINT8 FRT1WUE				: 1;	// 3	GPIO唤醒使能 (�?3)
            UINT8 Reserved_0            : 4;	//
			UINT8 GPIOAWUE				: 1; 	// 8	Whether or not to use the GPIOA port event as a wake-up source
			UINT8 GPIOBWUE				: 1; 	// 9	Whether or not to use the GPIOB port event as a wake-up source
			UINT8 GPIOCWUE				: 1; 	// 10	Whether or not to use the GPIOC port event as a wake-up source
			UINT8 GPIODWUE				: 1; 	// 11	Whether or not to use the GPIOD port event as a wake-up source
			UINT8 GPIOEWUE				: 1; 	// 12	Whether or not to use the GPIOE port event as a wake-up source
			UINT8 GPIOFWUE				: 1; 	// 13	Whether or not to use the GPIOF port event as a wake-up source
			UINT8 GPIOGWUE				: 1; 	// 14	Whether or not to use the GPIOG port event as a wake-up source
        } WUER_register;
    };

    union
    {
        UINT32 WUSR;                // 唤醒源状态寄存器 (偏移: 0x0014)
		struct WUSR_Register
        {
             // WUSR
            UINT8 LVIWU					: 1;	// 0	低电压指示唤�?
            UINT8 WDTWU					: 1;	// 1	看门狗定时器唤醒
            UINT8 FRT0WU            	: 1;	// 2	自由运行定时器唤�?
            UINT8 FRT1WU				: 1;	// 3	GPIO唤醒
            UINT8 Reserved_0            : 4;	//
			UINT8 GPIOAWU				: 1; 	// 8	Whether or not the GPIOA port event has been triggered for wakeup
			UINT8 GPIOBWU				: 1; 	// 9	Whether or not the GPIOB port event has been triggered for wakeup
			UINT8 GPIOCWU				: 1; 	// 10	Whether or not the GPIOC port event has been triggered for wakeup
			UINT8 GPIODWU				: 1; 	// 11	Whether or not the GPIOD port event has been triggered for wakeup
			UINT8 GPIOEWU				: 1; 	// 12	Whether or not the GPIOE port event has been triggered for wakeup
			UINT8 GPIOFWU				: 1; 	// 13	Whether or not the GPIOF port event has been triggered for wakeup
			UINT8 GPIOGWU				: 1; 	// 14	Whether or not the GPIOG port event has been triggered for wakeup
        } WUSR_register;
    };

    union
    {
        UINT32 RSER;                // 复位源使能寄存器 (偏移: 0x0018)
		struct RSER_Register
        {
            // RSER
            UINT8 LVDRST           		: 1;	// 0	Whether to enable or disable the LVR reset signal
            UINT8 HSEFRST           	: 1;	// 1	Whether to enable or disable the HSE error reset signal
            UINT8 LSEFRST           	: 1;	// 2	Whether to enable or disable the LSE error reset signal
            UINT8 MCKFRST        		: 1;	// 3	Whether to enable or disable the MCLK error reset signal
            UINT8 WDTRST             	: 1;	// 4	Whether to enable or disable the WDT reset signal
            UINT8 SWRST         		: 1;	// 5	Whether to enable or disable the software reset signal
            UINT8 CPURST         		: 1;	// 6	Whether to enable or disable the CPU request reset signal
            UINT8 PINRST         		: 1;	// 7	Whether to enable or disable the external-pin reset signal
            UINT8 LOCKUPRST            	: 2;	// 8-9	Whether to enable or disable the CPU lock-up reset signal
        } RSER_register;
    };

    union
    {
        UINT32 RSSR;                // 复位源状态寄存器 (偏移: 0x001C)
		struct RSSR_Register
        {
            // RSSR
            UINT8 LVDRST           		: 1;	// 0	Whether or not the LVD reset has occurred
            UINT8 HSEFRST           	: 1;	// 1	Whether or not the HSE error reset has occurred
            UINT8 LSEFRST           	: 1;	// 2	Whether or not the LSE error reset has occurred
            UINT8 MCKFRST        		: 1;	// 3	Whether or not the MCLK error reset has occurred
            UINT8 WDTRST             	: 1;	// 4	Whether or not the WDT reset has occurred
            UINT8 SWRST         		: 1;	// 5	Whether or not the software reset has occurred
            UINT8 CPURST         		: 1;	// 6	Whether or not the CPU core reset has occurred
            UINT8 PINRST         		: 1;	// 7	Whether or not the external pin reset has occurred
            UINT8 PORST         		: 1;	// 8	Whether or not the POR reset has occurred
            UINT8 LOCKUPRST            	: 1;	// 9	Whether or not the CPU lock-up reset has occurred
        }RSSR_register;
    };

	union
	{
	    UINT32 PRER1; // 外设复位使能寄存�?（地址�?x4000_0020�?
		struct PRER1_Register
		{
	        UINT8 SCU      			: 1;	// 0		SCU复位掩码
	        UINT8 CFMC     			: 1;	// 1		CFMC复位掩码
	        UINT8 WDT      			: 1;	// 2		WDT复位掩码
	        UINT8 DMFC     			: 1;	// 3		DMFC复位掩码
	        UINT8 DMA      			: 1;	// 4		DMA复位掩码
	        UINT8 Reserved_0 		: 1;	// 5		保留
	        UINT8 FRT0     			: 1;	// 6		FRT0复位掩码
	        UINT8 FRT1     			: 1;	// 7		FRT1复位掩码
	        UINT8 GPIOA    			: 1;	// 8		GPIOA复位掩码
	        UINT8 GPIOB    			: 1;	// 9		GPIOB复位掩码
	        UINT8 GPIOC    			: 1;	// 10		GPIOC复位掩码
	        UINT8 GPIOD    			: 1;	// 11		GPIOD复位掩码
	        UINT8 GPIOE    			: 1;	// 12		GPIOE复位掩码
	        UINT8 GPIOF    			: 1;	// 13		GPIOF复位掩码
	        UINT8 GPIOG    			: 1;	// 14		GPIOG复位掩码
	        UINT8 Reserved_1 		: 1;	// 15		保留
	        UINT8 TIMER0   			: 1;	// 16		TIMER0复位掩码
	        UINT8 TIMER1   			: 1;	// 17		TIMER1复位掩码
	        UINT8 TIMER2   			: 1;	// 18		TIMER2复位掩码
	        UINT8 TIMER3  			: 1;	// 19		TIMER3复位掩码
	        UINT8 TIMER4   			: 1;	// 20		TIMER4复位掩码
	        UINT8 TIMER5   			: 1;	// 21		TIMER5复位掩码
	        UINT8 TIMER6   			: 1;	// 22		TIMER6复位掩码
	        UINT8 TIMER7   			: 1;	// 23		TIMER7复位掩码
	        UINT8 TIMER8   			: 1;	// 24		TIMER8复位掩码
	        UINT8 TIMER9   			: 1;	// 25		TIMER9复位掩码
	        UINT8 Reserved_2 		: 2;	// 26-27	保留
	        UINT8 QE10     			: 1;	// 28		QE10复位掩码
	        UINT8 QE11     			: 1;	// 29		QE11复位掩码
	        UINT8 Reserved_3 		: 2;	// 30-31	保留
	    } PRER1_register;
	} ;

	union
	{
		UINT32 PRER2; // 外设复位使能寄存�?（地址�?x4000_0024�?
		struct PRER2_Register
		{
			UINT8 SPI0					: 1;		// 0		SPI0复位掩码
			UINT8 SPI1					: 1;		// 1		SPI1复位掩码
			UINT8 SPI2					: 1;		// 2		SPI2复位掩码
			UINT8 Reserved_0			: 1;		// 3		保留
			UINT8 I2C0					: 1;		// 4		I2C0复位掩码
			UINT8 I2C1					: 1;		// 5		I2C1复位掩码
			UINT8 Reserved_1			: 2;		// 6-7		保留
			UINT8 UART0					: 1;		// 8		UART0复位掩码
			UINT8 UART1					: 1;		// 9		UART1复位掩码
			UINT8 UART2					: 1;		// 10		UART2复位掩码
			UINT8 UART3					: 1;		// 11		UART3复位掩码
			UINT8 UART4					: 1;		// 12		UART4复位掩码
			UINT8 UART5					: 1;		// 13		UART5复位掩码
			UINT8 Reserved_2			: 2;		// 14-15	保留
			UINT8 MPWM0					: 1;		// 16		MPWM0复位掩码
			UINT8 MPWM1					: 1;		// 17		MPWM1复位掩码
			UINT8 Reserved_3			: 2;		// 18-19	保留
			UINT8 ADC0					: 1;		// 20		ADC0复位掩码
			UINT8 ADC1					: 1;		// 21		ADC1复位掩码
			UINT8 ADC2					: 1;		// 22		ADC2复位掩码
			UINT8 Reserved_4			: 1;		// 23		保留
			UINT8 PGA					: 1;		// 24		PGA复位掩码
			UINT8 Reserved_5			: 3;		// 25-27	保留
			UINT8 COMPARATOR			: 1;		// 28		比较器复位掩�?
			UINT8 CRC					: 1;		// 29		CRC复位掩码
			UINT8 AES					: 1;		// 30		AES复位掩码
			UINT8 RNG					: 1;		// 31		RNG复位掩码
		} PRER2_register;
	};

	union
	{
		UINT32 PER1; // 外设使能寄存�?（地址�?x4000_0028�?
		struct PER1_Register
		{
			UINT8 Reserved_0			: 4; // 0-3		保留
			UINT8 DMA		 			: 1; // 4		DMA使能
			UINT8 Reserved_1			: 1; // 5		保留
			UINT8 FRT0 					: 1; // 6		FRT0使能
			UINT8 FRT1 					: 1; // 7		FRT1使能
			UINT8 GPIOA					: 1; // 8		GPIOA使能
			UINT8 GPIOB					: 1; // 9		GPIOB使能
			UINT8 GPIOC					: 1; // 10		GPIOC使能
			UINT8 GPIOD					: 1; // 11		GPIOD使能
			UINT8 GPIOE					: 1; // 12		GPIOE使能
			UINT8 GPIOF					: 1; // 13		GPIOF使能
			UINT8 GPIOG					: 1; // 14		GPIOG使能
			UINT8 Reserved_2			: 1; // 15		保留
			UINT8 TIMER0				: 1; // 16		TIMER0使能
			UINT8 TIMER1				: 1; // 17		TIMER1使能
			UINT8 TIMER2				: 1; // 18		TIMER2使能
			UINT8 TIMER3				: 1; // 19		TIMER3使能
			UINT8 TIMER4				: 1; // 20		TIMER4使能
			UINT8 TIMER5				: 1; // 21		TIMER5使能
			UINT8 TIMER6				: 1; // 22		TIMER6使能
			UINT8 TIMER7				: 1; // 23		TIMER7使能
			UINT8 TIMER8				: 1; // 24		TIMER8使能
			UINT8 TIMER9				: 1; // 25		TIMER9使能
			UINT8 Reserved_3			: 2; // 26-27	保留
			UINT8 QE10 					: 1; // 28		QE10使能
			UINT8 QE11 					: 1; // 29		QE11使能
			UINT8 Reserved_4			: 2; // 30-31	保留
		} PER1_register;
	} ;

	union
	{
		UINT32 PER2; // 外设使能寄存�?（地址�?x4000_002C�?
		struct PER2_Register
		{
			UINT8 SPI0 					: 1; // 0		SPI0使能
			UINT8 SPI1 					: 1; // 1		SPI1使能
			UINT8 SPI2 					: 1; // 2		SPI2使能
			UINT8 Reserved_0			: 1; // 3		保留
			UINT8 I2C0 					: 1; // 4		I2C0使能
			UINT8 I2C1 					: 1; // 5		I2C1使能
			UINT8 Reserved_1			: 2; // 6-7		保留
			UINT8 UART0					: 1; // 8		UART0使能
			UINT8 UART1					: 1; // 9		UART1使能
			UINT8 UART2					: 1; // 10		UART2使能
			UINT8 UART3					: 1; // 11		UART3使能
			UINT8 UART4					: 1; // 12		UART4使能
			UINT8 UART5					: 1; // 13		UART5使能
			UINT8 Reserved_2			: 2; // 14-15		保留
			UINT8 MPWM0					: 1; // 16		MPWM0使能
			UINT8 MPWM1					: 1; // 17		MPWM1使能
			UINT8 Reserved_3			: 2; // 18-19		保留
			UINT8 ADC0 					: 1; // 20		ADC0使能
			UINT8 ADC1 					: 1; // 21		ADC1使能
			UINT8 ADC2 					: 1; // 22		ADC2使能
			UINT8 Reserved_4			: 1; // 23		保留
			UINT8 PGA					: 1; // 24		PGA使能
			UINT8 Reserved_5			: 3; // 25-27		保留
			UINT8 COMPARATOR			: 1; // 28		比较器使�?
			UINT8 CRC					: 1; // 29		CRC使能
			UINT8 AES					: 1; // 30		AES使能
			UINT8 RNG					: 1; // 31		RNG使能
		} PER2_register;
	} ;

	union
	{
		UINT32 PCER1; // 外设时钟使能寄存�?（地址�?x4000_0030�?
		struct PCER1_Register
		{
			UINT8 Reserved_0			: 4; // 0-3		保留
			UINT8 DMA		 			: 1; // 4		DMA时钟使能
			UINT8 Reserved_1			: 1; // 5		保留
			UINT8 FRT0 					: 1; // 6		FRT0时钟使能
			UINT8 FRT1 					: 1; // 7		FRT1时钟使能
			UINT8 GPIOA					: 1; // 8		GPIOA时钟使能
			UINT8 GPIOB					: 1; // 9		GPIOB时钟使能
			UINT8 GPIOC					: 1; // 10		GPIOC时钟使能
			UINT8 GPIOD					: 1; // 11		GPIOD时钟使能
			UINT8 GPIOE					: 1; // 12		GPIOE时钟使能
			UINT8 GPIOF					: 1; // 13		GPIOF时钟使能
			UINT8 GPIOG					: 1; // 14		GPIOG时钟使能
			UINT8 Reserved_2			: 1; // 15		保留
			UINT8 TIMER0				: 1; // 16		TIMER0时钟使能
			UINT8 TIMER1				: 1; // 17		TIMER1时钟使能
			UINT8 TIMER2				: 1; // 18		TIMER2时钟使能
			UINT8 TIMER3				: 1; // 19		TIMER3时钟使能
			UINT8 TIMER4				: 1; // 20		TIMER4时钟使能
			UINT8 TIMER5				: 1; // 21		TIMER5时钟使能
			UINT8 TIMER6				: 1; // 22		TIMER6时钟使能
			UINT8 TIMER7				: 1; // 23		TIMER7时钟使能
			UINT8 TIMER8				: 1; // 24		TIMER8时钟使能
			UINT8 TIMER9				: 1; // 25		TIMER9时钟使能
			UINT8 Reserved_3			: 2; // 26-27	保留
			UINT8 QE10 					: 1; // 28		QE10时钟使能
			UINT8 QE11 					: 1; // 29		QE11时钟使能
			UINT8 Reserved_4			: 2; // 30-31	保留
		} PCER1_register;
	} ;


    union
	{
    	UINT32 PCER2; // 外设时钟使能寄存�?（地址�?x4000_0034�?
		struct PCER2_Register
		{
        	UINT8 SPI0     				: 1; // 0		SPI0时钟使能
	        UINT8 SPI1     				: 1; // 1		SPI1时钟使能
	        UINT8 SPI2     				: 1; // 2		SPI2时钟使能
	        UINT8 Reserved_0			: 1; // 3		保留
	        UINT8 I2C0     				: 1; // 4		I2C0时钟使能
	        UINT8 I2C1     				: 1; // 5		I2C1时钟使能
	        UINT8 Reserved_1			: 2; // 6-7		保留
	        UINT8 UART0   		 		: 1; // 8		UART0时钟使能
	        UINT8 UART1   	 			: 1; // 9		UART1时钟使能
	        UINT8 UART2    				: 1; // 10		UART2时钟使能
	        UINT8 UART3    				: 1; // 11		UART3时钟使能
	        UINT8 UART4    				: 1; // 12		UART4时钟使能
	        UINT8 UART5    				: 1; // 13		UART5时钟使能
	        UINT8 Reserved_2			: 2; // 14-15	保留
	        UINT8 MPWM0    				: 1; // 16		MPWM0时钟使能
	        UINT8 MPWM1    				: 1; // 17		MPWM1时钟使能
	        UINT8 Reserved_3			: 2; // 18-19	保留
	        UINT8 ADC0     				: 1; // 20		ADC0时钟使能
	        UINT8 ADC1     				: 1; // 21		ADC1时钟使能
	        UINT8 ADC2     				: 1; // 22		ADC2时钟使能
	        UINT8 Reserved_4			: 1; // 23		保留
	        UINT8 PGA      				: 1; // 24		PGA时钟使能
	        UINT8 Reserved_5			: 3; // 25-27	保留
	        UINT8 COMPARATOR			: 1; // 28		比较器时钟使�?
	        UINT8 CRC      				: 1; // 29		CRC时钟使能
	        UINT8 AES      				: 1; // 30		AES时钟使能
	        UINT8 RNG      				: 1; // 21		RNG时钟使能
	    } PCER2_register;
	} ;

	UINT32 RESERVED_2[2];

	union
	{
		UINT32 CSCR;                // 时钟源控制寄存器 (偏移: 0x0040)
		struct CSCR_Register
		{
			// CSCR
			UINT8 Reserved_0			: 1; 	// 0		保留
			UINT8 HSECON                : 1;  	// 1		外部高速时钟使�?(�?0)
			UINT8 Reserved_1			: 1; 	// 2		保留
			UINT8 HSICON                : 1; 	// 3		外部低速时钟使�?(�?1)
			UINT8 Reserved_2			: 1;	// 4		保留
			UINT8 LSICON                : 1;  	// 5		内部高速时钟使�?(�?2)
			UINT8 Reserved_3			: 1; 	// 6		保留
			UINT8 LSECON                : 1; 	// 7		内部低速时钟使�?(�?3)
		} CSCR_register;
	};

	union
	{
    	UINT32 SCCR;                // 				(偏移: 0x0044)
		struct SCCR_Register
		{
			UINT8 MCLKSEL		: 3; 	// 0-2
			UINT8 Reserved_0	: 5;  	// 3-7
			UINT8 PLLPREDIV		: 2; 	// 8-9
			UINT8 Reserved_1	: 2; 	// 10-11
			UINT8 PLLCLKSEL		: 1;	// 12
			UINT8 Reserved_2	: 3;  	// 13-15
			UINT8 PCLKDIV		: 3; 	// 16-18
			UINT8 Reserved_3	: 5; 	// 7
			UINT8 HCLKDIV		: 4; 	// 16-18
			UINT8 Reserved_4	: 4; 	// 7
		} SCCR_register;
	};

	union
	{
		UINT32 CMR; // 时钟监控寄存器（地址�?x4000_0048�?
		struct CMR_Register
		{
			UINT8 HSESTS 			: 1;	 	// 0		外部HSE	状态标�?
			UINT8 HSEFAIL 			: 1;  		// 1		外部HSE	错误中断标志
			UINT8 HSEIE 			: 1;	 	// 2		外部HSE	错误中断使能
			UINT8 HSEMNT 			: 1;		// 3		外部LSE	监控使能
			UINT8 MCLKSTS 			: 1;  		// 4		 MCLK	状态标�?
			UINT8 MCLKFAIL 			: 1; 		// 5		 MCLK	错误中断标志
			UINT8 MCLKIE 			: 1;	 	// 6		 MCLK	错误中断使能
			UINT8 MCLKMNT 			: 1;	 	// 7		 MCLK	错误监控使能
			UINT8 LSESTS 			: 1;	 	// 8		外部LSE	状态标�?
			UINT8 LSEFAIL 			: 1;  		// 9		外部LSE	错误中断标志
			UINT8 LSEIE 			: 1;	 	// 10		外部LSE	错误中断使能
			UINT8 LSEMNT 			: 1;	 	// 11		外部LSE	监控使能
		} CMR_register;
	};

	UINT32 RESERVED_3;

	union
	{
		UINT32 COR; // 时钟输出寄存器（地址�?x4000_0050�?
		struct COR_Register
		{
			UINT8 CLKODIV 			: 4;  	// 0-3		时钟输出分频�?
			UINT8 CLKOEN 			: 1;	// 4		时钟输出使能
			UINT8 CLKOINSEL 		: 3;  	// 5-7		时钟输出选择
		} COR_register;
	};


	union
	{
		UINT32 NMICR; // NMI控制寄存器（地址�?x4000_0054�?
		struct NMICR_Register
		{
			UINT8 LVIE 				: 1;	 	// 0		LVI错误中断作为NMI
			UINT8 MCLKFAILE 		: 1;		// 1		MCLK错误中断作为NMI
			UINT8 WDTINTEN 			: 1; 		// 2		WDT中断作为NMI
			UINT8 OVPOEN 			: 1;	 	// 3		MPWM0过压保护中断作为NMI
			UINT8 PROTOEN 			: 1;  		// 4		MPWM0保护中断作为NMI
			UINT8 OVP1EN 			: 1;	 	// 5		MPWM1过压保护中断作为NMI
			UINT8 PROT1EN 			: 1; 		// 6		MPWM1保护中断作为NMI
			UINT8 Reserved_0 		: 8;		// 7-14		保留
			UINT8 NMIINEN			: 1;		// 15		NMI使能
			UINT8 NMISRC			: 8;		// 16-23	NMI源选择
		} NMICR_register;
	};

	union
	{
		UINT32 NMISR; // NMI状态寄存器（地址�?x4000_0058�?
		struct NMISR_Register
		{
			UINT8 LVISTS 			: 1;	 	// 0		LVI中断状�?
			UINT8 MCLKFAILSTS 		: 1;		// 1		MCLK错误中断状�?
			UINT8 WDTINTSTS 		: 1;		// 2		WDT中断状�?
			UINT8 OVPOSTS 			: 1;  		// 3		MPWM0过压保护中断状�?
			UINT8 PROTOSTS 			: 1; 		// 4		MPWM0保护中断状�?
			UINT8 OVP1STS 			: 1;  		// 5		MPWM1过压保护中断状�?
			UINT8 PROT1STS 			: 1; 		// 6		MPWM1保护中断状�?
			UINT8 Reserved_0 		: 1; 		// 7		保留
			UINT8 Reserved_1 		: 7; 		// 8-14		保留
			UINT8 NMINTSTS 			: 1;  		// 15		NMI中断状�?
			UINT8 Reserved_2 		: 8; 		// 16-23	保留
			UINT8 WTIDKY			: 8;		// 24-31 	Write identification key
		} NMISR_register;
	};


	UINT32 RESERVED_4;

	union
	{
		UINT32 PLLCON; // PLL控制寄存器（地址�?x4000_0060�?
		struct PLLCON_Register
		{
			UINT8 OUTDIV 			: 4;		// 0-3		输出分频控制
			UINT8 POSTDIV2 		: 4; 		// 4-7		反馈控制2 (N2)
			UINT8 POSTDIV1 		: 8; 		// 8-15		反馈控制1 (N1)
			UINT8 PREDIV 			: 3;		// 16-18	输入分频
			UINT8 Reserved_0 		: 1; 		// 19		保留
			UINT8 PLLMODE 			: 1;		// 20		PLL模式选择
			UINT8 BYPASSB 			: 1;		// 21		PLL输入时钟旁路
			UINT8 PLLEN 			: 1;		// 22		PLL使能
			UINT8 PLLRSTB 			: 1;		// 23		PLL复位
			UINT8 CTRLOTP 			: 4;		// 24-27	PLL控制选项
			UINT8 Reserved_1 		: 3;		// 28-30	保留
			UINT8 PLLLOCK 			: 1;		// 31		PLL锁定状�?
		} PLLCON_register;
	};											//				PLLINCLK * (N1 + 1)
												//	Fout = ------------------------------
												//			(R + 1) × (N2 + 1) × (P + 1)
    union
    {
        UINT32 VDCCON;              // 电压检测控制寄存器 (偏移: 0x0064)
		struct VDCCON_Register
        {
            // VDCCON
            UINT8 VDCWDLY               : 8;  // VDC暖启动延�?(�?0-7)
        } VDCCON_register;
    };

    union
    {
        UINT32 LVICR;               // 低电压指示控制寄存器 (偏移: 0x0068)
		struct LVICR_Register
        {
            // LVICR
            UINT8 LVIVS                 : 4;  	// 0-3	LVI电压选择
            UINT8 LVIAON                : 1;  	// 4		LVI自动关闭使能
            UINT8 LVINTEN               : 1;  	// 5		Whether to enable or disable the PLL interrupt
			UINT8 Reserved_0 			: 1;	// 6		保留
            UINT8 LVIEN                 : 1;  	// 7		Whether to enable or disable the PLL
        } LVICR_register;
    };

    union
    {
        UINT32 LVISR;               // 低电压指示状态寄存器 (偏移: 0x006C)
		struct LVISR_Register
        {
            // LVISR
            UINT8 LVIINTSTS             : 1;  	// 0		LVI中断状�?
			UINT8 Reserved_0 			: 4;	// 1-4		保留
            UINT8 LVIIFLAG              : 1;  	// 5		LVI中断标志
			UINT32 Reserved_1			: 18;	// 6-23		保留
			UINT8 WTIDKY				: 8;	// 24-31	Write Identification Key
        } LVISR_register;
    };

    union
    {
        UINT32 LVRCR;               // 低电压复位控制寄存器 (偏移: 0x0070)
		struct LVRCR_Register
        {
            // LVRCR
            UINT8 LVRVS                 : 4;  	// 0-3			LVR电压选择
            UINT8 LVRAON                : 1;  	// 4			LVR自动关闭使能
			UINT8 Reserved_0 			: 3;	// 5-7			保留
            UINT8 LVREN                 : 8;  	// 8-15			LVR使能
        } LVRCR_register;
    };

	UINT32 RESERVED_5[3];

	union
	{
		UINT32 EOSCR; // 外部振荡器控制寄存器（地址�?x4000_0080�?
		struct EOSCR_Register
		{
			UINT8 HSENFSEL			: 2;  		// 0-1		MOSC噪声滤波器选择
			UINT8 Reserved_0 		: 2; 		// 2-3		保留
			UINT8 HSENFEN 			: 1;   		// 4		MOSC噪声滤波器使�?
			UINT8 Reserved_1 		: 3; 		// 5-7		保留
			UINT8 HSEISEL 			: 2;   		// 8-9		MOSC驱动电流选择
			UINT8 Reserved_2 		: 6; 		// 10-15	保留
			UINT8 LSENFEN 			: 1;   		// 16		LSE噪声滤波器使�?
			UINT8 Reserved_3 		: 7; 		// 17-23	保留
			UINT8 LSEISEL 			: 2;   		// 24-25	LSE驱动电流选择
			UINT8 Reserved_4 		: 6; 		// 26-31	保留
		} EOSCR_register;
	};


	UINT32 RESERVED_6[3];

	union
	{
		UINT32 MCCR1; // 杂项时钟控制寄存�?（地址�?x4000_0090�?
		struct MCCR1_Register
		{
			UINT8 STDIV				: 8;		// 0-7			SYSTICK时钟分频
			UINT8 STCSEL			: 3;		// 8-10			SYSTICK时钟源选择
			UINT8 Reserved_0		: 5;		// 11-15		保留
			UINT8 WDTCDIV			: 8;		// 16-23		WDT时钟分频
			UINT8 WTDCSEL			: 3;		// 24-26		WDT时钟源选择
			UINT8 Reserved_1		: 5;		// 27-31		保留
		} MCCR1_register;
	};


    union
    {
        UINT32 MCCR2;               // 杂项时钟控制寄存�? (偏移: 0x0094)
		struct MCCR2_Register
        {
            // MCCR2
            UINT8 MPWM0CDIV			: 8;	// 0-7			MPWM0时钟分频
            UINT8 MPWM0CSEL			: 3;	// 8-10			MPWM0时钟选择
			UINT8 Reserved_0		: 5;	// 11-15		保留
            UINT8 MPWM1CDIV 		: 8;	// 16-23		MPWM1时钟分频
			UINT8 MPWM1CSEL 		: 3;	// 24-26		MPWM1时钟选择
			UINT8 Reserved_1		: 5;	// 27-31		保留
        } MCCR2_register;
    };

    union
    {
        UINT32 MCCR3;               // 杂项时钟控制寄存�? (偏移: 0x0098)
		struct MCCR3_Register
        {
            // MCCR3
            UINT8 TIMER04CDIV		: 8;	// 0-7			TIMER0-4时钟分频
            UINT8 TIMER04CSEL		: 3;	// 8-10			TIMER0-4时钟选择
			UINT8 Reserved_0		: 5;	// 11-15		保留
            UINT8 TIMER59CDIV		: 8;	// 16-23		TIMER5-9时钟分频
			UINT8 TIMER59CSEL		: 3;	// 24-26		TIMER5-9时钟选择
			UINT8 Reserved_1		: 5;	// 27-31		保留
        } MCCR3_register;
    };

    union
    {
        UINT32 MCCR4;               // 杂项时钟控制寄存�? (偏移: 0x009C)
		struct MCCR4_Register
        {
            // MCCR4
            UINT8 ADCCDIV 			: 8;	// 0-7			ADC时钟分频
            UINT8 ADCCSEL			: 3;	// 8-10			ADC时钟选择
			UINT8 Reserved_0		: 5;	// 11-15		保留
            UINT8 PGADCDIV          : 8;	// 16-23		PGA时钟分频
			UINT8 PGADCSEL			: 3;	// 24-26		PGA时钟选择
			UINT8 Reserved_1		: 5;	// 27-31		保留
        } MCCR4_register;
    };

    union
    {
        UINT32 MCCR5;               // 杂项时钟控制寄存�? (偏移: 0x00A0)
		struct MCCR5_Register
        {
            // MCCR5
            UINT8 PGBDCDIV          : 8;  	// 0-7			PB端口去抖时钟分频
            UINT8 PGBDCSEL			: 3;  	// 8-10			PB端口去抖时钟选择
			UINT8 Reserved_0		: 5;	// 11-15		保留
            UINT8 PGCDCDIV			: 8;  	// 16-23		PG端口去抖时钟分频
			UINT8 PGCDCSEL			: 3;  	// 24-26		PG端口去抖时钟选择
			UINT8 Reserved_1		: 5;	// 27-31		保留
        } MCCR5_register;
    };

    union
    {
        UINT32 MCCR6;               // 杂项时钟控制寄存�? (偏移: 0x00A4)
		struct MCCR6_Register
        {
            // MCCR6
            UINT8 FRT0CDIV			: 8;  	// 0-7			FRT0时钟分频
            UINT8 FRT0CSEL			: 3;  	// 8-10			FRT0时钟选择
			UINT8 Reserved_0		: 5;	// 11-15		保留
            UINT8 FRT1CDIV			: 8;  	// 16-23		FRT1时钟分频
			UINT8 FRT1CSEL			: 3;  	// 24-26		FRT1时钟选择
			UINT8 Reserved_1		: 5;	// 27-31		保留
        } MCCR6_register;
    };

    union
    {
        UINT32 MCCR7;               // 杂项时钟控制寄存�? (偏移: 0x00A8)
		struct MCCR7_Register
        {
            // MCCR7
			UINT8 Reserved_0		: 8;	// 0-7			保留
			UINT8 Reserved_1		: 8;	// 8-15			保留
            UINT8 UARTCDIV			: 8; 	// 16-23		UART时钟分频
            UINT8 UARTCSEL			: 3;  	// 24-26		UART时钟选择
        } MCCR7_register;
    };

	UINT32 RESERVED_7[17];

    union
    {
        UINT32 SYSTEN;              // 系统访问使能寄存�?(偏移: 0x00F0)
		struct SYSTEN_Register
        {
            // SYSTEN
            UINT8 SYSTEN			: 8;	//	Writing 0x57 and then 0x75 to the bit field enables writing new
											//	values to SCU registers. After this, write a different value to this
											//	bit field to protect the SCU registers against being updated with
											//	new values.
											//	However, access to the NMISR and LVISR registers is not defined
											//	by the SYSTEM register. Their bits can be cleared regardless of
											//	SYSTEN enablement.
            UINT8 ENS				: 1;  // 使能
        } SYSTEN_register;
    };

}
WROS_SCU_Typedef;




typedef struct	// PCU
{
    // PCU �Ĵ�������
	union
	{
		UINT32 MR1;                 // Port n MUX1 ѡ��Ĵ���
		struct MR1_Register
		{
			// MR1
			UINT8 P0MUX                : 3;  // P0MUX ���Ÿ���ѡ��
			UINT8 Reserved_0           : 1;
			UINT8 P1MUX                : 3;  // P1MUX ���Ÿ���ѡ��
			UINT8 Reserved_1           : 1;
			UINT8 P2MUX                : 3;  // P2MUX ���Ÿ���ѡ��
			UINT8 Reserved_2           : 1;
			UINT8 P3MUX                : 3;  // P3MUX ���Ÿ���ѡ��
			UINT8 Reserved_3           : 1;
			UINT8 P4MUX                : 3;  // P4MUX ���Ÿ���ѡ��
			UINT8 Reserved_4           : 1;
			UINT8 P5MUX                : 3;  // P5MUX ���Ÿ���ѡ��
			UINT8 Reserved_5           : 1;
			UINT8 P6MUX                : 3;  // P6MUX ���Ÿ���ѡ��
			UINT8 Reserved_6           : 1;
			UINT8 P7MUX                : 3;  // P7MUX ���Ÿ���ѡ��
			UINT8 Reserved_7           : 1;
		}MR1_register;
	};

    union
    {
        UINT32 MR2;                 // Port n MUX2 ѡ��Ĵ���
         struct MR2_Register
        {
            // MR2
            UINT8 P8MUX                : 3;  // P8MUX ���Ÿ���ѡ��
            UINT8 Reserved_0           : 1;
            UINT8 P9MUX                : 3;  // P9MUX ���Ÿ���ѡ��
            UINT8 Reserved_1           : 1;
            UINT8 P10MUX               : 3;  // P10MUX ���Ÿ���ѡ��
            UINT8 Reserved_2           : 1;
            UINT8 P11MUX               : 3;  // P11MUX ���Ÿ���ѡ��
            UINT8 Reserved_3           : 1;
            UINT8 P12MUX               : 3;  // P12MUX ���Ÿ���ѡ��
            UINT8 Reserved_4           : 1;
            UINT8 P13MUX               : 3;  // P13MUX ���Ÿ���ѡ��
            UINT8 Reserved_5           : 1;
            UINT8 P14MUX               : 3;  // P14MUX ���Ÿ���ѡ��
            UINT8 Reserved_6           : 1;
            UINT8 P15MUX               : 3;  // P15MUX ���Ÿ���ѡ��
            UINT8 Reserved_7           : 1;
        }MR2_register;
    };

    union
    {
        UINT32 CR;                  // Port n ���ƼĴ���
         struct CR_Register
        {
            // CR
            UINT8 P0                   : 2;  // P0 ���ſ���
            UINT8 P1                   : 2;  // P1 ���ſ���
            UINT8 P2                   : 2;  // P2 ���ſ���
            UINT8 P3                   : 2;  // P3 ���ſ���
            UINT8 P4                   : 2;  // P4 ���ſ���
            UINT8 P5                   : 2;  // P5 ���ſ���
            UINT8 P6                   : 2;  // P6 ���ſ���
            UINT8 P7                   : 2;  // P7 ���ſ���
            UINT8 P8                   : 2;  // P8 ���ſ���
            UINT8 P9                   : 2;  // P9 ���ſ���
            UINT8 P10                  : 2;  // P10 ���ſ���
            UINT8 P11                  : 2;  // P11 ���ſ���
            UINT8 P12                  : 2;  // P12 ���ſ���
            UINT8 P13                  : 2;  // P13 ���ſ���
            UINT8 P14                  : 2;  // P14 ���ſ���
            UINT8 P15                  : 2;  // P15 ���ſ���
        }CR_register;
    };

    union
    {
        UINT32 PRCR;                // Port n ����/����������ƼĴ���
         struct PRCR_Register
        {
            // PRCR
            UINT8 PUE0                   : 2;  // P0 ����/�����������
            UINT8 PUE1                   : 2;  // P1 ����/�����������
            UINT8 PUE2                   : 2;  // P2 ����/�����������
            UINT8 PUE3                   : 2;  // P3 ����/�����������
            UINT8 PUE4                   : 2;  // P4 ����/�����������
            UINT8 PUE5                   : 2;  // P5 ����/�����������
            UINT8 PUE6                   : 2;  // P6 ����/�����������
            UINT8 PUE7                   : 2;  // P7 ����/�����������
            UINT8 PUE8                   : 2;  // P8 ����/�����������
            UINT8 PUE9                   : 2;  // P9 ����/�����������
            UINT8 PUE10                  : 2;  // P10 ����/�����������
            UINT8 PUE11                  : 2;  // P11 ����/�����������
            UINT8 PUE12                  : 2;  // P12 ����/�����������
            UINT8 PUE13                  : 2;  // P13 ����/�����������
            UINT8 PUE14                  : 2;  // P14 ����/�����������
            UINT8 PUE15                  : 2;  // P15 ����/�����������
        }PRCR_register;
    };

    union
    {
        UINT32 DER;                 // Port n ȥ�����ƼĴ���
         struct DER_Register
        {
            // DER
            UINT8 PDE0                   : 1;  // P0 ȥ��ʹ��
            UINT8 PDE1                   : 1;  // P1 ȥ��ʹ��
            UINT8 PDE2                   : 1;  // P2 ȥ��ʹ��
            UINT8 PDE3                   : 1;  // P3 ȥ��ʹ��
            UINT8 PDE4                   : 1;  // P4 ȥ��ʹ��
            UINT8 PDE5                   : 1;  // P5 ȥ��ʹ��
            UINT8 PDE6                   : 1;  // P6 ȥ��ʹ��
            UINT8 PDE7                   : 1;  // P7 ȥ��ʹ��
            UINT8 PDE8                   : 1;  // P8 ȥ��ʹ��
            UINT8 PDE9                   : 1;  // P9 ȥ��ʹ��
            UINT8 PDE10                  : 1;  // P10 ȥ��ʹ��
            UINT8 PDE11                  : 1;  // P11 ȥ��ʹ��
            UINT8 PDE12                  : 1;  // P12 ȥ��ʹ��
            UINT8 PDE13                  : 1;  // P13 ȥ��ʹ��
            UINT8 PDE14                  : 1;  // P14 ȥ��ʹ��
            UINT8 PDE15                  : 1;  // P15 ȥ��ʹ��
        }DER_register;
    };

    union
    {
        UINT32 STR;                 // Port n ��������ǿ�����üĴ���
         struct STR_Register
        {
            // STR
            UINT8 PST0                   : 1;  // P0 ��������ǿ��
            UINT8 PST1                   : 1;  // P1 ��������ǿ��
            UINT8 PST2                   : 1;  // P2 ��������ǿ��
            UINT8 PST3                   : 1;  // P3 ��������ǿ��
            UINT8 PST4                   : 1;  // P4 ��������ǿ��
            UINT8 PST5                   : 1;  // P5 ��������ǿ��
            UINT8 PST6                   : 1;  // P6 ��������ǿ��
            UINT8 PST7                   : 1;  // P7 ��������ǿ��
            UINT8 PST8                   : 1;  // P8 ��������ǿ��
            UINT8 PST9                   : 1;  // P9 ��������ǿ��
            UINT8 PST10                  : 1;  // P10 ��������ǿ��
            UINT8 PST11                  : 1;  // P11 ��������ǿ��
            UINT8 PST12                  : 1;  // P12 ��������ǿ��
            UINT8 PST13                  : 1;  // P13 ��������ǿ��
            UINT8 PST14                  : 1;  // P14 ��������ǿ��
            UINT8 PST15                  : 1;  // P15 ��������ǿ��
        }STR_register;
    };

    UINT32  RESERVED[2];

    union
    {
        UINT32 IER;                 // Port n �ж�ʹ�ܼĴ���
         struct IER_Register
        {
            // IER
            UINT8 PIE0                 : 2;  // P0 �ж�ʹ��
            UINT8 PIE1                 : 2;  // P1 �ж�ʹ��
            UINT8 PIE2                 : 2;  // P2 �ж�ʹ��
            UINT8 PIE3                 : 2;  // P3 �ж�ʹ��
            UINT8 PIE4                 : 2;  // P4 �ж�ʹ��
            UINT8 PIE5                 : 2;  // P5 �ж�ʹ��
            UINT8 PIE6                 : 2;  // P6 �ж�ʹ��
            UINT8 PIE7                 : 2;  // P7 �ж�ʹ��
            UINT8 PIE8                 : 2;  // P8 �ж�ʹ��
            UINT8 PIE9                 : 2;  // P9 �ж�ʹ��
            UINT8 PIE10                : 2;  // P10 �ж�ʹ��
            UINT8 PIE11                : 2;  // P11 �ж�ʹ��
            UINT8 PIE12                : 2;  // P12 �ж�ʹ��
            UINT8 PIE13                : 2;  // P13 �ж�ʹ��
            UINT8 PIE14                : 2;  // P14 �ж�ʹ��
            UINT8 PIE15                : 2;  // P15 �ж�ʹ��
        }IER_register;
    };

    union
    {
        UINT32 ISR;                 // Port n �ж�״̬�Ĵ���
         struct ISR_Register
        {
            // ISR
            UINT8 PIS0                 : 2;  // P0 �ж�״̬
            UINT8 PIS1                 : 2;  // P1 �ж�״̬
            UINT8 PIS2                 : 2;  // P2 �ж�״̬
            UINT8 PIS3                 : 2;  // P3 �ж�״̬
            UINT8 PIS4                 : 2;  // P4 �ж�״̬
            UINT8 PIS5                 : 2;  // P5 �ж�״̬
            UINT8 PIS6                 : 2;  // P6 �ж�״̬
            UINT8 PIS7                 : 2;  // P7 �ж�״̬
            UINT8 PIS8                 : 2;  // P8 �ж�״̬
            UINT8 PIS9                 : 2;  // P9 �ж�״̬
            UINT8 PIS10                : 2;  // P10 �ж�״̬
            UINT8 PIS11                : 2;  // P11 �ж�״̬
            UINT8 PIS12                : 2;  // P12 �ж�״̬
            UINT8 PIS13                : 2;  // P13 �ж�״̬
            UINT8 PIS14                : 2;  // P14 �ж�״̬
            UINT8 PIS15                : 2;  // P15 �ж�״̬
        }ISR_register;
    };

    union
    {
        UINT32 ICR;                 // Port n �жϿ��ƼĴ���
         struct ICR_Register
        {
            // ICR
            UINT8 PIC0                 : 2;  // P0 �ж�ģʽ
            UINT8 PIC1                 : 2;  // P1 �ж�ģʽ
            UINT8 PIC2                 : 2;  // P2 �ж�ģʽ
            UINT8 PIC3                 : 2;  // P3 �ж�ģʽ
            UINT8 PIC4                 : 2;  // P4 �ж�ģʽ
            UINT8 PIC5                 : 2;  // P5 �ж�ģʽ
            UINT8 PIC6                 : 2;  // P6 �ж�ģʽ
            UINT8 PIC7                 : 2;  // P7 �ж�ģʽ
            UINT8 PIC8                 : 2;  // P8 �ж�ģʽ
            UINT8 PIC9                 : 2;  // P9 �ж�ģʽ
            UINT8 PIC10                : 2;  // P10 �ж�ģʽ
            UINT8 PIC11                : 2;  // P11 �ж�ģʽ
            UINT8 PIC12                : 2;  // P12 �ж�ģʽ
            UINT8 PIC13                : 2;  // P13 �ж�ģʽ
            UINT8 PIC14                : 2;  // P14 �ж�ģʽ
            UINT8 PIC15                : 2;  // P15 �ж�ģʽ
        }ICR_register;
    };

    UINT32  RESERVED1;

    union
    {
        UINT32 ODR;                 // Port n ������ݼĴ���
         struct ODR_Register
        {
            // ODR
            UINT16 POD0                 : 1; // P0-P15 �������
            UINT16 POD1                 : 1; // P0-P15 �������
            UINT16 POD2                 : 1; // P0-P15 �������
            UINT16 POD3                 : 1; // P0-P15 �������
            UINT16 POD4                 : 1; // P0-P15 �������
            UINT16 POD5                 : 1; // P0-P15 �������
            UINT16 POD6                 : 1; // P0-P15 �������
            UINT16 POD7                 : 1; // P0-P15 �������
            UINT16 POD8                 : 1; // P0-P15 �������
            UINT16 POD9                 : 1; // P0-P15 �������
            UINT16 POD10                : 1; // P0-P15 �������
            UINT16 POD11                : 1; // P0-P15 �������
            UINT16 POD12                : 1; // P0-P15 �������
            UINT16 POD13                : 1; // P0-P15 �������
            UINT16 POD14                : 1; // P0-P15 �������
            UINT16 POD15                : 1; // P0-P15 �������
        }ODR_register;
    };

    union
    {
        UINT32 IDR;                 // Port n �������ݼĴ���
         struct IDR_Register
        {
            // IDR
            UINT16 PID0                 : 1; // P0-P15 ��������
            UINT16 PID1                 : 1; // P0-P15 ��������
            UINT16 PID2                 : 1; // P0-P15 ��������
            UINT16 PID3                 : 1; // P0-P15 ��������
            UINT16 PID4                 : 1; // P0-P15 ��������
            UINT16 PID5                 : 1; // P0-P15 ��������
            UINT16 PID6                 : 1; // P0-P15 ��������
            UINT16 PID7                 : 1; // P0-P15 ��������
            UINT16 PID8                 : 1; // P0-P15 ��������
            UINT16 PID9                 : 1; // P0-P15 ��������
            UINT16 PID10                : 1; // P0-P15 ��������
            UINT16 PID11                : 1; // P0-P15 ��������
            UINT16 PID12                : 1; // P0-P15 ��������
            UINT16 PID13                : 1; // P0-P15 ��������
            UINT16 PID14                : 1; // P0-P15 ��������
            UINT16 PID15                : 1; // P0-P15 ��������
        }IDR_register;
    };

    union
    {
        UINT32 BSR;                 // Port n �������üĴ���
         struct BSR_Register
        {
            // BSR
            UINT8 BSD0                 : 1;  // P0 ����
            UINT8 BSD1                 : 1;  // P1 ����
            UINT8 BSD2                 : 1;  // P2 ����
            UINT8 BSD3                 : 1;  // P3 ����
            UINT8 BSD4                 : 1;  // P4 ����
            UINT8 BSD5                 : 1;  // P5 ����
            UINT8 BSD6                 : 1;  // P6 ����
            UINT8 BSD7                 : 1;  // P7 ����
            UINT8 BSD8                 : 1;  // P8 ����
            UINT8 BSD9                 : 1;  // P9 ����
            UINT8 BSD10                : 1;  // P10 ����
            UINT8 BSD11                : 1;  // P11 ����
            UINT8 BSD12                : 1;  // P12 ����
            UINT8 BSD13                : 1;  // P13 ����
            UINT8 BSD14                : 1;  // P14 ����
            UINT8 BSD15                : 1;  // P15 ����
            // BCR
            UINT8 BCD0                 : 1;  // P0 ��λ
            UINT8 BCD1                 : 1;  // P1 ��λ
            UINT8 BCD2                 : 1;  // P2 ��λ
            UINT8 BCD3                 : 1;  // P3 ��λ
            UINT8 BCD4                 : 1;  // P4 ��λ
            UINT8 BCD5                 : 1;  // P5 ��λ
            UINT8 BCD6                 : 1;  // P6 ��λ
            UINT8 BCD7                 : 1;  // P7 ��λ
            UINT8 BCD8                 : 1;  // P8 ��λ
            UINT8 BCD9                 : 1;  // P9 ��λ
            UINT8 BCD10                : 1;  // P10 ��λ
            UINT8 BCD11                : 1;  // P11 ��λ
            UINT8 BCD12                : 1;  // P12 ��λ
            UINT8 BCD13                : 1;  // P13 ��λ
            UINT8 BCD14                : 1;  // P14 ��λ
            UINT8 BCD15                : 1;  // P15 ��λ
        }BSR_register;
    };

    union
    {
        UINT32 BCR;                 // Port n ���Ÿ�λ�Ĵ���
         struct BCR_Register
        {
            // BCR
            UINT8 BCD0                 : 1;  // P0 ��λ
            UINT8 BCD1                 : 1;  // P1 ��λ
            UINT8 BCD2                 : 1;  // P2 ��λ
            UINT8 BCD3                 : 1;  // P3 ��λ
            UINT8 BCD4                 : 1;  // P4 ��λ
            UINT8 BCD5                 : 1;  // P5 ��λ
            UINT8 BCD6                 : 1;  // P6 ��λ
            UINT8 BCD7                 : 1;  // P7 ��λ
            UINT8 BCD8                 : 1;  // P8 ��λ
            UINT8 BCD9                 : 1;  // P9 ��λ
            UINT8 BCD10                : 1;  // P10 ��λ
            UINT8 BCD11                : 1;  // P11 ��λ
            UINT8 BCD12                : 1;  // P12 ��λ
            UINT8 BCD13                : 1;  // P13 ��λ
            UINT8 BCD14                : 1;  // P14 ��λ
            UINT8 BCD15                : 1;  // P15 ��λ
        }BCR_register;
    };

}
WROS_PCU_TypeDef;

typedef struct 	//PORTEN
{
    union
    {
        UINT32 PORTEN;                 // Port ����ʹ�ܼĴ���
        struct
        {
            UINT8 PORTEN               : 8;  // �Ĵ���ʹ��
            UINT8 ENS                  : 1;  // �Ĵ���ʹ��
        } PORTEN_register;
    };
}
WROS_PORTEN_Type;                                  /*!< Size = 4 (0x4)                                                            */

typedef struct 	//CFMC
{
    union
    {
        UINT32 CONF; // Code flash control register
        struct
        {
            UINT32 LATENCY		: 4;		// 0-3: Flash wait value
            UINT32 Reserve_0	: 4;		// 4-7: Reserved
            UINT32 ICEN			: 1;		// 8: Instruction cache enable
            UINT32 DCEN			: 1;		// 9: Data cache enable
            UINT32 Reserve_1	: 6;		// 10-15: Reserved
            UINT32 ICRST		: 1;		// 16: Instruction cache reset
            UINT32 DCRST		: 1;		// 17: Data cache reset
            UINT32 Reserve_2	: 6;		// 18-23: Reserved
            UINT32 BBLOCK		: 1;		// 24: Boot block lock
            UINT32 Reserve_3	: 6;		// 25-31: Reserved
        } CONF_register;
    };

    union
    {
        UINT32 FLSKEY; // Code flash access key register
        struct
        {
            UINT32 FKEY : 32;         // 0-31: Flash access key
        } FLSKEY_register;
    };

    union
    {
        UINT32 OTPKEY; // Code flash OTP access key register
        struct
        {
            UINT32 OKEY : 32;         // 0-31: OTP access key
        } OTPKEY_register;
    };

    union
    {
        UINT32 FLSPROT; // Code flash protection register
        struct
        {
        	UINT32 FPBY32K_0	: 1;    // 0: Flash area protection
        	UINT32 FPBY32K_1	: 1;    // 1: Flash area protection
        	UINT32 FPBY32K_2	: 1;    // 2: Flash area protection
        	UINT32 FPBY32K_3	: 1;    // 3: Flash area protection
        	UINT32 FPBY32K_4	: 1;    // 4: Flash area protection
        	UINT32 FPBY32K_5	: 1;    // 5: Flash area protection
        	UINT32 FPBY32K_6	: 1;    // 6: Flash area protection
        	UINT32 FPBY32K_7	: 1;    // 7: Flash area protection
        	UINT32 FPBY32K_8	: 1;    // 8: Flash area protection
        	UINT32 FPBY32K_9	: 1;    // 9: Flash area protection
        	UINT32 FPBY32K_10	: 1;    // 10: Flash area protection
        	UINT32 FPBY32K_11	: 1;    // 11: Flash area protection
        	UINT32 FPBY32K_12	: 1;    // 12: Flash area protection
        	UINT32 FPBY32K_13	: 1;    // 13: Flash area protection
        	UINT32 FPBY32K_14	: 1;    // 14: Flash area protection
        	UINT32 FPBY32K_15	: 1;    // 15: Flash area protection
            UINT32 Reserve_0	: 6;    // 16-23: Reserved

            UINT32 FUP512B_0	: 1;     // 0: Protection of the first 4 KB of flash memory
            UINT32 FUP512B_1	: 1;     // 1: Protection of the first 4 KB of flash memory
            UINT32 FUP512B_2	: 1;     // 2: Protection of the first 4 KB of flash memory
            UINT32 FUP512B_3	: 1;     // 3: Protection of the first 4 KB of flash memory
            UINT32 FUP512B_4	: 1;     // 4: Protection of the first 4 KB of flash memory
            UINT32 FUP512B_5	: 1;     // 5: Protection of the first 4 KB of flash memory
            UINT32 FUP512B_6	: 1;     // 6: Protection of the first 4 KB of flash memory
            UINT32 FUP512B_7	: 1;     // 7: Protection of the first 4 KB of flash memory

        	}FLSPROT_register;

	};

    union
    {
        UINT32 CTRL; // Code flash access control register
        struct
        {
            UINT32 PGM			: 1;			// 0: Flash write
            UINT32 PERS			: 1;			// 1: Page erase mode
            UINT32 S1KERS		: 1;			// 2: 1 KB-sector erase mode
            UINT32 S4KERS		: 1;			// 3: 4 KB-sector erase mode
            UINT32 CERS			: 1;			// 4: Chip erase mode
            UINT32 Reserve_0	: 3;			// 5-7: Reserved
            UINT32 WDIEN		: 1;			// 8: Write done interrupt enable
            UINT32 Reserve_1	: 22;			// 9-30: Reserved
			UINT32 FLOCK		: 1;			// 31: Flash lock
        } CTRL_register;
    };

    union
    {
        UINT32 STAT; // Code flash access status register
        struct
        {
             UINT32 WBUSY 		: 1;		// 0: Write busy check
             UINT32 CBUSY 		: 1;		// 1: Checksum busy check
             UINT32 Reserve_0	: 6;		// 2-7: Flash write
             UINT32 WDONE 		: 1;		// 8: Write done interrupt status
             UINT32 CDONE 		: 1;		// 9: Checksum done check
             UINT32 Reserve_1	: 6;		// 10-15: Flash write
             UINT32 FLERR 		: 1;		// 16: Flash lock error
             UINT32 OLERR 		: 1;		// 17: OTP lock error
             UINT32 FPERR 		: 1;		// 18: Flash protect error
             UINT32 OPERR 		: 1;		// 19: OTP protect error
             UINT32 WSERR 		: 1;		// 20: Write sequence error
             UINT32 RPERR 		: 1;		// 21: Read-protect error
            UINT32 Reserve_2	: 10;		// 22-31: Flash write
        } STAT_register;
    };

    // 其他寄存器定�?..
}
WROS_CFMC_Type;

typedef struct {                                /*!< (@ 0x41000000) CFMC Structure                                             */
  __IO uint32_t  CONF;                         /*!< (@ 0x00000000) Flash Memory Control Register                              */
  __IO uint32_t  FLSKEY;                       /*!< (@ 0x00000004) Flash Memory Access Key Register                           */
  __IO uint32_t  OTPKEY;                       /*!< (@ 0x00000008) Flash OTP Access Key Register                              */
  __IO uint32_t  FLSPROT;                      /*!< (@ 0x0000000C) Flash Memory Protection Register                           */
  __IO uint32_t  OTPPROT;                      /*!< (@ 0x00000010) Flash OTP Protection Register                              */
  __IO uint32_t  CTRL;                         /*!< (@ 0x00000014) Flash Access Control Register                              */
  __IO uint32_t  STAT;                         /*!< (@ 0x00000018) Flash Access Status Register                               */
  __IO uint32_t  READPROT;                     /*!< (@ 0x0000001C) Flash Read Protection Register                             */
  __O  uint32_t  PWIN;                         /*!< (@ 0x00000020) Flash Read Protection Password Input Register              */
  __I  uint32_t  RESERVED[3];
  __IO uint32_t  CHKCTRL;                      /*!< (@ 0x00000030) Flash Checksum Control Register                            */
  __IO uint32_t  CHKDOUT;                      /*!< (@ 0x00000034) Flash Checksum Data Output Register                        */
  __IO uint32_t  CHKSADDR;                     /*!< (@ 0x00000038) Flash Checksum Start Address Resgister                     */
  __IO uint32_t  CHKEADDR;                     /*!< (@ 0x0000003C) Flash Checksum End Address Register                        */
  __I  uint32_t  RESERVED1[950];
  __O  uint32_t  PWPRST;                       /*!< (@ 0x00000F18) Flash Read Protection Password Preset Register             */
} CFMC_Type;                                    /*!< Size = 3868 (0xf1c)                                                       */



/* =========================================================================================================================== */
/* ================                                           DFMC                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief DATA FLASH MEMORY CONTROLLER (DFMC)
  */

typedef struct {                                /*!< (@ 0x41001000) DFMC Structure                                             */
  __IO uint32_t  CONF;                         /*!< (@ 0x00000000) Flash Memory Control Register                              */
  __IO uint32_t  FLSKEY;                       /*!< (@ 0x00000004) Flash Memory Access Key Register                           */
  __I  uint32_t  RESERVED;
  __IO uint32_t  FLSPROT;                      /*!< (@ 0x0000000C) Flash Memory Protection Register                           */
  __I  uint32_t  RESERVED1;
  __IO uint32_t  CTRL;                         /*!< (@ 0x00000014) Flash Access Control Register                              */
  __IO uint32_t  STAT;                         /*!< (@ 0x00000018) Flash Access Status Register                               */
  __I  uint32_t  RESERVED2[5];
  __IO uint32_t  CHKCTRL;                      /*!< (@ 0x00000030) Flash Checksum Control Register                            */
  __IO uint32_t  CHKDOUT;                      /*!< (@ 0x00000034) Flash Checksum Data Output Register                        */
  __IO uint32_t  CHKSADDR;                     /*!< (@ 0x00000038) Flash Checksum Start Address Resgister                     */
  __IO uint32_t  CHKEADDR;                     /*!< (@ 0x0000003C) Flash Checksum End Address Register                        */
} DFMC_Type;                                    /*!< Size = 64 (0x40)                                                          */



/* =========================================================================================================================== */
/* ================                                           DMA0                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Direct Memory Access Control (DMA0)
  */

typedef struct {                                /*!< (@ 0x40000400) DMA0 Structure                                             */
  __IO uint32_t  CR;                           /*!< (@ 0x00000000) DMA Control Register                                       */
  __IO uint32_t  SR;                           /*!< (@ 0x00000004) DMA Status Register                                        */
  __IO uint32_t  PAR;                          /*!< (@ 0x00000008) DMA Peripheral address register                            */
  __IO uint32_t  MAR;                          /*!< (@ 0x0000000C) DMA Memory address register                                */
} DMA_Type;                                     /*!< Size = 16 (0x10)                                                          */



/* =========================================================================================================================== */
/* ================                                            WDT                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief WATCH-DOG TIMER (WDT)
  */

typedef struct {                                /*!< (@ 0x40000200) WDT Structure                                              */
  __IO uint32_t  LR;                           /*!< (@ 0x00000000) Watch-dog Timer Load Register                              */
  __IO uint32_t  CNT;                          /*!< (@ 0x00000004) Watch-dog Timer Counter Register                           */
  __IO uint32_t  CON;                          /*!< (@ 0x00000008) Watch-dog Timer Control Register                           */
  __I  uint32_t  RESERVED[57];
  __IO uint32_t  AEN;                          /*!< (@ 0x000000F0) Watch-dog Timer Master Lock/Reload Register                */
} WDT_Type;                                     /*!< Size = 244 (0xf4)                                                         */


typedef struct	// TIMER
{
	union
	{
		UINT32 CR1; // Timer n control register 1
		struct CR1_Register
		{
			UINT16 MODE			: 2;	// 0-1: Timer operation mode control
			UINT16 CLRMOD		: 2;	// 2-3: Clear mode selection in capture mode
			UINT16 CKSEL		: 3;	// 4-6: Counter clock source selection
			UINT16 STARTLVL		: 1;	// 7: Starting output value in periodic/PWM/one-shot modes
			UINT16 ADCTRGEN		: 1;	// 8: ADC trigger generation
			UINT16 Reserve_0	: 2;	// 9-10: Reserved
			UINT16 IOSEL		: 1;	// 11: TnIO pin configuration
			UINT16 OUTPOL		: 1;	// 12: Timer output polarity
			UINT16 UAO			: 1;	// 13: GRA/GRB update mode selection
			UINT16 TRGMOD 		: 2;	// 14-15: ADC trigger mode selection
		} CR1_register;
	};

    union
    {
        UINT32 CR2; // Timer n control register 2
        struct CR2_Register
        {
            UINT8 TEN		: 1;		// 0: Timer enable
            UINT8 TCLR		: 1;		// 1: Timer counter clear (write-only)
        } CR2_register;
    };

    union
    {
        UINT32 PRS; // Timer n prescaler register
        struct PRS_Register
        {
            UINT16 PRS		: 10;          // 0-9: Prescaler value for the counter clock
        } PRS_register;
    };

    union
    {
        UINT32 GRA; // Timer n general data register A
        struct GRA_Register
        {
            UINT16 GRA		: 16;          // 0-15: General register A value
        } GRA_register;
    };

    union
    {
        UINT32 GRB; // Timer n general data register B
        struct GRB_Register
        {
            UINT16 GRB		: 16;          // 0-15: General register B value
        } GRB_register;
    };

    union
    {
        UINT32 CNT; // Timer n counter register
        struct CNT_Register
        {
            UINT16 CNT		: 16;          // 0-15: Current counter value
        } CNT_register;
    };

    union
    {
        UINT32 SR; // Timer n status register
        struct SR_Register
        {
            UINT8 OVF		: 1;
            UINT8 MFB		: 1;
            UINT8 MFA		: 1;
       } SR_register;
    };

    union
    {
        UINT32 TIMER_IER; // Timer n interrupt enable register
        struct TIMER_IER_Register
        {
            UINT8 OVE		: 1;
            UINT8 MBIE		: 1;
            UINT8 MAIE		: 1;
	} TIMER_IER_register;
    };

    union
    {
        UINT32 TRGPNT; // Timer n trigger point register
        struct TRGPNT_Register
        {
            UINT16 TRGPNT	: 16;       // 0-15: Trigger point value
        } TRGPNT_register;
    };

    union
    {
		UINT32 SYNC; // Timer n sync configuration register
		struct SYNC_Register
		{
		    UINT16 SYNCDLY	: 16;		// 0-15: Synchronization delay
		    UINT8 CSYNC		: 1;		// 16: Clear synchronization
		    UINT8 SSYNC		: 1;		// 17: Clear synchronization
		    UINT8 Reserve_0	: 1;		// 18: Reserved
		    UINT8 Reserve_1	: 1;		// 19: Reserved
		    UINT8 T0SYNCB	: 1;		// 20: Timer0 synchronization
		    UINT8 T1SYNCB	: 1;		// 21: Timer1 synchronization
		    UINT8 T2SYNCB	: 1;		// 22: Timer2 synchronization
		    UINT8 T3SYNCB	: 1;		// 23 Timer3 synchronization
			UINT8 T4SYNCB	: 1;		// 24: Timer4 synchronization
		    UINT8 T5SYNCB	: 1;		// 25: Timer5 synchronization
		    UINT8 T6SYNCB	: 1;		// 26: Timer6 synchronization
		    UINT8 T7SYNCB	: 1;		// 27: Timer7 synchronization
		    UINT8 T8SYNCB	: 1;		// 28: Timer8 synchronization
		    UINT8 T9SYNCB	: 1;		// 29: Timer9 synchronization
		} SYNC_register;
    };
}
WROS_TIMER_Type;


/* =========================================================================================================================== */
/* ================                                           FRT0                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Free Run Timer (FRT0)
  */

typedef struct {                                /*!< (@ 0x40000600) FRT0 Structure                                             */
  __IO uint32_t  CTRL;                         /*!< (@ 0x00000000) FRT n Control Register                                     */
  __IO uint32_t  MCNT;                         /*!< (@ 0x00000004) FRT n Match Counter Register                               */
  __IO uint32_t  CNT;                          /*!< (@ 0x00000008) FRT n Counter Register                                     */
  __IO uint32_t  STAT;                         /*!< (@ 0x0000000C) FRT n Status Register                                      */
} FRT_Type;                                     /*!< Size = 16 (0x10)                                                          */



/* =========================================================================================================================== */
/* ================                                           UART0                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief Universal Asynchronous Receiver/Transmitter (UART0)
  */

typedef struct {                                /*!< (@ 0x40008000) UART0 Structure                                            */

  union {
    __I  uint32_t RBR;                         /*!< (@ 0x00000000) UARTn Receive Data Buffer Register                         */
    __O  uint32_t THR;                         /*!< (@ 0x00000000) UARTn Transmit Data Hold Register                          */
  };
  __IO uint32_t  IER;                          /*!< (@ 0x00000004) UARTn Interrupt Enable Register                            */
  __I  uint32_t  IIR;                          /*!< (@ 0x00000008) UARTn Interrupt ID Register                                */
  __IO uint32_t  LCR;                          /*!< (@ 0x0000000C) UARTn Line Control Register                                */
  __IO uint32_t  DCR;                          /*!< (@ 0x00000010) UARTn Data Control Register                                */
  __I  uint32_t  LSR;                          /*!< (@ 0x00000014) UARTn Line Status Register                                 */
  __I  uint32_t  RESERVED[2];
  __IO uint32_t  BDR;                          /*!< (@ 0x00000020) UARTn Baud Rate Divisor Latch Register                     */
  __IO uint32_t  BFR;                          /*!< (@ 0x00000024) UARTn Baud Rate Fractional Counter Value                   */
  __I  uint32_t  RESERVED1[2];
  __IO uint32_t  IDTR;                         /*!< (@ 0x00000030) UARTn Inter-frame Delay Time Register                      */
} UART_Type;                                    /*!< Size = 52 (0x34)                                                          */

typedef struct
{
	union
	{
		UINT32 RBR; // UART n receive data buffer register
		UINT32 THR; // UART n transmit data hold register
		struct THR_Register
		{
			UINT8	DATA_Buffer 		: 8; // Transmit & Receive buffer register,Received data
		} THR_register;
	};

	union
	{
		UINT32 UART_IER; // UART n interrupt enable register
		struct UART_IER_Register
		{
			UINT8 DRIE 				: 1; // 0		Enable receiver interrupt
			UINT8 THREIE 			: 1; // 1		Enable transmitter interrupt
			UINT8 RLSIE 			: 1; // 2		Enable line status interrupt
			UINT8 TXEIE 			: 1; // 3		Enable modem status interrupt
			UINT8 DRXIEN 			: 1; // 4		Enable the DMA receive complete interrupt
			UINT8 DTXIEN 			: 1; // 5		Enable the DMA transmit complete interrupt
		} UART_IER_register;
	};

	union
	{
		UINT32 IIR; // UART n interrupt ID register
		struct IIR_Register
		{
			UINT8 IPEN 			: 1; // 0		Interrupt pending
			UINT8 INT_ID 		: 3; // 1-3		Interrupt identification
			UINT8 TXE 			: 1; // 4	Transmit complete
		} IIR_register;
	};

	union
	{
		UINT32 LCR; // UART n line control register
		struct LCR_Register
		{
			UINT8 DLEN 			: 2; // Word length
			UINT8 STOPBIT 		: 1; // Number of stop bits
			UINT8 PEN 			: 1; // Parity enable
			UINT8 PARITY 		: 1; // Parity mode selection
			UINT8 STICKP 		: 1; // Whether or not to use stick parity. The setting of this bit is valid only when the PEN bit is set to 1.
			UINT8 BREAK 		: 1; // Break enable		Divisor latch access bit
		} LCR_register;
	};

	union
	{
		UINT32 DCR; // UART n line control register
		struct DCR_Register
		{
			UINT8 Reserve_0 	: 2; //
			UINT8 TXINV 		: 1; // Tx data inversion selection
			UINT8 RXINV 		: 1; // Rx data inversion selection
		} DCR_register;
	};

	union
	{
		UINT32 LSR; // UART n line status register
		struct LSR_Register
		{
			UINT8 DR 		: 1;		// 0 Data ready
			UINT8 OE 		: 1;		// 1 Overrun error
			UINT8 PE 		: 1;		// 2 Parity error
			UINT8 FE 		: 1;		// 3 Framing error
			UINT8 BI 		: 1;		// 4 Break interrupt
			UINT8 THRE 		: 1;		// 5 Transmit hold register empty
			UINT8 TEMT 		: 1;		// 6 Transmit registers empty
		} LSR_register;
	};

	UINT32	RESERVED_0[2];

	union
	{
		UINT32 BDR; // UART n baud-rate divisor latch register
		struct BDR_Register
		{
			UINT16 BDR 			: 16; 		// 	Baud-rate divisor latch
		} BDR_register;
	};

	union
	{
		UINT32 BFR; // UART n baud-rate fraction register
		struct BFR_Registers
		{
			UINT8 BFR 			: 8; 		// 	Fraction counter
		} BFR_registers;
	};

	UINT32	RESERVED_1[2];

	union
	{
		UINT8 IDTR; // UART n inter-frame delay time register
		struct IDTR_Register
		{
			UINT8 WAITVAL 		: 3; 		// 0-2	Wait time value
			UINT8 Reserve_0 	: 3;		// 3-5	Reserved bits
			UINT8 DMS 			: 1;		// 6	Multi-sampling each data bit
			UINT8 SMS 			: 1;		// 7	Multi-sampling the start bit
		} IDTR_register;
	};


} WROS_UART_Type;


/* =========================================================================================================================== */
/* ================                                           SPI0                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Serial Peripheral Interface Bus (SPI0)
  */

typedef struct {                                /*!< (@ 0x40009000) SPI0 Structure                                             */

  union {
    __O  uint32_t TDR;                         /*!< (@ 0x00000000) SPI n Transmit Data Register                               */
    __I  uint32_t RDR;                         /*!< (@ 0x00000000) SPI n Received Data Register                               */
  };
  __IO uint32_t  CR;                           /*!< (@ 0x00000004) SPI Control Register                                       */
  __IO uint32_t  SR;                           /*!< (@ 0x00000008) SPI n Status Register                                      */
  __IO uint32_t  BR;                           /*!< (@ 0x0000000C) SPI n Baud Rate Register                                   */
  __IO uint32_t  EN;                           /*!< (@ 0x00000010) SPI n Enable Register                                      */
  __IO uint32_t  LR;                           /*!< (@ 0x00000014) SPI n Delay Length Register                                */
} SPI_Type;                                     /*!< Size = 24 (0x18)                                                          */



/* =========================================================================================================================== */
/* ================                                           I2C0                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Inter-Integrated Circuit (I2C0)
  */

typedef struct {                                /*!< (@ 0x4000A000) I2C0 Structure                                             */
  __IO uint32_t  DR;                           /*!< (@ 0x00000000) I2Cn Data Register                                         */
  __I  uint32_t  RESERVED;
  __IO uint32_t  SR;                           /*!< (@ 0x00000008) I2Cn Status Register                                       */
  __IO uint32_t  SAR;                          /*!< (@ 0x0000000C) I2Cn Slave Address Register                                */
  __I  uint32_t  RESERVED1;
  __IO uint32_t  CR;                           /*!< (@ 0x00000014) I2Cn Control Register                                      */
  __IO uint32_t  SCLL;                         /*!< (@ 0x00000018) I2Cn SCL Low Period Register                               */
  __IO uint32_t  SCLH;                         /*!< (@ 0x0000001C) I2Cn SCL High Period Register                              */
  __IO uint32_t  SDH;                          /*!< (@ 0x00000020) I2Cn SCL Hold Time Register                                */
} I2C_Type;                                     /*!< Size = 36 (0x24)                                                          */

typedef struct
{
	union
	{
		UINT32 DR;                 // I2C Data Register (偏移地址: 0x00)
		struct DR_Register
		{
		    UINT8 ICDR                  : 8;  // 数据寄存器
		}DR_register;
	};

	union
	{
	    UINT32 I2C_SR;                 // I2C Status Register (偏移地址: 0x04)
	    struct I2C_SR_Register
		{
	        UINT8 RXACK					: 1;  // Rx ACK标志
	        UINT8 TMOD					: 1;  // 传输/接收模式标志
	        UINT8 BUSY					: 1;  // 总线忙标志
	        UINT8 MLOST					: 1;  // 主设备丢失标志
	        UINT8 SSEL					: 1;  // 从设备选择标志
	        UINT8 STOP					: 1;  // 停止标志
	        UINT8 TEND					: 1;  // 传输结束标志
	        UINT8 GCALL					: 1;  // 通用呼叫标志
	    }I2C_SR_register;
	};

	union
	{
	    UINT32 SAR;                // I2C Slave Address Register (偏移地址: 0x08)
	    struct SAR_Register
		{
	        UINT8 GCEN                  : 1;  // 通用呼叫使能
	        UINT8 SVAD                  : 7;  // 7位从设备地址
	    }SAR_register;
	};

	union
	{
	    UINT32 I2C_CR;                 // I2C Control Register (偏移地址: 0x0C)
	    struct I2C_CR_Register
		{
	        UINT8 START						: 1;	// 开始信号
	        UINT8 STOP						: 1;	// 停止信号
	        UINT8 Reserved_0				: 1;	// 保留位
	        UINT8 ACKEN						: 1;	// ACK使能
	        UINT8 INTEN						: 1;	// 中断使能
	        UINT8 Reserved_1				: 2;	// 保留位
	        UINT8 IIF						: 1;	// 中断标志
	        UINT8 INTDEL					: 2;	// 内部延迟
	    }I2C_CR_register;
	};

	union
	{
	    UINT32 SCLL;               // I2C SCL Low Duration Register (偏移地址: 0x10)
	    struct SCLL_Register
    	{
	        UINT16 SCLL                  : 16; // SCL低电平持续时间
	    }SCLL_register;
	};

	union
	{
	    UINT32 SCLH;               // I2C SCL High Duration Register (偏移地址: 0x14)
	    struct SCLH_Register
		{
	        UINT16 SCLH                  : 16; // SCL高电平持续时间
	    } SCLH_register;
	};

	union
	{
	    UINT32 SDAH;               // I2C SDA Hold Register (偏移地址: 0x18)
	    struct SDAH_Register
		{
	        UINT16 SDH                   : 15; // SDA保持时间
	    } SDAH_register;
	};
} WROS_I2C_Type;


/* =========================================================================================================================== */
/* ================                                            CAN                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Controller Area Network (CAN)
  */

typedef struct {                                /*!< (@ 0x40007000) CAN Structure                                              */
  __IO uint32_t  CR;                           /*!< (@ 0x00000000) CAN Control Register                                       */
  __I  uint32_t  SR;                           /*!< (@ 0x00000004) CAN Status Register                                        */
  __I  uint32_t  ERRCNT;                       /*!< (@ 0x00000008) CAN Error Counter Register                                 */
  __IO uint32_t  BTR;                          /*!< (@ 0x0000000C) CAN Bit Timing Register                                    */
  __IO uint32_t  IER;                          /*!< (@ 0x00000010) CAN Interrupt Enable Register                              */
  __IO uint32_t  TEST;                         /*!< (@ 0x00000014) CAN Test Register                                          */
  __O  uint32_t  BRPEXT;                       /*!< (@ 0x00000018) CAN BRP Extend Register                                    */
  __IO uint32_t  EN;                           /*!< (@ 0x0000001C) CAN Enable Register                                        */
  __IO uint32_t  I1COMR;                       /*!< (@ 0x00000020) CAN Interface 1 Command Request Register                   */
  __IO uint32_t  I1COMM;                       /*!< (@ 0x00000024) CAN Interface1 Command Mask Register                       */
  __IO uint32_t  I1MSK1;                       /*!< (@ 0x00000028) CAN Interface1 Mask1 Register                              */
  __IO uint32_t  I1MSK2;                       /*!< (@ 0x0000002C) CAN Interface1 Mask2 Register                              */
  __IO uint32_t  I1ARB1;                       /*!< (@ 0x00000030) CAN Interface1 Arbitration1 Register                       */
  __IO uint32_t  I1ARB2;                       /*!< (@ 0x00000034) CAN Interface1 Arbitration2 Register                       */
  __IO uint32_t  I1MCR;                        /*!< (@ 0x00000038) CAN Interface1 Message Control Register                    */
  __IO uint32_t  I1DA1;                        /*!< (@ 0x0000003C) CAN Interface1 Data A1 Register                            */
  __IO uint32_t  I1DA2;                        /*!< (@ 0x00000040) CAN Interface1 Data A2 Register                            */
  __IO uint32_t  I1DB1;                        /*!< (@ 0x00000044) CAN Interface1 Data B1 Register                            */
  __IO uint32_t  I1DB2;                        /*!< (@ 0x00000048) CAN Interface1 Data B2 Register                            */
  __I  uint32_t  RESERVED[13];
  __IO uint32_t  I2COMR;                       /*!< (@ 0x00000080) CAN Interface 2 Command Request Register                   */
  __IO uint32_t  I2COMM;                       /*!< (@ 0x00000084) CAN Interface2 Command Mask Register                       */
  __IO uint32_t  I2MSK1;                       /*!< (@ 0x00000088) CAN Interface2 Mask1 Register                              */
  __IO uint32_t  I2MSK2;                       /*!< (@ 0x0000008C) CAN Interface2 Mask2 Register                              */
  __IO uint32_t  I2ARB1;                       /*!< (@ 0x00000090) CAN Interface2 Arbitration1 Register                       */
  __IO uint32_t  I2ARB2;                       /*!< (@ 0x00000094) CAN Interface2 Arbitration2 Register                       */
  __IO uint32_t  I2MCR;                        /*!< (@ 0x00000098) CAN Interface2 Message Control Register                    */
  __IO uint32_t  I2DA1;                        /*!< (@ 0x0000009C) CAN Interface2 Data A1 Register                            */
  __IO uint32_t  I2DA2;                        /*!< (@ 0x000000A0) CAN Interface2 Data A2 Register                            */
  __IO uint32_t  I2DB1;                        /*!< (@ 0x000000A4) CAN Interface2 Data B1 Register                            */
  __IO uint32_t  I2DB2;                        /*!< (@ 0x000000A8) CAN Interface2 Data B2 Register                            */
  __I  uint32_t  RESERVED1[21];
  __I  uint32_t  TXR1;                         /*!< (@ 0x00000100) CAN transmission Request Bit (n=16~1)                      */
  __I  uint32_t  TXR2;                         /*!< (@ 0x00000104) CAN transmission Request Bit (n=32~17)                     */
  __I  uint32_t  RESERVED2[6];
  __I  uint32_t  ND1;                          /*!< (@ 0x00000120) CAN New Data Register (n=16~1)                             */
  __I  uint32_t  ND2;                          /*!< (@ 0x00000124) CAN New Data Register (n=32~17)                            */
  __I  uint32_t  RESERVED3[6];
  __I  uint32_t  ISR1;                         /*!< (@ 0x00000140) CAN Interrupt Status Register (n=16~1)                     */
  __I  uint32_t  ISR2;                         /*!< (@ 0x00000144) CAN Interrupt Status Register (n=32~17)                    */
  __I  uint32_t  RESERVED4[6];
  __I  uint32_t  MVR1;                         /*!< (@ 0x00000160) CAN Message Validation Register (n=16~1)                   */
  __I  uint32_t  MVR2;                         /*!< (@ 0x00000164) CAN Message Validation Register (n=32~17)                  */
} CAN_Type;                                     /*!< Size = 360 (0x168)                                                        */



/* =========================================================================================================================== */
/* ================                                           MPWM0                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief Motor Pulse Width Modulation (MPWM0)
  */

typedef struct {                                /*!< (@ 0x40004000) MPWM0 Structure                                            */
  __IO uint32_t  MR;                           /*!< (@ 0x00000000) MPWM n Mode Register                                       */
  __IO uint32_t  OLR;                          /*!< (@ 0x00000004) MPWM n Output Level Register                               */
  __IO uint32_t  FOLR;                         /*!< (@ 0x00000008) MPWM n compulsion Output Register                          */
  __IO uint32_t  PRD;                          /*!< (@ 0x0000000C) MPWM n Period Register                                     */
  __IO uint32_t  DUH;                          /*!< (@ 0x00000010) MPWM n DUTY x Register                                     */
  __IO uint32_t  DVH;                          /*!< (@ 0x00000014) MPWM n DUTY x Register                                     */
  __IO uint32_t  DWH;                          /*!< (@ 0x00000018) MPWM n DUTY x Register                                     */
  __IO uint32_t  DUL;                          /*!< (@ 0x0000001C) MPWM n DUTY x Register                                     */
  __IO uint32_t  DVL;                          /*!< (@ 0x00000020) MPWM n DUTY x Register                                     */
  __IO uint32_t  DWL;                          /*!< (@ 0x00000024) MPWM n DUTY x Register                                     */
  __IO uint32_t  CR1;                          /*!< (@ 0x00000028) MPWM n Control Register 1                                  */
  __IO uint32_t  CR2;                          /*!< (@ 0x0000002C) MPWM n Control Register 2                                  */
  __IO uint32_t  SR;                           /*!< (@ 0x00000030) MPWM n Status Register                                     */
  __IO uint32_t  IER;                          /*!< (@ 0x00000034) MPWM n Interrupt Enable Register                           */
  __IO uint32_t  CNT;                          /*!< (@ 0x00000038) MPWM n Counter Register                                    */
  __IO uint32_t  DTR;                          /*!< (@ 0x0000003C) MPWM n Dead-Time Register                                  */
  __IO uint32_t  PCR;                          /*!< (@ 0x00000040) MPWM n Protection Control Register                         */
  __IO uint32_t  PSR;                          /*!< (@ 0x00000044) MPWM n Protection Status Register                          */
  __IO uint32_t  OCR;                          /*!< (@ 0x00000048) MPWM n Overvoltage Control Register                        */
  __IO uint32_t  OSR;                          /*!< (@ 0x0000004C) MPWM n Overvoltage Status Register                         */
  __I  uint32_t  RESERVED[2];
  __IO uint32_t  ATR1;                         /*!< (@ 0x00000058) MPWM n ADC Trigger Counter m Register                      */
  __IO uint32_t  ATR2;                         /*!< (@ 0x0000005C) MPWM n ADC Trigger Counter m Register                      */
  __IO uint32_t  ATR3;                         /*!< (@ 0x00000060) MPWM n ADC Trigger Counter m Register                      */
  __IO uint32_t  ATR4;                         /*!< (@ 0x00000064) MPWM n ADC Trigger Counter m Register                      */
  __IO uint32_t  ATR5;                         /*!< (@ 0x00000068) MPWM n ADC Trigger Counter m Register                      */
  __IO uint32_t  ATR6;                         /*!< (@ 0x0000006C) MPWM n ADC Trigger Counter m Register                      */
  __I  uint32_t  RESERVED1[4];
  __IO uint32_t  CR3;                          /*!< (@ 0x00000080) MPWM n Control Register 3                                  */
  __IO uint32_t  CR4;                          /*!< (@ 0x00000084) MPWM n Control Register 4                                  */
  __I  uint32_t  RESERVED2[2];
  __IO uint32_t  PRDU;                         /*!< (@ 0x00000090) MPWM n Phase U Period Register                             */
  __IO uint32_t  PRDV;                         /*!< (@ 0x00000094) MPWM n Phase V Period Register                             */
  __IO uint32_t  PRDW;                         /*!< (@ 0x00000098) MPWM n Phase W Period Register                             */
  __I  uint32_t  RESERVED3;
  __IO uint32_t  CNTU;                         /*!< (@ 0x000000A0) MPWM n Counter U Register                                  */
  __IO uint32_t  CNTV;                         /*!< (@ 0x000000A4) MPWM n Counter V Register                                  */
  __IO uint32_t  CNTW;                         /*!< (@ 0x000000A8) MPWM n Counter W Register                                  */
  __I  uint32_t  RESERVED4;
  __IO uint32_t  DTRU;                         /*!< (@ 0x000000B0) MPWM n Dead-Time Register                                  */
  __IO uint32_t  DTRV;                         /*!< (@ 0x000000B4) MPWM n Dead-Time Register                                  */
  __IO uint32_t  DTRW;                         /*!< (@ 0x000000B8) MPWM n Dead-Time Register                                  */
  __I  uint32_t  RESERVED5;
  __IO uint32_t  CAPCNTU;                      /*!< (@ 0x000000C0) MPWM n Capture Counter Register (Ph-U)                     */
  __IO uint32_t  CAPCNTV;                      /*!< (@ 0x000000C4) MPWM n Capture Counter Register (Ph-V)                     */
  __IO uint32_t  CAPCNTW;                      /*!< (@ 0x000000C8) MPWM n Capture Counter Register (Ph-W)                     */
  __I  uint32_t  RESERVED6;
  __IO uint32_t  RCAPU;                        /*!< (@ 0x000000D0) MPWM n Capture Rising Value Register (Ph-U)                */
  __IO uint32_t  RCAPV;                        /*!< (@ 0x000000D4) MPWM n Capture Rising Value Register (Ph-V)                */
  __IO uint32_t  RCAPW;                        /*!< (@ 0x000000D8) MPWM n Capture Rising Value Register (Ph-W)                */
  __I  uint32_t  RESERVED7;
  __IO uint32_t  FCAPU;                        /*!< (@ 0x000000E0) MPWM n Capture Falling Value Register (Ph-U)               */
  __IO uint32_t  FCAPV;                        /*!< (@ 0x000000E4) MPWM n Capture Falling Value Register (Ph-V)               */
  __IO uint32_t  FCAPW;                        /*!< (@ 0x000000E8) MPWM n Capture Falling Value Register (Ph-W)               */
  __I  uint32_t  RESERVED8;
  __IO uint32_t  SCAPU;                        /*!< (@ 0x000000F0) MPWM n Sub Capture Value Register (Ph-U)                   */
  __IO uint32_t  SCAPV;                        /*!< (@ 0x000000F4) MPWM n Sub Capture Value Register (Ph-V)                   */
  __IO uint32_t  SCAPW;                        /*!< (@ 0x000000F8) MPWM n Sub Capture Value Register (Ph-W)                   */
} MPWM_Type;                                    /*!< Size = 252 (0xfc)                                                         */






typedef struct
{
    union
	{
        UINT32 MR;
        struct MR_Register {
            UINT8 UPDOWN 		:1; // PWM up/down counter mode (0: up-counter, 1: up-down counter)
            UINT8 MCHMOD 		:2; // Channel symmetry/asymmetry mode (Two-channel symmetric/One-channel asymmetric/One-channel symmetric)
            UINT8 Reserved_0 	:1; // Reserved
            UINT8 BUP 			:1; // Period update at bottom matches (0: not updated, 1: updated)
            UINT8 TUP 			:1; // Period update at period matches (0: not updated, 1: updated)
            UINT8 Reserved_1 	:1; // Reserved
            UINT8 UAO 			:1; // Update timing setting (0: designated timings, 1: immediate update)
            UINT8 Reserved_2 	:6; // Reserved
            UINT8 MOTORB 		:2; // MPWM mode selection (MPWM mode/Normal PWM mode/Individual PWM mode)
        } MR_register;
    };

    // MPWMn_OLR: MPWM output level register (偏移地址: 0x04)
    union
    {
        UINT32 OLR;
        struct OLR_Register {
            UINT8 ULL 			:1; // Invert at start of PWMxL (0: Basic, 1: Inverted)
            UINT8 VLL 			:1;
            UINT8 WLL 			:1;
            UINT8 UHL 			:1; // Invert at start of PWMxH (0: Basic, 1: Inverted)
            UINT8 VHL 			:1;
            UINT8 WHL 			:1;
            UINT8 Reserved_0 	:2; // Reserved
            UINT8 DOLUL 		:1; // Output level when PWMxL is disabled (0: Low, 1: High)
            UINT8 DOLVL 		:1;
            UINT8 DOLWL 		:1;
            UINT8 DOLUH 		:1; // Output level when PWMxH is disabled (0: Low, 1: High)
            UINT8 DOLVH 		:1;
            UINT8 DOLWH 		:1;
        } OLR_register;
    };

    // MPWMn_FOLR: MPWM forced output level register (偏移地址: 0x08)
    union
    {
        UINT32 FOLR;
        struct FOLR_Register {
            UINT8 ULFL 			:1; // Forced output level for UL (0: "L", 1: "H")
            UINT8 VLFL 			:1; // Forced output level for VL (0: "L", 1: "H")
            UINT8 WLFL 			:1; // Forced output level for WL (0: "L", 1: "H")
            UINT8 UHFL 			:1; // Forced output level for UH (0: "L", 1: "H")
            UINT8 VHFL 			:1; // Forced output level for VH (0: "L", 1: "H")
            UINT8 WHFL 			:1; // Forced output level for WH (0: "L", 1: "H")
        } FOLR_register;
    };

    // MPWMn_PRD: MPWM period register (偏移地址: 0x0C)
    union
    {
        UINT32 PRD;
        struct PRD_Register {
            UINT16 PERIOD 		:16; // PWM period (must be larger than 0x0010)
        } PRD_register;
    };

    // MPWMn_DUH: MPWM duty UH register (偏移地址: 0x10)
    union
    {
        UINT32 DUH;
        struct DUH_Register {
            UINT16 DUTY_UH 		:16; // Duty for UH output (0: Full duty "low", 0xFFFF: Zero duty "high")
        } DUH_register;
    };

    // MPWMn_DVH: MPWM duty VH register (偏移地址: 0x14)
    union
    {
        UINT32 DVH;
        struct DVH_Register {
            UINT16 DUTY_VH 		:16; // Duty for VH output (0: Full duty "low", 0xFFFF: Zero duty "high")
        } DVH_register;
    };

    // MPWMn_DWH: MPWM duty WH register (偏移地址: 0x18)
    union
    {
        UINT32 DWH;
        struct DWH_Register {
            UINT16 DUTY_WH 		:16; // Duty for WH output (0: Full duty "low", 0xFFFF: Zero duty "high")
        } DWH_register;
    };

    // MPWMn_DUL: MPWM duty UL register (偏移地址: 0x1C)
    union
    {
        UINT32 DUL;
        struct DUL_Register {
            UINT16 DUTY_UL 		:16; // Duty for UL output (0: Full duty "low", 0xFFFF: Zero duty "high")
        } DUL_register;
    };

    // MPWMn_DVL: MPWM duty VL register (偏移地址: 0x20)
    union
    {
        UINT32 DVL;
        struct DVL_Register {
            UINT16 DUTY_VL 		:16; // Duty for VL output (0: Full duty "low", 0xFFFF: Zero duty "high")
        } DVL_register;
    };

    // MPWMn_DWL: MPWM duty WL register (偏移地址: 0x24)
    union
    {
        UINT32 DWL;
        struct DWL_Register {
            UINT16 DUTY_WL 		:16; // Duty for WL output (0: Full duty "low", 0xFFFF: Zero duty "high")
        } DWL_register;
    };

    // MPWMn_CR1: MPWM control register 1 (偏移地址: 0x28)
    union
    {
        UINT32 MPWM_CR1;
        struct MPWM_CR1_Register {
            UINT8 PWMEN 		:2; // PWM enable (0: disables, 1: enables)
            UINT8 Reserved_0	:6; // Reserved
            UINT8 IRQN 			:3; // Interrupt request interval number
        }MPWM_CR1_register;
    };

    // MPWMn_CR2: MPWM control register 2 (偏移地址: 0x2C)
    union
    {
        UINT32 MPWM_CR2;
        struct MPWM_CR2_Register {
            UINT8 PSTART 		:1; // PWM counter start (0: stops and clears, 1: starts)
            UINT8 Reserved_0 	:6; // Reserved
            UINT8 HALT 			:1; // PWM halting (0: counter stops and resets, 1: counter stops but retains state)
        }MPWM_CR2_register;
    };

    // MPWMn_SR: MPWM status register (偏移地址: 0x30)
    union {
        UINT32 MPWM_SR;
        struct MPWM_SR_Register {
            UINT8 DULIF 		:1; // UL duty interrupt flag
            UINT8 DVLIF 		:1; // VL duty interrupt flag
            UINT8 DWLIF 		:1; // WL duty interrupt flag
            UINT8 DUHIF 		:1; // UH duty interrupt flag
            UINT8 DVHIF 		:1; // VH duty interrupt flag
            UINT8 DWHIF 		:1; // WH duty interrupt flag
            UINT8 BOTUIF 		:1; // PWM bottom interrupt flag
            UINT8 PRDUIF 		:1; // PWM period interrupt flag
            UINT8 BOTVIF 		:1; // Phase V channel's bottom interrupt flag
            UINT8 PRDVIF 		:1; // Phase V channel's period interrupt flag
            UINT8 BOTWIF 		:1; // Phase W channel's bottom interrupt flag
            UINT8 PRDWIF 		:1; // Phase W channel's period interrupt flag
            UINT8 UIRQCNT 		:3; // Phase U IRQ count
            UINT8 UDOWN 		:1; // PWM counter mode (0: up-counter, 1: down-counter)
            UINT8 VIRQCNT 		:3; // Phase V IRQ count
            UINT8 VDOWN 		:1; // Phase V counter mode (0: up-counter, 1: down-counter)
            UINT8 WIRQCNT 		:3; // Phase W IRQ count
            UINT8 WDOWN 		:1; // Phase W counter mode (0: up-counter, 1: down-counter)
        }MPWM_SR_register;
    };

    // MPWMn_IER: MPWM interrupt enable register (偏移地址: 0x34)
    union
    {
        UINT32 MPWM_IER;
        struct MPWM_IER_Register {
            UINT8 ULIE 			:1; // Enable UL duty interrupt
            UINT8 VLIE 			:1; // Enable VL duty interrupt
            UINT8 WLIE 			:1; // Enable WL duty interrupt
            UINT8 UHIE 			:1; // Enable UH duty interrupt
            UINT8 VHIE 			:1; // Enable VH duty interrupt
            UINT8 WHIE 			:1; // Enable WH duty interrupt
            UINT8 BOTIE 		:1; // Enable PWM bottom interrupt
            UINT8 PRDIUE 		:1; // Enable PWM period interrupt
            UINT8 BOTVIE 		:1; // Enable Phase V bottom interrupt
            UINT8 PRDIE 		:1; // Enable Phase V period interrupt
            UINT8 BOTWIE 		:1; // Enable Phase W bottom interrupt
            UINT8 PRDWIE 		:1; // Enable Phase W period interrupt
        }MPWM_IER_register;
    };

    // MPWMn_CNT: MPWM counter register (偏移地址: 0x38)
    union
    {
        UINT16 MPWM_CNT;
        struct MPWM_CNT_Register {
            UINT16 CNT 			:16; // PWM counter value
        }MPWM_CNT_register;
    };

    // MPWMn_DTR: MPWM dead time register (偏移地址: 0x3C)
    union
    {
        UINT32 DTR;
        struct DTR_Register {
            UINT8 DT 			:8; // Dead time value
            UINT8 DTCLK 		:2; // Dead time prescaler
            UINT8 Reserved_0 	:3; // Reserved
            UINT8 DTMDSEL 		:1; // Dead time mode selection
            UINT8 PSHRT 		:1; // Short-circuit protection (0: Enabled, 1: Disabled)
            UINT8 DTEN 			:1; // Enable dead time function (0: Disabled, 1: Enabled)
        } DTR_register;
    };

    // MPWMn_PCR: MPWM protection control register (偏移地址: 0x40)
    union
    {
        UINT32 PCR;
        struct PCR_Register {
            UINT8 ULPROTM 		:1; // Enable phase U L-side protection output
            UINT8 VLPROTM 		:1; // Enable phase V L-side protection output
            UINT8 WLPROTM 		:1; // Enable phase W L-side protection output
            UINT8 UHPROTM 		:1; // Enable phase U H-side protection output
            UINT8 VHPROTM 		:1; // Enable phase V H-side protection output
            UINT8 WHPROTM 		:1; // Enable phase W H-side protection output
            UINT8 Reserved_0 	:1; // Reserved
            UINT8 PROTIE 		:1; // Enable protection interrupt
            UINT8 PROTD 		:3; // PWM protection debounce
            UINT8 Reserved_1 	:3; // Reserved
            UINT8 PROTPOL 		:1; // PWM protection polarity (0: L-active, 1: H-active)
            UINT8 PROTEN 		:1; // Enable PWM protection input
            UINT8 VPROTD 		:3; // Phase V protection debounce
            UINT8 Reserved_2 	:3; // Reserved
            UINT8 VPROTPOL 		:1; // Phase V protection polarity (0: L-active, 1: H-active)
            UINT8 VPROTEN 		:1; // Enable phase V protection input
            UINT8 WPROTD 		:3; // Phase W protection debounce
            UINT8 Reserved_3 	:3; // Reserved
            UINT8 WPROTPOL 		:1; // Phase W protection polarity (0: L-active, 1: H-active)
            UINT8 WPROTEN 		:1; // Enable phase W protection input
        } PCR_register;
    };

    // MPWMn_PSR: MPWM protection status register (偏移地址: 0x44)
    union
    {
        UINT16 PSR;
        struct PSR_Register {
            UINT8 ULPROT 		:1; // Phase U L-side protection flag
            UINT8 VLPROT 		:1; // Phase V L-side protection flag
            UINT8 WLPROT 		:1; // Phase W L-side protection flag
            UINT8 UHPROT 		:1; // Phase U H-side protection flag
            UINT8 VHPROT 		:1; // Phase V H-side protection flag
            UINT8 WHPROT 		:1; // Phase W H-side protection flag
            UINT8 PROTIF 		:1; // Protection interrupt status
            UINT8 Reserved_0	:1; // Reserved
            UINT8 PROTKEY 		:8; // Protection clear access key (0xCA)
        } PSR_register;
    };

    // MPWMn_OCR: MPWM overvoltage control register (偏移地址: 0x48)
    union
    {
        UINT32 OCR;
        struct OCR_Register {
            UINT8 ULOVIN 		:1; // Enable phase U L-side overvoltage output
            UINT8 VLOVIN 		:1; // Enable phase V L-side overvoltage output
            UINT8 WLOVIN 		:1; // Enable phase W L-side overvoltage output
            UINT8 UHOVIN 		:1; // Enable phase U H-side overvoltage output
            UINT8 VHOVIN 		:1; // Enable phase V H-side overvoltage output
            UINT8 WHOVIN 		:1; // Enable phase W H-side overvoltage output
            UINT8 Reserved_0 	:1; // Reserved
            UINT8 OVINIE 		:1; // Enable overvoltage detection interrupt

            UINT8 OVIND 		:3; // PWM overvoltage debounce
            UINT8 Reserved_1 	:3; // Reserved
            UINT8 OVINPOL 		:1; // PWM overvoltage polarity (0: L-active, 1: H-active)
            UINT8 OVINEN 		:1; // Enable PWM overvoltage detection


            UINT8 VOVIND 		:3; // Phase V overvoltage debounce
            UINT8 Reserved_2 	:3; // Reserved
            UINT8 VOVINPOL 		:1; // Phase V overvoltage polarity (0: L-active, 1: H-active)
            UINT8 VOVINEN 		:1; // Enable phase V overvoltage detection

            UINT8 WOVIND 		:3; // Phase W overvoltage debounce
            UINT8 Reserved_3 	:3; // Reserved
            UINT8 WOVINPOL 		:1; // Phase W overvoltage polarity (0: L-active, 1: H-active)
            UINT8 WOVINEN 		:1; // Enable phase W overvoltage detection

        } OCR_register;
    };

    // MPWMn_OSR: MPWM overvoltage status register (偏移地址: 0x4C)
    union
    {
        UINT16 OSR;
        struct OSR_Register {
            UINT8 ULOVIN 		:1; // Phase U L-side overvoltage flag
            UINT8 VLOVIN 		:1; // Phase V L-side overvoltage flag
            UINT8 WLOVIN 		:1; // Phase W L-side overvoltage flag
            UINT8 UHOVIN 		:1; // Phase U H-side overvoltage flag
            UINT8 VHOVIN 		:1; // Phase V H-side overvoltage flag
            UINT8 WHOVIN 		:1; // Phase W H-side overvoltage flag
            UINT8 OVINIF 		:1; // Overvoltage detection interrupt status
            UINT8 Reserved_0 	:1; // Reserved
            UINT8 OVINKEY 		:8; // Overvoltage detection clear access key (0xAC)
        } OSR_register;
    };

    // MPWMn_ATRm: MPWM ADC trigger counter register (偏移地址: 0x50)
    union
    {
        UINT32 ATRm;
        struct ATRm_Register {
            UINT16 ATCNT 		:16; // ADC trigger counter

            UINT8 ATMOD 		:2; // ADC trigger mode
            UINT8 Reserved_0 	:1; // Reserved
            UINT8 ATUDT 		:1; // Trigger register update mode
            UINT8 Reserved_1 	:2; // Reserved
            UINT8 ATSRC 		:2; // ADC trigger source (Phase U/V/W)
        } ATRm_register;
    };
} WROS_MPWM_Type;


/* =========================================================================================================================== */
/* ================                                           QEI0                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Quadurature Encoder Interface (QEI0)
  */

typedef struct {                                /*!< (@ 0x4000B400) QEI0 Structure                                             */
  __IO uint32_t  MR;                           /*!< (@ 0x00000000) QEI n Mode Register                                        */
  __IO uint32_t  CON;                          /*!< (@ 0x00000004) QEI n Control Register                                     */
  __IO uint32_t  SR;                           /*!< (@ 0x00000008) QEI n Status Register                                      */
  __IO uint32_t  POS;                          /*!< (@ 0x0000000C) QEI n Position Counter Register                            */
  __IO uint32_t  MAX;                          /*!< (@ 0x00000010) QEI n Position Counter Maximum Register                    */
  __IO uint32_t  CMP0;                         /*!< (@ 0x00000014) QEI n Position Counter Compare0 Register                   */
  __IO uint32_t  CMP1;                         /*!< (@ 0x00000018) QEI n Position Counter Compare1 Register                   */
  __IO uint32_t  CMP2;                         /*!< (@ 0x0000001C) QEI n Position Counter Compare2 Register                   */
  __IO uint32_t  IDX;                          /*!< (@ 0x00000020) QEI n Index Counter Register                               */
  __IO uint32_t  CMPI;                         /*!< (@ 0x00000024) QEI n Index Comapre Register                               */
  __I  uint32_t  RESERVED[2];
  __IO uint32_t  VLR;                          /*!< (@ 0x00000030) QEI n Velocity Reload Register                             */
  __IO uint32_t  VLT;                          /*!< (@ 0x00000034) QEI n Velocity Timer Register                              */
  __IO uint32_t  VLP;                          /*!< (@ 0x00000038) QEI n Velocity Pulse Counter Register                      */
  __IO uint32_t  VLC;                          /*!< (@ 0x0000003C) QEI n Velocity Capture Register                            */
  __IO uint32_t  VLCOM;                        /*!< (@ 0x00000040) QEI n Velocity Compare Value Register                      */
  __I  uint32_t  RESERVED1[3];
  __IO uint32_t  IER;                          /*!< (@ 0x00000050) QEI n Interrupt Enable Register                            */
  __I  uint32_t  ISR;                          /*!< (@ 0x00000054) QEI n Interrupt Status Register                            */
  __O  uint32_t  ISCR;                         /*!< (@ 0x00000058) QEI n Interrupt Status Clear Register                      */
} QEI_Type;                                     /*!< Size = 92 (0x5c)                                                          */



/* =========================================================================================================================== */
/* ================                                           ADC0                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief 12-BIT A/D CONVERTER (ADC0)
  */

typedef struct {                                /*!< (@ 0x4000B000) ADC0 Structure                                             */
  __IO uint32_t  MR;                           /*!< (@ 0x00000000) ADC Mode Register                                          */
  __IO uint32_t  CSCR;                         /*!< (@ 0x00000004) ADC Current Sequence_Channel Register                      */
  __IO uint32_t  CCR;                          /*!< (@ 0x00000008) ADC Clock Control Register                                 */
  __IO uint32_t  TRG;                          /*!< (@ 0x0000000C) ADC Trigger Selection Register                             */
  __I  uint32_t  RESERVED[2];
  __IO uint32_t  SCSR1;                        /*!< (@ 0x00000018) ADC Channel Selection Register 1                           */
  __IO uint32_t  SCSR2;                        /*!< (@ 0x0000001C) ADC Channel Selection Register 2                           */
  __IO uint32_t  CR;                           /*!< (@ 0x00000020) ADC Control Register                                       */
  __IO uint32_t  SR;                           /*!< (@ 0x00000024) ADC Status Register                                        */
  __IO uint32_t  IER;                          /*!< (@ 0x00000028) ADC Interrupt Enable Register                              */
  __I  uint32_t  DDR;                          /*!< (@ 0x0000002C) ADC DMA Data Register                                      */
  __IO uint32_t  DR0;                          /*!< (@ 0x00000030) ADC Sequence Data Register0                                */
  __IO uint32_t  DR1;                          /*!< (@ 0x00000034) ADC Sequence Data Register1                                */
  __IO uint32_t  DR2;                          /*!< (@ 0x00000038) ADC Sequence Data Register2                                */
  __IO uint32_t  DR3;                          /*!< (@ 0x0000003C) ADC Sequence Data Register3                                */
  __IO uint32_t  DR4;                          /*!< (@ 0x00000040) ADC Sequence Data Register4                                */
  __IO uint32_t  DR5;                          /*!< (@ 0x00000044) ADC Sequence Data Register5                                */
  __IO uint32_t  DR6;                          /*!< (@ 0x00000048) ADC Sequence Data Register6                                */
  __IO uint32_t  DR7;                          /*!< (@ 0x0000004C) ADC Sequence Data Register7                                */
  __I  uint32_t  RESERVED1[8];
  __IO uint32_t  CMPR;                         /*!< (@ 0x00000070) ADC Channel Compare Register                               */
} ADC_Type;                                     /*!< Size = 116 (0x74)                                                         */



/* =========================================================================================================================== */
/* ================                                           PGA0                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Programmable Gain Amplifier (PGA0)
  */

typedef struct {                                /*!< (@ 0x4000B300) PGA0 Structure                                             */
  __IO uint32_t  CR;                           /*!< (@ 0x00000000) PGA Control Register                                       */
} PGA_Type;                                     /*!< Size = 4 (0x4)                                                            */



/* =========================================================================================================================== */
/* ================                                           COMP0                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief Comparator (COMP0)
  */

typedef struct {                                /*!< (@ 0x4000B380) COMP0 Structure                                            */
  __IO uint32_t  CONF;                         /*!< (@ 0x00000000) Comparator 0 Configuration Register                        */
  __IO uint32_t  CTRL;                         /*!< (@ 0x00000004) Comparator 0 Control Register                              */
  __IO uint32_t  STAT;                         /*!< (@ 0x00000008) Comparator 0 Status Register                               */
} COMP_Type;                                    /*!< Size = 12 (0xc)                                                           */



/* =========================================================================================================================== */
/* ================                                          AES128                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief Advanced Encryption Standard 128 (AES128)
  */

typedef struct {                                /*!< (@ 0x40000500) AES128 Structure                                           */
  __IO uint32_t  CTRL;                         /*!< (@ 0x00000000) AES Control Register                                       */
  __IO uint32_t  STAT;                         /*!< (@ 0x00000004) AES Status Register                                        */
  __O  uint32_t  INFIFO;                       /*!< (@ 0x00000008) AES Input FIFO Register                                    */
  __I  uint32_t  OUTFIFO;                      /*!< (@ 0x0000000C) AES Output FIFO Register                                   */
  __IO uint32_t  KEYIN0;                       /*!< (@ 0x00000010) AES KEY IN Register 0                                      */
  __IO uint32_t  KEYIN1;                       /*!< (@ 0x00000014) AES KEY IN Register 1                                      */
  __IO uint32_t  KEYIN2;                       /*!< (@ 0x00000018) AES KEY IN Register 2                                      */
  __IO uint32_t  KEYIN3;                       /*!< (@ 0x0000001C) AES KEY IN Register 3                                      */
  __I  uint32_t  TEXTIN0;                      /*!< (@ 0x00000020) AES TEXT IN 0 Register                                     */
  __I  uint32_t  TEXTIN1;                      /*!< (@ 0x00000024) AES TEXT IN 1 Register                                     */
  __I  uint32_t  TEXTIN2;                      /*!< (@ 0x00000028) AES TEXT IN 2 Register                                     */
  __I  uint32_t  TEXTIN3;                      /*!< (@ 0x0000002C) AES TEXT IN 3 Register                                     */
  __I  uint32_t  TEXTOUT0;                     /*!< (@ 0x00000030) AES TEXT OUT Register 0                                    */
  __I  uint32_t  TEXTOUT1;                     /*!< (@ 0x00000034) AES TEXT OUT Register 1                                    */
  __I  uint32_t  TEXTOUT2;                     /*!< (@ 0x00000038) AES TEXT OUT Register 2                                    */
  __I  uint32_t  TEXTOUT3;                     /*!< (@ 0x0000003C) AES TEXT OUT Register 3                                    */
} AES128_Type;                                  /*!< Size = 64 (0x40)                                                          */



/* =========================================================================================================================== */
/* ================                                            RNG                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Random Number Generator (RNG)
  */

typedef struct {                                /*!< (@ 0x40000A00) RNG Structure                                              */
  __IO uint32_t  CTRL;                         /*!< (@ 0x00000000) RNG Control Register                                       */
  __IO uint32_t  SEED;                         /*!< (@ 0x00000004) RNG SEED Register                                          */
  __I  uint32_t  RNGD;                         /*!< (@ 0x00000008) RNG Random number data register                            */
  __IO uint32_t  STAT;                         /*!< (@ 0x0000000C) RNG Status Register                                        */
} RNG_Type;                                     /*!< Size = 16 (0x10)                                                          */



/* =========================================================================================================================== */
/* ================                                            CRC                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief CYCLIC REDUNDANCY CHECK AND CHECKSUM (CRC)
  */

typedef struct {                                /*!< (@ 0x41002000) CRC Structure                                              */
  __IO uint32_t  CTRL;                         /*!< (@ 0x00000000) CRC Control Register                                       */
  __IO uint32_t  INIT;                         /*!< (@ 0x00000004) CRC Init value Register                                    */

  union {
    __I  uint32_t ODR;                         /*!< (@ 0x00000008) CRC Output Data Register                                   */
    __O  uint8_t IDR;                          /*!< (@ 0x00000008) CRC Input Data Register                                    */
  };
  __IO uint32_t  STAT;                         /*!< (@ 0x0000000C) CRC Status Register                                        */
} CRC_Type;                                     /*!< Size = 16 (0x10)                                                          */


/** @} */ /* End of group Device_Peripheral_peripherals */


/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_peripheralAddr
  * @{
  */

#define CHIPCONFIG_BASE             0x4000F000UL
#define SCU_BASE                    0x40000000UL




// PCU �Ĵ�������ַ
#define PCU_PA_BASE				0x40001000
#define PCU_PB_BASE				0x40001100
#define PCU_PC_BASE				0x40001200
#define PCU_PD_BASE				0x40001300
#define PCU_PE_BASE				0x40001400
#define PCU_PF_BASE				0x40001500
#define PCU_PG_BASE				0x40001600
#define PCU_PORTEN_BASE				0x40001FF0


















#define CFMC_BASE                   0x41000000UL
#define DFMC_BASE                   0x41001000UL
#define DMA0_BASE                   0x40000400UL
#define DMA1_BASE                   0x40000410UL
#define DMA2_BASE                   0x40000420UL
#define DMA3_BASE                   0x40000430UL
#define DMA4_BASE                   0x40000440UL
#define DMA5_BASE                   0x40000450UL
#define DMA6_BASE                   0x40000460UL
#define DMA7_BASE                   0x40000470UL
#define DMA8_BASE                   0x40000480UL
#define DMA9_BASE                   0x40000490UL
#define DMA10_BASE                  0x400004A0UL
#define DMA11_BASE                  0x400004B0UL
#define DMA12_BASE                  0x400004C0UL
#define DMA13_BASE                  0x400004D0UL
#define DMA14_BASE                  0x400004E0UL
#define DMA15_BASE                  0x400004F0UL
#define WDT_BASE                    0x40000200UL
#define TIMER0_BASE                 0x40003000UL
#define TIMER1_BASE                 0x40003040UL
#define TIMER2_BASE                 0x40003080UL
#define TIMER3_BASE                 0x400030C0UL
#define TIMER4_BASE                 0x40003100UL
#define TIMER5_BASE                 0x40003140UL
#define TIMER6_BASE                 0x40003180UL
#define TIMER7_BASE                 0x400031C0UL
#define TIMER8_BASE                 0x40003200UL
#define TIMER9_BASE                 0x40003240UL
#define FRT0_BASE                   0x40000600UL
#define FRT1_BASE                   0x40000700UL
#define UART0_BASE                  0x40008000UL
#define UART1_BASE                  0x40008100UL
#define UART2_BASE                  0x40008200UL
#define UART3_BASE                  0x40008300UL
#define UART4_BASE                  0x40008400UL
#define UART5_BASE                  0x40008500UL
#define SPI0_BASE                   0x40009000UL
#define SPI1_BASE                   0x40009100UL
#define SPI2_BASE                   0x40009200UL
#define I2C0_BASE                   0x4000A000UL
#define I2C1_BASE                   0x4000A100UL
#define CAN_BASE                    0x40007000UL
#define MPWM0_BASE                  0x40004000UL
#define MPWM1_BASE                  0x40005000UL
#define QEI0_BASE                   0x4000B400UL
#define QEI1_BASE                   0x4000B500UL
#define ADC0_BASE                   0x4000B000UL
#define ADC1_BASE                   0x4000B100UL
#define ADC2_BASE                   0x4000B200UL
#define PGA0_BASE                   0x4000B300UL
#define PGA1_BASE                   0x4000B304UL
#define PGA2_BASE                   0x4000B308UL
#define COMP0_BASE                  0x4000B380UL
#define COMP1_BASE                  0x4000B38CUL
#define COMP2_BASE                  0x4000B398UL
#define COMP3_BASE                  0x4000B3A4UL
#define AES128_BASE                 0x40000500UL
#define RNG_BASE                    0x40000A00UL
#define CRC_BASE                    0x41002000UL

/** @} */ /* End of group Device_Peripheral_peripheralAddr */


/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_declaration
  * @{
  */



#define CHIPCONFIG                  ((CHIPCONFIG_Type*)        CHIPCONFIG_BASE)
#define SCU                         ((SCU_Type*)               SCU_BASE)
#define CFMC                        ((CFMC_Type*)              CFMC_BASE)
#define DFMC                        ((DFMC_Type*)              DFMC_BASE)
#define DMA0                        ((DMA_Type*)               DMA0_BASE)
#define DMA1                        ((DMA_Type*)               DMA1_BASE)
#define DMA2                        ((DMA_Type*)               DMA2_BASE)
#define DMA3                        ((DMA_Type*)               DMA3_BASE)
#define DMA4                        ((DMA_Type*)               DMA4_BASE)
#define DMA5                        ((DMA_Type*)               DMA5_BASE)
#define DMA6                        ((DMA_Type*)               DMA6_BASE)
#define DMA7                        ((DMA_Type*)               DMA7_BASE)
#define DMA8                        ((DMA_Type*)               DMA8_BASE)
#define DMA9                        ((DMA_Type*)               DMA9_BASE)
#define DMA10                       ((DMA_Type*)               DMA10_BASE)
#define DMA11                       ((DMA_Type*)               DMA11_BASE)
#define DMA12                       ((DMA_Type*)               DMA12_BASE)
#define DMA13                       ((DMA_Type*)               DMA13_BASE)
#define DMA14                       ((DMA_Type*)               DMA14_BASE)
#define DMA15                       ((DMA_Type*)               DMA15_BASE)
#define WDT                         ((WDT_Type*)               WDT_BASE)
/*
*/
#define FRT0                        ((FRT_Type*)               FRT0_BASE)
#define FRT1                        ((FRT_Type*)               FRT1_BASE)
//#define UART0                       ((UART_Type*)              UART0_BASE)
//#define UART1                       ((UART_Type*)              UART1_BASE)
//#define UART2                       ((UART_Type*)              UART2_BASE)
//#define UART3                       ((UART_Type*)              UART3_BASE)
//#define UART4                       ((UART_Type*)              UART4_BASE)
//#define UART5                       ((UART_Type*)              UART5_BASE)
//#define SPI0                        ((SPI_Type*)               SPI0_BASE)
//#define SPI1                        ((SPI_Type*)               SPI1_BASE)
//#define SPI2                        ((SPI_Type*)               SPI2_BASE)
//#define I2C0                        ((I2C_Type*)               I2C0_BASE)
//#define I2C1                        ((I2C_Type*)               I2C1_BASE)
#define CAN                         ((CAN_Type*)               CAN_BASE)
//#define MPWM0                       ((MPWM_Type*)              MPWM0_BASE)
//#define MPWM1                       ((MPWM_Type*)              MPWM1_BASE)
#define QEI0                        ((QEI_Type*)               QEI0_BASE)
#define QEI1                        ((QEI_Type*)               QEI1_BASE)
//#define ADC0                        ((ADC_Type*)               ADC0_BASE)
//#define ADC1                        ((ADC_Type*)               ADC1_BASE)
//#define ADC2                        ((ADC_Type*)               ADC2_BASE)
#define PGA0                        ((PGA_Type*)               PGA0_BASE)
#define PGA1                        ((PGA_Type*)               PGA1_BASE)
#define PGA2                        ((PGA_Type*)               PGA2_BASE)
#define COMP0                       ((COMP_Type*)              COMP0_BASE)
#define COMP1                       ((COMP_Type*)              COMP1_BASE)
#define COMP2                       ((COMP_Type*)              COMP2_BASE)
#define COMP3                       ((COMP_Type*)              COMP3_BASE)
#define AES128                      ((AES128_Type*)            AES128_BASE)
#define RNG                         ((RNG_Type*)               RNG_BASE)
#define CRC                         ((CRC_Type*)               CRC_BASE)

/** @} */ /* End of group Device_Peripheral_declaration */



extern	WROS_SCU_Typedef*	WROS_SCU;

extern	WROS_PORTEN_Type*	WROS_PORTEN;
extern	WROS_PCU_TypeDef*	WROS_PA;
extern	WROS_PCU_TypeDef*	WROS_PB;
extern	WROS_PCU_TypeDef*	WROS_PC;
extern	WROS_PCU_TypeDef*	WROS_PD;
extern	WROS_PCU_TypeDef*	WROS_PE;
extern	WROS_PCU_TypeDef*	WROS_PF;
extern	WROS_PCU_TypeDef*	WROS_PG;


extern	WROS_TIMER_Type*	WROS_TIER_0;
extern	WROS_TIMER_Type*	WROS_TIER_1;
extern	WROS_TIMER_Type*	WROS_TIER_2;
extern	WROS_TIMER_Type*	WROS_TIER_3;
extern	WROS_TIMER_Type*	WROS_TIER_4;
extern	WROS_TIMER_Type*	WROS_TIER_5;


extern	WROS_UART_Type*		WROS_UART_0;
extern	WROS_UART_Type*		WROS_UART_1;
extern	WROS_UART_Type*		WROS_UART_2;
extern	WROS_UART_Type*		WROS_UART_3;
extern	WROS_UART_Type*		WROS_UART_4;
extern	WROS_UART_Type*		WROS_UART_5;


extern	WROS_I2C_Type*		WROS_I2C_0;
extern	WROS_I2C_Type*		WROS_I2C_1;

extern	WROS_MPWM_Type*		WROS_MPWM_0;
extern	WROS_MPWM_Type*		WROS_MPWM_1;


/************************************************************************
************************************************************************
				Driver_Struct
************************************************************************
************************************************************************/
//	TIMER
void	WROS_Base_Timer(void);




typedef enum{	SPI,			IIC																																	}T_Device_Type;
typedef enum{	Initial_Dev_0,	Device_Index_1,		Device_Index_2,		Device_Index_3,		Device_Index_4,		Device_Index_5,		Device_Index_6					}T_Device_Step;
typedef enum{	Serial_Oneshot,	Serial_Keep,		Serial_Busy,		Serial_Sleep																				}T_Comm_State;
typedef enum{	Serial_Start,	Serial_Write_mode,	Serial_Read_mode,	Serial_TX_Adr,		Serial_RX_Adr,		Serial_TX_DATA,		Serial_RX_DATA,		Serial_Stop	}T_Comm_Step;
typedef enum{	NONE,			ACK,				NCK,				WriteACK,			ReadACK																	}T_Echo_Step;

typedef void(*Device_NextStep)();
typedef T_Echo_Step(*Device_Event)(volatile UINT32*, volatile UINT32*, volatile UINT32*);
typedef struct
{
	T_Device_Type		Device_Type;
	T_Device_Step		Device_Step;
	T_Comm_State		Comm_Request;
	T_Comm_Step			Comm_Step;

	struct
	{
				UINT8	Adr_Size;
				UINT8	Adr_Index;
				UINT8	Adr[4];

				UINT16	Data_Size;
				UINT16	Data_Index;
				UINT8	Data[320];
	}T_Serial_Packet;

	volatile	UINT32*	Eable_Pin;
	volatile	UINT32*	Clock_Pin;
	volatile	UINT32*	ChipS_Pin;
	volatile	UINT32*	DataW_Pin;
	volatile	UINT32*	Write_Pin_state;	//
	volatile	UINT32*	DataR_Pin;
	volatile	UINT32*	Read_Pin_state;

	void			(*Device_NextStep)(void);

	T_Echo_Step		EchoReq;
	T_Echo_Step		(*Device_Event)(volatile UINT32*, volatile UINT32*, volatile UINT32*, volatile UINT32*, volatile UINT32*);
}T_Serial_Interface_drive;


extern T_Serial_Interface_drive	LCD_Device;
extern T_Serial_Interface_drive	Flash_Device;
extern T_Serial_Interface_drive	Mpu6050_Device;
/*
//	USB
typedef struct
{
	UINT8		I2C_ID;
	T_CommState	CommState;

	struct
	{
		UINT8	Adr_Size;
		UINT8	Adr[2];
	    	UINT8	Data_Size;
	    	UINT8	Data[256];
	}Data_Packet;
}T_USB_drive;
extern T_USB_drive USB_Device;

*/























#define PERI_BASE (0x4000000UL)
#define BITBAND_PERI_BASE (0x42000000UL)



//#define BITBAND_PERI(addr, bitnum) (BITBAND_PERI_BASE + (((uint32_t)(addr) - PERI_BASE) << 5) + ((uint32_t)(bitnum) << 2))


#define BITBAND_PERI(addr, bitnum) (BITBAND_PERI_BASE + (((uint32_t)(addr) & 0x00FFFFFF) << 5) + ((uint32_t)(bitnum) << 2))


//	WROS_PE
#define GPIO_ODR(PinID, Num)	(*((__IO UINT32 *)BITBAND_PERI(&((WROS_P ## PinID)->ODR),Num)))
#define GPIO_IDR(PinID, Num)	(*((__IO UINT32 *)BITBAND_PERI(&((WROS_P ## PinID)->IDR),Num)))
#define GPIO_CR_1(PinID, Num)		(*((__IO UINT32 *)BITBAND_PERI(&((WROS_P ## PinID)->CR),(Num * 2))))
#define GPIO_CR_2(PinID, Num)		(*((__IO UINT32 *)BITBAND_PERI(&((WROS_P ## PinID)->CR),(Num * 2) + 1)))







#endif /* WROS_H */
