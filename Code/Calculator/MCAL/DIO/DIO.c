/*
 * DIO.c
 *
 * Created: 9/4/2022 7:15:54 PM
 *  Author: Mahmoud Elwazeer
 */ 


#include "DIO.h"


void DIO_PortDirection(DIO_Port_ID port_ID ,DIO_Direction direction)
{
	if (direction == OUTPUT)
	{
		switch(port_ID)
		{
			case PORTA: DDRA_Reg = 0xFF ; break;
			case PORTB: DDRB_Reg = 0xFF ; break;
			case PORTC: DDRC_Reg = 0xFF ; break;
			case PORTD: DDRD_Reg = 0xFF ; break;
		}
	}
	else if(direction == INPUT)
	{
		switch(port_ID)
		{
			case PORTA: DDRA_Reg = 0x00 ; break;
			case PORTB: DDRB_Reg = 0x00 ; break;
			case PORTC: DDRC_Reg = 0x00 ; break;
			case PORTD: DDRD_Reg = 0x00 ; break;
		}
	}
}

void DIO_PortDirectionValue(DIO_Port_ID port_ID , u8 value)
{
	switch(port_ID)
	{
		case PORTA: DDRA_Reg = value ; break;
		case PORTB: DDRB_Reg = value ; break;
		case PORTC: DDRC_Reg = value ; break;
		case PORTD: DDRD_Reg = value ; break;
	}
}


void DIO_PinDirection(DIO_Port_ID port_ID,DIO_Pin_ID pin_ID ,DIO_Direction direction)
{
	if (port_ID <= PORTD && pin_ID <= pin7)
	{
		
		
		if (direction == OUTPUT)
		{
			switch(port_ID)
			{
				case PORTA: SET_BIT(DDRA_Reg , pin_ID) ; break;
				case PORTB: SET_BIT(DDRB_Reg , pin_ID) ; break;
				case PORTC: SET_BIT(DDRC_Reg , pin_ID) ; break;
				case PORTD: SET_BIT(DDRD_Reg , pin_ID) ; break;
			}
		}
		else if(direction == INPUT)
		{
			switch(port_ID)
			{
				case PORTA: CLEAR_BIT(DDRA_Reg , pin_ID) ; break;
				case PORTB: CLEAR_BIT(DDRB_Reg , pin_ID) ; break;
				case PORTC: CLEAR_BIT(DDRC_Reg , pin_ID) ; break;
				case PORTD: CLEAR_BIT(DDRD_Reg , pin_ID) ; break;
			}
		}
	}
}


void DIO_SetPortValue(DIO_Port_ID port_ID , u8 value)
{
	switch(port_ID)
	{
		case PORTA: PORTA_Reg = value ; break;
		case PORTB: PORTB_Reg = value ; break;
		case PORTC: PORTC_Reg = value ; break;
		case PORTD: PORTD_Reg = value ; break;
	}
}

void DIO_SetPinValue(DIO_Port_ID port_ID,DIO_Pin_ID Pin_ID , DIO_Value value)
{
	if (port_ID <= PORTD && Pin_ID <= pin7)
	{
		
		
		if (value == HIGH)
		{
			switch(port_ID)
			{
				case PORTA: SET_BIT(PORTA_Reg , Pin_ID) ; break;
				case PORTB: SET_BIT(PORTB_Reg , Pin_ID) ; break;
				case PORTC: SET_BIT(PORTC_Reg , Pin_ID) ; break;
				case PORTD: SET_BIT(PORTD_Reg , Pin_ID) ; break;
			}
		}
		else if(value == LOW)
		{
			switch(port_ID)
			{
				case PORTA: CLEAR_BIT(PORTA_Reg , Pin_ID) ; break;
				case PORTB: CLEAR_BIT(PORTB_Reg , Pin_ID) ; break;
				case PORTC: CLEAR_BIT(PORTC_Reg , Pin_ID) ; break;
				case PORTD: CLEAR_BIT(PORTD_Reg , Pin_ID) ; break;
			}
		}
	}
}

DIO_Value DIO_GetPinValue(DIO_Port_ID port_ID , DIO_Pin_ID Pin_ID )
{
	DIO_Value pinvalue;
	if (port_ID <= PORTD && Pin_ID <= pin7)
	{
		switch(port_ID)
		{
			case PORTA:pinvalue = GET_BIT(PINA_Reg , Pin_ID) ; break;
			case PORTB:pinvalue = GET_BIT(PINB_Reg , Pin_ID) ; break;
			case PORTC:pinvalue = GET_BIT(PINC_Reg , Pin_ID) ; break;
			case PORTD:pinvalue = GET_BIT(PIND_Reg , Pin_ID) ; break;
		}
	}
	return pinvalue;
}

void DIO_TogglePin(DIO_Port_ID port_ID , DIO_Pin_ID Pin_ID )
{
	if (port_ID <= PORTD && Pin_ID <= pin7)
		{
			switch(port_ID)
			{
				case PORTA: TOGGLE_BIT(PORTA_Reg , Pin_ID) ; break;
				case PORTB: TOGGLE_BIT(PORTB_Reg , Pin_ID) ; break;
				case PORTC: TOGGLE_BIT(PORTC_Reg , Pin_ID) ; break;
				case PORTD: TOGGLE_BIT(PORTD_Reg , Pin_ID) ; break;
			}
		}
}