/*
 * display_7segment.c
 *
 *  Created on: Nov 6, 2022
 *      Author: Admins
 */
#include "main.h"
void display7SEG(int num){
	  switch(num){
	  case 0:
	  HAL_GPIO_WritePin(GPIOB, G_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOB, B_Pin | C_Pin | D_Pin | E_Pin | F_Pin | A_Pin, GPIO_PIN_RESET);
	  break;
	  case 1:
	  HAL_GPIO_WritePin(GPIOB, B_Pin | C_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOB, A_Pin | D_Pin | E_Pin | F_Pin | G_Pin, GPIO_PIN_SET);
	  break;
	  case 2:
	  HAL_GPIO_WritePin(GPIOB, F_Pin | C_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOB, B_Pin | G_Pin | D_Pin | E_Pin | A_Pin, GPIO_PIN_RESET);
	  break;
	  case 3:
	  HAL_GPIO_WritePin(GPIOB, F_Pin | E_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOB, B_Pin | G_Pin | D_Pin | C_Pin | A_Pin, GPIO_PIN_RESET);
	  break;
	  case 4:
	  HAL_GPIO_WritePin(GPIOB, A_Pin | E_Pin | D_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOB, B_Pin | G_Pin | F_Pin | C_Pin, GPIO_PIN_RESET);
	  break;
	  case 5:
	  HAL_GPIO_WritePin(GPIOB, B_Pin | E_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOB, F_Pin | G_Pin | D_Pin | C_Pin | A_Pin, GPIO_PIN_RESET);
	  break;
	  case 6:
	  HAL_GPIO_WritePin(GPIOB, B_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOB, F_Pin | G_Pin | D_Pin | E_Pin | C_Pin | A_Pin, GPIO_PIN_RESET);
	  break;
	  case 7:
	  HAL_GPIO_WritePin(GPIOB, F_Pin | E_Pin | D_Pin | G_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOB, B_Pin | C_Pin | A_Pin, GPIO_PIN_RESET);
	  break;
	  case 8:
	  HAL_GPIO_WritePin(GPIOB, B_Pin | C_Pin | D_Pin | E_Pin | F_Pin | A_Pin | G_Pin, GPIO_PIN_RESET);
	  break;
	  case 9:
	  HAL_GPIO_WritePin(GPIOB, E_Pin , GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOB, B_Pin | C_Pin | D_Pin | G_Pin | F_Pin | A_Pin, GPIO_PIN_RESET);
	  break;
	  default:
	  break;
	  }
  }
