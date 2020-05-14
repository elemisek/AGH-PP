#include <stdio.h>
#include <time.h>
#define N 5
int suma(const int * a, const int * b);
int rand_int (int a, int b);
int main(void)
{
    time_t czas;
    srand( (unsigned int)time(&czas) );
    int tab[N];
    int * p;
    p=NULL;
    for(p=tab; p < tab + N ; p++)
    {
        *p=rand_int(7,35);
        printf("p[%d]=%d\n", p-tab, *p);
    }
    printf("\n");
    int sum = suma(tab, tab+N);
    printf("sum=%d\n",sum);
    return 0;
}
int suma(const int * a, const int * b)
{
    int sum=0;
    const int * p;
    p=NULL;
    for(p=a; p <b ; p++)
    {
        sum+=*p;
    }
    return sum;
}
int rand_int (int a, int b)
{
    return (a + rand()%(b-a+1));    // losowane wartości całkowitej z zakresu od a do b
}
