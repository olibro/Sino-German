#include <iostream>
#include <sstream>
#include "conio.h"

using namespace std;

int main(int argc, char* argv[])
{
    char c;
    bool abc=true;
    while(abc == true)
    {
        c = getch();
        cout << c << " <- wurde eingetippt" << endl;

        switch(c)
        {
    case 'w':
        case 'W':
            cout << "wW wurde ged." << endl;
            break;
        case 's':
        case 'S':
            cout << "sS wurde ged." << endl;
            break;
        case 'a':
        case 'A':
            cout << "aA wurde ged." << endl;
            break;
        case 'd':
        case 'D':
            cout << "dD wurde ged." << endl;
            break;
        case 'b':
            cout << "Leertaste wurde ged." << endl;
            break;
        case 'l':
        case 'L':
            cout << "lL wurde ged." << endl;
            break;
        case 'e':
            cout << "e wurde ged." << endl;
            abc = false;
            break;
        }
    }
    return 0;
}
