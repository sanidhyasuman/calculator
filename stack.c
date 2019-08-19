#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
int push(stack *s, char op)
{
	struct stack_node *n =(struct stack_node *)malloc(sizeof(struct stack_node));
	n -> data = op;
	n->next = s -> head;
	s -> head = n;
	s -> length++;
}

int display_stack(stack s)
{
	while(s.head != NULL)
	{
		printf("data = %c\n",s.head -> data);
		s.head = s.head -> next;
	}
}

char pop(stack *s)
{
	struct stack_node *temp;
	char d;
	temp = s -> head;
	s -> head = temp -> next;
	d = temp -> data;
	free(temp);
	s -> length--;
	return d;
}

	
	
	






















