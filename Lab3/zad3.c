#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int * sieve(int n)
{
    int i,j,where;
    int *arr=calloc(n, n*sizeof(int));
    where=floor(sqrt(n));
    for (i=1; i<=n; i++)
        arr[i]=1;
    for (i=2; i<=where; i++)
    {
        if (arr[i] != 0)
        {
            j=i+i;
            while (j<=n)
            {
                arr[j] = 0;
                j+=i;
            }
        }
    }
    return arr;
}

int main(void)
{
    int * arr;
    int n,primecount=0,j=0;
    scanf("%d",&n);
    arr=sieve(n);
    for (int i=2; i<=n; i++)
        if (arr[i]!=0)
        {
            printf("%d ",i);
            primecount++;
        }
    printf("ilosc = %d ",primecount);
    int *arr2=calloc(n, primecount*sizeof(int));
    for (int i=2; i<=n; i++)
        if (arr[i]!=0)
        {
            arr2[j++]=i;
        }
        free(arr);
        free(arr2);
}
