#include <stdio.h>
#include <wiringPi.h>

#define IRL 5 //SENSORLEFT PHYSICAL=18
#define IRR 4 //SENSORRIGHT PHYSICAL=16


/// Pin zuweisung IR Sensor
/**
	\param IRL linker Infrarotsensor
	\param IRR rechter Infrarotsensor
	rechter und linker Infrarotsensor am Pin x des Raspberry Pi werden ueber die Funktion pinMode () aus der Headerdatei wiringPi.h deklariert
	HIGH bzw. LOW sind ebenfalls in der Headerdatei wiringPi.h deklariert
*/

void init_irsens(void){
	pinMode(IRR,INPUT);
	pinMode(IRL,INPUT);
}
