#pragma once

typedef struct
{
	char chevrons[8];
	char name[50];
	char solarSystem[50];
	double distanceToEarth;
} Planet;

Planet createPlanet(char chevrons[], char name[], char solarSystem[], double d);
/**/
double getDistanceToEarth(Planet p);