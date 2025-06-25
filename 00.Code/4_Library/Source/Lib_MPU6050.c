

#include <string.h>

#include "../../4_Library/Include/general.h"
#include "../../4_Library/Include/Int.h"
#include "../../4_Library/Include/Lib_UartComm.h"
#include "../../4_Library/Include/Lib_MPU6050.h"
#include "../../4_Library/Include/Lib_CommSubMicom.h"
#include "../../4_Library/Include/Lib_SensingADC.h"
#include "../../4_Library/Include/Lib_EEPROM.h"


#include "../../5_WROS/Include/DDI_RegisterDriver.h"
#include "../../5_WROS/Include/WROS.h"

const UINT8 Init_Mpu6050_0[1]	= {0x00};

const UINT8 Init_Mpu6050_1[3]	= {0xD0, 0x6B, 0x80};

const UINT8 Init_Mpu6050_2[3]	= {0xD0, 0x6B, 0x09};

const UINT8 Init_Mpu6050_3[3]	= {0xD0, 0x6A, 0x45};

const UINT8 Init_Mpu6050_4[3]	= {0xD0, 0x19, 0x00};

const UINT8 Init_Mpu6050_5[3]	= {0xD0, 0x1A, 0x03};

const UINT8 Init_Mpu6050_6[3]	= {0xD0, 0x1B, 0x08};

const UINT8 Init_Mpu6050_7[3]	= {0xD0, 0x1C, 0x08};

const UINT8 Init_Mpu6050_8[3]	= {0xD0, 0x23, 0x78};


enum{								ID_W,			ID_R,		X_Register,	Y_Register,	Z_Register,
									X_Data_H = 10,	X_Data_L,	Y_Data_H,	Y_Data_L,	Z_Data_H,	Z_Data_L,
									X_ACC_H = 20,	X_ACC_L,	Y_ACC_H,	Y_ACC_L,	Z_ACC_H,	Z_ACC_L};

const UINT8 Acc_Mpu6050_H[5]	=	{0xD0,	0xD1,	0x3B,	0x3D,	0x3F};
const UINT8 Acc_Mpu6050_L[5]	=	{0xD0,	0xD1,	0x3C,	0x3E,	0x40};

const UINT8 Dist_Mpu6050_H[5]	=	{0xD0,	0xD1,	0x43,	0x45,	0x47};
const UINT8 Dist_Mpu6050_L[5]	=	{0xD0,	0xD1,	0x44,	0x46,	0x48};




void Cmp_Mpu6050_Next_Step(void);


T_Device_Step Cmp_Mpu6050_Init(void);
T_Device_Step Cmp_Set_Mpu6050_Data(void);
T_Device_Step Cmp_Get_Mpu6050_Data(void);

static T_Device_Step (* const mapfnMpu6050ControlStepTbl[]) (void) =
{
	Cmp_Mpu6050_Init,
	Cmp_Set_Mpu6050_Data,
	Cmp_Get_Mpu6050_Data,
};





void	Cmp_Mpu6050_Control()
{
	Mpu6050_Device.Device_Step = mapfnMpu6050ControlStepTbl[Mpu6050_Device.Device_Step]();

}







void Cmp_Mpu6050_Next_Step()
{
	switch(Mpu6050_Device.Comm_Step)
	{
		case Serial_Start:
			Mpu6050_Device.Comm_Step = Serial_Write_mode;
			break;

		case Serial_Write_mode:
			Mpu6050_Device.Comm_Step	= Serial_TX_Adr;
			break;

		case Serial_Read_mode:
			Mpu6050_Device.Comm_Step	= Serial_RX_DATA;
			break;

		case Serial_TX_Adr:
			if(Mpu6050_Device.T_Serial_Packet.Adr_Size == 0)
			{

				if(Mpu6050_Device.Device_Step == Device_Index_1)
				{
					Mpu6050_Device.Comm_Step	= Serial_RX_DATA;
				}
				else
				{
					Mpu6050_Device.Comm_Step	= Serial_TX_DATA;
				}

			}
			Mpu6050_Device.EchoReq		= ReadACK;
			break;

		case Serial_TX_DATA:
			if(Mpu6050_Device.T_Serial_Packet.Data_Size == 0)
			{
				Mpu6050_Device.Comm_Step = Serial_Stop;
			}
			else
			{	;
			}
			Mpu6050_Device.EchoReq		= ReadACK;
			break;

		case Serial_RX_DATA:
//			Mpu6050_Device.Comm_Step					= Serial_Read_mode;
			if(Mpu6050_Device.T_Serial_Packet.Data_Size == 0)
			{
				Mpu6050_Device.Comm_Step = Serial_Stop;
//				Mpu6050_Device.EchoReq						= WriteACK;
			}
			else
			{	;
			}
			Mpu6050_Device.EchoReq						= ReadACK;
			break;

		case Serial_Stop:
			Mpu6050_Device.Comm_Request = Serial_Sleep;
			break;

	}

}








T_Device_Step Cmp_Mpu6050_Init()
{
	static UINT8 Mpu6050_Init = 0;
	switch(Mpu6050_Init)
	{
		case 0:
			Mpu6050_Device.Device_Type			= IIC;

			Mpu6050_Device.Clock_Pin			= &GPIO_ODR(F, 6);	//	SCL		35.PE11_SCL1
			Mpu6050_Device.DataW_Pin			= &GPIO_ODR(F, 7);	//	SDA		36.PE12_SDA1
			Mpu6050_Device.DataR_Pin			= &GPIO_IDR(F, 7);	//	SDA		36.PE12_SDA1


			Mpu6050_Device.Read_Pin_state		= &GPIO_CR_2(F, 7);
//			*Mpu6050_Device.Read_Pin_state		= ((Input >> 1) & 0x01);
			Mpu6050_Device.Write_Pin_state		= &GPIO_CR_2(F, 7);
			*Mpu6050_Device.Write_Pin_state		= ((OD_Output >> 1) & 0x01);

			Mpu6050_Device.Eable_Pin			= NULL;
			Mpu6050_Device.ChipS_Pin			= NULL;

			Mpu6050_Device.Device_NextStep		= Cmp_Mpu6050_Next_Step;				//	SDA		17.PE4_SDA0


			Mpu6050_Device.T_Serial_Packet.Adr_Size		= 0;
			Mpu6050_Device.T_Serial_Packet.Data_Size	= 0;

			Mpu6050_Device.Comm_Request		= Serial_Oneshot;
			Mpu6050_Device.Comm_Step		= Serial_Start;

			Mpu6050_Init++;
			break;

		case 1:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request		= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size		= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Init_Mpu6050_1, SIZE_OF_ARRAY(Init_Mpu6050_1));


				Mpu6050_Device.T_Serial_Packet.Data_Size	= 2;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Init_Mpu6050_1, SIZE_OF_ARRAY(Init_Mpu6050_1));
				Mpu6050_Init++;
			}
			break;

		case 2:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request		= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size		= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Init_Mpu6050_2, SIZE_OF_ARRAY(Init_Mpu6050_2));


				Mpu6050_Device.T_Serial_Packet.Data_Size	= 2;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Init_Mpu6050_2, SIZE_OF_ARRAY(Init_Mpu6050_2));
				Mpu6050_Init++;
			}
			break;

		case 3:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request		= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size		= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Init_Mpu6050_3, SIZE_OF_ARRAY(Init_Mpu6050_3));


				Mpu6050_Device.T_Serial_Packet.Data_Size	= 2;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Init_Mpu6050_3, SIZE_OF_ARRAY(Init_Mpu6050_3));
				Mpu6050_Init++;
			}
			break;

		case 4:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request		= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size		= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Init_Mpu6050_4, SIZE_OF_ARRAY(Init_Mpu6050_4));


				Mpu6050_Device.T_Serial_Packet.Data_Size	= 2;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Init_Mpu6050_4, SIZE_OF_ARRAY(Init_Mpu6050_4));
				Mpu6050_Init++;
			}
			break;

		case 5:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request		= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size		= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Init_Mpu6050_5, SIZE_OF_ARRAY(Init_Mpu6050_5));


				Mpu6050_Device.T_Serial_Packet.Data_Size	= 2;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Init_Mpu6050_5, SIZE_OF_ARRAY(Init_Mpu6050_5));
				Mpu6050_Init++;
			}
			break;

		case 6:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request		= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size		= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Init_Mpu6050_6, SIZE_OF_ARRAY(Init_Mpu6050_6) );


				Mpu6050_Device.T_Serial_Packet.Data_Size	= 2;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Init_Mpu6050_6, SIZE_OF_ARRAY(Init_Mpu6050_6) );
				Mpu6050_Init++;
			}
			break;

		case 7:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request		= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size		= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Init_Mpu6050_7, SIZE_OF_ARRAY(Init_Mpu6050_7) );


				Mpu6050_Device.T_Serial_Packet.Data_Size	= 2;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Init_Mpu6050_7, SIZE_OF_ARRAY(Init_Mpu6050_7) );
				Mpu6050_Init++;
			}
			break;

		case 8:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request		= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size		= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= 0;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Init_Mpu6050_8, SIZE_OF_ARRAY(Init_Mpu6050_8) );


				Mpu6050_Device.T_Serial_Packet.Data_Size	= 2;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= 1;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Init_Mpu6050_8, SIZE_OF_ARRAY(Init_Mpu6050_8) );
				Mpu6050_Init++;
			}
			break;

		case 9:
		default:
			return Device_Index_1;
			break;
	}

	return Initial_Dev_0;
}













T_Device_Step Cmp_Set_Mpu6050_Data()
{
	static UINT8 Mpu6050_Init = 0;
	switch(Mpu6050_Init)
	{
		case 0:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request 	= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= ID_W;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Dist_Mpu6050_H, SIZE_OF_ARRAY(Dist_Mpu6050_H));


				Mpu6050_Device.T_Serial_Packet.Data_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= X_Register;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Dist_Mpu6050_H, SIZE_OF_ARRAY(Dist_Mpu6050_H));
				Mpu6050_Init++;
			return Device_Index_2;
			}
			break;

		case 1:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request 	= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= ID_W;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Dist_Mpu6050_L, SIZE_OF_ARRAY(Dist_Mpu6050_L));


				Mpu6050_Device.T_Serial_Packet.Data_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= X_Register;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Dist_Mpu6050_L, SIZE_OF_ARRAY(Dist_Mpu6050_L));
				Mpu6050_Init++;
				return Device_Index_2;
			}
			break;

		case 2:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request 	= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= ID_W;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Dist_Mpu6050_H, SIZE_OF_ARRAY(Dist_Mpu6050_H));


				Mpu6050_Device.T_Serial_Packet.Data_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= Y_Register;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Dist_Mpu6050_H, SIZE_OF_ARRAY(Dist_Mpu6050_H));
				Mpu6050_Init++;
				return Device_Index_2;
			}
			break;

		case 3:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request 	= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= ID_W;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Dist_Mpu6050_L, SIZE_OF_ARRAY(Dist_Mpu6050_L));


				Mpu6050_Device.T_Serial_Packet.Data_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= Y_Register;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Dist_Mpu6050_L, SIZE_OF_ARRAY(Dist_Mpu6050_L));
				Mpu6050_Init++;
				return Device_Index_2;
			}
			break;

		case 4:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request 	= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= ID_W;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Dist_Mpu6050_H, SIZE_OF_ARRAY(Dist_Mpu6050_H));


				Mpu6050_Device.T_Serial_Packet.Data_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= Z_Register;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Dist_Mpu6050_H, SIZE_OF_ARRAY(Dist_Mpu6050_H));
				Mpu6050_Init++;
				return Device_Index_2;
			}
			break;

		case 5:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request 	= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= ID_W;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Dist_Mpu6050_L, SIZE_OF_ARRAY(Dist_Mpu6050_L));


				Mpu6050_Device.T_Serial_Packet.Data_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= Z_Register;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Dist_Mpu6050_L, SIZE_OF_ARRAY(Dist_Mpu6050_L));
				Mpu6050_Init++;
				return Device_Index_2;
			}
			break;

		case 6:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request 	= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= ID_W;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Acc_Mpu6050_H, SIZE_OF_ARRAY(Acc_Mpu6050_H));


				Mpu6050_Device.T_Serial_Packet.Data_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= Z_Register;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Acc_Mpu6050_H, SIZE_OF_ARRAY(Acc_Mpu6050_H));
				Mpu6050_Init++;
				return Device_Index_2;
			}
			break;

		case 7:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request 	= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= ID_W;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Acc_Mpu6050_L, SIZE_OF_ARRAY(Acc_Mpu6050_L));


				Mpu6050_Device.T_Serial_Packet.Data_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= Z_Register;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Acc_Mpu6050_L, SIZE_OF_ARRAY(Acc_Mpu6050_L));
				Mpu6050_Init++;
				return Device_Index_2;
			}
			break;

		case 8:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request 	= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= ID_W;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Acc_Mpu6050_H, SIZE_OF_ARRAY(Acc_Mpu6050_H));


				Mpu6050_Device.T_Serial_Packet.Data_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= Z_Register;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Acc_Mpu6050_H, SIZE_OF_ARRAY(Acc_Mpu6050_H));
				Mpu6050_Init++;
				return Device_Index_2;
			}
			break;

		case 9:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request 	= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= ID_W;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Acc_Mpu6050_L, SIZE_OF_ARRAY(Acc_Mpu6050_L));


				Mpu6050_Device.T_Serial_Packet.Data_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= Z_Register;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Acc_Mpu6050_L, SIZE_OF_ARRAY(Acc_Mpu6050_L));
				Mpu6050_Init++;
				return Device_Index_2;
			}
			break;

		case 10:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request 	= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= ID_W;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Acc_Mpu6050_H, SIZE_OF_ARRAY(Acc_Mpu6050_H));


				Mpu6050_Device.T_Serial_Packet.Data_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= Z_Register;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Acc_Mpu6050_H, SIZE_OF_ARRAY(Acc_Mpu6050_H));
				Mpu6050_Init++;
				return Device_Index_2;
			}
			break;

		case 11:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request 	= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= ID_W;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Acc_Mpu6050_L, SIZE_OF_ARRAY(Acc_Mpu6050_L));


				Mpu6050_Device.T_Serial_Packet.Data_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= Z_Register;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Acc_Mpu6050_L, SIZE_OF_ARRAY(Acc_Mpu6050_L));
				Mpu6050_Init = 0;
				return Device_Index_2;
			}
			break;

	}

	return Device_Index_1;
}







T_Device_Step Cmp_Get_Mpu6050_Data()
{
	static UINT8 Mpu6050_Init = 0;
	switch(Mpu6050_Init)
	{
		case 0:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request 	= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= ID_R;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Dist_Mpu6050_H, SIZE_OF_ARRAY(Dist_Mpu6050_H));


				Mpu6050_Device.T_Serial_Packet.Data_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= X_Data_H;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Dist_Mpu6050_H, SIZE_OF_ARRAY(Dist_Mpu6050_H));
				Mpu6050_Init++;
				return Device_Index_1;
			}
			break;

		case 1:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request 	= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= ID_R;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Dist_Mpu6050_L, SIZE_OF_ARRAY(Dist_Mpu6050_L));


				Mpu6050_Device.T_Serial_Packet.Data_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= X_Data_L;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Dist_Mpu6050_L, SIZE_OF_ARRAY(Dist_Mpu6050_L));
				Mpu6050_Init++;
				return Device_Index_1;
			}
			break;

		case 2:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request 	= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= ID_R;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Dist_Mpu6050_H, SIZE_OF_ARRAY(Dist_Mpu6050_H));


				Mpu6050_Device.T_Serial_Packet.Data_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= Y_Data_H;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Dist_Mpu6050_H, SIZE_OF_ARRAY(Dist_Mpu6050_H));
				Mpu6050_Init++;
				return Device_Index_1;
			}
			break;

		case 3:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request 	= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= ID_R;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Dist_Mpu6050_L, SIZE_OF_ARRAY(Dist_Mpu6050_L));


				Mpu6050_Device.T_Serial_Packet.Data_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= Y_Data_L;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Dist_Mpu6050_L, SIZE_OF_ARRAY(Dist_Mpu6050_L));
				Mpu6050_Init++;
				return Device_Index_1;
			}
			break;

		case 4:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request 	= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= ID_R;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Dist_Mpu6050_H, SIZE_OF_ARRAY(Dist_Mpu6050_H));


				Mpu6050_Device.T_Serial_Packet.Data_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= Z_Data_H;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Dist_Mpu6050_H, SIZE_OF_ARRAY(Dist_Mpu6050_H));
				Mpu6050_Init++;
				return Device_Index_1;
			}
			break;

		case 5:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request 	= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= ID_R;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Dist_Mpu6050_L, SIZE_OF_ARRAY(Dist_Mpu6050_L));


				Mpu6050_Device.T_Serial_Packet.Data_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= Z_Data_L;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Dist_Mpu6050_L, SIZE_OF_ARRAY(Dist_Mpu6050_L));
				Mpu6050_Init++;
				return Device_Index_1;
			}
			break;

		case 6:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request 	= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= ID_R;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Acc_Mpu6050_H, SIZE_OF_ARRAY(Acc_Mpu6050_H));


				Mpu6050_Device.T_Serial_Packet.Data_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= X_ACC_H;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Acc_Mpu6050_H, SIZE_OF_ARRAY(Acc_Mpu6050_H));
				Mpu6050_Init++;
				return Device_Index_1;
			}
			break;

		case 7:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request 	= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= ID_R;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Acc_Mpu6050_L, SIZE_OF_ARRAY(Acc_Mpu6050_L));


				Mpu6050_Device.T_Serial_Packet.Data_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= X_ACC_L;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Acc_Mpu6050_L, SIZE_OF_ARRAY(Acc_Mpu6050_L));
				Mpu6050_Init++;
				return Device_Index_1;
			}
			break;

		case 8:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request 	= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= ID_R;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Acc_Mpu6050_H, SIZE_OF_ARRAY(Acc_Mpu6050_H));


				Mpu6050_Device.T_Serial_Packet.Data_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= Y_ACC_H;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Acc_Mpu6050_H, SIZE_OF_ARRAY(Acc_Mpu6050_H));
				Mpu6050_Init++;
				return Device_Index_1;
			}
			break;

		case 9:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request 	= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= ID_R;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Acc_Mpu6050_L, SIZE_OF_ARRAY(Acc_Mpu6050_L));


				Mpu6050_Device.T_Serial_Packet.Data_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= Y_ACC_L;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Acc_Mpu6050_L, SIZE_OF_ARRAY(Acc_Mpu6050_L));
				Mpu6050_Init++;
				return Device_Index_1;
			}
			break;

		case 10:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request 	= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= ID_R;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Acc_Mpu6050_H, SIZE_OF_ARRAY(Acc_Mpu6050_H));


				Mpu6050_Device.T_Serial_Packet.Data_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= Z_ACC_H;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Acc_Mpu6050_H, SIZE_OF_ARRAY(Acc_Mpu6050_H));
				Mpu6050_Init++;
				return Device_Index_1;
			}
			break;

		case 11:
			if(Mpu6050_Device.Comm_Request == Serial_Sleep)
			{
				Mpu6050_Device.Comm_Request 	= Serial_Oneshot;
				Mpu6050_Device.Comm_Step		= Serial_Start;

				Mpu6050_Device.T_Serial_Packet.Adr_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Adr_Index	= ID_R;
				memcpy( Mpu6050_Device.T_Serial_Packet.Adr, Acc_Mpu6050_L, SIZE_OF_ARRAY(Acc_Mpu6050_L));


				Mpu6050_Device.T_Serial_Packet.Data_Size 	= 1;
				Mpu6050_Device.T_Serial_Packet.Data_Index	= Z_ACC_L;
				memcpy( Mpu6050_Device.T_Serial_Packet.Data, Acc_Mpu6050_L, SIZE_OF_ARRAY(Acc_Mpu6050_L));
				Mpu6050_Init = 0;
				return Device_Index_1;
			}
			break;
	}

	return Device_Index_2;
}
























