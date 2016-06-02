//===========================
// 智能小车黑线
//#include <Servo.h>
#include <wiringPi.h>
#include <iostream>
#include <IRSensor.h>

#define Left_motor_go 21
#define Left_motor_back 22
#define Right_motor_go 23
#define Right_motor_back 24
#define SensorRight 4 //rechte IRSensor Pin4(wiringPi)
#define SensorLeft 5 //linke IRSensor Pin5(wiringPi)

void init_IRSensor()
{
//Initialisierung von Pin
  pinMode(Left_motor_go,OUTPUT); // PIN 21 (PWM)
  pinMode(Left_motor_back,OUTPUT); // PIN 22 (PWM)
  pinMode(Right_motor_go,OUTPUT);// PIN 2 (PWM) 
  pinMode(Right_motor_back,OUTPUT);// PIN 3 (PWM)
  pinMode(SensorRight, INPUT); //definieren SensorRight als input
  pinMode(SensorLeft, INPUT); //definieren SensorLeft als input   
}


void run()
{
  digitalWrite(Right_motor_go,HIGH);  // rechter Motor vor
  digitalWrite(Right_motor_back,LOW);     
  analogWrite(Right_motor_go,150);//PWM:0~255 für Geschwindigkeiteinstellung
  analogWrite(Right_motor_back,0);
  digitalWrite(Left_motor_go,HIGH);  // rechter Motor vor
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,150);//PWM:0~255 für Geschwindigkeiteinstellung
  analogWrite(Left_motor_back,0);
}

void brake()//stopp
{
  digitalWrite(Right_motor_go,LOW);
  digitalWrite(Right_motor_back,LOW);
  digitalWrite(Left_motor_go,LOW);
  digitalWrite(Left_motor_back,LOW);
}

void left()//links fahren
{
  digitalWrite(Right_motor_go,HIGH);	// rechter Motor vor
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,150); // PWM für die Geschwindigkeiteinstellung
  analogWrite(Right_motor_back,0);
  digitalWrite(Left_motor_go,LOW);   // linker Motor anhalten
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,0); 
  analogWrite(Left_motor_back,0);
}


void right()//rechts fahren
{
  digitalWrite(Right_motor_go,LOW);   //rechter Motor anhalt
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,0); 
  analogWrite(Right_motor_back,0);
  digitalWrite(Left_motor_go,HIGH);//linker Motor vor
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,150);//PMW für Geschwindigkeiteinstellung 
  analogWrite(Left_motor_back,0);
}


void back(int time)
{
  digitalWrite(Right_motor_go,LOW);  //rechter Motor zurück
  digitalWrite(Right_motor_back,HIGH);
  analogWrite(Right_motor_go,0);
  analogWrite(Right_motor_back,150);//PWM für Geschwindigkeiteinstellung
  digitalWrite(Left_motor_go,LOW);  //linker Motor zurück
  digitalWrite(Left_motor_back,HIGH);
  analogWrite(Left_motor_go,0);
  analogWrite(Left_motor_back,150);//PWM für Geschwindigkeiteinstellung
}


 


   




