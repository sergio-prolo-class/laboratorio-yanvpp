#include <stdio.h>
#include <math.h>

typedef struct {
    int ladoa;
    int ladob;
    int graus;
} Paralelogramo;

typedef struct
{
    float perimetro;
    float area;
} Resultado;

Paralelogramo perarea()
{
    Resultado obj1;
    Resultado obj2;
    Paralelogramo medida;
    Paralelogramo medida2;

    obj1.perimetro = (2 * medida.ladoa) + (2 * medida.ladob);

    obj1.area = (medida.ladoa * medida.ladob) * sin(medida.graus * 3.141551 / 180);

    printf("Perímetro do primeiro: %.2f\nÁrea do primeiro: %.2f\n", obj1.perimetro, obj1.area);

    obj2.perimetro = (2 * medida2.ladoa) + (2 * medida2.ladob);

    obj2.area = (medida2.ladoa * medida2.ladob) * sin(medida2.graus * 3.141551 / 180);

    printf("Perímetro do segundo: %.2f\nÁrea do segundo: %.2f\n", obj2.perimetro, obj2.area);
}

int main()
{
    Paralelogramo medida;
    Paralelogramo medida2;

    printf("Entre com os lados do primeiro: ");
    scanf("%d %d", &medida.ladoa, &medida.ladob);
    printf("Entre com os lados do segundo: ");
    scanf("%d %d", &medida2.ladoa, &medida2.ladob);

    printf("Entre com o ângulo do primeiro (graus): ");
    scanf("%d", &medida.graus);

    printf("Entre com o ângulo do segundo (graus): ");
    scanf("%d", &medida2.graus);

    perarea;

    return 0;
}