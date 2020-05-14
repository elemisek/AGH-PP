#include <stdio.h>
#define N 1000

void main(void)
{
    int a1[N]= {0};
    int a2[N]= {0};
    int n;
    a1[1]=1;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i+1; j++)
        {
            a2[j+1]=a1[j]+a1[j+1];
        }
        for(int j=1; j<=i+1; j++)
        {
            a1[j]=a2[j];
        }
        printf("%d    ",i);
        for(int j=n-i; j>0; j--)
        {
            printf("  ");
        }
        for(int j=1; j<=i+1; j++)
        {
            printf("%5d",a1[j]);
        }
        printf("\n");

    }

}
