#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct PriorityQueue 
{
 	int items[MAX];
 	int priorities[MAX];
 	int size;
};
void initializeQueue(struct PriorityQueue *pq) 
{
 	pq->size = 0;
}
int isEmpty(struct PriorityQueue *pq) 
{
 	return pq->size == 0;
}
void enqueue(struct PriorityQueue *pq, int value, int priority) 
{
 	if (pq->size == MAX) 
 	{
 		printf("Priority Queue is full!\n");
 		return;
 	}
 	int i = pq->size - 1;
	while (i >= 0 && pq->priorities[i] > priority) 
 	{
 		pq->items[i + 1] = pq->items[i];
 		pq->priorities[i + 1] = pq->priorities[i];
 		i--;
 	}
 	pq->items[i + 1] = value;
	pq->priorities[i + 1] = priority;
	pq->size++;
	printf("Inserted %d with priority %d into the queue.\n", value, priority);
}
int dequeue(struct PriorityQueue *pq) 
{
	int i;
 	if (isEmpty(pq)) 
 	{
 		printf("Priority Queue is empty!\n");
 		return -1;
 	}
 	int value = pq->items[0];
 	for (i = 0; i < pq->size - 1; i++) 
 	{
 		pq->items[i] = pq->items[i + 1];
 		pq->priorities[i] = pq->priorities[i + 1];
 	}
 	pq->size--;
 	return value;
}
void displayQueue(struct PriorityQueue *pq) 
{
	int i;
 	if (isEmpty(pq)) 
 	{
 		printf("Priority Queue is empty!\n");
 		return;
 	}
 	printf("Priority Queue elements: \n");
 	for (i = 0; i < pq->size; i++) 
 	{
 		printf("Value: %d, Priority: %d\n", pq->items[i], pq->priorities[i]);
 	}
 	printf("\n");
}
int main() 
{
	 struct PriorityQueue pq;
	 initializeQueue(&pq);
	 enqueue(&pq, 10, 2);
	 enqueue(&pq, 20, 1);
	 enqueue(&pq, 30, 3);
	 displayQueue(&pq);
	 printf("Dequeued: %d\n", dequeue(&pq));
	 printf("Dequeued: %d\n", dequeue(&pq));
	 displayQueue(&pq);
	 return 0;	
}

