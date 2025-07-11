#include <stdio.h>
#include <stdlib.h>

int main()
{
    int segredo = rand() % 100, palpite, tentativas = 0;

    do {
        printf("Entre com o seu palpite (1 a 100): ");
        scanf("%d", &palpite);

        tentativas++;

        if (palpite < segredo) {
            printf("O segredo é maior\n");
        } else {
            printf("O palpite é menor\n");
        }
    } while (palpite != segredo);

    // for(tentativas = 0; palpite != segredo; tentativas++){
    // instruções
    // }

    printf("Parabéns, você acertou em %d tentativas!\n", tentativas);

    return 0;
}