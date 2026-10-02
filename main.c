#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "supplier.h"
#include "login.h"
#include "assets.h"
#include "reports.h"

int main(void)
{
    int choice;

    if (!login())
{
    return 0;
}

    do
    {
        printf("\n========================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("6. Exit\n");
        printf("========================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input. Please enter a number.\n");

            while (getchar() != '\n')
            {
                /* Clear invalid input */
            }

            choice = 0;
            continue;
        }

        while (getchar() != '\n')
        {
            /* Clear input buffer */
        }

        switch (choice)
        {
            case 1:
                employeeMenu();
                break;

            case 2:
                budgetMenu();
                break;

            case 3:
                supplierMenu();
                break;

            case 4:
                assetMenu();
                break;

            case 5:
                reportsMenu();
                break;

            case 6:
                printf("\nExiting MFMS. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice. Please enter a number from 1 to 6.\n");
        }

    } while (choice != 6);

    return 0;
}