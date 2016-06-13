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
        cout << c << " <- wurde eingetippt";

        switch(c)
        {
        case 'a':
            cout << "a wurde ged." ;
            break;
        case 'A':
            cout << "a wurde ged." ;
            break;
        case 'd' || 'D':
            cout << "D oder d wurde ged." ;
            break;
        case 'e':
            abc = false;
            break;
        }
    }


    return 0;
}
