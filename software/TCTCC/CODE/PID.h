
#ifndef _PID_h
#define _PID_h



extern float turn_Kp[6],turn_Kd[6];
extern uint32 turn_PID_out;

extern void turn_PID(float error);

#endif
