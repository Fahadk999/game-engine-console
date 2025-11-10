#include <iostream>
#include <chrono>
#include <thread>

#include "gameengine.h"

const unsigned int WIDTH = 40;
const unsigned int HEIGHT = 20;

int main ()
{
    RenderWindow window(WIDTH, HEIGHT);
    window.drawBoundary = true;

    while (true)
    {
        window.clear();
        window.draw(6, 17, '&');
        window.render(); // add the boundary switch, also try this in a loop
    }
}
