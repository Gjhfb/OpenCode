#include <stdio.h>
#include <stdint.h>
#include <string.h>


#define __KEYSCAN_H_
#include "../../3_Component/Include/Cmp_KeyScan.h"
#undef __KEYSCAN_H_

#include "../../3_Component/Include/Cmp_SetError.h"

#include "../../4_Library/Include/general.h"
#include "../../4_Library/Include/Int.h"


#include "../../6_Vablesource/Include/Vable_ModelInformation.h"

UINT8 gunKey_Confirm = NO_KEY;
INT8 Platform = Yellow;

typedef struct T_KEY_StructList
{
	UINT8 stSelectedKey;
	void (*KeyFunction)(void);
}T_KEY_Struct;


static const T_KEY_Struct mastKeyTable[] =
{
	{BIN8(0000,0000),	No_Key,								},
	{BIN8(0000,0001),	InputProc_AugmentKey,			},
	{BIN8(0000,0010),	InputProc_ConfirmKey,			},
	{BIN8(0000,0100),	No_Key,								},
	{BIN8(0000,1000),	No_Key,								},
	{BIN8(0001,0000),	No_Key,								},
	{BIN8(0010,0000),	InputProc_LongConfirmKey,		},
};



void KeyScan()
{
	UINT8 i = 0;
	for(i = 0; i <= (sizeof(mastKeyTable) / sizeof(T_KEY_Struct) - 1); i++)
	{
		if(gunKey_New == mastKeyTable[i].stSelectedKey)
		{
			gunKey_New = CLR;
			mastKeyTable[i].KeyFunction();
		}
		else
		{;}
	}

	MIN_Limite(Platform, 0, 5);
	MAX_Limite(Platform, 0, 5);
}



void No_Key()
{
	;
}

void InputProc_AugmentKey()
{
	if(gunKey_Confirm != CONFIRM_KEY)
	{
		gunKey_Confirm = CHOOSE_KEY_augment;
		Platform++;
	}
	else
	{	;
	}
}

void InputProc_SubtractKey()
{
	if(gunKey_Confirm != CONFIRM_KEY)
	{
		gunKey_Confirm = CHOOSE_KEY_subtract;
		Platform--;
	}
	else
	{	;
	}
}

void InputProc_ConfirmKey()
{
	gunKey_Confirm = CONFIRM_KEY;


}

void InputProc_LongConfirmKey()
{
	gunKey_Confirm = LONGCONFIRM_KEY;
}

void InputProc_OnBoardingKey()
{
	;
}

void InputProc_LongOnBoardingKey()
{
	if(Platform == 0)
	{
		ErrorCheckFlag = CLR;
	}
	else
	{;}
}
void Set_Platform(UINT8 ucPlatform)
{
	Platform = ucPlatform;
}

UINT8 Get_Key(void)
{
	return gunKey_Confirm;
}

UINT8 Get_JigPlatform(void)
{
	return Platform;
}


