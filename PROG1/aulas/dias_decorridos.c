#include <stdio.h>
#include <stdbool.h>

bool bissexto(int ano)
{
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int main()
{
    int dia, mes, ano, dias_no_mes, dias_decorridos;

    printf("Insira a data (dd/mm/aaaa):");
    scanf("%d/%d/%d", &dia, &mes, &ano);

    switch (mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        dias_no_mes = 31;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        dias_no_mes = 30;
        break;

    case 2:
        dias_no_mes = bissexto(ano) ? 29 : 28;
        break;

    default:
        dias_no_mes = 0;
    }

    if ((mes <= 12 && mes >= 1) && (dia >= 1 && dia <= dias_no_mes))
    {
        if (bissexto == 1)
        {
            switch (mes)
            {
            case 1:
                dias_decorridos = dia;
                break;

            case 2:
                dias_decorridos = 31 + dia;
                break;

            case 3:
                dias_decorridos = 31 + 29 + dia;

            case 4:
                dias_decorridos = 31 + 29 + 31 + dia;

            default:
                break;
            }
        }
    }

    return 0;
}