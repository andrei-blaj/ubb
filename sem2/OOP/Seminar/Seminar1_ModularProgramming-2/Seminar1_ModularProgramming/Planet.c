#include "Planet.h"
#include <string.h>
#include <stdio.h>

Planet createPlanet(char symbols[], char name[], char solarSystem[], double distanceToEarth)
{
	Planet p;
	strcpy(p.symbols, symbols);
	strcpy(p.name, name);
	strcpy(p.solarSystem, solarSystem);
	p.distanceToEarth = distanceToEarth;

	return p;
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

void toString(Planet p, char str[])
{
	sprintf(str, "Planet %s has symbol combination %s, is in the solar system %s and its distance to Earth is %.2lf.", p.name, p.symbols, p.solarSystem, p.distanceToEarth);
}