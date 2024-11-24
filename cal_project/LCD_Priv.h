/*
 * LCD_Priv.h
 *
 *  Created on: Oct 16, 2024
 *      Author: mylap
 */

#ifndef LCD_PRIV_H_
#define LCD_PRIV_H_

#define EIGHT_BIT   0
#define FOUR_BIT    1

static void LCD_Latch(u8 Copy_u8Data);

inline static void LCD_invidSendCommend(u8 Copy_u8Command);


#endif /* LCD_PRIV_H_ */
