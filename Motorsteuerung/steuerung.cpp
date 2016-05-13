//Compile: g++ -Wall -pedantic steuerung.cpp -o steuerung -lwiringPi -lpthread

#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>

using namespace std;

// Benutze Pinkonfiguration von CPU, wiringPiSetupGpio()
// VOR==Vorwaertsfahren, ZUR==Rueckwaertsfahren
// LM==Linker Motor, RM==Rechter Motor
#define LM_VOR	17	// wiringPin 0
#define	LM_ZUR	18	// wiringPin 1
#define RM_VOR	22	// wiringPin 3
#define RM_ZUR	23	// wiringPin 4

void init(void){
	if(wiringPiSetupGpio()==-1){
		cout << "Initalisation failed.\n";
	}
	pinMode(LM_VOR,OUTPUT);
	pinMode(LM_ZUR,OUTPUT);
	pinMode(RM_VOR,OUTPUT);
	pinMode(RM_ZUR,OUTPUT);
	
	//Wenn Initalisierung fehlgeschlagen ist, soll eine Fehlermeldung erfolgen.
	if(softPwmCreate(LM_VOR,0,100)!=0){ //initValue=0 (Motor aus), PWMrange 0..100 (in Prozent)
		cout << "Initalisation failed.\n";
	}
	if(softPwmCreate(LM_ZUR,0,100)!=0){
		cout << "Initalisation failed.\n";
	}
	if(softPwmCreate(RM_VOR,0,100)!=0){ //initValue=0 (Motor aus), PWMrange 0..100 (in Prozent)
		cout << "Initalisation failed.\n";
	}
	if(softPwmCreate(RM_ZUR,0,100)!=0){
		cout << "Initalisation failed.\n";
	}
}

void rm_vor(int pwr){
	
	
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
