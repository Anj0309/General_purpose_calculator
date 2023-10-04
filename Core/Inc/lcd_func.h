/*
 * lcd_func.h
 *
 *  Created on: Sep 18, 2023
 *      Author: anjal
 */

#ifndef INC_LCD_FUNC_H_
#define INC_LCD_FUNC_H_

//void lcd_send(int a, int data);
void lcd_send_data(int data);
void lcd_send_cmd(int cmd);
void lcd_init();
void lcd_set_cursor(int row, int col);
void lcd_clear();
void lcd_Send_String(const char *str);
void lcd_4bit_init();
void lcd_send_4bit(int a, int data);

#endif /* INC_LCD_FUNC_H_ */
