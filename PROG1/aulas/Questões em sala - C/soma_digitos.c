#include <stdio.h>

int main()
{
    int numero, soma, resto;

    soma = 0;

    printf("Entre com um número inteiro positivo:\n");
    scanf("%d", &numero);

    while (numero > 0)
    {
        resto = numero % 10;
        soma += resto;
        numero = numero / 10;
    }
    printf("A soma dos dígitos é: %d\n", soma);

    return 0;
}