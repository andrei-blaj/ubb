#include "controller.h"
#include "OperationsStack.h"
#include <string.h>

/*
 creates a controller object, allocating memory and initializing the repo
 input:	r - a repository object
 */
Controller* createController(MedRepo* r, OperationsStack* undoS, OperationsStack* redoS)
{
    Controller* c = (Controller*)malloc(sizeof(Controller));
    c->repo = r;
    c->undoStack = undoS;
    c->redoStack = redoS;
    return c;
}

/*
 destroy a controller object, by destroying the repository and
 deallocating  memory occupied by the controller object until now.
 */
void destroyController(Controller* c)
{
    // first destroy the repository inside
    destroyRepo(c->repo);
    destroyStack(c->undoStack);
    destroyStack(c->redoStack);
    // then free the memory
    free(c);
}
/*
 recives the data from the ui, creates a new medicine object and passes to th repository
 input: the controller structure, containing the repository, and data for a medicine
 (name, concentration, quantity, price)
 output: 1 - the medicine was not in the repositry => it was added successfully
 0 - if the medicine was already in the repository => the quantity was increased
 */

int addMedicine(Controller* c, char *name, float concentration, int quantity, float price)
{
    medicine* m = createMedicine(name, quantity, concentration, price);
    medicine* res = add(c->repo, m);
    if (res == NULL)
    {
        Operation* o = createOperation(m,NULL,"add");
        push(c->undoStack, o);
        return 1;
    }
    else
    {
        Operation* o = createOperation(res,m,"update");
        push(c->undoStack, o);
        return 0;
    }
}
/*
 recives the data from the ui, creats a new medicine object and passes to th repository
 input: the controller structure, containing the repository, and data for a medicine
 (name, concentration, quantity, price).
 output: 1 - the medicine was not in the repositry => error, cannot update an
 object which is not in the repository.
 0 - if the medicine was already in the repository => the object was updated successfully.
 */
int updateMedicine(Controller* c, char* name, int quantity, float concentration, float price)
{
    medicine* m = createMedicine(name, quantity, concentration, price);
    int i = find_pos(c->repo, getName(m), getConcentration(m));
    medicine* old = NULL;
    if (i != -1)
        old = createMedicine(getName(getMedicineAtX(c->repo, i)), getQuantity(getMedicineAtX(c->repo, i)), getConcentration(getMedicineAtX(c->repo, i)), getPrice(getMedicineAtX(c->repo, i)));
    if (old != NULL)
    {
        update(c->repo, m, old);
        if (i == 0)
            return 0;
        Operation* o = createOperation(m, old, "update");
        push(c->undoStack, o);
        return 1;
    }
    else
        return 0;
}

/*
 recives the data from the ui, finds the medicine with the given name and concentration(unique keys)
 input: the controller structure, containing the repository, and data for identifying a medicine
 (name and concentration)
 output: 1 - the medicine was not in the repositry => cannot delete an
 object which is not in the repository.
 0 - if the medicine was already in the repository =>  the object was deleted successfully
 */
int deleteMedicine(Controller* c, char* name, float concentration)
{
    medicine* m = find(c->repo, name, concentration);
    if (m == NULL)
        return 0;
    Operation* o = createOperation(m,NULL,"delete");
    push(c->undoStack, o);
    //destroyOperation(o);
    delete(c->repo, name, concentration);
    return 1;
}

/*
 returns the repository of the controller
 input:	c - a controller object
 output:	r - a repository object
 */
MedRepo* getRepo(Controller* c)
{
    return c->repo;
}

/*
 recives a string from the ui, creates a new repository with the medicines containing the given string.
 input:	c - a controller object
 string - a string that will be be used for searching the medicines contining it as a substring.
 output:	a repository object containing the medicines after filtering them
 or the whole repository if the string was 'null'
 */
MedRepo* filter(Controller* c, char string[], int way, int record)
{
    MedRepo* res = createRepo();
    if (strlen(string) == 0)
    {
        return c->repo;
    }
    
    int i;
    for (i = 0; i < getLength(c->repo); i++)
    {
        medicine* m = getMedicineAtX(c->repo, i);
        if (strstr(getName(m), string) != NULL)
        {
            medicine* newMedicine = createMedicine(m->name, m->quantity, m->concentration, m->price);
            add(res, newMedicine);
        }
    }
    if (record == 1)//1 is for name filter
        sortRepoByName(res, way);
    else
        if (record == 2)//2 is for price filter
            sortRepoByPrice(res, way);
        else
            if (record == 3)
                sortRepoByConcentration(res,way);
            else
                return NULL;
    
    return res;
}

void sortRepoByConcentration(MedRepo *res, int aORd)
{
    if (aORd == 1)
        // 1 is for ascending
        sortMedicine(res, cmpfctConcentrationAscending);
    else
        //2 is for descending
        sortMedicine(res, cmpfctConcentrationDescending);
}

void sortRepoByName(MedRepo* res, int aORd)
{
    if (aORd == 1)
        //1 is for ascending
        sortMedicine(res, cmpfctNameAscending);
    else
        if (aORd == 2)
            //2 is for descending
            sortMedicine(res, cmpfctNameDescending);
}

void sortRepoByPrice(MedRepo* res, int aORd)
{
    if (aORd == 1)
        //1 is for ascending
        sortMedicine(res, cmpfctPriceAscendent);
    else
        if (aORd == 2)
            //2 is for descending
            sortMedicine(res, cmpfctPriceDescending);
}

// filters by quantity ascending or descending depending on the value of way
// all the medicines objects that have the quantity less than q
MedRepo* filterByQuantity(Controller* c, int way, int q)
{
    MedRepo* res = createRepo();
    
    int i;
    for (i = 0; i < getLength(c->repo); i++)
    {
        medicine* m = getMedicineAtX(c->repo, i);
        if (getQuantity(m) < q)
        {
            medicine* newMedicine = createMedicine(m->name, m->quantity, m->concentration, m->price);
            add(res, newMedicine);
        }
    }
    if (getLength(res) == 0)
    {
        return NULL;
    }
    
    if (way == 1)//1 is for ascending
        sortMedicine(res, cmpfctQuantityAscending);
    else
        if (way == 2)//2 is for descending
            sortMedicine(res, cmpfctQuantityDescending);
        else
            return NULL;
    
    return res;
}

int redo(Controller* c)
{
    if (isEmpty(c->redoStack))
        return 0;
    
    Operation* operation = pop(c->redoStack);
    c->undoStack->length++;
    if (strcmp(getOperationType(operation), "add") == 0)
    {
        medicine* m = getMedicine1(operation);
        add(c->repo, m);
    }
    else
        if (strcmp(getOperationType(operation), "delete") == 0)
        {
            medicine* m = getMedicine1(operation);
            delete(c->repo, getName(m), getConcentration(m));
        }
        else
            if (strcmp(getOperationType(operation), "update") == 0)
            {
                medicine* m1 = getMedicine1(operation);
                medicine* m2 = getMedicine2(operation);
                update(c->repo, m1, m2);
            }
    return 1;
}

int undo(Controller* c)
{
    if (isEmpty(c->undoStack))
    {
        return 0;
    }
    
    Operation* operation = pop(c->undoStack);
    push(c->redoStack, operation);
    
    if (strcmp(getOperationType(operation), "add") == 0)
    {
        medicine* m = getMedicine1(operation);
        delete(c->repo, getName(m), getConcentration(m));
    }
    else
        if (strcmp(getOperationType(operation), "delete") == 0)
        {
            medicine* m = getMedicine1(operation);
            add(c->repo,m);
        }
        else
            if (strcmp(getOperationType(operation), "update") == 0)
            {
                medicine* m1 = getMedicine1(operation);
                medicine* m2 = getMedicine2(operation);
                update(c->repo, m2, m1);
            }
    // the operation must be destroyed
    
    return 1;
}
