#include <stdio.h>
int suma_szeregu(int x, int n)
{
if(n==1)
    return x;
return x*suma_szeregu(x,n-1)+x;
}
int main()
{
    printf("%d",suma_szeregu(2,2));

}
