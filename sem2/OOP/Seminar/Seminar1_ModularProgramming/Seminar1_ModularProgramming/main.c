#include "PlanetRepository.h"
#include "UI.h"
#include <crtdbg.h>

int main()
{
	testsPlanetRepo();

	PlanetRepo repo = createRepo();
	Controller ctrl = createController(&repo);
	
	addPlanet(&ctrl, "UV$O*~1", "Gallifrey", "Kasterborous", 250000);
	addPlanet(&ctrl, "V^E$9L@", "Abydos", "Sol", 583);
	addPlanet(&ctrl, "A&V$9+Q", "Cimmeria", "Asgard", 1058);
	addPlanet(&ctrl, "SSSSSSS", "Earth", "Sol", 0);
	
	UI ui = createUI(&ctrl);

	startUI(&ui);

	_CrtDumpMemoryLeaks();

	return 0;
}