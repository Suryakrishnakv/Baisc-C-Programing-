#include <stdio.h>
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
struct Book
{
    char title[MAX_TITLE_LENGTH];    
    char author[MAX_AUTHOR_LENGTH];  
    float price;                     
    int publication_year;            
};
int main() 
{
    struct Book book;
    printf("Enter the title of the book: ");
    fgets(book.title, sizeof(book.title), stdin);
    book.title[strcspn(book.title, "\n")] = '\0';
    printf("Enter the author's name: ");
    fgets(book.author, sizeof(book.author), stdin);
    book.author[strcspn(book.author, "\n")] = '\0';
    printf("Enter the price of the book: ");
    scanf("%f", &book.price);
    printf("Enter the publication year of the book: ");
    scanf("%d", &book.publication_year);
    printf("\nBook Details:\n");
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Price: %.2f\n", book.price);
    printf("Publication Year: %d\n", book.publication_year);
    return 0;
}
