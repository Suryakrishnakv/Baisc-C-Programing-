#include<stdio.h>
#define N 5
int top=-1;
char a[N];
void push(char s)
{
	if(top==N)
	{
		printf("stack is full:\n");
	}
	else{
		top=top+1;
		a[top]=s;
	}
}
void pop()
{
	if(top==-1)
	{
		printf("stack is empty\n");
	}
	else
	{
		printf("%c",a[top]);
		top=top-1;
	}
}
int main()
{
	int i;
	char s[N];
	printf("enter a string:");
	scanf("%s",s);
	for(i=0;s[i]!='\0';i++)
	{
		push(s[i]);
	}
	while(top!=-1){
		pop();
	}
	return 0;
}

