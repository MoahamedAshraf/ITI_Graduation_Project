/***************************************************************************************/
/* Author               : Mohamed Ashraf
 * Version              : V0.0.0
 * Date                 : 17 - 1 -2023
 * Description          : MGPIO_Interface.h -> Function Prototypes
 * Module Features      :
 *        01- MGPIO_voidSetPinMode()
 *        02- MGPIO_voidSetPortMode()
 *        02- MGPIO_voidSetOutputType()
 *        03- MGPIO_voidSetOutputPinSpeed()
 *        04- MGPIO_voidSetPinPullType()
 *        05- MGPIO_voidSetPinValue()
 *        06- MGPIO_voidGetPinValue()
 * Future Update :
 * 					07-MGPIO_voidSetPinLock()
 * 					08-MGPIO_voidSetResetPin()
 * 					09-MGPIO_voidSetPinAltFunction()
 * */
/***************************************************************************************/

/***************************************************************************************/
/*                            Standard Types LIB                                       */
/***************************************************************************************/

#include <MGPIO_Config.h>
#include <MGPIO_Interface.h>
#include <MGPIO_Private.h>
#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "LBIT_MATH.h"


/***************************************************************************************/
/*                                    Lower Layer                                      */
/***************************************************************************************/


/***************************************************************************************/
/*                                    Own Header                                       */
/***************************************************************************************/


/***************************************************************************************/
/*                                    Function Implementation                          */
/***************************************************************************************/


/***************************************************************************************/
/*                         01- MGPIO_voidSetPinMode()                           	   */
/*-------------------------------------------------------------------------------------*/
/* @fu MGPIO_voidSetPinMode                                                  		   */
/* @brief  This Function used to set pin MODE									       */
/* 											-INPUT									   */
/* 											-OUTPUT									   */
/* 											-ALTF									   */
/* 											-ANLG                               	   */
/* @param[in] Copy_uddtPortNUM : The port of the PIN                             	   */
/* [MGPIO_PortA - MGPIO_PortB - MGPIO_PortC] Detect The Required Register              */
/* @param[in] Copy_uddtPINNum : the PIN Number										   */
/* 											[PIN0:PIN15]
 * @param[in] Copy_u8PinMode : the PIN Mode
 * 			[ MGPIO_PIN_INPUT, MGPIO_PIN_OUTPUT,  MGPIO_PIN_ALTF, MGPIO_PIN_ANLG       */
/***************************************************************************************/




void MGPIO_voidSetPinMode(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum , u8 Copy_u8PinMode)
{
	switch(Copy_uddtPortNum)
	{
	case MGPIO_PortA :
		Clr_BITS(MGPIOA -> MODER , (0b11 << Copy_uddtPinNum * 2U) );
		MGPIOA -> MODER  |= (u32) ((Copy_u8PinMode << Copy_uddtPinNum * 2U)); break;
	case MGPIO_PortB :
		Clr_BITS(MGPIOB -> MODER , (0b11 << Copy_uddtPinNum * 2U) );
		MGPIOB -> MODER  |= (u32) ((Copy_u8PinMode << Copy_uddtPinNum * 2U)); break;
	case MGPIO_PortC :
		Clr_BITS(MGPIOC -> MODER , (0b11 << Copy_uddtPinNum * 2U) );
		MGPIOC -> MODER  |= (u32) ((Copy_u8PinMode << Copy_uddtPinNum * 2U)); break;
	default : /* do nothing*/ break;
	}
}

/***************************************************************************************/
/*                         02- MGPIO_voidSetPortMode()
 *--------------------------------------------------------------------------------------
 * @fu MGPIO_voidSetPortMode
 * @brief  This Function used to set port MODE
 * 											-INPUT
 * 											-OUTPUT
 * 											-ALTF
 * 											-ANLG
 * @param[in] Copy_uddtPortNUM : The Port number
 * [MGPIO_PortA - MGPIO_PortB - MGPIO_PortC] Detect The Required Register
 *
 * @param[in] Copy_u8PortMode : the Port Mode
 * 			[ MGPIO_Port_INPUT, MGPIO_Port_OUTPUT,  MGPIO_Port_ALTF, MGPIO_Port_ANLG ]
 **/
/***************************************************************************************/



void MGPIO_voidSetPortMode(MGPIO_t Copy_uddtPortNum , u8 Copy_u8PortMode)
{
	switch(Copy_uddtPortNum)
	{

	/*************MGPIO_PortA*****************/

	case MGPIO_PortA :
		switch(Copy_u8PortMode)
		{
		case MGPIO_PORT_INPUT :
			Clr_ALL_BITS(MGPIOA -> MODER); break;
		case MGPIO_PORT_OUTPUT :
			Clr_ALL_BITS(MGPIOA -> MODER);
			MGPIOA -> MODER = 0x55555555;
			break;
		case MGPIO_PORT_ALTF :
			Clr_ALL_BITS(MGPIOA -> MODER);
			MGPIOA -> MODER = 0xAAAAAAAA;
			break;
		case MGPIO_PORT_ANLG :
			Clr_ALL_BITS(MGPIOA -> MODER);
			Set_ALL_BITS(MGPIOA -> MODER);
			break;
		default :
			break;
		}break;


		/*************MGPIO_PortB*****************/


		case MGPIO_PortB :
			switch(Copy_u8PortMode)
			{
			case MGPIO_PORT_INPUT :
				Clr_ALL_BITS(MGPIOB -> MODER); break;
			case MGPIO_PORT_OUTPUT :
				Clr_ALL_BITS(MGPIOB -> MODER);
				MGPIOB -> MODER = 0x55555555;
				break;
			case MGPIO_PORT_ALTF :
				Clr_ALL_BITS(MGPIOB -> MODER);
				MGPIOB -> MODER = 0xAAAAAAAA;
				break;
			case MGPIO_PORT_ANLG :
				Clr_ALL_BITS(MGPIOB -> MODER);
				Set_ALL_BITS(MGPIOB -> MODER);
				break;
			default :
				break;
			}break;


			/*************MGPIO_PortC*****************/


			case MGPIO_PortC :
				switch(Copy_u8PortMode)
				{
				case MGPIO_PORT_INPUT :
					Clr_ALL_BITS(MGPIOC -> MODER); break;
				case MGPIO_PORT_OUTPUT :
					Clr_ALL_BITS(MGPIOC -> MODER);
					MGPIOC -> MODER = 0x55555555;
					break;
				case MGPIO_PORT_ALTF :
					Clr_ALL_BITS(MGPIOC -> MODER);
					MGPIOC -> MODER = 0xAAAAAAAA;
					break;
				case MGPIO_PORT_ANLG :
					Clr_ALL_BITS(MGPIOC -> MODER);
					Set_ALL_BITS(MGPIOC -> MODER);
					break;

				default : break;
				}
				break;
	}
}

void MGPIO_voidSetOutputType(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum , OutputType_t CopyuddtPinOutType)
{
	switch(Copy_uddtPortNum)
	{
	case MGPIO_PortA :
		MGPIOA -> OTYPER  = (u32) ((CopyuddtPinOutType << Copy_uddtPinNum )); break;
	case MGPIO_PortB :
		MGPIOB -> OTYPER  = (u32) ((CopyuddtPinOutType << Copy_uddtPinNum )); break;
	case MGPIO_PortC :
		MGPIOC -> OTYPER  = (u32) ((CopyuddtPinOutType << Copy_uddtPinNum )); break;
	default : /* do nothing*/ break;
	}
}

void MGPIO_voidSetOutputPinSpeed(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum , Speed_t CopyuddtPinOutSpeed)
{
	switch (Copy_uddtPortNum)
	{
	case MGPIO_PortA :
		MGPIOA -> OSPEEDR = (CopyuddtPinOutSpeed << Copy_uddtPinNum * 2U); break;
	case MGPIO_PortB :
		MGPIOB -> OSPEEDR = (CopyuddtPinOutSpeed << Copy_uddtPinNum * 2U); break;
	case MGPIO_PortC :
		MGPIOC -> OSPEEDR = (CopyuddtPinOutSpeed << Copy_uddtPinNum * 2U); break;
	}
}

void MGPIO_voidSetPinPullType(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum , u8 Copy_u8PullMode)
{
	switch (Copy_uddtPortNum)
	{
	case MGPIO_PortA :
		Clr_BITS(MGPIOA->PUPDR,(3U<<Copy_uddtPortNum * 2U)) ;
		MGPIOA -> PUPDR |= (u32)((Copy_u8PullMode << Copy_uddtPinNum * 2U )); break;
	case MGPIO_PortB :
		Clr_BITS(MGPIOA->PUPDR,(3U<<Copy_uddtPortNum * 2U)) ;
		MGPIOB -> PUPDR |= (u32)((Copy_u8PullMode << Copy_uddtPinNum * 2U )); break;
	case MGPIO_PortC :
		Clr_BITS(MGPIOA->PUPDR,(3U<<Copy_uddtPortNum * 2U)) ;
		MGPIOC -> PUPDR |= (u32)((Copy_u8PullMode << Copy_uddtPinNum * 2U )); break;
	}

}

void MGPIO_voidSetPinValue(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum , u8 Copy_u8PinValue)
{
	switch (Copy_uddtPortNum)
	{
	case MGPIO_PortA :
		CLR_BIT(MGPIOA -> ODR, Copy_uddtPinNum);
		MGPIOA -> ODR |= (u32) ((Copy_u8PinValue << Copy_uddtPinNum )); break;
	case MGPIO_PortB :
		CLR_BIT(MGPIOB -> ODR, Copy_uddtPinNum);
		MGPIOB -> ODR |= (u32) ((Copy_u8PinValue << Copy_uddtPinNum )); break;
	case MGPIO_PortC :
		CLR_BIT(MGPIOB -> ODR, Copy_uddtPinNum);
		MGPIOC -> ODR |= (u32) ((Copy_u8PinValue << Copy_uddtPinNum )); break;
	default : /* nothin */ break;
	}
}


void MGPIO_voidSetPortValue(MGPIO_t Copy_uddtPortNum , u8 Copy_u8PortValue)
{
	switch (Copy_uddtPortNum)
	{
	case MGPIO_PortA :

		MGPIOA -> ODR = Copy_u8PortValue ; break ;
		switch (Copy_u8PortValue)
		{

		case MGPIO_PORT_HIGH :
			Set_ALL_BITS(MGPIOA -> ODR); break;
		case MGPIO_PORT_LOW :
			Clr_ALL_BITS(MGPIOA -> ODR); break;
		default :MGPIOA -> ODR = Copy_u8PortValue ; break ;
			// MGPIOA -> ODR = (Copy_u8PortValue << Copy_uddtPortNum); break;

		}break;


		case MGPIO_PortB :

			MGPIOB -> ODR = Copy_u8PortValue ; break ;

			switch (Copy_u8PortValue)
			{
			case MGPIO_PORT_HIGH :
				Set_ALL_BITS(MGPIOB -> ODR); break;
			case MGPIO_PORT_LOW :
				Clr_ALL_BITS(MGPIOB -> ODR); break;
			default : MGPIOB -> ODR = Copy_u8PortValue ; break ;
				//MGPIOB -> ODR = (Copy_u8PortValue << Copy_uddtPortNum); break;
			}break;


			case MGPIO_PortC :

				MGPIOC -> ODR = Copy_u8PortValue ; break ;

				switch (Copy_u8PortValue)
				{
				case MGPIO_PORT_HIGH :
					Set_ALL_BITS(MGPIOC -> ODR); break;
				case MGPIO_PORT_LOW :
					Clr_ALL_BITS(MGPIOC -> ODR); break;
				default :MGPIOC -> ODR = Copy_u8PortValue ; break ;
					//MGPIOC -> ODR = (Copy_u8PortValue << Copy_uddtPortNum); break;
				}break;
			default : /* nothin */ break;
	}
}


u8 MGPIO_voidGetPinValue(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum)
{
	u8 ret;
	switch (Copy_uddtPortNum)
	{
	case MGPIO_PortA :
		ret = GET_BIT(MGPIOA -> IDR , Copy_uddtPinNum); break;
	case MGPIO_PortB :
		ret = GET_BIT(MGPIOB -> IDR , Copy_uddtPinNum); break;
	case MGPIO_PortC :
		ret = GET_BIT(MGPIOC -> IDR , Copy_uddtPinNum); break;
	}
	return ret;
}

void MGPIO_voidSetResetPin(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum ,SetReset_t Copy_u8AtomPinMode)
{
	switch (Copy_uddtPortNum)
	{
	case MGPIO_PortA :

		switch (Copy_u8AtomPinMode)
		{
		case Reset :
			MGPIOA -> BSRR = (1 << Copy_uddtPinNum * 2U); break;
		case Set :
			MGPIOA -> BSRR = (1 << Copy_uddtPinNum ); break;
		}break;

		case MGPIO_PortB :

			switch (Copy_u8AtomPinMode)
			{
			case Reset :
				MGPIOA -> BSRR = (1 << Copy_uddtPinNum * 2U); break;
			case Set :
				MGPIOA -> BSRR = (1 << Copy_uddtPinNum ); break;
			}break;

			case MGPIO_PortC :

				switch (Copy_u8AtomPinMode)
				{
				case Reset :
					MGPIOA -> BSRR = (1 << Copy_uddtPinNum * 2U); break;
				case Set :
					MGPIOA -> BSRR = (1 << Copy_uddtPinNum ); break;
				}break;

	}
}

void MGPIO_voidSetPinLock(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum )
{
	switch (Copy_uddtPortNum)
	{
	case MGPIO_PortA :
		MGPIOA -> LCKR = (u32) (0x00010000 | (1 << Copy_uddtPinNum));
		MGPIOA -> LCKR = (u32) (0x00000000 | (1 << Copy_uddtPinNum));
		MGPIOA -> LCKR = (u32) (0x00010000 | (1 << Copy_uddtPinNum));
		break;
	case MGPIO_PortB :
		MGPIOB -> LCKR = (u32) (0x00010000 | (1 << Copy_uddtPinNum));
		MGPIOB -> LCKR = (u32) (0x00000000 | (1 << Copy_uddtPinNum));
		MGPIOB -> LCKR = (u32) (0x00010000 | (1 << Copy_uddtPinNum));
		break;
	case MGPIO_PortC :
		MGPIOC -> LCKR = (u32) (0x00010000 | (1 << Copy_uddtPinNum));
		MGPIOC -> LCKR = (u32) (0x00000000 | (1 << Copy_uddtPinNum));
		MGPIOC -> LCKR = (u32) (0x00010000 | (1 << Copy_uddtPinNum));
		break;

	}
}


void MGPIO_voidSetPinAltFunction(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum , ALTF_t Copy_uddtALF)
{
	switch (Copy_uddtPortNum)
	{
	case MGPIO_PortA :
		if(Copy_uddtPinNum >= 0 && Copy_uddtPinNum <= 7)
		{
			MGPIOA -> AFRL |= (u32) (Copy_uddtALF << (Copy_uddtPinNum * 4U));
		}
		else if(Copy_uddtPinNum >= 8 && Copy_uddtPinNum <= 15)
		{
			MGPIOA -> AFRH |= (u32) (Copy_uddtALF << (4U * (Copy_uddtPinNum %8U)));
		}
		break;
	case MGPIO_PortB :
		if(Copy_uddtPinNum >= 0 && Copy_uddtPinNum <= 7)
		{
			MGPIOB -> AFRL |= (u32) (Copy_uddtALF << (Copy_uddtPinNum * 4U));
		}
		else if(Copy_uddtPinNum >= 8 && Copy_uddtPinNum <= 15)
		{
			MGPIOB -> AFRH |= (u32) (Copy_uddtALF << (4U * (Copy_uddtPinNum %8U)));
		}
		break;
	case MGPIO_PortC :
		if(Copy_uddtPinNum >= 0 && Copy_uddtPinNum <= 7)
		{
			MGPIOC -> AFRL |= (u32) (Copy_uddtALF << (Copy_uddtPinNum * 4U));
		}
		else if(Copy_uddtPinNum >= 8 && Copy_uddtPinNum <= 15)
		{
			MGPIOC -> AFRH |= (u32) (Copy_uddtALF << (4U * (Copy_uddtPinNum %8U)));
		}
		break;
	}
}












