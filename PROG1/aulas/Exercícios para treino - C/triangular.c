#include <stdio.h>
#include <stdbool.h>

bool eh_triangular(int n)
{
    int i = 0, j = 1;

    while (i < n) {
        i += j;
        j++;
    }
    return (i == n);
}

int main()
{
    int n;

    printf("Entre com um inteiro positivo: ");
    scanf("%d", &n);

    if (eh_triangular(n)) {
        printf("É triangular.\n");
    } else {
        printf("Não é triangular.\n");
    }

    return 0;
}