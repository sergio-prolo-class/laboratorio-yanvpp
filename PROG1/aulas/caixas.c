#include <stdio.h>

int main()
{
    float altura, largura, profundidade, area, volume; // Declaração de variáveis

    printf("Insira a altura da caixa:\n");
    scanf("%f", &altura);

    printf("Insira a largura da caixa:\n");
    scanf("%f", &largura);

    printf("Insira a profundidade de caixa\n");
    scanf("%f", &profundidade);

    area = (2 * altura * largura) + (2 * altura * profundidade) + (2 * largura * profundidade);
    volume = (altura * largura * profundidade);

    printf("A área é %.2fm² e o volume é %.3fm³", area, volume);

    return 0;
}