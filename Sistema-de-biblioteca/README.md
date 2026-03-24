# Sistema de Biblioteca

Este é um projeto de Sistema de Biblioteca em linha de comando. O objetivo é entender conceitos iniciais antes de construir estruturas de dados usando a linguagem C. O projeto contém conceitos sobre structs, ponteiros, alocação de memória dinâmica, passagem por referência/valor e modularização de código.

## Funcionalidades

- Cadastro de livro com nome, autor, editora e edição
- Listagem de livros com status de disponibilidade
- Empréstimo de livros com mapeamento de usuário
- Listagem de empréstimos realizados

## Estruturas de Dados

A struct `Livro` possui:
- `nome[TAM_STRING]`
- `autor[TAM_STRING]`
- `editora[TAM_STRING]`
- `edicao` (inteiro)
- `disponivel` (flag 1/0)

A struct `Emprestimo` possui:
- `indiceLivro` (índice no vetor biblioteca)
- `nomeUsuario[TAM_STRING]`

## Alocação de Memória

O projeto utiliza alocação dinâmica de memória:
- `biblioteca` é alocada com `calloc(MAX_LIVROS, sizeof(Livro))`
- `emprestimo` é alocada com `malloc(MAX_EMPRESTIMOS * sizeof(Emprestimo))`

A memória é liberada através da função `limparMemoria()` que chama `free()` antes de encerrar o programa.

## Ponteiros e Passagem por Referência

As funções `cadastrarLivros` e `realizarEmprestimo` recebem `int *totalLivros` e `int *totalEmprestimos` respectivamente. Isso permite que as funções modifiquem o valor original destas variáveis através de `(*totalLivros)++` e `(*totalEmprestimos)++`.

As estruturas são passadas como ponteiros (`Livro *biblioteca`, `Emprestimo *emprestimo`), permitindo acesso e modificação diretos aos dados alocados dinamicamente.

## Modularização

As funções são pequenas e fazem uma coisa:
- `cadastrarLivros`: pega dados do usuário, coloca em `biblioteca[indice]`, marca `disponivel = 1`.
- `listarLivros`: mostra os livros já cadastrados (e campo `Disponível`).
- `realizarEmprestimo`: lista os livros disponíveis de forma enumerada, mapeia a escolha para o índice real usando `indicesDisponiveis`, marca `disponivel = 0`, e grava no vetor `emprestimo`.
- `listarEmprestimo`: lista empréstimos usando `emprestimo[i].indiceLivro` para buscar nome do livro.
- `removeBuffer`: limpa o stdin para não quebrar a leitura de strings (básico e essencial para misturar `scanf` e `fgets`).

Isso é a parte de tornar seguro, manutenível e reutilizável:
- cada função lida com um conjunto de passos
- não misturar muita lógica (por exemplo, não fazemos busca e print juntos no `main`)

## Detalhes Técnicos

Na função `realizarEmprestimo`, é criado um array `indicesDisponiveis` que mapeia os livros disponíveis. Quando o usuário escolhe uma opção de 1 a N, a conversão para o índice real do vetor é feita através deste mapeamento: `indice = indicesDisponiveis[numLivro - 1]`. Isso resolve o problema de indexação quando alguns livros já estão emprestados.

O uso de `fgets` para leitura de strings é combinado com `strcspn(..., "\n")` para remover a quebra de linha. A função `removeBuffer()` é necessária após `scanf` para limpar o resto da linha antes de usar `fgets`.

## 7) Menu do programa

O `do/while` no `main` faz:
- opção 1: cadastrar
- opção 2: listar livros
- opção 3: emprestar
- opção 4: listar empréstimos
- opção 0: sair

## 8) Algumas noções aprendidas

- Sempre valide entrada de usuário.
- Indexação de arrays e relação entre número mostrado (1..N) x índice real (0..N-1).
- Como usar ponteiro para atualizar variáveis de contagem em uma função.
- Passar struct * para função equivale a passar um “array de structs”.
- Separar a lógica em funções pequenas deixa mais fácil achar bugs.

## 10) Compilação e Execução

```bash
gcc library.c -o library
./library
```

Menu do programa:
- 1: Cadastrar Livro
- 2: Listar Livros
- 3: Realizar Emprestimo
- 4: Listar Emprestimos
- 0: Sair

## Correções Implementadas

- Incremento de `totalLivros` dentro de `cadastrarLivros` para evitar sobrescrita do primeiro livro
- Mapeamento correto de índices em `realizarEmprestimo` usando array auxiliar
- Adição de campo `Disponível` na listagem de livros
