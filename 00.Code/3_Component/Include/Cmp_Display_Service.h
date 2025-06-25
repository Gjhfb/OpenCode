



#include "../../4_Library/Include/general.h"

#ifndef _LED_DIS_SERVICE_
#define _LED_DIS_SERVICE_

#ifdef __LEDDISPLAY__
#define EXTR
#else
#define EXTR extern
#endif

EXTR TYPE_WORD gu8LED_Data[4];

EXTR void Display_Service(UINT16);

#undef  EXTR
#endif

