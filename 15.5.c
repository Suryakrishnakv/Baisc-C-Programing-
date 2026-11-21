#include <stdio.h>
#define CUBE(x) ((x) * (x) * (x))
int main() 
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int result = CUBE(num);
    printf("The cube of %d is %d\n", num, result);
    return 0;
}
