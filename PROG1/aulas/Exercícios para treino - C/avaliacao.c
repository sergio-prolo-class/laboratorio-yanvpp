#include <stdio.h>

float maximo(float x, float y)
{
    if (x > y)
    {
        return x;
    }
    return y;
}

float media(float x, float y, float z)
{
    return ((x + y + z) / 3);
}

float arredonda(float x)
{
    int y = (int)x;

    if (x < y)
    {
        x++;
    }
    else
    {
        x = y;
    }

    return x;
}

int main()
{

    return 0;
}