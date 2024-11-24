/*
 * cal.c
 *
 *  Created on: Nov 8, 2024
 *      Author: mylap
 */
#include "stdTypes.h"
#include "cal.h"
#include "LCD_int.h"

void CAL_u32SUM(u8 num1[],u8 num2[],u8 n, u8 m)
{
	u8 n1 = 0,n2 = 0,res,Res[NUM_SIZE],dec=1;
	for(u8 counter = n; counter > 0;counter--)
	{
		n1 += (dec * num1[counter-1]);
		dec *= 10;
	}
	dec = 1;
	for(u8 counter = m; counter > 0;counter--)
	{
		n2 += (dec * num2[counter-1]);
		dec *= 10;
	}
	res = n1 + n2;
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

void CAL_u32SUB(u8 num1[],u8 num2[],u8 n, u8 m)
{
	u8 n1 = 0,n2 = 0,res,Res[NUM_SIZE],dec=1;
	for(u8 counter = n; counter > 0;counter--)
	{
		n1 += (dec * num1[counter-1]);
		dec *= 10;
	}
	dec = 1;
	for(u8 counter = m; counter > 0;counter--)
	{
		n2 += (dec * num2[counter-1]);
		dec *= 10;
	}
	if(n1 > n2)
	{
		res = n1 - n2;
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
	else if(n1 == n2)
		LCD_enuDisplayChar('0');
	else
	{
		res = n2 - n1;
		LCD_enuDisplayChar('-');
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
}

void CAL_u32MUL(u8 num1[],u8 num2[],u8 n, u8 m)
{
	u8 n1 = 0,n2 = 0,res,Res[NUM_SIZE],dec=1;
	for(u8 counter = n; counter > 0;counter--)
	{
		n1 += (dec * num1[counter-1]);
		dec *= 10;
	}
	dec = 1;
	for(u8 counter = m; counter > 0;counter--)
	{
		n2 += (dec * num2[counter-1]);
		dec *= 10;
	}
	res = n1 * n2;
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

void CAL_u32DIV(u8 num1[],u8 num2[],u8 n, u8 m)
{
	u8 n1 = 0,n2 = 0,res,Res[NUM_SIZE],dec=1;
	for(u8 counter = n; counter > 0;counter--)
	{
		n1 += (dec * num1[counter-1]);
		dec *= 10;
	}
	dec = 1;
	for(u8 counter = m; counter > 0;counter--)
	{
		n2 += (dec * num2[counter-1]);
		dec *= 10;
	}
	res = n1 / n2;
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
	if(n1%n2 != 0)
	{
		LCD_enuDisplayChar('.');
		f32 result = (f32)n1/n2;
		result *= 10;
		u8 ress = result;
		LCD_enuDisplayChar((ress%10)+'0');
	}

}
