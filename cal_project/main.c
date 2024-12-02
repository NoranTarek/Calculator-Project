/*
 * main.c
 *
 *  Created on: Oct 17, 2024
 *      Author: mylap
 */

#include "stdTypes.h"
#include "errorStates.h"
#include "util/delay.h"

#include "DIO_int.h"
#include "LCD_int.h"

#include "KPD_int.h"

#include "cal.h"

int main(void)
{
	u8 Local_u8Key;
	u8 Local_u8OP1[NUM_SIZE];
	u8 Local_u8OP2[NUM_SIZE];
	u8 Local_u8OP;
	u8 counter1 = 0;
	u8 Local_u8Sign1 = 0;
	u8 Local_u8Sign2 = 0;
	u8 counter2 = 0;
	u8 Local_u8Flag = 0;
	DIO_enuInit();
	LCD_enuInit();

	while(1)
	{
		Local_u8Key = KPD_enuGetPresedKey();
		if(Local_u8Key == 20)
			continue;
		else
		{
			do
			{
			}while(Local_u8Key == 0xff);
			LCD_enuDisplayChar(Local_u8Key);
			if(Local_u8Key == ' ')
			{
				counter1 = 0;
				counter2 = 0;
				Local_u8Sign1 = 0;
				Local_u8Sign2 = 0;
				Local_u8Flag = 0;
				LCD_enuInit();
				continue;
			}
			if(Local_u8Flag == 0)
			{
			if((Local_u8Key == '+' || Local_u8Key == '-' || Local_u8Key == '/' || Local_u8Key == '*') && (counter1 != 0))
			{
				Local_u8OP = Local_u8Key;
				Local_u8Flag = 1;
			}
			else
			{
				if(Local_u8Key == '-')
				{
					Local_u8Sign1 = 1;
					continue;
				}
				Local_u8OP1[counter1] = Local_u8Key-'0';
				counter1++;
			}
			}else if(Local_u8Flag == 1)
			{
				if(Local_u8Key == '=')
				{
					Local_u8Flag = 2;
				}
				else
				{
					if(Local_u8Key == '-')
					{
						Local_u8Sign2 = 1;
						continue;
					}
					Local_u8OP2[counter2] = Local_u8Key-'0';
					counter2++;
				}
			}
			if(Local_u8Flag ==2)
			{
				u8 Local_u8Num1 = 0,Local_u8Num2 = 0,Local_u8Dec = 1;
				for(u8 counter = counter1; counter > 0;counter--)
					{
						Local_u8Num1 += (Local_u8Dec * Local_u8OP1[counter-1]);
						Local_u8Dec *= 10;
					}
					Local_u8Dec = 1;
					for(u8 counter = counter2; counter > 0;counter--)
					{
						Local_u8Num2 += (Local_u8Dec * Local_u8OP2[counter-1]);
						Local_u8Dec *= 10;
					}
				switch(Local_u8OP)
				{
					case '+':
						CAL_u32SUM(Local_u8Num1,Local_u8Num2,Local_u8Sign1,Local_u8Sign2);
						break;
					case '-':
						CAL_u32SUB(Local_u8Num1,Local_u8Num2,Local_u8Sign1,Local_u8Sign2);
						break;
					case '*':
						CAL_u32MUL(Local_u8Num1,Local_u8Num2,Local_u8Sign1,Local_u8Sign2);
						break;
					case '/':
						CAL_u32DIV(Local_u8Num1,Local_u8Num2,Local_u8Sign1,Local_u8Sign2);
						break;
				}
				//Local_u8Flag = 3;
			}
			/*if(Local_u8Flag == 3)
			{
				_delay_ms(1000);
				counter1 = 0;
				counter2 = 0;
				Local_u8Flag = 0;
				LCD_enuInit();
				Local_u8Flag = 0;
			}*/
		}
	}
	return 0;
}
