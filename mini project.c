#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_EXPENSES 100
#define MAX_CATEGORY_LENGTH 20
#define MAX_DESCRIPTION_LENGTH 100
#define EXPENSE_FILE "expenses.dat"
typedef struct 
{
    char date[11];        
    char category[MAX_CATEGORY_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
} Expense;
Expense expenses[MAX_EXPENSES];
int expense_count = 0;
float budget = 0.0f;
void load_expenses() 
{
    FILE *file = fopen(EXPENSE_FILE, "rb");
    if (file != NULL) 
	{
        fread(&expense_count, sizeof(int), 1, file);
        fread(expenses, sizeof(Expense), expense_count, file);
        fclose(file);
    }
}
void save_expenses() 
{
    FILE *file = fopen(EXPENSE_FILE, "wb");
    if (file != NULL) 
	{
        fwrite(&expense_count, sizeof(int), 1, file);
        fwrite(expenses, sizeof(Expense), expense_count, file);
        fclose(file);
    }
}
void set_budget() 
{
    printf("Enter your monthly budget: $");
    scanf("%f", &budget);
    printf("Budget set to: $%.2f\n", budget);
}
void add_expense() 
{
    if (expense_count >= MAX_EXPENSES) 
	{
        printf("Error: Maximum expense limit reached!\n");
        return;
    }
    Expense new_expense;
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", new_expense.date);
    printf("Enter category (e.g., Food, Travel, Utilities, etc.): ");
    scanf("%s", new_expense.category);
    printf("Enter description: ");
    getchar();
    fgets(new_expense.description, MAX_DESCRIPTION_LENGTH, stdin);
    new_expense.description[strcspn(new_expense.description, "\n")] = 0;  
    printf("Enter amount: $");
    scanf("%f", &new_expense.amount);
    expenses[expense_count] = new_expense;
    expense_count++;
    save_expenses();
    printf("Expense added successfully!\n");
}
void edit_expense() 
{
    char date[11], category[MAX_CATEGORY_LENGTH], description[MAX_DESCRIPTION_LENGTH];
    printf("Enter date of the expense to edit (YYYY-MM-DD): ");
    scanf("%s", date);
    printf("Enter category of the expense: ");
    scanf("%s", category);
    printf("Enter description of the expense: ");
    getchar();  
    fgets(description, MAX_DESCRIPTION_LENGTH, stdin);
    description[strcspn(description, "\n")] = 0;  
    for (int i = 0; i < expense_count;i++) 
	{
        if (strcmp(expenses[i].date, date) == 0 && strcmp(expenses[i].category, category) == 0 &&
            strcmp(expenses[i].description, description) == 0) 
			{
            printf("Enter new amount: $");
            scanf("%f", &expenses[i].amount);
            save_expenses();
            printf("Expense updated successfully!\n");
            return;
        }
    }
    printf("Expense not found!\n");
}
void delete_expense()
{
    char date[11], category[MAX_CATEGORY_LENGTH], description[MAX_DESCRIPTION_LENGTH];
    printf("Enter date of the expense to delete (YYYY-MM-DD): ");
    scanf("%s", date);
    printf("Enter category of the expense: ");
    scanf("%s", category);
    printf("Enter description of the expense: ");
    getchar();  
    fgets(description, MAX_DESCRIPTION_LENGTH, stdin);
    description[strcspn(description, "\n")] = 0;  

    for (int i = 0; i < expense_count; i++) 
	{
        if (strcmp(expenses[i].date, date) == 0 && strcmp(expenses[i].category, category) == 0 &&
            strcmp(expenses[i].description, description) == 0)
			{
            for (int j = i; j < expense_count - 1; j++) 
			{
                expenses[j] = expenses[j + 1];
            }
            expense_count--;
            save_expenses();
            printf("Expense deleted successfully!\n");
            return;
        }
    }
    printf("Expense not found!\n");
}
void display_expenses() 
{
    if (expense_count == 0) 
	{
        printf("No expenses recorded yet.\n");
        return;
    }
    printf("Expense Records:\n");
    for (int i = 0; i < expense_count; i++) {
        printf("%s | %s | %s | $%.2f\n", expenses[i].date, expenses[i].category, expenses[i].description, expenses[i].amount);
    }
}
void generate_monthly_report() 
{
    int month, year;
    float total_expenses = 0.0f;
    float category_totals[5] = {0.0f};  
    printf("Enter the month (1-12): ");
    scanf("%d", &month);
    printf("Enter the year (e.g., 2025): ");
    scanf("%d", &year);
    for (int i = 0; i < expense_count; i++) 
	{
        int exp_month, exp_year;
        sscanf(expenses[i].date, "%d-%d-%d", &exp_year, &exp_month, &day);  
        if (exp_month == month && exp_year == year) 
		{
            total_expenses += expenses[i].amount;
            if (strcmp(expenses[i].category, "Food") == 0) 
			{
                category_totals[0] += expenses[i].amount;
            } 
			else if (strcmp(expenses[i].category, "Travel") == 0) 
			{
                category_totals[1] += expenses[i].amount;
            } 
			else if (strcmp(expenses[i].category, "Utilities") == 0) 
			{
                category_totals[2] += expenses[i].amount;
            } 
			else if (strcmp(expenses[i].category, "Entertainment") == 0)
			{
                category_totals[3] += expenses[i].amount;
            } 
			else 
			{
                category_totals[4] += expenses[i].amount;
            }
        }
    }
    printf("\nMonthly Report for %d-%d\n", month, year);
    printf("Total Expenses: $%.2f\n", total_expenses);
    printf("Category Breakdown:\n");
    printf("Food: $%.2f\n", category_totals[0]);
    printf("Travel: $%.2f\n", category_totals[1]);
    printf("Utilities: $%.2f\n", category_totals[2]);
    printf("Entertainment: $%.2f\n", category_totals[3]);
    printf("Miscellaneous: $%.2f\n", category_totals[4]);
    if (budget > 0 && total_expenses > budget) 
	{
        printf("WARNING: You have exceeded your monthly budget of $%.2f by $%.2f\n", budget, total_expenses - budget);
    }
}
int main() 
{
    load_expenses();
    int choice;
    printf("Welcome to the Expense Tracker!\n");
    while (1) 
	{
        printf("\n1. Set Budget\n");
        printf("2. Add Expense\n");
        printf("3. Edit Expense\n");
        printf("4. Delete Expense\n");
        printf("5. Generate Monthly Report\n");
        printf("6. Display All Expenses\n");
        printf("7. Exit\n");
        printf("Choose an option (1-7): ");
        scanf("%d", &choice);
        switch (choice) 
		{
            case 1: set_budget(); break;
            case 2: add_expense(); break;
            case 3: edit_expense(); break;
            case 4: delete_expense(); break;
            case 5: generate_monthly_report(); break;
            case 6: display_expenses(); break;
            case 7: printf("Goodbye!\n"); return 0;
            default: printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
