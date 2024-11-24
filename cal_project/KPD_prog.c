/*
 * KPD_prog.c
 *
 *  Created on: Oct 17, 2024
 *      Author: mylap
 */

#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_int.h"

#include "KPD_config.h"
#include "KPD_priv.h"


u8 KPD_enuGetPresedKey(void)
{
	u8 Local_u8PressedKey = KPD_NOT_PRESSED_KEY;

	static u8 Local_u8KPDArr[KPD_DIM][KPD_DIM] = KPD_ARR ;

	u8 Local_u8ColumnIdx , Local_u8RowIdx ,Local_u8PinState;

	static u8 Local_u8ColPortArr [] = {KPD_COL0_PORT , KPD_COL1_PORT , KPD_COL2_PORT , KPD_COL3_PORT};

	static u8 Local_u8ColPinArr[] = {KPD_COL0_PIN , KPD_COL1_PIN , KPD_COL2_PIN , KPD_COL3_PIN};

	static u8 Local_u8RowPortArr[] = {KPD_ROW0_PORT , KPD_ROW1_PORT , KPD_ROW2_PORT , KPD_ROW3_PORT};

	static u8 Local_u8RowPinArr[] = {KPD_ROW0_PIN , KPD_ROW1_PIN , KPD_ROW2_PIN , KPD_ROW3_PIN};

	for(Local_u8ColumnIdx = 0 ;Local_u8ColumnIdx < KPD_DIM ;Local_u8ColumnIdx++ )
	{
		/*	activate current column	*/
		DIO_enuSetPinValue(Local_u8ColPortArr[Local_u8ColumnIdx] ,Local_u8ColPinArr[Local_u8ColumnIdx], DIO_u8LOW);
		for(Local_u8RowIdx = 0; Local_u8RowIdx <KPD_DIM ; Local_u8RowIdx++)
		{
			/*	read the current row	*/
			DIO_enuGetPinValue(Local_u8RowPortArr[Local_u8RowIdx],Local_u8RowPinArr[Local_u8RowIdx], &Local_u8PinState);
			/*	check switch is pressed	*/
			if(DIO_u8LOW == Local_u8PinState)
			{
				Local_u8PressedKey = Local_u8KPDArr[Local_u8RowIdx][Local_u8ColumnIdx];
				/* polling (busy waiting) until key is released */
				while(DIO_u8LOW == Local_u8PinState)
				{
					DIO_enuGetPinValue(Local_u8RowPortArr[Local_u8RowIdx],Local_u8RowPinArr[Local_u8RowIdx], &Local_u8PinState);
				}
				return Local_u8PressedKey;
			}
		}
		/*	deactivate current column	*/
		DIO_enuSetPinValue(Local_u8ColPortArr[Local_u8ColumnIdx] ,Local_u8ColPinArr[Local_u8ColumnIdx], DIO_u8HIGH);
	}

	return Local_u8PressedKey;
}
