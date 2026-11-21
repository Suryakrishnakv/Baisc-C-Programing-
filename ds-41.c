#include <stdio.h>
#include <stdlib.h> 
struct Node 
{
	int data;
	struct Node *left, *right;
};
struct Stack 
{ 
	struct Node* data; 
	struct Stack* next;
};
void push(struct Stack** top, struct Node* node) 
{
	struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack)); 
	newNode->data = node;
	newNode->next = *top;
	*top = newNode;
}
struct Node* pop(struct Stack** top) 
{
	if (*top == NULL) return NULL; 
	struct Stack* temp = *top;
	struct Node* node = temp->data;
	*top = (*top)->next; free(temp);
	return node;
}
struct Node* createNode(int value) 
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
	newNode->data = value;
	newNode->left = newNode->right = NULL; 
	return newNode;
}
struct Node* insert(struct Node* root, int value) 
{ 
	if (root == NULL)
	return createNode(value); 
	if (value < root->data)
	root->left = insert(root->left, value); 
	else if (value > root->data)
	root->right = insert(root->right, value); 
	return root;
}
void inorderNonRecursive(struct Node* root) 
{ 
	struct Stack* stack = NULL;
	struct Node* current = root;
	while (current != NULL || stack != NULL) 
	{ 
		while (current != NULL) 
		{
			push(&stack, current); 
			current = current->left;
		}
		current = pop(&stack); 
		printf("%d ", current->data); 
		current = current->right;
	}
}
int main() 
{
	struct Node* root = NULL; 
	root = insert(root, 50); 
	insert(root, 30);
	insert(root, 70);
	insert(root, 20);
	insert(root, 40);
	insert(root, 60);
	insert(root, 80); 
	inorderNonRecursive(root); 
	printf("\n");
	return 0;
}

