#include<stdio.h>
int main()
{
	printf("1 for porrota\n2 for chapathi\n3 for chiken curry");
    int a;
    printf("enter a");
    scanf("%d",&a);
	switch(a)
	{
		case 1:
			{
				printf("porotta");
				break;
			}
        case 2:
        	{
        		printf("chapathi");
        		break;
			}
		case 3:
			{
				printf("chiken curry");
				break;
			}
		default:
			{
				printf("nil");
				break;
			}
	}
}
