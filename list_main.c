#include <stdio.h>

#include "linkedlist.h"

int main()
{
	struct node_info list1;
	struct data data1;
	list1.head = NULL;
	list1.length = 0;
  printf("in main\n");
	data1.d_code = num;
	data1.value.number = 23;
	insert_position(&list1, 1, data1); 
	
	data1.d_code = num;
	data1.value.number = 73;
	insert_position(&list1, 2, data1); 

	data1.d_code = op;
	data1.value.operator = '*';
	insert_position(&list1, 3, data1); 

	data1.d_code = num;
	data1.value.number = 45;
	insert_position(&list1, 4, data1); 

	data1.d_code = op;
	data1.value.operator = '+';
	insert_position(&list1, 5, data1); 
	
	display(list1);

	data1 = delete_node(&list1, 1);
	printf("delete = %f\n",data1.value.number);
	data1.d_code = num;
	data1.value.number = 46;
	insert_last(&list1,data1);
	display(list1);
	return 0;
}

