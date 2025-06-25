#include <stdlib.h>
#include <string.h>


#define __LEDDISPLAY__
#include "../../3_Component/Include/Cmp_Display_Service.h"
#undef __LEDDISPLAY__

#include "../../3_Component/Include/Cmp_KeyScan.h"

#include "../../4_Library/Include/general.h"
#include "../../4_Library/Include/Int.h"
#include "../../4_Library/Include/Lib_UartComm.h"
#include "../../4_Library/Include/Lib_EEPROM.h"

#include "../../6_Vablesource/Include/Vable_ModelInformation.h"


UINT8 gu8Temp_Data[4];

void Cmp_Dsp_ValueSet(UINT16);
void Cmp_Dsp_Displaying(void);
UINT8 Lamp1sBlink(UINT8, UINT8);
UINT8 NumberToChar(UINT8);

const UINT8 Number_pattern[64] =
{
	//Number
	0x3F, 0x06, 0x5B, 0x4F, 0x66,	//	0, 1, 2, 3, 4
	0x6D, 0x7D, 0x27, 0x7F, 0x6F,	//	5, 6, 7, 8, 9
	0x77, 0x00, 0x39, 0x00, 0x79,	//	A, B, C, D, E
	0x71,				//	F
};
const UINT8 Aiphabet_pattern[64] =
{
	//Big Alphabet
	0x77, 0x7C, 0x39, 0x00, 0x79,	//	A, B, C, D, E
	0x71, 0x6F, 0x76, 0x06, 0x1F,	//	F, G, H, I, J
	0x00, 0x38, 0x00, 0x54, 0x3F,	//	K, L, M, N, O
	0x73, 0x67, 0x50, 0x6D, 0x78,	//	P, Q, R, S, T
	0x3E, 0x00, 0x00, 0x00, 0x66,	//	U, V, W, X, Y
	0x08,				//	Z
};


void Display_Service(UINT16 ucChecksum)
{
	Cmp_Dsp_ValueSet(ucChecksum);
	Cmp_Dsp_Displaying();
}

void Cmp_Dsp_ValueSet(UINT16 ucChecksum)
{
        memset(gu8Temp_Data, NULL, SIZE_OF_ARRAY(gu8Temp_Data));
        gu8Temp_Data[0] = NumberToChar(Get_JigPlatform());
}

void Cmp_Dsp_Displaying()
{
}

UINT8 Lamp1sBlink(UINT8 ucblinkOn, UINT8 ucblinkOff)
{
        return (timer_1s_calc() % 2 == 1 ? ucblinkOn : ucblinkOff);
}

UINT8 NumberToChar(UINT8 ucnumber)
{
    return (ucnumber < 16 ? Number_pattern[ucnumber] : Aiphabet_pattern[ucnumber - 65]);
}

