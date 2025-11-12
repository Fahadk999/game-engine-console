#include <iostream>
#include <chrono>
#include <thread>

#include "gameengine.h"

const unsigned int WIDTH = 40;
const unsigned int HEIGHT = 20;

void bounce (RenderWindow&, int&, int&);
int main ()
{
    RenderWindow window(WIDTH, HEIGHT);
    window.drawBoundary = true;
    DrawChar person(8, 8, 'G');
    int x = 0;
    int y = 0;
    while (true)
    {
        window.clear();
        x++;
        y++;
        person.move(x, y);
        window.draw(person);
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
