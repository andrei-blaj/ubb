#include "PlanetRepository.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

PlanetRepo* createRepo()
{
	PlanetRepo* v = (PlanetRepo*)malloc(sizeof(PlanetRepo));
	v->length = 0;

	return v;
}

void destroyRepo(PlanetRepo* v)
{
	// first destroy all the planets in the repository
	for (int i = 0; i < v->length; i++)
		destroyPlanet(v->planets[i]);
	free(v);
}

Planet* find(PlanetRepo* v, char* symbols)
{
	for (int i = 0; i < v->length; i++)
	{
		if (strcmp(v->planets[i]->symbols, symbols) == 0)
			return v->planets[i];
	}
	return NULL;
}

int add(PlanetRepo* v, Planet* p)
{
	// first search for a planet with the same symbol as the one that is to be added and do not add it if it already exists
	if (find(v, p->symbols) != NULL)
		return 0;

	v->planets[v->length] = p;
	v->length++;

	return 1;
}

int getLength(PlanetRepo* v)
{
	return v->length;
}

Planet* getPlanetOnPos(PlanetRepo* v, int pos)
{
	if (pos < 0 || pos >= v->length)
		return NULL;
	return v->planets[pos];
}


// Tests
void initPlanetRepoForTests(PlanetRepo* v)
{
	Planet* p = createPlanet("V^E$9L@", "Abydos", "Sol", 583);
	add(v, p);
}

void testAdd()
{
	PlanetRepo* v = createRepo();
	initPlanetRepoForTests(v);
	assert(getLength(v) == 1);

	Planet* p = createPlanet("A&V$9+Q", "Cimmeria", "Asgard", 1058);
	assert(add(v, p) == 1);
	assert(getLength(v) == 2);

	// now try to add the same planet again -> add must return 0
	assert(add(v, p) == 0);

	// destroy the test repository
	destroyRepo(v);
}

void testsPlanetRepo()
{
	testAdd();
}