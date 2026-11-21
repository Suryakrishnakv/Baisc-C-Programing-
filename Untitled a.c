#include<stdio.h>
#include<malloc.h>
int main()
{
	int *a;
	a=(int*)malloc(sizeof(int));
	printf("enter the number ");
	scanf("%d",a);
	printf("*a=%d",*a);
	free(a);
	return 0;
}
