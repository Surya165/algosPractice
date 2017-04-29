#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,*array;
	array = (int * ) calloc ( 9, sizeof(int ) );
	for ( i = 0; i < 9 ; i ++ )
		scanf("%d",&array[i]);
}
