#include <stdio.h>
#define MAX 100
void insert(int arr[], int *n);
void search(int arr[], int n);
void delete(int arr[], int *n);
void sort(int arr[], int n);
void display(int arr[], int n);
int main() 
{
    int arr[MAX], n = 0, choice;
    while (1) 
	{
        printf("\nMenu:\n");
        printf("1. Insert element\n");
        printf("2. Search element\n");
        printf("3. Delete element\n");
        printf("4. Sort array\n");
        printf("5. Display array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
		{
            case 1:
                insert(arr, &n);
                break;
            case 2:
                search(arr, n);
                break;
            case 3:
                delete(arr, &n);
                break;
            case 4:
                sort(arr, n);
                break;
            case 5:
                display(arr, n);
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
void insert(int arr[], int *n) 
{
    if (*n >= MAX) 
	{
        printf("Array is full! Cannot insert more elements.\n");
        return;
    }
    printf("Enter the element to insert: ");
    scanf("%d", &arr[*n]);
    (*n)++;
    printf("Element inserted successfully.\n");
}
void search(int arr[], int n) 
{
    int key, found = 0;
    i,n
    printf("Enter the element to search: ");
    scanf("%d", &key);
    for (int i = 0; i < n; i++) 
	{
        if (arr[i] == key) 
		{
            printf("Element %d found at index %d.\n", key, i);
            found = 1;
            break;
        }
    }
    if (!found) 
	{
        printf("Element not found in the array.\n");
    }
}
void delete(int arr[], int *n)
{
    int key, found = 0;
    printf("Enter the element to delete: ");
    scanf("%d", &key);
    for (int i = 0; i < *n; i++) 
	{
        if (arr[i] == key) 
		{
            found = 1;
            for (int j = i; j < *n - 1; j++) 
			{
                arr[j] = arr[j + 1];
            }
            (*n)--;
            printf("Element %d deleted successfully.\n", key);
            break;
        }
    }
    if (!found) 
	{
        printf("Element not found in the array.\n");
    }
}
void sort(int arr[], int n) 
{
    int temp;
    for (int i = 0; i < n - 1; i++) 
	{
        for (int j = 0; j < n - i - 1; j++)
		{
            if (arr[j] > arr[j + 1]) 
			{
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted successfully.\n");
}
void display(int arr[], int n) 
{
    if (n == 0) 
	{
        printf("Array is empty.\n");
    } else {
        printf("Array elements: ");
        for (int i = 0; i < n; i++) 
		{
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}
