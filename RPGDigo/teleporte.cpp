#include "bibliotecas.h"
#include "defines.h"
#include "funcoes.h"

void teleporte (int *warp, int *numeroMapa, int *posPlayerY, int *posPlayerX)
{
    switch (*numeroMapa)
    {
        //Teleportes do map1 " Skarttan "
        case 1:
        {
            if(*warp == 1)                       //TP CIMA Para map2 " Forest1 "
            {
                *posPlayerY = 21;
                *posPlayerX = 15;
                *numeroMapa = 2;
            }
            else if(*warp == 4)                  //TP DIREITA Para map3 " Forest2 "
            {
                *posPlayerY = 7;
                *posPlayerX = 1;
                *numeroMapa = 3;
            }
            else
            {
                printf("\n\n\n\n\nERRO DE TELEPORTE MAPA 1 !!!\n\n");
                getch();
            }
        }
        break;

        //Teleportes do map2 " Forest1 "
        case 2:
        {
            if(*warp == 2)                       //TP BAIXO Para map1 " Skarttan "
            {
                *posPlayerY = 1;
                *posPlayerX = 15;
                *numeroMapa = 1;
            }
            else
            {
                printf("\n\n\n\n\nERRO DE TELEPORTE MAPA 2 !!!\n\n");
                getch();
            }
        }
        break;

        //Teleportes do map3 " Forest2 "
        case 3:
        {
            if(*warp == 3)                       //TP ESQUERDA Para map1 " Skarttan "
            {
                *posPlayerY = 7;
                *posPlayerX = 21;
                *numeroMapa = 1;
            }
            else
            {
                printf("\n\n\n\n\nERRO DE TELEPORTE MAPA 3 !!!\n\n");
                getch();
            }
        }
        break;

        default:
            printf("\n\n\n\n\n\nDEFAULT... ERRO DE TELEPORTE, QUAL MAPA ???!!!\n\n");
            getch();
        break;
    }

    *warp = 0;
}
