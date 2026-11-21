#include <stdio.h> 
#include <stdlib.h> 
struct Node 
{ 
 	int coeff, exp; 
 	struct Node* next; 
}; 
struct Node* insert(struct Node* head, int coeff, int exp) 
{ 
 	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
 	newNode->coeff = coeff; 
 	newNode->exp = exp; 
 	newNode->next = head; 
 	return newNode; 
} 
struct Node* addPolynomials(struct Node* p1, struct Node* p2) 
{ 
 	struct Node* result = NULL; 
 	while (p1 && p2) 
 	{ 
 		if (p1->exp > p2->exp) 
 		{ 
 			result = insert(result, p1->coeff, p1->exp); 
 			p1 = p1->next; 
 		} 
		else if (p1->exp < p2->exp) 
 		{ 
 			result = insert(result, p2->coeff, p2->exp); 
 			p2 = p2->next; 
 		} 
		else 
 		{ 
 			result = insert(result, p1->coeff + p2->coeff, p1->exp); 
 			p1 = p1->next; 
 			p2 = p2->next; 
 		} 
 	} 
 	while (p1) 
 	{ 
 		result = insert(result, p1->coeff, p1->exp); 
 		p1 = p1->next; 
 	} 
 	while (p2) 
 	{ 
 		result = insert(result, p2->coeff, p2->exp); 
 		p2 = p2->next; 
 	} 
 	return result; 
} 
void display(struct Node* head) 
{ 
 	while (head) 
 	{ 
 		printf("%dx^%d ", head->coeff, head->exp); 
 		head = head->next; 
 	} 
 	printf("\n"); 
} 
int main() 
{ 
 	struct Node *p1 = NULL, *p2 = NULL, *sum = NULL; 
 	p1 = insert(p1, 3, 2); 
 	p1 = insert(p1, 5, 1); 
 	p2 = insert(p2, 4, 2); 
 	p2 = insert(p2, 2, 1); 
 	sum = addPolynomials(p1, p2); 
 	display(sum); 
 	return 0; 
}

