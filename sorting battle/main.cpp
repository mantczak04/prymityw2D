#include <iostream>
#include <vector>
#include <random>
#include "Screen.h"

#define BLACK 0x0000 << 4
#define BLUE 0x0001 << 4
#define GREEN 0x0002 << 4
#define AQUA 0x0003 << 4
#define RED 0x0004 << 4
#define PURPLE 0x0005 << 4
#define YELLOW 0x0006 << 4
#define WHITE 0x0007 << 4
#define GRAY 0x0008 << 4
#define LIGHT_BLUE 0x0009 << 4
#define LIGHT_GREEN 0x000A << 4
#define LIGHT_AQUA 0x000B << 4
#define LIGHT_RED 0x000C << 4
#define LIGHT_PURPLE 0x000D << 4
#define LIGHT_YELLOW 0x000E << 4
#define BRIGHT_WHITE 0x000F << 4


using namespace std;


int main()
{
    Screen screen(400, 400);
    screen.setScreenActive();

    screen.drawCircle(50, 50, 24, RED);
    screen.drawCircle(60, 60, 24, PURPLE);


    while (1)
    {
        screen.displayScreen();
    }
    
    return 0;
}