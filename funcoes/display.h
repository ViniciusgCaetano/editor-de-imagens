#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

struct imagem leitura_imagem(){
    int flag_imagem_inexistente = 1;
    struct imagem imagem_input;
    do{
        printf("Forneça o caminho para a imagem a ser editada (Escreva P para o padrão [./imagens_teste/pgm/image1.pgm]): \n : ");
        char image_path[MAX_LIMIT];
        scanf("%s", &image_path);
        imagem_input = ler_imagem(image_path);
        if (imagem_input.n_linhas > 0){
            flag_imagem_inexistente = 0;
        }

    }while(flag_imagem_inexistente);
    printf("%d", imagem_input.n_linhas);

    return imagem_input;
}

int selecionar_filtro(){
    int valid_filter_selected = 0;
    int filtro_selecionado;
    printFilterMenu();

    while (!valid_filter_selected)
    {
        printf("Selecione o filtro desejado (ex: 2): ");
        scanf("%d", &filtro_selecionado);

        if (filtro_selecionado <= 0 || filtro_selecionado > 4)
        {
            printf("Filtro escolhido não é válido!\n");
            continue;
        }

        valid_filter_selected = 1;
    }
    return filtro_selecionado;
}
    
int aplicar_filtro(int filtro_selecionado, struct imagem imagem_input){
     switch (filtro_selecionado)
    {
        case 1: //Negativo
            negativo(imagem_input);
            
            return 0;
        case 2: //Espelhamento
            espelhamento(imagem_input);

            return 0;
        case 3: //Borramento
            borramento(imagem_input);
           
            return 0;
        case 4: //Brightening
            brightening(imagem_input);
            
            return 0;
    }
}


int gravacao(int filtro_selecionado, struct imagem imagem_input){
    printf("Forneça o caminho para salvar a imagem (Escreva P para o padrão [./results/resultado.pgm]): \n : ");
    char caminho_para_guardar[MAX_LIMIT];
    scanf("%s", &caminho_para_guardar);
    gravar_imagem(imagem_input, caminho_para_guardar);
    return 0;

}