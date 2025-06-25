





#ifndef __FLASH_H__
#define __FLASH_H__



void SetCMDBuffer(UINT32*);
void HWI_FlashEraseSector(UINT32);


typedef enum
{
	CMD_FINISH_STEP,
	CMD_ERASE_STEP,
	CMD_WRITE_STEP,

}T_CMD_STEP;



typedef enum
{
	SIZE_OF_STX = 1,
	SIZE_OF_LENGTH = 2,

	SIZE_OF_FRAME_ID = 1,
	SIZE_OF_DOWNLOAD_ID = 1,

	SIZE_OF_CRC = 1,
	SIZE_OF_ETX = 1,

}T_PKT_LENGTH;



#define DATA_LEN 256L

#define PROGRAM_UNIT 4L

#define FLASH_SEQ_BASE 0x5E000000
#define FLASH_0_SEQ_54XX *((volatile UINT32*)(FLASH_SEQ_BASE + 0x005400))
#define FLASH_0_SEQ_AAXX *((volatile UINT32*)(FLASH_SEQ_BASE + 0x00AA00))


#define FLASH_CMD_AA	0xAA
#define FLASH_CMD_A0	0xA0
#define FLASH_CMD_10	0x10
#define FLASH_CMD_30	0x30
#define FLASH_CMD_40	0x40
#define FLASH_CMD_55	0x55
#define FLASH_CMD_80	0x80

#define NVIC_ISPR0	*((volatile UINT32*) (0xE000E200))
#define NVIC_ICPR0	*((volatile UINT32*) (0xE000E280))



#define INTRX0_BIT	0x0040
#define INTTX0_BIT	0x0080



T_CMD_STEP CMDErase(void);
T_CMD_STEP CMDWrite(void);
void HWI_FlashWrite(UINT32, UINT32*);
void HW_CheckBusy(void);


typedef T_CMD_STEP (*T_CMD_Step_Func)(void);
static const T_CMD_Step_Func mapfnFlashStepFunc[] =
{
	CMDErase,
	CMDWrite,
};


#endif
