#include <stdio.h>

int main()
{

    int dias = 7, chuva, acumulado = 0;

    for (int i = 1; i <= 7; i++)
    {
        printf("Entre com a quantidade de chuva no dia %d em litros:\n", i);
        scanf("%d", &chuva);

        acumulado += chuva;

        if (acumulado > 400)
        {
            printf("O reservatório transbordou no dia %d\n", i);
            break;
        }
    }
    return 0;
}