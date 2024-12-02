/*
 * cal.c
 *
 *  Created on: Nov 8, 2024
 *      Author: mylap
 */
#include "stdTypes.h"
#include "cal.h"
#include "LCD_int.h"

void CAL_u32SUM(u8 num1,u8 num2,u8 sign1,u8 sign2)
{
	u32 res;
	u8 Res[NUM_SIZE];
	if((sign1 == 1) && (sign2 == 0))
	{
		if(num1 < num2)
			res = num2 - num1;
		else if(num1 == num2)
			res = 0;
		else
		{
			LCD_enuDisplayChar('-');
			res = num1 - num2;
		}
	}
	else if((sign2 == 1) && (sign1 ==0))
	{
		if(num1 > num2)
			res = num1 - num2;
		else if(num1 == num2)
			res = 0;
		else
		{
			LCD_enuDisplayChar('-');
			res = num2 - num1;
		}
	}
	else if((sign2 == 1) && (sign1 == 1))
	{
		LCD_enuDisplayChar('-');
		res = num1 + num2;
	}
	else
		res = num1 + num2;
	if(res > 9)
	{
		for(int i = 0;i < sizeof(Res);i++)
		{
			Res[i] = (res%10)+'0';
			res /= 10;
		}
		int counter = sizeof(Res)-1;
		while(Res[counter] == '0')
		{
			counter --;
		}
		for(int i = counter; i >= 0; i--)
			LCD_enuDisplayChar(Res[i]);
	}
	else
		LCD_enuDisplayChar(res+'0');

}

void CAL_u32SUB(u8 num1,u8 num2,u8 sign1,u8 sign2)
{
	u32 res;
	u8 Res[NUM_SIZE];
	if((sign1 == 1) && (sign2 == 0))
	{
		LCD_enuDisplayChar('-');
		res = num1 + num2 ;
	}
	else if((sign1 == 0) && (sign2 == 1))
		res = num1 + num2;
	else if((sign1 == 1) && (sign2 ==1))
	{
		if(num2 >= num1)
		{
			res = num2 - num1;
		}
		else
		{
			res = num1 - num2;
			LCD_enuDisplayChar('-');

		}
	}
	else if((sign1 == 0) && (sign2 == 0))
	{
		if(num1 >= num2)
		{
			res = num1 - num2;
		}
		else
		{
			res = num2 - num1;
			LCD_enuDisplayChar('-');

		}
	}
	if(res > 9)
	{
		for(int i = 0;i < sizeof(Res);i++)
		{
			Res[i] = (res%10)+'0';
			res /= 10;
		}
		int counter = sizeof(Res)-1;
		while(Res[counter] == '0')
		{
			counter --;
		}
		for(int i = counter; i >= 0; i--)
			LCD_enuDisplayChar(Res[i]);
	}
	else
		LCD_enuDisplayChar(res+'0');
}

void CAL_u32MUL(u8 num1,u8 num2,u8 sign1,u8 sign2)
{
	u32 res;
	u8 Res[NUM_SIZE];
	if(((sign1 == 1)&&(sign2 == 0))||((sign1 == 0)&&(sign2 == 1)))
		LCD_enuDisplayChar('-');
	res = num1 * num2;
	if(res > 9)
	{
		for(int i = 0;i < sizeof(Res);i++)
		{
			Res[i] = (res%10)+'0';
			res /= 10;
		}
		int counter = sizeof(Res)-1;
		while(Res[counter] == '0')
		{
			counter --;
		}
		for(int i = counter; i >= 0; i--)
			LCD_enuDisplayChar(Res[i]);
	}
	else
		LCD_enuDisplayChar(res+'0');

}

void CAL_u32DIV(u8 num1,u8 num2,u8 sign1,u8 sign2)
{
	u32 res;
	u8 Res[NUM_SIZE];
	if(((sign1 == 1)&&(sign2 == 0))||((sign1 == 0)&&(sign2 == 1)))
			LCD_enuDisplayChar('-');
	res = num1 / num2;
	if(res > 9)
	{
		for(int i = 0;i < sizeof(Res);i++)
		{
			Res[i] = (res%10)+'0';
			res /= 10;
		}
		int counter = sizeof(Res)-1;
		while(Res[counter] == '0')
		{
			counter --;
		}
		for(int i = counter; i >= 0; i--)
			LCD_enuDisplayChar(Res[i]);
	}
	else
		LCD_enuDisplayChar(res+'0');
	if(num1%num2 != 0)
	{
		LCD_enuDisplayChar('.');
		f32 result = (f32)num1/num2;
		result *= 10;
		u8 ress = result;
		LCD_enuDisplayChar((ress%10)+'0');
	}

}
