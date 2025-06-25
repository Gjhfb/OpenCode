


/* Includes ------------------------------------------------------------------*/

#ifndef __INC_INT_LIB__
#define __INC_INT_LIB__




#ifdef  ROOT
#define EXTR
#else
#define EXTR    extern
#endif

void HWKeyScan(void);

/** @addtogroup TX04_Periph_Driver
  * @{
  */

#define CHECKSUM_KEY ((WROS_GPIO_E->DATA >> 4) & BIN4(1100))
#define CHOOSE_KEY ((WROS_GPIO_E->DATA >> 4) & BIN4(0011))


#define STANDBY_SIGNAL PA_DATA_(7)


#define DOOR_SIG_SIGNAL PE_DATA_(2)
#define DOOR_SEN_SIGNAL PE_DATA_(3)


EXTR UINT8 gunKey_New;


EXTR UINT8 Standby_Signal_Flag;
EXTR UINT8 Door_SEN_SIGNAL_Flag;
EXTR UINT8 Door_SIG_SIGNAL_Flag;




#define LED_SCAN_LINE_MAX       3
#define LED_SCAN_LINE_0_3       WROS_GPIO_C->DATA

#define SCAN_LINE_0 PC_DATA_(3)
#define SCAN_LINE_1 PC_DATA_(2)
#define SCAN_LINE_2 PC_DATA_(1)
#define SCAN_LINE_3 PC_DATA_(0)


#define LED_DATA_LINE_A_G WROS_GPIO_A->DATA

#define LED_DATA_LINE_A PA_DATA_(0)
#define LED_DATA_LINE_B PA_DATA_(1)
#define LED_DATA_LINE_C PA_DATA_(2)
#define LED_DATA_LINE_D PA_DATA_(3)
#define LED_DATA_LINE_E PA_DATA_(4)
#define LED_DATA_LINE_F PA_DATA_(5)
#define LED_DATA_LINE_G PA_DATA_(6)


/*
EXTR UINT8 gu8Timer_dsp_CheckState;
EXTR volatile T_UByteBit gucTimeFlag1;
#define TIME_1MS_F gucTimeFlag1.BIT.B0
*/


#define HW_SELECT_KEY PE_DATA_PE6
#define HW_RESULT_KEY PE_DATA_PE7


void MWI_INT_Timer0(void);


void MWI_SetDoorCheckDelayTimer(UINT8);
UINT8 MWI_GetDoorCheckDelayTimer(void);
void MWI_SetSpinIpmTempControl(UINT8);
void MWI_SetSpinIpmTempControl_In_Dry(UINT8);
void MWI_INT_Set1msCnt(UINT8);
void MWI_INT_SetTumbling1msCnt(UINT8);






/*
EXTR TYPE_WORD gu8LED_Data[4];
void Device_500usBaseTimer(void);
void Device_InitTimer(void);
UINT32 timer_halfSec_Calc(void);
void Init_WDT(void);
void Device_Scan_lineControl(UINT8);
void Device_LED_Control_PortAllClear(void);
void Device_Set_LED_Scanline(UINT8);
void Device_Data_lineControl(void);
void Device_Set_LED_Dataline(UINT8);
void Device_Key_Scan(void);
*/
#undef  EXTR
#endif




UINT32 timer_1s_calc(void);
void Timer_TimeInc(void);
UINT8 Timer_MsecCheckPassTime(T_Time*,UINT32);
void Timer_GetTime(T_Time*);

static T_Time mstTimeCheckBaseTimer;

