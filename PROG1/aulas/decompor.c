#include <stdio.h>

char decompor(float x, int *parte_int, float *parte_frac)
{
    char sinal;

    if (x > 0)
    {
        sinal = '+';
    }
    else if (x < 0)
    {
        x = -x;
        sinal = '-';
    }
    else
    {
        sinal = ' ';
    }

    *parte_int = (int)x;
    *parte_frac = x - *parte_int;

    return sinal;
}

int main()
{
    float x, parte_frac;
    int parte_int;
    char sinal;

    printf("Entre com um número real:\n");
    scanf("%f", &x);

    sinal = decompor(x, &parte_int, &parte_frac);

    printf("Sinal: %c\n", sinal);
    printf("Parte inteira: %d\n", parte_int);
    printf("Parte fracionária: %.2f\n", parte_frac);

    return 0;
}