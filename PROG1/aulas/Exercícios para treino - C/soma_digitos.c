#include <stdio.h>

int soma_digitos(int n, int *soma)
{
    int resto = 0;

    for (int i = 0; n >= 1; i++) {
        resto = n % 10;
        n = (n / 10);
        soma += resto;
    }
}

int main()
{
    int n, soma = 0;

    printf("Entre com um inteiro não negativo: ");
    scanf("%d", &n);

    soma = soma_digitos(n, &soma);

    printf("Soma dos dígitos: %d", soma);

    return 0;
}