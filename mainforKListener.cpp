#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include <sstream>

#include "./USSensor/USSensor.h"
#include "./Motorsteuerung/steuerung.h"

#define PMIN 50;
#define MMIN -50;


using namespace std;

// main mit Parameteraufruf, argc = Anzahl Parameter, argv[0] = Parameter an 1. stelle
int main(int argc, char* argv[])
{
    int cSpeed, cDirection;
    int PRM, PLM, time;
    bool active = true;

    stringstream ss;

    // Parameter Einlesen - zu int Konvertieren - wert Variablen zuweisen
    ss << argv[1] << ' ' << argv[2] << ' ' << argv[3];
    ss >> cSpeed >> cDirection >> time;

    if(wiringPiSetup()==-1)
    {
        cout << "Initalisation failed.\n";
    }

    init_motorsteuerung();
    init_USSensor();
    // init_irsens();

    cout << "Starte Motor" << endl << "Distance = " << getDistance() << endl;

    while(getDistance()>=8 && active){

    // Vorwärts
    if(cSpeed > 0)
    {
        //Rechts
        if(cDirection > 0){
            PRM = PMIN + ((cSpeed*10)/cDirection);
            PLM = PMIN + (cSpeed*10);
        }
        //Links
        else if(cDirection < 0){
            PRM = PMIN + (cSpeed*10);
            PLM = PMIN + ((cSpeed*10)/cDirection);
        }
        //gerade
        else{
            PRM = PMIN + (cSpeed*10);
            PLM = PMIN + (cSpeed*10);
        }
    }
    // Rückwärt
    else if(cSpeed <0)
    {
        //Rechts
        if(cDirection > 0){
            PRM = MMIN + ((cSpeed*10)/cDirection);
            PLM = MMIN + (cSpeed*10);
        }
        //Links
        else if(cDirection < 0){
            PRM = MMIN + (cSpeed*10);
            PLM = MMIN + ((cSpeed*10)/cDirection);
        }
        //gerade
        else{
            PRM = MMIN + (cSpeed*10);
            PLM = MMIN + (cSpeed*10);
        }
    }
    else // cspeed == 0
    {
        //Rechts
        if(cDirection > 0){
            PRM = 0;
            PLM = MMIN + (cDirection*10);
        }
        //Links
        else if(cDirection < 0){
            PRM = MMIN + (cDirection*10);
            PRM = MMIN + (cDirection*10);
            PLM = 0;
        }
        //gerade
        else{
            PRM = 0;
            PLM = 0;
        }
    }
            cout << "Motoren starten mit " << *PRM << ", " << *PLM << ", " << *time << endl;
            steuerung(PRM, PLM, time);
            delay(5000);
            active = false;
            steuerung(PRM, PLM, 1);
    }

}

/*
            if(cSpeed == 0){ PRM == 0};

            if(cSpeed == 1){ PRM = PMIN +10; PLM = PMIN +10}
            if(cSpeed == 2){ PRM = PMIN +20; PLM = PMIN +20};
            if(cSpeed == 3){ PRM = PMIN +30; PLM = PMIN +30};
            if(cSpeed == 4){ PRM = PMIN +40; PLM = PMIN +40};

            if(cSpeed == -1){ PRM = MMIN -10; PLM = MMIN +10};
            if(cSpeed == -2){ PRM = MMIN -20; PLM = MMIN +20};
            if(cSpeed == -3){ PRM = MMIN -30; PLM = MMIN +30};
            if(cSpeed == -4){ PRM = MMIN -40; PLM = MMIN +40};

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
