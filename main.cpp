#include <iostream>
#include <chrono>
#include <thread>

#include "gameengine.h"

const unsigned int WIDTH = 40;
const unsigned int HEIGHT = 60;

void bounce (RenderWindow&, int&, int&);
int main ()
{
    RenderWindow window(WIDTH, HEIGHT);
    window.drawBoundary = true;
    char c = '&';
    int x = 5;
    int y = 0;
    while (true)
    {
        bounce(window, x, y);
        window.clear();
        window.draw(x++, y++, '&');
        window.render(); 
    }
}

void bounce (RenderWindow& window, int& x, int& y)
{
    if (x >= WIDTH) { x--; }
    if (x <= 0) { x++; }
    if (y >= HEIGHT) { y--; }
    if (y <= 0) { y++; }
}
