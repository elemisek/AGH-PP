#include <stdio.h>

int main()
{
    int x[5], y[30][8][2];

    int *px;
    px=x;

    int (*py)[8][2];
    py=y;

    int (*pz)[2];
    pz=y[2];

}
