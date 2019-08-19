typedef struct stack stack;
struct stack_node
{
	char data;
	struct stack_node *next;
};
struct stack
{
	struct stack_node *head;
	int length;
};
int push( stack *s, char );
char pop(stack *s);
int display_stack(stack s);
