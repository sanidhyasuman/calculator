#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
typedef struct node linked_list;
enum data_code{num, op};
struct data
{
	enum data_code d_code;
	 union data_type
	{
		float number;
		char operator;
	}value;
};
	
struct node
{
	struct data data_node;
	node *next;
};
struct node_info
{
	struct node *head;
	int length;
};
int display(struct node_info node);
int insert_position(struct node_info *node, int pos, struct data);
struct data delete_node(struct node_info *node, int pos);
int insert_last(struct node_info *node, struct data);
