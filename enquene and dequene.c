#include<stdio.h>
#define N 5
int a[5],f=-1,r=-1;
void enquene(int e)
{
	if((r+1)% N == f)
	{
		printf("error : Quene is full");
	}
	else
	{
		if(f=-1)
		{
			f=0;
		}
		r=(r+1)% N;
		a[r] =e;
	}
}
void dequene()
{
	int i;
	if(f=-1)
	{
		printf("enter : Quene is empty");
	}
	else
	{
		printf("Dequene item %d",a[f]);
		if(f==r)// one element in the quene
		{
			f=-1;
			r=-1;
		}
		else
		{
			f=(f+1)%N;
		}
	}
}
int main()
{
	enquene(10);
	enquene(20);
	enquene(30);
	dequene();
	dequene();
	dequene();
	dequene();
	enquene(10);
	enquene(20);
	enquene(30);
	enquene(40);
	return 0;
}
