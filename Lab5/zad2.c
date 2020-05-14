#include <stdio.h>
#include <stdlib.h>
float rand_float (float a, float b)
{
 
  return (a + (rand()/(1.0 * RAND_MAX)) *(b-a));    // losowane wartoœci zmiennoprzecinkowej z zakresu od a do b 
}
void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}
void norm(float * tab,int n)
{
	int suma=0,i;
	for(i=0;i<n;i++)
	{
		suma+=tab[i];
	}
	for(i=0;i<n;i++)
	{
		tab[i]/=suma;
	}
	
	
}
void sort(float * tab, int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)          
       for (j = 0; j < n-i-1; j++)  
           if (tab[j] > tab[j+1]) 
              swap(tab+j, tab+j+1); 
} 
int main(int argc, char **argv)
{
	int size,i,a,b;
	size=atoi(argv[1]);
	float *tab = malloc(size*sizeof(float));
	a=atoi(argv[2]);
	b=atoi(argv[3]);
	for(i=0;i<size;i++)
	{
		tab[i]=rand_float(a,b);	
	}
	for(i=0;i<size;i++)
	{
		printf("%f\n",tab[i]);
	}
	sort(tab,size);
	printf("\n");
	for(i=0;i<size;i++)
	{
		printf("%f\n",tab[i]);
	}
		norm(tab,size);
	printf("\n");
	for(i=0;i<size;i++)
	{
		printf("%f\n",tab[i]);
	}
	
	
	
	
	
	
	
	
	
	
}
