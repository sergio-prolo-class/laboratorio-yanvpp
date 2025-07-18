#include <stdio.h>
#include <stdlib.h>

int main()
{
    int palpite, segredo, tentativas;

    segredo = 1 + rand() % 100;

    tentativas = 0;

    do
    {
        printf("Entre com o seu palpite (1 a 100):\n");
        scanf("%d", &palpite);

        tentativas++;

        if (palpite < segredo)
        {
            printf("O número é maior!\n");
        }
        else
        {
            printf("O número é menor!\n");
        }
    } while (palpite != segredo);

    printf("Parabéns, você acertou!\n Número de tentativas: %d\n", tentativas);

    return 0;
}