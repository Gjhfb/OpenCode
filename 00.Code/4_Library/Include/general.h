/**********************

#define HAL_GPIO_MODULE_ENABLED

#ifndef	__SILS__

typedef	unsigned	long	UINT32;
typedef	signed		long	INT32;

#else

#pragma once
typedef	unsigned	int		UINT32;
typedef	signed		int		INT32;

#endif

typedef	float		FLOAT32;
typedef	double		FLOAT64;


#define	IOB8(x)	(((0x##x##L & 0x00000001L) >> 0)\
				|((0x##x##L & 0x00000010L) >> 3)\
				|((0x##x##L & 0x00000100L) >> 6)\
				|((0x##x##L & 0x00001000L) >> 9)\
				|((0x##x##L & 0x00010000L) >> 12)\
				|((0x##x##L & 0x00100000L) >> 15)\
				|((0x##x##L & 0x01000000L) >> 18)\
				|((0x##x##L & 0x10000000L) >> 21))





#define	IOB16(y)	(((0x##y##L & 0x0000000000000001LL) >> 0)\
					|((0x##y##L & 0x0000000000000010L) >> 3)\
					|((0x##y##L & 0x0000000000000100L) >> 6)\
					|((0x##y##L & 0x0000000000001000L) >> 9)\
					|((0x##y##L & 0x0000000000010000L) >> 12)\
					|((0x##y##L & 0x0000000000100000L) >> 15)\
					|((0x##y##L & 0x0000000001000000L) >> 18)\
					|((0x##y##L & 0x0000000010000000L) >> 21)\
					|((0x##y##L & 0x0000000100000000L) >> 24)\
					|((0x##y##L & 0x0000001000000000L) >> 27)\
					|((0x##y##L & 0x0000010000000000L) >> 30)\
					|((0x##y##L & 0x0000100000000000L) >> 33)\
					|((0x##y##L & 0x0001000000000000L) >> 36)\
					|((0x##y##L & 0x0010000000000000L) >> 39)\
					|((0x##y##L & 0x0100000000000000L) >> 42)\
					|((0x##y##L & 0x1000000000000000L) >> 45))


**************************/

#ifndef _GENERAL_H_
#define _GENERAL_H_


#ifdef	AUTOUB_TESTING_MODE
#define CONST
#else
#define CONST const
#endif



/************************************************/

typedef	unsigned	char	U8;
typedef	unsigned	char	UINT8;
typedef	signed		char	INT8;
typedef	unsigned	short	UINT16;
typedef	signed		short	INT16;

#ifndef	__SILS__
typedef	unsigned	long	UINT32;
typedef	signed		long	INT32;
#else
typedef	unsigned	int	UINT32;
typedef	signed		int	INT32;
#endif



#define BIN4(a)	( /*1*/ ( /*2*/ ( /*3*/ 0x ## a ## L & 0x00000001L /*3*/ ) >> 0 /*2*/ ) \
		|          ( /*2*/ ( /*3*/ 0x ## a ## L & 0x00000010L /*3*/ ) >> 3 /*2*/ ) \
		|          ( /*2*/ ( /*3*/ 0x ## a ## L & 0x00000100L /*3*/ ) >> 6 /*2*/ ) \
		|          ( /*2*/ ( /*3*/ 0x ## a ## L & 0x00001000L /*3*/ ) >> 9 /*2*/ ))

#define BIN8(a,b)\
	( /*1*/ (uint8_t)( /*2*/ ( /*3*/ ( /*4*/ 0x0F & ( /*5*/ BIN4(a) /*5*/ ) /*4*/ ) << 4 /*3*/ ) | ( /*6*/ 0x0F & ( /*7*/ BIN4(b) /*7*/ ) /*6*/ ) /*2*/ ) /*1*/ )

#define BIN16(a,b,c,d)\
	( /*1*/ (uint16_t)( /*2*/ ( /*3*/ ( /*4*/ 0x00FF & ( /*5*/ (uint16_t) BIN8(a,b) /*5*/ ) /*4*/ ) << 8 /*3*/ ) | ( /*6*/ 0x00FF & ( /*7*/ (uint16_t) BIN8(c,d) /*7*/ ) /*6*/ ) /*2*/ ) /*1*/ )

#define BIN32(a,b,c,d,e,f,g,h)\
	( /*1*/ (uint32_t)( /*2*/ ( /*3*/ ( /*4*/ 0x0000FFFF & ( /*5*/ (uint32_t) BIN16(a,b,c,d) /*5*/ ) /*4*/ ) << 16 /*3*/ ) | ( /*6*/ 0x0000FFFF & ( /*7*/ (uint32_t) BIN16(e,f,g,h) /*7*/ ) /*6*/ ) /*2*/ ) /*1*/ )


/************************************************/


typedef union
{
	unsigned char BYTE;
	struct
	{
		unsigned char B7:1;
		unsigned char B6:1;
		unsigned char B5:1;
		unsigned char B4:1;
		unsigned char B3:1;
		unsigned char B2:1;
		unsigned char B1:1;
		unsigned char B0:1;
	}BIT;
}T_UByteBit;

typedef struct
{
	UINT16 RealDspOption;
	UINT16 RecvDspOption;
	UINT16 RecvPCOption;
}T_OptionInfo;

typedef struct
{
	UINT8* pstSendBuffer;
	UINT8* pstRecvBuffer;
	UINT8 ucStx;
	UINT8 ucEtx;
}T_BufferDef;

typedef void (*RPC_SEND_PACKET_TYPE)(UINT8);
typedef void (*RPC_RECV_PACKET_TYPE)(UINT8);

typedef struct
{
	RPC_SEND_PACKET_TYPE pSendFunc;
	RPC_RECV_PACKET_TYPE pRecvFunc;
}T_UartCommDef;

typedef struct
{
	unsigned char b7:1;
	unsigned char b6:1;
	unsigned char b5:1;
	unsigned char b4:1;
	unsigned char b3:1;
	unsigned char b2:1;
	unsigned char b1:1;
	unsigned char b0:1;

	unsigned char b15:1;
	unsigned char b14:1;
	unsigned char b13:1;
	unsigned char b12:1;
	unsigned char b11:1;
	unsigned char b10:1;
	unsigned char b9:1;
	unsigned char b8:1;
}WORD_FIELD;

typedef union
{
	unsigned int	word;
	unsigned char	byte[2];
	WORD_FIELD		bit;
}TYPE_WORD;


typedef struct
{
	UINT32 ulLow;
}T_Time;


typedef enum
{
//	SCCR_Registers.MCLKSEL
	LSI	= 0,		LSE = 1,		HSI	= 2,			HSE	= 6,		PLL	= 7,
//	COR_Registers.CLKOINSEL
	LSI_COR	= 0,	LSE_COR	= 1,	MCLK_COR	= 2,	HSI_COR	= 3,	HSE_COR	= 4,	PLL_COR	= 5,

}T_SCU_Register;


typedef enum
{
//	MR1_Registers
//	MR2_Registers
	Func_0		= 0,	Func_1		= 1,	Func_2		= 2,	Func_3	= 3,	Func_7	= 7,
//	CR_Registers
	PP_Output	= 0,	OD_Output	= 1,	Input		= 2,
//	PRCR_Registers
	DisPu_DisPd	= 0,	EnPu_DisPd	= 1,	DisPu_EnPd	= 2,

}T_GPIO_Register;





enum
{
	CLR					= 0,	SET					= 1,

	OFF					= 0,	ON					= 1,

	DISABLE				= 0,	ENABLE				= 1,

	RETURN_NG			= 0,	RETURN_OK			= 1,

	WRITE				= 0,	READ				= 1,

	DOOR_OPEN			= 0,	DOOR_CLOSE			= 1,

	EN_ONBOARD			= 0,	DIS_ONBOARD			= 1,

	FAIL    			= 0,	SUCCESS	        	= 1,

	SUB_STE_STANDBY		= 0,	SUB_STE_INITIAL		= 1,	STATE_LQCTEST		= 2,

	NT_DOOR_Sensing		= 0,	NT_DOOR_OPEN		= 1,	NT_DOOR_CLOSE		= 2,
};



#endif


//#define SET_BIT(REG, BIT)     ((REG) |= (BIT))
#define MIN_Limite(X, MINlimit, MAXlimit)	((X) < (MINlimit) ? (X) = MAXlimit : (X))
#define MAX_Limite(X, MINlimit, MAXlimit)	((X) > (MAXlimit) ? (X) = MINlimit : (X))
#define CounterAddLimite(X, MIN, MAX)           ((X) < MAX ? ++X : (X = MIN))

#define SIZE_OF_ARRAY(Variable) (sizeof(Variable) / sizeof(Variable[0]))

#define GET_HIGH_1BYTE(Data)		((UINT8)((Data) >> 8))
#define GET_LOW_1BYTE(Data)			((UINT8)((Data) & 0xFF))




