//Compile: g++ mainUSTest.cpp USSensor.cpp -o USSTest -lwiringPi

#include <wiringPi.h>
#include <iostream>

using namespace std;

#define TRIG 7
#define ECHO 0

//Pin zuweisung
void init_USSensor()
{
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);

    //TRIG pin must start LOW
    digitalWrite(TRIG, LOW);
    delay(30);
}
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
