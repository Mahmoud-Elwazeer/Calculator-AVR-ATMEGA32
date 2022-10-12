/*
 * LCD_Driver.c
 *
 * Created: 8/7/2022 10:42:59 PM
 *  Author: Mahmoud Elwazeer
 */ 

#include "LCD_Driver.h"




/*****************************************/

void LCD_Init()
{
	
	DIO_PortDirection(DATA , OUTPUT);
	DIO_PinDirection(COMMAND , rs ,OUTPUT );
	DIO_PinDirection(COMMAND , rw ,OUTPUT );
	DIO_PinDirection(COMMAND , en ,OUTPUT );
	DIO_SetPortValue(DATA , 0x00);
	LCD_WriteCmd(0x38);
	LCD_WriteCmd(0x0C);
	LCD_WriteCmd(0x06);
	LCD_WriteCmd(0x01);
	LCD_WriteCmd(0x80);
}

void LCD_WriteCmd(u8 cmd)
{
	DIO_SetPortValue(DATA , cmd);
	
	DIO_SetPinValue(COMMAND , rs , LOW);
	DIO_SetPinValue(COMMAND , rw , LOW);
	DIO_SetPinValue(COMMAND , en , HIGH);
	_delay_ms(2);
	DIO_SetPinValue(COMMAND , en , LOW);
}

void LCD_WriteData(u8 dataaaa)
{
	DIO_SetPortValue(DATA , dataaaa);
	
	DIO_SetPinValue(COMMAND , rs , HIGH);
	DIO_SetPinValue(COMMAND , rw , LOW);
	DIO_SetPinValue(COMMAND , en , HIGH);
	_delay_ms(2);
	DIO_SetPinValue(COMMAND , en , LOW);
}

void LCD_GOTO(u8 pos_x , u8 pos_y)
{
	int address = 0;
	
	if (pos_x == 0)
	address = 0x80;
	else if (pos_x == 1)
	address = 0xC0;
	
	if (pos_y <= 15)
	address += pos_y;
	
	LCD_WriteCmd(address);
}

void LCD_WriteChar(u8 character)
{
	LCD_WriteData(character);
}


void LCD_WriteString(u8 *str)
{
	for(u8 i =0; str[i] != '\0'  ; i++)
	{
		LCD_WriteData(str[i]);
		_delay_ms(1);
	}
	
}

void LCD_WriteSpaces(u8 n)
{
	for(u8 i =0; i < n ; i++)
	{
		LCD_WriteData(' ');
		_delay_ms(1);
	}
}

void LCD_WriteNumber(u64 Number)
{
	u8 i=0,arr[10],j;
	if(Number==0)
	LCD_WriteData('0');
	else{
		while(Number)
		{
			arr[i]=Number%10 +'0';
			Number/=10;
			i++;
		}
		for(j=i;j>0;j--)
		{
			LCD_WriteData(arr[j-1]);
		}
	}
}

void LCD_WriteNumber5(u32 Number)
{
	LCD_WriteData(Number%100000/10000+'0');
	LCD_WriteData(Number%10000/1000+'0');
	LCD_WriteData(Number%1000/100+'0');
	LCD_WriteData(Number%100/10+'0');
	LCD_WriteData(Number%10/1+'0');
}


void LCD_WriteNumber2(u16 Number)
{
	LCD_WriteData(Number%10000/1000+'0');
	LCD_WriteData(Number%1000/100+'0');
	LCD_WriteData(Number%100/10+'0');
	LCD_WriteData(Number%10/1+'0');
}

void LCD_WriteNumber3(u8 Number)
{
	LCD_WriteData(Number%1000/100+'0');
	LCD_WriteData(Number%100/10+'0');
	LCD_WriteData(Number%10/1+'0');
}



void LCD_Clear(void)
{

	LCD_WriteCmd(0x01);

}