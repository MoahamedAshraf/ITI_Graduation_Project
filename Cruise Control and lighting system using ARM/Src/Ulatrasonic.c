#include "MGPIO_Interface.h"
#include "MSTK_Interface.h"
#include "MNVIC_Interface.h"
#include "MEXTI_Interface.h"
#include "Timer_Interface.h"
#include "Ultrasonic.h"
#include "Ultrasonic_Config.h"

extern u32 volatile Distance;
u32 IC_Val1;
u32 IC_Val2;
u32 Time;
u8 flag;


void TIM3_IRQHandler(void)
{

	if (flag == 0)
	{
		IC_Val1 = Timer3_voidReadCaptureVal();
		flag = 1;
	}
	else if(flag == 1)
	{
		IC_Val2 = Timer3_voidReadCaptureVal();
		Timer3_u16Count(0);
		flag = 0;
		Time = IC_Val2 - IC_Val1;
		Distance = Time * .343 / 3.85;

	}
}



void Ultrsonic_Trigger(void)
{
	MGPIO_voidSetPinValue(UltraPort,Trigger_Pin,MGPIO_PIN_HIGH);
	MSTK_voidDelay_us(15);
	MGPIO_voidSetPinValue(UltraPort,Trigger_Pin,MGPIO_PIN_LOW);
}







