



#ifndef __INC_BOOT_DRIVE_DDI__
#define __INC_BOOT_DRIVE_DDI__

#ifdef ROOT
#define EXTR
#else
#define EXTR extern
#endif

void DD_SetUARTWithDisplay(UINT8, UINT8);
void DD_SetDMAUARTDisplay(UINT8, UINT8);

void DDI_BootMicom(void);
void DD_SetFlowMeterRegister(void);

void DDI_Disable_Interrupt(void);
void DDI_Enable_Interrupt(void);

void DDI_SetEcoSensing(void);

void DDI_SetHallSensing(void);


void DDI_SetWDT(void);
void DDI_Disable_WDT(void);


#undef EXTR
#endif



