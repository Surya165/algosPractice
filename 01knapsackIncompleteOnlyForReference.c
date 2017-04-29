#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct item
{
	float weight;
	float value;
	int level;
};
struct queue
{
	int *array;
	int start;
	int end;
	
};
int pop(struct queue)
int main()
{
	int numberOfItems,i;
	printf("Enter the number of items\n");
	scanf("%d",&numberOfItems);



	struct item *items;
	items = ( struct item * ) calloc ( numberOfItems, sizeof(struct item));

	
	for ( i = 0; i < numberOfItems; i ++ )
	{
		scanf("%f%f", &items[i].weight,&items[i].value);
	}
	


	struct queue *Q;
	Q = (struct queue *) calloc ( 1, sizeof(struct queue));

	Q -> array = ( int * ) calloc ( numberOfItems,sizeof(int));
	int bag[numberOfItems];
	
	
	

}
