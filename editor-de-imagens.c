#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

int main()
{
    printf("---> Bem vindo ao Editor de Imagens! <---\n\n");
    while(1){
       

        struct imagem imagem_input = leitura_imagem();
        int filtro_selecionado = selecionar_filtro();
        aplicar_filtro(filtro_selecionado, imagem_input);
        gravacao(filtro_selecionado, imagem_input);


        int resposta;
        printf("Terminar programa? (1=SIM 0=NÃO):  ");
        scanf("%d", &resposta);
        if(resposta==1){
            break;
        }
    }
    
    return 0;

}
