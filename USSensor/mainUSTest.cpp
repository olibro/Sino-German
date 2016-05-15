//Compile: g++ mainUSTest.cpp USSensor.cpp -o USSTest -lwiringPi

#include <wiringPi.h>
#include <iostream>
#include "USSensor.h"

using namespace std;

int main(void)
{
    setup();
    while(true)
    {
        cout <<  "Entfernung: " << getDistance() << " cm" << endl;
        // Warte 1 Sekunde (1000ms = 1 s)
        delay(1000);
    }
    return 0;
}
