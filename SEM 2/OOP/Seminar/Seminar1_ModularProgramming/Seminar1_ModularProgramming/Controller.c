#include "Controller.h"
#include <string.h>

Controller createController(PlanetRepo* r)
{
	Controller c;
	c.repo = r;

	return c;
}

int addPlanet(Controller* c, char symbols[], char name[], char solarSystem[], double distanceToEarth)
{
	Planet p = createPlanet(symbols, name, solarSystem, distanceToEarth);
	
	int res = add(c->repo, p);
	return res;
}

PlanetRepo* getRepo(Controller* c)
{
	return c->repo;
}

PlanetRepo filterBySymbolCombination(Controller* c, char symbols[])
{
	PlanetRepo res = createRepo();
	if (strcmp(symbols, "null") == 0)
		return *(c->repo);

	for (int i = 0; i < getLength(c->repo); i++)
	{
		Planet p = getPlanetOnPos(c->repo, i);
		if (strstr(getSymbols(&p), symbols) != NULL)
			add(&res, p);
	}

	return res;
}