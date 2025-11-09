#include "gameengine.h"

RenderWindow::~RenderWindow ()
{
    if (window)
    {
        for (int x = 0; x < HEIGHT; x++)
            delete[] window[x];
        delete[] window;
    }
}
void RenderWindow::setWindow (unsigned int WIDTH, unsigned int HEIGHT)
{
    if (window)
    {
        for (int i = 0; i < HEIGHT; i++)
            delete[] window[i];
        delete[] window;
    }

    this->WIDTH = WIDTH;
    this->HEIGHT = HEIGHT;
    window = nullptr;
    initWindow();
}
void RenderWindow::initWindow ()
{
    if (!window)
    {
        window = new char*[HEIGHT];
        for (int i = 0; i < HEIGHT; i++)
            window[i] = new char[WIDTH];
    }

    for (int x = 0; x < HEIGHT; x++)
        for (int y = 0; y < WIDTH; y++)
            window[x][y] = ' ';
}
void RenderWindow::render ()
{
    for (int x = 0; x < HEIGHT; x++)
    {
        for (int y = 0; y < WIDTH; y++)
        {
            std::cout << window[x][y];
        }
        std::cout << '\n';
    }
}
void RenderWindow::clear ()
{
    for (int x = 0; x < HEIGHT; x++)
        for (int y = 0; y < WIDTH; y++)
            window[x][y] = ' ';
}
void RenderWindow::draw(int x, int y, char ch) {
    if (x >= 0 && x < (int)HEIGHT && y >= 0 && y < (int)WIDTH)
        window[x][y] = ch;
}
