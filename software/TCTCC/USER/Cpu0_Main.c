/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ����Ⱥ��824575535
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file            main
 * @company         �ɶ���ɿƼ����޹�˾
 * @author          ��ɿƼ�(QQ3184284598)
 * @version         �鿴doc��version�ļ� �汾˵��
 * @Software        tasking v6.3r1
 * @Target core     TC264D
 * @Taobao          https://seekfree.taobao.com/
 * @date            2020-3-23
 ********************************************************************************************************************/
#include "math.h"
#include "ANO_DT.h"
#include "headfile.h"
#pragma section all "cpu0_dsram"
uint8 protect_flag=0;    //ͣ����������


//���������#pragma section all restore���֮���ȫ�ֱ���������CPU0��RAM��
//���̵��뵽���֮��Ӧ��ѡ�й���Ȼ����refreshˢ��һ��֮���ٱ���
//����Ĭ������Ϊ�ر��Ż��������Լ��һ�����ѡ��properties->C/C++ Build->Setting
//Ȼ�����Ҳ�Ĵ������ҵ�C/C++ Compiler->Optimization->Optimization level�������Ż��ȼ�
//һ��Ĭ���½����Ĺ��̶���Ĭ�Ͽ�2���Ż�����˴��Ҳ��������Ϊ2���Ż�

//����TCϵ��Ĭ���ǲ�֧���ж�Ƕ�׵ģ�ϣ��֧���ж�Ƕ����Ҫ���ж���ʹ��enableInterrupts();�������ж�Ƕ��
//�򵥵�˵ʵ���Ͻ����жϺ�TCϵ�е�Ӳ���Զ�������disableInterrupts();���ܾ���Ӧ�κε��жϣ���Ϊ��Ҫ�����Լ��ֶ�����enableInterrupts();�������жϵ���Ӧ��
  int core0_main(void)
{
    disableInterrupts();
    get_clk();//��ȡʱ��Ƶ��  ��ر���



    wildWolf_init();



    enableInterrupts();

    //�û��ڴ˴����ø��ֳ�ʼ��������
    //ע�� ��V1.1.6�汾֮��  printf��ӡ����Ϣ�Ӵ�������������ѧϰ������6-Printf_Demo
    //ע�� ��V1.1.6�汾֮��  printf��ӡ����Ϣ�Ӵ�������������ѧϰ������6-Printf_Demo
    //ע�� ��V1.1.6�汾֮��  printf��ӡ����Ϣ�Ӵ�������������ѧϰ������6-Printf_Demo
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

