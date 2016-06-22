#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include <sstream>


#include "./USSensor/USSensor.h"
#include "./Motorsteuerung/steuerung.h"

using namespace std;

// main mit Parameteraufruf, argc = Anzahl Parameter, argv[0] = Parameter an 1. stelle
int main(int argc, char* argv[])
{
    int PRM, PLM, time;
    stringstream ss;

    // Parameter Einlesen - zu int Konvertieren - wert Variablen zuweisen
    ss << argv[1] << ' ' << argv[2] << ' ' << argv[3];
    ss >> PRM >> PLM >> time;

    if(wiringPiSetup()==-1)
    {
        cout << "Initalisation failed.\n";
    }

    init_motorsteuerung();
    init_USSensor();
    // init_irsens();

    cout << "Starte Motor" << "Distance = " << getDistance() << endl;

    while(getDistance()>=8){
            steuerung(PRM, PLM, time);
    }

}
