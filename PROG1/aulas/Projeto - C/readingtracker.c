#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char titulo;
    char autor;
    int data_inicio[3];
    int data_fim[3];
    char comentario;
} Livro;

int tela_inicial(int *escolha)
{
    int *escolha;

    printf("READING TRACKER\n");
    printf("Selecione uma opção:\n");
    printf("1. Cadastrar livro\n");
    printf("2. Consultar livros\n");
    printf("3. Remover livro\n");
    printf("4. Sair");

    scanf("%d", escolha);

    if (escolha == 4) {
        return 0;
    } else {
        return 1;
    }
}

void cadastrar()
{
}

int main()
{
    int escolha;

    tela_inicial(&escolha);

    return 0;
}