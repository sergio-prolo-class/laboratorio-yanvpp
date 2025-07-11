#include <stdio.h>

int main()
{

    int m_fora = 0, medicoes;
    float faixa_min, faixa_max, ph;

    printf("Entre com a faixa de pH adequada (faixa_min faixa_max):\n");
    scanf("%f %f", &faixa_min, &faixa_max);

    printf("Entre com o número de medições:\n");
    scanf("%d", &medicoes);

    printf("Entre com o valor do pH:\n");

    for (int i = medicoes; i > 0; i--)
    {
        scanf("%f", &ph);

        if (ph < faixa_min || ph > faixa_max)
        {
            m_fora++;
        }
    }

    printf("Número de medições fora da faixa: %d\n", m_fora);

    return 0;
}