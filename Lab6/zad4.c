#include <stdio.h>
#include <math.h>
#include <time.h>
#define N 1000
int rand_int (int a, int b)
{
    return (a + rand()%(b-a+1));
}

int compare(const void *x, const void *y)
{
    int m= *(int*)x;
    int n= *(int*)y;
    if(m>n)
        return -1;
    if(m==n)
        return 0;
    if(m<n)
        return 1;

}
int main()
{
    int a,b;
    int tab[N];
    scanf("%d %d",&a,&b);
    srand(time(NULL));
    if(a<b)
    {
        for(int i=0; i<N; i++)
        {
            tab[i]=rand_int(a,b);
        }
    }
    else
    {
        for(int i=0; i<N; i++)
        {
            tab[i]=rand_int(b,a);
        }
    }
    qsort(tab, N, sizeof(int), compare);
    for(int k=0; k<N; k++)
    {
        printf("%d ",tab[k]);
    }
    printf("\n");
}
