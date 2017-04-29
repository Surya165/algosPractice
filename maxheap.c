#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void createArray(int * array, int n)
{
	time_t t;
        srand((unsigned) time(&t) );
	int i;
	for ( i = 0; i < n; i ++ )
	{
		array[i] = rand()%101;
	}
}
void printArray(int *a, int n,char *message)
{
	printf("%s\n",message);
	int i;
	for ( i = 0; i < n; i ++ )
	{
		printf("%d ",a[i] );
	}
	printf("\n");
}
void restoreUp(int *heap, int index)
{
	int parent,temp;
	parent = index/2;
	while(parent >= 0 && heap[parent] < heap[index])
	{
		temp = heap[parent];
		heap[parent] = heap[index];
		heap[index] = temp;
		
		index = parent;
		parent = index / 2;
	}
}
int greaterKey(int left, int right, int *heap)
{
	if(heap[left] > heap[right] )
		return left;
	else
		return right;
}
void restoreDown(int *heap, int index, int numberOfElements)
{
	int left,right,temp,i;
	left = index * 2+ 1;
	right = index * 2 + 2;
	while(heap[greaterKey(left,right,heap)] > heap[index] && right < numberOfElements )
	{
		i = greaterKey(left,right,heap);
		temp = heap[i];
		heap[i] = heap[index];
		heap[index] =temp;
		index = i;
		left = index * 2 + 1;
		right = index * 2 + 2;
		
	}
}
int addElementToMaxHeap(int *heap, int index, int element)
{
	heap[index] = element;
	restoreUp(heap,index);
	index ++;
	return index;
}
int* maxHeapify(int *array, int n)
{
	int i;
	int *b;
	b = (int * )calloc ( n, sizeof(int));
	for ( i = 0; i < n ;)
	{
		i = addElementToMaxHeap(b,i,array[i]);
	}
	return b;
}
int checkIfMaxHeap(int *array, int numberOfElements)
{
	int i,parent;
	for ( i = numberOfElements - 1; i > 0 ; i -- )
	{
		parent = i / 2;
		if( array[parent] < array[i] )
		{
			return 0;
		}

	}
	return 1;
}
void increaseValueOfElement( int * heap, int index, int element )
{
	heap[index] = element;
	restoreUp(heap,index);
}
int extractMax(int *heap , int *numberOfElements)
{
	int maxValue = heap[0];
	heap[0] = heap[*numberOfElements - 1];
//	printf("%d\n",*numberOfElements);
	(*numberOfElements)--;
	restoreDown(heap,0,*numberOfElements);
	return maxValue;
}
int main()
{
	int *array,yes,element,index,*sortedArray,temp;
	time_t t;
	srand((unsigned) t );
	int numberOfElements;
	scanf("%d",&numberOfElements);

	array = (int * )calloc(numberOfElements,sizeof(int));
	createArray(array,numberOfElements);
	printArray(array,numberOfElements,"This is the initial array");

	array = maxHeapify(array,numberOfElements);
	printArray(array,numberOfElements,"This is the maxHeapified array");
	
	printf("Implementing the checkIfMaxHeapFunction: %d\n",checkIfMaxHeap(array,numberOfElements));
	
	printf("Want to add an element to the heap?\n");
	scanf("%d",&yes);
	if(yes)
	{
		printf("Enter the element to be added: ");
		scanf("%d",&element);
		numberOfElements = addElementToMaxHeap(array,numberOfElements,element);
		printArray(array,numberOfElements,"The heap after the element is added");
		printf("Check if max heap: %d\n", checkIfMaxHeap(array,numberOfElements));
	}
	else
		printf("Thank you for your time\n");






	printf("Want to increase the value of  an element in the heap?: ");
	scanf("%d", &yes );
	if(yes)
	{
		printf("Enter the index at which the element is in the heap: ");
		scanf("%d",&index);
		printf("Enter the new increase value: ");
		scanf("%d",&element);
		while ( 1)
		{
			if(element > array[index] )
			{
				break;
			}
			else
			{
				printf("Please enter a value greater than the original value: ");
				scanf("%d",&element);
			}
		}
		increaseValueOfElement(array,index,element);
		printArray(array,numberOfElements,"\nThe heap after increasing the element");
	}
	else
	{
		printf("Thank you for your time\n");
	}




	printf("Want to print the array sorted by the heapsort algo?\n");
	scanf("%d",&yes);
	if(yes)
	{
		sortedArray = (int * ) calloc ( numberOfElements, sizeof(int));
		index = 0;
		
		temp = numberOfElements;
		while(numberOfElements > 0)
		{
//			printf("Before Sorted array in the while loop\n");
			sortedArray[index] =  extractMax(array,&numberOfElements);	
			index ++;
//			printf("AFter sorted array in the while loop\n");
		}
		printArray(sortedArray,temp,"The sorted array is");
	}
	else
	{
		printf("Thank you for you time\n");
	}

























}
