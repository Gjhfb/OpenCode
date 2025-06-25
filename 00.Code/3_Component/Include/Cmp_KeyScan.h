






#include "../../4_Library/Include/general.h"



#ifdef __KEYSCAN_H__
#define EXTR
#else
#define EXTR extern
#endif

#define POWER_KEY		1
#define START_PAUSE_KEY	2

enum
{
	NO_KEY,					//	0
	CHOOSE_KEY_augment,		//	1
	CHOOSE_KEY_subtract,	//	2
	CONFIRM_KEY,			//	3
	LONGCONFIRM_KEY,		//	4
	ONBOARDING_KEY,			//	5
	LONGONBOARDING_KEY,		//	6

	OptionBeepKey = 0x3F,
};

void KeyScan(void);

void No_Key(void);
void InputProc_AugmentKey(void);
void InputProc_SubtractKey(void);
void InputProc_ConfirmKey(void);
void InputProc_OnBoardingKey(void);
void InputProc_LongConfirmKey(void);
void InputProc_LongOnBoardingKey(void);


void Set_Platform(UINT8);
UINT8 Get_Key(void);
UINT8 Get_Platform(void);


#undef EXTR


