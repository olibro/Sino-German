// compile mit:  g++ -Wall -pedantic mainAll.cpp ./USSensor/USSensor.cpp ./Motorsteuerung/steuerung.cpp -o mainAll -lwiringPi -lpthread

/*
Zum Testen haben wir die Motoren auf die folgende wiringPi Pins angeschlossen

#define LM_VOR	4
#define	LM_ZUR	5
#define RM_VOR	6
#define RM_ZUR	1

und die Ultraschallsensor

#define TRIG 7
#define ECHO 0

*/

#include <wiringPi.h>
#include <iostream>
#include <softPwm.h>

//#include "./IRSensor/IRSensor.h"
#include "./USSensor/USSensor.h"
#include "./Motorsteuerung/steuerung.h"

using namespace std;

// Hier wird/sollte später das Gesamte Programm ausgeführt

int main(void)
{
    wiringPiSetup();
//   if(wiringPiSetup()==-1)
//   {
//        cout << "Initalisation failed.\n";
//   }

    init_motorsteuerung();
    init_USSensor();

    while(true)
    {
        // Motor fährt sollane in 20 cm abstand kein hindernis ist
        while(getDistance() >= 20)
        {
            lm_vor(100,0);
        }
        lm_vor(0,0);
    }


}
