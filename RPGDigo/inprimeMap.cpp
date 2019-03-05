#include "bibliotecas.h"
#include "defines.h"
#include "funcoes.h"

void imprimeMap (int mapa[][Tmap], char nomeMapa[], int *numeroMapa, int *posPlayerY, int *posPlayerX)
{
    char impMap[Tmap][Tmap];

    printf("\t\t\tMAPA: %s",nomeMapa);
    printf("\n\t\t\tNUMERO : %d\n",*numeroMapa);

    for(int i=0; i<Tmap ; i++)
    {
        printf("\t\t");
        for(int j=0 ; j<Tmap ; j++)
        {
            if((i == *posPlayerY) && (j == *posPlayerX))          //Imprime PLAYER
                printf(" %c",4);
            else if(mapa[i][j] == 0)                              //Imprime VAZIO, para andar
                printf("  ");
            else if(mapa[i][j] == 1)                              //Imprime Teleporte   CIMA
                printf(" %c",15);
            else if(mapa[i][j] == 2)                              //Imprime Teleporte   BAIXO
                printf(" %c",15);
            else if(mapa[i][j] == 3)                              //Imprime Teleporte   ESQUERDA
                printf(" %c",15);
            else if(mapa[i][j] == 4)                              //Imprime Teleporte   DIREITA
                printf(" %c",15);
            else if(mapa[i][j] == 5)                              //Imprime Teleporte/Escada   SOBE ANDAR
                printf(" %c",30);
            else if(mapa[i][j] == 6)                              //Imprime Teleporte/Escada   DESCE ANDAR
                printf(" %c",31);
            else if(mapa[i][j] == 40)                             //Imprime Árvore / ZAP
                printf(" %c",5);
            else if(mapa[i][j] == 103)                            //Imprime Muro Centro
                printf(" %c",254);
            else if(mapa[i][j] == 200)                            //Imprime Água / Rio
                printf(" %c",176);
            else if(mapa[i][j] == 1000)                           //Imprime Padre/Healer       NPC Bom
                printf(" %c",1);
            else if(mapa[i][j] == 1001)                           //Imprime REI                NPC Bom
                printf(" %c",206);
            else if(mapa[i][j] == 1002)                           //Imprime GUARDA REAL        NPC Bom
                printf(" %c",1);
            else if(mapa[i][j] == 1003)                           //Imprime MERCADOR WEAPON    NPC Bom
                printf(" %c",36);
            else if(mapa[i][j] == 1004)                           //Imprime MERCADOR ARMOR     NPC Bom
                printf(" %c",36);
            else
                printf("ERRO DE IMPRESSAO");

        }
        printf("\n");
    }

}
