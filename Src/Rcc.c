/*
 * Rcc.c
 *
 *  Created on: Oct 27, 2017
 *      Author: Lee Theng Chun
 */

#include "Rcc.h"

uint32_t *rccAHB1Rst = (uint32_t *)(RCC_BASE_ADDR + RCC_AHB1RST_OFF);
uint32_t *rccAHB1En = (uint32_t *)(RCC_BASE_ADDR + RCC_AHB1EN_OFF);

void enableGpioG(void){
	// Unreset GPIOG
	*rccAHB1Rst &= ~(1<<6);
	// Reset GPIOG
	*rccAHB1En |= (1<<6);
}


