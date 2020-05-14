#include <stdio.h>
#include <stdlib.h>
float rand_float ()
{

    return ((rand())/(RAND_MAX+1.));
}
void zamiana(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}
void bubblesort(float tab[], int n)
{
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (tab[j] > tab[j+1])
                zamiana(&tab[j], &tab[j+1]);
}
void odwroc(float * t,int n)
{
    for(int i=0; i<n/2; i++)
        zamiana(t+i,t+n-i);
}
void wymien_tablice(float * tab1,float * tab2,int n)
{
    for(int i=0; i<n; i++)
        zamiana(tab1+i,tab2+i);
}
void scal(float * tab1, int t1,float * tab2, int t2,float * tab3)
{
    int i,k=0,j=0;
    for(int i=0; i<t1+t2; i++)
    {
        if(tab1[j]<tab2[k]&&j<=t1)
        {
            tab3[i]=tab1[j++];
        }
        else if(tab2[k]<=tab1[j]&&k<=t2)
        {
            tab3[i]=tab2[k++];
        }


    }

}
int main(void)
{
    const int N=10;
    float N1[N], N2[N];
    for(int i=0; i<N; i++)
    {
        N1[i]=rand_float();
        N2[i]=rand_float();
    }
    bubblesort(N1,N);
    bubblesort(N2,N);






}
