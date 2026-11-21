#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
struct Node 
{ 
 	char data[50]; 
 	struct Node* next; 
 	struct Node* prev; 
}; 
struct Node* insert(struct Node* tail, char value[]) 
{ 
 	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
 	strcpy(newNode->data, value); 
 	if (!tail) 
 	{ 
 		newNode->next = newNode; 
 		newNode->prev = newNode; 
 		return newNode; 
 	} 
 	newNode->next = tail->next; 
 	newNode->prev = tail; 
 	tail->next->prev = newNode; 
 	tail->next = newNode; 
 	return newNode; 
} 
void display(struct Node* tail) 
{ 
 	if (!tail) return; 
 	struct Node* temp = tail->next; 
 	do 
 	{ 
 		printf("%s <-> ", temp->data); 
 		temp = temp->next; 
 	} while (temp != tail->next); 
 	printf("...\n"); 
} 
int main() 
{ 
 	struct Node* tail = NULL;
 	tail = insert(tail, "RIYA"); 
 	tail = insert(tail, "PARU"); 
 	tail = insert(tail, "LANA"); 
 	display(tail); 
 	return 0; 
} 
