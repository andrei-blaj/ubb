#include "ui.h"
#include <stdio.h>

UI createUI(Controller* c)
{
    UI ui;
    ui.ctrl = c;
    
    return ui;
}

/*
	Prints the available menu for the problem
	Input: -
	Output: the menu is printed at the console
 */
void printMenu()
{
    //
    printf("\t\t --REAL ESTATE AGENCY--\t\t\n");
    printf("Press1️⃣to add an Estate.\n");
    printf("Press2️⃣to list all Estates.\n");
    printf("Press3️⃣to remove an Estate.\n");
    printf("Press4️⃣to update an Estate.\n");
    printf("Press5️⃣to list estates with {address} combination.(BONUS/MENU)\n");
    printf("Press6️⃣to filter by type and surface greater than.\n");
    printf("Press7️⃣to filter by price.(BONUS)\n");
    // printf("HIT ->'7' to undo (Coming soon...)\n");
   // printf("HIT ->'8' to redo (Coming soon...)\n");
    printf("HIT '0' to exit !\n");
    printf("Designed and implemented by Frent Tudor\n");
    printf("------------------------------------------------------\n");
}

/*
Verifies if the given command is valid (is either 1, 2, 3, 4, 5, 6 or 0)
Input: command - integer
Output: 1 - if the command is valid
0 - otherwise
*/
int validCommand(int command)
{
    if (command >= 0 && command <= 8)
        return 1;
    return 0;
}

/*
	Reads an integer number from the keyboard. Asks for number while read errors encoutered.
	Input: the message to be displayed when asking the user for input.
	Returns the number.
 */

int readIntegerNumber()
{
    char s[16];
    int res = 0;
    int flag = 0;
    int r = 0;
    
    while (flag == 0)
    {
        scanf("%s", s);
        
        r = sscanf(s, "%d", &res);	// reads data from s and stores them as integer, if possible; returns 1 if successful
        flag = (r == 1);
        if (flag == 0)
            printf("Error reading number!\n");
    }
    return res;
}

int addEstateUi(UI* ui)
{
    // read the estate's data
    char type[12+1], address[30+1];
    double surface,price;
    
    printf("Please input the type combination (must contain 12 letters max): ");
    scanf("%12s", type);
    printf("Please input the address: ");
    scanf("%30s", address);
    printf("Please input the surface: ");
    scanf("%lf", &surface);
    printf("Please input the price in $: ");
    scanf("%lf", &price);
    
    return addEstate(ui->ctrl, type, address, surface, price);
}
int deleteEstateUi(UI* ui)
{
    char address[30+1];
    printf("Please input the address of the estate you want to delete : ");
    scanf("%s", address);
    return deleteEstate(ui->ctrl, address);
}
int updateEstateUi(UI* ui)
{
    char type[12+1], address[30+1];
    double surface,price;
    
    printf("Give the address to which Estate you want to update : ");
    scanf("%30s", address);
    printf("Please input the new type : ");
    scanf("%12s", type);
    printf("Please input the new surface : ");
    scanf("%lf", &surface);
    printf("Please input the new price : ");
    scanf("%lf", &price);
    
    return updateEstate(ui->ctrl, type, address, surface, price);
}

void listAllEstates(UI* ui)
{
    EstateRepo* repo = getRepo(ui->ctrl);
    int length = getLength(repo);
    
    if (length == 0)
    {        char* str = "There are no stored Estates.";
        printf("%s \n", str);
    }
    
    for (int i = 0; i < getLength(repo); i++)
    {
        char str[200];
        toString(getEstateOnPos(repo, i), str);
        printf("%s\n", str);
    }
}

void listEstatesWithCombinations(UI* ui)
{
    char address[30+1];
    int CMD = 0;
    printf("Please input the address combination (must contain maximum 30 letters); input 'null' for no address combination: ");
    scanf("%30s", address);
    if (strcmp(address, "null") == 0)
    {
        printf("\nPress '1' for ascending order.\n");
        printf("Press '2' for descending order.\n");
        printf("Choose : ");
        CMD = readIntegerNumber();
    }
    
    EstateRepo res = filterByAddressCombination(ui->ctrl, address ,CMD);
    int length = getLength(&res);
    if (length == 0)
    {
        printf("There are no Estates with the given address combination.");
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            char str[200];
            toString(getEstateOnPos(&res, i), str);
            printf("%s\n", str);
        }
    }
}
void filterByTypeSurfaceUi(UI* ui)
{
    char type[12+1];
    double surface;
    printf("Please input the type : ");
    scanf("%12s", type);
    printf("Please input the surface : ");
    scanf("%lf", &surface);
    EstateRepo res = filterByTypeSurface(ui->ctrl, type, surface);
    int length = getLength(&res);
    if (length == 0)
    {
        printf("There are no Estates with this type or surface over what you mentioned.");
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            char str[200];
            toString(getEstateOnPos(&res, i), str);
            printf("%s\n", str);
        }
    }
}
void filterByPriceUi(UI* ui)
{
    double price;
    int CMD;
    printf("\nPlease input the price : ");
    scanf("%lf", &price);
    printf("Press '1' for Estates with price larger.\n");
    printf("Press '2' for Estates with price smaller.\n");
    printf("Choose : ");
    CMD = readIntegerNumber();
    printf("\n");
    EstateRepo res = filterByPrice(ui->ctrl, price, CMD);
    int length = getLength(&res);
    if (length == 0)
    {
        printf("There are no Estates over or lower the price you mentioned.\n");
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            char str[200];
            toString(getEstateOnPos(&res, i), str);
            printf("%s\n", str);
        }
    }
}


void startUI(UI* ui)
{
    while (1)
    {
        printMenu();
        printf("Enter command : ");
        int command = readIntegerNumber();
        while (validCommand(command) == 0)
        {
            printf("Please input a valid command!\n");
            printf("Enter command : ");
            command = readIntegerNumber();
        }
        if (command == 0)
        {
            printf("\nGoodbye!😀👋🏼\n");
            break;
        }
        else if (command == 1)
        {
            int res = addEstateUi(ui);
            if (res == 1)
                printf("Estate successfully added.\n");
            else
                printf("Error! Estate could not be added, as there is another estate with the same address combination!\n");
        }
        else if (command == 2)
        {
            listAllEstates(ui);
        }
        else if (command == 5)
        {
            listEstatesWithCombinations(ui);
        }
        else if (command == 3)
        {
            int res = deleteEstateUi(ui);
            if (res == 1)
                printf("Estate deleted !\n");
            
            else
                printf("Error! Estate could not be deleted\n");
        }
        else if (command == 4)
        {
            int res = updateEstateUi(ui);
            if (res == 1)
                printf("Estate updated !\n");
            else
                printf("Error! Estate address doesn't exist");
        }
        else if (command == 6)
        {
            filterByTypeSurfaceUi(ui);
        }
        else if (command == 7)
        {
            filterByPriceUi(ui);
        }
    }
}

