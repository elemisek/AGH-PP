#include <stdio.h>
#include <math.h>
#include <string.h>
void wyswietl_kropki(int kropki)
{
    for(int i=0; i<kropki; i++)
        printf(".");
}
rekurencja(int a)
{
    static int kropki=0;
    int suma;
    wyswietl_kropki(kropki++);
    printf("wartosc k=%d, adres k= %p\n",a,&a);
    if(a==1 || a==0)
    {
        --kropki;
        return 1;
    }
    else
    {
    suma=a*rekurencja(a-1);
    wyswietl_kropki(--kropki);
    printf("wartosc k=%d, adres k= %p wartosc wyn = %d adres wyn = %p\n",a,&a,suma,&suma);
    }
    return suma;
}

iteracja(int a)
{
    int b=1;
    if(a==1 || a==0)
        return 1;
    else
        for(int i=1; i<a; i++)
            b*=(i+1);
    return b;
}
int main(int argc, char *argv[])
{
    if(argc!=3)
    {
        printf("brak argumentow w linii polecen\n");
    }
    else if(strcmp(argv[2],"rekurencja")==0)
    {
        printf("rekurencja: %d\n",rekurencja(atoi(argv[1])));
    }
    else if(strcmp(argv[2],"iteracja")==0)
    {
        printf("iteracja: %d\n",iteracja(atoi(argv[1])));
    }

}
