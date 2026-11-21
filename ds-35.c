#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node queue;
queue *f=NULL;
queue *r=NULL;
void enqueue(int a)
{
	if(f==NULL)
	{
		f=(queue*)malloc(sizeof(queue));
		f->data=a;
		f->next=NULL;
		r=f;
	}
	else
	{
		r->next=(queue*)malloc(sizeof(queue));
 		r->next->data=a;
 		r->next->next=NULL;
 		r=r->next;
	}
}
void dequeue()
{
	if(f==NULL)
	{
		printf("empty linked queue");
	}
	else
	{
		printf("deleted element is %d",f->data);
		f=f->next;
	}
}
int main()
{
	enqueue(10);
	enqueue(20);
	dequeue();
	dequeue();
	dequeue();
return 0;
}
