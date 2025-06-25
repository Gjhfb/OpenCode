


#include <stdlib.h>
#include <string.h>
/*************************************************/
/************************/

#include "../../3_Component/Include/Cmp_KeyScan.h"


#include "../../4_Library/Include/general.h"
#include "../../4_Library/Include/Lib_LCD.h"
#include "../../4_Library/Include/Lib_Flash.h"

#include "../../4_Library/Include/Int.h"

#include "../../6_Vablesource/Include/Vable_ModelInformation.h"


const UINT8 Init_Lcd_0[1]	= {0x00};

const UINT8 Init_Lcd_1[1]	= {0x00};

const UINT8 Init_Lcd_2[1]	= {0x11};

const UINT8 Init_Lcd_3[1]	= {0x21};

const UINT8 Init_Lcd_4[4]	= {0xB1, 0x05, 0x3A, 0x3A};

const UINT8 Init_Lcd_5[4]	= {0xB2, 0x05, 0x3A, 0x3A};

const UINT8 Init_Lcd_6[7]	= {0xB3, 0x05, 0x3A, 0x3A, 0x05, 0x3A, 0x3A};

const UINT8 Init_Lcd_7[2]	= {0xB4, 0x03};

const UINT8 Init_Lcd_8[4]	= {0xC0, 0x62, 0x02, 0x04};

const UINT8 Init_Lcd_9[2]	= {0xC1, 0xC0};

const UINT8 Init_Lcd_10[3]	= {0xC2, 0x0D, 0x0D};

const UINT8 Init_Lcd_11[3]	= {0xC3, 0x8D, 0x6A};

const UINT8 Init_Lcd_12[3]	= {0xC4, 0x8D, 0xEE};

const UINT8 Init_Lcd_13[2]	= {0xC5, 0x0E};

const UINT8 Init_Lcd_14[17]	= {0xE0, 0x10, 0x0E, 0x02, 0x03, 0x0E, 0x07, 0x02, 0x07, 0x0A, 0x12, 0x27, 0x37, 0x00, 0x0D, 0x0E, 0x10};

const UINT8 Init_Lcd_15[17]	= {0xE1, 0x10, 0x0E, 0x03, 0x03, 0x0F, 0x06, 0x02, 0x08, 0x0A, 0x13, 0x26, 0x36, 0x00, 0x0D, 0x0E, 0x10};

const UINT8 Init_Lcd_16[2]	= {0x3A, 0x05};

const UINT8 Init_Lcd_17[2]	= {0x36, 0xA8};

const UINT8 Init_Lcd_18[1]	= {0x29};



#define X_Size			160
#define Y_Size			80

const UINT8 Init_Lcd_Size_0[5]	= {0x2a, 0x00, 0x01, 		0x00, X_Size		};

const UINT8 Init_Lcd_Size_1[5]	= {0x2b, 0x00, 0x00 + 0x1A, 0x00, Y_Size - 1 + 0x1A	};

const UINT8 Init_Lcd_BackGrd_0[2]	= {0x2c, 0x2c};



extern const UINT16 BaseColor[6];



T_Device_Step Cmp_LCD_Display(void);
void Cmp_LCD_Next_Step(void);
void delay(void);




T_Device_Step Cmp_Lcd_Init(void);
T_Device_Step Cmp_Init_Lcd_LcdSize(void);
T_Device_Step Cmp_Init_Lcd_BackGrd(void);
T_Device_Step Cmp_Set_LcdSize(void);
T_Device_Step Cmp_Set_LcdData(void);

static T_Device_Step (* const mapfnLcdControlStepTbl[]) (void) =
{
	Cmp_Lcd_Init,
	Cmp_Init_Lcd_LcdSize,
	Cmp_Init_Lcd_BackGrd,
	Cmp_Set_LcdSize,
	Cmp_Set_LcdData,
};


void Cmp_Lcd_Control()
{

	LCD_Device.Device_Step = mapfnLcdControlStepTbl[LCD_Device.Device_Step]();

	//LCD_Step = Cmp_LCD_Display();
}

T_Device_Step Cmp_LCD_Display(void)
{




	return Device_Index_3;
}

void Cmp_LCD_Next_Step()
{
	switch(LCD_Device.Comm_Step)
	{
		case Serial_Start:
			LCD_Device.Comm_Step = Serial_Write_mode;
			break;

		case Serial_Write_mode:
			*LCD_Device.ChipS_Pin = CLR;
			LCD_Device.Comm_Step = Serial_TX_Adr;
			break;

		case Serial_TX_Adr:
			if(LCD_Device.T_Serial_Packet.Adr_Size == 0)
			{
				*LCD_Device.ChipS_Pin = SET;
				LCD_Device.Comm_Step = Serial_TX_DATA;
			}
			break;

		case Serial_TX_DATA:
			if(LCD_Device.T_Serial_Packet.Data_Size == 0)
			{
				LCD_Device.Comm_Step = Serial_Stop;
			}
			else
			{	;
			}
			break;

		case Serial_Stop:
			LCD_Device.Comm_Request = Serial_Sleep;
			break;

	}

}

T_Device_Step Cmp_Lcd_Init()
{
	static UINT8 LCD_Init = 0;
	switch(LCD_Init)
	{
		case 0:
			LCD_Device.Device_Type			= SPI;

			LCD_Device.Eable_Pin			= &GPIO_ODR(F, 5);	//	RESET	15.PF5_RXD5
			LCD_Device.Clock_Pin			= &GPIO_ODR(E, 3);	//	SCL		16.PE3_SCL0
			LCD_Device.ChipS_Pin			= &GPIO_ODR(F, 4);	//	RS		14.PF4_TXD5
			LCD_Device.DataW_Pin			= &GPIO_ODR(E, 4);	//	SDA		17.PE4_SDA0
			LCD_Device.DataR_Pin			= NULL;

			LCD_Device.Write_Pin_state		= &GPIO_CR_2(E, 4);
			*LCD_Device.Write_Pin_state		= ((OD_Output >> 1) & 0x01);

			LCD_Device.Read_Pin_state		= NULL;
			*LCD_Device.Read_Pin_state		= NULL;


			LCD_Device.Device_NextStep		= Cmp_LCD_Next_Step;

			LCD_Device.EchoReq				= NONE;

			LCD_Device.T_Serial_Packet.Adr_Size		= 0;
			LCD_Device.T_Serial_Packet.Data_Size	= 0;
			LCD_Init++;
			break;


		case 1:
			*LCD_Device.Eable_Pin = CLR;
			delay();
			*LCD_Device.Eable_Pin = SET;
			delay();
			LCD_Device.T_Serial_Packet.Adr_Size		= 0;
			LCD_Device.T_Serial_Packet.Data_Size	= 0;
			LCD_Init++;
			break;

		case 2:
			LCD_Device.Comm_Request		= Serial_Oneshot;
			LCD_Device.Comm_Step		= Serial_Start;

			LCD_Device.T_Serial_Packet.Adr[0]	= Init_Lcd_2[0];	//	RS		14.PF4_TXD5
			LCD_Device.T_Serial_Packet.Adr_Size		= 1;
			LCD_Device.T_Serial_Packet.Adr_Index	= 0;
			LCD_Init++;
			break;

		case 3:
			if(LCD_Device.Comm_Request == Serial_Sleep)
			{
				LCD_Device.Comm_Request 	= Serial_Oneshot;
				LCD_Device.Comm_Step		= Serial_Start;
				LCD_Device.T_Serial_Packet.Adr[0]	= Init_Lcd_3[0];
				LCD_Device.T_Serial_Packet.Adr_Size		= 1;
				LCD_Device.T_Serial_Packet.Adr_Index	= 0;
				LCD_Init++;
			}
			break;

		case 4:
			if(LCD_Device.Comm_Request == Serial_Sleep)
			{
				LCD_Device.Comm_Request 	= Serial_Oneshot;
				LCD_Device.Comm_Step		= Serial_Start;
				LCD_Device.T_Serial_Packet.Adr_Size		= 1;
				LCD_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( LCD_Device.T_Serial_Packet.Adr, Init_Lcd_4, SIZE_OF_ARRAY(Init_Lcd_4) );

				LCD_Device.T_Serial_Packet.Data_Size	= 3;
				LCD_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( LCD_Device.T_Serial_Packet.Data, Init_Lcd_4, SIZE_OF_ARRAY(Init_Lcd_4) );
				LCD_Init++;
			}
			break;

		case 5:
			if(LCD_Device.Comm_Request == Serial_Sleep)
			{
				LCD_Device.Comm_Request 	= Serial_Oneshot;
				LCD_Device.Comm_Step		= Serial_Start;
				LCD_Device.T_Serial_Packet.Adr_Size		= 1;
				LCD_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( LCD_Device.T_Serial_Packet.Adr, Init_Lcd_5, SIZE_OF_ARRAY(Init_Lcd_5) );

				LCD_Device.T_Serial_Packet.Data_Size	= 3;
				LCD_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( LCD_Device.T_Serial_Packet.Data, Init_Lcd_5, SIZE_OF_ARRAY(Init_Lcd_5) );
				LCD_Init++;
			}
			break;

		case 6:
			if(LCD_Device.Comm_Request == Serial_Sleep)
			{
				LCD_Device.Comm_Request 	= Serial_Oneshot;
				LCD_Device.Comm_Step		= Serial_Start;
				LCD_Device.T_Serial_Packet.Adr_Size		= 1;
				LCD_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( LCD_Device.T_Serial_Packet.Adr, Init_Lcd_6, SIZE_OF_ARRAY(Init_Lcd_6) );

				LCD_Device.T_Serial_Packet.Data_Size	= 6;
				LCD_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( LCD_Device.T_Serial_Packet.Data, Init_Lcd_6, SIZE_OF_ARRAY(Init_Lcd_6) );
				LCD_Init++;
			}
			break;

		case 7:
			if(LCD_Device.Comm_Request == Serial_Sleep)
			{
				LCD_Device.Comm_Request 	= Serial_Oneshot;
				LCD_Device.Comm_Step		= Serial_Start;
				LCD_Device.T_Serial_Packet.Adr_Size		= 1;
				LCD_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( LCD_Device.T_Serial_Packet.Adr, Init_Lcd_7, SIZE_OF_ARRAY(Init_Lcd_7) );

				LCD_Device.T_Serial_Packet.Data_Size	= 1;
				LCD_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( LCD_Device.T_Serial_Packet.Data, Init_Lcd_7, SIZE_OF_ARRAY(Init_Lcd_7) );
				LCD_Init++;
			}
			break;

		case 8:
			if(LCD_Device.Comm_Request == Serial_Sleep)
			{
				LCD_Device.Comm_Request 	= Serial_Oneshot;
				LCD_Device.Comm_Step		= Serial_Start;
				LCD_Device.T_Serial_Packet.Adr_Size		= 1;
				LCD_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( LCD_Device.T_Serial_Packet.Adr, Init_Lcd_8, SIZE_OF_ARRAY(Init_Lcd_8) );

				LCD_Device.T_Serial_Packet.Data_Size	= 3;
				LCD_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( LCD_Device.T_Serial_Packet.Data, Init_Lcd_8, SIZE_OF_ARRAY(Init_Lcd_8) );
				LCD_Init++;
			}
			break;

		case 9:
			if(LCD_Device.Comm_Request == Serial_Sleep)
			{
				LCD_Device.Comm_Request 	= Serial_Oneshot;
				LCD_Device.Comm_Step		= Serial_Start;
				LCD_Device.T_Serial_Packet.Adr_Size		= 1;
				LCD_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( LCD_Device.T_Serial_Packet.Adr, Init_Lcd_9, SIZE_OF_ARRAY(Init_Lcd_9) );

				LCD_Device.T_Serial_Packet.Data_Size	= 1;
				LCD_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( LCD_Device.T_Serial_Packet.Data, Init_Lcd_9, SIZE_OF_ARRAY(Init_Lcd_9) );
				LCD_Init++;
			}
			break;

		case 10:
			if(LCD_Device.Comm_Request == Serial_Sleep)
			{
				LCD_Device.Comm_Request 	= Serial_Oneshot;
				LCD_Device.Comm_Step		= Serial_Start;
				LCD_Device.T_Serial_Packet.Adr_Size		= 1;
				LCD_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( LCD_Device.T_Serial_Packet.Adr, Init_Lcd_10, SIZE_OF_ARRAY(Init_Lcd_10) );

				LCD_Device.T_Serial_Packet.Data_Size	= 2;
				LCD_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( LCD_Device.T_Serial_Packet.Data, Init_Lcd_10, SIZE_OF_ARRAY(Init_Lcd_10) );
				LCD_Init++;
			}
			break;

		case 11:
			if(LCD_Device.Comm_Request == Serial_Sleep)
			{
				LCD_Device.Comm_Request 	= Serial_Oneshot;
				LCD_Device.Comm_Step		= Serial_Start;
				LCD_Device.T_Serial_Packet.Adr_Size		= 1;
				LCD_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( LCD_Device.T_Serial_Packet.Adr, Init_Lcd_11, SIZE_OF_ARRAY(Init_Lcd_11) );

				LCD_Device.T_Serial_Packet.Data_Size	= 2;
				LCD_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( LCD_Device.T_Serial_Packet.Data, Init_Lcd_11, SIZE_OF_ARRAY(Init_Lcd_11) );
				LCD_Init++;
			}
			break;

		case 12:
			if(LCD_Device.Comm_Request == Serial_Sleep)
			{
				LCD_Device.Comm_Request 	= Serial_Oneshot;
				LCD_Device.Comm_Step		= Serial_Start;
				LCD_Device.T_Serial_Packet.Adr_Size		= 1;
				LCD_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( LCD_Device.T_Serial_Packet.Adr, Init_Lcd_12, SIZE_OF_ARRAY(Init_Lcd_12) );

				LCD_Device.T_Serial_Packet.Data_Size	= 2;
				LCD_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( LCD_Device.T_Serial_Packet.Data, Init_Lcd_12, SIZE_OF_ARRAY(Init_Lcd_12) );
				LCD_Init++;
			}
			break;

		case 13:
			if(LCD_Device.Comm_Request == Serial_Sleep)
			{
				LCD_Device.Comm_Request 	= Serial_Oneshot;
				LCD_Device.Comm_Step		= Serial_Start;
				LCD_Device.T_Serial_Packet.Adr_Size		= 1;
				LCD_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( LCD_Device.T_Serial_Packet.Adr, Init_Lcd_13, SIZE_OF_ARRAY(Init_Lcd_13) );

				LCD_Device.T_Serial_Packet.Data_Size	= 1;
				LCD_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( LCD_Device.T_Serial_Packet.Data, Init_Lcd_13, SIZE_OF_ARRAY(Init_Lcd_13) );
				LCD_Init++;
			}
			break;

		case 14:
			if(LCD_Device.Comm_Request == Serial_Sleep)
			{
				LCD_Device.Comm_Request 	= Serial_Oneshot;
				LCD_Device.Comm_Step		= Serial_Start;
				LCD_Device.T_Serial_Packet.Adr_Size		= 1;
				LCD_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( LCD_Device.T_Serial_Packet.Adr, Init_Lcd_14, SIZE_OF_ARRAY(Init_Lcd_14) );

				LCD_Device.T_Serial_Packet.Data_Size	= 16;
				LCD_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( LCD_Device.T_Serial_Packet.Data, Init_Lcd_14, SIZE_OF_ARRAY(Init_Lcd_14) );
				LCD_Init++;
			}
			break;

		case 15:
			if(LCD_Device.Comm_Request == Serial_Sleep)
			{
				LCD_Device.Comm_Request 	= Serial_Oneshot;
				LCD_Device.Comm_Step		= Serial_Start;
				LCD_Device.T_Serial_Packet.Adr_Size		= 1;
				LCD_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( LCD_Device.T_Serial_Packet.Adr, Init_Lcd_15, SIZE_OF_ARRAY(Init_Lcd_15) );

				LCD_Device.T_Serial_Packet.Data_Size	= 16;
				LCD_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( LCD_Device.T_Serial_Packet.Data, Init_Lcd_15, SIZE_OF_ARRAY(Init_Lcd_15) );
				LCD_Init++;
			}
			break;

		case 16:
			if(LCD_Device.Comm_Request == Serial_Sleep)
			{
				LCD_Device.Comm_Request 	= Serial_Oneshot;
				LCD_Device.Comm_Step		= Serial_Start;
				LCD_Device.T_Serial_Packet.Adr_Size		= 1;
				LCD_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( LCD_Device.T_Serial_Packet.Adr, Init_Lcd_16, SIZE_OF_ARRAY(Init_Lcd_16) );

				LCD_Device.T_Serial_Packet.Data_Size	= 1;
				LCD_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( LCD_Device.T_Serial_Packet.Data, Init_Lcd_16, SIZE_OF_ARRAY(Init_Lcd_16) );
				LCD_Init++;
			}
			break;

		case 17:
			if(LCD_Device.Comm_Request == Serial_Sleep)
			{
				LCD_Device.Comm_Request 	= Serial_Oneshot;
				LCD_Device.Comm_Step		= Serial_Start;
				LCD_Device.T_Serial_Packet.Adr_Size		= 1;
				LCD_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( LCD_Device.T_Serial_Packet.Adr, Init_Lcd_17, SIZE_OF_ARRAY(Init_Lcd_17) );

				LCD_Device.T_Serial_Packet.Data_Size	= 1;
				LCD_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( LCD_Device.T_Serial_Packet.Data, Init_Lcd_17, SIZE_OF_ARRAY(Init_Lcd_17) );
				LCD_Init++;
			}
			break;

		case 18:
			if(LCD_Device.Comm_Request == Serial_Sleep)
			{
				LCD_Device.Comm_Request 	= Serial_Oneshot;
				LCD_Device.Comm_Step		= Serial_Start;
				LCD_Device.T_Serial_Packet.Adr_Size		= 1;
				LCD_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( LCD_Device.T_Serial_Packet.Adr, Init_Lcd_18, SIZE_OF_ARRAY(Init_Lcd_18) );

				LCD_Device.T_Serial_Packet.Data_Size	= 0;
				LCD_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( LCD_Device.T_Serial_Packet.Data, Init_Lcd_18, SIZE_OF_ARRAY(Init_Lcd_18) );
				LCD_Init++;
			}
			break;
		case 19:
		default:
			return Device_Index_1;
			break;
	}

	return Initial_Dev_0;
}




T_Device_Step Cmp_Init_Lcd_LcdSize()
{
	static UINT8 LCD_Init = 0;

	switch(LCD_Init)
	{
		case 0:
			if(LCD_Device.Comm_Request == Serial_Sleep)
			{
				LCD_Device.Comm_Request 	= Serial_Oneshot;
				LCD_Device.Comm_Step		= Serial_Start;
				LCD_Device.T_Serial_Packet.Adr_Size 	= 1;
				LCD_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( LCD_Device.T_Serial_Packet.Adr, Init_Lcd_Size_0, SIZE_OF_ARRAY(Init_Lcd_Size_0) );

				LCD_Device.T_Serial_Packet.Data_Size	= 4;
				LCD_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( LCD_Device.T_Serial_Packet.Data, Init_Lcd_Size_0, SIZE_OF_ARRAY(Init_Lcd_Size_0) );
				LCD_Init++;
			}
			break;

		case 1:
			if(LCD_Device.Comm_Request == Serial_Sleep)
			{
				LCD_Device.Comm_Request 	= Serial_Oneshot;
				LCD_Device.Comm_Step		= Serial_Start;
				LCD_Device.T_Serial_Packet.Adr_Size 	= 1;
				LCD_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( LCD_Device.T_Serial_Packet.Adr, Init_Lcd_Size_1, SIZE_OF_ARRAY(Init_Lcd_Size_1) );

				LCD_Device.T_Serial_Packet.Data_Size	= 4;
				LCD_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( LCD_Device.T_Serial_Packet.Data, Init_Lcd_Size_1, SIZE_OF_ARRAY(Init_Lcd_Size_1) );
				LCD_Init++;
			}
			break;

		case 2:
			return Device_Index_2;
			break;

	}


	return Device_Index_1;
}


T_Device_Step Cmp_Init_Lcd_BackGrd()
{
	static UINT8 LCD_Init = 0;

	switch(LCD_Init)
	{
		case 0:
			if(LCD_Device.Comm_Request == Serial_Sleep)
			{
				LCD_Device.Comm_Request 	= Serial_Oneshot;
				LCD_Device.Comm_Step		= Serial_Start;
				LCD_Device.T_Serial_Packet.Adr_Size 	= 2;
				LCD_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( LCD_Device.T_Serial_Packet.Adr, Init_Lcd_BackGrd_0, SIZE_OF_ARRAY(Init_Lcd_BackGrd_0) );

				LCD_Device.T_Serial_Packet.Data_Size	= 0;
				LCD_Device.T_Serial_Packet.Data_Index	= 0;
				LCD_Init++;
			}
			break;

		default:
		case 1:
			if(LCD_Device.Comm_Request == Serial_Sleep)
			{
				LCD_Device.Comm_Request 	= Serial_Oneshot;
				LCD_Device.Comm_Step		= Serial_Start;
				LCD_Device.T_Serial_Packet.Adr_Size 	= 0;
				LCD_Device.T_Serial_Packet.Adr_Index	= 0;

				LCD_Device.T_Serial_Packet.Data_Size	= X_Size * 2;
				LCD_Device.T_Serial_Packet.Data_Index	= 0;
				for(UINT8 Loop = 0; Loop < X_Size; Loop++)
				{
					LCD_Device.T_Serial_Packet.Data[(Loop * 2)]		= (UINT8)(BaseColor[Get_JigPlatform()] >> 8);
					LCD_Device.T_Serial_Packet.Data[(Loop * 2) + 1]	= (UINT8)(BaseColor[Get_JigPlatform()] & 0xFF);
				}

				LCD_Init++;
			}

			if(LCD_Init == (Y_Size + 1))
			{
			    	LCD_Init = 0;
				return Device_Index_3;
			}

			break;
	}

	return	Device_Index_2;
}

T_Device_Step Cmp_Set_LcdSize()
{
	static UINT8 LCD_Init = 0;

/*
	switch(LCD_Init)
	{
		case 0:
			if(LCD_Device.Comm_Request == Serial_Sleep)
			{
				LCD_Device.Comm_Request 	= Serial_Oneshot;
				LCD_Device.Comm_Step		= Serial_Start;
				LCD_Device.T_Serial_Packet.Adr_Size 	= 1;
				LCD_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( LCD_Device.T_Serial_Packet.Adr, Init_Lcd_Size_0, SIZE_OF_ARRAY(Init_Lcd_Size_0) );

				LCD_Device.T_Serial_Packet.Data_Size	= 4;
				LCD_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( LCD_Device.T_Serial_Packet.Data, Init_Lcd_Size_0, SIZE_OF_ARRAY(Init_Lcd_Size_0) );
				LCD_Init++;
			}
			break;

		case 1:
			if(LCD_Device.Comm_Request == Serial_Sleep)
			{
				LCD_Device.Comm_Request 	= Serial_Oneshot;
				LCD_Device.Comm_Step		= Serial_Start;
				LCD_Device.T_Serial_Packet.Adr_Size 	= 1;
				LCD_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( LCD_Device.T_Serial_Packet.Adr, Init_Lcd_Size_1, SIZE_OF_ARRAY(Init_Lcd_Size_1) );

				LCD_Device.T_Serial_Packet.Data_Size	= 4;
				LCD_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( LCD_Device.T_Serial_Packet.Data, Init_Lcd_Size_1, SIZE_OF_ARRAY(Init_Lcd_Size_1) );
				LCD_Init++;
			}
			break;

		case 2:
			return Set_LcdData;
			break;

	}
	*/
	if(LCD_Init != Get_JigPlatform())
	{
		LCD_Init = Get_JigPlatform();
		return Device_Index_2;
	}
	else
	{
		return Device_Index_3;
	}
}

T_Device_Step Cmp_Set_LcdData()
{

	static UINT8 LCD_Init = 0;

	switch(LCD_Init)
	{
		case 0:
			if(LCD_Device.Comm_Request == Serial_Sleep)
			{
				LCD_Device.Comm_Request 	= Serial_Oneshot;
				LCD_Device.Comm_Step		= Serial_Start;
				LCD_Device.T_Serial_Packet.Adr_Size 	= 1;
				LCD_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( LCD_Device.T_Serial_Packet.Adr, Init_Lcd_Size_0, SIZE_OF_ARRAY(Init_Lcd_Size_0) );

				LCD_Device.T_Serial_Packet.Data_Size	= 4;
				LCD_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( LCD_Device.T_Serial_Packet.Data, Init_Lcd_Size_0, SIZE_OF_ARRAY(Init_Lcd_Size_0) );
				LCD_Init++;
			}
			break;

		case 1:
			if(LCD_Device.Comm_Request == Serial_Sleep)
			{
				LCD_Device.Comm_Request 	= Serial_Oneshot;
				LCD_Device.Comm_Step		= Serial_Start;
				LCD_Device.T_Serial_Packet.Adr_Size 	= 1;
				LCD_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( LCD_Device.T_Serial_Packet.Adr, Init_Lcd_Size_1, SIZE_OF_ARRAY(Init_Lcd_Size_1) );

				LCD_Device.T_Serial_Packet.Data_Size	= 4;
				LCD_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( LCD_Device.T_Serial_Packet.Data, Init_Lcd_Size_1, SIZE_OF_ARRAY(Init_Lcd_Size_1) );
				LCD_Init++;
			}
			break;

		case 2:
			return Device_Index_2;
			break;

	}

	return Device_Index_4;
}


void delay(void)
{
	for(UINT8 loop = 100; loop > 0; loop--)
	{}
}

