#include <stdio.h>
#include <stdlib.h>
int main() 
{
 	int n, i, j;
 	printf("Enter the number of elements: ");
 	scanf("%d", &n);
 	int* arr = (int*)calloc(n, sizeof(int));
 	if (arr == NULL) 
 	{
 		printf("Memory allocation failed!\n");
 		return 1;
 	}
 	printf("Enter %d numbers: ", n);
 	for (i = 0; i < n; i++) 
 	{
 		scanf("%d", &arr[i]);
 	}
 	int mode = arr[0], maxCount = 0;
 	for (i = 0; i < n; i++) 
 	{
 		int count = 0;
 		for (j = 0; j < n; j++) 
 		{
 			if (arr[i] == arr[j]) 
 			{
 				count++;
 			}
 		}
 		if (count > maxCount) 
 		{
 			maxCount = count;
 			mode = arr[i];
 		}
	}
 	printf("Mode: %d\n", mode);
 	free(arr);
 	return 0;
}
