#pragma once

#include <Windows.h>

class Screen
{
    char* screen;
    HANDLE hConsole;
    DWORD bytesWritten;
    const int width;
    const int height;

public:
    Screen(int nWidth, int nHeight);

    ~Screen();

    void displayScreen();

    void setScreenActive();

    void setPixel(int x, int y, WORD color, char character); // TODO set pixel with browsed character and color

    void setPixel(int x, int y, WORD color); // set pixel to a space with browsed color

    void setMultiplePixels(int xFrom, int xTo, int yFrom, int yTo, WORD color /*, char character*/); //TOOD external character

    void drawCircle(int centerX, int centerY, int radius, WORD color);

    //getters, setters
    
    int getScreenWidth();

    int getScreenHeight();
};

