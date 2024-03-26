/*
 * led.c
 *
 *  Created on: Mar 25, 2024
 *      Author: liran
 */

#include "led.h"

#define pGpioB 0x40020400

#define pRcc 0x40023800

#define Gpio_out 0x14
#define Apb1_en 0x40

#define Ahb_en 0x30


#define Led_Pin 6
static uint32_t* pPortBModeReg  =(uint32_t*) pGpioB;
static uint32_t* pPortBOutReg =(uint32_t*) (pGpioB+Gpio_out);

static uint32_t* pClkCntrReg = (uint32_t*)(pRcc + Ahb_en);
static uint32_t* pApb1_en = (uint32_t*) (pRcc+Apb1_en);

void led_init()
//initialize led to port b and pin 6 as output and enable apb1 for tim2
//turn led on
{
	*pClkCntrReg |=(1<<1);
	*pPortBModeReg |=(1<<(12));
	*pApb1_en |=(1<<0);
	*pPortBOutReg |=(1<<6);
}

void led_toggle()
{
	*pPortBOutReg ^=(1<<6);
}
