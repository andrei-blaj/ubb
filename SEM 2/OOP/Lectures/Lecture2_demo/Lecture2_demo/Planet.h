#pragma once

typedef struct
{
	char symbols[8];
	char name[50];
	char solarSystem[50];
	double distanceToEarth;
} Planet;

Planet createPlanet(char symbols[], char name[], char solarSystem[], double distanceToEarth);
