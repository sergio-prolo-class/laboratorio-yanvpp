#include <stdio.h>     // Comandos básicos
#include <stdbool.h>   // Para booleano
#include <unistd.h>    // Para sleep() e access()
#include <sys/stat.h>  // Para criar pastas
#include <dirent.h>    // Para opendir() e readdir()
#include <stdlib.h>

#define PRATELEIRA 101  // para ir de 1 a 100, sem preencher o índice 0

/*Array de structs para salvar cada arquivo em um índice*/

typedef struct
{
    int dia, mes, ano;
} Data;

typedef struct
{
    int isbn;
    char titulo[100];
    char autor[100];
    Data data_inicio;
    Data data_fim;
    char comentario[1000];
} Livro;

/*
bool bissexto(Livro *livro)
{
    return (livro->data_inicio.ano % 4 == 0 && livro->data_inicio.ano % 100 != 0) || (livro->data_inicio.ano % 400 == 0);
}

int num_dias(Livro *livro)
{
    switch (livro->data_inicio.mes) {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return bissexto(livro->data_inicio.ano) ? 29 : 28;
        default:
            return 31;
    }
}

bool eh_data_valida_i(Livro *livro)
{
    Livro livro;
    if (livro->data_inicio.mes < 1 || livro->data_inicio.mes > 12) {
        return false;
    }
    return 1 <= livro->data_inicio.dia && 1 <= num_dias(&livro->data_inicio);
}
    */

bool pasta_existe()  // verifica se a pasta já existe
{
    return access("Livros lidos", F_OK) == 0;
}

/*
int duracao_leitura(Livro)
{
    // adicionar cálculo referente à duração da leitura em dias
    return;  // retorna a duração da leitura em dias
};
*/

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

    // fprintf para imprimir a struct dentro do arquivo, não linha por linha

    fprintf(arquivo, "Título: %s\n", livro->titulo);
    fprintf(arquivo, "Autor: %s\n", livro->autor);
    fprintf(arquivo, "Data de início: %02d/%02d/%04d\n", livro->data_inicio.dia, livro->data_inicio.mes, livro->data_inicio.ano);
    fprintf(arquivo, "Data de fim: %02d/%02d/%04d\n", livro->data_fim.dia, livro->data_fim.mes, livro->data_fim.ano);
    // fprint(arquivo, "Duração da leitura: %d dias\n", duracao_leitura(Livro));
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

bool adicionar(Livro *livro, int indice)
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
        sleep(2);
        printf("\n");
        return false;
    }

    livro->isbn = indice;

    printf("Entre com o nome do autor: ");
    scanf(" %[^\n]", livro->autor);

    printf("Entre com a data de início da leitura (DD/MM/AAA): ");
    scanf("%d/%d/%d", &livro->data_inicio.dia, &livro->data_inicio.mes, &livro->data_inicio.ano);
    /*
        if (!eh_data_valida(&livro->data_inicio))  // verifica se a data é válida
        {
            while (!eh_data_valida(&livro->data_inicio)) {
                printf("Data inválida, insira novamente: ");
                scanf("%d/%d/%d", &livro->data_inicio.dia, &livro->data_inicio.mes, &livro->data_inicio.ano);
            }
        }
    */

    printf("Entre com a data de fim da leitura (DD/MM/AAA): ");
    scanf("%d/%d/%d", &livro->data_fim.dia, &livro->data_fim.mes, &livro->data_fim.ano);

    /*
    if (!eh_data_valida(&livro->data_fim))  // verifica se a data é válida
    {
        while (!eh_data_valida(&livro->data_fim)) {
            printf("Data inválida, insira novamente: ");
            scanf("%d/%d/%d", &livro->data_fim.dia, &livro->data_fim.mes, &livro->data_fim.ano);
        }
    }
*/

    printf("Entre com os seus comentários sobre o livro: ");
    scanf(" %[^\n]", livro->comentario);  // lê até uma quebra de linha

    // Cadastro das informações recebidas em um arquivo:

    if (!salvar_livro(livro)) {
        printf("Erro ao salvar o livro.\n");
        sleep(1);
        printf("Retornando ao menu inicial...\n");
        sleep(2);
        return false;
    } else {
        printf("Livro cadastrado com sucesso, retornando para o menu inicial!\n");
        sleep(2);  // Aguarda 2 segundos para voltar ao menu inical
        printf("\n");
        return true;
    }
}

/*
void remover(titulo)
{
    printf("|--Remover livro--|\n");
    printf("\nEntre com o título do livro para remover: ");
    scanf(" [%^\n]", &titulo);
    sleep(1);

    int escolha = 0;

    printf("\nVocê tem certeza que deseja remover o livro '%s' da sua lista?\n");
    printf("1. Sim\n");
    printf("2. Não\n");
    scanf("%d", &escolha);

    if (escolha == 2) {
        sleep(1);
        printf("Certo, o livro não foi removido.");
        sleep(1);
        printf("Voltando...");
        sleep(2);
        return;
    }
}
    */

void info_livro(Livro *livro)  // recebe o índice do livro escolhido
{
    // mostra as informações contidas no arquivo e mostra as opções

    printf("\n|--Opções--|\n");
    printf("1. Modificar informações\n");
    printf("2. Remover livro\n");
    printf("3. Voltar\n");

    int escolha;

    switch (escolha) {
        case 1:
            // modificar();
            break;
        /*case 2:
            remover();
            break;*/
        case 3:
            printf("\nRetornando...\n");
            sleep(2);
            return;
    }
}

/*
void listar(Livro livro)
{
    char nome_do_livro[100];
    int escolha;
    printf("\n|--Lista de livros--|\n");

    // aqui os nomes dos arquivos serão listados com o índice no lado

    printf("\nDigite '0' para retornar ao menu, ou o índice do livro para mais informações.");
    scanf("%d", &escolha);

    if (escolha == 0) {
        printf("Retornando ao menu inicial...");
        sleep(2);
        return;
    } else {
        info_livro(livro.isbn);
    }
}
    */

void contador()  // conta a quantidade de livros adicionados
{
}

int main()
{
    int escolha, indice = 1;
    Livro livro[PRATELEIRA];

    if (!pasta_existe()) {  // cria a pasta livros no computador
        mkdir("Livros lidos");
    }

    do {
        printf("|--READING TRACKER--|\n");
        printf("1. Adicionar livro\n");
        printf("2. Listar livros\n");
        printf("3. Quantos livros já li?\n");
        printf("4. Sair\n");
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
            /*case 2:
                listar(livro[PRATELEIRA]);
                break;
                /*case 3:
                quantidade(&livro);
                break;*/
            case 4:
                printf("Boa leitura!\n");
                sleep(1);
                printf("Encerrando programa...");
                sleep(2);
                return 0;
        }
    }

    while (escolha != 4);
}