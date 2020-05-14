#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float rand_float(int a,int b)
{
    return (a+(rand()/(RAND_MAX+1.))*(b-a));
}

struct elast_tab
{
    int licznik;
    float srednia;
    float (*sred)(float*,int);
    float wyniki[];
};

float srednia(float *tab,int n)
{
    float sr=0;
    for(int i=0; i<n; ++i)
        sr+=*(tab+i);
    sr/=n;
    return sr;
}

struct elast_tab *allocate(int n)
{
    struct elast_tab *e=malloc(sizeof(struct elast_tab)+n*sizeof(float));
    return e;
}

int main(void)
{
    srand(time(NULL));
    const int n=4;
    int dlugosci_elast[]={3,6,4,2};
    struct elast_tab *Tab_wsk_elast[n];

    for(int i=0; i<n; ++i)
    {
        Tab_wsk_elast[i]=allocate(dlugosci_elast[i]);
        Tab_wsk_elast[i]->licznik=dlugosci_elast[i];

        for(int j=0; j<Tab_wsk_elast[i]->licznik; j++)
            Tab_wsk_elast[i]->wyniki[j]=rand_float(0,20);

        Tab_wsk_elast[i]->sred=srednia;
        Tab_wsk_elast[i]->srednia=Tab_wsk_elast[i]->sred(Tab_wsk_elast[i]->wyniki,Tab_wsk_elast[i]->licznik);
    }

    for(int i=0; i<n; ++i)
    {
        printf("struct %d\n",i+1);
        printf("tablica wyniki[]: ");
        for(int j=0; j<Tab_wsk_elast[i]->licznik; ++j)
            printf("%f ", Tab_wsk_elast[i]->wyniki[j]);
        printf("\nsredni wynik %f \n", Tab_wsk_elast[i]->srednia);
    }

    for(int i=0; i<n; ++i)
        free(Tab_wsk_elast[i]);
    free(Tab_wsk_elast);

    return 0;
}
