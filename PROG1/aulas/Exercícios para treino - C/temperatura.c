#include <stdio.h>

float c_para_f(float t)
{
    return (t = 1.8 * t + 32);
}

float f_para_c(float t)
{
    return (t = (t - 32) * (5 / 9));
}

float c_para_k(float t)
{
    return (t = t + 273.15);
}

float k_para_c(float t)
{
    return (t = t - 273.15);
}

float f_para_k(float t)
{
    return (t = (t - 32) * (5 / 9) + 273.15);
}

float k_para_f(float t)
{
    return (t = (t - 273.15) * (9 / 5) + 32);
}

float converter(float t, char origem, char destino)
{
    return t;
}

int main()
{
    float ti, tf;
    char origem, destino;

    printf("Entre com o valor da temperatura: ");
    scanf("%f", &ti);

    printf("Entre com a escala de origem (C, F, K): ");
    scanf("%c", &origem);

    printf("Entre com a escala de destino: ");
    scanf("%c", &destino);

    tf = converter(ti, origem, destino);

        return 0;
}