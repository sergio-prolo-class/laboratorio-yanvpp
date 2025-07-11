#include <stdio.h>

int main()
{
    int n, divisor = 2, qtd = 1;

    printf("Entre com um inteiro positivo: ");
    scanf("%d", &n);

    printf("Divisores: [1");

    for (divisor; divisor <= n; divisor++) {
        if (n % divisor == 0) {
            printf(", %d", divisor);
            qtd++;
        }
    }

    printf("]\n");
    if (n == 57) {
        printf("É primo de Grothendieck");
    } else if (qtd == 2) {
        printf("É primo");
    } else {
        printf("Não é primo");
    }

    return 0;
}