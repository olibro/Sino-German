//Compile: g++ -Wall -pedantic main.cpp steuerung.cpp -o steuerung -lwiringPi -lpthread

#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include "steuerung.h"

using namespace std;

// Benutze Pinkonfiguration von CPU, wiringPiSetupGpio()
// VOR==Vorwaertsfahren, ZUR==Rueckwaertsfahren
// LM==Linker Motor, RM==Rechter Motor
#define LM_VOR	21	// wiringPin 0
#define	LM_ZUR	22	
#define RM_VOR	23	
#define RM_ZUR	24	

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

//Funktion um rechten Motor nach vorne zu bewegen. Es wird die Leistung/Geschwindigkeit
//in Prozent(0..100%) mitgegeben

//Manueller Modus: Zeitdauer(in Millisekunden,1s=1000ms) wie lange der Motor an sein soll wird angegeben.
//Automatischer Modus: Zeitvariable muss 0 sein.

void rm_vor(int pwr, int time)
{
    if(time!=0) 	//zur Manuellen Steuerung
    {
        delay(50);					//Kurze Umschaltzeit
        softPwmWrite(RM_VOR,pwr);	//Erstellt eine PWM(Pulsweitenmodulation) fuer PIN=RM_VOR und Wert=pwr
        delay(time);				//Motor bleibt time ms an
        delay(50);					//Kurze Umschaltzeit
        softPwmWrite(RM_VOR,0);		//Motor ist wieder aus.
        digitalWrite(RM_VOR,0);
    }
    else 		//automatische Steuerung durch Sensorwerte
    {
        delay(50);					//Kurze Umschaltzeit
        softPwmWrite(RM_VOR,pwr);	//Erstellt eine PWM(Pulsweitenmodulation) fuer PIN=RM_VOR und Wert=pwr
        if(pwr==0)
        {
            delay(50);					//Kurze Umschaltzeit
            digitalWrite(RM_VOR,0);		//Bei mir hat der Motor ohne diese Zeile nicht aufgehört zu drehen???
        }
    }
}

void rm_zur(int pwr, int time)
{
    if(time!=0) 	//zur Manuellen Steuerung
    {
        delay(50);					//Kurze Umschaltzeit
        softPwmWrite(RM_ZUR,pwr);	//Erstellt eine PWM(Pulsweitenmodulation) fuer PIN=RM_ZUR und Wert=pwr
        delay(time);				//Motor bleibt time ms an
        delay(50);					//Kurze Umschaltzeit
        softPwmWrite(RM_ZUR,0);		//Motor ist wieder aus.
        digitalWrite(RM_ZUR,0);
    }
    else 		//automatische Steuerung durch Sensorwerte
    {
        delay(50);					//Kurze Umschaltzeit
        softPwmWrite(RM_ZUR,pwr);	//Erstellt eine PWM(Pulsweitenmodulation) fuer PIN=RM_ZUR und Wert=pwr
        if(pwr==0)
        {
            delay(50);					//Kurze Umschaltzeit
            digitalWrite(RM_ZUR,0);		//Bei mir hat der Motor ohne diese Zeile nicht aufgehört zu drehen???
        }
    }
}

void lm_vor(int pwr, int time)
{
    if(time!=0) 	//zur Manuellen Steuerung
    {
        delay(50);					//Kurze Umschaltzeit
        softPwmWrite(LM_VOR,pwr);	//Erstellt eine PWM(Pulsweitenmodulation) fuer PIN=LM_VOR und Wert=pwr
        delay(time);				//Motor bleibt time ms an
        delay(50);					//Kurze Umschaltzeit
        softPwmWrite(LM_VOR,0);		//Motor ist wieder aus.
        digitalWrite(LM_VOR,0);
    }
    else 		//automatische Steuerung durch Sensorwerte
    {
        delay(50);					//Kurze Umschaltzeit
        softPwmWrite(LM_VOR,pwr);	//Erstellt eine PWM(Pulsweitenmodulation) fuer PIN=LM_VOR und Wert=pwr
        if(pwr==0)
        {
            delay(50);					//Kurze Umschaltzeit
            digitalWrite(LM_VOR,0);		//Bei mir hat der Motor ohne diese Zeile nicht aufgehört zu drehen???
        }
    }
}

void lm_zur(int pwr, int time)
{
    if(time!=0) 	//zur Manuellen Steuerung
    {
        delay(50);					//Kurze Umschaltzeit
        softPwmWrite(LM_ZUR,pwr);	//Erstellt eine PWM(Pulsweitenmodulation) fuer PIN=LM_ZUR und Wert=pwr
        delay(time);				//Motor bleibt time ms an
        delay(50);					//Kurze Umschaltzeit
        softPwmWrite(LM_ZUR,0);		//Motor ist wieder aus.
        digitalWrite(LM_ZUR,0);
    }
    else 		//automatische Steuerung durch Sensorwerte
    {
        delay(50);					//Kurze Umschaltzeit
        softPwmWrite(LM_ZUR,pwr);	//Erstellt eine PWM(Pulsweitenmodulation) fuer PIN=LM_ZUR und Wert=pwr
        if(pwr==0)
        {
            delay(50);					//Kurze Umschaltzeit
            digitalWrite(LM_ZUR,0);		//Bei mir hat der Motor ohne diese Zeile nicht aufgehört zu drehen???
        }
    }
}
