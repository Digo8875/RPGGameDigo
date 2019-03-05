#include "bibliotecas.h"
#include "defines.h"
#include "funcoes.h"

int main()
{
    srand(time(NULL));
    rand();
    //system("color 0E");
    //setlocale(LC_ALL,"Portuguese"); // ***Se usar o Potuguese buga os caracteres na apresentação ao usuário...

    game();

    return 0;
}
