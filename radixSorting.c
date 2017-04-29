#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void printStrings(char **strings, int numberOfLetters, int numberOfStrings, char * message)
{
	printf("%s\n",message);
	int i,j;
	for ( i = 0 ; i < numberOfStrings; i ++ )
	{
		for ( j = 0; j < numberOfLetters; j ++ )
		{
			printf("%c",strings[i][j]);
		}
		printf("\n");
	}
}
void countSort(char ** strings,int numberOfLetters,int numberOfStings,int digit)
{
	int *count,numberOfdistinctLetters;
	numberOfdistinctLetters = countDistinctLetters();
	char *lateralString;
	lateralString = (char*)malloc(numberOfStrings*sizeof(int));
}
void radixSort1(char **strings, int numberOfLetters, int numberOfStrings)
{
	int digit,j;
	for ( digit = numberOfLetters-1; digit >= 0 ; digit -- )
	{	
		countSort(strings,numberOfLetters,numberOfStrings,digit);
	}
}
int main()
{
	char c,**strings;
	time_t t;
	int i,j,numberOfStrings,numberOfLetters;
	srand ( (unsigned)  time(&t));
	scanf("%d%d",&numberOfStrings,&numberOfLetters);
	
	strings = ( char ** ) malloc ( numberOfStrings*sizeof(char*));
	for ( i = 0 ; i < numberOfStrings; i ++ )
	{
		strings[i] = (char * ) malloc ( numberOfLetters *sizeof(char));
//		printf("Strings[%d] is created\n",i);
		for ( j = 0; j < numberOfLetters; j ++ )
		{
			strings[i][j]  = 65 + rand() % 26; 
		}
//		printf("you passed the for loop\n");
	}
	printStrings(strings,numberOfLetters,numberOfStrings,"The strings created by random are ");
	
	radixSort1(strings,numberOfLetters,numberOfStrings);
	printStrings(strings,numberOfLetters,numberOfStrings,"The strings sorted by radixSort1 are");
	return 0;
}
