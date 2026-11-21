#include <stdio.h> 
#include <stdlib.h> 
typedef struct Node 
{ 
 	int data; 
 	struct Node* next; 
} Node; 
typedef struct CircularQueue 
{ 
 	Node* rear; 
} CircularQueue; 
Node* createNode(int data) 
{ 
 	Node* newNode = (Node*)malloc(sizeof(Node)); 
 	newNode->data = data; 
 	newNode->next = NULL; 
 	return newNode; 
} 
void initQueue(CircularQueue* q) 
{ 
 	q->rear = NULL; 
} 
int isEmpty(CircularQueue* q) 
{ 
 	return (q->rear == NULL); 
} 
void enqueue(CircularQueue* q, int data) 
{ 
 	Node* newNode = createNode(data); 
 	if (isEmpty(q)) 
 	{ 
 		q->rear = newNode; 
 		q->rear->next = q->rear; 
 	} 
	else 
 	{ 
 		newNode->next = q->rear->next; 
 		q->rear->next = newNode; 
 		q->rear = newNode; 
 	} 
} 
int dequeue(CircularQueue* q) 
{ 
 	if (isEmpty(q))
 	{ 
 		printf("Queue is empty!\n"); 
 		return -1; 
 	} 
 	Node* temp = q->rear->next; 
 	int data = temp->data; 
 	if (q->rear == temp) 
 	q->rear = NULL; 
 	else 
 	q->rear->next = temp->next; 
 	free(temp); 
 	return data; 
} 
void display(CircularQueue* q) 
{ 
 	if (isEmpty(q)) 
 	{ 
 		printf("Queue is empty!\n"); 
 		return; 
 	} 
 	Node* temp = q->rear->next; 
 	do 
 	{ 
 		printf("%d ", temp->data); 
 		temp = temp->next; 
 	} while (temp != q->rear->next); 
 	printf("\n"); 
} 
int main() 
{ 
 	CircularQueue q; 
 	initQueue(&q); 
 	enqueue(&q, 10); 
 	enqueue(&q, 20); 
 	enqueue(&q, 30); 
 	display(&q); 
 	printf("Dequeued: %d\n", dequeue(&q)); 
 	display(&q); 
 	return 0; 
} 
