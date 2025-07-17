#include <stdio.h>     // Comandos básicos
#include <stdbool.h>   // Para booleano
#include <unistd.h>    // Para sleep()
#include <sys/stat.h>  // Para criar pastas
#include <dirent.h>    // Para opendir() e readdir()
#include <string.h>    // Para verificar a extensão do arquivo
#include <stdlib.h>
#include "livro.h"  // toda a lógica do meu código

bool eh_data_valida(Data data)
{
    int dias_por_mes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (data.ano % 4 == 0 && (data.ano % 100 != 0 || data.ano % 400 == 0)) {
        dias_por_mes[2] = 29;
    }

    if (data.mes < 1 || data.mes > 12)
        return false;

    return data.dia >= 1 && data.dia <= dias_por_mes[data.mes];
}

bool pasta_existe()  // verifica se a pasta já existe
{
    return access("Livros lidos", F_OK) == 0;
}

int duracao_leitura(Livro *livro)
{
    return (livro->data_fim.dia - livro->data_inicio.dia) + (livro->data_fim.mes - livro->data_inicio.mes) * 30 + (livro->data_fim.ano - livro->data_inicio.ano) * 365;
}

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

    FILE *arquivo = fopen(caminho, "wb");  // wb = write binary
    if (!arquivo) {
        perror("Erro ao abrir o arquivo para escrita.\n");
        sleep(1);
        printf("Voltando...");
        sleep(2);
        printf("\n");
        return false;
    }
    size_t escrito = fwrite(livro, sizeof(Livro), 1, arquivo);

    fclose(arquivo);

    return escrito == 1;
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

    printf("Entre com a data de início da leitura (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &livro->data_inicio.dia, &livro->data_inicio.mes, &livro->data_inicio.ano);

    if (!eh_data_valida(livro->data_inicio))  // verifica se a data é válida
    {
        while (!eh_data_valida(livro->data_inicio)) {
            printf("Data inválida, insira novamente: ");
            scanf("%d/%d/%d", &livro->data_inicio.dia, &livro->data_inicio.mes, &livro->data_inicio.ano);
        }
    }

    printf("Entre com a data de fim da leitura (DD/MM/AAAA): ");
    scanf("%d%*c%d%*c%d", &livro->data_fim.dia, &livro->data_fim.mes, &livro->data_fim.ano);

    if (!eh_data_valida(livro->data_fim))  // verifica se a data é válida
    {
        while (!eh_data_valida(livro->data_fim)) {
            printf("Data inválida, insira novamente: ");
            scanf("%d/%d/%d", &livro->data_fim.dia, &livro->data_fim.mes, &livro->data_fim.ano);
        }
    }

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

void remover(Livro prateleira[], int total_de_livros)
{
    int indice_para_remover;
    printf("|--Remover livro--|\n\n");

    if (total_de_livros == 1) {
        printf("Nenhum livro para remover.\n\n");
        sleep(2);
        return;
    }

    printf("0. Cancelar e voltar ao menu inicial\n");
    for (int i = 1; i < total_de_livros; i++) {
        if (strlen(prateleira[i].titulo) > 0) {
            printf("%d. %s\n", prateleira[i].isbn, prateleira[i].titulo);
        }
    }

    printf("\nSelecione o índice do livro que deseja remover: ");
    scanf("%d", &indice_para_remover);
    getchar();

    if (indice_para_remover == 0) {
        printf("Operação cancelada.\n\n");
        return;
    }

    if (indice_para_remover < 1 || indice_para_remover >= total_de_livros || strlen(prateleira[indice_para_remover].titulo) == 0) {
        printf("Índice inválido.\n\n");
        sleep(2);
        return;
    }

    int confirmacao;
    printf("\nVocê tem certeza que deseja remover permanentemente o livro '%s'?\n", prateleira[indice_para_remover].titulo);
    printf("1. Sim\n2. Não\nEscolha uma opção: ");
    scanf("%d", &confirmacao);
    getchar();

    if (confirmacao == 1) {
        char caminho_arquivo[250];
        sprintf(caminho_arquivo, "Livros lidos/%s.txt", prateleira[indice_para_remover].titulo);
        if (remove(caminho_arquivo) == 0) {
            prateleira[indice_para_remover].titulo[0] = '\0';
            printf("\nLivro removido com sucesso!\n\n");
        } else {
            perror("Erro ao tentar remover o arquivo");
        }
    } else {
        printf("\nRemoção cancelada.\n\n");
    }
    sleep(2);
}

void modificar(Livro prateleira[], int total_de_livros)
{
    int indice_para_modificar;
    printf("|--Modificar Livro--|\n\n");

    if (total_de_livros == 1) {
        printf("Nenhum livro para modificar.\n\n");
        sleep(2);
        return;
    }

    printf("Selecione o índice do livro que deseja modificar:\n");
    printf("0. Cancelar e voltar ao menu\n");
    for (int i = 1; i < total_de_livros; i++) {
        if (strlen(prateleira[i].titulo) > 0) {
            printf("%d. %s\n", prateleira[i].isbn, prateleira[i].titulo);
        }
    }

    printf("\nSua escolha: ");
    scanf("%d", &indice_para_modificar);
    getchar();

    if (indice_para_modificar == 0) {
        printf("Operação cancelada.\n\n");
        return;
    }

    if (indice_para_modificar < 1 || indice_para_modificar >= total_de_livros || strlen(prateleira[indice_para_modificar].titulo) == 0) {
        printf("Índice inválido.\n\n");
        sleep(2);
        return;
    }

    Livro *livro_alvo = &prateleira[indice_para_modificar];
    int escolha_campo;

    do {
        printf("Modificando o livro: '%s'\n\n", livro_alvo->titulo);
        printf("Qual campo você deseja alterar?\n");
        printf("1. Título\n2. Autor\n3. Data de início\n4. Data de fim\n5. Comentário\n0. Concluir modificações e voltar\n");
        printf("\nSua escolha: ");
        scanf("%d", &escolha_campo);
        getchar();

        char titulo_antigo[100];
        if (escolha_campo == 1) {
            strcpy(titulo_antigo, livro_alvo->titulo);
        }

        switch (escolha_campo) {
            case 1:
                printf("Digite o novo título: ");
                scanf(" %[^\n]", livro_alvo->titulo);
                livro_alvo->titulo[strcspn(livro_alvo->titulo, "\n")] = '\0';
                break;
            case 2:
                printf("Digite o novo autor: ");
                scanf(" %[^\n]", livro_alvo->autor);
                break;
            case 3: /* Lógica de data */ break;
            case 4: /* Lógica de data */ break;
            case 5:
                printf("Digite o novo comentário: ");
                scanf(" %[^\n]", livro_alvo->comentario);
                break;
            case 0: printf("Modificações concluídas.\n"); break;
            default: printf("Opção inválida.\n"); sleep(1);
        }

        if (escolha_campo >= 1 && escolha_campo <= 5) {
            if (escolha_campo == 1) {
                char caminho_antigo[250];
                sprintf(caminho_antigo, "Livros lidos/%s.txt", titulo_antigo);
                remove(caminho_antigo);
            }
            if (salvar_livro(livro_alvo)) {
                printf("\nAlteração salva com sucesso!\n");
            } else {
                printf("\nERRO: Não foi possível salvar a alteração.\n");
            }
            sleep(2);
        }
    } while (escolha_campo != 0);

    printf("Retornando ao menu principal...\n\n");
    sleep(1);
}

void info_livro(Livro prateleira[], int total_de_livros, int indice_do_livro)  // recebe o índice do livro escolhido
{
    Livro *livro = &prateleira[indice_do_livro];

    printf("|--Informações do livro--|\n");
    printf("\n");

    printf("Título: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Data de início: %02d/%02d/%04d\n", livro->data_inicio.dia, livro->data_inicio.mes, livro->data_inicio.ano);
    printf("Data de fim: %02d/%02d/%04d\n", livro->data_fim.dia, livro->data_fim.mes, livro->data_fim.ano);
    printf("Duração da leitura: %d dias\n", duracao_leitura(livro));
    printf("Comentário: %s\n", livro->comentario);

    printf("\nPressione a tecla 'Enter' para retornar ao menu inicial...\n");
    getchar();
    printf("Retornando ao menu inicial...\n");
    sleep(2);
    printf("\n");
}

void listar(Livro prateleira[], int total_de_livros)
{
    int escolha;

    // lista de nomes com índices ao lado:

    printf("\n|--Lista de livros--|\n");
    printf("\n");
    sleep(2);

    if (total_de_livros == 1) {
        printf("Nenhum livro cadastrado.\n");
        sleep(2);
        printf("Retornando ao menu...\n");
        sleep(1);
        printf("\n");
        return;
    }

    printf("0. Retornar ao menu\n");

    for (int i = 1; i < total_de_livros; i++) {
        if (strlen(prateleira[i].titulo) > 0) {
            printf("%d. %s\n", prateleira[i].isbn, prateleira[i].titulo);
        }
    }

    printf("\nSelecione uma opção: ");
    scanf("%d", &escolha);
    getchar();
    printf("\n");

    if (escolha == 0) {
        printf("Retornando ao menu inicial...\n");
        sleep(2);
        printf("\n");
        return;
    } else if (escolha > 0 && escolha < total_de_livros && strlen(prateleira[escolha].titulo) > 0) {
        sleep(1);
        info_livro(prateleira, total_de_livros, escolha);  // Passa o endereço do livro escolhido no array
    } else {
        printf("Índice inválido!\n");
        sleep(2);
    }
}

int carregar_livros(Livro prateleira[])
{
    DIR *d;
    struct dirent *dir;
    int max_indice = 0;

    d = opendir("Livros lidos");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (strstr(dir->d_name, ".txt") != NULL) {
                char caminho_completo[250];
                sprintf(caminho_completo, "Livros lidos/%s", dir->d_name);

                FILE *arquivo = fopen(caminho_completo, "rb");  // rb = read binary
                if (arquivo) {
                    Livro livro_temp;
                    if (fread(&livro_temp, sizeof(Livro), 1, arquivo) == 1) {
                        prateleira[livro_temp.isbn] = livro_temp;
                        if (livro_temp.isbn > max_indice) {
                            max_indice = livro_temp.isbn;
                        }
                    }
                    fclose(arquivo);
                }
            }
        }
        closedir(d);
    }
    return max_indice + 1;
}

void contar_livros(Livro prateleira[], int total_de_livros)
{
    int contador = 0;

    for (int i = 1; i < total_de_livros; i++) {
        if (strlen(prateleira[i].titulo) > 0) {
            contador++;
        }
    }

    printf("\n|--Quantos livros já li?--|\n");

    if (contador == 0) {
        printf("Você ainda não cadastrou nenhum livro.\n");
    } else if (contador == 1) {
        printf("\nVocê já leu 1 livro. Parabéns!\n");
    } else {
        printf("\nVocê já leu um total de %d livros. Continue assim!\n", contador);
    }
    printf("\nPressione a tecla 'Enter' para retornar ao menu inicial...\n");
    getchar();
    printf("Retornando ao menu inicial...\n");
    sleep(2);
    printf("\n");
}