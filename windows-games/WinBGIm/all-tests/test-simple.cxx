#include <graphics.h>
#include <iostream>
using namespace std;

int main( )
{
    fillsettingstype f;
    initwindow(300,300);
    getfillsettings(&f);
    cout << f.pattern << endl;
    cout << f.color << endl;
    bgiout << "What's up?" << endl;
    bgiout << "Hello " << 42000;
    outstreamxy(30, 30);
    bgiout << "Bye." << endl;
    outstreamxy(150, 150);
    while (!kbhit())
    delay(1000);
    return 0;
}
