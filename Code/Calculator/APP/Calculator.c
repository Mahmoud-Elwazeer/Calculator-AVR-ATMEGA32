/*
 * LCD_With_Keypad.c
 *
 * Created: 9/7/2022 12:52:11 AM
 *  Author: Mahmoud Elwazeer
 */ 

#include "Calculator.h"

void Calc()
{
	
	
	Keypad_init();
	
	LCD_Init();
	_delay_ms(2);
	
	
	LCD_GOTO(0 , 0);
	LCD_WriteString("CALC");
	_delay_ms(200);
	LCD_Clear();
	LCD_GOTO(0 , 0);
	u8 x ;
	u8 op = ' ' ;
	u8 flag = 0;
	u16 num1  =0, num2 = 0 ;
	
	
	while (1)
	{
		
		x = keypad_Data();
		if( x != DEFAULT_KEY )
		{
			if ((x >='0') &&( x <= '9'))
			{
				if (flag == 1)
				{
					LCD_Clear();
					flag = 0;
				}
				
				num1 = (num1 * 10) + (x - '0');
				LCD_WriteChar(x);
			}
			else if  ((x =='+') ||( x == '-') || (x == '*') || (x == '/'))
			{
				LCD_WriteChar(x);
				op = x;
				num2 = num1;
				num1 = 0;
			}
			else if (x == '=')
			{
				LCD_WriteChar(x);
				switch(op)
				{
					case '+':
					sum(num2 , num1);
					break;
					case '-':
					sub(num2 , num1);
					break;
					case '*':
					mul(num2 , num1);
					break;
					case '/':
					div(num2 , num1);
					break;
					default : break;
				}
				LCD_GOTO(0 , 0);
				num1 = 0;
				num2 = 0;
				flag = 1;
				
			}
			else if (x == 'c')
			{
				LCD_Clear();
			}
		}
	}
}

void sum(u16 n1 , u16 n2)
{
	u32 result = (u32)n1 + (u32)n2;
	LCD_GOTO(1 , 6);
	LCD_WriteNumber(result);
}

void sub(u16 n1 , u16 n2)
{
	u32 result ;
	if(n1 < n2)
	{
		result = (u32)n2-(u32)n1 ;
		LCD_GOTO(1 , 5);
		LCD_WriteChar('-');
	}
	else
	{
		result = (u32)n1-(u32)n2 ;
	}
	LCD_GOTO(1 , 6);
	LCD_WriteNumber(result);
}

void mul(u16 n1 , u16 n2)
{
	u32 result ;
	result =  ((u32)n1 * (u32)n2);
	LCD_GOTO(1 , 6);
	LCD_WriteNumber(result);
}

void div(u16 n1 , u16 n2)
{
	u32 result ;
	result = ((u32)n1*100)/(u32)n2 ;
	LCD_GOTO(1 , 6);
	LCD_WriteNumber(result / 100);
	LCD_WriteChar('.');
	LCD_WriteNumber(result%100/10);
	LCD_WriteNumber(result%10);
}