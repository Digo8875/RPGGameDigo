/*** Para iniciar corretamente:

    TROQUE:
    int numeroMapa = 2;
    int posPlayerY=1, posPlayerX=1;

    Para:
    int numeroMapa = 1;
    int posPlayerY, posPlayerX;      ***/


#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<locale.h>

#define Tmap 23
#define TnomeMap 50


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

void maps (int mapa[][Tmap], char nomeMapa[], int *numeroMapa, int *inicio, int *posPlayerY, int *posPlayerX)
{

    switch (*numeroMapa)
    {
        //map1   Cidade Inicial " Skarttan "
        case 1:
        {
            strcpy(nomeMapa,"Skarttan");
            *numeroMapa = 1;

            for(int i=0 ; i<Tmap ; i++)
            {
                for(int j=0 ; j<Tmap ; j++)
                {
                    if((i == 0) || (j == 0) || (i == Tmap-1) || (j == Tmap-1))   //Muro Centro  em volta da cidade
                        mapa[i][j] = 11;
                    else
                        mapa[i][j] = 0;
                }
            }

            /* ---------------------------------------------------------------------------------------- */
                            /* --- POSICIONA O PLAYER PELA PRIMEIRA VEZ NO MAPA 1--- */
            if(*inicio)
            {
                *posPlayerY = 14;
                *posPlayerX = 12;
                *inicio = 0;
            }
            /* ---------------------------------------------------------------------------------------- */

            mapa[18][3] = 100;                                        //PADRE / HEALER    NPC Bom
            mapa[2][6] = 101;                                         //REI               NPC Bom
            mapa[4][4] = 102;                                         //GUARDA REAL       NPC Bom
            mapa[4][8] = 102;                                         //GUARDA REAL       NPC Bom
            mapa[12][4] = 102;                                        //GUARDA REAL       NPC Bom
            mapa[12][8] = 102;                                        //GUARDA REAL       NPC Bom
            mapa[20][16] = 103;                                       //MERCADOR WEAPON   NPC Bom
            mapa[20][20] = 104;                                       //MERCADOR ARMOR    NPC Bom

            mapa[0][15] = 1;                                          //Teleporte  /\   Para FOREST1
            mapa[7][22] = 4;                                          //Teleporte   >   Para FOREST2

            /* -------------------------------------------------------------------------------------------------- */
                                    /* --- CERCADO DO PADRE/HEALER --- */
            for(int j=1 ; j<6 ; j++)                                  //Muro Centro  em cima do PADRE/HEALER
            {
                mapa[17][j] = 11;
            }
            for(int i=17 ; i<22 ; i++)                              //Muro Centro   na direita do PADRE/HEALER
            {
                if(i != 20)
                    mapa[i][5] = 11;
            }
            /* -------------------------------------------------------------------------------------------------- */

            /* -------------------------------------------------------------------------------------------------- */
                                    /* --- CERCADO DO REI --- */
            for(int j=1 ; j<13 ; j++)                                  //Muro Centro  embaixo do REI
            {
                if(!(j>=4 && j<=8))
                    mapa[12][j] = 11;
            }
            for(int i=1 ; i<12 ; i++)                              //Muro Centro   na direita do REI
            {
                    mapa[i][12] = 11;
            }
            /* -------------------------------------------------------------------------------------------------- */

            /* -------------------------------------------------------------------------------------------------- */
                                    /* --- CERCADO DOS MERCADORES WEAPONS e ARMORS --- */
            for(int j=14 ; j<22 ; j++)                                  //Muro Centro  cima dos MERCADORES
            {
                if(!(j==16 || j==20))
                    mapa[16][j] = 11;
            }
            for(int i=17 ; i<22 ; i++)                                 //Muro Centro   na esquerda dos MERCADORES
            {
                    mapa[i][14] = 11;
                    mapa[i][18] = 11;
            }
            /* -------------------------------------------------------------------------------------------------- */
        }
        break;

        //map2   CIMA de Skarttan " Forest1 "
        case 2:
        {
            strcpy(nomeMapa,"Forest1");
            *numeroMapa = 2;

            for(int i=0 ; i<Tmap ; i++)
            {
                for(int j=0 ; j<Tmap ; j++)
                {
                    if((i == 0) || (j == 0) || (i == Tmap-1) || (j == Tmap-1))   //Muro Centro  em volta da cidade
                        mapa[i][j] = 11;
                    else
                        mapa[i][j] = 0;
                }
            }

            /* -------------------------------------------------------------------------------------------------- */

            mapa[22][15] = 2;                                          //Teleporte  \/   Para SKARTTAN

            /* -------------------------------------------------------------------------------------------------- */

            /* -------------------------------------------------------------------------------------------------- */
                                    /* --- DESENHO DA ÁGUA / RIO --- */
            //Chave para abrir os FORs do desenho
            {
            for(int j=12 ; j<22 ; j++)
            {
                mapa[1][j] = 12;
                mapa[3][j] = 12;
            }
            for(int j=11 ; j<22 ; j++)
            {
                mapa[2][j] = 12;
                mapa[4][j] = 12;
            }
            for(int j=10 ; j<22 ; j++)
            {
                mapa[5][j] = 12;
            }
            for(int j=9 ; j<22 ; j++)
            {
                mapa[6][j] = 12;
                mapa[7][j] = 12;
            }
            for(int j=8 ; j<22 ; j++)
            {
                mapa[8][j] = 12;
                if((j!=12) && (j!=15))
                    mapa[9][j] = 12;
            }
            for(int j=7 ; j<22 ; j++)
            {
                if((j!=12) && (j!=14) && (j!=15) && (j!=16))
                    mapa[10][j] = 12;
                if((!(j>=11 && j<=16)) && (j!=21))
                    mapa[11][j] = 12;
                if((!(j>=11 && j<=17)) && (j!=21))
                    mapa[12][j] = 12;
            }
            for(int j=6 ; j<22 ; j++)
            {
                if((!(j>=10 && j<=16)) && (j!=20) && (j!=21))
                    mapa[13][j] = 12;
                if((!(j>=10 && j<=15)) && (j!=20) && (j!=21))
                    mapa[14][j] = 12;
                if((!(j>=6 && j<=14)) && (!(j>=18 && j<=21)))
                    mapa[15][j] = 12;
                if((!(j>=9 && j<=15)) && (!(j>=17 && j<=21)))
                    mapa[16][j] = 12;
                if(!(j>=8 && j<=21))
                    mapa[17][j] = 12;
            }
            for(int j=5 ; j<8 ; j++)
            {
                mapa[18][j] = 12;
                mapa[19][j] = 12;
            }
            for(int j=4 ; j<7 ; j++)
            {
                mapa[20][j] = 12;
                mapa[21][j] = 12;
            }
            }
            /* -------------------------------------------------------------------------------------------------- */
        }
        break;

        //map3   DIREITA de Skarttan " Forest2 "
        case 3:
        {
            strcpy(nomeMapa,"Forest2");
            *numeroMapa = 3;

            for(int i=0 ; i<Tmap ; i++)
            {
                for(int j=0 ; j<Tmap ; j++)
                {
                    if((i == 0) || (j == 0) || (i == Tmap-1) || (j == Tmap-1))   //Muro Centro  em volta da cidade
                        mapa[i][j] = 11;
                    else
                        mapa[i][j] = 0;
                }
            }

            /* -------------------------------------------------------------------------------------------------- */

            mapa[7][0] = 3;                                          //Teleporte  <<<   Para SKARTTAN

            /* -------------------------------------------------------------------------------------------------- */

            /* -------------------------------------------------------------------------------------------------- */
                                    /* --- DESENHO DA ÁGUA / RIO --- */
            //Chave para abrir os FORs do desenho
            {
                //Primeiro Lago
                mapa[2][14] = 12;
                for(int j=13 ; j<18 ; j++)
                {
                    if(j != 16)
                        mapa[3][j] = 12;
                }
                for(int j=12 ; j<18 ; j++)
                {
                    mapa[4][j] = 12;
                }
                for(int j=13 ; j<20 ; j++)
                {
                    mapa[5][j] = 12;
                }
                for(int j=12 ; j<19 ; j++)
                {
                    mapa[6][j] = 12;
                }
                mapa[7][11] = 12;
                mapa[7][12] = 12;
                mapa[7][15] = 12;
                mapa[7][17] = 12;
                mapa[8][17] = 12;

                //Segundo Lago
                mapa[15][8] = 12;
                mapa[16][7] = 12;
                mapa[16][8] = 12;
                mapa[16][10] = 12;
                mapa[17][12] = 12;
                for(int i=17 ; i<20 ; i++)
                {
                    for(int j=6 ; j<12 ; j++)
                    {
                        mapa[i][j] = 12;
                    }
                }
                for(int j=5 ; j<11 ; j++)
                {
                    mapa[20][j] = 12;
                }
                for(int j=4 ; j<12 ; j++)
                {
                    mapa[21][j] = 12;
                }
            }
            /* -------------------------------------------------------------------------------------------------- */
        }
        break;

        default:
            printf("\n\n\n\n\nDEFAULT ... NUMERO DE MAPA ERRADO!!!!!\n\n");
            getch();
        break;
    }
}

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
            if((i == *posPlayerY) && (j == *posPlayerX))         //Imprime PLAYER
                printf(" %c",4);
            else if(mapa[i][j] == 0)                             //Imprime VAZIO, para andar
                printf("  ");
            else if(mapa[i][j] == 1)                             //Imprime Teleporte   CIMA
                printf(" %c",15);
            else if(mapa[i][j] == 2)                             //Imprime Teleporte   BAIXO
                printf(" %c",15);
            else if(mapa[i][j] == 3)                             //Imprime Teleporte   ESQUERDA
                printf(" %c",15);
            else if(mapa[i][j] == 4)                             //Imprime Teleporte   DIREITA
                printf(" %c",15);
            else if(mapa[i][j] == 11)                            //Imprime Muro Centro
                printf(" %c",254);
            else if(mapa[i][j] == 12)                            //Imprime Água / Rio
                printf(" %c",176);
            else if(mapa[i][j] == 100)                           //Imprime Padre/Healer       NPC Bom
                printf(" %c",1);
            else if(mapa[i][j] == 101)                           //Imprime REI                NPC Bom
                printf(" %c",206);
            else if(mapa[i][j] == 102)                           //Imprime GUARDA REAL        NPC Bom
                printf(" %c",1);
            else if(mapa[i][j] == 103)                           //Imprime MERCADOR WEAPON    NPC Bom
                printf(" %c",36);
            else if(mapa[i][j] == 104)                           //Imprime MERCADOR ARMOR     NPC Bom
                printf(" %c",36);
            else
                printf("ERRO DE IMPRESSAO");

        }
        printf("\n");
    }

}

void comandoMovimento (int map2[][Tmap], int *y, int *x, bool *flagAnda, int **warp)
{
    if(map2[*y][*x] == 11)                                          //Não permite andar no Muro Centro
    {
        printf("\nNao e possivel andar atraves do muro!");
        getch();
    }
    else if(map2[*y][*x] == 12)                                     //Não permite andar na Água / Rio
    {
        printf("\nNao e possivel andar na agua!");
        getch();
    }
    else if(map2[*y][*x] == 1)
    {
        printf("\nTELEPORTE! /\\");
        **warp = 1;
        getch();
    }
    else if(map2[*y][*x] == 2)
    {
        printf("\nTELEPORTE! \\/");
        **warp = 2;
        getch();
    }
    else if(map2[*y][*x] == 3)
    {
        printf("\nTELEPORTE! <<");
        **warp = 3;
        getch();
    }
    else if(map2[*y][*x] == 4)
    {
        printf("\nTELEPORTE! >>");
        **warp = 4;
        getch();
    }
    else
        *flagAnda = 1;
}

void comandoPlayer (int mapa[][Tmap], int *posPlayerY, int *posPlayerX, int *numeroMapa, int *warp)
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

        if(flagAnda)                                               //Faz o movimento do player para CIMA
            *posPlayerY -= 1;
    }
    else if(tecla == 'd')                                           //Player andar para DIREITA
    {
        int y,x;
        bool flagAnda = 0;

        y = *posPlayerY;
        x = *posPlayerX + 1;

        comandoMovimento(map2, &y, &x, &flagAnda, &warp);                 //Chama a função para verificar se é possível ou não o movimento do player

        if(flagAnda)                                               //Faz o movimento do player para DIREITA
            *posPlayerX += 1;
    }
    else if(tecla == 'a')                                           //Player andar para ESQUERDA
    {
        int y,x;
        bool flagAnda = 0;

        y = *posPlayerY;
        x = *posPlayerX - 1;

        comandoMovimento(map2, &y, &x, &flagAnda, &warp);                 //Chama a função para verificar se é possível ou não o movimento do player

        if(flagAnda)                                               //Faz o movimento do player para ESQUERDA
            *posPlayerX -= 1;
    }
    else if(tecla == 's')                                           //Player andar para BAIXO
    {
        int y,x;
        bool flagAnda = 0;

        y = *posPlayerY + 1;
        x = *posPlayerX;

        comandoMovimento(map2, &y, &x, &flagAnda, &warp);                 //Chama a função para verificar se é possível ou não o movimento do player

        if(flagAnda)                                               //Faz o movimento do player para BAIXO
            *posPlayerY += 1;
    }
}

void game ()
{
    /* ------------------------------------------------------------------------------------ */
                        /* --- VARIÉVEIS PARA MAPA --- */
    int mapa[Tmap][Tmap];
    char nomeMapa[TnomeMap];
    int numeroMapa = 3;

    int warp = 0;
    /** WARP responsável por verificar se há teleporte para outro mapa ou não...
        warp 0 = Não há teleporte
        warp 1 = TP mapa CIMA
        warp 2 = TP mapa BAIXO
        warp 3 = TP mapa ESQUERDA
        warp 4 = TP mapa DIREITA      **/
    /* ------------------------------------------------------------------------------------ */

    /* ------------------------------------------------------------------------------------ */
                        /* --- VARIÉVEIS PARA PLAYER --- */
    int inicio = 1;                                   //Variável utilizada para posicionar o player na primeira vez no mapa 1
    int player = 50;
    int posPlayerY = 1, posPlayerX = 1;
    /* ------------------------------------------------------------------------------------ */
    do
    {
        system("cls");

        if(warp != 0)
            teleporte(&warp, &numeroMapa, &posPlayerY, &posPlayerX);                       //Chama a função TELEPORTE para decidir qual mapa irá imprimir, pois um WARP foi ativado para ir ao outro mapa.

        maps(mapa, nomeMapa, &numeroMapa, &inicio, &posPlayerY, &posPlayerX);              //Chama função dos mapas para escolher o mapa atual...
        imprimeMap(mapa, nomeMapa, &numeroMapa, &posPlayerY, &posPlayerX);                 //Chama a função para imprimir o mapa atual ao usuário...
        comandoPlayer(mapa, &posPlayerY, &posPlayerX, &numeroMapa, &warp);                 //Chama a função para pegar os comandos do player...    MOVIMENTO, TECLAS, TELEPORTE...


    }while(1); //Jogo Rodando sempre... fazer parada ?
}

int main()
{
    srand(time(NULL));
    rand();
    //system("color 0E");
    //setlocale(LC_ALL,"Portuguese"); // ***Se usar o Potuguese buga os caracteres na apresentação ao usuário...

    game();

    return 0;
}
