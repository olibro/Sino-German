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
    int cSpeed, cDirection;
    int PRM, PLM, time;
    bool active = true;

    int pmin = PMIN;
    int mmin = MMIN;

    stringstream ss;

    // Parameter Einlesen - zu int Konvertieren - wert Variablen zuweisen
    ss << argv[1] << ' ' << argv[2] << ' ' << argv[3];
    ss >> cSpeed >> cDirection >> time;
    cout <<argv[0] << argv[1] << argv[2] << argv[3];
    if(wiringPiSetup()==-1)
    {
        cout << "Initalisation failed.\n";
    }

    init_motorsteuerung();
    init_USSensor();
    // init_irsens();

    cout << "Erhaltene Parameter =  " << cSpeed << ", " << cDirection << ", " << time << endl;
    cout << "Distance = " << getDistance() << endl;

    while(getDistance()>=8 && active)
    {

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
        delay(1000);
        active = false;
        steuerung(PRM, PLM, 1);

    }
    return 0;
}

/*
            if(cSpeed == 0){ PRM == 0};

            if(cSpeed == 1){ PRM = pmin +10; PLM = pmin +10}
            if(cSpeed == 2){ PRM = pmin +20; PLM = pmin +20};
            if(cSpeed == 3){ PRM = pmin +30; PLM = pmin +30};
            if(cSpeed == 4){ PRM = pmin +40; PLM = pmin +40};

            if(cSpeed == -1){ PRM = mmin -10; PLM = mmin +10};
            if(cSpeed == -2){ PRM = mmin -20; PLM = mmin +20};
            if(cSpeed == -3){ PRM = mmin -30; PLM = mmin +30};
            if(cSpeed == -4){ PRM = mmin -40; PLM = mmin +40};

            if(cDirection == 0){};
            if(cDirection == 1){ PRM = PRM ; PLM = PLM +10};
            if(cDirection == 2){ PRM = PRM ; PLM = PLM +10};
            if(cDirection == 3){ PRM = PRM ; PLM = PLM +10};
            if(cDirection == 4){ PRM = PRM ; PLM = PLM +10};

            if(cDirection == -1){ PRM = PRM ; PLM = PLM +10};
            if(cDirection == -2){ PRM = PRM ; PLM = PLM +10};
            if(cDirection == -3){ PRM = PRM ; PLM = PLM +10};
            if(cDirection == -4){ PRM = PRM ; PLM = PLM +10};



                if(cDirection == 0){
                    PRM = MIN + 10;
                    PLM = MIN + 10;
                }
                if(cDirection == 1){
                    PRM = MIN + 10;
                    PLM = MIN + 20;
                }
                if(cDirection == 2){
                    PRM = MIN + 10;
                    PLM = MIN + 20;
                }
                if(cDirection == 3){
                    PRM = MIN + 10;
                    PLM = MIN + 30;
                }
                if(cDirection == 4){
                    PRM = MIN + 10;
                    PLM = MIN + 40;
                }
*/
