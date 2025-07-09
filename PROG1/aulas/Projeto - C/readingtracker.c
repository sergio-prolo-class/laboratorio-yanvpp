#include <stdio.h>    // Comandos básicos
#include <string.h>   // Para strings
#include <stdbool.h>  // Para booleano
#include <unistd.h>   // Para sleep()

typedef struct
{
    int dia, mes, ano;
} Data;

typedef struct
{
    char titulo;
    char autor;
    Data data_inicio;
    Data data_fim;
    char comentario;
} Livro;

void cadastrar(Livro *livro)
{
    printf("|--Cadastrar--|\n");
    printf("Entre com o título do livro: ");
    scanf("%s", &livro->titulo);

    printf("Entre com o nome do autor: ");
    scanf("%s", &livro->autor);

    printf("Entre com a data de início da leitura (DD/MM/AAA): ");
    scanf("%d/%d/%d", &livro->data_inicio.dia, &livro->data_inicio.mes, &livro->data_inicio.ano);

    printf("Entre com a data de fim da leitura (DD/MM/AAA): ");
    scanf("%d/%d/%d", &livro->data_fim.dia, &livro->data_fim.mes, &livro->data_fim.ano);

    printf("Entre com os seus comentários sobre o livro: ");
    scanf("%s", &livro->comentario);

    // Cadastro das informações recebidas em um arquivo:

    printf("Livro cadastrado com sucesso, retornando para o menu inicial!\n\n");

    sleep(2);  // Aguarda 2 segundos para voltar ao menu inical
}

int main()
{
    int escolha;
    Livro livro;

    printf("|--READING TRACKER--|\n");
    printf("Selecione uma opção:\n");
    printf("1. Cadastrar livro\n");
    printf("2. Consultar livros\n");
    printf("3. Remover livro\n");
    printf("4. Sair\n");

    scanf("%d", &escolha);

    if (escolha == 4) {
        return 0;
    } else {
        switch (escolha) {
            case 1:
                cadastrar(&livro);
                printf("|--READING TRACKER--|\n");
                printf("Selecione uma opção:\n");
                printf("1. Cadastrar livro\n");
                printf("2. Consultar livros\n");
                printf("3. Remover livro\n");
                printf("4. Sair\n");  // Precisa retornar para o começo do int main(), não imprimir novamente aqui
                break;
        }
    }
}