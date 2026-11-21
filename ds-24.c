#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Book 
{
	char author[50];
 	char book[50];
};
void read(struct Book *books, int n) 
{
 	for (int i = 0; i < n; i++) 
	{
 		printf("Enter details for book %d:\n", i+1);
 		printf("Author Name: ");
 		scanf(" %[^\n]", books[i].author);
 		printf("Book Name: ");
 		scanf(" %[^\n]", books[i].book);
 	}
}
void disp(struct Book *books, int n) 
{
 	printf("\nBook Details:\n");
 	for (int i = 0; i < n; i++) 
	{
 		printf("Book %d:\n", i + 1);
 		printf("Author: %s\n", books[i].author);
 		printf("Title: %s\n", books[i].book);
 	}
}
int main() 
{
 	int n;
 	printf("Enter the number of books: ");
 	scanf("%d", &n);
 	struct Book *books = (struct Book *)malloc(n * sizeof(struct Book));
 	if (books == NULL) 
 	{
 		printf("Memory allocation failed!\n");
 		return 1;
 	}
 	read(books,n);
 	disp(books, n);
 	free(books); 
 	return 0;
}

