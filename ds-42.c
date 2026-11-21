#include <stdio.h>
#include <stdlib.h> 
struct Node 
{
	int data;
	struct Node* left; struct Node* right;
};
struct Stack 
{ 
	struct Node* node; 
	struct Stack* next;
};
void push(struct Stack** stack, struct Node* node) 
{
	struct Stack* newStackNode = (struct Stack*)malloc(sizeof(struct Stack)); 
	newStackNode->node = node;
	newStackNode->next = *stack;
	*stack = newStackNode;
} 
struct Node* pop(struct Stack** stack) 
{ 
	if (*stack == NULL) 
	{
		return NULL;
	}
	struct Stack* temp = *stack; 
	struct Node* node = temp->node;
	*stack = (*stack)->next; 
	free(temp);
	return node;
}
void preorderNonRecursive(struct Node* root) 
{ 
	if (root == NULL) return;
	struct Stack* stack = NULL; 
	push(&stack, root);
	while (stack != NULL) 
	{
		struct Node* current = pop(&stack); 
		printf("%d ", current->data);
		if (current->right) push(&stack, current->right); 
		if (current->left) push(&stack, current->left);
	}
}
int main() 
{
	struct Node* root = (struct Node*)malloc(sizeof(struct Node)); 
	root->data = 1;
	root->left = (struct Node*)malloc(sizeof(struct Node)); 
	root->right = (struct Node*)malloc(sizeof(struct Node));
	root->left->data = 2; 
	root->left->left = NULL;
	root->left->right = NULL;
	root->right->data = 3; 
	root->right->left = NULL;
	root->right->right = NULL;
	printf("Preorder Traversal (Non-Recursive): "); 
	preorderNonRecursive(root);
	free(root->left); 
	free(root->right); 
	free(root);
	return 0;
}

