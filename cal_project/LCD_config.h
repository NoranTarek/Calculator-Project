/*
 * LCD_config.h
 *
 *  Created on: Oct 16, 2024
 *      Author: mylap
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


/*		LCD mode		*/

#define LCD_MODE EIGHT_BIT

/*		control pins	*/
#define RS_PIN     DIO_PIN0
#define RS_PORT    DIO_PORTB

#define RW_PIN     DIO_PIN1
#define RW_PORT    DIO_PORTB

#define EN_PIN     DIO_PIN2
#define EN_PORT    DIO_PORTB

/*		data pins 		*/

#define D0_PIN   DIO_PIN0
#define D0_PORT  DIO_PORTA

#define D1_PIN   DIO_PIN1
#define D1_PORT  DIO_PORTA

#define D2_PIN   DIO_PIN2
#define D2_PORT  DIO_PORTA

#define D3_PIN   DIO_PIN3
#define D3_PORT  DIO_PORTA

#define D4_PIN   DIO_PIN4
#define D4_PORT  DIO_PORTA

#define D5_PIN   DIO_PIN5
#define D5_PORT  DIO_PORTA

#define D6_PIN   DIO_PIN6
#define D6_PORT  DIO_PORTA

#define D7_PIN   DIO_PIN7
#define D7_PORT  DIO_PORTA


#endif /* LCD_CONFIG_H_ */
