#include <iostream>
#include <sstream>
#include <ncurses.h>
#include <wiringPi.h>
#include <softPwm.h>

#include "./USSensor/USSensor.h"
#include "./Motorsteuerung/steuerung.h"
#include "./IRSensor/ir.h"

#define PMIN 60
#define MMIN -60

void printElements();
void calcCounterToPWR();
void start();
void dynamischRechts();
void dynamischLinks();
void beschleunigen();
void updateIR();
void lineFollower();

using namespace std;

char c = '_';
int a = 0;

bool aktiv=true;
bool follow = false;

int PRM = 0;
int PLM = 0;
int t = 0;

int pmin = PMIN;
int mmin = MMIN;

int counterDirection = 0;
int counterSpeed = 0;

int irR = digitalRead(IRR);
int irL = digitalRead(IRL);

const char *strC = "LEER";
const char *titel = "SINO SmartSensor Car";
const char *titel2 = "Trible S-Car";

const char *strLE = "Letze Eingabe = ";

const char *strCS = "Aktuelle Geschwindigkeit = ";
const char *strCD = "Aktuelle Richtung = ";

const char *strPRL = "Pwr RM = ";
const char *strPLM = "Pwr LM = ";

const char *strIRR = "IR Rechts -> ";
const char *strIRL = " <- IR Links | ";

void printElements()
{
    refresh();
    mvprintw(0, 25, titel);
    mvprintw(1, 30, titel2);

    mvprintw(4, 2, strCS);
    mvprintw(5, 2, strCD);

    mvprintw(4, 30, "%d ", counterSpeed);
    mvprintw(5, 30, "%d ", counterDirection);

    mvprintw(4, 45, strPRL);
    mvprintw(5, 45, strPLM);

    mvprintw(4, 55, "%d ", PRM);
    mvprintw(5, 55, "%d ", PLM);

    mvprintw(7, 2, strLE);
    mvprintw(7, 20, "%c ", c);

    mvprintw(9, 33, strIRR);
    mvprintw(9, 2, strIRL);

    mvprintw(9, 19, "%d ", irR);
    mvprintw(9, 4, "%d ", irL);

    mvprintw(11, 2, "follow = ");
    mvprintw(11, 13, "%d", follow);

    mvprintw(20, 2, "'W' - SpeedUp");
    mvprintw(20, 27, "'S' - SpeedDown");
    mvprintw(21, 2, "'D' - Rechts");
    mvprintw(21, 27, "'A' - Links");

    mvprintw(20, 55, "'B' - Bremsen");
    mvprintw(21, 47, "'LEERTASTE' - PRM-PLM 100");

    mvprintw(22, 2, "'E' - Beenden");

}

void calcCounterToPWR()
{

// Vorwärts
    if(counterSpeed >= 1)
    {
        //Rechts
        if(counterDirection > 0)
        {
            PRM = pmin + ((counterSpeed*10)-(counterDirection*10));
            PLM = pmin + (counterSpeed*10);
        }
        //Links
        else if(counterDirection < 0)
        {
            PRM = pmin + (counterSpeed*10);
            PLM = pmin + ((counterSpeed*10)-(-counterDirection*10));
        }
        //gerade
        else
        {
            PRM = pmin + (counterSpeed*10);
            PLM = pmin + (counterSpeed*10);
        }
    }
    // Rückwärt
    else if(counterSpeed <=-1)
    {
        //Rechts
        if(counterDirection > 0)
        {
            PRM = mmin + ((counterSpeed*10)-(counterDirection*10));
            PLM = mmin + (counterSpeed*10);
        }
        //Links
        else if(counterDirection < 0)
        {
            PRM = mmin + (counterSpeed*10);
            PLM = mmin + ((counterSpeed*10)-(-counterDirection*10));
        }
        //gerade
        else
        {
            PRM = mmin + (counterSpeed*10);
            PLM = mmin + (counterSpeed*10);
        }
    }
    else // cspeed == 0
    {
        //Rechts
        if(counterDirection >= 1)
        {
            PRM = 0;
            PLM = pmin + (counterDirection*10);
        }
        //Links
        else if(counterDirection <= -1)
        {
            PRM = pmin + (-counterDirection*10);
            PLM = 0;
        }
        //gerade
        else
        {
            PRM = 0;
            PLM = 0;
        }
    }
}

void start()
{
    while(aktiv == true)
    {

        c = getch();
        mvprintw(16, 2, "Schleife geht weiter mit %d", a);
        a++;

        keyListener();
        if(counterDirection >= 4)
            counterDirection = 4;
        if(counterDirection <= -4)
            counterDirection = -4;
        if(counterSpeed >= 4)
            counterSpeed = 4;
        if(counterSpeed <= -4)
            counterSpeed = -4;

        calcCounterToPWR();
        steuerung(PRM, PLM, t);

        printElements();
    }
}

void keyListener()
{
    switch(c)
    {
    case 'w':
    case 'W':
        counterSpeed++;
        break;
    case 's':
    case 'S':
        counterSpeed--;
        break;
    case 'a':
    case 'A':
        counterDirection--;
        break;
    case 'd':
    case 'D':
        counterDirection++;
        break;
    case 'b':
        counterDirection = 0;
        counterSpeed = 0;
        softPwmWrite(21, 0);
        softPwmWrite(22, 0);
        softPwmWrite(23, 0);
        softPwmWrite(24, 0);
        break;
    case ' ':
        counterDirection = 0;
        counterSpeed = 4;
        softPwmWrite(21, 100);
        softPwmWrite(22, 0);
        softPwmWrite(23, 100);
        softPwmWrite(24, 0);
        break;
    case 'l':
    case 'L':
        // Toggle: true = false <-> false == true;
        follow = !follow;
        lineFollower();
        //  -> start lineFollower
        break;
    case 'e':
        //    printw(" e wurde ged.");
        aktiv = false;
        break;
    }
}

void dynamischRechts()
{
    for(int i = 10; i <= 50; i++)
    {
        steuerung(50+i,50,0);
        // delay(50);
    }
}
void dynamischLinks()
{
    for(int i = 10; i <= 50; i++)
    {
        steuerung(50,50+i,0);
        // delay(50);
    }
}
void beschleunigen()
{
    for(int i = 10; i <= 50; i++)
    {
        steuerung(50+i,50+i,0);
        // delay(50);
    }
}

// Aktuellisiert die IR Sensor Werte
void updateIR()
{
    irR = digitalRead(IRR);
    irL = digitalRead(IRL);
}

// Linienverfolgung, fährt gerade aus, bis eine Linie entdeckt wurde
void lineFollower()
{

    updateIR();
    bool findLine = false;

    while(follow == true && getDistance() >= 20 )
    {
        mvprintw(12, 2, "findLine = %d", findLine);
        mvprintw(13, 2, "Distance = %d", getDistance());



        // Fahre bis eine linie entdeckt wird
        while(findLine == false)
        {
            updateIR();
            steuerung(50, 50, 0);
            if(irL == LOW || irR == LOW)
                findLine = true;
        }

        updateIR();
        // stop
        if(irL == LOW && irR == LOW)
        {
            delay(50);
            if(irL == LOW && irR == LOW)
                steuerung(0,0,0);
        }
        // Links
        if(irL == LOW && irR == HIGH)
        {
            dynamischLinks();
            //steuerung(50,80,0);
        }
        // Rechts
        if(irL == HIGH && irR == LOW)
        {
            dynamischRechts();
            //steuerung(80,50,0);
        }
        // gerade aus
        if(irL == HIGH && irR == HIGH)
        {
            beschleunigen();
            //steuerung(80,80,0);
        }
        updateIR();
    }
    follow = !follow;
}

int main(int argc, char* argv[])
{
    if(wiringPiSetup()==-1)
    {
        cout << "Initalisation failed.\n";
    }

    init_motorsteuerung();
    init_USSensor();

    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();

    printElements();

    start();

    refresh();
    getch();
    endwin();
    return 0;

}



