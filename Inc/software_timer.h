/*
 * software_timer.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Admins
 */

#ifndef __SOFTWARE_TIMER_
#define __SOFTWARE_TIMER_

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;

void setTimer1(int duration);
void timerRun();
void setTimer2(int duration);
void setTimer3(int duration);



#endif
