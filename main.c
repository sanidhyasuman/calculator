#include<stdio.h>
#include"calculator.h"
int main(int argc, char *argv[])
{
	char *str, *temp;
	struct node_info *list;
	if(argc == 1)
	{
		str = (char *)malloc(100);
		scanf("%s",str);
		temp = str;
	}
	else
	{
		temp = argv[1];
	}
	printf("%s = ",temp);
	list = infix_to_postfix(temp);
	float result = eval_postfix(list);
	printf("%f\n", result);
	return 0;
}

