// Header-Datei IRSensor
// Hier werden alle nutzbaren Funktionen aus ir.cpp deklariert

//Prueft ob Konstante IR_H schonmal erstellt wurde.
//Wenn ja, dann wurde headerdatei schon hinzugefuegt und wird
//nicht noch ein zweites mal hinzugefuegt.
#ifndef IR_H
#define IR_H
	#define IRL 5 //SENSORLEFT PHYSICAL=18
	#define IRR 4 //SENSORRIGHT PHYSICAL=16
	void init_irsens(void);

#endif
