#pragma once
#include "repository.h"
#include "OperationsStack.h"

typedef struct ctrl_s
{
	MedRepo* repo;
	OperationsStack* undoStack;
	OperationsStack* redoStack;
}Controller;

Controller* createController(MedRepo* r);
void destroyController(Controller* c);

int addMedicine(Controller* c, char *name, float concentration, int quantity, float price);

int deleteMedicine(Controller* c, char* name, float concentration);

int updateMedicine(Controller* c, char* name, int quantity, float concentration, float price);

MedRepo* getRepo(Controller* c);

MedRepo* filter(Controller* c, char string[],int way, int record);

void sortRepoByName(MedRepo* res, int aORd);

void sortRepoByPrice(MedRepo* res, int aORd);

void sortRepoByConcentration(MedRepo *res, int aORd);

MedRepo* filterByQuantity(Controller* c, int way, int q);

int undo(Controller* c);
int redo(Controller* c);
