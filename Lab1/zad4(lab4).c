#include <stdio.h>
#include <time.h>
int rand_int (int a, int b)
{

  return (a + rand()%(b-a+1));    // losowane wartości całkowitej z zakresu od a do b
}
int main(void)
{
    int los,proba,a=0,b=100;
 time_t czas;
 srand( (unsigned int)time(&czas) );
    los=rand_int(a,b);
    printf("Los: %d\n",los);
    while(los!=proba)
    {
        printf("Losuje z przedzialu: %d %d\n",a,b);
        proba=rand_int(a,b);
         printf("Proba: %d\n",proba);
        if(proba>los)
            b=proba-1;
        else
            a=proba+1;
    }
}
