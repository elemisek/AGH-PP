#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	char tekst[10000];
	char linia[1000];
	char znaki[100]={0};
	int ile=0,i=0,j=0,linie;
	scanf("%s",&tekst);
	
	while(fgets(linia,80,stdin)!=NULL)
	{
		linie++;
		while(linia[i++]!='\n')
		znaki[atoi(linia[i])]++;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
}
