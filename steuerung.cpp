//Compile: g++ -Wall -pedantic steuerung.cpp -o steuerung -lwiringPi -lpthread

#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>

using namespace std;

#define VOR	17	//Benutze Pinkonfiguration von CPU, wiringPiSetupGpio()
#define	ZUR	18	//VOR==Vorwaertsfahren, ZUR==Rueckwaertsfahren

void init(void){
	if(wiringPiSetupGpio()==-1){
		cout << "Initalisation failed.\n";
	}
	pinMode(VOR,OUTPUT);
	pinMode(ZUR,OUTPUT);
	if(softPwmCreate(VOR,0,100)!=0){ //initValue=0 (Motor aus), PWMrange 0..100 (in Prozent)
		cout << "Initalisation failed.\n";
	}
	if(softPwmCreate(ZUR,0,100)!=0){
		cout << "Initalisation failed.\n";
	}
}
int main(void){
	int pwr_lm=0;	//Power linker Motor(0..100)
	int pwr_rm=0;	//Power rechter Motor(0..100)
	init();
	while(pwr_lm<100){
		softPwmWrite(VOR,pwr_lm);
		pwr_lm+=5;
		cout << "pwr " << pwr_lm << endl;
		delay(1000);
	}
	digitalWrite(VOR,0);
	digitalWrite(VOR,0);
	return 0;
}
