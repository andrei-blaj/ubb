#pragma once
#include "PlanetRepository.h"
#include "OperationsStack.h"

typedef struct
{
	PlanetRepo* repo;
	OperationsStack* undoStack;
} Controller;

Controller* createController(PlanetRepo* r, OperationsStack* undoS);
void destroyController(Controller* c);

/// <summary>
/// Adds a planet to the repository of planets.
/// </summary>
/// <param name="c">Pointer to theController.</param>
/// <param name = "symbols">A string, the symbol combination for the planet to be added.</param>
/// <param name = "name">A string, the name of the planet.</param>
/// <param name = "solarSystem">A string, the solar system the planet belongs to.</param>
/// <param name = "distanceToEarth">Double, the distance from the planet to Earth, in thousands of light years.</param>
/// <returns>1 - if the planet was sucessfully added; 0 - if the planet could not be added, as another planet with the same symbol already exists.</returns>
int addPlanetCtrl(Controller* c, char* symbols, char* name, char* solarSystem, double distanceToEarth);

PlanetRepo* getRepo(Controller* c);

/// <summary>
/// Searches for the planets containing a given symbol combination.
/// </summary>
/// <param name="c">Pointer to theController.</param>
/// <param name = "symbols">A string, the searched symbol combination; "null" - for all the planets.</param>
/// <returns>A pointer to a repository of planets, that have the given symbol combination.</returns>
PlanetRepo* filterBySymbolCombination(Controller* c, char symbols[]);

/// <summary>
/// Undoes the last performed operation.
/// </summary>
/// <param name="c">Pointer to theController.</param>
/// <returns>1, if the undo operation could be done, 0 otherwise.</returns>
int undo(Controller* c);
