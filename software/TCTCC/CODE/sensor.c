#include "headfile.h"


float ad_value[SENSOR_NUMBER][8];
float ad_sum[SENSOR_NUMBER];
float AD[SENSOR_NUMBER]={0};
float turn_error= 0,turn_error1=0.00,turn_error2=0.00,turn_error3=0.00,turn_error4=0.00,turn_error5=0.00;
float sensor1=0,sensor2=0,sensor3=0,sensor4=0,sensor5=0,sensor6=0,sensor7=0,sensor8=0,sensor9=0,sensor10=0,sensor11=0,sensor12=0,sensor13=0;
float volt[5]={0},volt_real=0;

uint8 special_Flag = 0,last_special_Flag = 0,lost_Flag=0,Sensor_Value_Flag = 0,Ring_Direction_Flag = 0;
//Ring_Direction_Flag       其中0代表左环，1代表右环
uint32 max_v[SENSOR_NUMBER];
uint32 turn_out=0;//舵机输出
uint32 last_turn_out=0;
uint32 distance=0;


void AD_Init(void)
{
    adc_init(ADC_0, ADC0_CH0_A0);
    adc_init(ADC_0, ADC0_CH1_A1);
    adc_init(ADC_0, ADC0_CH2_A2);
    adc_init(ADC_0, ADC0_CH3_A3);
    adc_init(ADC_0, ADC0_CH4_A4);
    adc_init(ADC_0, ADC0_CH5_A5);
    adc_init(ADC_0, ADC0_CH6_A6);
    adc_init(ADC_0, ADC0_CH7_A7);
    adc_init(ADC_0, ADC0_CH8_A8);
    adc_init(ADC_0, ADC0_CH10_A10);
    adc_init(ADC_0, ADC0_CH11_A11);
    adc_init(ADC_0, ADC0_CH12_A12);
    adc_init(ADC_0, ADC0_CH13_A13);


    max_v[0] = flash_read(SECTOR_AD,0,uint32);
    max_v[1] = flash_read(SECTOR_AD,1,uint32);
    max_v[2] = flash_read(SECTOR_AD,2,uint32);
    max_v[3] = flash_read(SECTOR_AD,3,uint32);
    max_v[4] = flash_read(SECTOR_AD,4,uint32);
    max_v[5] = flash_read(SECTOR_AD,5,uint32);
    max_v[6] = flash_read(SECTOR_AD,6,uint32);
    max_v[7] = flash_read(SECTOR_AD,7,uint32);
    max_v[8] = flash_read(SECTOR_AD,8,uint32);
    max_v[9] = flash_read(SECTOR_AD,9,uint32);
    max_v[10] = flash_read(SECTOR_AD,10,uint32);
    max_v[11] = flash_read(SECTOR_AD,11,uint32);
    max_v[12] = flash_read(SECTOR_AD,12,uint32);


systick_delay_ms(STM0, 200);//延时
}


void AD_Collect()//AD采集
{

  int16 i,j,k,temp;
      for(i = 0; i <8; i++)
       {
         ad_value[0][i]= adc_mean_filter(ADC_0, ADC0_CH4_A4, ADC_12BIT, 5);//0
         ad_value[1][i]= adc_mean_filter(ADC_0, ADC0_CH5_A5, ADC_12BIT, 5);//1
         ad_value[2][i]= adc_mean_filter(ADC_0, ADC0_CH6_A6, ADC_12BIT, 5);//2
         ad_value[3][i]= adc_mean_filter(ADC_0, ADC0_CH7_A7, ADC_12BIT, 5);//3
         ad_value[4][i]= adc_mean_filter(ADC_0, ADC0_CH2_A2, ADC_12BIT, 5);//4
         ad_value[5][i]= adc_mean_filter(ADC_0, ADC0_CH0_A0, ADC_12BIT, 5);//2
         ad_value[6][i]= adc_mean_filter(ADC_0, ADC0_CH1_A1, ADC_12BIT, 5);//3
         ad_value[7][i]= adc_mean_filter(ADC_0, ADC0_CH3_A3, ADC_12BIT, 5);//3
         ad_value[8][i]= adc_mean_filter(ADC_0, ADC0_CH8_A8, ADC_12BIT, 5);
         ad_value[9][i]= adc_mean_filter(ADC_0, ADC0_CH10_A10, ADC_12BIT, 5);
         ad_value[10][i]= adc_mean_filter(ADC_0, ADC0_CH11_A11, ADC_12BIT, 5);
         ad_value[11][i]= adc_mean_filter(ADC_0, ADC0_CH12_A12, ADC_12BIT, 5);
         ad_value[12][i]= adc_mean_filter(ADC_0, ADC0_CH13_A13, ADC_12BIT, 5);

       }

     // =========================冒泡排序升序==========================//
       for(i=0;i<SENSOR_NUMBER;i++)
       {
         for(j=0;j<8-1;j++)//5个数据排序
         {
           for(k=0;k<8-j-1;k++)
           {
             if(ad_value[i][k]>ad_value[i][k+1]) //前面的比后面的大则进行交换
             {
               temp=ad_value[i][k+1];
               ad_value[i][k+1]=ad_value[i][k];
               ad_value[i][k]= temp;
             }
           }
         }
       }
 //      ===========================中值滤波=================================
       for(i=0;i<SENSOR_NUMBER;i++)    //求中间四项的和
       {
          ad_sum[i] =ad_value[i][2]+ad_value[i][3]+ad_value[i][4]+ad_value[i][5];
          AD[i]=ad_sum[i]/4; //求平均值
       }

}



void SC_black_Init()//最大值采样
{

    uint16 i,j;
    uint32 write_buf;
    lcd_clear(WHITE);
    lcd_showstr(20,0,"SC_blacking......");
    pit_disable_interrupt(CCU6_0, PIT_CH0);
    pit_disable_interrupt(CCU6_0, PIT_CH1);

      max_v[0] = max_v[1] = max_v[2] = max_v[3]=max_v[4]=max_v[5]=max_v[6]=0;
      BEEP_ON;//蜂鸣器
      systick_delay_ms(STM0, 500);//延时10ms
      BEEP_OFF;//蜂鸣器
      BEEP_ON;//蜂鸣器
      systick_delay_ms(STM0, 500);//延时10ms
      BEEP_OFF;//蜂鸣器


     for(i=0;i<4000;i++)//采集执行的时间
     {
                 ad_value[0][0]= adc_mean_filter(ADC_0, ADC0_CH4_A4, ADC_12BIT, 5);//0
                 ad_value[1][0]= adc_mean_filter(ADC_0, ADC0_CH5_A5, ADC_12BIT, 5);//1
                 ad_value[2][0]= adc_mean_filter(ADC_0, ADC0_CH6_A6, ADC_12BIT, 5);//2

                 ad_value[3][0]= adc_mean_filter(ADC_0, ADC0_CH7_A7, ADC_12BIT, 5);//3
                 ad_value[4][0]= adc_mean_filter(ADC_0, ADC0_CH2_A2, ADC_12BIT, 5);//4

                 ad_value[5][0]= adc_mean_filter(ADC_0, ADC0_CH0_A0, ADC_12BIT, 5);//2
                 ad_value[6][0]= adc_mean_filter(ADC_0, ADC0_CH1_A1, ADC_12BIT, 5);//3
                 ad_value[7][0]= adc_mean_filter(ADC_0, ADC0_CH3_A3, ADC_12BIT, 5);//3
                 ad_value[8][0]= adc_mean_filter(ADC_0, ADC0_CH8_A8, ADC_12BIT, 5);     //电压
                 ad_value[9][0]= adc_mean_filter(ADC_0, ADC0_CH10_A10, ADC_12BIT, 5);
                 ad_value[10][0]= adc_mean_filter(ADC_0, ADC0_CH11_A11, ADC_12BIT, 5);
                 ad_value[11][0]= adc_mean_filter(ADC_0, ADC0_CH12_A12, ADC_12BIT, 5);
                 ad_value[12][0]= adc_mean_filter(ADC_0, ADC0_CH13_A13, ADC_12BIT, 5);

                 for(j=0;j<SENSOR_NUMBER;j++)
                 {

                     if(ad_value[j][0]>max_v[j])
                     {
                         max_v[j] = ad_value[j][0];//扫描最大值
                     }
                 }

                 lcd_showuint16(0,1,i/40);
                 systick_delay_ms(STM0, 1);//延时1ms
                 lcd_showstr(40,1,"%");

//                         lcd_showfloat(0,   0,  ad_value[0][i],  4,1);
//                         lcd_showfloat(50,  0,  ad_value[1][i],  4,1);
//                         lcd_showfloat(100, 0,  ad_value[2][i],  4,1);
//                         lcd_showfloat(0,   1,  ad_value[3][i],  4,1);
//                         lcd_showfloat(50,  1,  ad_value[4][i],  4,1);
//                         lcd_showfloat(100, 1,  ad_value[5][i],  4,1);
//                         lcd_showfloat(0,   2,  ad_value[6][i],  4,1);
//                         lcd_showfloat(50,  2,  ad_value[7][i],  4,1);
//                         lcd_showfloat(100, 2,  ad_value[8][i],  4,1);
//                         lcd_showfloat(0,   3,  ad_value[9][i],  4,1);
//                         lcd_showfloat(50,  3,  ad_value[10][i], 4,1);
//                         lcd_showfloat(100, 3,  ad_value[11][i], 4,1);
//                         lcd_showfloat(0,   4,  ad_value[12][i], 4,1);

     }

    eeprom_erase_sector(SECTOR_AD);//擦除10扇区

    for(i=0;i<SENSOR_NUMBER;i++)
    {
        write_buf = max_v[i];
        eeprom_page_program(SECTOR_AD, i, &write_buf);
    }

    lcd_showuint16(0,1,i/40);
    pit_enable_interrupt(CCU6_0, PIT_CH0);
    pit_enable_interrupt(CCU6_0, PIT_CH1);
    BEEP_ON;//蜂鸣器
    systick_delay_ms(STM0, 200);//延时10ms
    BEEP_OFF;//蜂鸣器
    systick_delay_ms(STM0, 200);//延时10ms
    lcd_clear(WHITE);
}







void AD_Date_analyse()//电感值处理
{

    sensor1  = 100*AD[3] / max_v[3];
    sensor2  = 100*AD[4] / max_v[4];
    sensor3  = 100*AD[7] / max_v[7];
    sensor4  = 100*AD[2] / max_v[2];
    sensor5  = 100*AD[12] / max_v[12];
    sensor6  = 100*AD[1] / max_v[1];
    sensor7  = 100*AD[6] / max_v[6];
    sensor8  = 100*AD[5] / max_v[5];
    sensor9  = 100*AD[10] / max_v[10];
    sensor10 = 100*AD[9] / max_v[9];
    sensor11 = 100*AD[8] / max_v[8];//电压
    sensor12 = 100*AD[11] / max_v[12];
    sensor13 = 100*AD[0] / max_v[13];
}



//特殊元素识别
void special_ident()
{



    //左直角
    if(!special_Flag)
        {
 //           if(sensor3-sensor8>35 && sensor3+sensor7<160&&sensor1<50&&sensor6<50&&sensor2<70&&sensor7<70&&sensor3<80&&sensor8<50)
        if(sensor3-sensor8>30 && sensor2+sensor7<80&&sensor1<30&&sensor6<20&&sensor2<70&&sensor7<70&&sensor3<80&&sensor8<30)
            {
                special_Flag=  1;//1
                time[5]=0;
                Angle_Count_Start(10 , 0);
                Angle_Count_Start(70 , 1);
            }
    //右直角
//            else if(sensor8-sensor3>35 && sensor3+sensor7<160 && sensor1<50 && sensor6<50 && sensor2<70 && sensor3<30 && sensor8<80)// && sensor7<50)
        else if(sensor8-sensor3>30 && sensor2+sensor7<80 && sensor1<20 && sensor6<30 && sensor2<70 && sensor3<30 && sensor8<80)
            {
            special_Flag=  2;//
            time[5]=0;
            Angle_Count_Start(-10 , 0);
            Angle_Count_Start(-70 , 1);
            }

   //入环


                //进右环

//                if((sensor4>120 && sensor6>sensor2 && sensor7>80 && sensor1<60 ))
//                {
//                    special_Flag = 4;
//                    distance=0;
//                }
        if(sensor4>120&&(sensor1>120||sensor6>120))
            switch(Ring_Direction_Flag)
            {
                case 0 : special_Flag = 3;   Angle_Count_Start( 66 , 2);      break;
                case 1 : special_Flag = 4;   Angle_Count_Start(-66 , 3);     break;
                default: break;

            }



            }








//标志位清除
    if(special_Flag)
    {
        switch(special_Flag)
        {
            case    1   :

                     //if(angle_contro(30)>0.75)
                    if(sensor4>30&&Angle_K[0] >0.9)
                       special_Flag=0;
                     break;

            case    2   :
                    //if(angle_contro(-30)>0.75)
                    if((sensor4>30)&&Angle_K[0] >0.9)
                        special_Flag=0;
                    break;
            case 3:
                    sensor8 = 0;
                    if(Angle_K[2] > 0.9)
                    special_Flag = 0;
                    break;
                    //计步行进之后脱出标志位，进入六标志位，向右打角度；
            case 4:
                    sensor8 = 0;
                    if(Angle_K[3] > 0.9)
                    special_Flag = 0;
                    break;

            case 5:

                    break;
            case 6:
                    if(distance>8000)
                    special_Flag=0;
                    break;
        }

    last_special_Flag=special_Flag;
    }
    //当前丢线时
        if(sensor1<10&&sensor2<10&&sensor3<10&&sensor4<10&&sensor5<10&&sensor6<10&&sensor7<10&&sensor8<10 && (special_Flag==0 || ((special_Flag == 3 && Angle_K[1] > 0.9) || (special_Flag == 3 && Angle_K[1] > 0.9))))
            lost_Flag=1;

}




void turn_out_cal()//舵机控制
{

            turn_error1 =-   100*(((sensor2 + sensor4 - sensor1 )/(sensor2 + sensor1+sensor4)) - ((sensor7 + sensor4 - sensor6 )/(sensor7 + sensor6+sensor4)));
            turn_error2 =-   100*(((sensor4 - sensor3 )/(sensor3+sensor4)) - ((sensor4 - sensor8 )/(sensor8+sensor4)));



            //电感值过小，不考虑偏差
            if(sensor1<5&&sensor6<5)      turn_error1=0;
            if(sensor2<5&&sensor7<5)      turn_error2=0;
            if(sensor3<5&&sensor8<5)      turn_error3=0;
            if(sensor4<5&&sensor9<5)      turn_error4=0;
            if(sensor5<5&&sensor10<5)     turn_error5=0;

            if(Car_Sudu<=400)
                turn_error = turn_error1 + turn_error2;
            else if((Car_Sudu<=600))
                turn_error = turn_error1 + 1.2*turn_error2;
//            if(fabs(turn_error) <= fabs(turn_error2))               turn_error = turn_error2;
//            if(fabs(turn_error) <= fabs(turn_error3))               turn_error = turn_error3;
//            if(fabs(turn_error) <= fabs(turn_error4))               turn_error = turn_error4;

            turn_PID(turn_error);

       switch(special_Flag)
       {

           case 0:
                               BEEP_OFF;
                               turn_out = turn_PID_out;
                               //Car_Sudu=Car_Sudu1;
                               break;

         //左直角
           case 1:           turn_out=DirectLeft;          BEEP_ON;         break;


         //右直角
           case 2:           turn_out=DirectRight;         BEEP_ON;         break;


         //左环
           case 3:           //turn_out=DirectMiddle+0.1*(DirectLeft-DirectMiddle);
                             BEEP_ON;
                             //distance=distance+0.25*Speed;

                             turn_out=turn_PID_out;
                             break;


         //右环
           case 4:           //turn_out=DirectMiddle-0.6*(DirectMiddle-DirectRight);
                             BEEP_ON;
                             //distance=distance+0.25*Speed;
                             turn_out = DirectMiddle;//turn_PID_out;
                             break;

           case 5:          break;
           case 6:          turn_out=DirectMiddle-0.5*(DirectMiddle-DirectRight);
                            distance=distance+0.25*Speed;
                            break;
           case 7:          break;
           case 8:          break;
           default :        break;


       }

         servo_out(turn_out);
         last_turn_out = turn_out;

      }



void Sensor_Standard()
{
    switch(Sensor_Value_Flag)
    {
        case 0 :
                max_v[0] = flash_read(SECTOR_AD,0,uint32);
                max_v[1] = flash_read(SECTOR_AD,1,uint32);
                max_v[2] = flash_read(SECTOR_AD,2,uint32);
                max_v[3] = flash_read(SECTOR_AD,3,uint32);
                max_v[4] = flash_read(SECTOR_AD,4,uint32);
                max_v[5] = flash_read(SECTOR_AD,5,uint32);
                max_v[6] = flash_read(SECTOR_AD,6,uint32);
                max_v[7] = flash_read(SECTOR_AD,7,uint32);
                max_v[8] = flash_read(SECTOR_AD,8,uint32);
                max_v[9] = flash_read(SECTOR_AD,9,uint32);
                max_v[10] = flash_read(SECTOR_AD,10,uint32);
                max_v[11] = flash_read(SECTOR_AD,11,uint32);
                max_v[12] = flash_read(SECTOR_AD,12,uint32);
            break;
        case 1 :
                max_v[0] = 2500;
                max_v[1] = 2500;
                max_v[2] = 2500;
                max_v[3] = 2500;
                max_v[4] = 2500;
                max_v[5] = 2500;
                max_v[6] = 2500;
                max_v[7] = 2500;
                max_v[8] = 2500;
                max_v[9] = 2500;
                max_v[10] = 2500;
                max_v[11] = 2500;
                max_v[12] = 2500;
            break;

        default :
            break;
    }


}


