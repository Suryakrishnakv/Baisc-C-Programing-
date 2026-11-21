#include <stdio.h>
union EmployeeInfo 
{
    float salary;  
    int age;       
};
int main() 
{
    union EmployeeInfo employee;  
    int choice;
    printf("Choose the information you want to enter:\n");
    printf("1. Employee's Salary\n");
    printf("2. Employee's Age\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    if (choice == 1) 
	{
        printf("Enter the employee's salary: ");
        scanf("%f", &employee.salary);
        printf("Employee's salary is: %.2f\n", employee.salary);
    } 
	else if (choice == 2) 
	{
        printf("Enter the employee's age: ");
        scanf("%d", &employee.age);
        printf("Employee's age is: %d\n", employee.age);
    } 
	else 
	{
        printf("Invalid choice! Please enter 1 for salary or 2 for age.\n");
    }
    return 0;
}
