#include <stdlib.h>
#include <stdio.h>

void borramento(struct imagem imagem_input)
{
    struct imagem img_nova;
    img_nova.n_linhas = imagem_input.n_linhas;
    img_nova.n_colunas = imagem_input.n_colunas;
    img_nova.matriz = malloc(img_nova.n_linhas * sizeof(unsigned char *));
    for (int i = 0; i < img_nova.n_linhas; i++) {
        img_nova.matriz[i] = malloc(img_nova.n_colunas * sizeof(unsigned char));
    }

    // Itera sobre cada pixel da imagem
    for (int i = 0; i < imagem_input.n_linhas; i++) {
        for (int j = 0; j < imagem_input.n_colunas; j++) {
            // Determina a média dos pixels vizinhos
            unsigned int sum = 0;
            int count = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    int row = i + x;
                    int col = j + y;
                    if (row >= 0 && row < imagem_input.n_linhas && col >= 0 && col < imagem_input.n_colunas) {
                        sum += imagem_input.matriz[row][col];
                        count++;
                    }
                }
            }
            unsigned char avg_pixel = (unsigned char)(sum / count);
            // Seta o pixel da nova imagem
            img_nova.matriz[i][j] = avg_pixel;
        }
    }

    imagem_input.matriz = img_nova.matriz;
}