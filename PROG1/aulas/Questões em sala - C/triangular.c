#include <stdio.h>
#include <stdbool.h>

bool eh_triangular(int numero_referencia)
{
    int i, numero_calculo;

    i = 1;
    numero_calculo = 0;

    while (numero_calculo < numero_referencia)
    {
        numero_calculo += i;
        i++;
    }
    return numero_calculo == numero_referencia;
}

int main()
{
    int numero_referencia;

    printf("Entre com um número inteiro positivo:\n");
    scanf("%d", &numero_referencia);

    if (eh_triangular(numero_referencia))
    {
        printf("É um número triângular.\n");
    }
    else
    {
        printf("Não é um número triângular.\n");
    }
    return 0;
}