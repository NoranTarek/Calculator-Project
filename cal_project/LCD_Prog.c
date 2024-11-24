/*
 * LCD_Prog.c
 *
 *  Created on: Oct 16, 2024
 *      Author: mylap
 */

#include "errorStates.h"
#include "stdTypes.h"

#include "DIO_int.h"

#include "LCD_config.h"
#include "LCD_priv.h"

#include "util/delay.h"

ES_t LCD_enuInit(void)
{
	u8 Local_u8ErrorState = ES_NOK;
	DIO_enuSetPinDirection(RS_PORT, RS_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(RW_PORT, RW_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(EN_PORT, EN_PIN, DIO_u8OUTPUT);

	DIO_enuSetPinDirection(D7_PORT, D7_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D6_PORT, D6_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D5_PORT, D5_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D4_PORT, D4_PIN, DIO_u8OUTPUT);

	_delay_ms(35);

#if LCD_MODE == EIGHT_BIT

	DIO_enuSetPinDirection(D3_PORT, D3_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D2_PORT, D2_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D1_PORT, D1_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D0_PORT, D0_PIN, DIO_u8OUTPUT);

	//function set
	LCD_invidSendCommend(0x38);
#elif LCD_MODE == FOUR_BIT
	LCD_invidSendCommend(0x28);
#endif
	_delay_ms(1);
	LCD_invidSendCommend(0x0f);
	_delay_ms(1);
	LCD_invidSendCommend(0x01);
	_delay_ms(2);
	LCD_invidSendCommend(0x06);


	return Local_u8ErrorState;
}

ES_t LCD_enuDisplayChar(u8 Copy_u8Data)
{
	u8 Local_u8ErrorState = ES_NOK;
	DIO_enuSetPinValue(RS_PORT,RS_PIN , DIO_u8HIGH);
	LCD_Latch(Copy_u8Data);
	Local_u8ErrorState = ES_OK;

	return Local_u8ErrorState;
}

ES_t LCD_enuSendCommand(u8 Copy_u8Command)
{
	u8 Local_u8ErrorState = ES_NOK;
	DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8LOW);
	LCD_Latch(Copy_u8Command);
	Local_u8ErrorState =ES_OK;


	return Local_u8ErrorState;
}

static void LCD_Latch(u8 Copy_u8Data)
{
	// set rw as write operation , EN is low
		DIO_enuSetPinValue(RW_PORT , RW_PIN , DIO_u8LOW);
		DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8LOW);
		//write Data
		DIO_enuSetPinValue(D7_PORT , D7_PIN , ((Copy_u8Data>>7)&1));
		DIO_enuSetPinValue(D6_PORT , D6_PIN , ((Copy_u8Data>>6)&1));
		DIO_enuSetPinValue(D5_PORT , D5_PIN , ((Copy_u8Data>>5)&1));
		DIO_enuSetPinValue(D4_PORT , D4_PIN , ((Copy_u8Data>>4)&1));

	#if LCD_MODE == EIGHT_BIT

		DIO_enuSetPinValue(D3_PORT , D3_PIN , ((Copy_u8Data>>3)&1));
		DIO_enuSetPinValue(D2_PORT , D2_PIN , ((Copy_u8Data>>2)&1));
		DIO_enuSetPinValue(D1_PORT , D1_PIN , ((Copy_u8Data>>1)&1));
		DIO_enuSetPinValue(D0_PORT , D0_PIN , ((Copy_u8Data>>0)&1));

	#elif LCD_MODE == FOUR_BIT

	#endif

		// Enable latch
		DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8HIGH);
		_delay_ms(10);
		DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8LOW);


		_delay_ms(10);
}
inline static void LCD_invidSendCommend(u8 Copy_u8Command)
{
	// set rs as command
	DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8LOW);
	// set rw as write operation , EN is low
	DIO_enuSetPinValue(RW_PORT , RW_PIN , DIO_u8LOW);
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8LOW);
	//write Data
	DIO_enuSetPinValue(D7_PORT , D7_PIN , ((Copy_u8Command>>7)&1));
	DIO_enuSetPinValue(D6_PORT , D6_PIN , ((Copy_u8Command>>6)&1));
	DIO_enuSetPinValue(D5_PORT , D5_PIN , ((Copy_u8Command>>5)&1));
	DIO_enuSetPinValue(D4_PORT , D4_PIN , ((Copy_u8Command>>4)&1));
	DIO_enuSetPinValue(D3_PORT , D3_PIN , ((Copy_u8Command>>3)&1));
	DIO_enuSetPinValue(D2_PORT , D2_PIN , ((Copy_u8Command>>2)&1));
	DIO_enuSetPinValue(D1_PORT , D1_PIN , ((Copy_u8Command>>1)&1));
	DIO_enuSetPinValue(D0_PORT , D0_PIN , ((Copy_u8Command>>0)&1));

	// Enable latch
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8HIGH);
	_delay_ms(10);
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8LOW);
}

