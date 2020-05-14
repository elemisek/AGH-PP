#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int N=5;
struct Klient
{
	char imie[20];
	char nazwisko[32];
	char kod_poczt[6];
	int wiek;
};
void input(struct Klient *ppl)
{
    for(int i=0; i<N; ++i)
		scanf("%s %s %s %d", ppl[i].imie, ppl[i].nazwisko, ppl[i].kod_poczt, &ppl[i].wiek);
}
void output(struct Klient *ppl)
{
    for(int i=0; i<N; ++i)
    {
        printf("imie %s\t nazwisko %s\n", ppl[i].imie, ppl[i].nazwisko);
        printf("kod pocztowy %s\t wiek %d\n\n", ppl[i].kod_poczt, ppl[i].wiek);
    }
}
int compare(const void *arg_1, const void *arg_2)
{
    struct Klient *prsn_1=(struct Klient *)arg_1;
    struct Klient *prsn_2=(struct Klient *)arg_2;
    
    if(!strcmp(prsn_1->nazwisko, prsn_2->nazwisko))
        return strcmp(prsn_1->imie, prsn_2->imie);
    
    return strcmp(prsn_1->nazwisko, prsn_2->nazwisko);
}
int main(int argc, char **argv)
{
	struct Klient ppl[N];
	
	input(ppl);

	output(ppl);
	printf("po:\n\n");
	qsort(ppl, N, sizeof(struct Klient), compare);

	output(ppl);
	
	return 0;
}
