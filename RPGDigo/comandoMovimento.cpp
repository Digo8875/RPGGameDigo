#include "bibliotecas.h"
#include "defines.h"
#include "funcoes.h"

void comandoMovimento (int map2[][Tmap], int *y, int *x, bool *flagAnda, int **warp)
{
    if(map2[*y][*x] == 40)                                            //Não permite andar na Árvore / ZAP
    {
        printf("\nNao e possivel andar atraves da arvore!");
        getch();
    }
    else if(map2[*y][*x] == 103)                                      //Não permite andar no Muro Centro
    {
        printf("\nNao e possivel andar atraves do muro!");
        getch();
    }
    else if(map2[*y][*x] == 200)                                      //Não permite andar na Água / Rio
    {
        printf("\nNao e possivel andar na agua!");
        getch();
    }
    else if(map2[*y][*x] == 1)                                        //Warp para mapa CIMA
    {
        printf("\nTELEPORTE! /\\");
        **warp = 1;
        getch();
    }
    else if(map2[*y][*x] == 2)                                       //Warp para mapa BAIXO
    {
        printf("\nTELEPORTE! \\/");
        **warp = 2;
        getch();
    }
    else if(map2[*y][*x] == 3)                                       //Warp para mapa ESQUERDA
    {
        printf("\nTELEPORTE! <<");
        **warp = 3;
        getch();
    }
    else if(map2[*y][*x] == 4)                                       //Warp para mapa DIREITA
    {
        printf("\nTELEPORTE! >>");
        **warp = 4;
        getch();
    }
    else if(map2[*y][*x] == 5)                                       //Warp para SUBIR ANDAR no mapa
    {
        printf("\nTELEPORTE! SOBE ANDAR NO MAPA");
        **warp = 5;
        getch();
    }
    else if(map2[*y][*x] == 6)                                       //Warp para DESCER ANDAR no mapa
    {
        printf("\nTELEPORTE! DESCE ANDAR NO MAPA");
        **warp = 6;
        getch();
    }
    else
        *flagAnda = 1;
}
