#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int add2(int *a,int *b)
{
	return *a+*b;
}
int comp2(int *a,int *b)
{
	return *a-*b;
}

int add2_or_comp2(int *a,int *b,int (*funkcja)(int*,int*))
{
	return funkcja(a,b);
}
int main()
{
	int a,b;
	int* wa=&a,wb=&b;
	scanf("%d %d",wa,wb);
	int (*add)=add2;
	int (*comp)=comp2;
	printf("%d + %d = %d\n",a,b,add2_or_comp2(wa,wb,add));
	printf("%d - %d = %d\n",a,b,add2_or_comp2(wa,wb,comp));
}
