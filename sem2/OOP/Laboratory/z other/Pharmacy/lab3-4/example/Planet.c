#include "Planet.h"
#include <string.h>

Planet createPlanet(char chevrons[], char name[], char solarSystem[], double d)
{
	Planet p;
	strcpy(p.chevrons, chevrons);
	strcpy(p.name, name);
	strcpy(p.solarSystem, solarSystem);
	p.distanceToEarth = d;

	return p;
}

double getDistanceToEarth(Planet p)
{
	return p.distanceToEarth;
}