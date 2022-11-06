/*
 * input_reading.c
 *
 *  Created on: Nov 6, 2022
 *      Author: Admins
 */
#include "input_reading.h"
#include "main.h"

#define N0_OF_BUTTONS 3
#define DURATION_FOR_AUTO_INCREASING 300
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET

static GPIO_PinState buttonBuffer [ N0_OF_BUTTONS ];
static GPIO_PinState debounceButtonBuffer1 [ N0_OF_BUTTONS ];
static GPIO_PinState debounceButtonBuffer2 [ N0_OF_BUTTONS ];
static uint8_t flagForButtonPress3s [ N0_OF_BUTTONS ];
static uint16_t counterForButtonPress3s [ N0_OF_BUTTONS ];

void button_reading(){
	for ( int i = 0; i < N0_OF_BUTTONS ; i ++) {
		debounceButtonBuffer2 [ i ] = debounceButtonBuffer1 [ i ];
		if(i==0){
			debounceButtonBuffer1 [ i ] = HAL_GPIO_ReadPin(RS_Button_GPIO_Port,RS_Button_Pin);
		}
		if(i==1){
			debounceButtonBuffer1 [ i ] = HAL_GPIO_ReadPin(INC_Button_GPIO_Port,INC_Button_Pin);
		}
		if(i==2){
			debounceButtonBuffer1 [ i ] = HAL_GPIO_ReadPin(DEC_Button_GPIO_Port,DEC_Button_Pin);
		}
		if( debounceButtonBuffer1 [ i ] == debounceButtonBuffer2 [i])
			buttonBuffer [i] = debounceButtonBuffer1 [ i ];
		if( buttonBuffer [i ] == BUTTON_IS_PRESSED ) {
			if( counterForButtonPress3s [ i ] < DURATION_FOR_AUTO_INCREASING ) {
				counterForButtonPress3s [ i ]++;
			} else {
				flagForButtonPress3s [i] = 1;
			}
		} else {
			counterForButtonPress3s [i] = 0;
			flagForButtonPress3s [i ] = 0;
		}
	}
}
unsigned char is_button_pressed ( uint8_t index ) {
 if( index >= N0_OF_BUTTONS ) return 0;
 return ( buttonBuffer [ index ] == BUTTON_IS_PRESSED );
}
unsigned char is_button_pressed_3s( unsigned char index ) {
 if( index >= N0_OF_BUTTONS ) return 0xff ;
 return ( flagForButtonPress3s [ index ] == 1) ;
}

