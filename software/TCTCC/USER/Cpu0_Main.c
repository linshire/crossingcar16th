/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：三群：824575535
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file            main
 * @company         成都逐飞科技有限公司
 * @author          逐飞科技(QQ3184284598)
 * @version         查看doc内version文件 版本说明
 * @Software        tasking v6.3r1
 * @Target core     TC264D
 * @Taobao          https://seekfree.taobao.com/
 * @date            2020-3-23
 ********************************************************************************************************************/
#include "math.h"
#include "ANO_DT.h"
#include "headfile.h"
#pragma section all "cpu0_dsram"
uint8 protect_flag=0;    //停车保护开关


//将本语句与#pragma section all restore语句之间的全局变量都放在CPU0的RAM中
//工程导入到软件之后，应该选中工程然后点击refresh刷新一下之后再编译
//工程默认设置为关闭优化，可以自己右击工程选择properties->C/C++ Build->Setting
//然后在右侧的窗口中找到C/C++ Compiler->Optimization->Optimization level处设置优化等级
//一般默认新建立的工程都会默认开2级优化，因此大家也可以设置为2级优化

//对于TC系列默认是不支持中断嵌套的，希望支持中断嵌套需要在中断内使用enableInterrupts();来开启中断嵌套
//简单点说实际上进入中断后TC系列的硬件自动调用了disableInterrupts();来拒绝响应任何的中断，因为需要我们自己手动调用enableInterrupts();来开启中断的响应。
  int core0_main(void)
{
    disableInterrupts();
    get_clk();//获取时钟频率  务必保留



    wildWolf_init();



    enableInterrupts();

    //用户在此处调用各种初始化函数等
    //注意 从V1.1.6版本之后  printf打印的信息从串口输出具体可以学习库例程6-Printf_Demo
    //注意 从V1.1.6版本之后  printf打印的信息从串口输出具体可以学习库例程6-Printf_Demo
    //注意 从V1.1.6版本之后  printf打印的信息从串口输出具体可以学习库例程6-Printf_Demo
    while (TRUE)
    {



        if(time[2])

            {





            if(key[0])           {  lcd_showstr(70,5,"K1");       PWMAAAA-=100;}
             if(key[1])      {  lcd_showstr(70,5,"K2"); PWMAAAA+=100; }
             if(key[2])      {   lcd_showstr(70,5,"K3");      if(Speed_Up_Flag) Speed_Up_Flag = 0; else  Speed_Up_Flag = 1;}
             if(key[3])      {   lcd_showstr(70,5,"K4");      SC_black_Init();  }
             if(key[4])      {  /*lcd_showstr(40,4,"K5"); */  if(Ring_Direction_Flag)    Ring_Direction_Flag = 0;   }
             if(key[5])      {  /*lcd_showstr(70,5,"K6");*/   if(Sensor_Value_Flag) {Sensor_Value_Flag = 0;  Sensor_Standard(); lcd_clear(WHITE);}}

             if(!key[4])     {   if(!Ring_Direction_Flag)     Ring_Direction_Flag = 1;   }
             if(!key[5])     {   if(!Sensor_Value_Flag)       {Sensor_Value_Flag = 1;    Sensor_Standard(); lcd_clear(WHITE);}      }

   //         if(Sensor_Value_Flag) Sensor_Value_Flag = 0; else Sensor_Value_Flag = 1;
            Date_Display();
            time[2]=0;
            }

                time[0]=0;




        if(lost_Flag&&protect_flag)
                {

                        Car_Sudu=0;
                        Car_Sudu1=0;
                        lcd_clear(WHITE);
                        lcd_showstr(0,0,"Lossing....");
                        systick_delay_ms(STM0, 500);
                        pit_disable_interrupt(CCU6_0, PIT_CH0);
                        pit_disable_interrupt(CCU6_0, PIT_CH1);
                        Motor_output(0);
                        BEEP_ON;    systick_delay_ms(STM0, 1000);    BEEP_OFF;  systick_delay_ms(STM0, 500);
                        BEEP_ON;    systick_delay_ms(STM0, 1000);    BEEP_OFF;  systick_delay_ms(STM0, 500);
                        while(1);

                }

    }

}

#pragma section all restore

