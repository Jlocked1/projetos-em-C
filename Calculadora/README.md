# Calculadora em C

Este repositório contém um exemplo simples de uma calculadora de linha de comando escrita em C. O arquivo serve para registrar o que aprendi sobre conceitos básicos da linguagem, como
* uso de **headers**,
* declaração de **variáveis**,
* estruturas de decisão (`if/else`),
* entrada e saída com `scanf`/`printf`,
* e noções de compilação no terminal Linux.

## Requisitos
- Um compilador C (por exemplo `gcc`).
- Um ambiente Linux/Unix (o tutorial usa o terminal).

## Compilação

No diretório `Calculadora/` execute:

```bash
gcc calculator.c -o calc
```

Isso gerará o executável `calc`.

## Uso

```bash
./calc
```

O programa solicitará:

1. Dois números inteiros.
2. Uma operação a ser realizada: `+`, `-`, `*`, `/` ou `%`.

Em seguida exibirá o resultado correspondente.

## Explicando o código

### Headers

O único cabeçalho utilizado é `<stdio.h>`, que declara funções de entrada e saída como `printf`, `scanf` e `puts`.

```c
#include <stdio.h>
```

### Sintaxe básica

O ponto de entrada de qualquer programa C é a função `main`. Cada instrução termina com `;`. Blocos são delimitados por `{}`.

```c
int main() {
    /* ... */
    return 0;
}
```

### Variáveis

São declaradas no início de `main`:

```c
int num1, num2;
char operation;
```

`num1` e `num2` armazenam números inteiros; `operation` guarda o caractere representando a operação.

### Entrada e saída

`puts` escreve uma string seguida de nova linha. `scanf` lê valores do teclado:

```c
puts("type a number: ");
scanf("%d", &num1);
```

Observe o uso de `&` para passar o endereço da variável.

### Estruturas de decisão

O programa usa uma sequência de `if` / `else if` para escolher qual operação executar:

```c
if (operation == '+') {
    return printf(...);
} else if (operation == '-') {
    ...
}
```

Cada condição compara `operation` com um caractere. A função `printf` imprime o resultado formatado. O retorno de `printf` também é usado como valor de retorno de `main`.

> **Operador ternário:** Embora não utilizado aqui, o operador ternário (`condição ? expr1 : expr2`) permite expressar decisões simples em uma única linha.

### Laços

Este exemplo não usa loops, mas laços como `for`, `while` ou `do...while` são fundamentais para tarefas repetitivas. Poderíamos, por exemplo, envolver a leitura e processamento em um `while` para aceitar várias operações sem reiniciar o programa.

---