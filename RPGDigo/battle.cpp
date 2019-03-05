#include "bibliotecas.h"
#include "defines.h"
#include "funcoes.h"

void battle (int *idMob, char *playerNome, int *playerLevel, int *playerHp, int *playerExp, int *playerAtk, int *playerDef, int *playerAtkM, int *playerDefM)
{
    /* ------------------------------------------------------------------------------------ */
                        /* --- VARIÉVEIS PARA MOBs/BOSS --- */
    char mobNome[100];
    int mobHp, mobExp, mobAtk, mobDef, mobAtkM, mobDefM;
    /* ------------------------------------------------------------------------------------ */

    if(*idMob > 10000)                                                          //BOSSes ID começam em 10.001
        //FAZER a função BOSS(); igual a MOB();
        printf("");
    else                                                                        //MOBs ID começam em 1
        mob(&idMob, mobNome, &mobHp, &mobExp, &mobAtk, &mobDef, &mobAtkM, &mobDefM);

    /* ------------------------------------------------------------------------------------ */
                        /* --- BATTLE --- */
    bool winBattle = 0;
    bool loseBattle = 0;
    bool fugiu = 0;
    int dano;

    do
    {
        system("cls");

        printf("\n\t\t\tBATTLE:");
        if(*idMob > 10000)
            printf("\n\nID<%d> BOSS : %s",*idMob,mobNome);
        else
            printf("\n\nID<%d> MOB : %s",*idMob,mobNome);
        printf("\nHP : %d",mobHp);
        printf("\nEXP : %d",mobExp);
        printf("\nATK : %d",mobAtk);
        printf("\nDEF : %d",mobDef);
        printf("\nATKM : %d",mobAtkM);
        printf("\nDEFM : %d",mobDefM);

        printf("\n\n");

        printf("\nPLAYER : %s",playerNome);
        printf("\nLEVEL : %d",*playerLevel);
        printf("\nHP : %d",*playerHp);
        printf("\nEXP : %d",*playerExp);
        printf("\nATK : %d",*playerAtk);
        printf("\nDEF : %d",*playerDef);
        printf("\nATKM : %d",*playerAtkM);
        printf("\nDEFM : %d",*playerDefM);

        printf("\n\n");

        int op;
        printf("\nEscolha a acao:");
        printf("\n1 - FUGIR"
               "\n2 - ATK"
               "\n3 - SKILLS"
               "\n4 - BACKPACK");
        fflush(stdin);
        scanf("%d",&op);

        switch(op)
        {
            default:
                printf("\nNao ha esta opcao... VOCE ESTA CONFUSO???");
            break;

            case 1:
                ///ARRUMAR A FUGA PARA COLOCAR PORCENTAGEM DE NAO FUGIR ??? POR MAPA ?? POR MOB ?? POR LVL do MOB ??
                fugiu = 1;
            break;

            case 2:
                dano = *playerAtk - mobDef;
                printf("\nVoce HITOU %s em %d de DANO!",mobNome,dano);
                mobHp -= dano;
            break;

            case 3:
            break;

            case 4:
            break;
        }
        getch();

        if(mobHp > 0 && fugiu != 1) //Se a vida do MOB é positiva, logo está vivo e pode atacar o player, caso não tenha fugido...
        {
            dano = mobAtk - *playerDef;
            printf("\n%s HITOU voce em %d DANO!",mobNome,dano);
            *playerHp -= dano;
            getch();
        }
        else if(fugiu == 0)
            winBattle = 1;

        if(*playerHp <= 0)         //Se o PLAYER não tiver HP, morreu e perdeu a battle... << winBattle recebe 0, pois caso ele tenha eliminado o MOB, ainda pode morrer de veneno, fogo, contra-ataque...>>
        {
            winBattle = 0;
            loseBattle = 1;
        }


    }while(winBattle != 1 && loseBattle != 1 && fugiu != 1);
    /* ------------------------------------------------------------------------------------ */

    system("cls");
    printf("\n\n\t\tRESULTADO DA BATTLE : ");
    if(winBattle == 1)
        printf("WIN !");
    else if(loseBattle == 1)
        printf("LOSE !");
    else if(fugiu == 1)
        printf("FUGA COM SUCESSO !");
    else
        printf("ERRO DE RESULTADO!!");
    getch();

    *idMob = 0;
}
