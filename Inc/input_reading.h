/*
 * input_reading.h
 *
 *  Created on: Nov 6, 2022
 *      Author: Admins
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include "main.h"

void button_reading ();
unsigned char is_button_pressed(uint8_t index);
unsigned char is_button_pressed_3s(unsigned char index);

#endif /* INC_BUTTON_H_ */
