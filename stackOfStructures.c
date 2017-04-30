#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct node 
{
	int x;	
	//this is an aribitary structure, customise it when using this code in other code.
};
struct stack
{
	struct node *array;
	int top;
};
void push(struct stack *s, struct node temp)
{
	s ->top ++;
	if ( s -> top == 0 )
	{
		s -> array = ( struct node * ) calloc ( 1, sizeof( struct node ) );
	}
	else
	{
		s -> array = ( struct node * ) realloc ( s -> array, ( s -> top + 1 ) *sizeof( struct node ) );
	}
	s -> array[ s -> top] = temp;
//	printf("%d\n" ,s -> array [s -> top ].x );
}
int isEmpty( struct stack *s )
{
	if ( s-> top == -1)	
		return 1;
	return 0;
}
struct node  pop( struct stack *s )
{
	struct node temp;
	int top;	
	top = s -> top;
	s -> top --;
	if ( top != 0 )
	{
		s -> array = ( struct node * ) realloc (  s -> array , ( top ) * sizeof( struct node ) );
	}
	else
	{
		free ( s -> array );
	}
	return s -> array [ top ];
}
void printStack(struct stack *s, char * message )
{
	struct node temp;
	printf("%s\n",message);
	while(!isEmpty(s))
	{
		temp = pop(s);
		printf("%d ",temp.x);
	}
	printf("\n");
}
int main()
{
	time_t t;
	srand((unsigned) time ( &t));
	




	int numberOfNodes,i;
	printf("Enter the number of nodes\n");
	scanf("%d",&numberOfNodes);
	
	struct stack *s;
		
	s = ( struct stack * ) calloc ( 1, sizeof( struct stack ) );
	s -> top = -1;	
	
	struct node temp;
	
		
	printf("This is the array of random numbers\n");
	for ( i  = 0 ; i < numberOfNodes ; i ++ )
	{
		temp.x = rand() % 100;
		printf("%d ",temp.x);
		push( s, temp ); 
	}
	printf("\n");
	printStack(s,"This is the stack that is created by random numbers\n");
	
}
