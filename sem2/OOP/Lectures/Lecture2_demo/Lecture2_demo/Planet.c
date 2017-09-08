#include "Planet.h"

Planet createPlanet(char symbols[], char name[], char solarSystem[], double distanceToEarth)
{
	Planet p;
	strcpy(p.symbols, symbols);
	strcpy(p.name, name);
	strcpy(p.solarSystem, solarSystem);
	p.distanceToEarth = distanceToEarth;

	return p;
}