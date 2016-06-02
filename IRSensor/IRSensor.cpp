//===========================
// 智能小车黑线
//#include <Servo.h>
#include <wiringPi.h>
#include <iostream>
#include <IRSensor.h>

#define rs 4 //rechte IRSensor Pin4(wiringPi)
#define ls 5 //linke IRSensor Pin5(wiringPi)

void init_IRSensor()
{
//Initialisierung von Pin
    pinMode(rs, INPUT); //定义右循迹红外传感器为输入
    pinMode(ls, INPUT); //定义左循迹红外传感器为输入
}

 


   




