
//#include <Servo.h>
#include <wiringPi.h>
#include <iostream>
#include <IRSensor.h>

#define SensorRight 4 //右循迹红外传感器(P3.2 OUT1)
#define SensorLeft 5 //左循迹红外传感器(P3.3 OUT2)

void init_IRSensor()
{
//Initialisierung von Pin
    pinMode(SensorRight, INPUT); //definieren den rechte Sensor als Input
    pinMode(SensorLeft, INPUT); //definieren den linke Sensor als Output
}




