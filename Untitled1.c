#include<stdio.h>
int main()
{
	int a;
	printf("enter a number ");
	scanf("%d",&a);
	if(a<0)
	{
		printf("it is negative");
	}
	else if(a==0)
	{
		printf("it is zero");
	}
	else 
	{
		printf("it is positive");
	}
	return 0;
}
