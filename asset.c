
#include <stdio.h>
#include <string.h>

#define MAX_ASSETS 100   

int    assetID[MAX_ASSETS];
char   assetName[MAX_ASSETS][50];
char   assetType[MAX_ASSETS][30];
double purchaseValue[MAX_ASSETS];
char   department[MAX_ASSETS][50];
char   condition[MAX_ASSETS][20];

int assetCount = 0;      

void displayMenu();
void readText(char text[], int size);
int  readInt();
double readDouble();
void addAsset();
void displayAssets();
void searchAsset();
void printAsset(int position);
int  findAssetByID(int id);

int main()
{
    int choice;

    printf("Welcome to the Municipal Asset Register\n");

    do
    {
        displayMenu();
        choice = readInt();

        switch (choice)
        {
            case 1:
                addAsset();
                break;
            case 2:
                displayAssets();
                break;
            case 3:
                searchAsset();
                break;
            case 4:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}


void displayMenu()
{
    printf("\n");
    printf("================================\n");
    printf("       ASSET MANAGEMENT\n");
    printf("================================\n");
    printf("1. Add Asset\n");
    printf("2. Display All Assets\n");
    printf("3. Search Asset\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
}


void readText(char text[], int size)
{
    fgets(text, size, stdin);
    text[strcspn(text, "\n")] = '\0';
}

int readInt()
{
    int number = 0;
    char line[50];

    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &number);
    return number;
}


double readDouble()
{
    double number = 0.0;
    char line[50];

    fgets(line, sizeof(line), stdin);
    sscanf(line, "%lf", &number);
    return number;
}


int findAssetByID(int id)
{
    for (int i = 0; i < assetCount; i++)
    {
        if (assetID[i] == id)
        {
            return i;
        }
    }
    return -1;
}

void addAsset()
{
    int id;
    int choice;
    int n;

    if (assetCount >= MAX_ASSETS)
    {
        printf("The asset register is full.\n");
        return;
    }

    n = assetCount;

    printf("\n--- ADD ASSET ---\n");

    
    printf("Enter asset ID: ");
    id = readInt();

    if (id <= 0)
    {
        printf("Asset ID must be a positive number.\n");
        return;
    }
    if (findAssetByID(id) != -1)
    {
        printf("That asset ID already exists.\n");
        return;
    }
    assetID[n] = id;

    
    printf("Select asset type:\n");
    printf("1. Vehicle\n");
    printf("2. Computer\n");
    printf("3. Building\n");
    printf("4. Equipment\n");
    printf("5. Office furniture\n");
    printf("Enter choice: ");
    choice = readInt();

    switch (choice)
    {
        case 1:
            strcpy(assetType[n], "Vehicle");
            break;
        case 2:
            strcpy(assetType[n], "Computer");
            break;
        case 3:
            strcpy(assetType[n], "Building");
            break;
        case 4:
            strcpy(assetType[n], "Equipment");
            break;
        case 5:
            strcpy(assetType[n], "Office furniture");
            break;
        default:
            printf("Invalid type. Asset not added.\n");
            return;
    }


    printf("Enter purchase value (NAD): ");
    purchaseValue[n] = readDouble();

    if (purchaseValue[n] < 0)
    {
        printf("Purchase value cannot be negative. Asset not added.\n");
        return;
    }

    
    printf("Enter department: ");
    readText(department[n], sizeof(department[n]));

    /* Condition */
    printf("Select condition:\n");
    printf("1. Good\n");
    printf("2. Fair\n");
    printf("3. Poor\n");
    printf("Enter choice: ");
    choice = readInt();

    switch (choice)
    {
        case 1:
            strcpy(condition[n], "Good");
            break;
        case 2:
            strcpy(condition[n], "Fair");
            break;
        case 3:
            strcpy(condition[n], "Poor");
            break;
        default:
            printf("Invalid condition. Asset not added.\n");
            return;
    }

    
    assetCount++;
    printf("Asset added successfully.\n");
}


void printAsset(int position)
{
    printf("Asset ID       : %d\n", assetID[position]);
    printf("Name           : %s\n", assetName[position]);
    printf("Type           : %s\n", assetType[position]);
    printf("Purchase value : NAD %.2f\n", purchaseValue[position]);
    printf("Department     : %s\n", department[position]);
    printf("Condition      : %s\n", condition[position]);
}


void displayAssets()
{
    double total = 0.0;

    printf("\n--- ALL ASSETS ---\n");

    if (assetCount == 0)
    {
        printf("No assets have been added yet.\n");
        return;
    }

    for (int i = 0; i < assetCount; i++)
    {
        printf("\nAsset %d of %d\n", i + 1, assetCount);
        printAsset(i);
        total = total + purchaseValue[i];
    }

    printf("\nTotal assets: %d\n", assetCount);
    printf("Total purchase value: NAD %.2f\n", total);
}


void searchAsset()
{
    int choice;
    int id;
    int position;
    int found = 0;
    char searchName[50];

    printf("\n--- SEARCH ASSET ---\n");

    if (assetCount == 0)
    {
        printf("No assets have been added yet.\n");
        return;
    }

    printf("1. Search by asset ID\n");
    printf("2. Search by asset name\n");
    printf("Enter choice: ");
    choice = readInt();

    if (choice == 1)
    {
        printf("Enter asset ID: ");
        id = readInt();

        position = findAssetByID(id);

        if (position == -1)
        {
            printf("Asset not found.\n");
        }
        else
        {
            printf("\nAsset found:\n");
            printAsset(position);
        }
    }
    else if (choice == 2)
    {
        printf("Enter asset name (must match exactly): ");
        readText(searchName, sizeof(searchName));

        for (int i = 0; i < assetCount; i++)
        {
            if (strcmp(assetName[i], searchName) == 0)
            {
                printf("\nAsset found:\n");
                printAsset(i);
                found = 1;
            }
        }

        if (!found)
        {
            printf("Asset not found.\n");
        }
    }
    else
    {
        printf("Invalid choice.\n");
    }
}