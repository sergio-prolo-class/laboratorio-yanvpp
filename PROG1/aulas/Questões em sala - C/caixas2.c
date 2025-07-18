#include <stdio.h>

int main()
{
    float altura, largura, profundidade, area, volume, preco, quantidade; // Declaração de variáveis

    printf("Insira a altura da caixa:\n");
    scanf("%f", &altura);

    printf("Insira a largura da caixa:\n");
    scanf("%f", &largura);

    printf("Insira a profundidade de caixa\n");
    scanf("%f", &profundidade);

    printf("Insira o preço por metro quadrado:");
    scanf("%f", &preco);

    printf("Insira a quantidade de caixas:");
    scanf("%f", &quantidade);

    area = (2 * altura * largura) + (2 * altura * profundidade) + (2 * largura * profundidade);
    volume = (altura * largura * profundidade);

    printf("O preço por caixa é R$%.2f, e o preço total é R$%.2f", preco * area, preco * area * quantidade);

    return 0;
}