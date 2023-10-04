/*
 *
 * keypad.c
 *
 *  Created on: Sep 23, 2023
 *      Author: anjal
 */

#include "calculator.h"
#include "lcd_func.h"
#include "stm32f1xx_hal.h"


#define C1_GPIO_Port   GPIOB
#define C2_GPIO_Port   GPIOB
#define C3_GPIO_Port   GPIOB
#define C4_GPIO_Port   GPIOB

#define R1_GPIO_Port   GPIOA
#define R2_GPIO_Port   GPIOA
#define R3_GPIO_Port   GPIOA
#define R4_GPIO_Port   GPIOA

#define C1_Pin         GPIO_PIN_15
#define C2_Pin         GPIO_PIN_14
#define C3_Pin         GPIO_PIN_13
#define C4_Pin         GPIO_PIN_12

#define R1_Pin         GPIO_PIN_11
#define R2_Pin         GPIO_PIN_10
#define R3_Pin         GPIO_PIN_9
#define R4_Pin         GPIO_PIN_8



extern flag status;
extern uint32_t first_input, second_input, result;
extern char operator;

void calci_init()
{
	  HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, 0);
	  HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, 0);
	  HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, 0);
	  HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, 0);

	  first_input =0;
	  second_input = 0;
	  result = 0;
	  HAL_Delay(1000);
	  lcd_clear();
	  lcd_set_cursor(0,0);
	  lcd_send_data('0');
}
char key_map()
{
	char key_data = 0;
	  /*R1 mapping*/
	  HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, SET);
	  if(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin)==1)
	  {
		  while(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin)==1);
		  key_data = '1';
		  status.data_available = 1;
	  }
	  else if(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin)==1)
	  {
		  while(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin)==1);
		  key_data = '2';
		  status.data_available = 1;
	  }
	  else if(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin)==1)
	  {
		  while(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin)==1);
		  key_data = '3';
		  status.data_available = 1;
	  }
	  else if(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin)==1)
	  {
		  while(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin)==1);
		  key_data = '/';
		  status.data_available = 1;
	  }
	  HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, 0);

	  /*R2 mapping*/
	  HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, SET);
	  if(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin)==1)
	  {
		  while(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin)==1);
		  key_data = '4';
		  status.data_available = 1;
	  }
	  else if(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin)==1)
	  {
		  while(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin)==1);
		  key_data = '5';
		  status.data_available = 1;
	  }
	  else if(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin)==1)
	  {
		  while(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin)==1);
		  key_data = '6';
		  status.data_available = 1;
	  }
	  else if(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin)==1)
	  {
		  while(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin)==1);
		  key_data = 'x';
		  status.data_available = 1;
	  }
	  HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, 0);

	  /*R3 mapping*/
	  HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, SET);
	  if(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin)==1)
	  {
		  while(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin)==1);
		  key_data = '7';
		  status.data_available = 1;
	  }
	  else if(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin)==1)
	  {
		  while(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin)==1);
		  key_data = '8';
		  status.data_available = 1;
	  }
	  else if(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin)==1)
	  {
		  while(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin)==1);
		  key_data = '9';
		  status.data_available = 1;
	  }
	  else if(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin)==1)
	  {
		  while(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin)==1);
		  key_data = '-';
		  status.data_available = 1;
	  }
	  HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, 0);

	  /*R4 mapping*/
	  HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, SET);
	  if(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin)==1)
	  {
		  while(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin)==1);
		  key_data = 'C';
		  status.data_available = 1;
	  }
	  else if(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin)==1)
	  {
		  while(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin)==1);
		  key_data = '0';
		  status.data_available = 1;
	  }
	  else if(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin)==1)
	  {
		  while(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin)==1);
		  key_data = '=';
		  status.data_available = 1;
	  }
	  else if(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin)==1)
	  {
		  while(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin)==1);
		  key_data = '+';
		  status.data_available = 1;
	  }
	  HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, 0);

	  return key_data;
}

void perform_calculation( uint32_t D1, uint32_t D2, char op)
{
	switch (op)
	{
		case '+':
			result = D1+D2;
			break;
		case '-':
			if(D2>D1)
			{
				result = D2-D1;
				status.negative_result = 1;
			}
			else
			{
				result = D1 - D2;
				status.negative_result = 0;
			}
			break;
		case 'x':

			result = D1*D2;
			break;
		case '/':
			result = D1/D2;
			break;
		default:
			lcd_Send_String("SYNTAX ERROR");
			break;
	}
}

void display_number(uint32_t num)
{
	int temp =0;
	int arr[10];
	while(num!=0)
	{
		arr[temp] = num%10;
		num = num/10;
		temp++;
	}
	temp--;
	if(status.negative_result)
		lcd_send_data('-');

	while(temp>=0)
	{
		lcd_send_data(arr[temp]+'0');
		temp--;
	}

}
void check_data(char data)
{
	status.data_available = 0 ;
	if(data>='0' && data<='9')
	{
		if( status.input2 == 1)
			second_input = (second_input*10)+ (data - 0x30);
		else
			first_input = (first_input*10)+ (data - 0x30) ;

	}

	else
	{
		switch (data)
		{
			case '+':
				if(status.input2)
				{
					perform_calculation(first_input, second_input, operator);
					first_input = result;
					second_input = 0;
					lcd_clear();
					operator = data;
				}
				else
				{
					status.input2 = 1;
					operator = data;
				}

				break;
			case '-':
				if(status.input2)
				{
					perform_calculation(first_input, second_input, operator);
					first_input = result;
					second_input = 0;
					lcd_clear();
					operator = data;
				}
				else
				{
					status.input2 = 1;
					operator = data;
				}

				break;
			case 'x':
				if(status.input2)
				{
					perform_calculation(first_input, second_input, operator);
					first_input = result;
					second_input = 0;
					lcd_clear();
					operator = data;
				}
				else
				{
					status.input2 = 1;
					operator = data;
				}

				break;
			case '/':
				if(status.input2)
				{
					perform_calculation(first_input, second_input, operator);
					first_input = result;
					second_input = 0;
					lcd_clear();
					operator = data;
				}
				else
				{
					status.input2 = 1;
					operator = data;
				}

				break;
			case '=':
				if(first_input == 0)
				{
					lcd_clear();
					lcd_set_cursor(0,3);
					lcd_Send_String("SYNTAX ERROR");
				}
			   else
				{
					perform_calculation(first_input, second_input, operator);
					HAL_Delay(10);
				}

				status.cal_complete = 1;

				break;
			case 'C':
				lcd_clear();
				if(status.input2 && (second_input == 0))
				{
					status.input2 = false;
					operator = 0;
				}
				else if(status.input2 && second_input != 0)
				{
					second_input = second_input/10;
				}
				else
				{
					if(first_input != 0)
						first_input = first_input/10;
				}
				break;

			default:
				break;
		}
	}


}

void display_data()
{
	lcd_set_cursor(0,0);
	if(first_input == 0 && status.cal_complete == 0)
		lcd_send_data('0');
	display_number(first_input);
	if(status.input2)
	{
		lcd_send_data(operator);
		display_number(second_input);
	}
	if(status.cal_complete)
	{
		lcd_set_cursor(1, 0);
		lcd_send_data('=');

		if(result == 0)
			lcd_send_data('0');
		else
			display_number(result);
	}
}


