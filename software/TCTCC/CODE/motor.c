#include "zf_gtm_pwm.h"
#include "common.h"
#include "headfile.h"



void Motor_init(void)
{
    gtm_pwm_init(ATOM0_CH0_P21_2,30000,0);
    gtm_pwm_init(ATOM0_CH1_P21_3,30000,0);

}


void Motor_output(int16 duty)
{
  //���ȶ�duty������ֵ  ���ֵΪ10000
    duty =   duty>  10000   ?    10000  :   duty;
    duty =   duty< -10000   ?   -10000  :   duty;

  //Ȼ���������
 if(duty>=0)
  {
  pwm_duty(ATOM0_CH0_P21_2, 0);
  pwm_duty(ATOM0_CH1_P21_3, duty);
  }
  else
  {

  pwm_duty(ATOM0_CH0_P21_2, -duty);
  pwm_duty(ATOM0_CH1_P21_3, 0);
  }
}

