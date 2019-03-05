#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<locale.h>


void troca (int a[][5])
{
    int b[5][5];

    printf("\n2 :\n");
    for(int i=0; i<5 ; i++)
    {
        for(int j=0; j<5; j++)
        {
            a[i][j] ++;
            b[i][j] = 5;
            printf(" %d | %d   ",a[i][j], b[i][j]);
        }
        printf("\n");
    }


    printf("\n3 :\n");
    for(int i=0; i<5 ; i++)
    {
        for(int j=0; j<5; j++)
        {
            a[i][j] = b[i][j];
            printf(" %d | %d   ",a[i][j], b[i][j]);
        }
        printf("\n");
    }
}

int main ()
{
    int a[5][5];

    printf("\n1 :\n");
    for(int i=0; i<5 ; i++)
    {
        for(int j=0; j<5; j++)
        {
            a[i][j] = 1;
            printf(" %d ",a[i][j]);
        }
        printf("\n");
    }

    troca(a);

    printf("\n4 :\n");
    for(int i=0; i<5 ; i++)
    {
        for(int j=0; j<5; j++)
        {
            printf(" %d ",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
