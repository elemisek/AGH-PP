#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double ff(double x)
{
	return 1+x*x;
}
double minusff(double x)
{
	return 1/(x*x);
}
int main(void)
{
	double (*p[])(double) = {sin,cos,ff,minusff,NULL};
	double (**q)(double) = p;
	for(double i=2.0;i<=30.0;i+=2.0)
	{
		while(*q)
            printf("%.5f ", (**q++)(i));
		q=p;
		printf("\n");
	}
}
