#pragma once

typedef struct
{
	char* symbols;
	char* name;
	char* solarSystem;
	double distanceToEarth;
} Planet;

Planet* createPlanet(char* symbols, char* name, char* solarSystem, double distanceToEarth);
void destroyPlanet(Planet* p); // the memory is freed

char* getSymbols(Planet* p);
char* getName(Planet* p);
char* getSolarSystem(Planet* p);
double getDistanceToEarth(Planet* p);

void toString(Planet* p, char str[]);
