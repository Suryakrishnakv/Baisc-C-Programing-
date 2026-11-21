#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
struct Node 
{
	char name[100];
	struct Node *left, *right;
};
struct Node* createNode(char* name) 
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
	strcpy(newNode->name, name);
	newNode->left = newNode->right = NULL; 
	return newNode;
}
struct Node* insert(struct Node* root, char* name) 
{ 
	if (root == NULL)
	return createNode(name);
	if (strcmp(name, root->name) < 0)
	root->left = insert(root->left, name); 
	else
	root->right = insert(root->right, name); 
	return root;
}
void inorder(struct Node* root) 
{ 
	if (root != NULL) 
	{
		inorder(root->left); 
		printf("%s\n", root->name); 
		inorder(root->right);
	}	
}
int main() 
{
	struct Node* root = NULL; 
	root = insert(root, "Alice"); 
	insert(root, "Bob"); 
	insert(root, "Charlie"); 
	insert(root, "David"); 
	inorder(root);
	return 0;
}

