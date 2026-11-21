#include<stdio.h>
#define N 5
int top=-1;
int a[N];
void push()
{
	if(top==N)
	{
		printf("stack is full:\n");
	}
	else{
		top=top+1;
		printf("enter an element:\n");
		scanf("%d",&a[top]);
	}
}
void pop()
{
	if(top==-1)
	{
		printf("stack is empty\n");
	}
	else
	{
		printf("deleted element is %d\n",a[top]);
		top=top-1;
		
	}
}
void peek()
{
	if(top==-1)
	{
		printf("\nno elements to display");
	}
	else{
		printf("%d\n",a[top]);
	}
}
int menu()
{
	int ch;
	printf("1.for push\n2 for pop\n3 for peek\n4 for exit\n");
	printf("enter your choice\n");
	scanf("%d",&ch);
	return ch;
}
int main()
{
	int ch;
	for(ch=menu();ch!=4;ch=menu())
	{
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			default:
				printf("invalid choice:");
				break;
		}
	}
	return 0;
}

