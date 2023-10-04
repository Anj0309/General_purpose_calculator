/*
 * lcd_func.c
 *
 *  Created on: Sep 18, 2023
 *      Author: anjal
 */


#include "lcd_func.h"
#include "stm32f1xx_hal.h"

#define D7_GPIO_Port    GPIOA
#define D6_GPIO_Port    GPIOA
#define D5_GPIO_Port    GPIOA
#define D4_GPIO_Port    GPIOA

#define D7_Pin    GPIO_PIN_7
#define D6_Pin    GPIO_PIN_6
#define D5_Pin    GPIO_PIN_5
#define D4_Pin    GPIO_PIN_4


#define RS_GPIO_Port  GPIOA
#define RS_Pin     GPIO_PIN_2

#define EN_GPIO_Port  GPIOA
#define EN_Pin      GPIO_PIN_3
//#include "main.h"
/*void lcd_send(int a, int data)
{
	HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, a);

	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, (data&0x80));
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, (data&0x40));
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, (data&0x20));
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, (data&0x10));

	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, (data&0x08));
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, (data&0x04));
	HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, (data&0x02));
	HAL_GPIO_WritePin(D0_GPIO_Port, D0_Pin, (data&0x01));

	HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, SET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, RESET);
}
*/
void lcd_send_4bit(int a, int data)
{
	HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, a);
	/*higher nibble send*/
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, (data&0x80));
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, (data&0x40));
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, (data&0x20));
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, (data&0x10));
	HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, SET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, RESET);
	HAL_Delay(10);
	/*send lower nibble*/
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, (data&0x08));
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, (data&0x04));
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, (data&0x02));
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, (data&0x01));

	HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, SET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, RESET);
	HAL_Delay(10);
}
void lcd_send_data(int data)
{
	lcd_send_4bit(1, data);
}
void lcd_send_cmd(int cmd)
{
	lcd_send_4bit(0, cmd);
}
void lcd_init()
{
	lcd_send_cmd(0x38); // 5x7 matrix
	lcd_send_cmd(0x80); //force to begining
	lcd_send_cmd(0x01); //clear lcd
	lcd_send_cmd (0x06); //cursor increment
	lcd_send_cmd(0x0c); //display on cursor off
}

void lcd_4bit_init()
{
	/*lcd_send_cmd(0x0c); //display on cursor off
	lcd_send_cmd(0x28); // 5x7 matrix 4bit mode
	lcd_send_cmd(0x02); //  4bit mode
	lcd_send_cmd(0x80); //force to begining
	lcd_send_cmd(0x06); //auto increement
	lcd_send_cmd(0x01); //clear lcd*/

	HAL_Delay(10);
		lcd_send_cmd (0x02); //4bit mode
		lcd_send_cmd (0x28); // Function set --> DL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 characters)
		lcd_send_cmd (0x08); //Display on/off control --> D=0,C=0, B=0  ---> display off
		lcd_send_cmd (0x01);  // clear display
		lcd_send_cmd (0x06); //Entry mode set --> I/D = 1 (increment cursor) & S = 0 (no shift)
		lcd_send_cmd (0x0C); //Display on/off control --> D = 1, C and B = 0. (Cursor and blink, last two bits)

}

void lcd_set_cursor(int row, int col)
{
	switch (row) {
		case 0:
			col |= 0x80;
			break;
		case 1:
			col |= 0xC0;
			break;
		default:
			break;
	}
	lcd_send_cmd(col);

}

void lcd_clear()
{
	lcd_send_cmd(0x01);
}

void lcd_Send_String(const char *str)
{
	while(*str != '\0')
	{
		lcd_send_data(*str);
		str++;
	}

}
