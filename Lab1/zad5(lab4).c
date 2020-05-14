void main(void)
{
    int i,j,range,where;
    int arr[100000];
    scanf("%d",&range);
    where=floor(sqrt(range));
    for (i=1; i<=range; i++)
        arr[i]=1;
    for (i=2; i<=where; i++)
    {
        if (arr[i] != 0)
        {
            j = i+i;
            while (j<=range)
            {
                arr[j] = 0;
                j += i;
            }
        }
    }
    for (i=2; i<=range; i++)
        if (arr[i]!=0)
            printf("%d ",i);
}
