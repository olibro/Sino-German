#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>

#include "./USSensor/USSensor.h"
#include "./Motorsteuerung/steuerung.h"

using namespace std;

int main(int argc, char* argv[])
{


    init_motorsteuerung();
    init_USSensor();

    if(wiringPiSetup()==-1)
    {
        cout << "Initalisation failed.\n";
    }


    //for(int i = 0; i <= 60; i++)
    //{
    //  steuerung(i, i, 0);
//
    //}
    steuerung(100,100,0);
    delay(10000);
    steuerung(0,0,0);
    delay(500);
    steuerung(100,100,0);
    delay(10000);
    steuerung(0,0,0);
    delay(2000);
    steuerung(100,100,0);
    delay(2000);
    steuerung(0,0,0);
    delay(2000);



}
