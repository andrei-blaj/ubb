#pragma once
#include "domain.h"
#include "dynamicArray.h"

typedef struct repo_s
{
	dynamicArray* meds;
}MedRepo;

MedRepo* createRepo();

int getLength(MedRepo* v);

medicine* get(MedRepo *v, int i);

void set(MedRepo *v, int i, medicine* m);

medicine* find_pos(MedRepo* v, char* name, float concentration);

void destroyRepo(MedRepo* v);

medicine* find(MedRepo* v, char* name,float concentration);

void add_quantity(MedRepo* v, medicine* m);

medicine* add(MedRepo* v, medicine* m);

void update(MedRepo* v, medicine* new, medicine* old);

void delete(MedRepo* v, char* name, float concentration);



medicine* getMedicineAtX(MedRepo* v, int x);

int cmpfctPriceAscendent(medicine* i, medicine* j);
int cmpfctPriceDescending(medicine* i, medicine* j);
int cmpfctNameAscending(medicine* i, medicine* j);
int cmpfctNameDescending(medicine* i, medicine* j);
int cmpfctConcentrationDescending(medicine *i, medicine *j);
int cmpfctConcentrationAscending(medicine *i, medicine *j);
int cmpfctQuantityAscending(medicine* i, medicine *j);
int cmpfctQuantityDescending(medicine* i, medicine* j);
void sort(MedRepo* v, int(*f)(medicine*, medicine*));

void sortMedicine(MedRepo* v, int(*f)(medicine*, medicine*));
