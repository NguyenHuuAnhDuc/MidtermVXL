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
enum ButtonState {BUTTON_RELEASED, BUTTON_PRESSED , BUTTON_PRESSED_MORE_THAN_3_SECOND, BUTTON_2, BUTTON_3};
enum ButtonState buttonState = BUTTON_RELEASED;

int counter = 0;

void fsm_for_input_processing(void){
 switch(buttonState){
 	 case BUTTON_RELEASED :
 		 if(is_button_pressed(0)){
 			 buttonState = BUTTON_PRESSED ;
 			 counter = 0;
 		 }
 		 if(is_button_pressed(1)){
 		 			 buttonState = BUTTON_2 ;
 		 			 counter++;
 		 		 }
 		 if(is_button_pressed(2)){
 		 			 buttonState = BUTTON_3 ;
 		 			 counter--;
 		 		 }
 		 break ;
 	 case BUTTON_PRESSED :
 		 if(!is_button_pressed(0)){
 			 buttonState = BUTTON_RELEASED ;
 		 }
 		 display7SEG(counter);
 		 break;
 	 case BUTTON_PRESSED_MORE_THAN_3_SECOND:
 		 if(!is_button_pressed(0)){
 			 buttonState = BUTTON_RELEASED;
 		 }
 		 break;
 	 case BUTTON_2:
 		if(!is_button_pressed(1)){
 		 			 buttonState = BUTTON_RELEASED ;
 		 		 }
 		 		 else{
 		 			 if(is_button_pressed_3s(1)){
 		 				 buttonState = BUTTON_PRESSED_MORE_THAN_3_SECOND;
 		 			 }
 		 		 }
 		if(counter > 9){
 			counter = 0;
 		}
 		display7SEG(counter);
 		 		 break;
 	 case BUTTON_3:
 	 		if(!is_button_pressed(2)){
 	 		 			 buttonState = BUTTON_RELEASED ;
 	 		 		 }
 	 		 		 else{
 	 		 			 if(is_button_pressed_3s(2)){
 	 		 				 buttonState = BUTTON_PRESSED_MORE_THAN_3_SECOND;
 	 		 			 }
 	 		 		 }
 	 		if(counter < 0){
 	 			counter = 9;
 	 		}
 	 		display7SEG(counter);
 	 		 		 break;

 	 }
}
