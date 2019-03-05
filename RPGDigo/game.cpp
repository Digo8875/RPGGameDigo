#include "bibliotecas.h"
#include "defines.h"
#include "funcoes.h"

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
    int posPlayerY = 7, posPlayerX = 1;
    bool andou = 0;                                   //Variável utilizada para saber se o player andou  e sortear se terá um mob para onde andou
    char playerNome[100];
    int playerLevel, playerHp, playerExp, playerAtk, playerDef, playerAtkM, playerDefM;
    /* ------------------------------------------------------------------------------------ */

    /* ------------------------------------------------------------------------------------ */
                        /* --- VARIÉVEIS PARA MOBs/BOSS --- */
    int idMob = 0;                                   //Variável utilizada para escolha do MOB/BOSS << 0 = NENHUM ESCOLHIDO >>
    /* ------------------------------------------------------------------------------------ */


    /* ------------------------------------------------------------------------------------ */
            /* --- FAZER FUNÇÃO MENU PARA PEGAR CLASSE DO PLAYER... NOME... --- */
    strcpy(playerNome,"RPG Teste");
    playerLevel = 1;
    playerHp = 100;
    playerExp = 0;
    playerAtk = 1;
    playerDef = 0;
    playerAtkM = 0;
    playerDefM = 0;
    /* ------------------------------------------------------------------------------------ */

    do
    {
        system("cls");

        if(warp != 0)
            teleporte(&warp, &numeroMapa, &posPlayerY, &posPlayerX);                       //Chama a função TELEPORTE para decidir qual mapa irá imprimir, pois um WARP foi ativado para ir ao outro mapa.

        maps(mapa, nomeMapa, &numeroMapa, &inicio, &posPlayerY, &posPlayerX);              //Chama função dos mapas para escolher o mapa atual...
        imprimeMap(mapa, nomeMapa, &numeroMapa, &posPlayerY, &posPlayerX);                 //Chama a função para imprimir o mapa atual ao usuário...
        comandoPlayer(mapa, &posPlayerY, &posPlayerX, &numeroMapa, &warp, &andou);         //Chama a função para pegar os comandos do player...    MOVIMENTO, TECLAS, TELEPORTE...

        if(andou == 1)
            sorteioMobAnda (&andou, &numeroMapa, &idMob);

        if(idMob > 0)
            battle(&idMob, playerNome, &playerLevel, &playerHp, &playerExp, &playerAtk, &playerDef, &playerAtkM, &playerDefM);

    }while(1); //Jogo Rodando sempre... fazer parada ?
}
