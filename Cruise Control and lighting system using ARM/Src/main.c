/*
 * main.c
 *
 *  Created on: 25 Jan 2023
 *      Author: Mohamed Ashraf
 */

/***************************************************************************************/
/*                            Standard Types LIB                                       */
/***************************************************************************************/
#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "LBIT_MATH.h"
/***************************************************************************************/
/*                                     MCAL Layer                                      */
/***************************************************************************************/
#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"
#include "MSTK_Interface.h"
#include "MNVIC_Interface.h"
#include "MEXTI_Interface.h"
#include "MUSART_Interface.h"
#include "Timer_Interface.h"
#include "TMR_int.h"
/***************************************************************************************/
/*                                     HAL Layer                                       */
/***************************************************************************************/
#include "Ultrasonic.h"
#include "HMOTOR_PWM_Interface.h"
#include "Encoder.h"
/**************************************************************************************/

// GLOBAL VARIABLES
volatile u8 Global_Data_Recieved;
volatile u16 speed;
volatile u16 speed_level;
volatile u16 speed_selected;
volatile u8 mode;
volatile u8 range;
volatile u8 upper_limit;
volatile u8 lower_limit;
volatile u32 Distance;
volatile u32 pulse;
//Converted Distance value array
u8 D[10];
//Converted Speed value array
u8 S[10];
//received data array
u8 array[22];
void main (void)
{
	sys_init();
	Timer3_voidStart();
	speed_level=100;
	//speed_selected=' '; // not sure if its going to work that way but hopefully it displays nothing on the text box
	mode = OFFCC;
	range= CLOSE;

	while(1)
	{

		Ultrsonic_Trigger();
		//Speed_Calc();

		config();

		if (mode == ACC)
		{
			ACC_MODE();
		}
		else if (mode == NCC)
		{
			NCC_MODE();
		}
		else
		{
			// system is in normal driving mode -> speed_level changed manually
		}

		App_u8SetSpeedLevel();
		decrease_speed();
		buzzer_on();


		//Sending motor speed and distance to raspberry pi

		u8 loop, index, S_len, D_len;

		S_len = D_len = 10;

		index = 0;


		itoa (speed, S, 10);
		for(loop = 0; loop < S_len; loop++)
		{
			array[index] = S[loop];
			index++;
		}

		array[index]=' ';
		index++;

		itoa (Distance, D, 10);
		for(loop = 0; loop < D_len; loop++)
		{
			array[index] = D[loop];
			index++;
		}
		array[index]='\r';
		index++;

		MUSART_u8SendData(1,array,22);
		array[0]='\0';
		S[0]='\0';
		D[0]='\0';
	}
}










