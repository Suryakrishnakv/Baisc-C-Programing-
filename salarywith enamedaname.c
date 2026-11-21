#include<stdio.h>
#include<malloc.h>
struct salary
{
	float bp;
	float da;
	float hra;
	char ename[50];
	char dname[50];
};
typedef struct salary sa;
int main()
{
	sa *s;
	int n,i;
	float sum=0;
	printf("enter the number of employees");
	scanf("%d",&n);
	s=(sa*)malloc(sizeof(sa));
	for(i=0;i<n;i++)
	{
		printf("enter name dname bp da and hra ");
		scanf("%s %s %f %f %f",(s+i)->ename,(s+i)->dname,&(s+i)->bp,&(s+i)->da,&(s+i)->hra);
	}
	for(i=0;i<n;i++)
	{
		printf("%s %s %f %f %f\n",(s+i)->ename,(s+i)->dname,(s+i)->bp+(s+i)->da+(s+i)->hra);
		sum+=(s+i)->bp+(s+i)->da+(s+i)->hra;
	}
	printf("Total salary=%f",sum);
	free(s);
	return 0;
}
