#include<math.h>
#include"stack.h"
#include"calculator.h"
int str_to_num(char *str, int begin, int last)
{
	int n, num = 0;
	for( ;begin <= last; begin++)
	{	
		n = *( str + begin);
		n = n - 48;
		num = num * 10 + n;
	}
	return num;
}
int priorty(char op)
{
	int pri;
	switch(op)
	{
		case '^':
			pri = 3;
			break;
		case '/':
		case '*':
			pri = 2;
			break;
		case '+':
		case '-':
			pri = 1;
	}
	return pri;
}
float result(char op, float b, float a)
{
	float sol;
	switch(op)
	{
		case '+':
			sol = a + b;
			break;
		case '-':
			sol = a - b;
			break;
		case '*':
			sol = a * b;
			break;
		case '/':
			sol = a / b;
			break;
		case '^':
			sol = pow(a, b);
	}
	return sol;
}
float eval_postfix(struct node_info *list)
{
	struct node *temp;
	temp = list -> head;
	int pos;
	struct data a, b, ch, data1;
	//printf("%f\n",temp -> data_node.value.number);
	//printf("evaluate ");
	//display(*list);
	while(1)
	{	
		pos = 1;
		while(pos)
		{
			temp = temp -> next;
			++pos;
			if(temp -> data_node.d_code == op)
			{
	//			printf("operator = %c\n",temp -> data_node.value.operator);
				break;
			}
		}
		ch = delete_node(list, pos--);
	//	printf("ch = %c\n",ch.value.operator);
		b = delete_node(list, pos--);
	//	printf("b = %f\n",b.value.number);
		a = delete_node(list, pos);
	//	printf("a = %f\npos = %d\n",a.value.number,pos);
		data1.d_code = num;
		data1.value.number = result(ch.value.operator, b.value.number, a.value.number);
	//	printf("result = %f\n",data1.value.number);
		insert_position(list, pos, data1);
	//	display(*list);
	//	printf("length = %d\n",list -> length);
		temp = list -> head;
		if(list -> head -> next == NULL)
			break;
	}
	return list -> head -> data_node.value.number;
}
struct node_info *infix_to_postfix(char *infix_str)
{
	int str_pos = 0, l_pos = 1;
	int n, d, begin, last;
	struct node_info *list;
	list = (struct node_info *)malloc(sizeof(struct node_info));
	list -> head = NULL;
	list -> length = 0;
	struct data data1;
	struct stack stack1;
	stack1.head = NULL;
	char ch1, ch2;
	//	printf("%s\n",infix_str);
	while(*(infix_str + str_pos) != 0)
	{
		ch1 = *(infix_str + str_pos);
		//printf("%s\n",infix_str);
		if(ch1 >= 48 && ch1 <= 57)
		{
			begin = str_pos;
			while(1)
			{
				ch1 = *(infix_str + (++str_pos));
				if(!(ch1 >= 48 && ch1 <= 57))
				{
					last = --str_pos;
					break;
				}
			}
			n = str_to_num(infix_str, begin, last);
	//		printf("%d\n",n);
			data1.d_code = num;
			data1.value.number = n;
	//		printf("%f\n",data1.value.number);
			insert_last(list, data1);
		}
		else
		{
			if(stack1.head == NULL)
			{
				push(&stack1, ch1);
			//	printf("ch1 = %c\n",ch1);
			}
			else 
			{
				while(stack1.head != NULL)
				{
					ch2 = pop(&stack1);
			//		printf("ch2 = %c\n",ch2);
					if(priorty(ch1) <= priorty(ch2))
					{	
						data1.d_code = op;
						data1.value.operator = ch2;
						insert_last(list, data1);
					}
					else
					{
						push(&stack1, ch2);
						break;
					}
					//push(&stack1, ch1);
				}
					push(&stack1, ch1);
			}
		}
		str_pos++;
	}
	while(stack1.head != NULL)
	{
		data1.d_code = op;
		data1.value.operator = pop(&stack1);
		insert_last(list,data1);
	}
//	display(*list);
	return list;
}





















