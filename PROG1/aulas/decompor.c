#include <stdio.h>

char decompor(float x, int *parte_int, float parte_frac, char sinal)
{
    if (x > 0)
    {
        sinal = '+';
    }
    else if (x < 0)
    {
        sinal = '-';
    }
    else
    {
        sinal = ' ';
    }

    parte_frac = x - float(x);
}

int main()
{
    float x, *parte_frac;
    int *parte_int;
    char sinal;

    printf("Entre com um número real:\n");
    scanf("f", &x);

    printf("Sinal: %c\n", sinal);
    printf("Parte inteira: %d\n", *parte_int);
    printf("Parte fracionária: %f\n", *parte_frac);

    return 0;
}