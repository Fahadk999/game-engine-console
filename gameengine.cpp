#include "gameengine.h"

#ifdef _WIN32
#include <windows.h>

void moveCursorTo (int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos {(SHORT)y, (SHORT)x};
    SetConsoleCursorPosition(hOut, pos);
}
#else
void moveCursorTo (int x, int y)
{
    std::cout<< "\033[" << x+1 << ";" << y+1 << "H";
}
#endif
void RenderWindow::setWindow(unsigned int width, unsigned int height)
{
    WIDTH = width;
    HEIGHT = height;
    frontBuffer.assign(HEIGHT, std::vector<char>(WIDTH, ' '));
    backBuffer = frontBuffer;
}
void RenderWindow::clear()
{
    for (auto& row : frontBuffer)
        std::fill(row.begin(), row.end(), ' ');
}

void RenderWindow::render() 
{
    for (unsigned int x = 0; x < HEIGHT; ++x)
    {
        for (unsigned int y = 0; y < WIDTH; ++y)
        {
            char ch = frontBuffer[x][y];
            if (drawBoundary && (x == 0 || y == 0 || x == HEIGHT - 1 || y == WIDTH - 1))
                ch = boundary;
            if (backBuffer[x][y] != ch)
            {
                moveCursorTo(x,y);
                std::cout << ch;
                backBuffer = ch;
            }
        }
    }
    std::cout.flush;
    std::this_thread::sleep_for(std::chrono::miliseconds(framedelay));
}

void RenderWindow::draw(int x, int y, char ch)
{
    if (x >= 0 && x < (int)HEIGHT && y >= 0 && y < (int)WIDTH)
        frontBuffer[x][y] = ch;
}

void RenderWindow::setBoundaryChar(char ch)
{
    if (drawBoundary)
        boundary = ch;
    else
        std::cout << "Set <yourWindow>.drawBoundary = true before changing boundary character.\n";
}
