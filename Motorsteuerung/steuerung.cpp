/***************************************************
	In diesem Modul steuerung.cpp wird die Funktion
	steuerung(int pwrRM, int pwrLM, int time)festgelegt, 
	mit der die Motoren gesteurt werden. Außerdem
	gibt es noch eine Initialisierungsfunktion
	init_motorsteuerung() definiert, die die Pins für
	die Motoren konfiguriert.
***************************************************/

#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include "steuerung.h"

using namespace std;

// Benutze Pinkonfiguration von wiringPi, wiringPiSetup()
// VOR==Vorwaertsfahren, ZUR==Rueckwaertsfahren
// LM==Linker Motor, RM==Rechter Motor

///Initialisierung der GPIO Pins zur Motorsteuerung
/**
	/param LM_VOR	Linker Motor vorwärts
	/param LM_ZUR	Linker Motor rückwärts
	/param RM_VOR	Rechter Motor vorwärts
	/param RM_ZUR	Rechter Motor rückwärts
	
	Hier werden die benötigten GPIO Pins  als PWM Output initialisiert.
	Hierzu wird mithilfe der wiringPi Bibliothek per Software an jedem Pin
	ein PWM Sinal erzeugt. Die Spannweite des Signals reicht von 0 bis 100 
	und entspricht somit 0 bis 100% Leistung.
*/
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

///Steuerung der Motoren
/**
	/param pwrRM	Übergabe der Leistung des rechten Motors in Prozent
	/param pwrLM	Übergabe der Leistung des linken Motors in Prozent
	/param time		Zeit, wie lange die Motoren laufen sollen. time=0 -> Motoren laufen "unendlich" lange
	
	In dieser Funktion gibt es zwei Modi: 
		- Die Motoren laufen eine bestimmte Zeit
		- Die Motoren laufen endlos
	pwrRM und pwrLM müssen! Werte zwischen -100 und 100 in 1er Schritten annehmen
	Eine negative Zahl entspricht dann dem Rückwärtsfahren. Positiv dem Vorwärtsfahren.
	Jenachdem welche Größe pwrRM und pwrLM und time haben wird ein anderes Kommando ausgeführt.
	In jedem Fall wird an den GPIO Pins der Motoren ein PWM Signal erzeugt, das dann der Leistung entspricht.
*/
void steuerung(int pwrRM, int pwrLM, int time)
{
    if(time != 0)	//Fährt eine gewisse Zeit t vorwärts/rückwarts
    {
        // Rechter Motor vorwärts
        if(pwrRM > 0) 
        {
            softPwmWrite(RM_VOR, pwrRM);
        }
        else if(pwrRM == 0) //Stop
        {
            softPwmWrite(RM_VOR, 0);
            softPwmWrite(RM_ZUR, 0);
        }
        else	//RM rückwärts
        {
            softPwmWrite(RM_ZUR, -pwrRM);
        }

        // Linker Motor vorwärts
        if(pwrLM > 0)
        {
            softPwmWrite(LM_VOR, pwrLM);
        }
        else if(pwrLM == 0) //LM stop
        {
            softPwmWrite(LM_VOR, 0);
            softPwmWrite(LM_ZUR, 0);
        }
        else //LM rückwärts
        {
            softPwmWrite(LM_ZUR, -pwrLM);
        }
        //Nachdem die Motoren an waren sollen sie nach Ablauf der Zeit t wieder ausgehen.
        delay(time);
        softPwmWrite(RM_VOR, 0);
        softPwmWrite(RM_ZUR, 0);
        softPwmWrite(LM_VOR, 0);
        softPwmWrite(LM_ZUR, 0);
    }
    else  // (time == 0)
	//Motoren laufen solange wie kein anderes Kommando gesendet wird
    {
        if(pwrRM > 0)	//RM vorwärts
        {
            softPwmWrite(RM_VOR, pwrRM);
        }
        else if(pwrRM == 0)	//RM stop
        {
            softPwmWrite(RM_VOR, 0);
            softPwmWrite(RM_ZUR, 0);
        }
        else	//RM rückwarts
        {
            softPwmWrite(RM_ZUR, -pwrRM);
        }

        if(pwrLM > 0)	//LM vorwärts
        {
            softPwmWrite(LM_VOR, pwrLM);
        }
        else if(pwrLM == 0)	//LM stop
        {
            softPwmWrite(LM_VOR, 0);
            softPwmWrite(LM_ZUR, 0);
        }
        else	//LM rückwarts
        {
            softPwmWrite(LM_ZUR, -pwrLM);
        }
    }
}
