#ifndef _LCD_INTERFACE_H_ //Header guard if not defined
#define _LCD_INTERFACE_H_
//LCD PORT CONNECTION
#define LCD_PORT PORTD
//LCD RS AND RW AND EN HARDWER CONNECTION
#define LCD_INIT PORTB
#define LCD_RS PIN3
#define LCD_RW PIN4
#define LCD_EN PIN5
//COMEND CODES
#define SET_CGRAM_ADDRESS 0b01000000
#define function_set_8_bit_lcd 0b00111000
#define Display_On_Cursor_OFF 0b00001100
#define Display_On_Cursor_ON 0b00001110
#define Clear_Display 0b00000001
#define DDRAM_address_row_one_lcd 0b10000000
#define DDRAM_address_row_two_lcd 0b11000000

void LCD_VidInit(void);

void LCD_VidWriteCommand(u8 LOC_u8Command);

void LCD_VidWriteData(u8 LOC_u8Data);

void LCD_VidString(u8* LOC_USER);
void LCD_VidDispNumber(u32 x);
void LCD_VidPostion(u8 row,u8 colm);
void LCD_VidGotoCGRAM();
void LCD_VidArabicNume(void);




#endif
