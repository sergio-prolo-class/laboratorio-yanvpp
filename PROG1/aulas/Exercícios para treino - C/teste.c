#include <stdio.h>
#include <stdlib.h>  // srand, rand
#include <time.h>    // time

int main()
{
    int dado1, dado2, soma, num_rolagens;
    int hist[13] = {};

    printf("Entre com o numero de rolagens: ");
    scanf("%d", &num_rolagens);

    srand(time(NULL));

    for (int i = 1; i <= num_rolagens; i++) {
        dado1 = rand() % 6 + 1;
        dado2 = rand() % 6 + 1;
        soma = dado1 + dado2;
        hist[soma]++;
    }

    for (soma = 2; soma <= 12; soma++) {
        printf("%2d : %5.2f%%\n", soma, (float)hist[soma] / num_rolagens * 100.0);
    }

    return 0;
}
