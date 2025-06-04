#include <stdio.h>

int main()
{
    float imc, altura, peso;

    printf("Insira a altura em metros (ex: 1.74):\n");
    scanf("%f", &altura);
    printf("Insira o peso em kg (ex:80.0)\n");
    scanf("%f", &peso);

    imc = peso / (altura * altura);

    printf("IMC: %.2f kg/m²\n", imc);

    if (imc < 18.5)
    {
        printf("Classificação: Abaixo do peso\n");
    }
    else if (imc >= 18.5 && imc < 24.9)
    {
        printf("Classificação: Peso ideal\n");
    }
    else if (imc >= 24.9 && imc < 29.9)
    {
        printf("Classificação: Sobrepeso\n");
    }
    else if (imc >= 30 && imc < 34.9)
    {
        printf("Classificação: Obesidade Grau I\n");
    }
    else if (imc >= 35 && imc < 39.9)
    {
        printf("Classificação: Obesidade Grau II\n");
    }
    else
    {
        printf("Classificação: Obesidade Grau III\n");
    }

    return 0;
}