/*
 * Gpio.c
 *
 *  Created on: Oct 27, 2017
 *      Author: Lee Theng Chun
 */

#include "Gpio.h"
void gpioConfig(GpioReg *gpio,int pin,int mode,int outDriveType,int pullType,int speed){
	gpio->mode &= ~(3 << (pin*2)); 				//clear pin mode to 0 first
	gpio->mode |= mode << (pin*2); 				//set pin mode

	gpio->outSpeed &= ~(3 << (pin*2));			//clear pin speed to 0 first
	gpio->outSpeed |= speed << (pin*2);			//set pin speed

	gpio->pullType &= ~(3 << (pin*2));				//clear pin pull-type to 0 first
	gpio->pullType |= pullType << (pin*2);			//set pin pull-type

	gpio->outType &= ~(1 << pin);					//clear drive type to 0 first
	gpio->outType |= outDriveType << pin;			//set drive type

}

void gpioWrite(GpioReg *gpio,int pin,int state){
	if(state == 1){
		gpio->outData |= 1<< pin;
	}
	else{
		gpio->outData &= ~(1 << pin);
	}
}

int gpioRead(GpioReg *gpio,int pin){
	return gpio->inData & (1<<pin);
}
