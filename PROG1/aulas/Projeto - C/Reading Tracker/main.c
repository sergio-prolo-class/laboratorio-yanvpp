#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "livro.h"  // toda a lógica do meu código

#define PRATELEIRA 101  // para ir de 1 a 100, sem preencher o índice 0

int main()
{
    int escolha, indice;
    Livro livro[PRATELEIRA] = {0};

    if (!pasta_existe()) {  // cria a pasta livros no computador
        mkdir("Livros lidos");
    }

    indice = carregar_livros(livro);

    do {
        printf("|--READING TRACKER--|\n");
        printf("1. Adicionar livro\n");
        printf("2. Listar livros\n");
        printf("3. Quantos livros já li?\n");
        printf("4. Remover livro\n");
        printf("5. Modificar livro\n");
        printf("6. Sair\n");
        printf("\nSelecione uma opção: ");

        scanf("%d", &escolha);
        getchar();

        printf("\n");

        switch (escolha) {
            case 1:
                if (adicionar(&livro[indice], indice)) {
                    indice++;
                }
                break;
            case 2:
                listar(livro, indice);
                break;
            case 3:
                contar_livros(livro, indice);
                break;
            case 4:
                remover(livro, indice);
                break;
            case 5:
                modificar(livro, indice);
                break;
            case 6:
                printf("Boa leitura!\n");
                sleep(1);
                printf("Encerrando programa...");
                sleep(2);
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
                sleep(1);
                printf("\n");
        }
    } while (escolha != 6);

    return 0;
}