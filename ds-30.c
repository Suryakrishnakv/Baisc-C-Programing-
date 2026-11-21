#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node list;
list *head=NULL;
list *t;
void insert(int a)
{
	if(head==NULL)
	{
		head=(list*)malloc(sizeof(list));
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
void disp()
{
	if(head==NULL)
	{
		printf("empty linked list");
	}
	else
	{
		t=head;
		while(t!=NULL)
		{
			printf("%d ",t->data);
			t=t->next;
		}	
	}
}
void delete(int e)
{
	if(head==NULL)
	{
		printf("empty linked list:");
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
		if(t==NULL)
		{
			printf("element not found");
		}
		else
		{
			t->next=t->next->next;
		}
	}
}
int main()
{
	insert(10);
	disp();
	printf("\n");
	insert(20);
	printf("\n");
	disp();
	delete(10);
	printf("\n");
	delete(20);
}

