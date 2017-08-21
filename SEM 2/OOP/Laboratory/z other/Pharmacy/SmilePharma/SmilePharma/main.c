#include "repository.h"
#include "ui.h"
#include <crtdbg.h>


int main()
{
	testsMedRepo();

	MedRepo* repo = createRepo();
	OperationsStack* operationsStack1 = createStack();
	OperationsStack* operationsStack2 = createStack();
	Controller* ctrl = createController(repo, operationsStack1, operationsStack2);

	addMedicine(ctrl, "nurofen", 80, 3, 27.5);
	addMedicine(ctrl, "aspirin", 70, 5, 10.9);
	addMedicine(ctrl, "coldrex", 88.70, 10, 15.4);
	addMedicine(ctrl, "bixtonim", 56.49, 4, 7.6);
	addMedicine(ctrl, "hofigal", 40, 9, 5.6);
	addMedicine(ctrl, "acc", 66, 15, 7.9);
	addMedicine(ctrl, "cavit", 25, 20, 11.7);
	addMedicine(ctrl, "amoxiplus", 55, 10, 25.2);
	addMedicine(ctrl, "nagelsin", 60, 12, 15.2);
	addMedicine(ctrl, "amoxicilin", 13, 20, 10.2);


	UI* ui = createUI(ctrl);

	startUI(ui);

	//destroyUI(ui);

	//_CrtDumpMemoryLeaks();

	return 0;
}
