#include <stdio.h>

void imprime_pascal(int n_max);
int coeficiente_binomial(int n, int k);
int potencia_fatorial(int x, int m);

int main()
{
    int n_max;
    printf("Entre com n máximo: ");
    scanf("%d", &n_max);
    imprime_pascal(n_max);
    return 0;
}

// Imprime o triângulo de Pascal até a linha `n_max`
void imprime_pascal(int n_max)
{
    for (int n = 0; n <= n_max; n++) {
        for (int k = 0; k <= n; k++) {
            printf("%4d ", coeficiente_binomial(n, k));
        }
        printf("\n");
    }
}

// Retorna o coeficiente binomial de `n` na classe `k`
int coeficiente_binomial(int n, int k)
{
    return potencia_fatorial(n, k) / potencia_fatorial(k, k);
}

// Retorna a `m`-ésima potência fatorial de `x`
int potencia_fatorial(int x, int m)
{
    int res = 1;
    while (m > 0) {
        res *= x;
        x--;
        m--;
    }
    return res;
}
