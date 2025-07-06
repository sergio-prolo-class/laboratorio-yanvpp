#include <stdio.h>
#include <stdbool.h>

bool bissexto(int ano)
{
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int num_dias(int mes, int ano)
{
    switch (mes) {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return bissexto(ano) ? 29 : 28;
        default:
            return 31;
    }
}

bool eh_data_valida(int dia, int mes, int ano)
{
    if (mes < 1 || mes > 12) {
        return false;
    }
    return 1 <= dia && dia <= num_dias(mes, ano);
}

int dias_decorridos(int dia, int mes, int ano)
{
    int num = dia;

    switch (mes) {
        case 12: num += num_dias(11, ano);
        case 11: num += num_dias(10, ano);
        case 10: num += num_dias(9, ano);
        case 9: num += num_dias(8, ano);
        case 8: num += num_dias(7, ano);
        case 7: num += num_dias(6, ano);
        case 6: num += num_dias(5, ano);
        case 5: num += num_dias(4, ano);
        case 4: num += num_dias(3, ano);
        case 3: num += num_dias(2, ano);
        case 2: num += num_dias(1, ano);
    }
    return num;
}

int main()
{
    int dia, mes, ano;

    printf("Insira a data (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &dia, &mes, &ano);

    if (!eh_data_valida(dia, mes, ano)) {
        printf("Data inválida!\n");
        return 1;
    }
    printf("Dias decorridos: %d\n", dias_decorridos(dia, mes, ano));

    return 0;
}