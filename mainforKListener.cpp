#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include <sstream>

#include "./USSensor/USSensor.h"
#include "./Motorsteuerung/steuerung.h"

#define PMIN 60;
#define MMIN -60;


using namespace std;

// main mit Parameteraufruf, argc = Anzahl Parameter, argv[0] = Parameter an 1. stelle
int main(int argc, char* argv[])
{
    // Initialisierung der GPIO
    init_motorsteuerung();
    init_USSensor();
    // init_irsens();

    int cSpeed, cDirection;
    int PRM, PLM, time;
    bool active = true;

    int pmin = PMIN;
    int mmin = MMIN;

    stringstream ss;

    // Parameter Einlesen - zu int Konvertieren - wert Variablen zuweisen
    ss << argv[1] << ' ' << argv[2] << ' ' << argv[3];
    ss >> cSpeed >> cDirection >> time;
    //cout <<argv[0] << argv[1] << argv[2] << argv[3];

    if(wiringPiSetup()==-1)
    {
        cout << "Initalisation failed.\n";
    }

    cout << "Erhaltene Parameter =  " << cSpeed << ", " << cDirection << ", " << time << endl;
    cout << "Distance = " << getDistance() << endl;


    //Fahre sollange bis kein Hinderniss erkannt wird und
    // active true ist
    while(getDistance()>=8 && active)
    {
        cin >> cSpeed >> cDirection;
        cout << cSpeed << " <- -> " << cDirection;
        // Vorwärts
        if(cSpeed > 0)
        {
            //Rechts
            if(cDirection > 0)
            {
                PRM = pmin + ((cSpeed*10)/cDirection);
                PLM = pmin + (cSpeed*10);
            }
            //Links
            else if(cDirection < 0)
            {
                PRM = pmin + (cSpeed*10);
                PLM = pmin + ((cSpeed*10)/cDirection);
            }
            //gerade
            else
            {
                PRM = pmin + (cSpeed*10);
                PLM = pmin + (cSpeed*10);
            }
        }
        // Rückwärt
        else if(cSpeed <0)
        {
            //Rechts
            if(cDirection > 0)
            {
                PRM = mmin + ((cSpeed*10)/cDirection);
                PLM = mmin + (cSpeed*10);
            }
            //Links
            else if(cDirection < 0)
            {
                PRM = mmin + (cSpeed*10);
                PLM = mmin + ((cSpeed*10)/cDirection);
            }
            //gerade
            else
            {
                PRM = mmin + (cSpeed*10);
                PLM = mmin + (cSpeed*10);
            }
        }
        else // cspeed == 0
        {
            //Rechts
            if(cDirection > 0)
            {
                PRM = 0;
                PLM = mmin + (cDirection*10);
            }
            //Links
            else if(cDirection < 0)
            {
                PRM = mmin + (cDirection*10);
                PRM = mmin + (cDirection*10);
                PLM = 0;
            }
            //gerade
            else
            {
                PRM = 0;
                PLM = 0;
            }
        }
        cout << "Motoren starten mit " << PRM << ", " << PLM << ", " << time << endl;

        steuerung(PRM, PLM, time);
        // Fahre 0,5 sekunden
        delay(500);
        active = false;
        // Halte langsam an
        steuerung(0, 0, 0);
    }
    return 0;
}
