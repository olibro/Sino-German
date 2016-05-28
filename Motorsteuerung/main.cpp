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
	cout << "RV und LZ\n";
	//steurung(int pwrRM, int pwrLM, int time);
    steurung(0, 0, 2000);
    cout << "RZ und LV\n";
	//steurung(int pwrRM, int pwrLM, int time);
    steurung(0, 0, 2000);
	return 0;
}
