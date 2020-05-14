#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	char tekst[100];
	char wyraz[10];
	int ile=0,i=0,j=0;
	scanf("%s",&tekst);
	
	while(tekst!=NULL)
	{
		while(tekst[i]==argv[1][j])
		{
		j++;
		}
		if(argv[1][j]==NULL)
		ile++;
		j=0;
	}
	printf("%d", ile);
	
	
	
	
	
	
	
	
	
	
	
}
