#include<stdio.h>
#define N 20
void readarray(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("enter a[%d]",i);
		scanf("%d",&a[i]);
	}
}
void disparray(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
int main()
{
	int a[N],n;
	printf("enter the no of elements");
	scanf("%d",&n);
	readarray (a,n);
	disparray (a,n);
	return 0;
}
