#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main()
{

    float prova11, prova12, prova1, rec1, prova2, rec2, nota1ofc, nota2ofc;
    int media, frequencia;

    printf("Insira a nota da prova 1.1:");
    scanf("%f", &prova11);
    prova11 = (int)(round(prova11));

    printf("Insira a nota da prova 1.2:");
    scanf("%f", &prova12);
    prova12 = (int)(round(prova12));

    prova1 = fmax(prova11, prova12);

    printf("Insira a nota da recuperação 1:");
    scanf("%f", &rec1);
    rec1 = (int)(round(rec1));

    nota1ofc = fmax(prova1, rec1);

    printf("Insira a nota da prova 2:");
    scanf("%f", &prova2);
    prova2 = (int)(round(prova2));

    printf("Insira a nota da recuperação 2:");
    scanf("%f", rec2);
    rec2 = (int)(round(rec2));

    nota2ofc = fmax(prova2, rec2);

    media = fmax(nota1ofc, nota2ofc);

    printf("Média final: %.2f", media);

    return 0;
}