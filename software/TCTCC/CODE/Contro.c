#include "headfile.h"



uint16 Speed_Change_Count = 0;

uint32 Turn_Out_Remote = {0};
int16 Turn_Out;
int16 Error;
int16 Car_Sudu,Car_Sudu1;   //PID目标速度，按键赋值速度1
int16 Speed_Straight = 800,Speed_Curve = 450,Speed_Max = 1000;
int16 Speed,SPEED;          //Speed实时速度，SPEED滑动滤波后速度
uint32 DirectMiddle =605;//舵机中值(减小偏左)660
uint32 DirectLeft =810; // 左极限
uint32 DirectRight = 360;//右极限

float sevro_duty=0;
float Angle = 0, Angle_Error = 0, Start_Angle[Angle_Number] = {0}, Angle_K[Angle_Number] = {0},Goal_Angle[Angle_Number] = {0};
float Speed_P,Speed_I,Speed_D;

uint8 PID_Switch_Flag = 0;
uint8 SPI_Write_Flag = 0;     //1发送数据，0不发数据
uint8 Speed_Up_Flag=0;
uint16 time[6]={0};         //计时数组，放置在定时中断中，记录中断触发次数，部分功能的作为标志位
int16 last_speed[5]={0};
float angle_sum=0,lats_angle=0;
const float MPU6050_coe=0.00004;

void Speed_Change(void);


void Speed_Control()
{
//    int16 sum=0;
//    last_speed[0]=last_speed[1];
//    last_speed[1]=last_speed[2];
//    last_speed[2]=last_speed[3];
//    last_speed[3]=last_speed[4];
//    last_speed[4]=Speed;
//    sum=last_speed[0]+last_speed[1]+last_speed[2]+last_speed[3]+last_speed[4];
//    SPEED=sum/5;
    SPEED = Speed*3;
//弯道降速

//    if(turn_error>=0)
//    Car_Sudu1 = Car_Sudu + 0.6*turn_error;
//    else
//    Car_Sudu1 = Car_Sudu - 0.6*turn_error;




    switch(PID_Switch_Flag)
    {
        case 1:
            switch(Speed_Up_Flag)
            {
                case 1 :  Speed_Change();   break;
                case 0 :  if(Car_Sudu1 != Speed_Curve)  Car_Sudu1 = Speed_Curve;   break;
            }
            Motor_output(Speed_PID(Car_Sudu1 ,SPEED));
            break;
        case 0:
            Motor_output(0);
            break;
        default : break;
    }
}





void servo_out(uint32 duty)
{
    //限幅
    duty    =  duty > DirectLeft   ?   DirectLeft      :       duty;
    duty    =  duty < DirectRight  ?   DirectRight     :       duty;

    sevro_duty = duty;
    pwm_duty(ATOM0_CH2_P21_4, duty);

}


void time_counter()
{
    uint8 i=0;
    for(i=0;i<6;i++)
    time[i]= time[i]>60000?60000:(time[i]+1);

}



//陀螺仪角度滤波
void MPU6050_data_analyse()
{
//向右为负
    get_accdata();
    get_gyro();
    Angle = MPU6050_coe * (atan2(mpu_acc_x, mpu_acc_y) * 180 / PI) + (1-MPU6050_coe) * (Angle + mpu_gyro_z / 16.4 * 0.0075);
    Angle=(Angle-0.008);

//    Angle_error=Angle-start_Angle;
//    if(goal_angle>0)
//        if(Angle_error>goal_angle)
//    mpu6050_acc_y=mpu_acc_y;

}



//Angle_Way可选0~4
//陀螺仪积分
void Angle_Count_Start(float Goal_Angle_Start , uint8 Angle_Way)
{
    Start_Angle[Angle_Way] = Angle;
    Goal_Angle[Angle_Way] = Goal_Angle_Start;

}

void Angle_Count()
{
    uint8 i = 0;
    for(i = 0;i < Angle_Number; ++i)
    {
        Angle_Error = Angle - Start_Angle[i];
        Angle_K[i] = (Angle_Error / Goal_Angle[i]);
    }
}


void Speed_Change()
{

    if((!special_Flag)&&(turn_error<30&&turn_error>-30)&&sensor4>70)
        Speed_Change_Count ++;
    else if(special_Flag||turn_error>50||turn_error<-50||sensor4<70)
        Speed_Change_Count = 0;

    if(Speed_Change_Count>=20&&Speed_Change_Count<60)
    //if((!special_Flag)&&(turn_error<30&&turn_error>-30)&&sensor4>70)
        Car_Sudu1 +=5;
        //Car_Sudu1 = Speed_Straight;
    else if(Speed_Change_Count>=70&&Speed_Change_Count<100)
        Car_Sudu1 = Speed_Straight;
    else if(Speed_Change_Count>=100)
        Car_Sudu1 = Speed_Max;
    else Car_Sudu1 = Speed_Curve;

    Speed_Change_Count = Speed_Change_Count>10000 ? 10000:Speed_Change_Count;
    Car_Sudu1 = Car_Sudu1 >= Speed_Curve ?   Car_Sudu1:Speed_Curve;
    Car_Sudu1 = Car_Sudu1 <= Speed_Max ?   Car_Sudu1:Speed_Max;
}




void Date_Display()
{


               lcd_showfloat(0,    0,  sensor1,  3,1);
               lcd_showfloat(0,    1,  sensor2,  3,1);
               lcd_showfloat(0,    2,  sensor3,  3,1);
               lcd_showfloat(100,  0,  sensor4,  3,1);

               lcd_showfloat(50,   0,  sensor6,  3,1);
               lcd_showfloat(50,   1,  sensor7,  3,1);
               lcd_showfloat(50,   2,  sensor8,  3,1);
               lcd_showint32(100,6,PWMAAAA,5);

               if(Ring_Direction_Flag)
                 lcd_showstr(100, 5, "L");
               else
                 lcd_showstr(100,5,"R");


               if(Speed_Up_Flag)
                 lcd_showstr(100, 4, "UP");
               else
                 lcd_showstr(100,4,"NOR");


               if(!Sensor_Value_Flag)
               {
                      lcd_showint16(0,3,SPEED);
                      lcd_showuint16(0,6,time[4]);
                      lcd_showfloat(0,5,(float)turn_error,3,1);
                      lcd_showuint8(50,7,special_Flag);
                      lcd_showuint16(100,7,Speed_Curve);

                      lcd_showfloat(100,   3,  Angle, 3,1);                   //陀螺仪当前角度
                      lcd_showfloat(100,1,turn_error1,3,1);
                      lcd_showfloat(100,2,turn_error2,3,1);




                      lcd_showuint8(50,4,Sensor_Value_Flag);
                      lcd_showuint8(50,6,Speed_Up_Flag);
               }
}
