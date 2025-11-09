#include <iostream>

class RenderWindow
{
    private:
        bool isopen = false;
        unsigned int WIDTH;
        unsigned int HEIGHT;
        char** window = nullptr;
    public:
        RenderWindow() { isopen = true; }
        RenderWindow(const unsigned int WIDTH, const unsigned int HEIGHT) : WIDTH(WIDTH), HEIGHT(HEIGHT) { initWindow(); }
        ~RenderWindow();
        bool isOpen() const { return isopen; }
        void setWindow (unsigned int WIDTH, unsigned int HEIGHT);
        void initWindow ();
        void render ();
        void draw (int x, int y, char ch);
        void clear ();
};
