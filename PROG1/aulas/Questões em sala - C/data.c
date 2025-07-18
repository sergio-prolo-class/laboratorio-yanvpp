#include <stdio.h>
#include <string.h>

int Bissexto(int ano)
{
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}
int main()
{

    int dia, mes_num, ano, dias_no_mes;
    char mes_text[20];

    printf("Insira a data (dd/mm/aaaa):\n");
    scanf("%d/%d/%d", &dia, &mes_num, &ano);

    switch (mes_num)
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
        dias_no_mes = Bissexto(ano) ? 29 : 28;
        break;

    default:
        dias_no_mes = 0;
    }

    if ((mes_num <= 12 && mes_num >= 1) && (dia >= 1 && dia <= dias_no_mes))
    {
        switch (mes_num)
        {
        case 1:
            strcpy(mes_text, "January");
            break;

        case 2:
            strcpy(mes_text, "February");
            break;

        case 3:
            strcpy(mes_text, "March");
            break;

        case 4:
            strcpy(mes_text, "April");
            break;

        case 5:
            strcpy(mes_text, "May");
            break;

        case 6:
            strcpy(mes_text, "June");
            break;

        case 7:
            strcpy(mes_text, "July");
            break;

        case 8:
            strcpy(mes_text, "August");
            break;

        case 9:
            strcpy(mes_text, "September");
            break;

        case 10:
            strcpy(mes_text, "October");
            break;

        case 11:
            strcpy(mes_text, "November");
            break;

        case 12:
            strcpy(mes_text, "December");
            break;

        default:
            printf("ERRO: Mês não reconhecido.\n");
        }
        switch (dia)
        {
        case 1:
        case 21:
        case 31:
            printf("%s %dst, %d\n", mes_text, dia, ano);
            break;

        case 2:
        case 22:
            printf("%s %dnd, %d\n", mes_text, dia, ano);
            break;

        case 3:
        case 23:
            printf("%s %drd, %d\n", mes_text, dia, ano);
            break;
        default:
            printf("%s %dth, %d\n", mes_text, dia, ano);
        }
    }
    else
    {
        printf("Data inválida\n");
    }
    return 0;
}