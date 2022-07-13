#include "Boma.h"
#include "PUBLIC.h"
#include "common.h"
#include "zf_gpio.h"

uint8  key_temp[6]={0};

uint8 key[6]={0};//¥¢¥Êº¸÷µ
int status1=0,status2=0, status3=0,status4=0,status5=0,status6=0;

//≤¶¬Î≈Ã≥ı ºªØ
void  Boma_init()
{

   gpio_init(P22_0, GPI, 0, PULLDOWN);
   gpio_init(P22_1, GPI, 0, PULLDOWN);
   gpio_init(P22_2, GPI, 0, PULLDOWN);
   gpio_init(P22_3, GPI, 0, PULLDOWN);
   gpio_init(P23_1, GPI, 0, PULLDOWN);
   gpio_init(P32_4, GPI, 0, PULLDOWN);

}
//≤¶¬Î≈Ã∂¡»°
void Boma_read()
{
    uint8 temp=0;
    status1 = gpio_get(P23_1);
    status2 = gpio_get(P32_4);
    status3 = gpio_get(P22_2);
    status4 = gpio_get(P22_3);
    status5 = gpio_get(P22_0);
    status6 = gpio_get(P22_1);


   if(status1 == 1)  key_temp[0]++;
       else key_temp[0]=0;
   if(status2 == 1)  key_temp[1]++;
          else key_temp[1]=0;
   if(status3 == 1)  key_temp[2]++;
          else key_temp[2]=0;
   if(status4 == 1)  key_temp[3]++;
          else key_temp[3]=0;
   if(status5 == 1)  key_temp[4]++;
          else key_temp[4]=0;
   if(status6 == 1)  key_temp[5]++;
          else key_temp[5]=0;




   for(temp=0;temp<6;temp++)
   {
       if(key_temp[temp]>=2)
           key[temp]=1;
       else
           key[temp]=0;
       if(key_temp[temp]>=200)
           key_temp[temp] = 100;
   }



}


