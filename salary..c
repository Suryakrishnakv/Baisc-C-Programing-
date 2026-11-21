#include<stdio.h>
#include<malloc.h>
struct salary
{
	float bp;
	float da;
	float hra;
};
typedef struct salary sa;
int main()
{
	sa *s;
	s=(sa*)malloc(sizeof(sa));
	printf("enter bp da and hra");
	scanf("%f%f%f",&s->bp,&s->da,&s->hra);
	printf("salary %f",s->bp+s->da+s->hra);
	free(s);
	return 0;
}
