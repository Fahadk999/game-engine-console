#include <iostream>
#include <chrono>
#include <thread>

#include "gameengine.h"

const unsigned int WIDTH = 80;
const unsigned int HEIGHT = 20;

int main ()
{
    RenderWindow window(WIDTH, HEIGHT);
    window.drawBoundary = true;
    DrawChar person(WIDTH/2, HEIGHT/2, 'G');
    bool right = false;
    int x = WIDTH/2;
    int y = HEIGHT/2;
    while (true)
    {
        window.clear();
        if (!right) { x++; }
        if (right) { --x; }
        if (x >= WIDTH-2) right = true;
        else if (x <= 1) right = false;
        
        person.setPosition(x, y);
        window.draw(person);
        window.render(); 
    }
}
