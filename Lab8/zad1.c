#include<stdio.h> //tydzien 11 lab 9 zad 1
#include<stdlib.h>
#include<time.h>

const int N=20;
const int a=2;
const int b=20;

union unia
{
    int calk;
    double rzecz;
};
struct liczbaCalRzecz
{
    char znak;
    union unia u;
};
int rand_i()
{
    return a+rand()%(b-a+1);
}
double rand_d()
{
    return (a+(rand()/(RAND_MAX+1.))*(b-a));
}
void wypisz(struct liczbaCalRzecz *liczby, int i)
{
    if(liczby[i].znak=='i')
        printf("%d.\t%c: %d\n", i+1, liczby[i].znak, liczby[i].u.calk);
    else
        printf("%d.\t%c: %f\n", i+1, liczby[i].znak, liczby[i].u.rzecz);
}
void bubblesort(struct liczbaCalRzecz *liczby)
{
	float temp;
	for (int i=0; i<N-1; ++i)
    {
		for (int j=0; j<N-1-i; ++j)
		{
		    if(liczby[j].znak=='i'&&liczby[j+1].znak=='i')
            {
                if(liczby[j].u.calk>liczby[j+1].u.calk)
                {
                    temp=liczby[j+1].u.calk;
                    liczby[j+1].u.calk=liczby[j].u.calk;
                    liczby[j].u.calk=temp;
                }
            }
            if(liczby[j].znak=='d'&&liczby[j+1].znak=='d')
            {
                if(liczby[j].u.rzecz<liczby[j+1].u.rzecz)
                {
                    temp=liczby[j+1].u.rzecz;
                    liczby[j+1].u.rzecz=liczby[j].u.rzecz;
                    liczby[j].u.rzecz=temp;
                }
            }
			if((liczby[j].znak=='d'&&liczby[j+1].znak=='i'))
			{
			    liczby[j].znak='i';
			    liczby[j+1].znak='d';
				temp=liczby[j+1].u.calk;
				liczby[j+1].u.rzecz=liczby[j].u.rzecz;
				liczby[j].u.calk=temp;
			}
		}
    }
}

int main()
{
    srand(time(NULL));
    struct liczbaCalRzecz *liczby=calloc(N, sizeof(struct liczbaCalRzecz));
    for(int i=0; i<N; ++i)
    {
        if(rand()%2)
        {
            liczby[i].znak='i';
            liczby[i].u.calk=rand_i();
        }
        else
        {
            liczby[i].znak='d';
            liczby[i].u.rzecz=rand_d();
        }
    }
    for(int i=0; i<N; ++i)
        wypisz(liczby, i);

    printf("Po sortowaniu:\n");
    bubblesort(liczby);

    for(int i=0; i<N; ++i)
        wypisz(liczby, i);

    return 0;
}
