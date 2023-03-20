#include <stdlib.h>
#include <stdio.h>
//#include "funcoes.h"

#define MAX_LIMIT 180

void printFilterMenu()
{
  printf("\n");
  printf("---> Filtros disponíveis <---\n");
  printf("[1] Negativo: inverte as cores\n");
  printf("[2] Espelhamento: inverte a imagem horizontalmente\n");
  printf("[3] Borramento: diminui a nitidez da imagem\n");
  printf("[4] Brightening: clareia a imagem\n");
  printf("\n");
}

int main()
{
  printf("---> Bem vindo ao Editor de Imagens! <---\n\n");

  printf("Forneça o caminho para a imagem a ser editada: \n : ");
  char image_path[MAX_LIMIT];
  fgets(image_path, MAX_LIMIT, stdin);

  //TODO: error handling caso seja um path inválido ou a imagem não exista

  int valid_filter_selected = 0;
  int selected_filter;
  printFilterMenu();
  while (!valid_filter_selected)
  {
    printf("Selecione o filtro desejado (ex: 2): ");
    scanf("%d", &selected_filter);

    if (selected_filter < 0 || selected_filter > 4)
    {
      printf("Filtro escolhido não é válido!\n");
      continue;
    }

    valid_filter_selected = 1;
  }

  switch (selected_filter)
  {
    case 1: //Negativo
      break;
    case 2: //Espelhamento
      break;
    case 3: //Borramento
      break;
    case 4: //Brightening
      break;
  }

  return 0;
}
