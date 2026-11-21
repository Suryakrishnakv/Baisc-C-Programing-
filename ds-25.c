#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Queue 
{
 	int items[MAX];
 	int front, rear;
};
void initializeQueue(struct Queue *q) 
{
 	q->front = -1;
 	q->rear = -1;
}
int isEmpty(struct Queue *q) 
{
 	return q->front == -1;
}
int isFull(struct Queue *q) 
{
 	return q->rear == MAX - 1;
}
void enqueue(struct Queue *q, int value) 
{
 	if (isFull(q)) 
	{
 		printf("Queue is full!\n");
 		return;
 	}
 	if (isEmpty(q)) 
 	{
 		q->front = 0;
 	}
 	q->rear++;
 	q->items[q->rear] = value;
 	printf("Inserted %d into the queue.\n", value);
}
int dequeue(struct Queue *q) 
{
 	if (isEmpty(q)) 
 	{
 		printf("Queue is empty!\n");
 		return -1;
 	}
 	int value = q->items[q->front];
 	if (q->front >= q->rear) 
 	{ 
 		q->front = -1;
 		q->rear = -1;
 	} 
 	else 
 	{
 		q->front++;
 	}
 return value;
}
void displayQueue(struct Queue *q) 
{
 	if (isEmpty(q)) 
 	{
 		printf("Queue is empty!\n");
 		return;
 	}
 	printf("Queue elements: ");
 	int i;
 	for ( i = q->front; i <= q->rear; i++) 
 	{
 		printf("%d ", q->items[i]);
 	}
 	printf("\n");
}
int main() 
{
	struct Queue q;
	initializeQueue(&q);
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	displayQueue(&q);
	printf("Dequeued: %d\n", dequeue(&q));
	printf("Dequeued: %d\n", dequeue(&q));
	displayQueue(&q);
	return 0;
}

