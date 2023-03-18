/*
 * HMOTOR_PWM_Prog.c
 *
 *  Created on: Feb 13, 2023
 *      Author: abdel
 */
/***************************************************************************************/
/*                            Standard Types LIB                                       */
/***************************************************************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
/***************************************************************************************/
/*                                     MCAL Layer                                      */
/***************************************************************************************/
#include "MRCC_Interface.h"
#include "MSTK_Interface.h"
#include "MGPIO_Interface.h"
#include "MNVIC_Interface.h"
#include "MEXTI_Interface.h"
#include "TMR_priv.h"
#include "TMR_int.h"
#include "Timer_Interface.h"
#include "MUSART_Interface.h"
/***************************************************************************************/
/*                                     HAL Layer                                       */
/***************************************************************************************/
#include "HMOTOR_PWM_Interface.h"
#include "LightingSys.h"
/***************************************************************************************/
/*                         Global Variables                                            */
/***************************************************************************************/
extern volatile u8 Global_Data_Recieved;
extern volatile u16 speed_level;
extern volatile u16 speed_selected;
extern volatile u16 speed;
extern volatile u8 mode;
extern volatile u8 range;
extern volatile u8 upper_limit;
extern volatile u8 lower_limit;
extern volatile u32 Distance;


/***************************************************************************************/
/*                                  System Functions                                   */
/***************************************************************************************/
void sys_init()
{
	/*System Clock initialization*/
	MRCC_voidInitSystemClock();
	/*--------------------------------------- Timer 3 ----------------------------------------------------*/
	/*GPIO pins initialization*/
	MRCC_voidEnablePeripheralClock(AHB1,MRCC_PERIPHERIAL_EN_GPIOA);
	MRCC_voidEnablePeripheralClock(AHB1,MRCC_PERIPHERIAL_EN_GPIOB);
	MRCC_voidEnablePeripheralClock(AHB1,MRCC_PERIPHERIAL_EN_GPIOC);
	MGPIO_voidSetPinMode(MGPIO_PortA,PIN6,MGPIO_PIN_ALTF);
	MGPIO_voidSetPinAltFunction(MGPIO_PortA,PIN6,AF2);
	MRCC_voidEnablePeripheralClock(APB1,MRCC_PERIPHERIAL_EN_TIM3);
	MGPIO_voidSetPinMode(MGPIO_PortA,PIN5,MGPIO_PIN_OUTPUT);

	/*Interrupt initialization*/
	MNVIC_voidEnableInterrupt(29); // Enable Timer3 Global Interrupt

	/*Timer initialization*/
	Timer3_voidCapture_Compare_Init();

	/*------------------------------------ Timer 2 ------------------------------------------------------ */

	/* GPIO pins initialization for DC motor PWM Timer 2*/
	MRCC_voidEnablePeripheralClock(APB1,MRCC_PERIPHERIAL_EN_TIM2);
	// to control the motors
	MGPIO_voidSetPinMode(MGPIO_PortA,PIN0,MGPIO_PIN_ALTF);
	MGPIO_voidSetPinAltFunction(MGPIO_PortA,PIN0,AF1);

	// to control the buzzer
	MGPIO_voidSetPinMode(MGPIO_PortA,PIN2,MGPIO_PIN_ALTF);
	MGPIO_voidSetPinAltFunction(MGPIO_PortA,PIN2,AF1);


	/* speed init */
	TMR_voidSetPrescaler(TMR2, 160);
	TMR_voidSetARR(TMR2,  1000 - 1);
	TMR_voidSetChannelOutput(TMR2, PWM_MODE1,  CH1);
	// PWM for the buzzer
	TMR_voidSetChannelOutput(TMR2, PWM_MODE1,  CH3);

	/*--------------------------------- Motors -----------------------------------------------------------*/

	/* Set Mode for Motor Input Pins */
	//	MGPIO_voidSetPinMode(MGPIO_PortA, PIN1, MGPIO_PIN_OUTPUT);
	//	MGPIO_voidSetPinMode(MGPIO_PortA, PIN2, MGPIO_PIN_OUTPUT);
	//	MGPIO_voidSetPinMode(MGPIO_PortA, PIN3, MGPIO_PIN_OUTPUT);
	//	MGPIO_voidSetPinMode(MGPIO_PortA, PIN4, MGPIO_PIN_OUTPUT);

	/*----------------------------------------- UART ----------------------------------------------------- */

	/*Enable RCC For USART1*/
	MRCC_voidEnablePeripheralClock(APB2, MRCC_PERIPHERIAL_EN_USART1); //Enable CLK Of UART1   At APB2

	/*Configure UART1 ,UART2  Pins*/
	MGPIO_voidSetPinMode(MGPIO_PortA, PIN9, MGPIO_PIN_ALTF);     //TX-->UART1
	MGPIO_voidSetPinMode(MGPIO_PortA, PIN10, MGPIO_PIN_ALTF);    //RX-->UART1
	MGPIO_voidSetPinAltFunction(MGPIO_PortA, PIN9, AF7);      //TX-->UART1
	MGPIO_voidSetPinAltFunction(MGPIO_PortA, PIN10, AF7);     //RX-->UART1

	/*Enable Peripherials interrupt from NVIC */
	MNVIC_voidEnableInterrupt(37) ;              //Enable uart1 from NVIC

	/*Initialize USART1*/
	MSUART_voidInit();

	/*initialize system Peripherals*/
	MUSART_voidEnable(1) ; //Enable UART 1

	/*------------------------------------------- LEDS ---------------------------------------------- */
	/* leds */
	//	MGPIO_voidSetPinMode(MGPIO_PortB, PIN0, MGPIO_PIN_OUTPUT);
	//	MGPIO_voidSetPinMode(MGPIO_PortB, PIN1, MGPIO_PIN_OUTPUT);
	//	MGPIO_voidSetPinMode(MGPIO_PortB, PIN2, MGPIO_PIN_OUTPUT);

	/*--------------------------------------- LIGHTING SYS ------------------------------------------- */
	/*GPIO pins initialization*/

	/* Set Mode for Lighting system Pins */
	MGPIO_voidSetPortMode(MGPIO_PortB, MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PortA, PIN15, MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PortA, PIN7 , MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PortA, PIN8 , MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PortA, PIN11, MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_PortA, PIN12, MGPIO_PIN_OUTPUT);

	/*--------------------------------------- ENCODER EXTI ------------------------------------------- */

	MRCC_voidEnablePeripheralClock(APB2,MRCC_PERIPHERIAL_EN_EXTI);
	MGPIO_voidSetPinMode(MGPIO_PortA,PIN4,MGPIO_PIN_INPUT);
	MGPIO_voidSetPinPullType(MGPIO_PortA,PIN4,MGPIO_PIN_PULL_DOWN);
	MEXTI_voidEnableEXTI(Line_4);
	MEXTI_voidSenseMode(RISING);
	MNVIC_voidEnableInterrupt(10);

}

void start_motor()
{
	/* Set Value for Motor Input Pins to START MOTOR */
	MGPIO_voidSetPinValue(MGPIO_PortB, PIN12, MGPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(MGPIO_PortB, PIN13, MGPIO_PIN_LOW);
	MGPIO_voidSetPinValue(MGPIO_PortB, PIN14, MGPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(MGPIO_PortB, PIN15, MGPIO_PIN_LOW);
}

void stop_motor()
{
	/* Set Value for Motor Input Pins to START MOTOR */
	MGPIO_voidSetPinValue(MGPIO_PortB, PIN12, MGPIO_PIN_LOW);
	MGPIO_voidSetPinValue(MGPIO_PortB, PIN13, MGPIO_PIN_LOW);
	MGPIO_voidSetPinValue(MGPIO_PortB, PIN14, MGPIO_PIN_LOW);
	MGPIO_voidSetPinValue(MGPIO_PortB, PIN15, MGPIO_PIN_LOW);
}

void config()
{
	switch(Global_Data_Recieved)
	{
	case 'A':
		if (mode == OFFCC)
		{
			speed_level +=50;
			LIGHTING_SYS_ACCELERATE();
		}
		else
		{
			// ACC or NCC are ON
//			if (speed_level < speed_selected)
//			{
//				speed_level +=50;
//				LIGHTING_SYS_ACCELERATE();
//			}
//			else
//			{
//				// do not increase the speed beyond the selected speed
//			}
		}                                 break;
	case 'D':
		if (mode==ACC)
		{
			mode=NCC;
		}
		speed_level -=50;
		LIGHTING_SYS_DACCELERATE();       break;
	case 'S':
		mode = OFFCC;
		speed_level = 100;
		LIGHTING_SYS_STOP();              break;
	case 'O':
		mode = OFFCC;                     break;
	case 'N':
		mode = NCC;
		speed_selected = speed_level;     break;
	case 'P':
		mode= ACC;
		speed_selected = speed_level;     break;
	case 'C': range = CLOSE;              break;
	case 'M': range = MEDIUM;             break;
	case 'F': range = FAR;                break;
	case 'I': speed_selected+=50;         break;
	case 'J': speed_selected-=50;         break;
	default:                              break;
	}
	Global_Data_Recieved=' ';
}

void App_u8SetSpeedLevel()
{
	u32 duty_cycle;
	// checking speed level
	if (speed_level > 1000)
	{
		speed_level=1000; // to handle the case of speed_level exceeding 100%
	}
	else if (speed_level < 100)
	{
		speed_level=100;
	}
	else
	{
		// do nothing
	}

	// do not start motors at low duty cycle
	if (speed_level < 150)
	{
//		stop_motor();
		duty_cycle=0;
		speed = 0;
	}
	else
	{
//		start_motor();
		duty_cycle = speed_level;
		speed = (duty_cycle-100)/20;
	}
	// generating PWM signal with the required duty cycle
	TMR_voidSetCMPVal(TMR2, CH1, duty_cycle);
	TMR_voidStart(TMR2);
	MSTK_voidDelay_ms(10);
}

void decrease_speed()
{
	if (mode == OFFCC && speed_level > 100)
	{
		speed_level-=2;
	}
	else
	{
		// Cruise Control ON
	}
}

void buzzer_on()
{
	if (mode == NCC && Distance < 30 && speed_level >= 150)
	{
		SET_BIT(TMR2_ADD -> CCER, CC3EN_BIT);
		TMR_voidSetCMPVal(TMR2, CH3, 500 - 1);
	}
	else
	{
		CLR_BIT(TMR2_ADD -> CCER, CC3EN_BIT);
	}
}



void ACC_MODE()
{
	switch (range)
	{
	case FAR:
		upper_limit = UPPER_FAR;
		lower_limit = LOWER_FAR;
		break;
	case MEDIUM:
		upper_limit = UPPER_MEDIUM;
		lower_limit = LOWER_MEDIUM;
		break;
	case CLOSE:
		upper_limit = UPPER_CLOSE;
		lower_limit = LOWER_CLOSE;
		break;
	default: break;
	}

	range = ' ';

	// checking distance
	if (Distance > upper_limit)
	{
		speed_level+=10;
	}
	else if (Distance < lower_limit && Distance > DANGER_DISTANCE)
	{
		speed_level-=10;
	}
	else if (Distance <= DANGER_DISTANCE)
	{
		speed_level = 100;
		mode = OFFCC;
	}
	else
	{
		//the car within the selected range -> do nothing
	}

	/****************************** check on speed_selected **********************/
	if(speed_selected > 1000)
	{
		speed_selected=1000;
	}
	else if (speed_selected < 100)
	{
		speed_selected=100;
	}
	else
	{
		// speed_selected within range
	}
	/****************************************************************************/

	// checking speed level
	if (speed_level > speed_selected)
	{
		speed_level = speed_selected;
	}
	else
	{
		// the speed within the required range
	}
}

void NCC_MODE()
{
	/****************************** check on speed_selected **********************/
	if(speed_selected > 1000)
	{
		speed_selected=1000;
	}
	else if (speed_selected < 100)
	{
		speed_selected=100;
	}
	else
	{
		// speed_selected within range
	}
	/****************************************************************************/

	if (speed_level > speed_selected)
	{
		speed_level = speed_selected; //to handle the case of speed_level exceeding speed_selected
	}
	else
	{
		// speed level within range
	}
	if (Distance <= DANGER_DISTANCE)
	{
		speed_level =100;
		mode = OFFCC;
	}
	else
	{
		// car within the safe zone
	}
}
