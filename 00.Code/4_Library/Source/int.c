


#include "../../1_Application/Include/APP_WorkingNormalState.h"


#include "../../3_Component/Include/Cmp_Display_Service.h"


#include "../../4_Library/Include/general.h"

#define ROOT
#include "../../4_Library/Include/Int.h"
#undef ROOT


#include "../../5_WROS/Include/DDI_BootingDriver.h"
#include "../../5_WROS/Include/DDI_RegisterDriver.h"



#include "../../6_Vablesource/Include/Vable_ModelInformation.h"


static UINT8 mucDimmingScanline;



void SetLEDScanLine(UINT8);
void SetDataLine(UINT16);
void ControlDataLine(void);
void ControlScanLine(UINT8);
void ReadKeyData(UINT8);
void MWI_LEDControlPortAllClear(void);
void PWMForDisplay(void);
void Encoder_Input_Control(void);
void DoorDE4Scan(void);
void StandbySignalScan(void);
void Timer_TimeInc();

#define KEY_VALUE ((WROS_PC->IDR & BIN8(0110,0000)) >> 5)


UINT32 gunTime_HalfS_Cnt = 0;
#define TotalCycle	40		//20ms
#define DutyCycle	10		//5ms


void MWI_INT_Timer0()
{
	static UINT8 ucScan_Line = 0;
	static UINT16 sunTime_500usec_Cnt = 0;

	sunTime_500usec_Cnt++;

	PWMForDisplay();


	StandbySignalScan();
	DoorDE4Scan();

	if(sunTime_500usec_Cnt % 2 == 0)
	{
		ucScan_Line++;
		MAX_Limite(ucScan_Line, 0, 3);
		ControlScanLine(ucScan_Line);

		#ifdef ROTARY_KEY
			Encoder_Input_Control();
		#else
		#endif
	}
	else
	{;}
	ControlDataLine();

	if(sunTime_500usec_Cnt % 20 == 0)
	{
		Timer_TimeInc();
	}
	else
	{
		;
	}


	if(sunTime_500usec_Cnt % 1000 == 0)
	{
		gunTime_HalfS_Cnt++;
		sunTime_500usec_Cnt = 0;
		MAX_Limite(gunTime_HalfS_Cnt, 0, 9);
	}
	else
	{
		;
	}
}

UINT32 timer_1s_calc(void)
{
	return gunTime_HalfS_Cnt;
}
/*
void int_timer2(void)
{
	su16Time_500usec_Cnt++;
	//5msec
	if(su16Time_500usec_Cnt % 20 == 0)
	{
		p8OUT ^= 0x10;
		TIME_5MS_F = SET;
		su16Time_500usec_Cnt = 0;
	}
}
*/
void int_WDT(void)
{
#if(0)

	while(1){
		RSTCTR = 0x01;		//micom software reset
	}
#else
	NVIC_SystemReset();
#endif
}


void ControlScanLine(UINT8 ucScan_line)
{
	MWI_LEDControlPortAllClear();
	SetLEDScanLine(ucScan_line);
	mucDimmingScanline = ucScan_line;
}


void ControlDataLine(void)
{
	UINT16 unLEDDataLine = 0;

	unLEDDataLine = gu8LED_Data[mucDimmingScanline].word;
	SetDataLine(unLEDDataLine);
}

void SetDataLine(UINT16 unMasking)
{
	//LED_DATA_LINE_A_G = (UINT8)(unMasking & 0x7F);
}

void SetLEDScanLine(UINT8 unScanline)
{
    /*
	if(unScanline == 0)
	{
		SCAN_LINE_0 = SET;
	}
	else if(unScanline == 1)
	{
		SCAN_LINE_1 = SET;
	}
	else if(unScanline == 2)
	{
		SCAN_LINE_2 = SET;
	}
	else if(unScanline == 3)
	{
		SCAN_LINE_3 = SET;
	}
	else
	{
		;
	}

	__asm("NOP");
	__asm("NOP");
	__asm("NOP");
*/
}



void MWI_LEDControlPortAllClear(void)
{
    /*
	UINT8 ucindex = CLR;


	LED_DATA_LINE_A = 0;
	LED_DATA_LINE_B = 0;
	LED_DATA_LINE_C = 0;
	LED_DATA_LINE_D = 0;
	LED_DATA_LINE_E = 0;
	LED_DATA_LINE_F = 0;
	LED_DATA_LINE_G = 0;

	__asm("NOP");
	__asm("NOP");
	__asm("NOP");

	SCAN_LINE_0 = 0;
	SCAN_LINE_1 = 0;
	SCAN_LINE_2 = 0;
	SCAN_LINE_3 = 0;

	for(ucindex = 0; ucindex < 15; ucindex++)
	{
		;
	}
*/
}

void PWMForDisplay()
{
    /*
	static UINT8 Step = 0;

	Step++;
	if(Step <= DutyCycle)
	{
		DOOR_SIG_SIGNAL = Standby_Signal_Flag;
	}
	else
	{
		DOOR_SIG_SIGNAL = CLR;
	}

	if(Step == TotalCycle)
	{
		Step = CLR;
	}
	else
	{;}
*/
}


void HWKeyScan()
{

	static UINT16 sucKeycounter = 0;

	if(KEY_VALUE != CLR)
	{
		if(sucKeycounter < 10000)
		{
			sucKeycounter++;
			if(sucKeycounter == 19)
			{
				gunKey_New |= KEY_VALUE;
			}
			else if(sucKeycounter == 9999)
			{
				gunKey_New |= (KEY_VALUE << 4);
			}
			else
			{;}
		}
		else
		{;}
	}
	else
	{
		gunKey_New = CLR;
		sucKeycounter = 0;
	}

}


void Encoder_Input_Control(void)
{
    /*
	static UINT8 gu8Encoder_Timer = 0;
	static UINT8 gu8Encoder_InCounter = 0;
	static UINT8 gaucEncoderBuffer[5] = {0,};
	UINT8 Temp = 0;
	UINT8 b,c = 0;
	if(gu8Encoder_Timer != 0)
	{	gu8Encoder_Timer--;
		return;
	}
	else
	{
		Temp = (UINT8)(CHOOSE_KEY);

		if(Temp != gaucEncoderBuffer[0])
		{
			for(b=4,c=3; b!=0; b--,c--)
			{	gaucEncoderBuffer[b] = gaucEncoderBuffer[c];
			}

			gaucEncoderBuffer[0] = Temp;
			gu8Encoder_InCounter++;
			if((gu8Encoder_InCounter >= 4)
					&& (gaucEncoderBuffer[0] == 0x03))
			{
				if((gaucEncoderBuffer[1] == 0x02)
						&& (gaucEncoderBuffer[2] == 0x00)
						&& (gaucEncoderBuffer[3] == 0x01)
						&& (gaucEncoderBuffer[4] == 0x03))
				{	gu8Encoder_InCounter = 0;
					gu8Encoder_Timer = 100;
					gunKey_New |= (CHOOSE_KEY & BIN4(0001));
				}
				else if((gaucEncoderBuffer[1] == 0x01)
						&& (gaucEncoderBuffer[2] == 0x00)
						&& (gaucEncoderBuffer[3] == 0x02)
						&& (gaucEncoderBuffer[4] == 0x03))
				{	gu8Encoder_InCounter = 0;
					gu8Encoder_Timer = 100;
					gunKey_New |= (CHOOSE_KEY & BIN4(0010));
				}
				else
				{;
				}


			}
			else
			{;
			}
		}
		else
		{;
		}
	}
    */
}

void StandbySignalScan(void)
{
/*
	if(STANDBY_SIGNAL == 1)
	{
		Standby_Signal_Flag = SET;
	}
	else
	{
		;
	}
*/
}

void DoorDE4Scan(void)
{
/*
	if(DOOR_SEN_SIGNAL == 1)
	{
		Door_SEN_SIGNAL_Flag = SET;
		Door_SIG_SIGNAL_Flag = SET;
	}
	else
	{
		Door_SEN_SIGNAL_Flag = CLR;
		Door_SIG_SIGNAL_Flag = CLR;
	}
*/
}


void Timer_TimeInc(void)
{
	mstTimeCheckBaseTimer.ulLow += 10;
}

UINT8 Timer_MsecCheckPassTime(T_Time* pstTime, UINT32 ulTime)
{
	T_Time stCurrentTime;
	UINT8 ucRetValue = 0;

	stCurrentTime.ulLow = mstTimeCheckBaseTimer.ulLow;

	if(stCurrentTime.ulLow >= pstTime->ulLow)
	{
		if(stCurrentTime.ulLow - pstTime->ulLow >= ulTime)
		{	ucRetValue = 1;
		}
		else
		{	ucRetValue = 0;
		}
	}
	else if((0xFFFFFFFF - pstTime->ulLow + stCurrentTime.ulLow) >= ulTime)
	{	ucRetValue = 1;
	}
	else
	{	ucRetValue = 0;
	}

	if(ucRetValue == SET)
	{
		pstTime->ulLow = stCurrentTime.ulLow;
	}
	else
	{
		;
	}

	return ucRetValue;
}



void Timer_GetTime(T_Time* pstTime)
{
	pstTime->ulLow = mstTimeCheckBaseTimer.ulLow;
}

/*
void Device_500usBaseTimer(void)
{
	InitTimeChekBaseTimer.Timer++;

	if(((UINT32)(Device_GetTime() / 0x00020000) % 2) == 1)
	{
		PE_DATA_PE2	=	SET;
	}
	else
	{
		PE_DATA_PE2	=	CLR;
	}


}
*/


