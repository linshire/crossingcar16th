#ifndef _CONTROL_H_
#define _CONTROL_H_


#define PI 3.1415926
#define Angle_Number  5

extern uint8    PID_Switch_Flag,Speed_Up_Flag;
extern float    Speed_P,Speed_I,Speed_D;
extern float    mpu6050_acc_x,mpu6050_acc_y,mpu6050_acc_z,Angle;
extern float    angle_sum,lats_angle;
extern float    Speed_P,Speed_I,Speed_D;
extern int16    Speed,SPEED;
extern int16 Speed_Straight ,Speed_Curve ,Speed_Max;
extern int16    Car_Sudu,Car_Sudu1;
extern uint16   time[6];
                //time[0]���ڴ��ڱ�־λ
                //time[1]�������һ���ʱ
                //time[2]������������Ƿ�ˢ�£�tft��ʾ
                //time[3]���ڳ������ͣ����ʱ
                //time[4]��������ʱ���ʱ
                //time[5]���ڱ�־λ���ʱ�价��ʱ
extern uint32   DirectMiddle;
extern uint32   DirectLeft;
extern uint32   DirectRight;
extern uint32   Turn_Out_Remote;
extern float    sevro_duty;
extern float    Angle_K[Angle_Number];

extern void     Turn_PD(float Input);
extern void     time_counter(void);
extern void     Date_Display(void);
extern void     AD_Date_analyse(void);
extern void     Speed_Control(void);
extern int16    Speed_PID(int16 Goal,int16 Input);
extern void     servo_out(uint32 duty);
extern void     MPU6050_data_analyse(void);
extern void     Angle_Count_Start(float Goal_Angle , uint8 Angle_Way);
extern void     Angle_Count(void);
#endif
