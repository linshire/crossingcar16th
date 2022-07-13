#include "headfile.h"


int16 Out_Speed,last_Out_Speed;

int Speed_error=0,PSpeed_error=0,ISpeed_error=0,DSpeed_error=0,last_error=0,last_last_error=0;
int16 last_Goal=0;
float turn_Kp[6]={0},turn_Kd[6]={0} , turn_Ki[6]={0};
      //turn_Ki[6]={0.00007};
float alfa = 0;
uint32 turn_PID_out=0;
float last_turn_error=0, error_sum=0, PID_D=0;
uint8 PID_flag = 0;
float gama = 0.4;

int16 Speed_PID(int16 Goal,int16 Input)
{

        //期望改变，数据重置
//      if(last_Goal!=Goal)
//      {
//          Speed_error=0,PSpeed_error=0,ISpeed_error=0,DSpeed_error=0,last_error=0,last_last_error=0;
//          last_Goal=Goal;
//      }

      Speed_error   =Goal-Input;
      PSpeed_error  = Speed_error - last_error;//比例
      DSpeed_error = Speed_error -2*last_error-last_last_error;//微分
      ISpeed_error = Speed_error;
      last_last_error=last_error;
      last_error=Speed_error;
      Out_Speed += PSpeed_error*Speed_P+ISpeed_error*Speed_I+DSpeed_error*Speed_D;


      //if(Goal*Out_Speed<0)
        //  Out_Speed=0;
      last_Goal=Goal;
      return Out_Speed;
}




void turn_PID(float error)
{

    float temp=0 , c1=0 , c2=0, c3=0;

    error_sum += error;
switch(PID_flag)
{
    case 0:

        if(error<100&&error>-100)//小弯
           {
           turn_Kp[0]=2.3;
           turn_Kd[0]=0.3;
           //Car_Sudu1 = 500;
           turn_PID_out = DirectMiddle + (float)turn_Kp[0]*error + error_sum*turn_Ki[0]  + (error - last_turn_error)*(float)turn_Kd[0]*(1-alfa) + alfa*last_turn_error;
           }


        else if(error<200&&error>-200)//中弯
           {
            turn_Kp[1]=2;
            turn_Kd[1]=0.4;
            //Car_Sudu1 = Car_Sudu;
            turn_PID_out = DirectMiddle + (float)turn_Kp[1]*error + error_sum*turn_Ki[0]  + (error - last_turn_error)*(float)turn_Kd[1] * (1 - alfa) + alfa*last_turn_error;
           }
        else if(error<600&&error>-600)//大弯
           {
            turn_Kp[2]=2;
            turn_Kd[2]=0.1;
            turn_PID_out = DirectMiddle + (float)turn_Kp[2]*error + error_sum*turn_Ki[0]  + (error - last_turn_error)*(float)turn_Kd[2] * (1 - alfa) + alfa*last_turn_error;
           }

        else
           {

            turn_Kp[3]=2;
            turn_Kd[3]=0.1;
            turn_PID_out = DirectMiddle + (float)turn_Kp[3]*error + error_sum*turn_Ki[0]  + (error - last_turn_error)*(float)turn_Kd[3] * (1 - alfa) + alfa*last_turn_error;
           }
        break;
    case 1 :

    if(error<100&&error>-100)//小弯
               {

               turn_Kp[0]=2.0;
               turn_Kd[0]=0.8;
               //Car_Sudu1 = Car_Sudu + 100;
               turn_PID_out = DirectMiddle + (float)turn_Kp[0]*error + error_sum*turn_Ki[0]  + (error - last_turn_error)*(float)turn_Kd[0]*(1-alfa) + alfa*last_turn_error;
               }


            else if(error<200&&error>-200)//中弯
               {

                turn_Kp[1]=2.5;
                turn_Kd[1]=0.8;
                //Car_Sudu1 = Car_Sudu;
                turn_PID_out = DirectMiddle + (float)turn_Kp[1]*error + error_sum*turn_Ki[0]  + (error - last_turn_error)*(float)turn_Kd[1] * (1 - alfa) + alfa*last_turn_error;
               }

            else
               {
                turn_Kp[3]=2;
                turn_Kd[3]=0.8;
                turn_PID_out = DirectMiddle + (float)turn_Kp[3]*error + error_sum*turn_Ki[0]  + (error - last_turn_error)*(float)turn_Kd[3] * (1 - alfa) + alfa*last_turn_error;
               }
            break;
}
//    error_sum += error;
//    temp = gama *turn_Ki[PID_flag] +turn_Kp[PID_flag];
//    c3 = turn_Kd[PID_flag] / temp;
//    c2 = ( turn_Kd[PID_flag] + turn_Kp[PID_flag]) / temp;
//    c1 = gama * c3;
//    PID_D = c1 * PID_D + c2 * error + c3 *  last_turn_error;
//    turn_PID_out = turn_Kp[PID_flag] + turn_Ki[PID_flag] * error_sum + PID_D;

    last_turn_error = error;
}


