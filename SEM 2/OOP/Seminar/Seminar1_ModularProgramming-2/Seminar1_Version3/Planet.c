#include "Planet.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Planet* createPlanet(char* symbols, char* name, char* solarSystem, double distanceToEarth)
{
	Planet* p = (Planet*)malloc(sizeof(Planet));
	p->symbols = (char*)malloc(strlen(symbols) + 1);
	strcpy(p->symbols, symbols);
	p->name = (char*)malloc(strlen(name) + 1);
	strcpy(p->name, name);
	p->solarSystem = (char*)malloc(strlen(solarSystem) + 1);
	strcpy(p->solarSystem, solarSystem);
	p->distanceToEarth = distanceToEarth;

	return p;
}

void destroyPlanet(Planet* p)
{
	// free the memory which was allocated for the component fields
	free(p->symbols);
	free(p->name);
	free(p->solarSystem);

	// free the memory which was allocated for the planet structure
	free(p);
}

Planet* copyPlanet(Planet* p)
{
	if (p == NULL)
		return NULL;

	Planet* newPlanet = createPlanet(getSymbols(p), getName(p), getSolarSystem(p), getDistanceToEarth(p));
	return newPlanet;
}

char* getSymbols(Planet* p)
{
	return p->symbols;
}

char* getName(Planet* p)
{
	return p->name;
}

char* getSolarSystem(Planet* p)
{
	return p->solarSystem;
}

double getDistanceToEarth(Planet* p)
{
	return p->distanceToEarth;
}

void toString(Planet* p, char str[])
{
	sprintf(str, "Planet %s has symbol combination %s, is in the solar system %s and its distance to Earth is %.2lf.", p->name, p->symbols, p->solarSystem, p->distanceToEarth);
}