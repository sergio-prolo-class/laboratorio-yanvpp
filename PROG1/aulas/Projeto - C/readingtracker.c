#include <stdio.h>     // Comandos básicos
#include <string.h>    // Para strings
#include <stdbool.h>   // Para booleano
#include <unistd.h>    // Para sleep() e access()
#include <sys/stat.h>  // Para criar pastas
#include <dirent.h>    // Para opendir() e readdir()

typedef struct
{
    int dia, mes, ano;
} Data;

typedef struct
{
    char titulo[100];
    char autor[100];
    Data data_inicio;
    Data data_fim;
    char comentario[1000];
} Livro;

bool pasta_existe()  // verifica se a pasta já existe
{
    return access("Livros lidos", F_OK) == 0;
}

void duracao_leitura(Livro *data_inicio, Livro *data_fim) {
    // adicionar cálculo referente à duração da leitura em dias
};

bool verificar(char *titulo)  // retorna true se o arquivo existe
{
    char caminho[150];

    sprintf(caminho, "Livros lidos/%s.txt", titulo);
    return access(caminho, F_OK) == 0;
}

bool salvar_livro(Livro *livro)
{
    char caminho[150];

    sprintf(caminho, "Livros lidos/%s.txt", livro->titulo);

    FILE *arquivo = fopen(caminho, "w");
    if (!arquivo) {
        return false;
    }

    fprintf(arquivo, "Título: %s\n", livro->titulo);
    fprintf(arquivo, "Autor: %s\n", livro->autor);
    fprintf(arquivo, "Data de início: %02d/%02d/%04d\n", livro->data_inicio.dia, livro->data_inicio.mes, livro->data_inicio.ano);
    fprintf(arquivo, "Data de fim: %02d/%02d/%04d\n", livro->data_fim.dia, livro->data_fim.mes, livro->data_fim.ano);
    fprintf(arquivo, "Comentário: %s", livro->comentario);

    fclose(arquivo);

    return true;

    /*como relaciono cada elemento do struct com uma linha do arquivo?
    também quero que o FILE salve os arquivo, cada qual com seu nome.txt
    para facilitar a localização dentro da pasta 'Livros lidos'*/

    /*também preciso adicionar o void verificar() aqui para, antes de adicionar
    um novo livro, verificar se o mesmo título já está presente na pasta, porém,
    preciso entender como relacionar cada elemento do struct com uma linha do file*/
}

void adicionar(Livro *livro)
{
    printf("|--Cadastrar--|\n");
    printf("\n");
    sleep(1);

    printf("Entre com o título do livro: ");
    scanf(" %[^\n]", livro->titulo);

    if (verificar(livro->titulo)) {
        printf("Este livro já foi cadastrado.\n");
        sleep(1);
        printf("Retornando ao menu inicial...\n");
        printf("\n");
        sleep(2);
        return;
    }

    printf("Entre com o nome do autor: ");
    scanf(" %[^\n]", livro->autor);

    printf("Entre com a data de início da leitura (DD/MM/AAA): ");
    scanf("%d/%d/%d", &livro->data_inicio.dia, &livro->data_inicio.mes, &livro->data_inicio.ano);

    printf("Entre com a data de fim da leitura (DD/MM/AAA): ");
    scanf("%d/%d/%d", &livro->data_fim.dia, &livro->data_fim.mes, &livro->data_fim.ano);

    printf("Entre com os seus comentários sobre o livro: ");
    scanf(" %[^\n]", livro->comentario);  // lê até uma quebra de linha

    // Cadastro das informações recebidas em um arquivo:

    if (!salvar_livro(livro)) {
        printf("Erro ao salvar o livro.\n");
        sleep(1);
        printf("Retornando ao menu inicial...\n");
        sleep(2);
    }

    printf("Livro cadastrado com sucesso, retornando para o menu inicial!\n\n");

    sleep(2);  // Aguarda 2 segundos para voltar ao menu inical
}

void consultar(Livro *livro)
{
    char nome_do_livro[100];

    // aqui preciso de uma lista do título dos livros adicionados,

    // como faço para relacionar cada elemento do struct com uma linha do arquivo?

    // criar struct para gerar .txt e for para percorrer o array de structs

    printf("Entre com o nome do livro: ");
    scanf(" %[^/n]", nome_do_livro);
}

void contador()  // conta a quantidade de livros adicionados
{
}

int main()
{
    int escolha;
    Livro livro;
    Livro biblioteca[100];

    if (!pasta_existe()) {  // cria a pasta livros no computador
        mkdir("Livros lidos");
    }

    do {
        printf("|--READING TRACKER--|\n");
        printf("1. Adicionar livro\n");
        printf("2. Consultar livros\n");
        printf("3. Quantos livros já li?\n");
        printf("4. Remover livro\n");
        printf("5. Sair\n");
        printf("\nSelecione uma opção: ");

        scanf("%d", &escolha);
        getchar();

        printf("\n");

        switch (escolha) {
            case 1:
                adicionar(&livro);
                escolha = 0;
                break;
            case 2:
                consultar(&livro);
                escolha = 0;
                break;
                /*case3:
                remover(&livro);
                escolha = 0;
                break;*/
            case 5:
                printf("Boa leitura!\n");
                sleep(1);
                printf("Encerrando programa...");
                sleep(2);
                return 0;
        }
    } while (escolha != 5);
}