//Compile: g++ -Wall -pedantic main.cpp steuerung.cpp -o steuerung -lwiringPi -lpthread

#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include "steuerung.h"

using namespace std;

// Benutze Pinkonfiguration von wiringPi, wiringPiSetup()
// VOR==Vorwaertsfahren, ZUR==Rueckwaertsfahren
// LM==Linker Motor, RM==Rechter Motor

// 			wiringPiPin		Physicalpin
#define LM_VOR	21	// 			29
#define	LM_ZUR	22	//			31
#define RM_VOR	23	//			33
#define RM_ZUR	24	//			35


void init_motorsteuerung(void)
{
    pinMode(LM_VOR,OUTPUT);
    pinMode(LM_ZUR,OUTPUT);
    pinMode(RM_VOR,OUTPUT);
    pinMode(RM_ZUR,OUTPUT);

    //Wenn Initalisierung fehlgeschlagen ist, soll eine Fehlermeldung erfolgen.
    if(softPwmCreate(LM_VOR,0,100)!=0)  //initValue=0 (Motor aus), PWMrange 0..100 (in Prozent)
    {
        cout << "Initalisation failed.\n";
    }
    if(softPwmCreate(LM_ZUR,0,100)!=0)
    {
        cout << "Initalisation failed.\n";
    }
    if(softPwmCreate(RM_VOR,0,100)!=0)  //initValue=0 (Motor aus), PWMrange 0..100 (in Prozent)
    {
        cout << "Initalisation failed.\n";
    }
    if(softPwmCreate(RM_ZUR,0,100)!=0)
    {
        cout << "Initalisation failed.\n";
    }
}

//Es wird die Leistung/Geschwindigkeit in Prozent(0..100%) mitgegeben


//Manueller Modus: Zeitdauer(in Millisekunden,1s=1000ms) wie lange der Motor an sein soll wird angegeben.
//Automatischer Modus: Zeitvariable muss 0 sein.


//int pwrRM: 	größer als Null -> fährt vorwärts
//				kleiner als Null -> fährt rückwärts
//int pwrLM: 	größer als Null -> fährt vorwärts
//				kleiner als Null -> fährt rückwärts
//int time: 	wenn Zeit ungleich Null, dann fahren beide Motoren so lange Zeitangabe war.
//				ist Zeit gleich Null fahren die Motoren solange bis ein anderes Kommando kommt.


void steuerung(int pwrRM, int pwrLM, int time)
{
    if(time != 0)
    {
        delay(100);
        // Rechter Motor
        if(pwrRM > 0)
        {
            //cout << "RM VOR\n";
            softPwmWrite(RM_VOR, pwrRM);
            delay(100);
            digitalWrite(RM_VOR, pwrRM);

            //delay(time);	FEHLER DA HIER PROGRAMM ANGEHALTEN WIRD FUER DELAY(TIME)
            //softPwmWrite(RM_VOR, 0);
            //digitalWrite(RM_VOR,0);
        }
        else if(pwrRM == 0)
        {
            //cout << "RM STOP\n";
            softPwmWrite(RM_VOR, 0);
            softPwmWrite(RM_ZUR, 0);
            digitalWrite(RM_VOR,0);
            digitalWrite(RM_ZUR,0);
        }
        else
        {
            //cout << "RM ZUR\n";
			//softPwmWrite(RM_ZUR, 0);
            softPwmWrite(RM_ZUR, -pwrRM);
            //delay(time);
            //softPwmWrite(RM_ZUR, 0);
            //digitalWrite(RM_ZUR,0);
        }

        // Linker Motor
        if(pwrLM > 0)
        {
            //cout << "LM VOR\n";
            softPwmWrite(LM_VOR, pwrLM);
            //delay(time);
            //softPwmWrite(LM_VOR, 0);
            //digitalWrite(LM_VOR,0);
        }
        else if(pwrLM == 0)
        {
            //cout << "LM STOP\n";
            softPwmWrite(LM_VOR, 0);
            digitalWrite(LM_VOR,0);
            softPwmWrite(LM_ZUR, 0);
            digitalWrite(LM_ZUR,0);
        }
        else
        {
            //cout << "LM ZUR\n";
			//softPwmWrite(LM_ZUR, 0);
            softPwmWrite(LM_ZUR, -pwrLM);
            //delay(time);
            //softPwmWrite(LM_ZUR, 0);
            //digitalWrite(LM_ZUR,0);
        }
        //Nachdem der Motor an war soll er nach ablauf der Zeit wieder ausgehen.
        delay(time);
        softPwmWrite(RM_VOR, 0);
        digitalWrite(RM_VOR,0);
        softPwmWrite(RM_ZUR, 0);
        digitalWrite(RM_ZUR,0);
        softPwmWrite(LM_VOR, 0);
        digitalWrite(LM_VOR,0);
        softPwmWrite(LM_ZUR, 0);
        digitalWrite(LM_ZUR,0);


    }
    else  // (time == 0)
    {
        delay(100);

        if(pwrRM > 0)
        {
            //cout << "RM VOR\n";
            softPwmWrite(RM_VOR, pwrRM);
        }
        else if(pwrRM == 0)
        {
            //cout << "RM STOP\n";
            softPwmWrite(RM_VOR, 0);
            digitalWrite(RM_VOR,0);
            softPwmWrite(RM_ZUR, 0);
            digitalWrite(RM_ZUR,0);
        }
        else
        {
            //cout << "RM ZUR\n";
			//softPwmWrite(RM_ZUR, 0);
            softPwmWrite(RM_ZUR, -pwrRM);
        }

        if(pwrLM > 0)
        {
            //cout << "LM VOR\n";
            softPwmWrite(LM_VOR, pwrLM);
        }
        else if(pwrLM == 0)
        {
            //cout << "LM STOP\n";
            softPwmWrite(LM_VOR, 0);
            digitalWrite(LM_VOR,0);
            softPwmWrite(LM_ZUR, 0);
            digitalWrite(LM_ZUR,0);
        }
        else
        {
            //cout << "LM ZUR\n";
			//softPwmWrite(LM_ZUR, 0);
            softPwmWrite(LM_ZUR, -pwrLM);
        }
    }
}
