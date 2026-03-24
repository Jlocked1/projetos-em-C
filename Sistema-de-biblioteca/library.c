#include <stdio.h>  // Funções de entrada e saída
#include <stdlib.h> // Funções utilitárias
#include <string.h> // Manipular strings

// Constantes globais
#define MAX_LIVROS 10
#define TAM_STRING 100
#define MAX_EMPRESTIMOS 100 // Nova constante para empréstimos de livros

// Estrutura para representar um livro
typedef struct
{
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel; // Uma flag para sinalizar se o livro está disponível '1' ou não '0'
} Livro;

// Struct para informações do empréstimo
typedef struct
{
    int indiceLivro;
    char nomeUsuario[TAM_STRING];
} Emprestimo;

// Funções protótipos
void cadastrarLivros(Livro *biblioteca, int *totalLivros);
void listarLivros(Livro *biblioteca, int totalLivros);
void realizarEmprestimo(Livro *biblioteca, int totalLivros, Emprestimo *emprestimo, int *totalEmprestimos);
void listarEmprestimo(Livro *biblioteca, Emprestimo *emprestimo, int totalEmprestimos);
void limparMemoria(Livro *biblioteca, Emprestimo *emprestimo);
void removeBuffer();

int main()
{
    // ALOCAÇÃO DINÂMICA usando ponteiros
    Livro *biblioteca;
    Emprestimo *emprestimo;

    // Usamos calloc(num_elementos, tamanho_de_cada_livro) para array de livros
    // A memória inicializa com zero, ou seja, a variavel disponivel já fica com o valor 0
    biblioteca = (Livro *)calloc(MAX_LIVROS, sizeof(Livro));

    // Usamos malloc para array de emprestimo malloc(quantidade_de_memória_bytes)
    emprestimo = (Emprestimo *)malloc(MAX_EMPRESTIMOS * sizeof(Emprestimo));

    // Verificar se os ponteiros não estão apontando para algum lugar NULO
    if (biblioteca == NULL || emprestimo == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return 1; // retorna erro
    }

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;

    do
    {
        printf("===========================\n");
        printf("Biblioteca - Menu\n");
        printf("===========================\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Listar Livros\n");
        printf("3. Realizar emprestimos\n");
        printf("4. Listar emprestimos\n");
        printf("0. Sair\n");
        printf("---------------------------\n");
        printf("Escolha uma opção: ");

        scanf("%d", &opcao);
        removeBuffer(); // Limpar o buffer após ler a opção

        switch (opcao)
        {
        case 0:
            printf("Saindo do programa. Até logo!\n");
            break;
        case 1:
            cadastrarLivros(biblioteca, &totalLivros);
            break;

        case 2:
            listarLivros(biblioteca, totalLivros);
            break;
        case 3:
            realizarEmprestimo(biblioteca, totalLivros, emprestimo, &totalEmprestimos);
            break;
        case 4:
            listarEmprestimo(biblioteca, emprestimo, totalEmprestimos); 
            break;
        default:
            printf("Opcao invalida!\n");
            printf("Pressione Enter para continuar...");
            getchar(); // Esperar o usuário pressionar Enter
        }

    } while (opcao != 0);

    limparMemoria(biblioteca, emprestimo);

    return 0;
}

void cadastrarLivros(Livro *biblioteca, int *totalLivros)
{
    if (*totalLivros < MAX_LIVROS)
    {
        int indice = *totalLivros; // Usa uma variavel para guardar o valor do ponteiro

        printf("Digite o nome do livro: ");
        fgets(biblioteca[indice].nome, TAM_STRING, stdin);

        printf("Digite o autor do livro: ");
        fgets(biblioteca[indice].autor, TAM_STRING, stdin);

        printf("Digite a editora do livro: ");
        fgets(biblioteca[indice].editora, TAM_STRING, stdin);

        // Remover nova linha
        biblioteca[indice].nome[strcspn(biblioteca[indice].nome, "\n")] = '\0';
        biblioteca[indice].autor[strcspn(biblioteca[indice].autor, "\n")] = '\0';
        biblioteca[indice].editora[strcspn(biblioteca[indice].editora, "\n")] = '\0';

        printf("Digite a edição do livro: ");
        scanf("%d", &biblioteca[indice].edicao);
        removeBuffer(); // Limpar o buffer após ler a edição

        biblioteca[indice].disponivel = 1; // Marca o livro como disponível

        (*totalLivros)++;
        printf("Livro cadastrado com sucesso!\n");
    }
    else
    {
        printf("Capacidade máxima de livros atingida!\n");
    }

    printf("Pressione Enter para continuar...");
    getchar(); // Esperar o usuário pressionar Enter
}

void listarLivros(Livro *biblioteca, int totalLivros)
{
    if (totalLivros == 0)
    {
        printf("Nenhum livro cadastrado!\n");
    }
    else
    {
        printf("Livros cadastrados:\n");
        for (int i = 0; i < totalLivros; i++)
        {
            printf("---------------------------\n");
            printf("Livro %d:\n", i + 1);
            printf("Nome: %s\n", biblioteca[i].nome);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("Editora: %s\n", biblioteca[i].editora);
            printf("Edição: %d\n", biblioteca[i].edicao);
            printf("Disponível: %s\n", biblioteca[i].disponivel ? "Sim" : "Não");
        }
        printf("---------------------------\n");
    }

    printf("Pressione Enter para continuar...");
    getchar(); // Esperar o usuário pressionar Enter
}

void realizarEmprestimo(Livro *biblioteca, int totalLivros, Emprestimo *emprestimo, int *totalEmprestimos)
{
    printf("--- Realizar Emprestimo ---\n\n");

    if (*totalEmprestimos >= MAX_EMPRESTIMOS)
    {
        printf("Limite de emprestimos atingido!\n");
    }
    else
    {
        int indicesDisponiveis[MAX_LIVROS];
        int countDisponiveis = 0;
        printf("Livros disponiveis:\n");
        for (int i = 0; i < totalLivros; i++)
        {
            if (biblioteca[i].disponivel)
            {
                printf("%d - %s\n", countDisponiveis + 1, biblioteca[i].nome);
                indicesDisponiveis[countDisponiveis] = i;
                countDisponiveis++;
            }
        }
        if (countDisponiveis == 0)
        {
            printf("Nenhum livro para emprestimo\n");
        }
        else
        {
            printf("\nDigite o numero do livro que deseja emprestar: ");
            int numLivro;
            scanf("%d", &numLivro);
            removeBuffer();
            if (numLivro >= 1 && numLivro <= countDisponiveis)
            {
                int indice = indicesDisponiveis[numLivro - 1];
                printf("Digite o nome do usuario que está adquirindo o livro: ");
                fgets(emprestimo[*totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
                emprestimo[*totalEmprestimos].nomeUsuario[strcspn(emprestimo[*totalEmprestimos].nomeUsuario, "\n")] = '\0';
                emprestimo[*totalEmprestimos].indiceLivro = indice;
                biblioteca[indice].disponivel = 0;
                (*totalEmprestimos)++;
                printf("\nEmprestimo realizado com sucesso!\n");
            }
            else
            {
                printf("\nNumero invalido\n");
            }
        }
    }
    printf("\nPressione Enter para continuar...");
    getchar();
}

void listarEmprestimo(Livro *biblioteca, Emprestimo *emprestimo, int totalEmprestimos)
{
    printf("--- Listar Emprestimos ---\n\n");
    if (totalEmprestimos == 0)
    {
        printf("Nenhum emprestimo realizado\n");
    }
    else
    {
        for (int i = 0; i < totalEmprestimos; i++)
        {
            // Usa o indice armazenado no emprestimo para buscar o nome do do livro.
            int indiceLivro = emprestimo[i].indiceLivro;
            printf("------------------------------------\n");
            printf("EMPRESTIMO: %d\n", i + 1);
            printf("Livro: %s\n", biblioteca[indiceLivro].nome);
            printf("Usuario: %s\n", emprestimo[i].nomeUsuario);
        }
        printf("------------------------------------\n");
    }
    printf("Pressione Enter para continuar...");
    getchar();
}

void limparMemoria(Livro *biblioteca, Emprestimo *emprestimo) {
    free(biblioteca);
    free(emprestimo);

    printf("Memoria liberada para evitar vazamentos\n");
}

void removeBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}