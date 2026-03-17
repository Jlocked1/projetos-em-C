#include <stdio.h>
#include <stdlib.h> // Funções utilitárias
#include <string.h> // Manipular strings

// Constantes globais
#define MAX_LIVROS 10
#define TAM_STRING 100

// Estrutura para representar um livro
typedef struct
{
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
} Livro;

// Limpar buffer do scanf
void removeBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

int main()
{
    Livro biblioteca[MAX_LIVROS];
    int numLivros = 0;
    int opcao;

    do
    {

        printf("===========================\n");
        printf("Biblioteca - Menu\n");
        printf("===========================\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Listar Livros\n");
        printf("3. Sair\n");
        printf("---------------------------\n");
        printf("Escolha uma opção: ");

        scanf("%d", &opcao);
        removeBuffer(); // Limpar o buffer após ler a opção

        switch (opcao)
        {
        case 1:
            if (numLivros < MAX_LIVROS)
            {
                printf("Digite o nome do livro: ");
                fgets(biblioteca[numLivros].nome, TAM_STRING, stdin);

                printf("Digite o autor do livro: ");
                fgets(biblioteca[numLivros].autor, TAM_STRING, stdin);

                printf("Digite a editora do livro: ");
                fgets(biblioteca[numLivros].editora, TAM_STRING, stdin);

                biblioteca[numLivros].nome[strcspn(biblioteca[numLivros].nome, "\n")] = '\0'; // Remover nova linha
                biblioteca[numLivros].autor[strcspn(biblioteca[numLivros].autor, "\n")] = '\0';
                biblioteca[numLivros].editora[strcspn(biblioteca[numLivros].editora, "\n")] = '\0';

                printf("Digite a edição do livro: ");
                scanf("%d", &biblioteca[numLivros].edicao);
                removeBuffer(); // Limpar o buffer após ler a edição

                numLivros++;
                printf("Livro cadastrado com sucesso!\n");
            }
            else
            {
                printf("Capacidade máxima de livros atingida!\n");
            }

            printf("Pressione Enter para continuar...");
            getchar(); // Esperar o usuário pressionar Enter
            break;

        case 2:
            if (numLivros == 0)
            {
                printf("Nenhum livro cadastrado!\n");
            }
            else
            {
                printf("Livros cadastrados:\n");
                for (int i = 0; i < numLivros; i++)
                {
                    printf("---------------------------\n");
                    printf("Livro %d:\n", i + 1);
                    printf("Nome: %s\n", biblioteca[i].nome);
                    printf("Autor: %s\n", biblioteca[i].autor);
                    printf("Editora: %s\n", biblioteca[i].editora);
                    printf("Edição: %d\n", biblioteca[i].edicao);
                }
                printf("---------------------------\n");
            }

            printf("Pressione Enter para continuar...");
            getchar(); // Esperar o usuário pressionar Enter
            break;
        case 3:
            printf("Saindo do programa. Até logo!\n");
            break;
        default:
            printf("Opcao invalida!\n");
            printf("Pressione Enter para continuar...");
            getchar(); // Esperar o usuário pressionar Enter
        }

    } while (opcao != 3);

    return 0;
}