#include <stdio.h>
#include <wiringPi.h>

#define IRL 5 //SENSORLEFT PHYSICAL=18
#define IRR 4 //SENSORRIGHT PHYSICAL=16

void init_irsens(void){
	pinMode(IRR,INPUT);
	pinMode(IRL,INPUT);
}
