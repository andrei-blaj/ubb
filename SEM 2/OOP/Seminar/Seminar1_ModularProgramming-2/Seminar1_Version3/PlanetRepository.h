#pragma once
#include "Planet.h"
#include "DynamicArray.h"

typedef struct
{
	DynamicArray* planets;
} PlanetRepo;

/// <summary>
/// Creates a PlanetRepo.
/// </summary>
PlanetRepo* createRepo();

/// <summary>
/// Destroys a given planet repository. The memory is freed.
/// </summary>
void destroyRepo(PlanetRepo* v);

/// <summary>
/// Finds the planet with the given symbols.
/// </summary>
/// <param name="v">Pointer to the PlanetRepo.</param>
/// <param name = "symbols">A string, the symbol combination to search for.</param>
/// <returns>The pointer to the planet containing the given symbols, or null, if such a planet does not exist.</returns>
Planet* find(PlanetRepo* v, char* symbol);

/*
	Finds the position of the planet with hte given symbol in the repository.
	Input:  - v - pointer to the PlanetRepo
			- symbol - a string, the symbol combination to search for.
	Output: If a planet with the given symbol exists in the repository, its position is returned.
			-1 - if such a planet does not exist.
*/
int findPosOfPlanet(PlanetRepo* v, char* symbol);

/*
	Adds a planet to the repository of planets.
	Input:	- v - pointer to the PlanetRepo
			- p - planet
	Output: 1 - if the planet was sucessfully added
			0 - if the planet could not be added, as another planet with the same symbol already exists in the PlanetRepo.
*/
int addPlanet(PlanetRepo* v, Planet* p);

/*
	Deletes the planet with the given symbol from the repository.
	Input:  - v - pointer to the PlanetRepo
			- symbol - a string, the symbol combination which identifies the planet to be deleted.
	Output: If a planet with the given symbol exists in the repository, it is deleted.
*/
void deletePlanet(PlanetRepo* v, char* symbol);

int getRepoLength(PlanetRepo* v);


/*
	Returns the planet on the given position in the planet vector.
	Input:	v - the planet repository;
			pos - integer, the position;
	Output: the planet on the given potision, or an "empty" planet.
*/
Planet* getPlanetOnPos(PlanetRepo* v, int pos);

void testsPlanetRepo();