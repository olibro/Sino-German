#include <iostream>
#include <sstream>
#include <ncurses.h>
#include <wiringPi.h>
#include <softPwm.h>

#include "./USSensor/USSensor.h"
#include "./Motorsteuerung/steuerung.h"

#define PMIN 60;
#define MMIN -60;

using namespace std;



char c = '_';

bool abc=true;

int PRM = 0;
int PLM = 0;
int t = 0;

int pmin = PMIN;
int mmin = MMIN;

int counterDirection = 0;
int counterSpeed = 0;

const char *strC = "LEER";
const char *titel = "SINO SmartSensor Car";
const char *titel2 = "Trible S-Car";

const char *strLE = "Letze Eingabe = ";

const char *strCS = "Aktuelle Geschwindigkeit = ";
const char *strCD = "Aktuelle Richtung = ";

const char *strPRL = "Pwr RM = ";
const char *strPLM = "Pwr LM = ";




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

void start(){
while(abc == true)
    {
        c = getch();


        switch(c)
        {
        case 'w':
        case 'W':
            counterSpeed++;
            //   str2 = "die Taste W oder w wurde gedrückt";
            //    refresh();
            break;
        case 's':
        case 'S':
            counterSpeed--;
            //    printw(" sS wurde ged.");
            //     refresh();
            break;
        case 'a':
        case 'A':
            counterDirection--;
            //     printw(" aA wurde ged.");
            //    refresh();
            break;
        case 'd':
        case 'D':
            counterDirection++;
            //    printw(" dD wurde ged.");
            //   refresh();
            break;
        case 'b':
            //    printw( "b wurde ged.");
            //   refresh();
            break;
        case 'l':
        case 'L':
            //    printw("lL wurde ged.");
            //   refresh();
            break;
        case 'e':

            //    printw(" e wurde ged.");
            abc = false;
            break;
        }
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



