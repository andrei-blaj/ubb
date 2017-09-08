#include "Controller.h"


EstateController* create_allocate_controller(EstateRepository* repo, OperationStack* undo_stack, OperationStack* redo_stack )
{
	EstateController* ctrl = (EstateController*)malloc(sizeof(EstateController));
	//ctrl->repo = (EstateRepository*)malloc(sizeof(EstateRepository)); 
	ctrl->repo = repo;
	ctrl->undo_stack = undo_stack;
	ctrl->redo_stack = redo_stack;

	return ctrl;



}

EstateController* destroy_controller(EstateController* ctrl)
{
	destroy_repository(ctrl->repo);
	free(ctrl);
}

int add_controller(EstateController* ctrl, char* type, char* address, double surface, double price)
{
	int result;
	Estate* estate = create_estate(type, address, surface, price);
	result = add_repository(ctrl->repo, estate);
	if (result == 1) {
		Operation* op = create_operation(m, "add");
		push(ctrl->undo_stack, op);
		destroy_operation(op);
		destroy_operation_stack(ctrl->redo_stack);
		ctrl->redo_stack = create_operation_stack();
	}
	return result;

}

EstateRepository * get_repo(EstateController * ctrl)
{
	return ctrl->repo;
}

int delete_controller(EstateController * ctrl, char * address)
{
	int result = delete_repository(ctrl->repo, address);
	if (result == 1) {
		Operation* op = create_operation(m, "del");
		push(ctrl->undo_stack, op);
		destroy_operation(op);
		destroy_operation_stack(ctrl->redo_stack);
		ctrl->redo_stack = create_operation_stack();
	}
	return result;
	
}

int update_controller(EstateController * ctrl, char * address, char * new_type, double new_surface, double new_price)
{
	Estate* new_estate = create_estate(new_type, address, new_surface, new_price);
	int result = update_repository(ctrl->repo, new_estate);
	if (result == 1) {
		Operation* op = create_operation(m, "update");
		push(ctrl->undo_stack, op);
		destroy_operation(op);
		destroy_operation_stack(ctrl->redo_stack);
		ctrl->redo_stack = create_operation_stack();
	}
	return result;
}

EstateRepository * filter_by_keyword(EstateController * ctrl, char key[])
{
	EstateRepository* repo = create_allocate_repository();
	int i;
	for (i = 0; i < ctrl->repo->estates->length; i++)
		if (strstr(get_address(ctrl->repo->estates->elems[i]), key) != NULL)
			add_repository(repo, ctrl->repo->estates->elems[i]);

	return repo;
}

EstateRepository* sort_repository(EstateController* ctrl, EstateRepository* repository)
{
	int i, j;
	Estate* aux;
	for (i = 0; i < repository->estates->length - 1; i++)
	{
		for (j = i + 1; j < repository->estates->length; j++)
		{
			if (repository->estates->elems[i] > repository->estates->elems[j])
			{
				aux = repository->estates->elems[j];
				repository->estates->elems[j] = repository->estates->elems[i];
				repository->estates->elems[i] = aux;
			}
		}
	}
	return repository;
}

EstateRepository* sort_repository_l(EstateController* ctrl, EstateRepository* repository)
{
	int i, j;
	Estate* aux;
	for (i = 0; i < repository->estates->length - 1; i++)
	{
		for (j = i + 1; j < repository->estates->length; j++)
		{
			if (get_price(repository->estates->elems[i]) > get_price(repository->estates->elems[j]))
			{
				aux = repository->estates->elems[j];
				repository->estates->elems[j] = repository->estates->elems[i];
				repository->estates->elems[i] = aux;
			}
		}
	}
	return repository;
}

EstateRepository * filter_by_type(EstateController * ctrl, char * key)
{
	EstateRepository* repo = create_allocate_repository();
	int i;
	for (i = 0; i < ctrl->repo->estates->length; i++)
		if (strstr(get_type(ctrl->repo->estates->elems[i]), key) != NULL)
			add_repository(repo, ctrl->repo->estates->elems[i]);


	return repo;
}

EstateRepository* filter_by_surface(EstateController* ctrl, double min_surface, EstateRepository* repo)
{
	EstateRepository* new_repo = create_allocate_repository();
	int i;
	for (i = 0; i < repo->estates->length; i++)
	{
		if (min_surface <= get_surface(repo->estates->elems[i]))
			add_repository(new_repo, repo->estates->elems[i]);
	}
		return new_repo;
}

EstateRepository * filter_by_surface_l(EstateController * ctrl, double surface, EstateRepository * repo)
{
	{
		EstateRepository* new_repo = create_allocate_repository();
		int i;
		for (i = 0; i < repo->estates->length; i++)
		{
			if (surface == get_surface(repo->estates->elems[i]))
				add_repository(new_repo, repo->estates->elems[i]);
		}
		return new_repo;
	}
}
