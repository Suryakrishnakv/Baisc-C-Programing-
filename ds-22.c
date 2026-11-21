#include <stdio.h>
#include <stdlib.h>
int main() 
{
 	int n, i;
 	printf("Enter the number of elements: ");
 	scanf("%d", &n);
 	if (n <= 0) 
	{
 		printf("Invalid input! The number of elements should be greater than zero.\n");
 		return 1;
	}
 	int* arr = (int*)malloc(n * sizeof(int));
 	if (arr == NULL) 
	{
 		printf("Memory allocation failed!\n");
 		return 1;
 	}
 	printf("Enter %d numbers: ", n);
 	int sum = 0;
 	for (i = 0; i < n; i++) 
	{
 		scanf("%d", &arr[i]);
 		sum += arr[i]; 
 	}	
 	double mean = (double)sum / n;
 	printf("Mean: %.2f\n", mean);
 	free(arr);
 	return 0;
}
