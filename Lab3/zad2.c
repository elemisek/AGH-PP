#include <stdio.h>
void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void sort(int a, int b, int c)
{
    printf("1. a = %d, b = %d, c = %d ", a, b, c);
    if(a>b)
    {
        swap(&a, &b);
        printf("2. a = %d, b = %d, c = %d " ,a, b, c);
    }
    if(a>c)
    {
        swap(&b, &c);
        swap(&a, &b);
        printf("3. a = %d, b = %d, c = %d " ,a, b, c);
    }
    if(b>c)
    {
        swap(&b, &c);
        printf("3. a = %d, b = %d, c = %d ",a, b, c);
    }
    else
        printf("4. a = %d, b = %d, c = %d ", a, b, c);
    printf("\n\n");
}
int main(void)
{
    int a, b, c;
    printf("Podaj trzy liczby:\n");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    printf("\n");
    sort(a, b, c);
    sort(a, c, b);
    sort(b, a, c);
    sort(b, c, a);
    sort(c, a, b);
    sort(c, b, a);
}

