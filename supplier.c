#include <stdio.h>
#include <string.h>
#include "supplier.h"

#define MAX_SUPPLIERS 100

typedef struct
{
    int supplierID;
    char supplierName[100];
    char email[100];
    char telephone[50];
    char town[100];
    char product[100];
} Supplier;

static Supplier suppliers[MAX_SUPPLIERS];
static int supplierCount = 0;

static void clearInputBuffer(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

static void removeNewline(char text[])
{
    text[strcspn(text, "\n")] = '\0';
}

void supplierMenu(void)
{
    int choice = 0;

    do
    {
        printf("\n========================================\n");
        printf("          SUPPLIER MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
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
                addSupplier();
                break;

            case 2:
                displaySuppliers();
                break;

            case 3:
                searchSupplier();
                break;

            case 4:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice. Please enter 1 to 4.\n");
        }

    } while (choice != 4);
}

void addSupplier(void)
{
    int i;

    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("\nSupplier storage is full.\n");
        return;
    }

    printf("\n--- ADD SUPPLIER ---\n");

    printf("Enter Supplier ID: ");

    if (scanf("%d", &suppliers[supplierCount].supplierID) != 1)
    {
        printf("Invalid Supplier ID.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    for (i = 0; i < supplierCount; i++)
    {
        if (suppliers[i].supplierID ==
            suppliers[supplierCount].supplierID)
        {
            printf("A supplier with this ID already exists.\n");
            return;
        }
    }

    printf("Enter Supplier Name: ");
    fgets(suppliers[supplierCount].supplierName,
          sizeof(suppliers[supplierCount].supplierName), stdin);
    removeNewline(suppliers[supplierCount].supplierName);

    if (strlen(suppliers[supplierCount].supplierName) == 0)
    {
        printf("Supplier name cannot be empty.\n");
        return;
    }

    printf("Enter Email: ");
    fgets(suppliers[supplierCount].email,
          sizeof(suppliers[supplierCount].email), stdin);
    removeNewline(suppliers[supplierCount].email);

    printf("Enter Telephone Number: ");
    fgets(suppliers[supplierCount].telephone,
          sizeof(suppliers[supplierCount].telephone), stdin);
    removeNewline(suppliers[supplierCount].telephone);

    printf("Enter Town/Location: ");
    fgets(suppliers[supplierCount].town,
          sizeof(suppliers[supplierCount].town), stdin);
    removeNewline(suppliers[supplierCount].town);

    printf("Enter Product/Service Supplied: ");
    fgets(suppliers[supplierCount].product,
          sizeof(suppliers[supplierCount].product), stdin);
    removeNewline(suppliers[supplierCount].product);

    supplierCount++;

    printf("\nSupplier added successfully.\n");
}

void displaySuppliers(void)
{
    int i;

    if (supplierCount == 0)
    {
        printf("\nNo suppliers have been added yet.\n");
        return;
    }

    printf("\n========================================\n");
    printf("             SUPPLIER LIST\n");
    printf("========================================\n");

    for (i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("----------------------------------------\n");
        printf("Supplier ID:     %d\n", suppliers[i].supplierID);
        printf("Supplier Name:   %s\n", suppliers[i].supplierName);
        printf("Email:           %s\n", suppliers[i].email);
        printf("Telephone:       %s\n", suppliers[i].telephone);
        printf("Town/Location:   %s\n", suppliers[i].town);
        printf("Product/Service: %s\n", suppliers[i].product);
    }
}

void searchSupplier(void)
{
    int searchID;
    int i;

    if (supplierCount == 0)
    {
        printf("\nNo suppliers have been added yet.\n");
        return;
    }

    printf("\nEnter Supplier ID to search: ");

    if (scanf("%d", &searchID) != 1)
    {
        printf("Invalid Supplier ID.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    for (i = 0; i < supplierCount; i++)
    {
        if (suppliers[i].supplierID == searchID)
        {
            printf("\n--- SUPPLIER FOUND ---\n");
            printf("Supplier ID:     %d\n", suppliers[i].supplierID);
            printf("Supplier Name:   %s\n", suppliers[i].supplierName);
            printf("Email:           %s\n", suppliers[i].email);
            printf("Telephone:       %s\n", suppliers[i].telephone);
            printf("Town/Location:   %s\n", suppliers[i].town);
            printf("Product/Service: %s\n", suppliers[i].product);
            return;
        }
    }

    printf("\nSupplier with ID %d was not found.\n", searchID);
}