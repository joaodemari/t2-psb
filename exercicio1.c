#include <stdio.h>

#define PERMISSAO_LEITURA 0x01 // 0001
#define PERMISSAO_ESCRITA 0x02 // 0010
#define PERMISSAO_ADMIN 0x04   // 0100

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

int main()
{
  int permissoes = 0;

  printf("Adicionando permissoes... \n");
  permissoes = permissoes | PERMISSAO_LEITURA;
  permissoes = permissoes | PERMISSAO_ESCRITA;

  printf("Depois de adicionar permissoes de leitura e escrita:\n");
  mostrar_permissoes(permissoes);

  printf("Removendo a permissao de escrita\n");
  permissoes = permissoes & ~PERMISSAO_ESCRITA;

  printf("Apos remover a permissao de escrita:\n");
  mostrar_permissoes(permissoes);

  if (permissoes & PERMISSAO_ADMIN)
  {
    printf("A permissao de ADMINISTRADOR esta definida.\n");
  }
  else
  {
    printf("A permissao de ADMINISTRADOR NAO esta definida.\n");
  }

  return 0;
}