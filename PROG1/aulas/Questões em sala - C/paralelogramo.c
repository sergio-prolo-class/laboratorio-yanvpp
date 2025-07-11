#include <stdio.h>
#include <math.h>

typedef struct
{
    float a;
    float b;
    float angulo;
}Paralelogramo;


int main(){

    Paralelogramo medida;

    float perimetro, area;

    printf("Entre com o ângulo (graus):\n");
    scanf ("%f", &medida.angulo);

    printf ("Entre com os lados:\n");
    scanf("%f %f", &medida.a, &medida.b);

    perimetro = (2*medida.a)+(2*medida.b);
    area = (medida.a*medida.b)*sin(medida.angulo * M_PI / 180);


    printf("Perímetro: %.2f\n", perimetro);
    printf("Área: %.2f\n", area);

    return 0;
}