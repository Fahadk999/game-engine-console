#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <thread>

class RenderWindow
{
private:
    unsigned int WIDTH = 0;
    unsigned int HEIGHT = 0;
    std::vector<std::vector<char>> frontBuffer;
    std::vector<std::vector<char>> backBuffer;
    char boundary = '#';

public:
    bool drawBoundary = false;

    RenderWindow() = default;
    RenderWindow(unsigned int width, unsigned int height)
        : WIDTH(width), HEIGHT(height) 
    {
        setWindow(width, height);
    }

    void setWindow(unsigned int width, unsigned int height);
    void render(); 
    void draw(int x, int y, char ch);
    void clear();
    void setBoundaryChar(char ch);
    unsigned int getWidth() const { return WIDTH; }
    unsigned int getHeight() const { return HEIGHT; }
};
