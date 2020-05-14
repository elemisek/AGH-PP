#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

struct zespolona
{
    double re;
    double im;
};
struct zesp_modul
{
    struct zespolona z;
    double modul;
    void (*wsk_struct)(struct zespolona);
};

double rand_d()
{
    return (rand()/(RAND_MAX+1.))*10;
}
void zesp_wypisz(struct zespolona z)
{
    printf("%lf + %lf*i", z.re, z.im);
}
void wpisz_modul(struct zesp_modul *z_m)
{
    z_m->modul=sqrt((z_m->z.re*z_m->z.re)+(z_m->z.im*z_m->z.im));
}
int comp(const void *x, const void *y)
{
    struct zesp_modul *z_m1=(struct zesp_modul*)x;
    struct zesp_modul *z_m2=(struct zesp_modul*)y;

    if(z_m1->modul>z_m2->modul)
        return 1;
    else if(z_m1->modul<z_m2->modul)
        return -1;
    else
        return 0;
}
int main(void)
{
    srand(time(NULL));
    int n;
    scanf("%d", &n);
    struct zesp_modul *tab=malloc(n*sizeof(struct zesp_modul));
    printf("\n");
    FILE *fptr = fopen("printfzad2.txt", "w");
    for(int i=0; i<n; ++i)
    {
        tab[i].z.re=rand_d();
        tab[i].z.im=rand_d();
        wpisz_modul(tab+i);

        printf("|(");
        fprintf(fptr,"|(");
        printf("%lf + %lf*i", tab[i].z.re, tab[i].z.im);
        fprintf(fptr,"%lf + %lf*i", tab[i].z.re, tab[i].z.im);
        printf(")|=%lf\n", tab[i].modul);
        fprintf(fptr,")|=%lf\n", tab[i].modul);
    }

    printf("\n\n");
    fprintf(fptr,"\n\n");
    qsort(tab, n, sizeof(struct zesp_modul), comp);
    tab->wsk_struct=zesp_wypisz;

    for(int i=0; i<n; ++i)
    {
        printf("|(");
        fprintf(fptr,"|(");
        tab->wsk_struct(tab[i].z);
        printf(")|=%lf\n", tab[i].modul);
        fprintf(fptr,"%lf + %lf*i", tab[i].z.re, tab[i].z.im);
        fprintf(fptr,")|=%lf\n", tab[i].modul);

    }
    fclose(fptr);
    free(tab);
}
