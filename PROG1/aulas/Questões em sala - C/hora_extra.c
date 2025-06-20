#include <stdio.h>

int main()
{
    float horas, pagamento;
    printf("Insira as horas trabalhadas:");
    scanf("%f", &horas);
    pagamento = (50.0 * horas);
    if (horas > 8.0)
    {
        pagamento += 25 * (horas - 8);
    }
    printf("Pagamento: %.2f\n", pagamento);

    return 0;
}