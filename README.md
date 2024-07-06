# Operadores Bitwise em C

Este README explica os operadores bitwise utilizados no arquivo C fornecido. O código define permissões usando operadores bitwise para manipulação de bits. 

## Definições de Permissões

As permissões são definidas usando macros e valores hexadecimais:

```c
#define PERMISSAO_LEITURA 0x01 // 0001
#define PERMISSAO_ESCRITA 0x02 // 0010
#define PERMISSAO_ADMIN 0x04   // 0100
```

PERMISSAO_LEITURA é representada pelo bit menos significativo (0001).
PERMISSAO_ESCRITA é representada pelo segundo bit menos significativo (0010).
PERMISSAO_ADMIN é representada pelo terceiro bit menos significativo (0100).
Função mostrar_permissoes
A função mostrar_permissoes exibe as permissões configuradas:

c
Copiar código
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
Operadores Bitwise Usados
& (AND)
Este operador é usado para verificar se uma permissão específica está definida:

c
Copiar código
if (permissoes & PERMISSAO_LEITURA)
{
  printf("Leitura ");
}
| (OR)
Este operador é usado para adicionar permissões:

c
Copiar código
permissoes = permissoes | PERMISSAO_LEITURA;
permissoes = permissoes | PERMISSAO_ESCRITA;
~ (NOT)
Este operador é usado em combinação com & para remover permissões:

c
Copiar código
permissoes = permissoes & ~PERMISSAO_ESCRITA;
O operador ~ inverte os bits de PERMISSAO_ESCRITA, resultando em 1111 1101 para que & remova a permissão de escrita.

Fluxo do Programa
Inicialmente, permissoes é definido como 0 (nenhuma permissão).

Adiciona permissões de leitura e escrita:

c
Copiar código
permissoes = permissoes | PERMISSAO_LEITURA;
permissoes = permissoes | PERMISSAO_ESCRITA;
Exibe as permissões atuais usando mostrar_permissoes.

Remove a permissão de escrita:

c
Copiar código
permissoes = permissoes & ~PERMISSAO_ESCRITA;
Exibe novamente as permissões atuais usando mostrar_permissoes.

Verifica se a permissão de administrador está definida:

c
Copiar código
if (permissoes & PERMISSAO_ADMIN)
{
  printf("A permissao de ADMINISTRADOR esta definida.\n");
}
else
{
  printf("A permissao de ADMINISTRADOR NAO esta definida.\n");
}
Compilação e Execução
Para compilar e executar o programa, use os seguintes comandos no terminal:

sh
Copiar código
gcc -o permissoes permissoes.c
./permissoes
Saída Esperada
A saída do programa será semelhante a:

markdown
Copiar código
Adicionando permissoes... 
Depois de adicionar permissoes de leitura e escrita:
--------------------
Permissoes: Leitura Escrita 
--------------------
Removendo a permissao de escrita
Apos remover a permissao de escrita:
--------------------
Permissoes: Leitura 
--------------------
A permissao de ADMINISTRADOR NAO esta definida.