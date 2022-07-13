#include "headfile.h"

//void wildWolf_init(void)//初始化
//{
//
//
//    Motor_init();//电机初始化
//}

uint32 PWMAAAA = 0;

void wildWolf_init(void)//初始化
{

     lcd_init();
     lcd_showstr(0,0,"Initializing....");
     gtm_pwm_init(ATOM0_CH2_P21_4, 50, DirectMiddle);//舵机初始化
     Boma_init();//拨码盘初始化
     lcd_showstr(0,1,"Boma    Initialized");
     AD_Init();//AD初始化
     lcd_showstr(0,2,"AD      Initialized");
     uart_init(UART_2,230400,UART2_TX_P10_5,UART2_RX_P10_6);
     gpt12_init(GPT12_T5, GPT12_T5INB_P10_3, GPT12_T5EUDB_P10_1);
     pit_interrupt_ms(CCU6_0, PIT_CH0, 100);
     pit_interrupt_ms(CCU6_0, PIT_CH1, 5);
     lcd_showstr(0,3,"Inter   Initialized");
     Motor_init();//电机初始化
     lcd_showstr(0,4,"Motor   Initialized");
     simiic_init();
     mpu6050_init();
     mpu6050_self1_check();
     lcd_showstr(0,5,"MPU6050 Initialized");
//速度环常量初始化
   Car_Sudu=0;//150
   Speed_P=20;//20
   Speed_I=1.8;//1.8
   Speed_D=0;
   lcd_showstr(0,7,"Successfuly");
   lcd_clear(WHITE);

}
