


#include "../../4_Library/Include/general.h"
#include "../../4_Library/Include/Int.h"
#include "../../4_Library/Include/Lib_UartComm.h"
#include "../../4_Library/Include/Lib_CommSubMicom.h"
#include "../../4_Library/Include/Lib_SensingADC.h"
#include "../../4_Library/Include/Lib_EEPROM.h"



#include "../../5_WROS/Include/DDI_RegisterDriver.h"

#define M93C86_EEPROM

UINT8 EEP_SaveBufferToEEPROM(UINT16 ucstartAddr, UINT8* pucBuff, UINT8 ucBuffSize)
{
	UINT8 i = 0;

	EEP_Erase_Write_Enable();
	for(i = 0; i < ucBuffSize; i++)
	{
		if(EEP_ByteWrite((ucstartAddr + i), (UINT8)(*(pucBuff + i))) == RETURN_NG)
		{
			return RETURN_NG;
		}
		else
		{
			;
		}
	}
	EEP_Erase_Write_Disable();

	return RETURN_OK;
}

void EEP_LoadBufferFromEEPROM(UINT16 ucstartAddr, UINT8* pucBuff, UINT8 ucBuffSize)
{
	UINT8 i = 0;

	for(i = 0; i < ucBuffSize; i++)
	{
		*(pucBuff + i) = EEP_ByteRead(ucstartAddr + i);
	}
}

#define ADD_HW_EEPROM

UINT8 EEP_ByteRead(UINT16 ucAddress_Data)
{
/*
	UINT8 u8Read_Data = 0;

	EEPROM_CHIP_SELECT_INPUT_P = CLEAR;
	EEP_nBit_Write(0xC0,3);		//110
	EEP_AddressSet(ucAddress_Data);
	u8Read_Data = EEP_nBit_Read();
	EEPROM_CHIP_SELECT_INPUT_P = CLEAR;

	return (u8Read_Data);
 */
	return 0;
}

UINT8 EEP_ByteWrite(UINT16 ucAddress_Data, UINT8 ucWrite_Data)
{
/*
	UINT8 ucRetVal = 0;

	EEPROM_CHIP_SELECT_INPUT_P = CLEAR;
	EEP_nBit_Write(0xA0,3);		//opersion code 101
	EEP_AddressSet(ucAddress_Data);

	EEP_nBit_Write(ucWrite_Data, WRITE_BIT_LENGTH);

	EEPROM_CHIP_SELECT_INPUT_P = CLEAR;
	EEP_Loop_Delay(DEFAULT_DELAY_NUMBER);
	EEPROM_CHIP_SELECT_INPUT_P = SET;

	if(EEP_Busy_Delay() == RETURN_NG)
	{	ucRetVal = RETURN_NG;
	}
	else
	{
		ucRetVal = RETURN_OK;
	}

	return ucRetVal;
*/
	return 0;
}
void EEP_AddressSet(UINT16 ucAddress)
{

#if(EEPROM_TYPE == M93C86)
	EEP_nBit_Write(((UINT8)(ucAddress >> 3) & 0xE0), 3);
#else
	EEP_nBit_Write(((UINT8)(ucAddress >> 1) & 0x80), 1);
#endif
	EEP_nBit_Write((UINT8)(ucAddress & 0x00FF), 8);
}

UINT8 EEP_Busy_Delay(void)
{
/*
	static T_Time stEEPROMtimer;

	Timer_GetTime(&stEEPROMtimer);

	while(!EEPROM_SERIAL_READ_P)
	{
		if(Timer_MsecCheckPassTime(&stEEPROMtimer, (UINT32)(BUSY_DELAY_TIME)) == SET)
		{	EEPROM_CHIP_SELECT_INPUT_P = CLEAR;
			EEP_Loop_Delay(DEFAULT_DELAY_NUMBER);
			EEPROM_SERIAL_CLOCK_P = CLEAR;
			return (RETURN_NG);
		}
		else
		{;}
	}
	EEPROM_CHIP_SELECT_INPUT_P = CLEAR;
	EEP_Loop_Delay(DEFAULT_DELAY_NUMBER);
	EEPROM_SERIAL_CLOCK_P = CLEAR;
	return (RETURN_OK);
*/
	return 0;
}

void EEP_nBit_Write(UINT8 ucWriteData, UINT8 ucNumberOfBit)
{
/*
	UINT8 ucTemp1 = 0;

	EEPROM_SERIAL_CLOCK_P = CLEAR;
	EEP_Loop_Delay(DEFAULT_DELAY_NUMBER);
	EEPROM_CHIP_SELECT_INPUT_P = SET;

	ucTemp1 = ucWriteData;


	while(1)
	{
		if(ucTemp1 & 0x80)
		{	EEPROM_SERIAL_WRITE_P = ON;
		}
		else
		{	EEPROM_SERIAL_WRITE_P = OFF;
		}

		EEP_Loop_Delay(DEFAULT_DELAY_NUMBER);
		EEPROM_SERIAL_CLOCK_P = SET;
		ucNumberOfBit--;

		if(ucNumberOfBit != 0)
		{	ucTemp1 = (UINT8)((ucTemp1 << 1) & 0xFF);
			EEPROM_SERIAL_CLOCK_P = CLEAR;
		}
		else
		{	EEPROM_SERIAL_CLOCK_P = CLEAR;
			EEP_Loop_Delay(DEFAULT_DELAY_NUMBER);
			EEPROM_SERIAL_WRITE_P = CLEAR;
			return;
		}
	}
*/
}


UINT8 EEP_nBit_Read()
{
/*
	UINT8 ucTemp1 = WRITE_BIT_LENGTH;
	UINT8 ucRead_Data = 0;

	while(1)
	{

		EEPROM_CHIP_SELECT_INPUT_P = SET;
		EEP_Loop_Delay(DEFAULT_DELAY_NUMBER);

		EEPROM_SERIAL_CLOCK_P = SET;
		EEP_Loop_Delay(DEFAULT_DELAY_NUMBER);

		if(EEPROM_SERIAL_READ_P == SET)
		{	ucRead_Data |= 0x01;
		}
		else
		{	ucRead_Data &= 0xFE;
		}

		EEPROM_SERIAL_CLOCK_P = CLEAR;
		ucTemp1--;

		if(ucTemp1 != 0)
		{	ucRead_Data <<= 1;
		}
		else
		{	return (ucRead_Data);
		}

	}
*/
	return 0;
}



void EEP_Erase_Write_Enable(void)
{
/*
	EEPROM_CHIP_SELECT_INPUT_P = CLEAR;
	EEP_nBit_Write(0x80,3);

#if(EEPROM_TYPE == M93C86)

	EEP_nBit_Write(0xC0, 3);
	EEP_nBit_Write(0x00, 8);
#else
	EEP_nBit_Write(ENABLE_ORDER,8);
#endif

	EEPROM_CHIP_SELECT_INPUT_P = CLEAR;
}

void EEP_Erase_Write_Disable(void)
{
	EEPROM_CHIP_SELECT_INPUT_P = CLEAR;
	EEP_nBit_Write(0x80,3);

#if(EEPROM_TYPE == M93C86)
	EEP_nBit_Write(0x00,3);
#endif

	EEP_nBit_Write(0x00,8);
	EEPROM_CHIP_SELECT_INPUT_P = CLEAR;
*/
}


void EEP_Loop_Delay(UINT8 ucLoop_Number)
{
	while(ucLoop_Number > 0)
	{	ucLoop_Number--;
	}
}
