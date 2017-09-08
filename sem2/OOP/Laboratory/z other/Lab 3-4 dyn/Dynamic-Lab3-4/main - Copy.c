#include<Windows.h>
#include "UI.h"
#include<crtdbg.h>

int main()
{
	EstateRepository* repo = create_allocate_repository();
	EstateController* ctrl = create_allocate_controller(repo);
	UI* ui = create_allocate_UI(ctrl);
	run(ui);
	destroy(ui);
	_CrtDumpMemoryLeaks();
	system("pause");
}