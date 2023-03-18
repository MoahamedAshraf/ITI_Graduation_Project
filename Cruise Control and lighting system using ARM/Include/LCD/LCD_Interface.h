/*
 * LCD_Interface.h
 *
 *  Created on: 25 Nov 2022
 *      Author: user
 */

#ifndef LIB_LCD_INTERFACE_H_
#define LIB_LCD_INTERFACE_H_

/**********************************************/
/******************Public Macros***************/
/**********************************************/

/* LCD control commands */

#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "LBIT_MATH.h"

#define lcd_clr					0x01
#define lcd_home				0x02
#define lcd_entrymode			0x06
#define	lcd_dispoff				0x08
#define	lcd_dispon_curson		0x0E
#define lcd_funcreset			0x30
#define	lcd_funcset8bit			0x38
#define	lcd_setcursor			0x80
#define	lcd_dispon_cursblink	0x0F
#define	lcd_dispon_cursoff		0x0C








void HLCD_voidInit(void);
void HLCD_voidSendCommand(u8 Copy_u8Cmd);
void HLCD_voidSendChar(u8 Copy_u8Char);
void HLCD_Send_Num(u32 num);
void HLCD_voidSendString(u8 *ptr);
void HLCD_voidGotoxy(u8 row , u8 col );
void HLCD_voidSendCustom (u8 * Pattern, u8 Location);




#endif /* LIB_LCD_INTERFACE_H_ */
