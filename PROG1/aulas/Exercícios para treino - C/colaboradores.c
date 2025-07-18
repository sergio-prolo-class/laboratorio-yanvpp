#include <stdio.h>

int main()
{
    int salario = 0, horas = 0, pagamento = 0, total = 0;

    for (int i = 1; i <= 3; i++) {
        printf("Entre com o salário e as horas trabalhadas: ");
        scanf("%d %d", &salario, &horas);

        pagamento = salario * horas;

        printf("Pagamento: %d\n", pagamento),

            total += pagamento;
    }

    printf("Total: %d\n", total);

    return 0;
}