#include <stdio.h>
#define N 4
int first = 0;
void push(int *tab, int p)
{
    if(first>=N)
    {
        printf("FULL\n");
        return;
    }
    tab[++first]=p;
    return;
}

void pop(int *tab)
{
    tab[first--]=0;
    return;
}
void show(int *tab)
{
    if(first==0)
    {
        printf("EMPTY\n");
        return;
    }

    for(int j=1; j<first+1; j++)
    {
        printf("%d ",tab[j]);
    }
    printf("\n");
    return;
}
int main()
{
    int tab[N];
    char c;
    int a;
    do
    {
        printf("0-9 - push\np - pop\ns - show\ne - exit\n");
        scanf("%c%*c", &c);
        if(c=='p')
            pop(tab);
        else if(c=='s')
            show(tab);
        else if(c>='0'&&c<='9')
        {
            push(tab,c-48);
        }
    }
    while(c!='e');


}
