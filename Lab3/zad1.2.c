#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    printf("\n");
    int *tab=calloc(n, 2*sizeof(int));
    tab[1]=1;
    for(int i=0; i<n+1; i++)
    {
        for(int j=i; j>0; j--)
            tab[j+1]+=tab[j];
        realloc (tab, i-1);
        printf("%d    ",i);
        for(int j=n-i; j>0; j--)
            printf("  ");
        for(int j=1; j<=i+1; j++)
        {
            printf("%d ",tab[j]);
            printf("   ");
        }
        printf("\n");
    }
    free(tab);
}

