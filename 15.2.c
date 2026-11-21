#include <stdio.h>
enum Day
{
    Monday = 1,   
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};
int main() 
{
    int dayNumber;
    printf("Enter a number between 1 and 7 to get the corresponding day of the week: ");
    scanf("%d", &dayNumber);
    switch(dayNumber)
	{
        case Monday:
            printf("The day is Monday.\n");
            break;
        case Tuesday:
            printf("The day is Tuesday.\n");
            break;
        case Wednesday:
            printf("The day is Wednesday.\n");
            break;
        case Thursday:
            printf("The day is Thursday.\n");
            break;
        case Friday:
            printf("The day is Friday.\n");
            break;
        case Saturday:
            printf("The day is Saturday.\n");
            break;
        case Sunday:
            printf("The day is Sunday.\n");
            break;
        default:
            printf("Invalid input! Please enter a number between 1 and 7.\n");
            break;
    }
    return 0;
}
