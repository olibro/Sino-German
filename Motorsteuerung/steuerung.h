// Header-Datei zur Motorsteuerung
// Hier werden alle nutzbaren Funktionen aus steuerung.cpp deklariert.r

//Prueft ob Konstante STEUERUNG_H schonmal erstellt wurde.
//Wenn ja, dann wurde headerdatei schon hinzugefuegt und wird
//nicht noch ein zweites mal hinzugefuegt.
#ifndef STEUERUNG_H
#define STEUERUNG_H

	//Manueller Modus: pwr=0..100, time=An-Zeit in ms, danach wieder aus.
	//Automatischer Modus: time==0, Motor immer an bis pwr==0
	void init_motorsteuerung(void);	//initialisiert Pins
	void rm_vor(int pwr, int time);
	void rm_zur(int pwr, int time);
	void lm_vor(int pwr, int time);
	void lm_zur(int pwr, int time);
	void steurung(int pwrRM, int pwrLM, int time);

	//Hier fehlen noch die Prototypen fuer die anderen Motoren

#endif
