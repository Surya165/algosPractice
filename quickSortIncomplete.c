#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void createArray( int *array, int start , int end )
{
	int i;
	time_t t;
	srand( ( unsigned ) time(&t));

	for ( i=  start; i <= end; i ++ )
	{
		array[i] = rand()%101;
	}
}
void printArray( int * array , int numberOfElements, char * message )
{
	int i;
	printf("%s\n",message);
	for ( i = 0; i < numberOfElements; i ++ )
	{
		printf("%d ",array[i] );
	}
	printf("\n");
}
int partition(int *array, int start, int end )
{
	int pivotIndex,i,j,pivotValue,temp,latestIndex;
	pivotValue = array[end];
	
	
}
void quickSort(int * array, int start, int end)
{
	int pivot;
	int i,j,temp;
	if( end - start + 1 <= 3 )
	{
		for ( i = start; i <= end ; i ++ )
		{
			for ( j = i  +1; j <= end ; j ++ )
			{
				if(array[j] < array[i] )
				{
					temp = array[i];
					array[i] = array[j];
					array[j] = temp;
				}
			}
		}
	}
	else
	{
		printf("In the else loop, start = %d, end = %d\n",start,end);
		pivot = partition(array,start,end);
		quickSort(array,start,pivot);
		quickSort(array,pivot+1,end);
	}

}
int main()
{
	int i,*array,numberOfElements;
	scanf("%d",&numberOfElements);
	array = (int * ) calloc ( numberOfElements, sizeof(int));
	createArray(array,0,numberOfElements - 1 );
	printArray(array,numberOfElements,"The array created randomly is");

	quickSort(array,0,numberOfElements - 1);
	printArray(array,numberOfElements,"The array after sorting with quicksort algorithm");
}
