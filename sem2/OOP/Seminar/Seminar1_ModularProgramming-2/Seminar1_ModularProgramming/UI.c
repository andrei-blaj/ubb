#include "UI.h"
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
	printf("\n**********************************************************\n");
	printf("1 - add a planet.\n");
	printf("2 - list all planets.\n");
	printf("3 - list planets with a given symbol combination.\n");
	printf("0 - to exit.\n");
	printf("\**********************************************************\n");
}

/*
	Verifies if the given command is valid (is either 1, 2 or 0)
	Input: command - integer
	Output: 1 - if the command is valid
	0 - otherwise
*/
int validCommand(int command)
{
	if (command >= 0 && command <= 3)
		return 1;
	return 0;
}

/*
	Reads an integer number from the keyboard. Asks for number while read errors encoutered.
	Input: the message to be displayed when asking the user for input.
	Returns the number.
*/
int readIntegerNumber(const char* message)
{
	char s[16];
	int res = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0)
	{
		printf(message);
		scanf("%s", s);

		r = sscanf(s, "%d", &res);	// reads data from s and stores them as integer, if possible; returns 1 if successful
		flag = (r == 1);
		if (flag == 0)
			printf("Error reading number!\n");
	}
	return res;
}

int addPlanetUI(UI* ui)
{
	// read the planet's data
	char symbols[8], name[50], solarSystem[50];
	double distanceToEarth;
	
	printf("Please input the symbol combination (must contain 7 symbols): ");
	scanf("%7s", symbols);
	printf("Please input the name: ");
	scanf("%49s", name);
	printf("Please input the solar system: ");
	scanf("%49s", solarSystem);
	printf("Please input the distance to Earth (in thousands of light years): ");
	scanf("%lf", &distanceToEarth);

	return addPlanet(ui->ctrl, symbols, name, solarSystem, distanceToEarth);
}

void listAllPlanets(UI* ui)
{
	PlanetRepo* repo = getRepo(ui->ctrl);
	int length = getLength(repo);

	if (length == 0)
	{
		char* str = "There are no stored planets.";
		printf("%s \n", str);
	}

	for (int i = 0; i < getLength(repo); i++)
	{
		char str[200];
		toString(getPlanetOnPos(repo, i), str);
		printf("%s\n", str);
	}
}

void listPlanetsWithCombination(UI* ui)
{
	char symbols[8];
	printf("Please input the symbol combination (must contain maximum 7 symbols); input 'null' for no symbol combination: ");
	scanf("%7s", symbols);

	PlanetRepo res = filterBySymbolCombination(ui->ctrl, symbols);
	int length = getLength(&res);
	if (length == 0)
	{
		printf("There are no planets with the given symbol combination.");
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			char str[200];
			toString(getPlanetOnPos(&res, i), str);
			printf("%s\n", str);
		}
	}
}

void startUI(UI* ui)
{
	while (1)
	{
		printMenu();
		int command = readIntegerNumber("Input command: ");
		while (validCommand(command) == 0)
		{
			printf("Please input a valid command!\n");
			command = readIntegerNumber("Input command: ");
		}
		if (command == 0)
			break;
		switch (command)
		{
		case 1:
		{
			int res = addPlanetUI(ui);
			if (res == 1)
				printf("Planet successfully added.\n");
			else
				printf("Error! Planet could not be added, as there is another planet with the same symbol combination!\n");
			break;
		}
		case 2:
		{
			listAllPlanets(ui);
			break;
		}
		case 3:
		{
			listPlanetsWithCombination(ui);
			break;
		}
		}
	}
}