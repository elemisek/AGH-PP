#include<stdio.h>
#include<stdlib.h>
#include<time.h>
float** tabl(int wiersze, int kolumny)
{
	float **tab=calloc(wiersze, sizeof(float*));
	for(int i=0; i<wiersze; ++i)
		tab[i]=calloc(kolumny, sizeof(float));
	return tab;
}
float rand_float(float a, float b)
{
	return (a+(rand()/(RAND_MAX+1.))*(b-a));
}
void rand_tab(float **tab, int wiersze, int kolumny, float a, float b)
{
	int i, j;
	for(i=0; i<wiersze; ++i)
		for(j=0; j<kolumny; ++j)
			tab[i][j]=rand_float(a,b);
}
void mnozenie(float **tab_A, float **tab_B, float **tab_C, int m, int k, int n)
{
	int i, j, l;
	float sum=0;
	for(i=0; i<m; ++i)
		for(j=0; j<n; ++j)
		{
			sum=0;
			for(l=0; l<k; ++l)
				sum+=tab_A[i][l]*tab_B[l][j];
			tab_C[i][j]=sum;
		}
}
void wypisz(float **tab, char nazw_tab, int wiersze, int kolumny)
{
	int i, j;
	printf("Tablica %c:", nazw_tab);
	printf("\n");
	for(i=0; i<wiersze; ++i)
	{
		for(j=0; j<kolumny; ++j)
			printf("%.3f  ", tab[i][j]);
		printf("\n");
	}
}
int main(void)
{
	srand(time(NULL));
	float a=12.5, b=44.0;
    int m=8,k=8,n=8;
	float **tab_A=tabl(m,k);
	float **tab_B=tabl(k,n);
	float **tab_C=tabl(m,n);
	rand_tab(tab_A, m, k, a, b);
	rand_tab(tab_B, k, n, a, b);
	mnozenie(tab_A, tab_B, tab_C, m, k, n);
	wypisz(tab_A, 'A', m, k);
	wypisz(tab_B, 'B', k, n);
	wypisz(tab_C, 'C', m, n);
}
