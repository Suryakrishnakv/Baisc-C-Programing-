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
void reverseDisplay(struct Node* head) 
{ 
 	if (head == NULL) return; 
 	reverseDisplay(head->next); 
 	printf("%d -> ", head->data); 
} 
void sortByValue(struct Node* head) 
{ 
 	struct Node* i, *j; 
 	int temp; 
 	for (i = head; i != NULL; i = i->next) 
 	{ 
 		for (j = i->next; j != NULL; j = j->next) 
 		{ 
 			if (i->data > j->data) 
 			{ 
 				temp = i->data; 
 				i->data = j->data; 
 				j->data = temp; 
 			} 
 		} 
 	} 
} 
void sortByAddress(struct Node** head) 
{ 
 	struct Node *i, *j, *prev, *temp; 
 	for (i = *head; i != NULL && i->next != NULL; i = i->next) 
 	{ 
 		for (prev = i, j = i->next; j != NULL; prev = j, j = j->next) 
 		{ 
 			if (i->data > j->data) 
 			{ 
 				prev->next = j->next; 
 				j->next = *head; 
 				*head = j; 
 				j = prev; 
 			} 
 		} 
 	} 
} 
int main() 
{ 
	struct Node* head = NULL; 
	display(head); 
	reverseDisplay(head); 
	printf("NULL\n"); 
	sortByValue(head); 
	sortByAddress(&head); 
	return 0; 
} 
