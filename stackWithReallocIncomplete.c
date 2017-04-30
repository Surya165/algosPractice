#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int *array;
	int top ;
};
void push ( struct stack *s , int number )
{
	if ( s -> top == -1 )
	{
		s -> array = ( int * ) malloc ( sizeof ( int ) );
		s -> top ++;
		s -> top = number;
	}
	else 
	{
		s -> top ++;
		s -> array = ( int * )  realloc ( s -> array , (s -> top + 1 ) * sizeof ( int ) );
		s -> array [ s -> top ] = number;
	}
}
int pop(struct stack *s)
{
	int top;
	top = s -> array[s -> top ];
	s -> top --;
	if ( top == -1 )
	{
		free(s -> array);
	}
	else
	{
		s-> array = realloc ( s -> array, ( s-> top + 1) * sizeof(int));
	}
	return top;
}
void printStack(struct stack *s)
{
}
int main()
{
	struct stack *s;
	int decision,number;
	
	s = ( struct stack * ) malloc ( 1 * sizeof(struct stack ));
	
//	s -> array = ( int * ) malloc ( 1 * sizeof( struct int ));
	s -> top = -1;
	
	while ( 1 )
	{
		printf("Enter 1 for pushing a number, 2 for popping , 3 for printing all the elements in the stack, and 0 for stopping");
		scanf("%d\n",&decision);
		if(!decision)
			break;
		switch(decision)
		{
			case 1:
				scanf("%d",&number);
				push(s,number);
				printf("The number is pushed\n");
				break;
			case 2:
				printf("The popped number is %d\n",pop(s));
				break;	
			case 3: 
				printStack(s);
				break;
			default:
				break;
		}
		
	}
	
}
