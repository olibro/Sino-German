#include <wiringPi.h>
#include <iostream>
#include "IRSensor.h"
#include <steuerung.h>


int main(void)
{
    int SL; //Zustand des linken IRSensor
    int SR; //Zustand des rechten IRSensor
    wiringPiSetup();
    init_IRSensor();
    while(1)
    {
    SR = digitalRead(SensorRight);      // SR=1→der rechte Infrarotsensor befindet sich innerhalb weisser zone;SR=0→ schwarze Linie
    SL = digitalRead(SensorLeft);       // SL=1→der linke Infrarotsensor befindet sich innerhalb weisser zone;SL=0→ schwarze Linie
    //steurung(int pwrRM, int pwrLM, int time);
    //die scharzen Linie ist dünner als die Abstand von zwei Sensoren
    if (SL == LOW&&SR==LOW)          // die zwei Infrarotsensor befinden sich in weisser Zone → das ist gut
    steuerung(50,50,0);                         
    else if (SL == LOW & SR == HIGH)    // rechter IRSensor ist innerhalb der scharzen Linie, das Auto braucht links zu fahren
    steuerung(50,0,0);
    else if (SR == LOW & SL == HIGH)    // linker IRSensor ist innerhalb der scharzen Linie, das Auto braucht rechts zu fahren
    steuerung(0,50,0);
    else                                // zwei Sensoren sind in weisser Zone→stopp
    steuerung(0,0,0);
    }
    return 0;
       
}
