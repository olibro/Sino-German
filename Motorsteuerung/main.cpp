//Compile: g++ -Wall -pedantic main.cpp steuerung.cpp -o steuerung -lwiringPi -lpthread

#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>

#include "steuerung.h"
#include "USSensor.h"

using namespace std;

int main(void){
	init_motorsteuerung(); //Init
	setup(); //INit USS
	while(getDistance()<=10cm){
		rm_vor(100,0);
		lm_vor(100,0);
		//Abhängigkeit zu IRSensor1 und 2 fehlen noch
		//Aber da könnte man einfach zwei weitere Bedingungen hinzufügen.
		//Wenn IRSensor1(linkerSensor)==1(keine Linie) dann soll rechter Motor solange langsamer werden bis linker sensor wieder einen Wert 1 hat usw..
	}
	return 0;
}
