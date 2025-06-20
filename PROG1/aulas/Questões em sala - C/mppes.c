#include <stdio.h>
#include <math.h>

int main()
{
    float altm;
    int pes, polegadas, altp;

    printf("Insira a altura em metros (ex: 1.70)");
    scanf("%f", &altm);

    altp = (int)(altm / 0.0254);
    pes = altp / 12;
    polegadas = altp % 12;

    printf("A altura em pés é: %d.%d pés\n", pes, polegadas);

    return 0;
}