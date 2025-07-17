#ifndef LIVRO_H
#define LIVRO_H

#include <stdbool.h>

// Structs
typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    int isbn;
    char titulo[100];
    char autor[100];
    Data data_inicio;
    Data data_fim;
    char comentario[1000];
} Livro;

// Funções de manipulação de livros
bool adicionar(Livro *livro, int indice);
void remover(Livro prateleira[], int total_de_livros);
void modificar(Livro prateleira[], int total_de_livros);
void listar(Livro prateleira[], int total_de_livros);
void info_livro(Livro prateleira[], int total_de_livros, int indice_do_livro);
void contar_livros(Livro prateleira[], int total_de_livros);

// Funções de arquivo e utilitários
bool salvar_livro(Livro *livro);
int carregar_livros(Livro prateleira[]);
bool verificar(char *titulo);
bool eh_data_valida(Data data);
bool pasta_existe(void);

#endif