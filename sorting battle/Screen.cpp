#include "Screen.h"
#define BLACK 0


    Screen::Screen(int nWidth, int nHeight) : width(nWidth), height(nHeight)
    {
        screen = new wchar_t[width * height];
        hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
        bytesWritten = 0;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                setPixel(j, i, BLACK);
            }
        }
    }

    Screen::~Screen()
    {
        delete[] screen;
        CloseHandle(hConsole);
    }

    void Screen::displayScreen()
    {
        WriteConsoleOutputCharacter(hConsole, screen, width * height, { 0, 0 }, &bytesWritten);
    }

    void Screen::setScreenActive()
    {
        SetConsoleActiveScreenBuffer(hConsole);
    }

    void Screen::setPixel(int x, int y, WORD color)
    {
        screen[y * width + x] = ' ';
        COORD pos = { (SHORT)x, (SHORT)y };
        FillConsoleOutputAttribute(hConsole, color, 1, pos, &bytesWritten);
    }

    int Screen::getScreenWidth()
    {
        return width;
    }

    int Screen::getScreenHeight()
    {
        return height;
    }