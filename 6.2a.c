#include <stdio.h>
int main() 
{
    int n, i, j, k;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("\nPattern 1:\n");
    for (i = 1; i <= n; i++) 
	{
        for (j = 1; j <= i; j++) 
		{
            printf("* ");
        }
        printf("\n");
    }
    for (i = n - 1; i >= 1; i--) 
	{
        for (j = 1; j <= i; j++) 
		{
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}

