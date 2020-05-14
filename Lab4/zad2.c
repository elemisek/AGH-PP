#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define wiersze 4
#define kolumny 2
int main(void)
{

    int T[wiersze][kolumny];
    int n=0;
    srand(time(NULL));
    int * wsk_2D=T;
    for(int i=0; i<wiersze; ++i)
        for(int j=0; j<kolumny; ++j)
        {
            n+=2;
            T[i][j]=n;
        }
    for(int i=0; i<wiersze; ++i)
    {
        for(int j=0; j<kolumny; ++j)
            printf("%3d  %3d  ", T[i][j], &(T[i][j]));
        printf("\n");
    }
    printf("T[0]=      %3p      &(T[0])=      %3p\n", T[0], &(T[0]));
    printf("T[0]+1=    %3p      &T[0][1]=     %3p\n", T[0]+1, &T[0][1]);
    printf("T=         %3p      &(T)=         %3p\n", T, &(T));
    printf("T+1=       %3p      &T[1]         %p\n", T+1, &(T[1]));
    printf("T[0][0]=   %3d      T=            %3p\n", T[0][0], T);
    printf("T[0][0]+1= %3d      &(T[0][0])+1= %p\n", T[0][0]+1, &(T[0][0])+1);
    printf("T[1][0]=   %3d      &(T[1][0])=   %3p\n", T[1][0], &(T[1][0]));
    for(int i=0; i<wiersze; i++)
    {
        for (int j=0; j<kolumny; j++)
        {
            printf("T[%d][%d]=%d  adres:%p\n", i, j, *(T[i]+j), T[i]+j); //
            printf("---\n");
            printf("T[%d][%d]=%d  adres:%p\n\n", i, j, *(*(T+i)+j), *(T+i)+j);
        }
        printf ("\n");
    }

    printf("----------------------------\n");

    for(wsk_2D; wsk_2D<T+4; wsk_2D++)
        printf("%d, adres: %p\n", *wsk_2D, wsk_2D);

    return 0;
}

