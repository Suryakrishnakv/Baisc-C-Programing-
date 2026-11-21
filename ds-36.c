#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node clist;
clist *head=NULL;
clist *t;
void insert(int a)
{
	if(head==NULL)
	{
		head=(clist*)malloc(sizeof(clist));
		head->data=a;
		head->next=head;
	}
	else
	{
	t=head;
	while(t->next!=head)
	{
	t=t->next;
	}
	t->next=(clist*)malloc(sizeof(clist));
	t->next->data=a;
	t->next->next=head;
	}
}
void delete(int a)
{
	if(head==NULL)
	{
		printf("no elemnts to delete");
	}	
	else if(head->data==a&&head->next==head)
	{
	head=NULL;
	}
	else if(head->data==a)
	{
		for(t=head;t->next!=head;t=t->next)
		{
			t->next=head->next;
			head=head->next;
		}
		else
		{
			t=head;
			while(t->next!=head&&t->next->data!=a)
			{
				t=t->next;
			}
		}
		if(t->next==head)
		{
			printf("element not found:");
		}
		else
		{
			t->next=t->next->next;
		}
	}
void display()
{
	if(head==NULL)
	{
		printf("empty circular linked list:");
	}
	else
	{
		t=head;
		do
		{
			printf("%d",t->data);
			t=t->next;
		}
		while(t->next!=head);
	}
}
int main()
{
	insert(10);
	display();
	insert(20);
	display();
	delete(10);
	display();
	delete(20);
	display();
}

