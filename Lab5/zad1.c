#include <stdio.h>
#include <stdlib.h>
//int main(int argc, char *argv[]) // (argument count, argument values)
//int main(int argc, char **argv) // posta  alternatywna ć

//1.  Wypisz ile jest argumentów (argc)
//2.W pętli wypisz argumenty
//printf(''%d: %s\n'',arg_no, argv[arg_no])
//3. dokonaj konwersji łańcuchów znaków na liczby przy pomocy funkcji:
//atoi() (alphanumeric to integer), atof(), atol()

/*np.liczba= atoi(argv[1]))
jeśli argument nie jest rozpoznawalny jako liczba funkcja zwraca wartość 0
Wykonaj  test dla przykładowych argumentów :
np. a.out    jeden  2  4.5*/
int main(int argc, char **argv)
{
int i;
char * n;
char napis[80];
scanf("%s",&napis);
printf("%s\n",napis);
getchar();
n = gets(napis); 
if(n != NULL)
    puts(napis);
    else
    puts("blad odczytu");   
printf("%s\n",n);
fgets(napis, 80, stdin );
printf("%s\n",napis);
//Wypisanie argumentow:
 printf("argc = %d\n", argc);
  for(i=0; i<argc; i++)
    {
  printf("argv[%d] = %s\n", i, argv[i]);
  }

  //2. Konwersja lancucha
  // ./1 <integer> <float> <char>
  printf("%c %f %ld\n", atoi(napis),atof(napis),atol(napis));
  int integer = atoi(argv[1]);
  float floatNumber = atof(argv[2]);
  printf("Integer: %d, Float: %0.2f\n", integer, floatNumber);
}
