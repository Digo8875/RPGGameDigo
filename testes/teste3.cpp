#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<locale.h>


int main ()
{
    int map1[23][23];
    for(int i=0; i<23 ; i++)
    {
        for(int j=0 ; j<23 ; j++)
        {
            if((i == 0) || (j == 0) || (i == 22) || (j == 22))
            {
                map1[i][j] = 11;
            }
            else if((i==0) || (j==15))
            {
                map1[i][j] = 1;
            }
            else
            {
                map1[i][j] = 0;
            }
        }
    }






    for(int i=0; i<23 ; i++)
    {
        printf("\t\t");
        for(int j=0 ; j<23 ; j++)
        {
            if(map1[i][j] == 0)
                printf("  ");
            else if(map1[i][j] == 1)
                printf(" A");
            else if(map1[i][j] == 11)
                printf(" %c",254);
        }
        printf("\n");
    }


    return 0;
}
