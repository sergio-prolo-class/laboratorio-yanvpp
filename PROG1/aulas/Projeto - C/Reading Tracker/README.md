# Reading Tracker - Gerenciador de Livros Lidos

## Sobre o Projeto

Reading Tracker é um sistema de gerenciamento de arquivos desenvolvido em C como projeto final para a disciplina de Programação I do curso de Engenharia de Telecomunicações do IFSC - Campus São José. [cite: 1, 2] O programa permite ao usuário catalogar os livros que já leu, armazenando as informações de forma persistente em arquivos.

O projeto aplica conceitos fundamentais de programação estruturada, incluindo manipulação de arquivos, uso de ponteiros, modularização com funções e criação de estruturas de dados. [cite: 7, 8]

## Funcionalidades

* **Adicionar Livro:** Cadastra um novo livro com título, autor, datas de início e fim da leitura e um comentário pessoal.
* **Listar Livros:** Exibe todos os livros cadastrados, permitindo visualizar suas informações detalhadas.
* **Modificar Livro:** Permite editar qualquer informação de um livro já cadastrado.
* **Remover Livro:** Apaga o registro de um livro permanentemente.
* **Contar Livros:** Mostra a quantidade total de livros lidos.
* **Persistência de Dados:** Todas as informações são salvas em uma pasta "Livros lidos", garantindo que os dados não sejam perdidos ao fechar o programa.

## Pré-requisitos

Para compilar e executar o projeto, você precisa de:
* Um compilador C, como o GCC.

## Como Compilar e Executar

1.  **Clone ou baixe o repositório.**
2.  **Abra um terminal** na pasta raiz do projeto (onde estão os arquivos `main.c`, `livro.c` e `livro.h`).
3.  **Compile os arquivos** com o seguinte comando:
    ```bash
    gcc main.c livro.c -o reading_tracker
    ```
4.  **Execute o programa:**
    * No Linux ou macOS:
        ```bash
        ./reading_tracker
        ```
    * No Windows:
        ```bash
        .\reading_tracker.exe
        ```

## Estrutura dos Arquivos

O código é organizado em três arquivos principais para melhor modularização:
* `main.c`: Contém a função `main`, responsável pelo menu principal e pelo fluxo geral do programa.
* `livro.h`: O arquivo de cabeçalho. Define as estruturas `Livro` e `Data` e declara os protótipos de todas as funções do sistema.
* `livro.c`: Contém a implementação (o código) de todas as funções declaradas em `livro.h`.