#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct imagem ler_imagem(char caminho[])
{
    FILE* ptr;
    if(strcmp("P",caminho) == 0){
        caminho = "./imagens_teste/pgm/image1.pgm";
    }
    ptr = fopen(caminho, "r"); // ler imagem no caminho selecionado

    struct imagem imagem; // cria struct 
    if (NULL == ptr) {
        printf("A imagem não está no caminho selecionado \n");
        imagem.n_linhas = 0;
        return imagem;
    }

    int MAX_LEN = 10000;
    char buf[] = "";

    fgets(buf, MAX_LEN, ptr); // pula primeira linha com "P2"

    char largura[10], altura[10];
    fscanf(ptr, "%s %s", largura, altura);
    
    int int_largura = atoi(largura);
    int int_altura = atoi(altura);
    imagem.n_linhas = int_altura;
    imagem.n_colunas = int_largura;

    imagem.matriz = (unsigned char**) malloc(int_altura * sizeof(unsigned char*)); //cria matriz baseada nos parâmetros da segunda linha
    
    for (int i = 0; i < int_altura; i++) {
        imagem.matriz[i] = (unsigned char*) malloc(int_largura* sizeof(unsigned char));   // alocando memória para as colunas
    }
    
    fscanf(ptr, "%u ", &imagem.max_cinza); //Solução temporária: alocar o valor máximo de cinza na posição (0,0) da matriz para ser apagado em seguida

    for(int linha = 0; linha < atoi(altura); linha++){
        for(int coluna = 0; coluna < atoi(largura); coluna++){
            fscanf(ptr, "%u ", &imagem.matriz[linha][coluna]); //preenchendo valores
        }   
    }
    
    fclose(ptr);

    return imagem;
}

