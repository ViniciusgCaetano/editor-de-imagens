#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char** ler_imagem(char caminho[])
{
    FILE* ptr;
    ptr = fopen(caminho, "r"); // ler imagem no caminho selecionado

    if (NULL == ptr) {
        printf("A imagem não está no caminho selecionado \n");
    }

    int MAX_LEN = 10000;
    char buf[] = "";

    fgets(buf, MAX_LEN, ptr); // pula primeira linha com "P2"

    char largura[10], altura[10];
    fscanf(ptr, "%s %s", largura, altura);

    int int_largura = atoi(largura);
    int int_altura = atoi(altura);

    unsigned char ** arr = (unsigned char**) malloc(int_altura * sizeof(unsigned char*)); //cria matriz baseada nos parâmetros da segunda linha
    
    for (int i = 0; i < int_altura; i++) {
        arr[i] = (unsigned char*) malloc(int_largura* sizeof(unsigned char));   // alocando memória para as colunas
    }
    
    

    fscanf(ptr, "%u ", &arr[0][0]); //Solução temporária: alocar o valor máximo de cinza na posição (0,0) da matriz para ser apagado em seguida

    for(int linha = 0; linha < atoi(altura); linha++){
        for(int coluna = 0; coluna < atoi(largura); coluna++){
            fscanf(ptr, "%u ", &arr[linha][coluna]); //preenchendo valores
            // printf("%u, ", arr[linha][coluna]);
        }
        
        // printf("\n");
    }
    
    fclose(ptr);

    return arr;
}

