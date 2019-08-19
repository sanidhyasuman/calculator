
output:main.o linkedlist.o 
	cc main.o linkedlist.o -o runme
linkedlist.o:linkedlist.c
	cc -c linkedlist.c 
main.o:main.c
	cc -c main.c

stack:main_stack.o stack.o
	cc main_stack.o stack.o -o runme
stack.o:stack.c
	cc -c stack.c
main_stack.o:main_stack.o
	cc -c main_stack.c

calculator:main.o linkedlist.o calculator.o stack.o
	cc main.o stack.o calculator.o linkedlist.o -lm -o runme
stack.o:stack.c
	cc -c stack.c
linkedlist.o:linkedlist.c
	cc -c linkedlist.c
calculator.o:calculator.c
	cc -c calculator.c
