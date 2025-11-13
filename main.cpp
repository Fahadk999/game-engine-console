#include <conio.h>

#include "gameengine.h"
#include "logic.h"

const unsigned int WIDTH = 80;
const unsigned int HEIGHT = 20;

int main ()
{
    RenderWindow window(WIDTH, HEIGHT);
    window.drawBoundary = true;
    DrawChar ball(WIDTH/2, HEIGHT/2, 'O');
    DrawChar line[4] =
    {
        {5,3, '|'},
        {5,4, '|'},
        {5,5, '|'},
        {5,6, '|'}
    };
    bool right = false;
    int x = WIDTH/2;
    int y = HEIGHT/2;

    while (true)
    {
        window.clear();
        input(line);
        ballMotion(right, x, y, WIDTH, HEIGHT);
        
        ball.setPosition(x, y);
        window.drawAll(line, 4);
        window.draw(ball);
        window.render(); 
    }
}
