#include <stdio.h>

void imprime_pascal(int n_max);
int coeficiente_binomial(int n, int k);
int potencia_fatorial(int x, int m);

int main()
{
    int num, numax;

    printf("Entre com o número máximo:\n");
    scanf("%d", &numax);

    imprime_pascal(numax);

    return 0;
}

void imprime_pascal(int numax)
{
    for (int num = 0; num <= numax; num++)
    {
        for (int k = 0; k <= num; k++)
        {
            printf("%4d ", coeficiente_binomial(num, k));
        }
        printf("\n");
    }
}

int coeficiente_binomial(int num, int k)
{
    return potencia_fatorial(num, k) / potencia_fatorial(k, k);
}

int potencia_fatorial(int x, int m)
{
    int res = 1;
    while (m > 0)
    {
        res *= x;
        x--;
        m--;
    }
    return res;
}