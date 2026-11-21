#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node stack;
stack *top=NULL;
void push(int a)
{
	stack *t;
	t=(stack*)malloc(sizeof(stack));
	t->data=a;
	t->next=top;
	top=t;
}
void pop()
{
	if(top==NULL)
	{
		printf(" empty stack: ");
	}
	else
	{
	printf(" deleted element is %d ",top->data);
	top=top->next;
	}
}
void peek()
{
	if(top==NULL)
	{
		printf(" empty stack:");
	}
	else
	{
		printf("%d ",top->data);
	}
}
int main()
{
	push(10);
	peek();
	push(20);
	peek();
	pop();
	pop();
	pop();
}

