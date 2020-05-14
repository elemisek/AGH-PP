#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    printf("\n");
    int *tab1=calloc(n, (n+1)*sizeof(int));
    int *tab2=calloc(n, (n+1)*sizeof(int));
    tab1[1]=1;

    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<=i+1; j++)
            tab2[j+1]=tab1[j]+tab1[j+1];

        for(int j=1; j<=i+1; j++)
            tab1[j]=tab2[j];

        printf("%d    ",i);

        for(int j=n-i; j>0; j--)
            printf("  ");

        for(int j=1; j<=i+1; j++)
        {
            printf("%d ",tab1[j]);
            printf("   ");
        }
        printf("\n");
    }
    free(tab1);
    free(tab2);
}
