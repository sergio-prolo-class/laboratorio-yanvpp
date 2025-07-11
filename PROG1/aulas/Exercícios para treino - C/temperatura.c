#include <stdio.h>

float c_para_f(float t)
{
    return 1.8 * t + 32;
}

float f_para_c(float t)
{
    return (t - 32) / 1.8;
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
    return (t = (t - 32) * (5.0 / 9.0) + 273.15);
}

float k_para_f(float t)
{
    return (t = (t - 273.15) * (9. / 5.0) + 32);
}

float converter(float t, char origem, char destino)
{
    if (origem != destino)
    {
        if (origem == 'C' && destino == 'F')
        {
            t = c_para_f(t);
        }
        else if (origem == 'F' && destino == 'C')
        {
            t = f_para_c(t);
        }
        else if (origem == 'C' && destino == 'K')
        {
            t = c_para_k(t);
        }
        else if (origem == 'K' && destino == 'C')
        {
            t = k_para_c(t);
        }
        else if (origem == 'F' && destino == 'K')
        {
            t = f_para_k(t);
        }
        else
        {
            t = k_para_f(t);
        }
    }
    else
    {
        t = t;
    }

    return t;
}

int main()
{
    float ti, tf;
    char origem, destino;

    printf("Entre com o valor da temperatura: ");
    scanf("%f", &ti);

    printf("Entre com a escala de origem (C, F, K): ");
    scanf(" %c", &origem);

    printf("Entre com a escala de destino (C, F, K): ");
    scanf(" %c", &destino);

    tf = converter(ti, origem, destino);

    printf("Temperatura convertida: %.2f\n", tf);

    return 0;
}