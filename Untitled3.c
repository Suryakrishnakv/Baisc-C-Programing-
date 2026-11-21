#include <stdio.h>
#include <stdlib.h>
struct Book 
{
 	char author_name[100];
 	char book_name[100];
};
void readBooks(struct Book *books, int n) 
{
	int i;
 	for(i = 0; i < n; i++) 
 	{
 		printf("Enter details for book %d:\n", i + 1);
 		printf("Enter book name: ");
 		scanf(" %s", books[i].book_name);
 		printf("Enter author name: ");
 		scanf(" %s", books[i].author_name);
 	}
}
void displayBooks(struct Book *books, int n) 
{
 	printf("\nList of Books:\n");
 	int i;
 	for (i = 0; i < n; i++) 
 	{
 		printf("Book %d:\n", i + 1);
 		printf("Book Name: %s\n", books[i].book_name);
 		printf("Author Name: %s\n\n", books[i].author_name);
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
 	readBooks(books, n);
 	displayBooks(books, n);
 	free(books);
 	return 0;
}
