/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ����Ⱥ��824575535
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		main
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		tasking v6.3r1
 * @Target core		TC264D
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-3-23
 ********************************************************************************************************************/
#include "math.h"
#include "ANO_DT.h"
#include "headfile.h"
#pragma section all "cpu1_dsram"


void core1_main(void)
{
	disableInterrupts();
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());

    //�û��ڴ˴����ø��ֳ�ʼ��������

    enableInterrupts();
    while (TRUE)
    {
		//�û��ڴ˴���д�������

//        ANO_DT_send_int16((float)SPEED,sensor1,sensor2,sensor3,sensor4,sensor5,sensor6,sensor7,sensor8,turn_out);


    }
}





#pragma section all restore
