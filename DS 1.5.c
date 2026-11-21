#include<stdio.h>
int a[20],l,i;
int read()
{
	printf("enter the limit:");
	scanf("%d",&l);
	for(i=0;i<l;i++)
	{
		printf("enter a[%d]",i);
		scanf("%d",&a[i]);
	}
}
void sort()
{
	int i,j,temp;
	for(i=0;i<l;i++)
	{
		for(j=0;j<l-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void display()
{
	for(i=0;i<l;i++)
	{
		printf("%d\t",a[i]);
    }
}
int main()
{
	read();
	printf("elements before sorting\n");
	display();
	sort();
	printf("\nelements after sorting\n");
	display();
	return 0;
}

