#include<stdio.h>
#include<stdlib.h>
/*struct node 
{
	int level;
	int array[9];
	int cost;
};

struct queue;
{
	struct node *nodes;
	int front;
	int end;
};
*/
struct listNode
{
	int array[3][3];
	int cost;
	int level;
	struct node *next;
	struct node *previous;
};
struct stack
{
	struct listNode *head;
	struct listNode *tail;
};
struct listNode * initialiseListNode ()
{
	struct listNode * node;
	node = (struct listNode * ) calloc (1,sizeof(struct listNode ));
	node -> previous = NULL;
	node -> next = NULL;
	node -> cost = 5;	
	node -> level = 5;
	return node;
}
int isEmpty(struct stack s)
{
	if(s -> last -> next  == s-> head && s -> head -> previous = s -> last )
	{
		return 1;
	}
	return 0;
}
struct listNode *top()
{
	return s -> last;
}
void pop(struct stack *s )
{
	s -> last  = s -> last -> previous;
}
void push ( struct stack *s , struct node * n )
{
	s -> last -> next = n;
	s -> last = s -> last -> next;	
}
int main()
{
	int i,j,*array,tempInteger;
	array = (int ** ) calloc ( 3, sizeof(int ) );
	for ( i = 0; i < 9 ; i ++ )
	{
		array[i] = ( int * ) calloc ( 3, sizeof( int ) );
		scanf("%d",&array[i]);
	}
	struct stack *s;
	
 	s = ( struct stack *) calloc ( 1, sizeof( struct stack ) );
	
	s -> head = ( struct listNode *  ) calloc  ( 1, sizeof( struct listNode ) ); 	
	
	struct listNode *temp;
	/*s -> head -> previous = NULL;
	s -> head -> next = NULL;
	
	s -> head -> cost = 0;
	s -> head -> level = 0;
	*/
	s -> head = initialiseListNode( );
	temp = initialiseListNode ( );
	
	s -> tail = initialiseListNode ( );
	printf("%d\n", s-> head -> level );
	
	s -> head -> array = ( int ** ) calloc (3, sizeof(int*));

	for ( i = 0; i < 3; i ++ )
	{
		s-> head -> array[i] = (int * ) calloc ( 3, sizeof ( int ) );
		for ( j = 0; j < 3; j ++ ) 
		{
			
			s->head->array[i][j]  = array[i][j];
		}
	}
	
	temp = head;
	last = head;
	
	int zeroIndexX = 0,zeroIndexY = 0,indexX,indexY ;
	while ( !isEmpty(s))
	{
		temp = top(s);
		if(isSolved(temp -> array ))
		{
			printf("Problem Solved\n");
			return 0;
		}
		for ( i = 0; i < 3; i ++ )
		{	
			for ( j = 0; j < 3; j ++ )
			{
				if( temp -> array[i][j] == 0 )
				{
					zeroIndexX  = i;
					xeroIndexY = j;
				}
			}
		}
		for ( i = 0; i < 4; i ++ )
		{
			temp -> next = initialiseListNode();
			temp -> next -> previous = temp;	
			i % 2 ? indexX=  1: indexX = -1;
			( i / 2 ) % 2 ? indexY = 1: indexY = -1;
		
	
			temp -> next -> array = temp-> array;
			 

			tempInteger = temp -> next ->array[zeroIndexX][zeroIndexY];
			temp->next -> array[zeroIndexX][zeroIndexY] = temp -> next -> array[indexX][indexY];
			temp -> next -> array[indexX][indexY] = tempInteger;

			temp -> next -> level = temp -> level + 1;
			if(isSolvable(temp->next->array))
			{
				push(s,temp -> next );
				break;
			}
		}
		pop(s);
	}
	return 0;	
	
	




}
