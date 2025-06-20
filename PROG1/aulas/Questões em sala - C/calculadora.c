#include <stdio.h>

int main()
{

    float n1, n2, resultado;
    char operacao;

    printf("Entre com a expressão: ");
    scanf("%f %c %f", &n1, &operacao, &n2);
    if (n2 == 0)
    {
        printf("Erro: Não é possível dividir por zero\n");
        return 1;
    }
    else
    {
        switch (operacao)
        {
        case '+':
            resultado = n1 + n2;
            break;
        case '-':
            resultado = n1 - n2;
            break;
        case '*':
            resultado = n1 * n2;
            break;
        case '/':
            resultado = n1 / n2;
            break;
        default:
            printf("Erro: Operação desconhecida\n");
        }
        printf("Resultado: %.2f\n", resultado);

        return 0;
    }
}