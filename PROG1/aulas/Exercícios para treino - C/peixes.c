#include <stdio.h>

int main()
{
    float phmax, phmin, medicoes;
    int qtdmed, mederro = 0;

    printf("Entre com a faixa de pH adequada: ");
    scanf("%f %f", &phmin, &phmax);

    printf("Entre com o número de medições: ");
    scanf("%d", &qtdmed);

    printf("Entre com as medições de pH: ");

    for (mederro; qtdmed > 0; qtdmed--) {
        scanf("%f", &medicoes);

        if (medicoes < phmin || medicoes > phmax) {
            mederro++;
        }
    }

    printf("Número de medições fora da faixa: %d\n", mederro);

    return 0;
}