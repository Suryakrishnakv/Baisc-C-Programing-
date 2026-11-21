#include <stdio.h>
int main()
{
	int n,s,a;
	printf("Enter the value of n : ");
	scanf("%d",&n);
	while(n!=0)
	{
		printf("enter the number : ");
		scanf("%d",&a);
		s=s+a;
		n--;
	}
	printf("The sum of the given n numbers is %d ",s);
	return 0;
}
