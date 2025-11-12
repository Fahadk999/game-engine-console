#include <iostream>

class DrawChar
{
    private:
        int x = 0;
        int y = 0;
        char ch = '#';

    public:
        DrawChar () = default;
        DrawChar (int x, int y, char ch)
            :   x(x), y(y), ch(ch) {}

        int getX () const { return x; }
        int getY () const { return y; }
        char getChar () const { return ch; }

        void setX (int x) { this->x = x; }
        void setY (int y) { this->y = y; }
        void setChar (char ch) { this->ch = ch; }
        void move (int newX, int newY);
};
