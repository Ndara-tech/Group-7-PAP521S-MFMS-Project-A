#include <stdio.h>
#include <string.h>
#include "budget.h"

#define MAX_BUDGETS 100

char departmentNames[MAX_BUDGETS][100];
double allocatedBudgets[MAX_BUDGETS];
double expenditures[MAX_BUDGETS];

int budgetCount = 0;

/* Clear remaining characters from input buffer */
static void clearInputBuffer(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

/* Remove newline added by fgets */
static void removeNewline(char text[])
{
    text[strcspn(text, "\n")] = '\0';
}

/* Budget Management submenu */
void budgetMenu(void)
{
    int choice = 0;

    do
    {
        printf("\n========================================\n");
        printf("           BUDGET MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Department Budget\n");
        printf("2. Display Budget Information\n");
        printf("3. Check Budget Balance\n");
        printf("4. Return to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input. Please enter a number.\n");
            clearInputBuffer();
            choice = 0;
            continue;
        }

        clearInputBuffer();

        switch (choice)
        {
            case 1:
                addBudgetItem();
                break;

            case 2:
                displayBudget();
                break;

            case 3:
                checkBudgetBalance();
                break;

            case 4:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice. Please enter 1 to 4.\n");
        }

    } while (choice != 4);
}

/* Add a departmental budget */
void addBudgetItem(void)
{
    if (budgetCount >= MAX_BUDGETS)
    {
        printf("\nBudget storage is full.\n");
        return;
    }

    printf("\n--- ADD DEPARTMENT BUDGET ---\n");

    printf("Enter Department Name: ");
    fgets(departmentNames[budgetCount],
          sizeof(departmentNames[budgetCount]), stdin);

    removeNewline(departmentNames[budgetCount]);

    if (strlen(departmentNames[budgetCount]) == 0)
    {
        printf("Department name cannot be empty.\n");
        return;
    }

    printf("Enter Allocated Budget: N$");

    if (scanf("%lf", &allocatedBudgets[budgetCount]) != 1)
    {
        printf("Invalid budget amount.\n");
        clearInputBuffer();
        return;
    }

    if (allocatedBudgets[budgetCount] < 0)
    {
        printf("Allocated budget cannot be negative.\n");
        clearInputBuffer();
        return;
    }

    printf("Enter Expenditure: N$");

    if (scanf("%lf", &expenditures[budgetCount]) != 1)
    {
        printf("Invalid expenditure amount.\n");
        clearInputBuffer();
        return;
    }

    if (expenditures[budgetCount] < 0)
    {
        printf("Expenditure cannot be negative.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    budgetCount++;

    printf("\nDepartment budget added successfully.\n");
}

/* Display all departmental budgets */
void displayBudget(void)
{
    int i;
    double remainingBudget;

    if (budgetCount == 0)
    {
        printf("\nNo departmental budgets have been added yet.\n");
        return;
    }

    printf("\n========================================\n");
    printf("            BUDGET INFORMATION\n");
    printf("========================================\n");

    for (i = 0; i < budgetCount; i++)
    {
        remainingBudget = allocatedBudgets[i] - expenditures[i];

        printf("\nDepartment: %s\n", departmentNames[i]);
        printf("Allocated Budget: N$%.2f\n",
               allocatedBudgets[i]);
        printf("Expenditure: N$%.2f\n",
               expenditures[i]);
        printf("Remaining Budget: N$%.2f\n",
               remainingBudget);

        if (expenditures[i] <= allocatedBudgets[i])
        {
            printf("Status: WITHIN BUDGET\n");
        }
        else
        {
            printf("Status: BUDGET EXCEEDED\n");
        }
    }
}

/* Check the budget balance of a selected department */
void checkBudgetBalance(void)
{
    char searchDepartment[100];
    int i;
    int found = 0;
    double remainingBudget;

    if (budgetCount == 0)
    {
        printf("\nNo departmental budgets have been added yet.\n");
        return;
    }

    printf("\nEnter Department Name: ");

    fgets(searchDepartment,
          sizeof(searchDepartment), stdin);

    removeNewline(searchDepartment);

    for (i = 0; i < budgetCount; i++)
    {
        if (strcmp(departmentNames[i], searchDepartment) == 0)
        {
            remainingBudget =
                allocatedBudgets[i] - expenditures[i];

            printf("\n--- BUDGET BALANCE ---\n");
            printf("Department: %s\n",
                   departmentNames[i]);
            printf("Allocated Budget: N$%.2f\n",
                   allocatedBudgets[i]);
            printf("Expenditure: N$%.2f\n",
                   expenditures[i]);
            printf("Remaining Budget: N$%.2f\n",
                   remainingBudget);

            if (expenditures[i] <= allocatedBudgets[i])
            {
                printf("Status: WITHIN BUDGET\n");
            }
            else
            {
                printf("Status: BUDGET EXCEEDED\n");
            }

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nDepartment '%s' was not found.\n",
               searchDepartment);
    }
}