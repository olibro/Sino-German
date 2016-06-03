// Header-Datei zur Motorsteuerung
// Hier werden alle nutzbaren Funktionen aus steuerung.cpp deklariert.r

//Prueft ob Konstante STEUERUNG_H schonmal erstellt wurde.
//Wenn ja, dann wurde headerdatei schon hinzugefuegt und wird
//nicht noch ein zweites mal hinzugefuegt.

	//Hier fehlen noch die Prototypen fuer die anderen Motoren

	//Es wird die Leistung/Geschwindigkeit in Prozent(0..100%) mitgegeben

	//Manueller Modus: Zeitdauer(in Millisekunden,1s=1000ms) wie lange der Motor an sein soll wird angegeben.
	//Automatischer Modus: Zeitvariable muss 0 sein.

	//int pwrRM: 	größer als Null -> fährt vorwärts
	//				kleiner als Null -> fährt rückwärts
	//int pwrLM: 	größer als Null -> fährt vorwärts
	//				kleiner als Null -> fährt rückwärts
	//int time: 	wenn Zeit ungleich Null, dann fahren beide Motoren so lange Zeitangabe war.
	//				ist Zeit gleich Null fahren die Motoren solange bis ein anderes Kommando kommt.

#ifndef STEUERUNG_H
#define STEUERUNG_H

	void init_motorsteuerung(void);	//initialisiert Pins
	void steuerung(int pwrRM, int pwrLM, int time);




#endif
