#include "bibliotecas.h"
#include "defines.h"
#include "funcoes.h"

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
                        mapa[i][j] = 103;
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

            mapa[18][3] = 1000;                                        //PADRE / HEALER    NPC Bom
            mapa[2][6] = 1001;                                         //REI               NPC Bom
            mapa[4][4] = 1002;                                         //GUARDA REAL       NPC Bom
            mapa[4][8] = 1002;                                         //GUARDA REAL       NPC Bom
            mapa[12][4] = 1002;                                        //GUARDA REAL       NPC Bom
            mapa[12][8] = 1002;                                        //GUARDA REAL       NPC Bom
            mapa[20][16] = 1003;                                       //MERCADOR WEAPON   NPC Bom
            mapa[20][20] = 1004;                                       //MERCADOR ARMOR    NPC Bom

            mapa[0][15] = 1;                                          //Teleporte  /\   Para FOREST1
            mapa[7][22] = 4;                                          //Teleporte   >   Para FOREST2

            /* -------------------------------------------------------------------------------------------------- */
                                    /* --- CERCADO DO PADRE/HEALER --- */
            for(int j=1 ; j<6 ; j++)                                  //Muro Centro  em cima do PADRE/HEALER
            {
                mapa[17][j] = 103;
            }
            for(int i=17 ; i<22 ; i++)                              //Muro Centro   na direita do PADRE/HEALER
            {
                if(i != 20)
                    mapa[i][5] = 103;
            }
            /* -------------------------------------------------------------------------------------------------- */

            /* -------------------------------------------------------------------------------------------------- */
                                    /* --- CERCADO DO REI --- */
            for(int j=1 ; j<13 ; j++)                                  //Muro Centro  embaixo do REI
            {
                if(!(j>=4 && j<=8))
                    mapa[12][j] = 103;
            }
            for(int i=1 ; i<12 ; i++)                              //Muro Centro   na direita do REI
            {
                    mapa[i][12] = 103;
            }
            /* -------------------------------------------------------------------------------------------------- */

            /* -------------------------------------------------------------------------------------------------- */
                                    /* --- CERCADO DOS MERCADORES WEAPONS e ARMORS --- */
            for(int j=14 ; j<22 ; j++)                                  //Muro Centro  cima dos MERCADORES
            {
                if(!(j==16 || j==20))
                    mapa[16][j] = 103;
            }
            for(int i=17 ; i<22 ; i++)                                 //Muro Centro   na esquerda dos MERCADORES
            {
                    mapa[i][14] = 103;
                    mapa[i][18] = 103;
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
                    if((i == 0) || (j == 0) || (i == Tmap-1) || (j == Tmap-1))   //Varredura em volta da Florest1
                    {
                        if(i == 22)
                            mapa[i][j] = 103;                                    //Muro Centro de SKARTTAN embaixo da Florest1
                        else
                            mapa[i][j] = 40;                                     //Árvore / ZAP em volta da Florest1
                    }
                    else
                        mapa[i][j] = 0;                                          //Imprime chão "VAZIO"
                }
            }

            /* -------------------------------------------------------------------------------------------------- */

            mapa[22][15] = 2;                                          //Teleporte  \/   Para SKARTTAN

            /* -------------------------------------------------------------------------------------------------- */

            /* -------------------------------------------------------------------------------------------------- */
                                    /* --- DESENHO DA ÁGUA / RIO --- */
            //Chave para abrir os FORs do desenho
            {
            for(int j=12 ; j<18 ; j++)
                mapa[1][j] = 200;
            for(int j=11 ; j<22 ; j++)
                if(!(j >= 17 && j<=20))
                    mapa[2][j] = 200;
            for(int j=12 ; j<22 ; j++)
                if(j!= 17 && j!= 18 && j!= 20)
                    mapa[3][j] = 200;
            for(int j=11 ; j<22 ; j++)
                if(!(j>=16 && j<=18))
                    mapa[4][j] = 200;
            for(int j=10 ; j<22 ; j++)
                mapa[5][j] = 200;
            for(int j=9 ; j<22 ; j++)
            {
                mapa[6][j] = 200;
                mapa[7][j] = 200;
            }
            for(int j=8 ; j<22 ; j++)
            {
                mapa[8][j] = 200;
                if((j!= 11) && (j!=12) && (j!=15))
                    mapa[9][j] = 200;
            }
            for(int j=7 ; j<22 ; j++)
            {
                if((j!=11) && (j!=12) && (j!=14) && (j!=15) && (j!=16))
                    mapa[10][j] = 200;
                if((!(j>=10 && j<=16)) && (j!=20) && (j!=21))
                    mapa[11][j] = 200;
                if((!(j>=11 && j<=17)) && (j!=21))
                    mapa[12][j] = 200;
            }
            for(int j=6 ; j<22 ; j++)
            {
                if((!(j>=10 && j<=16)) && (j!=20) && (j!=21))
                    mapa[13][j] = 200;
                if((!(j>=10 && j<=15)) && (j!=20) && (j!=21))
                    mapa[14][j] = 200;
                if((!(j>=6 && j<=14)) && (!(j>=18 && j<=21)))
                    mapa[15][j] = 200;
                if((!(j>=9 && j<=15)) && (!(j>=17 && j<=21)))
                    mapa[16][j] = 200;
                if(!(j>=8 && j<=21))
                    mapa[17][j] = 200;
            }
            for(int j=5 ; j<8 ; j++)
            {
                mapa[18][j] = 200;
                mapa[19][j] = 200;
            }
            for(int j=4 ; j<7 ; j++)
            {
                mapa[20][j] = 200;
                mapa[21][j] = 200;
            }
            }
            /* -------------------------------------------------------------------------------------------------- */

            /* -------------------------------------------------------------------------------------------------- */
                                        /* --- DESENHO DAS ÁRVORES --- */
            //Chave para abrir os FORs do desenho das ÁRvores
            {
                for(int j=1 ; j<22 ; j++)
                    if(j== 1 || j== 2 || j== 6 || j== 8 || j== 11 || (j>=18 &&j<=21))
                        mapa[1][j] = 40;
                for(int j=1 ; j<22 ; j++)
                    if((j>=1 && j<=4) || j==6 || j==7 || (j>=17 && j<=20))
                        mapa[2][j] = 40;
                for(int j=1 ; j<22 ; j++)
                    if((j>=1 && j<=4) || j==6 || j==17 || j==18 || j==20)
                        mapa[3][j] = 40;
                for(int j=1 ; j<22 ; j++)
                    if((j>=1 && j<=2) || (j>=16 && j<=18))
                        mapa[4][j] = 40;
                mapa[5][1] = 40;
                mapa[5][6] = 40;
                mapa[6][7] = 40;
                mapa[9][3] = 40;
                mapa[9][11] = 40;
                mapa[9][12] = 40;
                mapa[10][3] = 40;
                mapa[10][4] = 40;
                mapa[10][11] = 40;
                mapa[10][21] = 40;
                mapa[11][10] = 40;
                mapa[11][15] = 40;
                mapa[11][20] = 40;
                mapa[11][21] = 40;
                mapa[13][2] = 40;
                mapa[14][1] = 40;
                mapa[14][21] = 40;
                mapa[15][13] = 40;
                mapa[17][1] = 40;
                mapa[17][2] = 40;
                mapa[17][19] = 40;
                mapa[17][21] = 40;
                mapa[18][1] = 40;
                mapa[20][1] = 40;
                mapa[21][1] = 40;
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
                    if((i == 0) || (j == 0) || (i == Tmap-1) || (j == Tmap-1))   //Varredura em volta da Florest1
                    {
                        if(j == 0)
                            mapa[i][j] = 103;                                    //Muro Centro de SKARTTAN na esquerda da Florest2
                        else
                            mapa[i][j] = 40;                                     //Árvore / ZAP em volta da Florest1
                    }
                    else
                        mapa[i][j] = 0;                                          //Imprime chão "VAZIO"
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
                mapa[2][14] = 200;
                for(int j=13 ; j<18 ; j++)
                {
                    if(j != 16)
                        mapa[3][j] = 200;
                }
                for(int j=12 ; j<18 ; j++)
                {
                    mapa[4][j] = 200;
                }
                for(int j=13 ; j<20 ; j++)
                {
                    mapa[5][j] = 200;
                }
                for(int j=12 ; j<19 ; j++)
                {
                    mapa[6][j] = 200;
                }
                mapa[7][11] = 200;
                mapa[7][12] = 200;
                mapa[7][15] = 200;
                mapa[7][17] = 200;
                mapa[8][17] = 200;

                //Segundo Lago
                mapa[15][8] = 200;
                mapa[16][7] = 200;
                mapa[16][8] = 200;
                mapa[16][10] = 200;
                mapa[17][12] = 200;
                for(int i=17 ; i<20 ; i++)
                {
                    for(int j=6 ; j<12 ; j++)
                    {
                        mapa[i][j] = 200;
                    }
                }
                for(int j=5 ; j<11 ; j++)
                {
                    mapa[20][j] = 200;
                }
                for(int j=4 ; j<12 ; j++)
                {
                    mapa[21][j] = 200;
                }
            }
            /* -------------------------------------------------------------------------------------------------- */

            /* -------------------------------------------------------------------------------------------------- */
                                        /* --- DESENHO DAS ÁRVORES --- */
            //Chave para abrir os FORs do desenho das ÁRvores
            {
                for(int j=1 ; j<=4 ; j++)
                        mapa[1][j] = 40;
                mapa[1][9] = 40;
                mapa[1][12] = 40;
                for(int j=18 ; j<=21 ; j++)
                        mapa[1][j] = 40;
                for(int j=1 ; j<=3 ; j++)
                        mapa[2][j] = 40;
                mapa[2][5] = 40;
                mapa[2][7] = 40;
                for(int j=19 ; j<=21 ; j++)
                        mapa[2][j] = 40;
                mapa[3][2] = 40;
                mapa[3][3] = 40;
                mapa[4][3] = 40;
                mapa[4][4] = 40;
                for(int j=7 ; j<=10 ; j++)
                        mapa[4][j] = 40;
                mapa[4][20] = 40;
                mapa[5][2] = 40;
                for(int j=8 ; j<=10 ; j++)
                        mapa[5][j] = 40;
                mapa[6][9] = 40;
                mapa[6][10] = 40;
                for(int j=5 ; j<=7 ; j++)
                        mapa[8][j] = 40;
                mapa[8][12] = 40;
                mapa[9][6] = 40;
                mapa[11][4] = 40;
                mapa[11][9] = 40;
                mapa[11][14] = 40;
                mapa[11][20] = 40;
                mapa[12][1] = 40;
                mapa[12][3] = 40;
                mapa[12][8] = 40;
                mapa[12][9] = 40;
                mapa[12][13] = 40;
                mapa[12][15] = 40;
                mapa[12][21] = 40;
                for(int j=1 ; j<=3 ; j++)
                {
                        mapa[13][j] = 40;
                        mapa[13][j+12] = 40;
                }
                mapa[13][20] = 40;
                for(int j=1 ; j<=4 ; j++)
                        mapa[14][j] = 40;
                for(int j=12 ; j<=16 ; j++)
                        mapa[14][j] = 40;
                for(int j=19 ; j<=21 ; j++)
                        mapa[14][j] = 40;
                for(int j=1 ; j<=3 ; j++)
                        mapa[15][j] = 40;
                mapa[15][16] = 40;
                mapa[15][21] = 40;
                mapa[16][1] = 40;
                mapa[16][2] = 40;
                mapa[17][1] = 40;
                mapa[17][3] = 40;
                mapa[18][15] = 40;
                mapa[18][18] = 40;
                mapa[18][19] = 40;
                mapa[19][12] = 40;
                mapa[19][17] = 40;
                mapa[19][18] = 40;
                mapa[19][21] = 40;
                mapa[20][11] = 40;
                mapa[20][12] = 40;
                for(int j=16 ; j<=18 ; j++)
                        mapa[20][j] = 40;
                mapa[21][3] = 40;
                mapa[21][12] = 40;
                mapa[21][13] = 40;
                for(int j=17 ; j<=19 ; j++)
                        mapa[21][j] = 40;
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
