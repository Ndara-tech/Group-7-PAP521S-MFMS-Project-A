#include <stdio.h>
#include <string.h>
#include "employees.h"

#define MAX_EMPLOYEES 50

int employeeIDs[MAX_EMPLOYEES];
char employeeNames[MAX_EMPLOYEES][100];
char employeeDepartments[MAX_EMPLOYEES][50];

double basicSalaries[MAX_EMPLOYEES];
double housingAllowances[MAX_EMPLOYEES];
double transportAllowances[MAX_EMPLOYEES];

int employeeCount = 0;


/* Clears remaining characters from keyboard input */
void clearEmployeeInput(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
        /* Clear input */
    }
}


/* Employee Management submenu */
void employeeMenu(void)
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("        EMPLOYEE MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Calculate Employee Salary\n");
        printf("5. Return to Main Menu\n");
        printf("========================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input. Please enter a number.\n");
            clearEmployeeInput();
            choice = 0;
            continue;
        }

        clearEmployeeInput();

        switch (choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                calculateSalary();
                break;

            case 5:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice. Please select 1 to 5.\n");
        }

    } while (choice != 5);
}


/* Add a new employee */
void addEmployee(void)
{
    int id;
    double basic;
    double housing;
    double transport;

    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("\nEmployee storage is full.\n");
        return;
    }

    printf("\n--- ADD EMPLOYEE ---\n");

    printf("Enter Employee ID: ");

    if (scanf("%d", &id) != 1 || id <= 0)
    {
        printf("Invalid Employee ID.\n");
        clearEmployeeInput();
        return;
    }

    clearEmployeeInput();

    /* Check for duplicate Employee ID */
    for (int i = 0; i < employeeCount; i++)
    {
        if (employeeIDs[i] == id)
        {
            printf("Employee ID already exists.\n");
            return;
        }
    }

    printf("Enter Employee Name: ");
    fgets(employeeNames[employeeCount],
          sizeof(employeeNames[employeeCount]), stdin);

    employeeNames[employeeCount][
        strcspn(employeeNames[employeeCount], "\n")
    ] = '\0';

    if (strlen(employeeNames[employeeCount]) == 0)
    {
        printf("Employee name cannot be empty.\n");
        return;
    }

    printf("Enter Department: ");
    fgets(employeeDepartments[employeeCount],
          sizeof(employeeDepartments[employeeCount]), stdin);

    employeeDepartments[employeeCount][
        strcspn(employeeDepartments[employeeCount], "\n")
    ] = '\0';

    if (strlen(employeeDepartments[employeeCount]) == 0)
    {
        printf("Department cannot be empty.\n");
        return;
    }

    printf("Enter Basic Salary: N$");

    if (scanf("%lf", &basic) != 1 || basic < 0)
    {
        printf("Invalid salary. Salary cannot be negative.\n");
        clearEmployeeInput();
        return;
    }

    printf("Enter Housing Allowance: N$");

    if (scanf("%lf", &housing) != 1 || housing < 0)
    {
        printf("Invalid housing allowance.\n");
        clearEmployeeInput();
        return;
    }

    printf("Enter Transport Allowance: N$");

    if (scanf("%lf", &transport) != 1 || transport < 0)
    {
        printf("Invalid transport allowance.\n");
        clearEmployeeInput();
        return;
    }

    clearEmployeeInput();

    employeeIDs[employeeCount] = id;
    basicSalaries[employeeCount] = basic;
    housingAllowances[employeeCount] = housing;
    transportAllowances[employeeCount] = transport;

    employeeCount++;

    printf("\nEmployee added successfully.\n");
}


/* Display all employees */
void displayEmployees(void)
{
    if (employeeCount == 0)
    {
        printf("\nNo employees have been added yet.\n");
        return;
    }

    printf("\n========================================\n");
    printf("           EMPLOYEE LIST\n");
    printf("========================================\n");

    for (int i = 0; i < employeeCount; i++)
    {
        double grossSalary;

        grossSalary = basicSalaries[i]
                    + housingAllowances[i]
                    + transportAllowances[i];

        printf("\nEmployee %d\n", i + 1);
        printf("----------------------------------------\n");
        printf("ID:                  %d\n", employeeIDs[i]);
        printf("Name:                %s\n", employeeNames[i]);
        printf("Department:          %s\n", employeeDepartments[i]);
        printf("Basic Salary:        N$%.2f\n", basicSalaries[i]);
        printf("Housing Allowance:   N$%.2f\n", housingAllowances[i]);
        printf("Transport Allowance: N$%.2f\n", transportAllowances[i]);
        printf("Gross Salary:        N$%.2f\n", grossSalary);
    }
}


/* Search for an employee using Employee ID */
void searchEmployee(void)
{
    int searchID;
    int found = 0;

    if (employeeCount == 0)
    {
        printf("\nNo employees have been added yet.\n");
        return;
    }

    printf("\n--- SEARCH EMPLOYEE ---\n");
    printf("Enter Employee ID: ");

    if (scanf("%d", &searchID) != 1)
    {
        printf("Invalid Employee ID.\n");
        clearEmployeeInput();
        return;
    }

    clearEmployeeInput();

    for (int i = 0; i < employeeCount; i++)
    {
        if (employeeIDs[i] == searchID)
        {
            double grossSalary;

            grossSalary = basicSalaries[i]
                        + housingAllowances[i]
                        + transportAllowances[i];

            printf("\nEmployee found.\n");
            printf("----------------------------------------\n");
            printf("ID:                  %d\n", employeeIDs[i]);
            printf("Name:                %s\n", employeeNames[i]);
            printf("Department:          %s\n", employeeDepartments[i]);
            printf("Basic Salary:        N$%.2f\n", basicSalaries[i]);
            printf("Housing Allowance:   N$%.2f\n", housingAllowances[i]);
            printf("Transport Allowance: N$%.2f\n", transportAllowances[i]);
            printf("Gross Salary:        N$%.2f\n", grossSalary);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nEmployee with ID %d was not found.\n", searchID);
    }
}


/* Calculate salary for a selected employee */
void calculateSalary(void)
{
    int searchID;
    int found = 0;

    if (employeeCount == 0)
    {
        printf("\nNo employees have been added yet.\n");
        return;
    }

    printf("\n--- EMPLOYEE SALARY CALCULATION ---\n");
    printf("Enter Employee ID: ");

    if (scanf("%d", &searchID) != 1)
    {
        printf("Invalid Employee ID.\n");
        clearEmployeeInput();
        return;
    }

    clearEmployeeInput();

    for (int i = 0; i < employeeCount; i++)
    {
        if (employeeIDs[i] == searchID)
        {
            double grossSalary;

            grossSalary = basicSalaries[i]
                        + housingAllowances[i]
                        + transportAllowances[i];

            printf("\nEmployee: %s\n", employeeNames[i]);
            printf("Basic Salary:        N$%.2f\n", basicSalaries[i]);
            printf("Housing Allowance:   N$%.2f\n", housingAllowances[i]);
            printf("Transport Allowance: N$%.2f\n", transportAllowances[i]);
            printf("----------------------------------------\n");
            printf("Gross Salary:        N$%.2f\n", grossSalary);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nEmployee with ID %d was not found.\n", searchID);
    }
}