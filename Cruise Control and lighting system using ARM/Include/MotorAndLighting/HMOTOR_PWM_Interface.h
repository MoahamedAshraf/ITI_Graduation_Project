/*
 * HMOTOR_PWM_Iterface.h
 *
 *  Created on: Feb 13, 2023
 *      Author: abdel
 */

#ifndef HMOTOR_PWM_ITERFACE_H_
#define HMOTOR_PWM_ITERFACE_H_


/***************************************************************************************/
/*                            Standard Types LIB                                       */
/***************************************************************************************/

#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "LBIT_MATH.h"
/***************************************************************************************/
/************************************** Functions **************************************/
void sys_init();
void App_u8SetSpeedLevel();
void start_motor();
void stop_motor();
void config();
void ACC_MODE();
void NCC_MODE();
void buzzer_on();
void decrease_speed();

/*******************************************************************************************************/
/*                                           MODES & RANGES     	                                   */
/*******************************************************************************************************/
typedef enum
{
	OFFCC,
	NCC,
	ACC
}CCmode_t;

typedef enum
{
	CLOSE,
	MEDIUM,
	FAR
}range_t;

typedef enum
{
	// FAR LIMITS
	UPPER_FAR = 120,
	LOWER_FAR = 90,
	// MEDIUM LIMITS
	UPPER_MEDIUM = 90,
	LOWER_MEDIUM = 60,
	// CLOSE LIMITS
	UPPER_CLOSE = 60,
	LOWER_CLOSE = 30,

	DANGER_DISTANCE = 10

}distance_t;
#endif /* HMOTOR_PWM_ITERFACE_H_ */
