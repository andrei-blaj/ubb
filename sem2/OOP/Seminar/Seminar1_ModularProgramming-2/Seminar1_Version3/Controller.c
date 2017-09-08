#include "Controller.h"
#include <stdlib.h>
#include <string.h>

Controller* createController(PlanetRepo* r, OperationsStack* undoS)
{
	Controller* c = (Controller*)malloc(sizeof(Controller));
	c->repo = r;
	c->undoStack = undoS;

	return c;
}

void destroyController(Controller * c)
{
	// first destroy the repository inside
	destroyRepo(c->repo);

	// then the operation stack
	destroyStack(c->undoStack);

	// then free the memory
	free(c);
}

int addPlanetCtrl(Controller* c, char* symbols, char* name, char* solarSystem, double distanceToEarth)
{
	Planet* p = createPlanet(symbols, name, solarSystem, distanceToEarth);
	
	int res = addPlanet(c->repo, p);

	if (res == 1) // if the planet was successfully added - register the operation
	{
		Operation* o = createOperation(p, "add");
		push(c->undoStack, o);
		// once added, the operation can be destroyed (a copy of the operation was added)
		destroyOperation(o);
	}

	// destroy the planet that was just created, as the repository stored a copy
	destroyPlanet(p);

	return res;
}

PlanetRepo* getRepo(Controller* c)
{
	return c->repo;
}

PlanetRepo* filterBySymbolCombination(Controller* c, char symbols[])
{
	PlanetRepo* res = createRepo();
	if (strcmp(symbols, "null") == 0)
	{
		// what should we do here?
	}

	for (int i = 0; i < getRepoLength(c->repo); i++)
	{
		Planet* p = getPlanetOnPos(c->repo, i);
		if (strstr(getSymbols(p), symbols) != NULL)
		{
			addPlanet(res, p);
		}
	}

	return res;
}

int undo(Controller* c)
{
	if (isEmpty(c->undoStack))
	{
		return 0;
	}

	Operation* operation = pop(c->undoStack);

	if (strcmp(getOperationType(operation), "add") == 0)
	{
		Planet* planet = getPlanet(operation);
		char symbol[8];
		strcpy(symbol, getSymbols(planet));
		deletePlanet(c->repo, symbol);
	}
	else if (strcmp(getOperationType(operation), "remove") == 0)
	{
		// TO DO!!!
	}

	// the operation must be destroyed
	destroyOperation(operation);

	return 1;

}
