#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Book 
{
    int id;
    char title[50];
    char author[50];
    struct Book* next;
}
Book;
Book* head = NULL;
void insertBook(int id, char title[], char author[]) 
{
    Book* newBook = (Book*)malloc(sizeof(Book));
    newBook->id = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->next = head;
    head = newBook;
    printf("Book inserted successfully!\n");
}
void deleteBook(int id) 
{
    Book *temp = head, *prev = NULL;
    while (temp != NULL && temp->id != id) 
	{
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) 
	{
        printf("Book not found!\n");
        return;
    }
    if (prev == NULL) head = temp->next;
    else prev->next = temp->next;
    free(temp);
    printf("Book deleted successfully!\n");
}
void findBook(int id) 
{
    Book* temp = head;
    while (temp != NULL) 
	{
        if (temp->id == id) 
		{
            printf("Book Found: ID=%d, Title=%s, Author=%s\n", temp->id, temp->title, temp->author);
            return;
        }
        temp = temp->next;
    }
    printf("Book not found!\n");
}
void findAndReplace(int id, char newTitle[], char newAuthor[]) 
{
    Book* temp = head;
    while (temp != NULL) 
	{
        if (temp->id == id) 
		{
            strcpy(temp->title, newTitle);
            strcpy(temp->author, newAuthor);
            printf("Book updated successfully!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Book not found!\n");
}
int countBooks() 
{
    int count = 0;
    Book* temp = head;
    while (temp != NULL) 
	{
        count++;
        temp = temp->next;
    }
    return count;
}
void sortBooks() 
{
    if (!head || !head->next) return;
    Book *i, *j;
    int tempId;
    char tempTitle[50], tempAuthor[50];
    for (i = head; i->next != NULL; i = i->next) 
	{
        for (j = i->next; j != NULL; j = j->next) 
		{
            if (i->id > j->id) 
			{
                tempId = i->id;
                i->id = j->id;
                j->id = tempId;
        
                strcpy(tempTitle, i->title);
                strcpy(i->title, j->title);
                strcpy(j->title, tempTitle);
                
                strcpy(tempAuthor, i->author);
                strcpy(i->author, j->author);
                strcpy(j->author, tempAuthor);
            }
        }
    }
    printf("Books sorted successfully!\n");
}
void reverseList() 
{
    Book *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) 
	{
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printf("List reversed successfully!\n");
}
void displayBooks() 
{
    Book* temp = head;
    if (!temp) 
	{
        printf("No books in the library!\n");
        return;
    }
    printf("Library Books:\n");
    while (temp != NULL) 
	{
        printf("ID=%d, Title=%s, Author=%s\n", temp->id, temp->title, temp->author);
        temp = temp->next;
    }
}
int main() 
{
    int choice, id;
    char title[50], author[50];
    do 
	{
        printf("\nLibrary Book Management System\n");
        printf("1. Insert Book\n");
        printf("2. Delete Book\n");
        printf("3. Find Book\n");
        printf("4. Find and Replace\n");
        printf("5. Count Books\n");
        printf("6. Sort Books\n");
        printf("7. Reverse List\n");
        printf("8. Display Books\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
		{
            case 1:
                printf("Enter Book ID, Title, and Author: ");
                scanf("%d", &id);
                getchar();
                fgets(title, 50, stdin);
                title[strcspn(title, "\n")] = 0;
                fgets(author, 50, stdin);
                author[strcspn(author, "\n")] = 0;
                insertBook(id, title, author);
                break;
            case 2:
                printf("Enter Book ID to delete: ");
                scanf("%d", &id);
                deleteBook(id);
                break;
            case 3:
                printf("Enter Book ID to find: ");
                scanf("%d", &id);
                findBook(id);
                break;
            case 4:
                printf("Enter Book ID to update: ");
                scanf("%d", &id);
                getchar();
                printf("Enter new Title and Author: ");
                fgets(title, 50, stdin);
                title[strcspn(title, "\n")] = 0;
                fgets(author, 50, stdin);
                author[strcspn(author, "\n")] = 0;
                findAndReplace(id, title, author);
                break;
            case 5:
                printf("Total books: %d\n", countBooks());
                break;
            case 6:
                sortBooks();
                break;
            case 7:
                reverseList();
                break;
            case 8:
                displayBooks();
                break;
            case 9:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } 
	while (choice != 9);
    return 0;
}
