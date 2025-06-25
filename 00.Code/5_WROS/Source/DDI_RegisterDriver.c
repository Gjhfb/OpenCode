



#include "../../4_Library/Include/general.h"


#include "../../5_WROS/Include/DDI_BootingDriver.h"
#include "../../5_WROS/Include/DDI_RegisterDriver.h"



#define FOS_INIT	0
#define FOS_ON		1
#define FOS_END		2


void DDI_SetFanMotorDuty(UINT16 unDuty)
{
	if(unDuty != 0)
	{
		DDI_FC_EnablePWMDuty(unDuty);
	}
	else
	{
		DDI_FC_DisablePWMDuty();
	}

}

void DDI_FC_EnablePWMDuty(UINT16 unDuty)
{}

void DDI_FC_DisablePWMDuty()
{}

void DDI_TC_InitFreqTimer(void)
{
	//API_TMRB_CLR(TB1);
}

UINT16 DDI_TC_GetFreqBC(void)
{
	return 0;
}

UINT16 DDI_TC_GetFreqBC100ms(void)
{
	return 0;//(API_TMRB_CAP(TB1) + 5) / 10;
}

void DDI_ADC_StartADConv(void)
{
	//API_ADC_Start_of_SoftConvert(ADB);
}

UINT8 DDI_ADC_InProgress(void)
{
	return 0;//API_ADC_Busy_of_SoftFinish(ADB);
}

void DDI_INIT_SetWatchDogClear(void)
{
	//API_WDT_Set_WdtClr();
}

void DDI_INIT_SetWDandNMIClear(void)
{
	//API_WDT_Set_Wdt_Nmi_Clr();
}

void DDI_ResetMicom(void)
{
	NVIC_SystemReset();
}

void DDI_DisableReset(void)
{
	;
}

/*

*/
UINT8 DDI_Uart_GetRxByte(void)
{
	return 0;//API_SIO_RecvDataRead(SC0);
}

void DDI_Uart_SetTxByte(UINT8 ucTxByte)
{
	//API_SIO_SendDataSet(SC0, ucTxByte);
}

void DDI_UART_ClearBuffer(void)
{
	//API_SIO_CR_Read(SC0);
	//API_SIO_RecvDataRead(SC0);
}

UINT8 DDI_Uart_GetRxByte_ezDsps(void)
{
	return 0;//API_SIO_RecvDataRead(SC3);
}

void DDI_Uart_SetTxByte_ezDsps(UINT8 ucTxByte)
{
	//API_SIO_SendDataSet(SC3, ucTxByte);
}

void DDI_UART_ClearBuffer_ezDsps(void)
{
	//API_SIO_CR_Read(SC3);
	//API_SIO_RecvDataRead(SC3);
}

UINT8 DDI_Uart_GetRxByte_DxProtocol(void)
{
	return 0;//API_SIO_RecvDataRead(SC2);
}

void DDI_Uart_SetTxByte_DxProtocol(UINT8 ucTxByte)
{
	//API_SIO_SendDataSet(SC2, ucTxByte);
}

void DDI_UART_ClearBuffer_DxProtocol(void)
{
	//API_SIO_CR_Read(SC2);
	//API_SIO_RecvDataRead(SC2);
}








