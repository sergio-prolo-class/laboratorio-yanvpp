#include <stdio.h>

float maximo(float x, float y)
{
    if (x > y)
    {
        return x;
    }
    return y;
}

float media(float x, float y, float z)
{
    return ((x + y + z) / 3);
}

float arredonda(float x)
{
    return (int)(x + 0.5);
}

int main()
{
    float p1, p2, p3, r1, r2, r3, nota1 = 0, nota2 = 0, nota3 = 0, frequencia;
    int notafinal = 0;

    printf("Entre com P1 e R1: ");
    scanf("%f %f", &p1, &r1);

    printf("Entre com P2 e R2: ");
    scanf("%f %f", &p2, &r2);

    printf("Entre com P3 e R3: ");
    scanf("%f %f", &p3, &r3);

    printf("Entre com a frequência (%%): ");
    scanf("%f", &frequencia);

    nota1 = (r1 == -1) ? p1 : maximo(p1, r1);
    nota2 = (r2 == -1) ? p2 : maximo(p2, r2);
    nota3 = (r3 == -1) ? p3 : maximo(p3, r3);

    nota1 = arredonda(nota1);
    nota2 = arredonda(nota2);
    nota3 = arredonda(nota3);

    notafinal = arredonda(media(nota1, nota2, nota3));

    if (frequencia < 75.0)
    {
        notafinal = 0;
    }

    printf("Resultado final: %d\n", notafinal);

    if (frequencia < 75.0)
    {
        printf("Situação: reprovado\n");

        return 0;
    }

    if (notafinal < 6)
    {
        printf("Situação: reprovado\n");
    }
    else
    {
        printf("Situação: aprovado\n");
    }

    return 0;
}