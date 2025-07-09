#include <stdio.h>

int main()
{
    FILE *arquivo;
    arquivo = fopen("teste.txt", "w");
    fprintf(arquivo, "Testando.");
    fclose(arquivo);

    return 0;
}