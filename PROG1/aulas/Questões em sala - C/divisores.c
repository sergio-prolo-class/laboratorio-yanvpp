#include <stdio.h>

int main()
{

    int num, divs = 0;

    printf("Entre com um número inteiro:\n");
    scanf("%d", &num);

    printf("Divisores: [1");

    for (int i = 2; i <= num; i++)
    {
        if (num % i == 0)
        {
            divs++;
            printf(", %d", i);
        }
    }

    printf("]");

    if (divs == 2)
    {
        printf("\nÉ primo\n");
    }
    else
    {
        printf("\nNão é primo\n");
    }

    return 0;
}