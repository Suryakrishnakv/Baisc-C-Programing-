#include <stdio.h> 
void displayReverseArray(int arr[], int size, int index)  
{ 
    if (index == size) 
	{ 
        return; 
    } 
    displayReverseArray(arr, size, index + 1); 
    printf("%d ", arr[index]); 
} 
int main()  
{ 
    int arr[] = {1, 2, 3, 4, 5}; 
    int size = sizeof(arr) / sizeof(arr[0]); 
    printf("Array elements in reverse order: "); 
    displayReverseArray(arr, size, 0);   
    printf("\n"); 
    return 0; 
}

