#include<stdio.h>
int main()
{
	int a,b,c,sum=0,average;
	printf("enter the three numbers");
	scanf("%d%d%d",&a,&b,&c);
	sum=a+b+c;
	average=sum/3;
	printf("%d",average);
	return 0;
}
