#ifndef _SENSOR_H
#define _SENSOR_H

//#include "headfile.h"


#define SECTOR_AD 11//选择扇区
#define SENSOR_NUMBER 13//AD数量

extern void AD_Init(void);
extern void AD_Collect(void);
extern void turn_out_cal(void);
extern void AD_Date_analyse();
extern void the_max_init(void);            //强行赋最大值
extern void special_ident(void);
extern void SC_black_Init(void);
extern void Sensor_Standard(void);

extern float sensor1,sensor2,sensor3,sensor4,sensor5,sensor6,sensor7,sensor8,sensor9,sensor10,sensor11,sensor12,sensor13;
extern float turn_error1,turn_error2,turn_error3,turn_error4,turn_error5,turn_error;
extern float ad_value[SENSOR_NUMBER][8],ad_sum[SENSOR_NUMBER];
extern float AD[SENSOR_NUMBER];
#endif
