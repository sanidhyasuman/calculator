#include<stdio.h>
#include"stack.h"
int main()
{
	stack s;
	s.head = NULL;
	s.length = 0;
	push(&s, '*');
	push(&s, '-');
	push(&s, '+');
	printf("data = %c\n",pop(&s));
	display(s);
	return 0;
}

