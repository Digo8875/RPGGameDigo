#include "bibliotecas.h"
#include "defines.h"
#include "funcoes.h"

void sorteioMobAnda (bool *andou, int *numeroMapa, int *idMob)
{
    int sorteio;

    switch (*numeroMapa)
    {
        //Map1 "Skarttan"
        case 1:
        break;

        //Map2 "Forest1"
        case 2:
            sorteio = 1 + rand()%100;

            printf("SORTEADO > ");
            if(sorteio == 77)
            {
                printf("BOSS");
            }
            else if(sorteio >= 70)
            {
                sorteio = 1 + rand()%100;
                if(sorteio >= 1)
                    *idMob = 1;
            }
            else
                printf("ANDOU");

            getch();
        break;

        //Map3 "Forest2"
        case 3:
            sorteio = 1 + rand()%100;

            printf("SORTEADO > ");
            if(sorteio == 77)
            {
                printf("BOSS");
            }
            else if(sorteio >= 70)
            {
                sorteio = 1 + rand()%100;
                if(sorteio >= 1)
                    *idMob = 1;
            }
            else
                printf("ANDOU");

            getch();
        break;

        default:
            printf("ERRO NUMERO DE MAPA... funcao sorteioMobAnda");
        break;
    }

    *andou = 0;
}
