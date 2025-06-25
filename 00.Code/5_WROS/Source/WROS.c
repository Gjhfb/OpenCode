
#include "../../4_Library/Include/Int.h"

#include "../../5_WROS/Include/WROS.h"

#include "../../6_Vablesource/Include/Vable_ModelInformation.h"

/************************************************************************
************************************************************************
				WROS_Reister
************************************************************************
************************************************************************/
//	SCU
WROS_SCU_Typedef*	WROS_SCU	= 	((WROS_SCU_Typedef*)SCU_BASE);

//	GPIO
WROS_PORTEN_Type*	WROS_PORTEN	= 	((WROS_PORTEN_Type*)PCU_PORTEN_BASE);
WROS_PCU_TypeDef*	WROS_PA		=	((WROS_PCU_TypeDef*)PCU_PA_BASE);
WROS_PCU_TypeDef*	WROS_PB		=	((WROS_PCU_TypeDef*)PCU_PB_BASE);
WROS_PCU_TypeDef*	WROS_PC		=	((WROS_PCU_TypeDef*)PCU_PC_BASE);
WROS_PCU_TypeDef*	WROS_PD		=	((WROS_PCU_TypeDef*)PCU_PD_BASE);
WROS_PCU_TypeDef*	WROS_PE		=	((WROS_PCU_TypeDef*)PCU_PE_BASE);
WROS_PCU_TypeDef*	WROS_PF		=	((WROS_PCU_TypeDef*)PCU_PF_BASE);
WROS_PCU_TypeDef*	WROS_PG		=	((WROS_PCU_TypeDef*)PCU_PG_BASE);

//	TIER
WROS_TIMER_Type*	WROS_TIER_0	=	((WROS_TIMER_Type*)TIMER0_BASE);
WROS_TIMER_Type*	WROS_TIER_1	=	((WROS_TIMER_Type*)TIMER1_BASE);
WROS_TIMER_Type*	WROS_TIER_2	=	((WROS_TIMER_Type*)TIMER2_BASE);
WROS_TIMER_Type*	WROS_TIER_3	=	((WROS_TIMER_Type*)TIMER3_BASE);
WROS_TIMER_Type*	WROS_TIER_4	=	((WROS_TIMER_Type*)TIMER4_BASE);
WROS_TIMER_Type*	WROS_TIER_5	=	((WROS_TIMER_Type*)TIMER5_BASE);

//	UART
WROS_UART_Type*		WROS_UART_0	=	((WROS_UART_Type*)UART0_BASE);
WROS_UART_Type*		WROS_UART_1	=	((WROS_UART_Type*)UART1_BASE);
WROS_UART_Type*		WROS_UART_2	=	((WROS_UART_Type*)UART2_BASE);
WROS_UART_Type*		WROS_UART_3	=	((WROS_UART_Type*)UART3_BASE);
WROS_UART_Type*		WROS_UART_4	=	((WROS_UART_Type*)UART4_BASE);
WROS_UART_Type*		WROS_UART_5	=	((WROS_UART_Type*)UART5_BASE);

//	I2C
WROS_I2C_Type*		WROS_I2C_0	=	((WROS_I2C_Type*)I2C0_BASE);
WROS_I2C_Type*		WROS_I2C_1	=	((WROS_I2C_Type*)I2C1_BASE);

// 定义 MPWM 寄存器的基地址
WROS_MPWM_Type*		WROS_MPWM_0	=	((WROS_MPWM_Type*)MPWM0_BASE);
WROS_MPWM_Type*		WROS_MPWM_1	=	((WROS_MPWM_Type*)MPWM1_BASE);


/************************************************************************
************************************************************************
				Device_Func
************************************************************************
************************************************************************/
//	timer
static UINT32 Base_Timer_100us = 0;
static UINT32 Base_Timer_1s = 0;
void	timer_0_1ms(void);	//	100us
void	timer_1ms(void);	//	1000us
void	timer_10ms(void);	//	10000us
void	timer_1000ms(void);	//	1000000us

void WROS_Serial_Interface_Control(T_Serial_Interface_drive* pstSerial_CommInfo);
void WROS_Serial_Start(T_Serial_Interface_drive* pstSerial_CommInfo);
void WROS_Serial_Stop(T_Serial_Interface_drive* pstSerial_CommInfo);
void WROS_Serial_ChangetoTx(T_Serial_Interface_drive* pstSerial_CommInfo);
void WROS_Serial_ChangetoRx(T_Serial_Interface_drive* pstSerial_CommInfo);
void WROS_Serial_WriteAddress(T_Serial_Interface_drive* pstSerial_CommInfo);
void WROS_Serial_WriteOneByteAddress(T_Serial_Interface_drive* pstSerial_CommInfo);
void WROS_Serial_WriteData(T_Serial_Interface_drive* pstSerial_CommInfo);
void WROS_Serial_WriteOneByteData(T_Serial_Interface_drive* pstSerial_CommInfo);
void WROS_Serial_ReadData(T_Serial_Interface_drive* pstSerial_CommInfo);
void WROS_Serial_ReadOneByte(T_Serial_Interface_drive* pstSerial_CommInfo);
T_Echo_Step Write_ACK(volatile UINT32* Clock_Pin, volatile UINT32* DataW_Pin, volatile UINT32* DataR_Pin, volatile UINT32* DataW_Pin_State, volatile UINT32* DataR_Pin_State);
T_Echo_Step Read_ACK(volatile UINT32* Clock_Pin, volatile UINT32* DataW_Pin, volatile UINT32* DataR_Pin, volatile UINT32* DataW_Pin_State, volatile UINT32* DataR_Pin_State);
void Loop_Delay(UINT8);


T_Serial_Interface_drive	LCD_Device;
T_Serial_Interface_drive	Flash_Device;
T_Serial_Interface_drive	Mpu6050_Device;
//	USB
//T_USB_drive USB_Device;

/************************************************************************
************************************************************************/


static void (* const FuncBaseTimer[]) (void) =

{
	timer_0_1ms,
	timer_1ms,
//	timer_10ms,
//	timer_1000ms,
};




//	timer
void	WROS_Base_Timer()
{
	Base_Timer_100us++;
	if(Base_Timer_100us % 10000 == 0)
	{
		Base_Timer_100us = 0;
		Base_Timer_1s++;		//	Max130years
	}

	UINT8 TimerIndex = 0;
	while(TimerIndex < SIZE_OF_ARRAY(FuncBaseTimer)){FuncBaseTimer[TimerIndex++]();}
}


void	timer_0_1ms()
{
#ifdef _LCD_

	if(LCD_Device.Comm_Request != Serial_Sleep)
	{
		WROS_Serial_Interface_Control(&LCD_Device);
	}
	else
	{	;
	}

#endif

}

void	timer_1ms()
{
/*
	if(LCD_Device.Device_Step < Device_Index_3)
	{	return;
	}
	else
	{	;
	}
*/
	HWKeyScan();

#ifdef _MPU6050_
		if(Mpu6050_Device.Comm_Request != Serial_Sleep)
		{
			WROS_Serial_Interface_Control(&Mpu6050_Device);
		}
		else
		{	;
		}
#endif
}
void	timer_10ms()
{
	if(Base_Timer_100us % 100 == 0)
	{
		HWKeyScan();

	}
}

void	timer_1000ms()
{
	if(Base_Timer_100us % 10000 == 0)
	{
		Base_Timer_100us = 0;
		Base_Timer_1s++;		//	Max130years

		WROS_PE->ODR_register.POD0 ^= SET;

	}
}












//	Key




//	IIC
void WROS_Serial_Interface_Control(T_Serial_Interface_drive* pstSerial_CommInfo)
{
	switch(pstSerial_CommInfo->Comm_Step)
	{
		case Serial_Start:
			WROS_Serial_Start(pstSerial_CommInfo);
			pstSerial_CommInfo->Device_NextStep();
			break;

		case Serial_Write_mode:
			WROS_Serial_ChangetoTx(pstSerial_CommInfo);
			pstSerial_CommInfo->Device_NextStep();
			break;

		case Serial_Read_mode:
			WROS_Serial_ChangetoRx(pstSerial_CommInfo);
			pstSerial_CommInfo->Device_NextStep();
			break;

		case Serial_TX_Adr:
			WROS_Serial_WriteAddress(pstSerial_CommInfo);
			pstSerial_CommInfo->Device_NextStep();
			break;
/*
		case Serial_RX_Adr:
			WROS_Serial_WriteAddress(pstSerial_CommInfo);
			pstSerial_CommInfo->Device_NextStep();
			break;
*/
		case Serial_TX_DATA:
			WROS_Serial_WriteData(pstSerial_CommInfo);
			pstSerial_CommInfo->Device_NextStep();
			break;

		case Serial_RX_DATA:
			WROS_Serial_ReadData(pstSerial_CommInfo);
			pstSerial_CommInfo->Device_NextStep();
			break;

		case Serial_Stop:
			WROS_Serial_Stop(pstSerial_CommInfo);
			pstSerial_CommInfo->Device_NextStep();
			break;

		default:
			break;
	}


	if(pstSerial_CommInfo->EchoReq == NONE)
	{	;
	}
	else
	{
		pstSerial_CommInfo->Device_Event = (pstSerial_CommInfo->EchoReq == WriteACK ? Write_ACK : Read_ACK);
		pstSerial_CommInfo->Device_Event(pstSerial_CommInfo->Clock_Pin, pstSerial_CommInfo->DataW_Pin, pstSerial_CommInfo->DataR_Pin, pstSerial_CommInfo->Write_Pin_state, pstSerial_CommInfo->Read_Pin_state);
		pstSerial_CommInfo->EchoReq = NONE;
	}
}

void WROS_Serial_Start(T_Serial_Interface_drive* pstSerial_CommInfo)
{
	if(pstSerial_CommInfo->Device_Type == IIC)
	{
		Loop_Delay(20);
	}

	*pstSerial_CommInfo->DataW_Pin = (pstSerial_CommInfo->Device_Type == IIC ? SET : CLR);
	*pstSerial_CommInfo->DataR_Pin = (pstSerial_CommInfo->Device_Type == IIC ? SET : CLR);
	*pstSerial_CommInfo->Clock_Pin = (pstSerial_CommInfo->Device_Type == IIC ? SET : CLR);

	if(pstSerial_CommInfo->Device_Type == IIC)
	{
		Loop_Delay(20);
	}

	*pstSerial_CommInfo->DataW_Pin = CLR;
	*pstSerial_CommInfo->DataR_Pin = CLR;

	if(pstSerial_CommInfo->Device_Type == IIC)
	{
		Loop_Delay(20);
	}

	*pstSerial_CommInfo->Clock_Pin = CLR;
}

void WROS_Serial_Stop(T_Serial_Interface_drive* pstSerial_CommInfo)
{
	if(pstSerial_CommInfo->Device_Type == IIC)
	{
		Loop_Delay(20);
	}

	*pstSerial_CommInfo->Clock_Pin = CLR;
	*pstSerial_CommInfo->DataW_Pin = CLR;
	*pstSerial_CommInfo->DataR_Pin = CLR;

	if(pstSerial_CommInfo->Device_Type == IIC)
	{
		Loop_Delay(20);
	}

	*pstSerial_CommInfo->Clock_Pin = (pstSerial_CommInfo->Device_Type == IIC ? SET : CLR);

	if(pstSerial_CommInfo->Device_Type == IIC)
	{
		Loop_Delay(20);
	}

	*pstSerial_CommInfo->DataW_Pin = (pstSerial_CommInfo->Device_Type == IIC ? SET : CLR);
	*pstSerial_CommInfo->DataR_Pin = (pstSerial_CommInfo->Device_Type == IIC ? SET : CLR);
}

void WROS_Serial_ChangetoTx(T_Serial_Interface_drive* pstSerial_CommInfo)
{
	if(*pstSerial_CommInfo->Write_Pin_state == ((OD_Output >> 1) & 0x01))
	{	;
	}
	else
	{
		*pstSerial_CommInfo->Write_Pin_state = ((OD_Output >> 1) & 0x01);
	}
}

void WROS_Serial_ChangetoRx(T_Serial_Interface_drive* pstSerial_CommInfo)
{
	if(*pstSerial_CommInfo->Read_Pin_state == ((Input >> 1) & 0x01))
	{	;
	}
	else
	{
		*pstSerial_CommInfo->Read_Pin_state = ((Input >> 1) & 0x01);
	}
}

void WROS_Serial_WriteAddress(T_Serial_Interface_drive* pstSerial_CommInfo)
{
	if(pstSerial_CommInfo->T_Serial_Packet.Adr_Size != 0)
	{
		pstSerial_CommInfo->T_Serial_Packet.Adr_Size--;
		WROS_Serial_WriteOneByteAddress(pstSerial_CommInfo);
		pstSerial_CommInfo->T_Serial_Packet.Adr_Index++;
	}
}

void WROS_Serial_WriteOneByteAddress(T_Serial_Interface_drive* pstSerial_CommInfo)
{
	UINT8 Data = pstSerial_CommInfo->T_Serial_Packet.Adr[pstSerial_CommInfo->T_Serial_Packet.Adr_Index];

	for(UINT8 i = 8; i > 0; i--)
	{
		if(Data & 0x80)
		{
			*pstSerial_CommInfo->DataW_Pin = SET;
		}
		else
		{
			*pstSerial_CommInfo->DataW_Pin	= CLR;
		}

		if(pstSerial_CommInfo->Device_Type == IIC)
		{
			Loop_Delay(20);
		}

		*pstSerial_CommInfo->Clock_Pin = CLR;
		*pstSerial_CommInfo->Clock_Pin = SET;

		if(pstSerial_CommInfo->Device_Type == IIC)
		{
			Loop_Delay(20);
			*pstSerial_CommInfo->Clock_Pin = CLR;
		}
		else
		{	;
		}

		Data <<= 1;
	}

}

void WROS_Serial_WriteData(T_Serial_Interface_drive* pstSerial_CommInfo)
{
	if(pstSerial_CommInfo->T_Serial_Packet.Data_Size != 0)
	{
		pstSerial_CommInfo->T_Serial_Packet.Data_Size--;
		WROS_Serial_WriteOneByteData(pstSerial_CommInfo);
		pstSerial_CommInfo->T_Serial_Packet.Data_Index++;
	}
}

void WROS_Serial_WriteOneByteData(T_Serial_Interface_drive* pstSerial_CommInfo)
{
	UINT8 Data = pstSerial_CommInfo->T_Serial_Packet.Data[pstSerial_CommInfo->T_Serial_Packet.Data_Index];

	for(UINT8 i = 8; i > 0; i--)
	{
		if(Data & 0x80)
		{
			*pstSerial_CommInfo->DataW_Pin = SET;
		}
		else
		{
			*pstSerial_CommInfo->DataW_Pin	= CLR;
		}

		if(pstSerial_CommInfo->Device_Type == IIC)
		{
			Loop_Delay(20);
		}
		else
		{	;
		}

		*pstSerial_CommInfo->Clock_Pin = CLR;
		*pstSerial_CommInfo->Clock_Pin = SET;

		if(pstSerial_CommInfo->Device_Type == IIC)
		{
			Loop_Delay(20);
			*pstSerial_CommInfo->Clock_Pin = CLR;
		}
		else
		{	;
		}

		Data <<= 1;
	}

	*pstSerial_CommInfo->DataW_Pin = (pstSerial_CommInfo->Device_Type == SPI ? CLR : SET);
}

void WROS_Serial_ReadData(T_Serial_Interface_drive* pstSerial_CommInfo)
{
	pstSerial_CommInfo->T_Serial_Packet.Data_Size--;
	WROS_Serial_ReadOneByte(pstSerial_CommInfo);
	pstSerial_CommInfo->T_Serial_Packet.Data_Index++;
}



void WROS_Serial_ReadOneByte(T_Serial_Interface_drive* pstSerial_CommInfo)
{
	UINT8 Data = 0;


	for(UINT8 i = 8; i > 0; i--)
	{
		Data <<= 1;

		*pstSerial_CommInfo->Clock_Pin = CLR;

		if(pstSerial_CommInfo->Device_Type == IIC)
		{
			Loop_Delay(20);
		}

		*pstSerial_CommInfo->Clock_Pin = SET;

		if(pstSerial_CommInfo->Device_Type == IIC)
		{
			Loop_Delay(20);
		}

		if(*pstSerial_CommInfo->DataR_Pin == SET)
		{
			Data |= 0x01;
		}
		else
		{
			Data &= 0xFE;
		}
	}
	pstSerial_CommInfo->T_Serial_Packet.Data[pstSerial_CommInfo->T_Serial_Packet.Data_Index] = Data;
//	*pstSerial_CommInfo->DataW_Pin = (pstSerial_CommInfo->Comm_Type == SPI ? CLR : SET);
}

T_Echo_Step Write_ACK(volatile UINT32* Clock_Pin, volatile UINT32* DataW_Pin, volatile UINT32* DataR_Pin, volatile UINT32* DataW_Pin_State, volatile UINT32* DataR_Pin_State)
{

	UINT8 Pin_State;
	Pin_State = *(DataR_Pin_State);
	*DataR_Pin_State = Input;

	*Clock_Pin = CLR;


	Loop_Delay(20);

	*DataW_Pin = CLR;						// write Low Signal ACK


	Loop_Delay(20);


	*Clock_Pin = SET;

	Loop_Delay(20);


	*Clock_Pin = CLR;

	*DataR_Pin_State = Pin_State;

	return ACK;
}

T_Echo_Step Read_ACK(volatile UINT32* Clock_Pin, volatile UINT32* DataW_Pin, volatile UINT32* DataR_Pin, volatile UINT32* DataW_Pin_State, volatile UINT32* DataR_Pin_State)
{
	UINT8 Pin_State;
	Pin_State = *(DataR_Pin_State);
	*DataR_Pin_State = ((Input >> 1) & 0x01);

	T_Echo_Step ucTemp;
	*Clock_Pin = CLR;


	Loop_Delay(20);

	*Clock_Pin = SET;


	Loop_Delay(20);


	ucTemp = (*DataR_Pin == CLR ? ACK : NCK);	// read Low Signal ACK
	*Clock_Pin = CLR;


	Loop_Delay(20);


	*Clock_Pin = CLR;

	*DataR_Pin_State = Pin_State;

	return ucTemp;
}




void Loop_Delay(UINT8 ucLoop_Number)
{
	while(ucLoop_Number > 0)
	{	ucLoop_Number--;
	}
}





