#include <stdio.h>
int main()
{
	int n;
	printf("Enter the value of n : ");
	scanf("%d",&n);
	if (n==0)
	{
		printf("The given number is Zero");
	}
	else if (n%2==0)
	{
		printf("The given number is Even");
	}
	else 
	{
		printf("The given number is Odd");
	}
	return 0;
}
