




void DDI_SetFanMotorDuty(UINT16);

void DDI_FC_EnablePWMDuty(UINT16);
void DDI_FC_DisablePWMDuty(void);

void DDI_TC_InitFreqTimer(void);

UINT16 DDI_TC_GetFreqBC(void);

UINT16 DDI_TC_GetFreqBC100ms(void);
void DDI_ADC_StartADConv(void);

UINT8 DDI_ADC_InProgress(void);

void DDI_INIT_SetWatchDogClear(void);

void DDI_INIT_SetWDandNMIClear(void);

void DDI_ResetMicom(void);

void DDI_DisableReset(void);

UINT8 DDI_Uart_GetRxByte(void);

void DDI_Uart_SetTxByte(UINT8);

void DDI_UART_ClearBuffer(void);

UINT8 DDI_Uart_GetRxByte_ezDsps(void);

void DDI_Uart_SetTxByte_ezDsps(UINT8);

void DDI_UART_ClearBuffer_ezDsps(void);

UINT8 DDI_Uart_GetRxByte_DxProtocol(void);

void DDI_Uart_SetTxByte_DxProtocol(UINT8);


void DDI_UART_ClearBuffer_DxProtocol(void);




















