#ifndef _PUBLIC_H_
#define _PUBLIC_H_
#include "zf_gpio.h"
#include "headfile.h"



#define BEEP_ON  gpio_init(P33_10, GPO, 1, PUSHPULL)
#define BEEP_OFF gpio_init(P33_10, GPO, 0, PUSHPULL)

#endif
