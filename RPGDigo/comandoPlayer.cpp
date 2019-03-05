#include "bibliotecas.h"
#include "defines.h"
#include "funcoes.h"

void comandoPlayer (int mapa[][Tmap], int *posPlayerY, int *posPlayerX, int *numeroMapa, int *warp, bool *andou)
{
    char tecla;
    int map2[Tmap][Tmap];

    for(int ii=0 ; ii<Tmap ; ii++)
    {
        for(int jj=0 ; jj<Tmap ; jj++)
        {
            map2[ii][jj] = mapa[ii][jj];
        }
    }

    printf("\nDigite o comando: ");
    fflush(stdin);
    tecla = getch();

    if(tecla == 'w')                                                 //Player andar para CIMA
    {
        int y,x;
        bool flagAnda = 0;

        y = *posPlayerY - 1;
        x = *posPlayerX;

        comandoMovimento(map2, &y, &x, &flagAnda, &warp);                 //Chama a função para verificar se é possível ou não o movimento do player

        if(flagAnda)
        {                                               //Faz o movimento do player para CIMA
            *posPlayerY -= 1;
            *andou = 1;
        }
    }
    else if(tecla == 'd')                                           //Player andar para DIREITA
    {
        int y,x;
        bool flagAnda = 0;

        y = *posPlayerY;
        x = *posPlayerX + 1;

        comandoMovimento(map2, &y, &x, &flagAnda, &warp);                 //Chama a função para verificar se é possível ou não o movimento do player

        if(flagAnda)
        {                                               //Faz o movimento do player para DIREITA
            *posPlayerX += 1;
            *andou = 1;
        }
    }
    else if(tecla == 'a')                                           //Player andar para ESQUERDA
    {
        int y,x;
        bool flagAnda = 0;

        y = *posPlayerY;
        x = *posPlayerX - 1;

        comandoMovimento(map2, &y, &x, &flagAnda, &warp);                 //Chama a função para verificar se é possível ou não o movimento do player

        if(flagAnda)
        {                                               //Faz o movimento do player para ESQUERDA
            *posPlayerX -= 1;
            *andou = 1;
        }
    }
    else if(tecla == 's')                                           //Player andar para BAIXO
    {
        int y,x;
        bool flagAnda = 0;

        y = *posPlayerY + 1;
        x = *posPlayerX;

        comandoMovimento(map2, &y, &x, &flagAnda, &warp);                 //Chama a função para verificar se é possível ou não o movimento do player

        if(flagAnda)
        {                                               //Faz o movimento do player para BAIXO
            *posPlayerY += 1;
            *andou = 1;
        }
    }
    else
    {
        printf("\n\n\n\n\n\nERRO COMANDO PLAYER!!!\n\n");
        getch();
    }
}
