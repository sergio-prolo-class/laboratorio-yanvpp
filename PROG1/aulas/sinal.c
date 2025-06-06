#include <stdio.h>

int main()
{

    int n;

    printf("Entre com um número inteiro:\n");
    scanf("%d", &n);

    if (n > 0)
    {
        printf("É positivo\n");
    }
    else if (n < 0)
    {
        printf("É negativo\n");
    }
    else
    {
        printf("É zero\n");
    }

    return 0;
}