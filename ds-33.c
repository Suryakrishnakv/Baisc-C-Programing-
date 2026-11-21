#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
struct Node 
{ 
 	char name[50]; 
 	struct Node* next; 
}; 
struct Node* insert(struct Node* head, char name[]) 
{ 
 	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
 	strcpy(newNode->name, name); 
 	newNode->next = head; 
 	return newNode; 
} 
void display(struct Node* head) 
{ 
 	while (head) 
 	{ 
 		printf("%s -> ", head->name); 
 		head = head->next; 
 	} 
 	printf("NULL\n"); 
} 
int main() 
{ 
 	struct Node* head = NULL; 
 	head = insert(head, "VASUDEV"); 
 	head = insert(head, "HRITHIK"); 
 	head = insert(head, "Sam"); 
 	display(head); 
 	return 0; 
} 
