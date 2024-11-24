/*
 * LCD_int.h
 *
 *  Created on: Oct 16, 2024
 *      Author: mylap
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_
#include "DIO_int.h"

ES_t LCD_enuInit(void);

ES_t LCD_enuDisplayChar(u8 Copy_u8Data);

ES_t LCD_enuSendCommand(u8 Copy_u8Command);



#endif /* LCD_INT_H_ */
