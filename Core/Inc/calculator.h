/*
 * keypad.h
 *
 *  Created on: Sep 23, 2023
 *      Author: anjal
 */

#ifndef INC_CALCULATOR_H_
#define INC_CALCULATOR_H_
#include "stdint.h"
#include <stdbool.h>



typedef struct
{
	bool data_available;
	bool input2;
	bool cal_complete;
	bool negative_result;
	bool sleep;
}flag;

char key_map();
void check_data(char data);
void perform_calculation( uint32_t D1, uint32_t D2, char op);
void calci_init();
void display_number(uint32_t num);

void display_data();
#endif /* INC_CALCULATOR_H_ */
