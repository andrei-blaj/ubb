#include "Controller.h"
#include <stdlib.h>
#include <string.h>

Controller* createController(PlanetRepo* r)
{
	Controller* c = (Controller*)malloc(sizeof(Controller));
	c->repo = r;

	return c;
}

void destroyController(Controller * c)
{
	// first destroy the repository inside
	destroyRepo(c->repo);
	// then free the memory
	free(c);
}

int addPlanet(Controller* c, char* symbols, char* name, char* solarSystem, double distanceToEarth)
{
	Planet* p = createPlanet(symbols, name, solarSystem, distanceToEarth);
	
	int res = add(c->repo, p);
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

	for (int i = 0; i < getLength(c->repo); i++)
	{
		Planet* p = getPlanetOnPos(c->repo, i);
		if (strstr(getSymbols(p), symbols) != NULL)
		{
			Planet* newPlanet = createPlanet(p->symbols, p->name, p->solarSystem, p->distanceToEarth);
			add(res, newPlanet);
		}
	}

	return res;
}