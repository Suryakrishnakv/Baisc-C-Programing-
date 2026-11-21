#include<stdio.h>
int main()
{
	int y;
	printf("enter the y ");
	scanf("%d",&y);
	if(y%4==0)
	{
		printf("Leap year ");
	}
	else
	{
		printf(" it is not leap year");
	}
	return 0;
}
