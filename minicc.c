#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EXPENSES 100
#define FILENAME "expenses.dat"
typedef struct 
{
    char date[11];      
    char category[50]; 
    char description[100]; 
    float amount;       
} Expense;
int load_expenses(Expense expenses[]) 
{
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) 
	{
        return 0; 
    }
    int count = fread(expenses, sizeof(Expense), MAX_EXPENSES, file);
    fclose(file);
    return count;
}
void save_expenses(Expense expenses[], int count) 
{
    FILE *file = fopen(FILENAME, "wb");
    if (file != NULL) 
	{
        fwrite(expenses, sizeof(Expense), count, file);
        fclose(file);
    }
}
void add_expense(Expense expenses[], int *count) 
{
    if (*count >= MAX_EXPENSES) 
	{
        printf("Cannot add more expenses, limit reached.\n");
        return;
    }
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", expenses[*count].date);
    printf("Enter the category (Food, Travel, Utilities, etc.): ");
    scanf("%s", expenses[*count].category);
    printf("Enter the description: ");
    scanf(" %[^\n]s", expenses[*count].description); 
    printf("Enter the amount: ");
    scanf("%f", &expenses[*count].amount);
    (*count)++;
    save_expenses(expenses, *count);
    printf("Expense added successfully.\n");
}
void edit_expense(Expense expenses[], int count) 
{
    char date[11];
    printf("Enter the date of the expense you want to edit (YYYY-MM-DD): ");
    scanf("%s", date);
	int i;
    for ( i = 0; i < count; i++) 
	{
        if (strcmp(expenses[i].date, date) == 0) 
		{
            printf("Current details: \n");
            printf("Category: %s\n", expenses[i].category);
            printf("Description: %s\n", expenses[i].description);
            printf("Amount: %.2f\n", expenses[i].amount);
            printf("Enter new category (or press Enter to keep current): ");
            char category[50];
            scanf("%s", category);
            if (strlen(category) > 0) 
			{
                strcpy(expenses[i].category, category);
            }
            printf("Enter new description (or press Enter to keep current): ");
            char description[100];
            scanf(" %[^\n]s", description);
            if (strlen(description) > 0) 
			{
                strcpy(expenses[i].description, description);
            }
            printf("Enter new amount (or press Enter to keep current): ");
            float amount;
            if (scanf("%f", &amount) == 1) 
			{
                expenses[i].amount = amount;
            }
            save_expenses(expenses, count);
            printf("Expense updated successfully.\n");
            return;
        }
    }
    printf("Expense not found.\n");
}
void delete_expense(Expense expenses[], int *count) 
{
    char date[11];
    printf("Enter the date of the expense you want to delete (YYYY-MM-DD): ");
    scanf("%s", date);
	int i,j;
    for ( i = 0; i < *count; i++) 
	{
        if (strcmp(expenses[i].date, date) == 0) 
		{
            for (j = i; j < *count - 1; j++) 
			{
                expenses[j] = expenses[j + 1];
            }
            (*count)--;
            save_expenses(expenses, *count);
            printf("Expense deleted successfully.\n");
            return;
        }
    }
    printf("Expense not found.\n");
}
void display_report(Expense expenses[], int count, float budget) 
{
    float total_expenses = 0;
    float category_expenses[50] = {0}; 
    char categories[50][50];  
    int category_count = 0;
	int i;
    for (i = 0; i < count; i++) 
	{
        total_expenses += expenses[i].amount;
		int i,j;
        int found = 0;
        for (j = 0; j < category_count; j++) 
		{
            if (strcmp(categories[j], expenses[i].category) == 0) 
			{
                category_expenses[j] += expenses[i].amount;
                found = 1;
                break;
            }
        }
        if (!found) 
		{
            strcpy(categories[category_count], expenses[i].category);
            category_expenses[category_count] = expenses[i].amount;
            category_count++;
        }
    }
    printf("\nMonthly Expense Report:\n");
    printf("Total Expenses: $%.2f\n", total_expenses);
    for (i = 0; i < category_count; i++) 
	{
        printf("%s: $%.2f\n", categories[i], category_expenses[i]);
    }
    printf("\nBudget: $%.2f\n", budget);
    if (total_expenses > budget) 
	{
        printf("Warning: You have exceeded your budget by $%.2f\n", total_expenses - budget);
    } 
	else 
	{
        printf("You are within the budget by $%.2f\n", budget - total_expenses);
    }
}
int main() 
{
    Expense expenses[MAX_EXPENSES];
    int count = load_expenses(expenses);
    float budget;
    printf("Enter your monthly budget: ");
    scanf("%f", &budget);
    while (1) 
	{
        printf("\nMenu:\n");
        printf("1. Add Expense\n");
        printf("2. Edit Expense\n");
        printf("3. Delete Expense\n");
        printf("4. Display Monthly Report\n");
        printf("5. Exit\n");
        int choice;
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) 
		{
            case 1:
                add_expense(expenses, &count);
                break;
            case 2:
                edit_expense(expenses, count);
                break;
            case 3:
                delete_expense(expenses, &count);
                break;
            case 4:
                display_report(expenses, count, budget);
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
