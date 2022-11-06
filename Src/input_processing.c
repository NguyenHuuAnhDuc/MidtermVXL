/*
 * input_processing.c
 *
 *  Created on: Nov 6, 2022
 *      Author: Admins
 */
#include "main.h"
#include "input_reading.h"
#include "software_timer.h"
#include "display_7segment.h"
enum ButtonState {BUTTON_RELEASED, BUTTON_PRESSED , BUTTON_PRESSED_MORE_THAN_3_SECOND};
enum ButtonState buttonState = BUTTON_RELEASED;

int counter = 0;

void fsm_for_input_processing(void){
 switch(buttonState){
 	 case BUTTON_RELEASED :
 		 if(is_button_pressed(0)){
 			 buttonState = BUTTON_PRESSED ;
 			 counter++;
 		 }
 		 display7SEG(9);
 		 break ;
 	 case BUTTON_PRESSED :
 		 if(!is_button_pressed(0)){
 			 buttonState = BUTTON_RELEASED ;
 		 }
 		 else{
 			 if(is_button_pressed_3s(0)){
 				 buttonState = BUTTON_PRESSED_MORE_THAN_3_SECOND;
 			 }
 		 }
 		 display7SEG(0);
 		 break;
 	 case BUTTON_PRESSED_MORE_THAN_3_SECOND:
 		 if(!is_button_pressed(0)){
 			 buttonState = BUTTON_RELEASED;
 		 }
 		 break;
 	 }
}
