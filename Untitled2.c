#include<stdio.h>
int main()
{
	int a;
	printf("enter a number");
	scanf("%d",&a);
	if(a>0)
	{
		printf("positive");
		if(a%2==0)
		{
			printf("even");
		}
		else
		{
			printf("\nodd");
		}
	}
	return 0;
}
