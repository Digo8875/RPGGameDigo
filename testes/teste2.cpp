#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<locale.h>

//SITE http://www.caracteresespeciais.com/2009/09/lista-de-atalhos-do-teclado-para.html

int main ()
{
    for(int i=0; i<255 ; i++)
    {
        printf("\nCARACTERE > %c                VALOR > %d",i,i);
    }

    getch();
    return 0;
}
