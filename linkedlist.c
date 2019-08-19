#include<stdio.h>
#include<stdlib.h>

#include"linkedlist.h"

int display(struct node_info list)
{
	if(list.head == NULL)
	{
		return -1;
		printf("error1\n");
	}
	else
	{
		while(list.head != NULL)
		{
			if(list.head -> data_node.d_code)
				printf("%c  ",list.head -> data_node.value.operator);
			else
				printf("%f  ",list.head -> data_node.value.number);
			list.head = list.head -> next;
		}
		printf("\n");
		return 0;
	}
}

int insert_position(struct node_info *list, int pos, struct data data)
{
	node *new_node, *temp1, *temp2;
	int i = 1;
	new_node = (node *)malloc(sizeof(node));
	if(new_node == NULL)
	{
		return -1;
		printf("error2\n");
	}
	else
	{
		new_node -> data_node = data;
		if(pos == 1)
		{
			new_node -> next = list -> head;
			list -> head = new_node;
			list -> length++;
		}
		else
		{
			temp2 = list -> head;
			while(i < pos && temp2 != NULL)
			{
				temp1 = temp2;
				i++;
				temp2 = temp2 -> next;
			}
			new_node -> next = temp1 -> next;
			temp1 -> next = new_node;
			list -> length++;
		}
		return 0;
	}
}
int insert_last(struct node_info *list,struct data data)
{
	return insert_position(list,++ list -> length,data);
}

struct data delete_node(struct node_info *list, int pos)
{
	node *temp1, *temp2, data;
	int i = 1;
	if(pos == 1)
	{
		temp1 = list -> head;
		list -> head = temp1 -> next;
		data.data_node = temp1 -> data_node;
		free(temp1);
		list -> length--;
		return data.data_node;
	}
	else
	{
		temp2 = list -> head;
		while(temp2 != NULL && i < pos)
		{	
			temp1 = temp2;
			i++;
			temp2 = temp2 -> next;
		}
		if(temp2 == NULL)
			printf("error3\n");
		else
		{
			temp1 -> next = temp2 -> next;
			data.data_node = temp2 -> data_node;
			free(temp2);
			list -> length--;
			return data.data_node;
		}
	}
}
	

	
	
	






















