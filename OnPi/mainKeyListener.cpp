#include <iostream>
#include <sstream>
#include <ncurses.h>

using namespace std;

int main(int argc, char* argv[])
{
    char c;
    string t = "Hallo bitte hier etwas einfügen";
    mvaddstr(5, 5, "aaabbbcc");
    bool abc=true;
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    while(abc == true)
    {
        printw("\nBitte eine Buchstabe eintippen\n");
        c = getch();
        string str = "Test string str";
        cout << str;
        insstr(str);

        printw("Eingabe : ");
        attron(A_BOLD);
		printw("%c", c);
		attroff(A_BOLD);
        printw("\n");

        switch(c)
        {
        case 'w':
        case 'W':
            refresh();
                        move(5, 5);

            printw(" wW wurde ged.");
            refresh();

            //cout << "wW wurde ged." << endl;
            break;
        case 's':
        case 'S':
                    move(5, 5);

            printw(" sS wurde ged.");
            //mvaddstr(5, 5, "aaabbbcc");
                refresh();

            break;
        case 'a':
        case 'A':
                    move(5, 5);

            printw(" aA wurde ged.");
                refresh();

            break;
        case 'd':
        case 'D':
            printw(" dD wurde ged.");
                refresh();

            break;
        case 'b':
            refresh();
	    printw( "b wurde ged.");
	        refresh();

            break;
        case 'l':
        case 'L':
            printw("lL wurde ged.");
                refresh();

	    break;
        case 'e':

            printw(" e wurde ged.");
            abc = false;
            break;
        }
        refresh();
    }
    refresh();
    endwin();
    return 0;
}
