/*
 * DIO_types.h
 *
 * Created: 9/4/2022 7:18:06 PM
 *  Author: Mahmoud Elwazeer
 */ 


#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

typedef enum {
	INPUT,          // 0
	OUTPUT          // 1   
	} DIO_Direction;

typedef enum {
	PORTA,
	PORTB,
	PORTC,
	PORTD
	}DIO_Port_ID;
	
typedef enum{
	pin0,
	pin1,
	pin2,
	pin3,
	pin4,
	pin5,
	pin6,
	pin7
	}DIO_Pin_ID;

typedef enum {
	LOW,          // 0
	HIGH          // 1
} DIO_Value;

#endif /* DIO_TYPES_H_ */