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
    SR = digitalRead(SensorRight);      // SR=1→der rechte Infrarotsensor befindet sich innerhalb schwarzer zone;SR=0→ weisse Zone
    SL = digitalRead(SensorLeft);       // SL=1→der linke Infrarotsensor befindet sich innerhalb schwarzer zone;SL=0→ weisseZone
    //steurung(int pwrRM, int pwrLM, int time);
    /*die schwarzen Linie ist dünner als die Abstand von zwei Sensoren
    */
    if (SL == LOW&&SR==LOW)          // die zwei Infrarotsensor befinden sich in weisser Zone → das ist gut
    run();                         
    else if (SL == LOW & SR == HIGH)    // rechter IRSensor ist innerhalb der schwarzen Linie und der linke Sensor ist in weisser Zone, das Auto braucht rechts zu fahren
    right();
    else if (SR == LOW & SL == HIGH)    // linker IRSensor ist innerhalb der scharzen Linie und der rechter Sensor ist in schwarzer Zone, das Auto braucht links zu fahren
    left();
    else                                // zwei Sensoren sind in weisser Zone → stopp
    brake();
    }
    return 0;
       
}
