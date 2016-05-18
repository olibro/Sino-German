//Compile: g++ -Wall -pedantic main.cpp steuerung.cpp -o steuerung -lwiringPi -lpthread

#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include "steuerung.h"

using namespace std;

int main(void){
    if(wiringPiSetup()==-1)
    {
        cout << "Initalisation failed.\n";
    }
	init_motorsteuerung();
	cout << "Vor\n";
	rm_vor(100,500);
    lm_vor(100,0);
    delay(5000);
    lm_vor(0,0);
	cout << "Zur";
	rm_zur(30,500);
    lm_zur(30,5000);
	return 0;
}
