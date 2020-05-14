#include <stdio.h>
#define BINSIZE 10
void bin(int n)
{
    if(n>=2)
        bin(n/2);
    printf("%d",n%2);
}
int main (void)
{
    int liczba;
    scanf ("%d",&liczba);
    char tab[BINSIZE]="000000000";
    printf("Reprezentacja binarnia:");
    int licznik=BINSIZE-1;
    while(liczba)
    {
        tab[--licznik]+=liczba%2;
        liczba>>=1;
    }
    printf("%s\n",tab);
    bin(liczba);
    return 0;
}
