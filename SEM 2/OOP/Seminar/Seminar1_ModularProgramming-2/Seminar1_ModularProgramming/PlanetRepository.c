#include "PlanetRepository.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

PlanetRepo createRepo()
{
	PlanetRepo v;
	v.length = 0;

	return v;
}

int find(PlanetRepo* v, char symbols[])
{
	Planet* p = NULL;

	for (int i = 0; i < v->length; i++)
	{
		if (strcmp(v->planets[i].symbols, symbols) == 0)
			return i;
	}
	return -1;
}

int add(PlanetRepo* v, Planet p)
{
	// first search for a planet with the same symbol as the one that is to be added and do not add it if it already exists
	if (find(v, p.symbols) != -1)
		return 0;

	v->planets[v->length] = p;
	v->length++;

	return 1;
}

int getLength(PlanetRepo* v)
{
	return v->length;
}

Planet getPlanetOnPos(PlanetRepo* v, int pos)
{
	if (pos < 0 || pos >= v->length)
		return createPlanet("", "", "", -1);
	return v->planets[pos];
}


// Tests
void initPlanetRepoForTests(PlanetRepo* v)
{
	Planet p = createPlanet("V^E$9L@", "Abydos", "Sol", 583);
	add(v, p);
}

void testAdd()
{
	Planet p = createPlanet("A&V$9+Q", "Cimmeria", "Asgard", 1058);

	PlanetRepo v = createRepo();
	initPlanetRepoForTests(&v);
	assert(getLength(&v) == 1);

	assert(add(&v, p) == 1);
	assert(getLength(&v) == 2);

	// now try to add the same planet again -> add must return 0
	assert(add(&v, p) == 0);
}

void testsPlanetRepo()
{
	testAdd();
}