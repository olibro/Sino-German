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
    }
    return 0;
}
