#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include "steuerung.h"

using namespace std;

int main(void){
	init_motorsteuerung();
	cout << "Vor\n";
	rm_vor(100,5000);
	cout << "Zur";
	rm_zur(30,5000);
	return 0;
}