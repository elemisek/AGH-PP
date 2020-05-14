#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void rand_int(int *tab, int size)
{
	for(int i=0; i<size; i++)
		tab[i]=rand()%10;
}
int suma(int *TAB, int numer, int size)
{
	int sum=0;
	for(int i=0; i<size; i++)
	{
		sum+=*(TAB+i);
	}
	return sum;
}
void wypisz(int *tab, int size)
{
	for(int i=0; i<size; i++)
		printf("%d ", tab[i]);
	printf("\n");
}

int main(void)
{
	srand(time(NULL));
	int T_1[4]={0}, T_2[6], T_3[3], T_4[2], T_5[4];
	int Tr[5]={4,6,3,2,4};
	int *TAB[5]={T_1, T_2, T_3, T_4, T_5};
	int licznik=0;
	rand_int(T_1, Tr[licznik++]);
	rand_int(T_2, Tr[licznik++]);
	rand_int(T_3, Tr[licznik++]);
	rand_int(T_4, Tr[licznik++]);
	rand_int(T_5, Tr[licznik++]);
	printf("T_1 suma: %d\n", suma(TAB[0], 1, Tr[0]));
	licznik=0;
	wypisz(T_1, Tr[licznik++]);
	wypisz(T_2, Tr[licznik++]);
	wypisz(T_3, Tr[licznik++]);
	wypisz(T_4, Tr[licznik++]);
	wypisz(T_5, Tr[licznik++]);

	printf("\nWielkosc TAB: %d", sizeof(TAB)/sizeof(int));
	return 0;
}

