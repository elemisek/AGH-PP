#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 5
int rand_int(int a, int b)
{
    return (a+rand()%(b-a+1));
}
int avg_sum(int *arr, int *avg)
{
    int sum=0, i;
    for(i=0; i<N; i++)
        sum+=arr[i];
    *avg=sum/N;
    return sum;
}
int main(void)
{
    srand(time(NULL));
    int arr[N][N];
    int *sw=calloc(N, N*sizeof(int));
    int *sk=calloc(N, N*sizeof(int));
    int avg=0, temp, sum_all=0,a=1, b=10;
    int i, j, sum_w=0, sum_k=0;

    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            arr[i][j]=rand_int(a,b);

    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
            printf("%d	", arr[i][j]);
        printf("\n\n");
    }
    for(i=0; i<N; i++) {
        sw[i]=avg_sum(*(arr+i), &avg);
        sum_w+=sw[i];
        printf("%d\n\n", sw[i]);
    }

    for(i=0; i<N; i++)
        for(j=i; j<N; j++)
        {
            temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++)
            printf("%d	", arr[i][j]);
        printf("\n\n");
    }
    for(i=0; i<N; i++) {
        sk[i]=avg_sum(*(arr+i), &avg);
        sum_k+=sk[i];
        printf("%d\n\n", sk[i]);
    }

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            sum_all+=arr[i][j];
    printf("Suma wiersze: %d\nSuma kolumny: %d\n", sum_w, sum_k);
    printf("Suma elementy: %d\n", sum_all);
    free(sw);
    free(sk);


    return 0;
}
