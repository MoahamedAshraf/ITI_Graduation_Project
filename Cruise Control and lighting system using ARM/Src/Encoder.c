/*
 * Encoder.c
 *
 *  Created on: 2 Mar 2023
 *      Author: user
 */

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

#include "MNVIC_Interface.h"
#include "MSTK_Interface.h"
#include "MEXTI_Interface.h"
#include "Encoder.h"


extern volatile u32 pulse;
volatile u32 PulsesPerRev = 383;
extern volatile u16 speed;


void Speed_Calc()
{
	u32 rpm;
	rpm = (pulse * 60) / PulsesPerRev;
	if(rpm > 0)
	{
		speed = ((rpm * 2 * 3.14 * 33.5)/1000);

	}
	pulse = 0;
	MSTK_voidDelay_ms(50);

}

void EXTI4_IRQHandler(void)
{
	pulse++;

	MEXTI_voidPendingRegister(Line_4);
}



