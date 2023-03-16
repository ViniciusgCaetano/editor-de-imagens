#include <stdlib.h>
#include <stdio.h>

void negativo(struct imagem input){
    for(int i=0; i < input.n_linhas; i++){
        for(int j= 0; j < input.n_colunas; j++){
            input.matriz[i][j] = 255 - input.matriz[i][j];
            printf("%u, ", input.matriz[i][j]);
        }
        printf("\n");
    }
}
