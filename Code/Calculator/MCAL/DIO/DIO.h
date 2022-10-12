/*
 * DIO.h
 *
 * Created: 9/4/2022 7:16:04 PM
 *  Author: Mahmoud Elwazeer
 */ 


#ifndef DIO_H_
#define DIO_H_

#define F_CPU 8000000UL

#include <util/delay.h>
#include "DIO_types.h"
#include "BIT_Math.h"
#include "ATMEGA32_REG.h"
#include "Std_types.h"

void DIO_PortDirection(DIO_Port_ID port_ID ,DIO_Direction direction);
void DIO_PortDirectionValue(DIO_Port_ID port_ID , u8 value);
void DIO_PinDirection(DIO_Port_ID port_ID,DIO_Pin_ID pin_ID ,DIO_Direction direction);

void DIO_SetPortValue(DIO_Port_ID port_ID , u8 value);
void DIO_SetPinValue(DIO_Port_ID port_ID,DIO_Pin_ID Pin_ID , DIO_Value value);

DIO_Value DIO_GetPinValue(DIO_Port_ID port_ID , DIO_Pin_ID Pin_ID );

void DIO_TogglePin(DIO_Port_ID port_ID , DIO_Pin_ID Pin_ID );


#endif /* DIO_H_ */