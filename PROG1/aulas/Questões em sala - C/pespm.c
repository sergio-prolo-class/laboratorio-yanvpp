#include <stdio.h>
#include <math.h>

int main()
{
    float alturam;
    int polegadas, pes, alturap;

    printf("Insira a altura em pés + polegadas (ex: 5 10):");
    scanf("%d"
          "%d",
          &pes, &polegadas);

    alturap = pes * 12;
    alturap += polegadas;

    alturam = (float)(alturap * 0.0254);

    printf("A altura em pés é %.2f m\n", alturam);

    return 0;
}