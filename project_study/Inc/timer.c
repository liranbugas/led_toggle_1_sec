/*
 * timer.c
 *
 *  Created on: Mar 25, 2024
 *      Author: liran
 */
#include "timer.h"


#define pTim2 0x40000000

#define Tim2_psc 0x28
#define	Tim2_arr 0x2C
#define Tim2_sr  0x10

static uint32_t* pTim2_Psc=(uint32_t*) (pTim2+Tim2_psc);
static uint32_t* pTim2_Cr=(uint32_t*)  pTim2;
static uint32_t* pTim2_Arr=(uint32_t*) (pTim2 +Tim2_arr);
static uint32_t* pTim2_Sr =(uint32_t*) (pTim2+Tim2_sr);

void timer_ini()
//initialize timer2 parameters and 1 second delay
{
	*pTim2_Psc |= 0x3E7;
	*pTim2_Arr &=~0xFFFFFFFF;
	*pTim2_Arr |= 0x3E80;


}
void timer_start()
//start timer
{
	*pTim2_Cr |=(1<<0);
}
bool timer_check()
//check if passes 1 second
{
	int temp = (*pTim2_Sr)&(0x1);
	if(temp)
	{
		*pTim2_Sr &=0;
		return true;
	}
	return false;
}
