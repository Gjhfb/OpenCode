
#define WRITE_BIT_LENGTH		8
#define DEFAULT_DELAY_NUMBER	2
#define BUSY_DELAY_TIME			20


#define EEPROM_TYPE				2

#define M93C86 					2
#define M93C66 					1



#define ENABLE_ORDER			0xC0

#define EEPROM_CHIP_SELECT_INPUT_P	PD_DATA_(3)
#define EEPROM_SERIAL_CLOCK_P		PD_DATA_(4)
#define EEPROM_SERIAL_WRITE_P		PD_DATA_(2)
#define EEPROM_SERIAL_READ_P		PD_DATA_(1)


UINT8 EEP_SaveBufferToEEPROM(UINT16,UINT8*,UINT8);
void EEP_LoadBufferFromEEPROM(UINT16,UINT8*,UINT8);


UINT8 EEP_ByteRead(UINT16);
UINT8 EEP_ByteWrite(UINT16,UINT8);
void EEP_AddressSet(UINT16);
UINT8 EEP_Busy_Delay(void);
void EEP_nBit_Write(UINT8,UINT8);
UINT8 EEP_nBit_Read(void);
void EEP_Erase_Write_Enable(void);
void EEP_Erase_Write_Disable(void);
void EEP_Loop_Delay(UINT8);

