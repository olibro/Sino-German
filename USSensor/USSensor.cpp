//Compile: g++ mainUSTest.cpp USSensor.cpp -o USSTest -lwiringPi

#include <wiringPi.h>
#include <iostream>

using namespace std;

#define TRIG 7
#define ECHO 0

/// Pin zuweisung US Sensor
/**
	\param TRIG Pin als Ausgang
	\param ECHO Pin als Eingang
	Echo und Trigger Pin am Raspberry Pi werden ueber die Funktion pinMode () aus der Headerdatei wiringPi.h deklariert
	HIGH bzw. LOW sind ebenfalls in der Headerdatei wiringPi.h deklariert
	LOW entspricht 0
	HIGH entspricht 1
*/

void init_USSensor()
{
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);

    //TRIG pin must start LOW
    digitalWrite(TRIG, LOW);
    delay(30);
}


/// Berechnen der Distanz zum nächsten Objekt
/**
	digitalWrite und delayMicroseconds sind in der Headerdatei wiringPi.h deklariert
	Vorgang zum ermitteln der Distanz:
	1. TRIG wird für 20ms eingeschaltet und danach wieder ausgeschaltet, dies dient zum aussenden der Schallwellen
	2. warte darauf, das ECHO LOW ist
	3. starte einen Timer der Microsekunden zaehlt
	4. solange bis ECHO HIGH ist.
	5. Auswerten des Timers 
	\param distance wird die Distanz in Zentimetern (cm) zugewiesen
	Der Rückgabewert der Funktion ist die Entfernung zum nächsten Objekt in cm.
*/

int getDistance()
{
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(20);
    digitalWrite(TRIG, LOW);

    //Wait for echo start
    while(digitalRead(ECHO) == LOW);

    //Wait for echo end
    long startTime = micros();
    while(digitalRead(ECHO) == HIGH);
    long travelTime = micros() - startTime;

    //Get distance in cm
    int distance = travelTime / 58;

    return distance;
}
