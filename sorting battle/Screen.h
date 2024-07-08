#pragma once

#include <Windows.h>

class Screen
{
    wchar_t* screen;
    HANDLE hConsole;
    DWORD bytesWritten;
    const int width;
    const int height;

public:
    Screen(int nWidth, int nHeight);

    ~Screen();

    void displayScreen();

    void setScreenActive();

    void setPixel(int x, int y, WORD color);
    
    int getScreenWidth();

    int getScreenHeight();
};

