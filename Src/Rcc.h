/*
 * Rcc.h
 *
 *  Created on: Oct 27, 2017
 *      Author: Lee Theng Chun
 */

#ifndef RCC_H_
#define RCC_H_

#include <stdint.h>

#define RCC_BASE_ADDR		0x40023800
#define RCC_AHB1RST_OFF		0x10
#define RCC_AHB1EN_OFF		0x30

//Export variables to other modules
extern uint32_t *rccAHB1Rst;
extern uint32_t *rccAHB1En;

void enableGpioA(void);
void enableGpioB(void);
void enableGpioG(void);
#endif /* RCC_H_ */
