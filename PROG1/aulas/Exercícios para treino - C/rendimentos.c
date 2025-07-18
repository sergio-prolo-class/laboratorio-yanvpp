#include <stdio.h>

#define VALOR_INICIAL 10000.0
#define TAXA_INICIAL 6.0
#define PASSO_TAXA 0.5
#define NUM_TAXAS 5
#define NUM_ANOS 4

int main()
{
    float taxa[NUM_TAXAS];   // Armazena as taxas de rendimento
    float valor[NUM_TAXAS];  // Começa com o valor inicial e atualiza a cada ano

    printf("Ano  ");
    for (int i = 0; i < NUM_TAXAS; i++) {
        printf("%.2f%%        ", TAXA_INICIAL + PASSO_TAXA * i);
        taxa[i] = TAXA_INICIAL + PASSO_TAXA * i;
    }

    printf("\n1    ");
    for (int i = 0; i < NUM_TAXAS; i++) {
        printf("%.2f     ", taxa[i] / 100 * VALOR_INICIAL + VALOR_INICIAL);
        taxa[i];
        valor[i] = taxa[i] / 100 * VALOR_INICIAL + VALOR_INICIAL;
    }

    printf("\n2    ");
    for (int i = 0; i < NUM_TAXAS; i++) {
        printf("%.2f     ", taxa[i] / 100 * valor[i] + valor[i]);

        valor[i] = taxa[i] / 100 * valor[i] + valor[i];
    }

    printf("\n3    ");
    for (int i = 0; i < NUM_TAXAS; i++) {
        printf("%.2f     ", taxa[i] / 100 * valor[i] + valor[i]);

        valor[i] = taxa[i] / 100 * valor[i] + valor[i];
    }

    printf("\n4    ");
    for (int i = 0; i < NUM_TAXAS; i++) {
        printf("%.2f     ", taxa[i] / 100 * valor[i] + valor[i]);

        valor[i] = taxa[i] / 100 * valor[i] + valor[i];
    }

    return 0;
}