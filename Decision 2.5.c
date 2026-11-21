#include<stdio.h>
int main()
{
	char c;
	printf("enter the c ");
	scanf("%c",&c);
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
	{
		printf("it is vowel");
	}
	else
	{
		printf("it is consonant ");
	}
	return 0;
}
