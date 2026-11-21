#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node list;
list * head=NULL;
void insert(int a)
{
	list *t;
	if(head==NULL)
	{
		head=(list *) malloc (sizeof(list));
		head->data=a;
		head->next=NULL;
	}
	else
	{
		t=head;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=(list*)malloc(sizeof(list));
		t->next->data=a;
		t->next->next=NULL;
	}
}
void delete(int e)
{
	list *t;
	if(head==NULL)
	{
		printf("empty linked list");
	}
	else if(head->data==e)
	{
		head=head->next;
	}
	else
	{
		t=head;
		while(t->next!=NULL&&t->next->data!=e)
		{
			t=t->next;
		}
		if(t->next ==NULL)
		{
			printf("element not found");
		}
		else
		{
			t->next=t->next->next;
		}
	}
}
void disp()
{
	list *t;
	if(head==NULL)
	{
		printf("empty linked list");
	}
	else
	{
		t=head;
		while(t!=NULL)
		{
			printf("%d\t",t->data);
			t=t->next;
		}
	}
}
int main()
{
	insert(10);
	insert(20);
	disp();
	delete(20);
	disp();
	return 0;
}
