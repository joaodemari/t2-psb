# Operadores Bitwise em C

Este README explica os operadores bitwise utilizados nos exercícios 1 e 2 do Trabalho Final da disciplina de Programação de Software Básico.

> ## Definições de Permissões - Exercício 1

As permissões são definidas usando macros e valores hexadecimais:

```c
#define PERMISSAO_LEITURA 0x01 // 0001
#define PERMISSAO_ESCRITA 0x02 // 0010
#define PERMISSAO_ADMIN 0x04   // 0100
```

- PERMISSAO_LEITURA é representada pelo bit menos significativo (0001).
- PERMISSAO_ESCRITA é representada pelo segundo bit menos significativo (0010).
- PERMISSAO_ADMIN é representada pelo terceiro bit menos significativo (0100).

## Função mostrar_permissoes

A função mostrar_permissoes exibe as permissões configuradas:

```c
void mostrar_permissoes(int permissoes)
{
  printf("--------------------\n");
  printf("Permissoes: ");
  if (permissoes & PERMISSAO_LEITURA)
  {
    printf("Leitura ");
  }
  if (permissoes & PERMISSAO_ESCRITA)
  {
    printf("Escrita ");
  }
  if (permissoes & PERMISSAO_ADMIN)
  {
    printf("Execucao ");
  }
  if (!(permissoes & (PERMISSAO_LEITURA | PERMISSAO_ESCRITA | PERMISSAO_ADMIN)))
  {
    printf("Nenhuma");
  }
  printf("\n");
  printf("--------------------\n");
}
```
## Operadores Bitwise Usados
### & (AND)

Este operador é usado para verificar se uma permissão específica está definida.
Exemplo:
```
#define PERMISSAO_LEITURA 0x01 // 0001

// Esse if será recusado pois 0010 & 0001 = 0000
// Assim, percebemos que nesse caso, esse usuário não tem permissão de Leitura
int permissoes = 0b0010
if (permissoes & PERMISSAO_LEITURA)
{
  printf("Leitura ");
}

// Esse if vai passar pois 0011 & 0001 = 0001
// Assim, percebemos que nesse caso, esse usuário tem permissão de Leitura
int permissoes = 0b0011;
if (permissoes & PERMISSAO_LEITURA)
{
  printf("Leitura ");
}
```

## | (OR)
Este operador é usado para adicionar permissões:
Exemplo:

```c
int permissoes = 0b0000;
// 0000 | 0001 = 0001, logo a permissão foi adicionada
permissoes = permissoes | PERMISSAO_LEITURA;
// 0001 | 0011 = 0011, logo a permissão de escrita foi adicionada
permissoes = permissoes | PERMISSAO_ESCRITA;
```
## ~ (NOT)
Este operador é usado em combinação com & para remover permissões:
Exemplo:

```c
permissoes = permissoes & ~PERMISSAO_ESCRITA;
// O operador ~ inverte os bits de PERMISSAO_ESCRITA, resultando em 1111 & NOT(0010) = 1101 para que & remova a permissão de escrita.
```
