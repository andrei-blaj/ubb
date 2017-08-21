#include<Windows.h>
#include "UI.h"
#include<crtdbg.h>

int main()
{
	EstateRepository* repo = create_allocate_repository();
	OperationStack* undo_stack = create_operation_stack();
	OperationStack* redo_stack = create_operation_stack();
	EstateController* ctrl = create_allocate_controller(repo,undo_stack, redo_stack);
	UI* ui = create_allocate_UI(ctrl);
	run(ui);
	destroy(ui);
	_CrtDumpMemoryLeaks();
	system("pause");
}