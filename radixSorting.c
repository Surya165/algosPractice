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
int* countDistinctLetters(char **strings, int digit, int numberOfStrings)
{
	int i,count,*distinctLetters;
	distinctLetters = (int * ) calloc ( 26, sizeof(int));
	for ( i = 0; i < numberOfStrings; i ++ )
	{
		distinctLetters[strings[i][digit] - 65] ++;
	}
	for (  i = 0,count = 0 ;i  <numberOfStrings; i ++ )
	{
		if(distinctLetters[strings[i][digit] - 65] !=0 )	
			count ++;
	}
	return distinctLetters;

}
void countSort(char ** strings,int numberOfLetters,int numberOfStrings,int digit,char **output)
{
	int *count,i,j,numberOfDistinctLetters,*distinctLetters;
	distinctLetters = (int * ) calloc ( 26,sizeof(int));
	distinctLetters =  countDistinctLetters(strings,digit,numberOfStrings);
	char *lateralString;
	lateralString = (char*)malloc(numberOfStrings*sizeof(int));
	numberOfDistinctLetters = 0;
	for ( i = 0; i < 26; i ++ )
	{
		if(distinctLetters[i] != 0)
		{
			numberOfDistinctLetters ++;
		}   
	}






	//creating the sorted array
	int latestIndex = 0;
	char *temp;
	for ( i = 0; i < 26; i ++ )
	{

		if(distinctLetters[i] != 0 )
		{
			for ( j = 0; j < numberOfStrings; j ++ )
			{
				if(strings[j][digit] == (char)65 + i )
				{
					output[latestIndex] = strings[j];
					latestIndex ++;
				}
			}
		} 
	}



	printf("The numberOfDistinctLetters for digit %d is : %d\n",digit,numberOfDistinctLetters);
	printf("For digit %d, the frequency is:\n",digit);
	for ( i = 0; i < 26; i ++ )
	{
		printf("%c : %d\n", 65 + i, distinctLetters[i] );
	}
}
void radixSort1(char **strings, int numberOfLetters, int numberOfStrings,char **output)
{
	int digit,i;


	for ( digit = numberOfLetters-1; digit >= 0 ; digit -- )
	{	
		countSort(strings,numberOfLetters,numberOfStrings,digit,output);
	}
	//strings = output;
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




	char **output;
	output = (char**) calloc(numberOfStrings,sizeof(char*));
	for ( i = 0 ;i < numberOfStrings ; i ++ )
	{
		output[i] = (char*) calloc ( numberOfLetters, sizeof(char));
	}

	radixSort1(strings,numberOfLetters,numberOfStrings,output);
	printStrings(output,numberOfLetters,numberOfStrings,"The strings sorted by radixSort1 are");
	return 0;
}
