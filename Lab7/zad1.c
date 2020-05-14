#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 10
#define M 16
int rand_int(int x)
{
    return x+rand()%26;
}
int compare(const void *arg1, const void *arg2)
{
    char x=*((const char *)arg1);
    char y=*((const char *)arg2);
    char xl=tolower(x);
    char yl=tolower(y);
    if(xl==yl)
    {
        return x-y;
    }
    return xl-yl;
}
int comparestring(const void *arg1, const void *arg2)
{
    char *x=(char *)arg1;
    char *y=(char *)arg2;
    char xl;
    char yl;
    for(int i=0; i<M; i++)
    {
        xl=tolower(*(x+i));
        yl=tolower(*(y+i));
        if(xl==yl)
        {
            if(x[i]!=y[i])
                return x[i]-y[i];
            i++;
        }
        else
            return xl-yl;
    }
    return 0;

}
int main(int argc, char **argv)
{
    srand(time(NULL));
    char str[N][M];
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            if(j%2)
                str[i][j]=rand_int(97);
            else
                str[i][j]=rand_int(65);
        }
        str[i][M-1]='\0';
    }
    for(int i=0; i<N; ++i)
        qsort(str[i], M-1, sizeof(char), compare);
    for(int i=0; i<N; ++i)
        printf("%s\n", str[i]);
    printf("\n\n");
    qsort(str[0], N, M*sizeof(char), comparestring);
    for(int i=0; i<N; ++i)
        printf("%s\n", str[i]);
}
