#include"linkedlist.h"
int priorty(char);
int str_to_num(char *str,int begin, int last);
struct node_info *infix_to_postfix(char *infix_str);
float eval_postfix(struct node_info *list);
float result(char op, float b, float a);
