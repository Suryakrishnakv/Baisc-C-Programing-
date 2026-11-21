#include <stdio.h> 
#include <stdlib.h> 
struct Node 
{ 
 	int data; 
 	struct Node* next; 
}; 
void display(struct Node* head) 
{ 
 	struct Node* temp = head; 
 	while (temp != NULL) 
 	{ 
		printf("%d -> ", temp->data); 
 		temp = temp->next; 
 	} 
 	printf("NULL\n"); 
} 
void insertAtBeginning(struct Node** head, int value) 
{ 
 	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
 	newNode->data = value; 
 	newNode->next = *head; 
 	*head = newNode; 
} 
void insertAtEnd(struct Node** head, int value) 
{ 
 	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
 	newNode->data = value; 
 	newNode->next = NULL; 
 	if (*head == NULL) 
 	{ 
 		*head = newNode; 
 		return; 
 	} 
 	struct Node* temp = *head; 
 	while (temp->next != NULL) 
 	temp = temp->next; 
 	temp->next = newNode; 
} 
void insertAfter(struct Node* prevNode, int value) 
{ 
 	if (prevNode == NULL) return; 
 	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
 	newNode->data = value; 
 	newNode->next = prevNode->next; 
 	prevNode->next = newNode; 
} 
int main() 
{ 
 	struct Node* head = NULL; 
 	insertAtBeginning(&head, 10); 
 	insertAtEnd(&head, 30); 
 	insertAfter(head, 20); 
 	display(head); 
 	return 0; 
}

