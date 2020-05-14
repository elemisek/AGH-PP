#include <stdio.h>
#include <time.h>
int rand_int (int a, int b)
{

  return (a + rand()%(b-a+1));    // losowane wartości całkowitej z zakresu od a do b
}
int main(void)
{
    int los,proba,a=0,b=100,suma=0;
 time_t czas;
 srand( (unsigned int)time(&czas) );
    for(int i=0;i<100;i++)
    {
    a=0;
    b=100;
    los=rand_int(a,b);
    while(los!=proba)
    {
        suma++;
        proba=rand_int(a,b);
        if(proba>los)
            b=proba-1;
        else
            a=proba+1;
    }
    }
    printf("%f",suma/100.);
}
