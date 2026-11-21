#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define FILENAME "expenses.dat"

typedef struct {
    char date[11];       // Date format YYYY-MM-DD
    char category[30];   // Category (e.g., Food, Travel)
    char description[100];  // Description of the expense
    float amount;        // Expense amount
} Expense;

Expense expenses[MAX_EXPENSES];
int expense_count = 0;

void load_expenses();
void save_expenses();
void add_expense();
void edit_expense();
void delete_expense();
void view_expenses();
void view_category_breakdown();
void check_budget(float budget);
float get_total_expenses();
void menu();

int main() {
    float budget;

    // Load expenses from the file
    load_expenses();

    // Ask user for monthly budget
    printf("Enter your monthly budget: ");
    scanf("%f", &budget);
    
    while (1) {
        menu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                edit_expense();
                break;
            case 3:
                delete_expense();
                break;
            case 4:
                view_expenses();
                break;
            case 5:
                view_category_breakdown();
                break;
            case 6:
                check_budget(budget);
                break;
            case 7:
                save_expenses();
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

void load_expenses() {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("No previous expenses found. Starting fresh.\n");
        return;
    }
    fread(&expense_count, sizeof(int), 1, file);
    fread(expenses, sizeof(Expense), expense_count, file);
    fclose(file);
}

void save_expenses() {
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL) {
        printf("Error saving expenses to file.\n");
        return;
    }
    fwrite(&expense_count, sizeof(int), 1, file);
    fwrite(expenses, sizeof(Expense), expense_count, file);
    fclose(file);
}

void add_expense() {
    if (expense_count >= MAX_EXPENSES) {
        printf("Expense record limit reached.\n");
        return;
    }

    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%s", expenses[expense_count].date);
    printf("Enter expense category (e.g., Food, Travel): ");
    scanf("%s", expenses[expense_count].category);
    printf("Enter expense description: ");
    scanf(" %[^\n]", expenses[expense_count].description);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[expense_count].amount);

    expense_count++;
    save_expenses();
    printf("Expense added successfully.\n");
}

void edit_expense() {
    char date[11], category[30];
    printf("Enter the date of the expense to edit (YYYY-MM-DD): ");
    scanf("%s", date);
    printf("Enter the category of the expense to edit: ");
    scanf("%s", category);

    for (int i = 0; i < expense_count; i++) {
        if (strcmp(expenses[i].date, date) == 0 && strcmp(expenses[i].category, category) == 0) {
            printf("Edit expense description: ");
            scanf(" %[^\n]", expenses[i].description);
            printf("Edit expense amount: ");
            scanf("%f", &expenses[i].amount);
            save_expenses();
            printf("Expense updated successfully.\n");
            return;
        }
    }
    printf("Expense not found.\n");
}

void delete_expense() {
    char date[11], category[30];
    printf("Enter the date of the expense to delete (YYYY-MM-DD): ");
    scanf("%s", date);
    printf("Enter the category of the expense to delete: ");
    scanf("%s", category);

    for (int i = 0; i < expense_count; i++) {
        if (strcmp(expenses[i].date, date) == 0 && strcmp(expenses[i].category, category) == 0) {
            for (int j = i; j < expense_count - 1; j++) {
                expenses[j] = expenses[j + 1];
            }
            expense_count--;
            save_expenses();
            printf("Expense deleted successfully.\n");
            return;
        }
    }
    printf("Expense not found.\n");
}

void view_expenses() {
    printf("\n--- Expenses ---\n");
    for (int i = 0; i < expense_count; i++) {
        printf("Date: %s, Category: %s, Description: %s, Amount: %.2f\n", 
               expenses[i].date, expenses[i].category, expenses[i].description, expenses[i].amount);
    }
    printf("\n");
}

void view_category_breakdown() {
    float total_by_category[MAX_EXPENSES] = {0};
    char categories[MAX_EXPENSES][30];
    int category_count = 0;

    for (int i = 0; i < expense_count; i++) {
        int found = 0;
        for (int j = 0; j < category_count; j++) {
            if (strcmp(expenses[i].category, categories[j]) == 0) {
                total_by_category[j] += expenses[i].amount;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(categories[category_count], expenses[i].category);
            total_by_category[category_count] = expenses[i].amount;
            category_count++;
        }
    }

    printf("\nCategory Breakdown:\n");
    for (int i = 0; i < category_count; i++) {
        printf("%s: %.2f\n", categories[i], total_by_category[i]);
    }
}

float get_total_expenses() {
    float total = 0;
    for (int i = 0; i < expense_count; i++) {
        total += expenses[i].amount;
    }
    return total;
}

void check_budget(float budget) {
    float total = get_total_expenses();
    printf("Total expenses: %.2f, Budget: %.2f\n", total, budget);
    if (total > budget) {
        printf("Warning: You have exceeded your monthly budget!\n");
    } else {
        printf("You are within the budget. Remaining budget: %.2f\n", budget - total);
    }
}

void menu() {
    printf("\n--- Digital Expense Manager ---\n");
    printf("1. Add Expense\n");
    printf("2. Edit Expense\n");
    printf("3. Delete Expense\n");
    printf("4. View Expenses\n");
    printf("5. View Category Breakdown\n");
    printf("6. Check Budget\n");
    printf("7. Exit\n");
}
