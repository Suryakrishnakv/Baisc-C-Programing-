#include<stdio.h>
struct date
{
	int dd,yy;
	char mm[20];
};
int main()
{
	struct date a,b;
	printf("enter a date");
	scanf("%d %s %d",&a.dd,a.mm,&a.yy);
	printf("enter another date:");
	scanf("%d %s %d",&b.dd,b.mm,&b.yy);
	if(a.dd==b.dd&&strcmp(a.mm,b.mm)==0&&a.yy==b.yy)
	{
		printf("they are equal");
	}
	else
	{
		printf("they are not equal");
	}
}

