

#include <stdio.h>
#include <string.h>
/*************************************************/
/************************/


/************************/
/************************/

#include "../../1_Application/Include/main.h"

#include "../../3_Component/Include/Cmp_KeyScan.h"

#include "../../4_Library/Include/general.h"
#include "../../4_Library/Include/Lib_LCD.h"
#include "../../4_Library/Include/Lib_MPU6050.h"


#include "../../5_WROS/Include/WROS.h"
#include "../../5_WROS/Include/DDI_BootingDriver.h"


#include "../../6_Vablesource/Include/Vable_ModelInformation.h"

/************************/



UINT16  CalcChecksum(UINT32, UINT32);
void    Clock_Test_Init(void);
/************************/
void Lcd_Init();





void QDTFT_Test_Demo(void);
void Font_Test(void);
void Lcd_Clear(UINT16);
void Lcd_Reset(void);
void Gui_DrawFont_GBK16(UINT16, UINT16, UINT16, UINT16, UINT8*);
void Gui_DrawPoint(UINT16, UINT16, UINT16);
void Lcd_SetRegion(UINT16, UINT16, UINT16, UINT16);
void LCD_WriteData_16Bit(UINT16);
void Lcd_WriteIndex(UINT8);
void Lcd_WriteData(UINT8);
void SPI_WriteData(UINT8);
void delay_ms(UINT8);

















//	InterruptMark

/************************/
void main()
{
//	API_SetBootloaderMode(USER_APP_MODE);
//	API_SetStackPointer(*(int*)0x4000);
//	SCB->VTOR =	0x4000; //	(int*)0xE000ED08 = 0x4000;

	DDI_BootMicom();

	/*
	static UINT16 ucTemp;
	ucTemp = gunVDECheckSumData[1];
	ucTemp += 0;

	static UINT16 _Checksum;
	_Checksum = CalcChecksum(0,0x80000);
	_Checksum += 0;

	Clock_Test_Init();
	*/
	LCD_Device.Device_Step		= Initial_Dev_0;
	Flash_Device.Device_Step	= Initial_Dev_0;
	Mpu6050_Device.Device_Step	= Initial_Dev_0;



	//Run(_Checksum);
	static UINT32 X_Location,	Y_Location,	Z_Location;
	static UINT32 X_ACC,		Y_ACC,		Z_ACC;


	while(1)
	{
		Cmp_Lcd_Control();
		Cmp_Mpu6050_Control();
		KeyScan();

		static UINT32 MainLoop = 0;
		MainLoop++;
		if(MainLoop % 100 == 0)
		{
			WROS_UART_2->THR	= MainLoop / 100;
			//QDTFT_Test_Demo();
		}
		else
		{	;
		}
		X_Location =	Mpu6050_Device.T_Serial_Packet.Data[10] << 8
				| Mpu6050_Device.T_Serial_Packet.Data[11];
		Y_Location =	Mpu6050_Device.T_Serial_Packet.Data[12] << 8
				| Mpu6050_Device.T_Serial_Packet.Data[13];
		Z_Location =	Mpu6050_Device.T_Serial_Packet.Data[14] << 8
				| Mpu6050_Device.T_Serial_Packet.Data[15];

		X_ACC =	Mpu6050_Device.T_Serial_Packet.Data[20] << 8
				| Mpu6050_Device.T_Serial_Packet.Data[21];
		Y_ACC =	Mpu6050_Device.T_Serial_Packet.Data[22] << 8
				| Mpu6050_Device.T_Serial_Packet.Data[23];
		Z_ACC =	Mpu6050_Device.T_Serial_Packet.Data[24] << 8
				| Mpu6050_Device.T_Serial_Packet.Data[25];
	}
}

/*********************************************micom����ģ��*/


UINT16 CalcChecksum(UINT32 ulAddress, UINT32 ulLength)
{
	UINT16 unCheckSum = 0;
	UINT8* pucRomData = (UINT8*)ulAddress;

	while(ulLength)
	{
		unCheckSum += *pucRomData;
		pucRomData++;
		ulLength--;
	}

	return unCheckSum;
}

void Clock_Test_Init(void)
{/*
	CG_OSCCR_XEN2 = 1;
	OFD->CR1 = 0x000000F9;
	OFD->MNPLLON = 0x133;
	OFD->MXPLLON = 0x1CC;
	OFD->MNPLLOFF = 0x1D;
	OFD->MXPLLOFF = 0x25;
	OFD->CR2 = 0x000000E4;
	OFD->CR1 = 0x00000006;
	*/
}














/**************************************************************************/
/**************************************************************************/
/**************************************************************************/
/**************************************************************************/
/**************************************************************************/
/**************************************************************************/


#define X_MAX_PIXEL	        160
#define Y_MAX_PIXEL	        80


void QDTFT_Test_Demo(void)
{

//	LCD_CS_SET;//ͨ��IO���Ʊ�����

//	Lcd_Init();


//	Redraw_Mainmenu();//�������˵�(�����������ڷֱ��ʳ�������ֵ�����޷���ʾ)
//	Color_Test();//�򵥴�ɫ������
//	Num_Test();//������������
	Font_Test();//��Ӣ����ʾ����
//	showimage(gImage_mom);//ͼƬ��ʾʾ��


//	delay_ms(1200);
//	LCD_ShowNumTES();
}



void Font_Test(void)
{
	Lcd_Clear(WHITE);
	Gui_DrawFont_GBK16(8,10,BLUE,GRAY0,"����ģ��");

	delay_ms(255);
	Lcd_Clear(WHITE);
	Gui_DrawFont_GBK16(8,0,RED,WHITE,"weiren.wang");
	Gui_DrawFont_GBK16(8,20,YELLOW,WHITE,"1997/0/0");
	Gui_DrawFont_GBK16(8,40,GREEN,WHITE, "Control Software");
	Gui_DrawFont_GBK16(0,60,BLUE,WHITE,"Tel:15501159585");
	Gui_DrawFont_GBK16(0,80,RED,WHITE, "QQ:666666666");
	delay_ms(255);
}

void Lcd_Clear(UINT16 Color)
{
   unsigned int i,m;
   Lcd_SetRegion(0,0,X_MAX_PIXEL-1,Y_MAX_PIXEL-1);
   Lcd_WriteIndex(0x2C);
   for(i=0;i<X_MAX_PIXEL;i++)
    for(m=0;m<Y_MAX_PIXEL;m++)
    {
	  	LCD_WriteData_16Bit(Color);
    }
}

void Lcd_Reset(void)
{
	LCD_RST_CLR;
	delay_ms(255);
	LCD_RST_SET;
	delay_ms(255);
}


void Gui_DrawFont_GBK16(UINT16 x, UINT16 y, UINT16 fc, UINT16 bc, UINT8 *s)
{
	unsigned char i,j;
	unsigned short k,x0;
	x0=x;

	while(*s)
	{
		if((*s) < 128)
		{
			k=*s;
			if (k==13)
			{
				x=x0;
				y+=16;
			}
			else
			{
				if (k>32) k-=32; else k=0;

			    for(i=0;i<16;i++)
				for(j=0;j<8;j++)
					{
				    	if(asc16[k*16+i]&(0x80>>j))	Gui_DrawPoint(x+j,y+i,fc);
						else
						{
							if (fc!=bc) Gui_DrawPoint(x+j,y+i,bc);
						}
					}
				x+=8;
			}
			s++;
		}

		else
		{


			for (k=0;k<hz16_num;k++)
			{
			  if ((hz16[k].Index[0]==*(s))&&(hz16[k].Index[1]==*(s+1)))
			  {
				    for(i=0;i<16;i++)
				    {
						for(j=0;j<8;j++)
							{
						    	if(hz16[k].Msk[i*2]&(0x80>>j))	Gui_DrawPoint(x+j,y+i,fc);
								else {
									if (fc!=bc) Gui_DrawPoint(x+j,y+i,bc);
								}
							}
						for(j=0;j<8;j++)
							{
						    	if(hz16[k].Msk[i*2+1]&(0x80>>j))	Gui_DrawPoint(x+j+8,y+i,fc);
								else
								{
									if (fc!=bc) Gui_DrawPoint(x+j+8,y+i,bc);
								}
							}
				    }
				}
			  }
			s+=2;x+=16;
		}

	}
}


void Gui_DrawPoint(UINT16 x,UINT16 y,UINT16 Data)
{
	Lcd_SetRegion(x,y,x+1,y+1);
	LCD_WriteData_16Bit(Data);

}

void Lcd_SetRegion(UINT16 x_start,UINT16 y_start,UINT16 x_end,UINT16 y_end)
{
	Lcd_WriteIndex(0x2a);
	Lcd_WriteData(0x00);
	Lcd_WriteData(x_start+1);
	Lcd_WriteData(0x00);
	Lcd_WriteData(x_end+1);

	Lcd_WriteIndex(0x2b);
	Lcd_WriteData(0x00);
	Lcd_WriteData(y_start+0x1A);
	Lcd_WriteData(0x00);
	Lcd_WriteData(y_end+0x1A);
	Lcd_WriteIndex(0x2c);

}

void LCD_WriteData_16Bit(UINT16 Data)
{

	LCD_RS_SET;
	SPI_WriteData(Data>>8); 	//д���8λ����
	SPI_WriteData(Data); 			//д���8λ����

}

//��Һ����дһ��8λָ��
void Lcd_WriteIndex(UINT8 Index)
{
   //SPI д����ʱ��ʼ
   LCD_RS_CLR;
	 SPI_WriteData(Index);
}


void Lcd_WriteData(UINT8 Data)
{
   LCD_RS_SET;
   SPI_WriteData(Data);
}


void  SPI_WriteData(UINT8 Data)
{
	unsigned char i=0;
	for(i=8;i>0;i--)
	{
		if(Data&0x80)
		{
			LCD_SDA_SET; //�������
		}
		else
		{
			LCD_SDA_CLR;
		}
      LCD_SCL_CLR;
      LCD_SCL_SET;
      Data<<=1;
	}
}









void delay_ms(UINT8 ucLoop_Number)
{
	while(ucLoop_Number > 0)
	{	ucLoop_Number--;
	}
}







