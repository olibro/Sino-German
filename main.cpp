// compile mit:  g++ -Wall -pedantic mainAll.cpp ./USSensor/USSensor.cpp ./Motorsteuerung/steuerung.cpp -o mainAll -lwiringPi -lpthread

/*
Zum Testen haben wir die Motoren auf die folgende wiringPi Pins angeschlossen

#define LM_VOR	21
#define	LM_ZUR	22
#define RM_VOR	23
#define RM_ZUR	24

und die Ultraschallsensor

#define TRIG 7
#define ECHO 0


#define IRL 5 //SENSORLEFT PHYSICAL=18
#define IRR 4 //SENSORRIGHT PHYSICAL=16

*/

#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>

//Pfad muss an lokale Verzeichnisstruktur angepasst werden.
#include "./USSensor/USSensor.h"
#include "./Motorsteuerung/steuerung.h"
#include "./IRSensor/ir.h"

#define PWR 60
#define OFFSET 40
using namespace std;

int main(void){
    if(wiringPiSetup()==-1)
    {
        cout << "Initalisation failed.\n";
    }
	init_motorsteuerung();
	init_USSensor();
	init_irsens();
	
	char letzte_Richtung='v'; //vorärts=v, rueckwärts=b, links=l, rechts=r
	int i=OFFSET;	//Laufvariable zum lenken
	int k=OFFSET;
	//steuerung(int pwrRM, int pwrLM, int time);
    while(getDistance()>=8){
		int i=OFFSET;
		int k=OFFSET;
		if(digitalRead(IRL)==1 && digitalRead(IRR)==1){
			steuerung(PWR,PWR,0);
			letzte_Richtung='v';
			//delay(30);
		}
		//steuerung(0,0,0);
		while(digitalRead(IRL)==0 && digitalRead(IRR)==1 && i<=100){	//dynamisch lenken
			steuerung(i,0,0);
			i++;
			delay(10);
		}
		/* if(digitalRead(IRL)==0 && digitalRead(IRR)==1){
			steuerung(PWR,0,0);
			letzte_Richtung='l';
			//delay(15);
		} */
		//steuerung(0,0,0);
		/* if(digitalRead(IRL)==1 && digitalRead(IRR)==0){
			steuerung(0,PWR,0);
			letzte_Richtung='r';
			//delay(15);
		} */
		while(digitalRead(IRL)==1 && digitalRead(IRR)==0 && k<=100){	//dynamisch lenken
			steuerung(0,k,0);
			k++;
			delay(10);
		}
		/* if(digitalRead(IRL)==0 && digitalRead(IRR)==0){
			switch(letzte_Richtung){	//drehen solange bis schwarze Linie
				case 'l':
					steuerung(0,PWR-OFFSET,0);
					break;
				case 'r':
					steuerung(PWR-OFFSET,0,0);
					break;
				case 'v':
					//steuerung(0,0,0);
					//steuerung(-100,-100,0); //
					break;
					
			}
			//steuerung(0,0,0);
			//delay(15);
		} */
		
	}
	steuerung(0,0,100);
	return 0;
}
