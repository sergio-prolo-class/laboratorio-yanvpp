#include <stdio.h>

int main()
{
    char info[100];

    FILE *arquivo;
    arquivo = fopen("teste.txt", "r");
    fscanf(arquivo, "%s", &info);

    while (fgets(info, 100, arquivo) != NULL) {
        printf("%s", info);
    }

    int linha = 4;

    for(int i = 1; i<linha; i++){
        
    }

    fclose(arquivo);

    return 0;
}