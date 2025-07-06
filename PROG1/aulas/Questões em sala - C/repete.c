#include <stdio.h>
#include <string.h>

int repete_palavra(char orig[], int n, char dest[])
{

    while (n > 0)
    {
        strcpy(dest, orig);
        n--;
    }

    return strlen(dest);
}

int main()
{
    char palavra[11], dest[] = "";
    int vezes;

    printf("Entre com uma palavra: ");
    scanf("%s", palavra);

    printf("Entre com o número de repetições: ");
    scanf("%d", &vezes);

    int tamanho = repete_palavra(palavra, vezes, dest);

    printf("Resultado: %s\n", dest);
    printf("Tamanho: %d\n", tamanho);

    return 0;
}