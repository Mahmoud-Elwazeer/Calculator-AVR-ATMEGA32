/*
 * LCD_KEYPAD.h
 *
 * Created: 8/8/2022 10:31:14 PM
 *  Author: Mahmoud Elwazeer
 */ 


#ifndef KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_H_


#include "DIO.h"


#define OUT_Port             PORTD
#define FIRST_OUT_Pin        pin0

#define INP_Port             PORTD
#define FIRST_INP_Pin        pin4

#define ROW              4
#define COLUMN           4

#define DEFAULT_KEY       '.'

void Keypad_init();
u8 keypad_Data(void);



#endif /* KEYPAD_DRIVER_H_ */