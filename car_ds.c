#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Car 
{
    int no;
    char name[50];
    char countryorgin[50];
    struct Car* next;
}
Car;
Car* head = NULL;
void insertCar(int no, char name[], char countryorigin[]) 
{
    Car* newCar = (Car*)malloc(sizeof(Car));
    newCar->no = no;
    strcpy(newCar->name, name);
    strcpy(newCar->countryorgin,countryorgin);
    newCar->next = head;
    head = newCar;
    printf("Car inserted successfully!\n");
}
void deleteCar(int no) 
{
    Car *temp = head, *prev = NULL;
    while (temp != NULL && temp->no != no) 
	{
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) 
	{
        printf("Car not found!\n");
        return;
    }
    if (prev == NULL) head = temp->next;
    else prev->next = temp->next;
    free(temp);
    printf("Car deleted successfully!\n");
}
void findBook(int no) 
{
    Car* temp = head;
    while (temp != NULL) 
	{
        if (temp->no == no) 
		{
            printf("Car Found: ID=%d, Title=%s, Author=%s\n", temp->no, temp->name, temp->countryorgin);
            return;
        }
        temp = temp->next;
    }
    printf("Car not found!\n");
}
void findAndReplace(int no, char newname[], char newcountryorgin[]) 
{
    Car* temp = head;
    while (temp != NULL) 
	{
        if (temp->no == no) 
		{
            strcpy(temp->name, newname);
            strcpy(temp->countryorgin, newcountryorgin);
            printf("Car updated successfully!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Car not found!\n");
}
int countCars() 
{
    int count = 0;
    Car* temp = head;
    while (temp != NULL) 
	{
        count++;
        temp = temp->next;
    }
    return count;
}
void sortCar() 
{
    if (!head || !head->next) return;
    Book *i, *j;
    int tempId;
    char tempname[50], tempcountryorgin[50];
    for (i = head; i->next != NULL; i = i->next) 
	{
        for (j = i->next; j != NULL; j = j->next) 
		{
            if (i->no > j->no) 
			{
                tempno = i->no;
                i->no = j->no;
                j->no = tempno;
        
                strcpy(tempname, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, tempname);
                
                strcpy(tempcountryorgin, i->countryorgin);
                strcpy(i->countryorgin, j->countryorgin);
                strcpy(j->countryorgin, tempcountryorgin);
            }
        }
    }
    printf("Car sorted successfully!\n");
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
        printf("No Cars in the showrooms!\n");
        return;
    }
    printf("showrooms Cars :\n");
    while (temp != NULL) 
	{
        printf("no=%d, name=%s, countryorgin=%s\n", temp->no, temp->name, temp->countryorgin);
        temp = temp->next;
    }
}
int main() 
{
    int choice, no;
    charname[50], countryorgin[50];
    do 
	{
        printf("\nshowrooms Car Management System\n");
        printf("1. Insert Car\n");
        printf("2. Delete Car\n");
        printf("3. Find Car\n");
        printf("4. Find and Replace\n");
        printf("5. Count Car\n");
        printf("6. Sort Car\n");
        printf("7. Reverse List\n");
        printf("8. Display Car\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
		{
            case 1:
                printf("Enter Car no, name, and countryorgin: ");
                scanf("%d", &no);
                getchar();
                fgets(name, 50, stdin);
                title[strcspn(name, "\n")] = 0;
                fgets(countryorgin, 50, stdin);
                author[strcspn(countryorgin, "\n")] = 0;
                insertCar(no, name, countryorgin);
                break;
            case 2:
                printf("Enter Car no to delete: ");
                scanf("%d", &no);
                deleteCar(no);
                break;
            case 3:
                printf("Enter  Car no to find: ");
                scanf("%d", &no);
                findCar(no);
                break;
            case 4:
                printf("Enter Car no to update: ");
                scanf("%d", &no);
                getchar();
                printf("Enter new name and countryorgin: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = 0;
                fgets(countryorgin, 50, stdin);
                countryorgin[strcspn(countryorgin, "\n")] = 0;
                findAndReplace(no, name, countryorgin);
                break;
            case 5:
                printf("Total Cars: %d\n", countCars());
                break;
            case 6:
                sortcars();
                break;
            case 7:
                reverseList();
                break;
            case 8:
                displaycars();
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
