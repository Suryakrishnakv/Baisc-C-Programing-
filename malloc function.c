#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *p,i,n;
	printf("enter n:");
	scanf("%d",&n);
	p=(int*)malloc(n*size(int));
	for(i=0;i<n;i++)
	{
		printf("enter a[%d]",i);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	free(a);
	return 0;
}
