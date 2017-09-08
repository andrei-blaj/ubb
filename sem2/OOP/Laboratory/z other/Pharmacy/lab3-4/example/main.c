#include <stdio.h>
#include "Planet.h"

int main()
{
	Planet p = createPlanet("SSSSSSS", "Earth", "Sol", 0);

	printf("Distance to Earth is: %.2lf", getDistanceToEarth(p));
	//system("pause");
	return 0;
}