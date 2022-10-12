/*
 * LCD_KEYPAD.c
 *
 * Created: 8/8/2022 10:31:50 PM
 *  Author: Mahmoud Elwazeer
 */ 

#include "KEYPAD_Driver.h"


static u8 key_array[ROW][COLUMN]={
									{'7' , '8' , '9' , '/'},
									{'4' , '5', '6' , '*'},
									{'1' , '2' , '3' , '-'},
									{'c' , '0' , '=' , '+'}
								 };


void Keypad_init()
{
	u8 i ;
	for( i = 0; i < 4 ; i++)
	{
		DIO_PinDirection(OUT_Port , FIRST_OUT_Pin + i , OUTPUT);
		DIO_PinDirection(INP_Port , FIRST_INP_Pin + i , INPUT);
		
		// PULL UP
		DIO_SetPinValue(INP_Port , FIRST_INP_Pin + i  , HIGH);
	}
}


u8 keypad_Data(void)
{
	u8 r , c , key = DEFAULT_KEY;
	for(r = 0; r < ROW; r++)
	{
		DIO_SetPinValue(OUT_Port , FIRST_OUT_Pin + r  , LOW);
		for(c = 0; c < COLUMN; c++)
		{
			if(!DIO_GetPinValue(INP_Port ,FIRST_INP_Pin + c))
			{
				key = key_array[r][c];
				while(!DIO_GetPinValue(INP_Port ,FIRST_INP_Pin + c));
			}
		}
		DIO_SetPinValue(OUT_Port , FIRST_OUT_Pin + r  , HIGH);
	}
	return key;
}





