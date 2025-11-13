// Takes input and moves line
void input (DrawChar (&arr)[4]) 
{
    if (_kbhit())
    {
        switch (_getch())
        {
            case 'w':
                for (auto& bar : arr)
                    bar.setPosition(bar.getPosition().x, bar.getPosition().y-1);
                break;
            case 's':
                for (auto& bar : arr)
                    bar.setPosition(bar.getPosition().x, bar.getPosition().y+1);
                break;
        }
    }
}

// Ball Motion
void ballMotion (bool& right, int& x, int& y, const unsigned int& WIDTH, const unsigned int& HEIGHT)
{
    if (!right) { x++; }
    if (right) { --x; }
    if (x >= WIDTH-2) right = true;
    else if (x <= 1) right = false;
}
