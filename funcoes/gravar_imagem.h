#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void gravar_imagem(struct imagem input, char caminho[])
{
    FILE * fPtr; // Ponteiro para arquivo

    fPtr = fopen(caminho, "w"); // abrir arquivo para escrita
    
    if(fPtr == NULL) // validação para ver se a abertura do arquivo funcionou
    {
       
        printf("Erro ao escrever arquivo.\n");
        exit(EXIT_FAILURE);
    }

    // Escrever cabeçalho
    fprintf(fPtr,"P2\n");
    fprintf(fPtr,"%d %d\n",  input.n_colunas, input.n_linhas);
    fprintf(fPtr,"%d\n", input.max_cinza);

    for(int i=0; i < input.n_linhas; i++){
        for(int j= 0; j < input.n_colunas; j++){

            fprintf(fPtr,"%u ", input.matriz[i][j]);
        }
        fprintf(fPtr,"\n");
    }


    /* Fechar arquivo */
    fclose(fPtr);
}