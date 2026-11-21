#include <stdio.h>
#include <stdlib.h>
int main() 
{
 	int n,i;
 	printf("Enter the number of elements for malloc: ");
 	scanf("%d", &n);
 	int* arr_malloc = (int*)malloc(n * sizeof(int));
 	if(arr_malloc == NULL) 
 	{
 		printf("Memory allocation failed using malloc!\n");
 		return 1;
 	}
 	printf("Enter %d numbers using malloc\t:\t", n);
 	for(i = 0; i < n; i++) 
 	{
		scanf("%d", &arr_malloc[i]);
 	}
	printf("Numbers entered using malloc: ");
 	for(i = 0; i < n; i++) 
 	{
 		printf("%d ", arr_malloc[i]);
	}
	printf("\n");
	printf("Enter the number of elements for calloc: ");
	scanf("%d", &n);
	int* arr_calloc = (int*)calloc(n, sizeof(int)); 
	if(arr_calloc == NULL) 
	{
 		printf("Memory allocation failed using calloc!\n");
 		free(arr_malloc); 
 		return 1;
 	}
 	printf("Enter %d numbers using calloc\t:\t", n);
 	for(i = 0; i < n; i++) 
 	{
 		scanf("%d", &arr_calloc[i]);
 	}
 	printf("Numbers entered using calloc: ");
 	for(i = 0; i < n; i++) 
 	{
 		printf("%d ", arr_calloc[i]);
 	}
 	printf("\n");
 	free(arr_malloc); 
 	free(arr_calloc); 
 	printf("Memory freed successfully!\n");
	return 0;
}
