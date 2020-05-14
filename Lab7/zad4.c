#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 10
struct wektor
{
    double x;
    double y;
};
struct abc
{
    struct wektor w;
    double dlugosc;
};
int comparedlugosc(const void *arg1, const void *arg2)
{
    struct abc * key=(struct abc *)arg1;
    struct abc * y=((struct abc *)arg2);

    if(1,1*(y->dlugosc)>=(key->dlugosc)&&(0,9*(y->dlugosc)<=(key->dlugosc)))
       return key;
    else
        return NULL;
}
int comparedlugoscsort(const void *arg1, const void *arg2)
{
    struct abc * x=((struct abc *)arg1);
    struct abc * y=((struct abc *)arg2);
    return x->dlugosc-y->dlugosc;
}
void obliczdlugosc(struct abc * temp)
{
    for(int i=0;i<N;i++)
    {
        temp[i].dlugosc=sqrt(temp[i].w.x*temp[i].w.x+temp[i].w.y*temp[i].w.y);
    }
}
int main()
{
    struct abc key;
    struct abc * temp;
    scanf("%f",&key.dlugosc);
    struct abc tab[N];
    srand(time(NULL));
    for(int i=0;i<N;i++)
    {
        tab[i].w.x=rand()%50;
        tab[i].w.y=rand()%50;
    }
    obliczdlugosc(tab);
    qsort(tab, N, sizeof(struct abc), comparedlugoscsort);
    for(int i=0;i<N;i++)
    {
        printf("%f\n",(tab+i)->dlugosc);
    }
    temp=bsearch (&key, tab, N, sizeof(struct abc),comparedlugosc);
    printf("\n%f",temp->dlugosc);
    return 0;
}
