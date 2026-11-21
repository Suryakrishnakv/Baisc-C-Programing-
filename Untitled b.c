#include<stdio.h>
#include<malloc.h>
struct salary
{
	float bp;
	float da;
	float hra;
};
int main()
{
	struct salary *s;
	s=(struct salary *)malloc(sizeof(struct salary));
	printf("enter bp da and hra");
	scanf("%f%f%f",&s->bp,&s->da,&s->hra);
	printf("salary %f",s->bp+s->da+s->hra);
	free(s);
	return 0;
}
