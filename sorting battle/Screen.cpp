#include "Screen.h"
#define BLACK 0x0000<<4


    Screen::Screen(int nWidth, int nHeight) : width(nWidth), height(nHeight)
    {
        screen = new char[width * height];
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
        WriteConsoleOutputCharacterA(hConsole, screen, width * height, { 0, 0 }, &bytesWritten);
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


    //to be done with external character as next parameter?
    void Screen::setMultiplePixels(int xFrom, int xTo, int yFrom, int yTo, WORD color /*char character*/) {
        COORD startPos;
        DWORD length = xTo - xFrom + 1; // Number of characters per row to fill
        for (int y = yFrom; y <= yTo; ++y) {
            startPos = { SHORT(xFrom), SHORT(y) };
            FillConsoleOutputCharacter(hConsole, ' ', length, startPos, &bytesWritten); // Fill characters
            FillConsoleOutputAttribute(hConsole, color, length, startPos, &bytesWritten); // Fill attributes
        }
    }

    void Screen::drawCircle(int centerX, int centerY, int radius, WORD color)
    {
        int x = radius;
        int y = 0;
        int p = 1 - radius;

        while (x >= y)
        {
            setPixel(centerX + x, centerY + y, color);
            setPixel(centerX - x, centerY + y, color);
            setPixel(centerX + x, centerY - y, color);
            setPixel(centerX - x, centerY - y, color);
            setPixel(centerX + y, centerY + x, color);
            setPixel(centerX - y, centerY + x, color);
            setPixel(centerX + y, centerY - x, color);
            setPixel(centerX - y, centerY - x, color);
            y++;

            if (p <= 0) {
                p = p + 2 * y + 1;
            }
            else {
                x--;
                p = p + 2 * y - 2 * x + 1;
            }
        }
    }

    //GETTERS, SETTERS
    int Screen::getScreenWidth()
    {
        return width;
    }

    int Screen::getScreenHeight()
    {
        return height;
    }