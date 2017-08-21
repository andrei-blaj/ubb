#include "UI.h"
#include <crtdbg.h>

int main()
{
	testsDynamicArray();
	testsPlanetRepo();
	testsStack();

	PlanetRepo* repo = createRepo();
	OperationsStack* operationsStack = createStack();
	Controller* ctrl = createController(repo, operationsStack);
	
	addPlanetCtrl(ctrl, "UV$O*~1", "Gallifrey", "Kasterborous", 250000);
	addPlanetCtrl(ctrl, "V^E$9L@", "Abydos", "Sol", 583);
	addPlanetCtrl(ctrl, "A&V$9+Q", "Cimmeria", "Asgard", 1058);
	addPlanetCtrl(ctrl, "SSSSSSS", "Earth", "Sol", 0);
	
	UI* ui = createUI(ctrl);

	startUI(ui);

	destroyUI(ui);

	_CrtDumpMemoryLeaks();

	return 0;
}