/*
 * BIT_Math.h
 *
 * Created: 9/4/2022 8:35:16 PM
 *  Author: Mahmoud Elwazeer
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(port_ID , pin_ID)        ((port_ID) |= (1<<pin_ID))
#define CLEAR_BIT(port_ID , pin_ID)      ((port_ID) &= ~(1<<pin_ID))
#define TOGGLE_BIT(port_ID , pin_ID)     ((port_ID) ^= (1<<pin_ID))
#define GET_BIT(port_ID , pin_ID)        ((port_ID) >> (pin_ID) & 0x01)




#endif /* BIT_MATH_H_ */