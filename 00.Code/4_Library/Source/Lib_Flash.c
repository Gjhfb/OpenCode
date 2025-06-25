


#include <stdlib.h>
#include <string.h>
/*************************************************/
/************************/



#include "../../4_Library/Include/general.h"


#define __FLASH_H
#include "../../4_Library/Include/Lib_Flash.h"
#undef __FLASH_H


static UINT32 maucWriteBuffer[2];



void SetCMDBuffer(UINT32* pstMemoryInfo)
{
	memcpy(maucWriteBuffer,pstMemoryInfo,sizeof(maucWriteBuffer));
}

T_CMD_STEP CMDErase(void)
{
	HWI_FlashEraseSector(0x58000);
	return CMD_WRITE_STEP;
}

T_CMD_STEP CMDWrite(void)
{
	HWI_FlashWrite(0x58000,maucWriteBuffer);
	return CMD_FINISH_STEP;
}

#pragma location = "RAMCODE"
void HWI_FlashEraseSector(UINT32 ulAdr)
{
    /*
	volatile UINT32* ADR_54XX;
	volatile UINT32* ADR_AAXX;
	volatile UINT8* BA_ADR;

	ADR_54XX = &FLASH_0_SEQ_54XX;
	ADR_AAXX = &FLASH_0_SEQ_AAXX;

	FC->AREASEL = 0x07;
	while(FC->AREASEL != 0x07){}

	ulAdr &= 0xFFFFC000;
	ulAdr |= 0x5E000000;
	BA_ADR = (volatile UINT8*) ulAdr;

	*ADR_AAXX = 0xF0;
	HW_CheckBusy();


	*ADR_54XX = FLASH_CMD_AA;
	*ADR_AAXX = FLASH_CMD_55;
	*ADR_54XX = FLASH_CMD_80;
	*ADR_54XX = FLASH_CMD_AA;
	*ADR_AAXX = FLASH_CMD_55;
	*BA_ADR	= FLASH_CMD_30;

	HW_CheckBusy();


	FC->AREASEL = 0x00;
	while(FC->AREASEL != 0x00){}

*/
}



#pragma location = "RAMCODE"
void HWI_FlashWrite(UINT32 ulAdr, UINT32* pulData)
{
/*
	int nLoop;
	int tLoop;

	volatile UINT32* ADR_54XX;
	volatile UINT32* ADR_AAXX;
	volatile UINT32* PA_ADR;



	ADR_54XX = &FLASH_0_SEQ_54XX;
	ADR_AAXX = &FLASH_0_SEQ_AAXX;

	ulAdr &= 0xFFFFFF00;
	ulAdr |= 0x5E000000;
	PA_ADR = (UINT32*) ulAdr;

	for(tLoop = 0; tLoop < (DATA_LEN/(PROGRAM_UNIT << 2)); tLoop++)
	{

		FC->AREASEL = 0x07;
		while(FC->AREASEL != 0x07){}

		*ADR_AAXX = 0xF0;									//Reset Flash
		HW_CheckBusy();


		*ADR_54XX = FLASH_CMD_AA;
		*ADR_AAXX = FLASH_CMD_55;
		*ADR_54XX = FLASH_CMD_A0;

		for(nLoop = 0; nLoop < PROGRAM_UNIT; nLoop++)
		{
			*PA_ADR = *pulData;
			pulData++;
		}

		PA_ADR += PROGRAM_UNIT;
		HW_CheckBusy();
		*ADR_AAXX = 0xF0;									//Reset Flash


		FC->AREASEL = 0x00;
		while(FC->AREASEL != 0x00){}

	}
*/
}

#pragma location = "RAMCODE"
void HW_CheckBusy(void)
{
//	for(; FC->PSR0 & 0x01 == 0;){};
}

UINT8 UART_CrcMaker(UINT8* pucBuffer, UINT16 unLength)
{
	UINT16 unIndex = 0;
	UINT8 ucCrc = 0;

	for(; unIndex < unLength; unIndex++)
	{
		ucCrc += *pucBuffer++;
	}
	return (ucCrc ^ 0x55);
}




