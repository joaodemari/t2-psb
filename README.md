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
// O operador ~ inverte os bits de PERMISSAO_ESCRITA,
// resultando em 1111 & NOT(0010) = 1101
// para que & remova a permissão de escrita.
```

> ## Extração de Bits - Exercício 2
Neste exercício, vamos demonstrar como extrair bits específicos de um número usando operadores bitwise.

## Função extract_bits
A função extract_bits extrai uma quantidade específica de bits de um número, começando de uma posição definida:

```c
unsigned int extract_bits(unsigned int number, int position, int width)
{
    unsigned int mask = (1 << width) - 1;
    return (number >> position) & mask;
}
```

Vamos usar a função extract_bits para extrair bits de um número.
Suponha que queremos extrair 3 bits do número 0b11010110, começando da posição 2 (onde a posição 0 é o bit menos significativo).

Exemplo
```
unsigned int number = 0b11010110; 
int position = 2;
int width = 3;

unsigned int extracted_bits = extract_bits(number, position, width);
```

### Passo 1: Criar a Máscara
A máscara é criada para selecionar apenas a quantidade de bits que queremos extrair.

```
unsigned int mask = (1 << width) - 1;
```
1 << width desloca o bit 1 para a esquerda por width posições.
Para width = 3, isso resulta em 0b1000.
Subtraindo 1, obtemos 0b0111.
Então, mask é 0b0111.

### Passo 2: Deslocar o Número
Deslocamos o número para a direita por position bits para alinhar os bits desejados à direita.

```
return (number >> position) & mask;
```
number >> position desloca number para a direita por position bits. Para position = 2, isso resulta em 0b00110101.

### Passo 3: Aplicar a Máscara
Aplicamos a máscara para selecionar apenas os bits desejados.
```
(number >> position) & mask realiza a operação bitwise AND entre 0b00110101 e 0b0111.
```
Resultado da operação AND:

```
  00110101
& 00000111
  --------
  00000101
```
Então, o valor de extracted_bits é 0b101. Conseguimos extrair os bits de acordo com a posição!
