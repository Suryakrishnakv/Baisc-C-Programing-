#include<stdio.h>
#define N 5
int a[N],i,size;
void insert()
{
	for(i=0;i<N;i++)
	{
		printf("enter a[%d]",i);
		scanf("%d",&a[i]);
	}
	size=N;
}
void search()
{
	int b,flag=0;
	printf("enter the element to search");
	scanf("%d",&b);
	for(i=0;i<N;i++)
	{
		if(a[i]==b)
		{
			printf("element found");
			flag=flag+1;
		}
	}
		if(flag==0)
		{
			printf("element not found:");
		}
}
void delete()
{
	int k;
	printf("enter the position of element to delete");
	scanf("%d",&k);
	for(i=k-1;i<N;i++)
	{
	 	a[i]=a[i+1];
	}
	size--;
}
void bubbleSort()
{
    int i, j, temp;
    for (i = 0; i < N - 1; i++) 
	{
        for (j = 0; j < N - i - 1; j++) 
		{
            if (a[j] > a[j + 1]) 
			{
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int main()
{
	printf("1 for insert\n2 for delete\n3 for sorting\n4 for end\n");
	int c;
	printf("enter the choice:");
	scanf("%d",&c);
	while(1)
	{
		switch(c)
		{
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				bubbleSort();
				break;
			case 4:
				return 1;
				break;
		}
	}
	return 0;
}

