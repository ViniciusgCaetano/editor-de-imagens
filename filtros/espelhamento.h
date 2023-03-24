#include <stdlib.h>
#include <stdio.h>

void trocar(unsigned char *a, unsigned char *b)
{
    unsigned char temp = *a;
    *a = *b;
    *b = temp;
}

void espelhamento(struct imagem input)
{
    for(int i=0; i < input.n_linhas; i++){
        for(int j= 0; j < input.n_colunas / 2; j++){
            trocar(&input.matriz[i][j], &input.matriz[i][input.n_colunas-j]);
        }
    }
}

