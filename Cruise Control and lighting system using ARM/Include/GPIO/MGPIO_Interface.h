/***************************************************************************************/
/* Author               : Mohamed Ashraf
* Version              : V0.0.0
* Date                 : 17 - 1 -2023
* Description          : MGPIO_Interface.h -> Function Prototypes
* Module Features      :
*        01- MGPIO_voidSetPinMode()
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
/** What i sell to customer                                                            */
/** The Architecture Give The API                                                      */
/*                    - The Name Of Function                                           */
/*                    - What is The input                                              */
/*                    - What is The Output                                             */
/*                    - Macro                                                          */
/***************************************************************************************/


/***************************************************************************************/
/*                            Guard of file will call on time in c file                */
/***************************************************************************************/

/***************************************************************************************/
/*                            Standard Types LIB                                       */
/***************************************************************************************/

#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "LBIT_MATH.h"


#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_

/**********************************************************************************************/
/*                                   GPIO Port Name                                           */
/**********************************************************************************************/

typedef enum
{
	MGPIO_PortA,
	MGPIO_PortB,
	MGPIO_PortC

}MGPIO_t;

/*****************************************************************************************/
/*                                   PIN Num                                           */
/*****************************************************************************************/

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}PIN_t;


/*****************************************************************************************/
/*                                   Speed Type                                          */
/*****************************************************************************************/

typedef enum
{
	MGPIO_SPEED_LOW,
	MGPIO_SPEED_MED,
	MGPIO_SPEED_HIGH,
	MGPIO_SPEED_VHIGH
}Speed_t;

/*****************************************************************************************/
/*                                   PIN_MODE                                            */
/*****************************************************************************************/

//#define MGPIO_PIN_INPUT  0b00
//#define MGPIO_PIN_OUTPUT 0b01
//#define MGPIO_PIN_ALTF   0b10
//#define MGPIO_PIN_ANLG   0b11

typedef enum
{
	MGPIO_PIN_INPUT,
	MGPIO_PIN_OUTPUT,
	MGPIO_PIN_ALTF,
	MGPIO_PIN_ANLG
}PinMode_t;

/*****************************************************************************************/
/*                                   Port_MODE                                            */
/*****************************************************************************************/

typedef enum
{
	MGPIO_PORT_INPUT,
	MGPIO_PORT_OUTPUT,
	MGPIO_PORT_ALTF,
	MGPIO_PORT_ANLG
}PortMode_t;

/*****************************************************************************************/
/*                                   Output_MODE                                         */
/*****************************************************************************************/

typedef enum
{
	MGPIO_PUSH_PULL,
	MGPIO_OPEN_DRAIN
}OutputType_t;

/*****************************************************************************************/
/*                                   Pull_MODE                                           */
/*****************************************************************************************/

//#define MGPIO_PIN_FLOAT 	0b00
//#define MGPIO_PIN_PULL_UP   0b01
//#define MGPIO_PIN_PULL_UP   0b10

typedef enum
{
	MGPIO_PIN_FLOAT,
	MGPIO_PIN_PULL_UP,
	MGPIO_PIN_PULL_DOWN
}PullMode_t;

/*****************************************************************************************/
/*                                   PIN_Value                                           */
/*****************************************************************************************/

//#define MGPIO_PIN_HIGH	1
//#define MGPIO_PIN_LOW	0

typedef enum
{
	MGPIO_PIN_LOW,
	MGPIO_PIN_HIGH
}PinValue_t;

/*****************************************************************************************/
/*                                   Port_Value                                           */
/*****************************************************************************************/

typedef enum
{
	MGPIO_PORT_LOW,
	MGPIO_PORT_HIGH
}PortValue_t;

/*****************************************************************************************/
/*                                   SetReset_Mode                                       */
/*****************************************************************************************/

typedef enum
{
	Reset,
	Set
}SetReset_t;

/*****************************************************************************************/
/*                                   ALTF_mode 	                                         */
/*****************************************************************************************/

typedef enum
{
	AF0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15,
}ALTF_t;

/*#######################################################################################*/
/*									Function Prototypes									 */
/*#######################################################################################*/

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


void MGPIO_voidSetPinMode(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum , u8 Copy_u8PinMode);

void MGPIO_voidSetPortMode(MGPIO_t Copy_uddtPortNum , u8 Copy_u8PortMode);

void MGPIO_voidSetOutputType(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum , OutputType_t CopyuddtPinOutType);

void MGPIO_voidSetOutputPinSpeed(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum ,Speed_t CopyuddtPinOutSpeed);

void MGPIO_voidSetPinPullType(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum , u8 Copy_u8PullMode);

void MGPIO_voidSetPinValue(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum , u8 Copy_u8PinValue);

void MGPIO_voidSetPortValue(MGPIO_t Copy_uddtPortNum , u8 Copy_u8PortValue);

u8 MGPIO_voidGetPinValue(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum);

void MGPIO_voidSetResetPin(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum ,SetReset_t Copy_u8AtomPinMode);

void MGPIO_voidSetPinLock(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum );


void MGPIO_voidSetPinAltFunction(MGPIO_t Copy_uddtPortNum , PIN_t Copy_uddtPinNum , ALTF_t Copy_uddtALF);























#endif /* MGPIO_INTERFACE_H_ */
