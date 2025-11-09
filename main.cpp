#include <iostream>

#include "gameengine.h"

const unsigned int WIDTH = 30;
const unsigned int HEIGHT = 10;

int main ()
{
    RenderWindow window(WIDTH, HEIGHT);
    window.clear();
    window.draw(6, 7, '&');
    window.render(); // add the boundary switch, also try this in a loop
}
