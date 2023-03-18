/*
 * LightingSys.c
 *
 *  Created on: Feb 28, 2023
 *      Author: Alaa Ashraf
 */

/******************************************************************************************************/
/*                               Standard Types LIB                                                   */
/******************************************************************************************************/
#include   "LSTD_TYPES.h"
#include   "LBIT_MATH.h"
#include   "LERROR_STATES.h"

/******************************************************************************************************/
/*                               MCAL Layer                                                   */
/******************************************************************************************************/
#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"
#include "MSTK_Interface.h"

/***************************************************************************************/
/*                                     HAL Layer                                       */
/***************************************************************************************/
#include "LightingSys.h"
#include "Ultrasonic.h"
#include "HMOTOR_PWM_Interface.h"

/***************************************************************************************/
/*                         Global Variables                                            */
/***************************************************************************************/

//extern volatile u8 mode;
//extern volatile u8 Global_Data_Recieved;
/***************************************************************************************/
/*                         Local Variables                                            */
/***************************************************************************************/
u8  Col_Up = col_Up;

u8 Row_Up[8]={R_Up0,R_Up1,R_Up2,R_Up3,R_Up4,R_Up5,R_Up6,R_Up7};

u8  Col_Stop = col_Stop;

u8 Row_Stop[8]={R_Stop0,R_Stop1,R_Stop2,R_Stop3,R_Stop4,R_Stop5,R_Stop6,R_Stop7};

u8  Col_Daccel = col_Daccel;

u8 Row_Daccel[8]={R_Daccel0,R_Daccel1,R_Daccel2,R_Daccel3,R_Daccel4,R_Daccel5,R_Daccel6,R_Daccel7};

u8 flag_out=0;
/***************************************************************************************/
/*                                  System Functions                                   */
/***************************************************************************************/


void LIGHTING_SYS_ACCELERATE(){
	u8 i=0;
	u8 value=0;

	u16 count = 100;
	while(count > 0){

		u8 column ;

		for( i=0; i<8 ; i++){
			column = Col_Up;

			CLR_BIT(column , i);
			value = Row_Up[i];

			//USING other pins of portB and portA   (right code)
			MGPIO_voidSetPortValue(MGPIO_PortB, value);

			MGPIO_voidSetPinValue(MGPIO_PortB,PIN8,GET_BIT(column,0));
			MGPIO_voidSetPinValue(MGPIO_PortB,PIN9,GET_BIT(column,1));
			MGPIO_voidSetPinValue(MGPIO_PortB,PIN10,GET_BIT(column,2));

			MGPIO_voidSetPinValue(MGPIO_PortA,PIN7,GET_BIT(column,3));
			MGPIO_voidSetPinValue(MGPIO_PortA,PIN8,GET_BIT(column,4));
			MGPIO_voidSetPinValue(MGPIO_PortA,PIN11,GET_BIT(column,5));
			MGPIO_voidSetPinValue(MGPIO_PortA,PIN12,GET_BIT(column,6));

			MGPIO_voidSetPinValue(MGPIO_PortA,PIN15,GET_BIT(column,7));

			MSTK_voidDelay_us(500);

		}

		count--;
	}
	MGPIO_voidSetPinValue(MGPIO_PortA,PIN15,MGPIO_PIN_HIGH);

}


void LIGHTING_SYS_DACCELERATE(){
	u8 i=0;
	u8 value=0;

	u16 count = 100;
	while(count > 0){
		u8 column ;
		for( i=0; i<8 ; i++){

			column = Col_Daccel;

			CLR_BIT(column , i);
			value = Row_Daccel[i];

			//USING other pins of portB and portA   (right code)
			MGPIO_voidSetPortValue(MGPIO_PortB, value);

			MGPIO_voidSetPinValue(MGPIO_PortB,PIN8,GET_BIT(column,0));
			MGPIO_voidSetPinValue(MGPIO_PortB,PIN9,GET_BIT(column,1));
			MGPIO_voidSetPinValue(MGPIO_PortB,PIN10,GET_BIT(column,2));

			MGPIO_voidSetPinValue(MGPIO_PortA,PIN7,GET_BIT(column,3));
			MGPIO_voidSetPinValue(MGPIO_PortA,PIN8,GET_BIT(column,4));
			MGPIO_voidSetPinValue(MGPIO_PortA,PIN11,GET_BIT(column,5));
			MGPIO_voidSetPinValue(MGPIO_PortA,PIN12,GET_BIT(column,6));

			MGPIO_voidSetPinValue(MGPIO_PortA,PIN15,GET_BIT(column,7));

			MSTK_voidDelay_us(500);

		}

		count--;
	}
	MGPIO_voidSetPinValue(MGPIO_PortA,PIN15,MGPIO_PIN_HIGH);

}



void LIGHTING_SYS_STOP(){
	u8 i=0;
	u8 value=0;

	u16 count = 100;
	while(count > 0){

		u8 column ;
		for( i=0; i<8 ; i++){
			column = Col_Stop;

			CLR_BIT(column , i);
			value = Row_Stop[i];

			//USING other pins of portB and portA   (right code)
			MGPIO_voidSetPortValue(MGPIO_PortB, value);

			MGPIO_voidSetPinValue(MGPIO_PortB,PIN8,GET_BIT(column,0));
			MGPIO_voidSetPinValue(MGPIO_PortB,PIN9,GET_BIT(column,1));
			MGPIO_voidSetPinValue(MGPIO_PortB,PIN10,GET_BIT(column,2));

			MGPIO_voidSetPinValue(MGPIO_PortA,PIN7,GET_BIT(column,3));
			MGPIO_voidSetPinValue(MGPIO_PortA,PIN8,GET_BIT(column,4));
			MGPIO_voidSetPinValue(MGPIO_PortA,PIN11,GET_BIT(column,5));
			MGPIO_voidSetPinValue(MGPIO_PortA,PIN12,GET_BIT(column,6));

			MGPIO_voidSetPinValue(MGPIO_PortA,PIN15,GET_BIT(column,7));

			MSTK_voidDelay_us(500);

		}

		count--;
	}
	MGPIO_voidSetPinValue(MGPIO_PortA,PIN15,MGPIO_PIN_HIGH);

}




/*---------------------------------------------*/
//		switch(mode){
//		case ACC:
//			Col = Col_Up;
//			Row[8] = Row_Up[8];
//			flag_out=0;
//			break;
//		default:
//			flag_out=1;
//			break;
//		}


//		switch(Global_Data_Recieved){
//		case 'A':
//			Col = Col_Up;
//			Row[8] = Row_Up[8];
//			flag_out=0;
//			break;
//		case 'D':
//			flag_out=1;
//			break;
//		default:
//			flag_out=1;
//			break;
//		}

//		if (flag_out==1) break;
/*-------------------------------------------*/
