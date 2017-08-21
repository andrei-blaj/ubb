#include "PlanetRepository.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

PlanetRepo* createRepo()
{
	PlanetRepo* v = (PlanetRepo*)malloc(sizeof(PlanetRepo));
	v->planets = createDynamicArray(CAPACITY);

	return v;
}

void destroyRepo(PlanetRepo* v)
{
	if (v == NULL)
		return;

	// first free the memory allocated for the planets
	for (int i = 0; i < getLength(v->planets); i++)
	{
		Planet* p = get(v->planets, i);
		destroyPlanet(p);
	}

	// then destroy the dynamic array
	destroy(v->planets);
	free(v);
}

int findPosOfPlanet(PlanetRepo * v, char * symbol)
{
	if (v == NULL)
		return -1;

	for (int i = 0; i < getLength(v->planets); i++)
	{
		Planet* p = get(v->planets, i);
		if (strcmp(p->symbols, symbol) == 0)
			return i;
	}
	return -1;
}

Planet* find(PlanetRepo* v, char* symbols)
{
	if (v == NULL)
		return NULL;

	int pos = findPosOfPlanet(v, symbols);
	if (pos == -1)
		return NULL;
	return get(v->planets, pos);
}

int addPlanet(PlanetRepo* v, Planet* p)
{
	if (v == NULL)
		return 0;

	// first search for a planet with the same symbol as the one that is to be added and do not add it if it already exists
	if (find(v, p->symbols) != NULL)
		return 0;

	// a copy of the planet which was passed will be stored, such that the memory for the planet can be deallocated where it was allocated (in Controller) 
	// and the Repository will handle its own memory
	Planet* copy = copyPlanet(p);
	add(v->planets, copy);

	return 1;
}

void deletePlanet(PlanetRepo* v, char* symbol)
{
	if (v == NULL)
		return;

	// find the position of the planet in the repository
	int pos = findPosOfPlanet(v, symbol);
	if (pos == -1)
		return;

	// destroy the planet
	Planet* p = get(v->planets, pos);
	destroyPlanet(p);

	// delete the pointer from the dynamic array
	delete(v->planets, pos);
}

int getRepoLength(PlanetRepo* v)
{
	if (v == NULL)
		return -1;

	return getLength(v->planets);
}

Planet* getPlanetOnPos(PlanetRepo* v, int pos)
{
	if (v == NULL)
		return NULL;

	if (pos < 0 || pos >= getLength(v->planets))
		return NULL;

	return get(v->planets, pos);
}


// Tests
void testAdd()
{
	PlanetRepo* v = createRepo();

	Planet* p1 = createPlanet("V^E$9L@", "Abydos", "Sol", 583);
	addPlanet(v, p1);
	assert(getRepoLength(v) == 1);
	assert(strcmp(getName(getPlanetOnPos(v, 0)), "Abydos") == 0);

	Planet* p2 = createPlanet("A&V$9+Q", "Cimmeria", "Asgard", 1058);
	assert(addPlanet(v, p2) == 1);
	assert(getRepoLength(v) == 2);

	// now try to add the same planet again -> add must return 0
	assert(addPlanet(v, p2) == 0);

	// destroy the test repository
	destroyRepo(v);

	// now the memory allocated for the planets must be freed
	destroyPlanet(p1);
	destroyPlanet(p2);
}

void testsPlanetRepo()
{
	testAdd();
}