#include<stdio.h>
int main()
{
	int a[20],l,n,flag=0,i;
	printf("enter the limit:");
	scanf("%d",&l);
	for(i=0;i<l;i++)
	{
		printf("enter a[%d]",i);
		scanf("%d",&a[i]);
	}
	printf("enter the element");
	scanf("%d",&n);
	for(i=0;i<l;i++)
	{
		if(a[i]==n)
		{
			printf("element occured at position %d\n",i+1);
			flag=flag+1;
		}
	}
	if(flag==0)
	{
		printf("element is not occured");
	}
	return 0;
}

