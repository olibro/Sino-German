//Compile: g++ -Wall -pedantic main.cpp steuerung.cpp -o steuerung -lwiringPi -lpthread

/*
	Zum Testen haben wir die Motoren an die folgende wiringPi Pins angeschlossen
	Motoren
	LM_VOR	21
	LM_ZUR	22
	RM_VOR	23
	RM_ZUR	24

	Ultraschallsensor
	TRIG 7
	ECHO 0
*/

#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>

//Pfad muss an lokale Verzeichnisstruktur angepasst werden.
#include "./USSensor/USSensor.h"
#include "./Motorsteuerung/steuerung.h"

using namespace std;

int main(void)
{
    if(wiringPiSetup()==-1)
    {
        cout << "Initalisation failed.\n";
    }
    init_motorsteuerung();

    cout << "RV und LZ\n";
//      steurung(int pwrRM, int pwrLM, int time);
    steurung(0, 0, 2000);
    cout << "RZ und LV\n";
//      steurung(int pwrRM, int pwrLM, int time);
    steurung(0, 0, 2000);

    init_USSensor();

    //steuerung(int pwrRM, int pwrLM, int time);
    while(1)
    {
        delay(100);		//Umschaltzeit. Zum Bremsen des Motors
        while(getDistance()>=20)
        {
            steuerung(50, 50, 0);
        }
        delay(100);
        while(getDistance()<20)
        {
            steuerung(-50,-50,0);
        }
        steuerung(0, 0, 0);
    }
    return 0;
}
