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
void postorderNonRecursive(struct Node* root) 
{ 
	if (root == NULL) return;
	struct Stack *stack1 = NULL, *stack2 = NULL; 
	push(&stack1, root);
	while (stack1 != NULL) 
	{
		struct Node* current = pop(&stack1); 
		push(&stack2, current);
		if (current->left) push(&stack1, current->left); 
		if (current->right) push(&stack1, current->right);
	}
	while (stack2 != NULL) 
	{	
		struct Node* node = pop(&stack2); 
		printf("%d ", node->data);
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
	printf("Postorder Traversal (Non-Recursive): "); 
	postorderNonRecursive(root);
	free(root->left); 
	free(root->right); 
	free(root);
	return 0;
}

