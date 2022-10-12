/*
 * Calculator.h
 *
 * Created: 10/12/2022 12:09:26 PM
 *  Author: fage
 */ 


#ifndef CALCULATOR_H_
#define CALCULATOR_H_



#include "KEYPAD_Driver.h"
#include "LCD_Driver.h"

void Calc();

void sum(u16 n1 , u16 n2);
void sub(u16 n1 , u16 n2);
void mul(u16 n1 , u16 n2);
void div(u16 n1 , u16 n2);


#endif /* CALCULATOR_H_ */