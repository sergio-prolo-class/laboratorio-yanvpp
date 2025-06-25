#include <stdio.h>

int main()
{
    float salario, bonus, valor_vendas, avaliacao_desempenho;
    printf("Insira o valor das vendas (R$):\n");
    scanf("%f", &valor_vendas);
    printf("Insira a nota da avaliação de desempenho (1-10):\n");
    scanf("%f", &avaliacao_desempenho);
    salario = 2000.00;

    if (valor_vendas >= 10000.00)
    {
        salario += salario * 0.07;
    }
    else
    {
        salario += (salario * 0.05);
    }
    if (avaliacao_desempenho >= 8)
    {
        bonus = salario + 500;
    }
    else
    {
        bonus = 0.0;
    }
    salario += bonus;
    printf("Remuneração: R$ %.2f\n", salario);

    return 0;
}