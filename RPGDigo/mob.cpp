#include "bibliotecas.h"
#include "defines.h"
#include "funcoes.h"

void mob (int **idMob, char *mobNome, int *mobHp, int *mobExp, int *mobAtk, int *mobDef, int *mobAtkM, int *mobDefM)
{
    switch(**idMob)
    {
        //MOB ID 1 > Small Snake
        case 1:
            strcpy(mobNome,"Small Snake");
            *mobHp = 5;
            *mobExp = 1;
            *mobAtk = 2;
            *mobDef = 0;
            *mobAtkM = 0;
            *mobDefM = 0;
        break;

        default:
            printf("ERRO! MOB nao cadastrado! ID %d",**idMob);
        break;
    }
}
