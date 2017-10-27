/*
 * Gpio.c
 *
 *  Created on: Oct 27, 2017
 *      Author: Lee Theng Chun
 */

#include "Gpio.h"

void gpioGConfig(int pin,int mode,int outDriveType,int pullType,int speed){
	GpioG->mode &= ~(3 << (pin*2)); 				//clear pin mode to 0 first
	GpioG->mode |= mode << (pin*2); 				//set pin mode

	GpioG->outSpeed &= ~(3 << (pin*2));			//clear pin speed to 0 first
	GpioG->outSpeed |= speed << (pin*2);			//set pin speed

	GpioG->pullType &= ~(3 << (pin*2));				//clear pin pull-type to 0 first
	GpioG->pullType |= pullType << (pin*2);			//set pin pull-type

	GpioG->outType &= ~(1 << pin);					//clear drive type to 0 first
	GpioG->outType |= outDriveType << pin;			//set drive type

}

void gpioGWrite(int pin,int state){
	if(state == 1){
		GpioG->outData |= 1<< pin;
	}
	else{
		GpioG->outData &= ~(1 << pin);
	}
}
