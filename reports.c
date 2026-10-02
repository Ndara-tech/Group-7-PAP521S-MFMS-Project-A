#include <stdio.h>
#include "reports.h"
#include "supplier.h"
#include "assets.h"

/* Employee data from employees.c */
extern int employeeCount;
extern double basicSalaries[];
extern double housingAllowances[];
extern double transportAllowances[];

/* Budget data from budget.c */
extern int budgetCount;
extern char departmentNames[][100];
extern double allocatedBudgets[];
extern double expenditures[];

/* Clear invalid keyboard input */
static void clearReportInput(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

/* Reports submenu */
void reportsMenu(void)
{
    int choice = 0;

    do
    {
        printf("\n========================================\n");
        printf("                 REPORTS\n");
        printf("========================================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Return to Main Menu\n");
        printf("========================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input. Please enter a number.\n");
            clearReportInput();
            choice = 0;
            continue;
        }

        clearReportInput();

        switch (choice)
        {
            case 1:
                employeeReport();
                break;

            case 2:
                budgetReport();
                break;

            case 3:
                supplierReport();
                break;

            case 4:
                assetReport();
                break;

            case 5:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice. Please select 1 to 5.\n");
        }

    } while (choice != 5);
}

/* Employee summary report */
void employeeReport(void)
{
    int i;
    double grossSalary;
    double totalSalary = 0.0;
    double averageSalary;
    double highestSalary;
    double lowestSalary;

    printf("\n========================================\n");
    printf("             EMPLOYEE REPORT\n");
    printf("========================================\n");

    if (employeeCount == 0)
    {
        printf("No employees have been registered yet.\n");
        return;
    }

    highestSalary = basicSalaries[0]
                  + housingAllowances[0]
                  + transportAllowances[0];

    lowestSalary = highestSalary;

    for (i = 0; i < employeeCount; i++)
    {
        grossSalary = basicSalaries[i]
                    + housingAllowances[i]
                    + transportAllowances[i];

        totalSalary += grossSalary;

        if (grossSalary > highestSalary)
        {
            highestSalary = grossSalary;
        }

        if (grossSalary < lowestSalary)
        {
            lowestSalary = grossSalary;
        }
    }

    averageSalary = totalSalary / employeeCount;

    printf("Total Employees: %d\n", employeeCount);
    printf("Average Salary:  N$%.2f\n", averageSalary);
    printf("Highest Salary:  N$%.2f\n", highestSalary);
    printf("Lowest Salary:   N$%.2f\n", lowestSalary);
}

/* Budget summary report */
void budgetReport(void)
{
    int i;
    int exceededCount = 0;
    double totalAllocated = 0.0;
    double totalExpenditure = 0.0;
    double totalRemaining;

    printf("\n========================================\n");
    printf("              BUDGET REPORT\n");
    printf("========================================\n");

    if (budgetCount == 0)
    {
        printf("No departmental budgets have been added yet.\n");
        return;
    }

    for (i = 0; i < budgetCount; i++)
    {
        totalAllocated += allocatedBudgets[i];
        totalExpenditure += expenditures[i];
    }

    totalRemaining = totalAllocated - totalExpenditure;

    printf("Total Allocated Budget: N$%.2f\n",
           totalAllocated);

    printf("Total Expenditure:      N$%.2f\n",
           totalExpenditure);

    printf("Remaining Budget:       N$%.2f\n",
           totalRemaining);

    printf("\nDepartments Exceeding Budget:\n");

    for (i = 0; i < budgetCount; i++)
    {
        if (expenditures[i] > allocatedBudgets[i])
        {
            printf("- %s\n", departmentNames[i]);
            exceededCount++;
        }
    }

    if (exceededCount == 0)
    {
        printf("None\n");
    }

    printf("\nTotal Departments Exceeding Budget: %d\n",
           exceededCount);
}

/* Supplier report */
void supplierReport(void)
{
    printf("\n========================================\n");
    printf("             SUPPLIER REPORT\n");
    printf("========================================\n");

    displaySuppliers();
}

/* Asset report */
void assetReport(void)
{
    printf("\n========================================\n");
    printf("               ASSET REPORT\n");
    printf("========================================\n");

    displayAssets();
}