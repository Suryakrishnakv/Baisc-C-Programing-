#include <stdio.h> 
#include <stdlib.h> 
typedef struct Node 
{ 
 	int data; 
 	struct Node* prev; 
 	struct Node* next; 
} Node; 
Node* createNode(int data) 
{ 
 	Node* newNode = (Node*)malloc(sizeof(Node)); 
 	newNode->data = data; 
 	newNode->prev = newNode->next = NULL; 
 	return newNode; 
} 
void insert(Node** head, int data) 
{ 
 	Node* newNode = createNode(data); 
 	if (!*head) 
 	{ 
 		*head = newNode; 
 		return; 
 	} 
 	Node* temp = *head; 
 	while (temp->next) temp = temp->next; 
 	temp->next = newNode; 
 	newNode->prev = temp; 
} 
void display(Node* head) 
{ 
 	while (head) 
 	{ 
 		printf("%d ", head->data); 
 		head = head->next; 
 	} 
 	printf("\n"); 
} 
int main() 
{ 
 	Node* head = NULL; 
 	insert(&head, 10); 
 	insert(&head, 20); 
 	insert(&head, 30); 
 	display(head); 
 	return 0; 
}

