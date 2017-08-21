#pragma once
#include "Planet.h"

typedef struct
{
	Planet planets[100];
	int length;
} PlanetRepo;

/// <summary>
/// Creates a PlanetRepo.
/// </summary>
PlanetRepo createRepo();

/// <summary>
/// Finds the planet with the given symbols.
/// </summary>
/// <param name="v">Pointer to the PlanetRepo.</param>
/// <param name = "symbols">A string, the symbol combination to search for.</param>
/// <returns>pos - the position on which the planet with the given symbol is in the PlanetRepo; -1 - if the planet does not exist.</returns>
int find(PlanetRepo* v, char symbols[]);

/*
	Adds a planet to the repository of planets.
	Input:	- v - pointer to the PlanetRepo
			- p - planet
	Output: 1 - if the planet was sucessfully added
			0 - if the planet could not be added, as another planet with the same symbol already exists in the PlanetRepo.
*/
int add(PlanetRepo* v, Planet p);

int getLength(PlanetRepo* v);


/*
	Returns the planet on the given position in the planet vector.
	Input:	v - the planet repository;
			pos - integer, the position;
	Output: the planet on the given potision, or an "empty" planet.
*/
Planet getPlanetOnPos(PlanetRepo* v, int pos);

void testsPlanetRepo();