#pragma once
#include "Repository.h"
#include "OperationsStack.h"

typedef struct {
    
    EstateRepository* repo;
    OperationStack* undo_stack;
    OperationStack* redo_stack;
    
}EstateController;

EstateController* create_allocate_controller(EstateRepository* repo, OperationStack* undo_stack, OperationStack* redo_stack);

void destroy_controller(EstateController* ctrl);

int add_controller(EstateController* ctrl, char* type, char* address, double surface, double price);

EstateRepository* get_repo(EstateController* ctrl);

int delete_controller(EstateController* ctrl, char* address);
int update_controller(EstateController* ctrl, char* address, char* new_type, double new_surface, double new_price);
EstateRepository* filter_by_keyword(EstateController* ctrl, char key[]);
EstateRepository* sort_repository(EstateController* ctrl, EstateRepository* repository);

EstateRepository* filter_by_type(EstateController* ctrl, char* type);

EstateRepository* filter_by_surface(EstateController* ctrl, double min_surface, EstateRepository* repo);

EstateRepository* filter_by_surface_l(EstateController* ctrl, double surface, EstateRepository* repo);

int undo(EstateController* ctrl);
// Undo the last operation. Return 1 if successful, 0 otherwise
int redo(EstateController* ctrl);
// Redo the last undo. Return 1 if successful, 0 otherwise
