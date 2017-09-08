#include "repository.h"
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

/*
 creates a repository object, allocating memory and initializing the repo length
 input:	-
 output:	v - a repository object
 */
MedRepo* createRepo()
{
    MedRepo* v = (MedRepo*)malloc(sizeof(MedRepo));
    v->meds = create_da(CAPACITY);
    
    return v;
}

/*
 destroy a repository object, by destroying the medicines and
 deallocating  memory occupied by the repository object until now.
 */
void destroyRepo(MedRepo* v)
{
    int i;
    for (i = 0; i < getLength(v); i++)
    {
        medicine* m = getMedicineAtX(v, i);
        destroyMedicine(m);
    }
    free(v);
}

/*
 finds a medicine in the repository by its unique keys(name and concentration)
 input:	v - a repository object
 name and concentration - the unique keys of a medicine
 output:	the medicine object with the unique keys, if it was found in the repository
 pointer NULL, if it was not found in the repository any medicine with the given unique keys
 */
medicine* find(MedRepo* v, char* name,float concentration)
{
    int i;
    for (i = 0; i < getLength(v); i++)
    {
        if (strcmp(name, getName(getMedicineAtX(v,i))) == 0 && concentration == getConcentration(getMedicineAtX(v, i)))
            return getMedicineAtX(v,i);
    }
    return NULL;
}
medicine* find_pos(MedRepo* v, char* name, float concentration)
{
    int i;
    for (i = 0; i < getLength(v); i++)
    {
        if (strcmp(name, getName(getMedicineAtX(v, i))) == 0 && concentration == getConcentration(getMedicineAtX(v, i)))
            return i;
    }
    return -1;
    
}

/*
 increases the quantity of a given medicine.
 */
void add_quantity(MedRepo* v, medicine* m)
{
    int i;
    for (i = 0; i < getLength(v); i++)
    {
        if (strcmp(m->name, getName(getMedicineAtX(v, i))) == 0 && m->concentration == getConcentration(getMedicineAtX(v, i)));
        {
            getMedicineAtX(v,i)->quantity += getQuantity(m);
        }
    }
}

/*
 recives a medicine from the contoller and adds it to the repository
 input: the repository structure, and a medicine
 output: 1 - the medicine was not in the repositry => it was added successfully
 0 - if the medicine was already in the repository => the quantity was increased
 */
medicine* add(MedRepo* v, medicine* m)
{
    if (v == NULL)
        return 0;
    int i = find_pos(v, getName(m), getConcentration(m));
    if (i != -1)
    {
        medicine* old = createMedicine(getName(getMedicineAtX(v, i)), getQuantity(getMedicineAtX(v, i)), getConcentration(getMedicineAtX(v, i)), getPrice(getMedicineAtX(v, i)));
        medicine* new = createMedicine(getName(m), getQuantity(m) + getQuantity(getMedicineAtX(v, i)), getConcentration(m), getPrice(getMedicineAtX(v, i)));
        update(v, new, old);
        //destroy(new);
        //add_quantity(v, m);
        return old;
    }
    add_da(v->meds, m);
    return NULL;
}

/*
 recives the data from the controller, deletes the medicine with the given name and concentration(unique keys)
 input:	v - a repository object
 name and concentration - the unique keys of a medicine
 output:	-
 */
void delete(MedRepo* v, char* name, float concentration)
{
    if (v == NULL)
        return;
    
    int i = find_pos(v, name, concentration);
    for (i = 0; i < getLength(v); i++)
    {
        if (strcmp(name, getName(getMedicineAtX(v,i))) == 0 && concentration == getConcentration(getMedicineAtX(v,i)))
            break;
    }
    //medicine* m = getMedicineAtX(v, i);
    //destroyMedicine(m);
    delete_da(v->meds, i);
    
    
}

/*
 recives the data from the controller and updates the medicine
 input: v - a repository object
 new - the medicine object meant to be updated
 output: 0 - the medicine was not in the repositry => error, cannot update an
 object which is not in the repository.
 1 - if the medicine was already in the repository => the object was updated successfully.
 */
void update(MedRepo* v, medicine* new, medicine* old)
{
    medicine* m = find(v, getName(new), getConcentration(new));
    if (v == NULL)
        return;
    m->quantity = new->quantity;
    m->price = new->price;
}

/*
 returns the repository length
 input:	r - a repository object
 output:	the length of the repository object
 */
int getLength(MedRepo* v)
{
    if (v == NULL)
        return;
    return getLength_da(v->meds);
}


medicine* get(MedRepo* v,int i)
{
    if (v == NULL)
        return NULL;
    int j = i;
    return get_element(v->meds, j);
}
void set(MedRepo *v, int i,medicine* m)
{
    if (v == NULL)
        return;
    //set_element(v->meds, i, m);
    v->meds->elements[i] = m;
}
/*
 returns the medicine at the position x in the repository
 input:	r - a repository object
 x - integer, the position
 output:	the medicine that is on the position x in the repository
 */
medicine* getMedicineAtX(MedRepo* v, int x)
{
    if (v == NULL)
        return NULL;
    if (x < 0 || x >= getLength(v))
        return NULL;
    return get(v,x);
}

int cmpfctPriceAscendent(medicine* i, medicine* j)
{
    return i->price > j->price;
}
int cmpfctPriceDescending(medicine* i, medicine* j)
{
    return i->price < j->price;
}
int cmpfctNameAscending(medicine* i, medicine* j)
{
    return strcmp(i->name, j->name) > 0;
}
int cmpfctNameDescending(medicine* i, medicine* j)
{
    return strcmp(i->name, j->name) < 0;
}
int cmpfctConcentrationAscending(medicine *i, medicine *j)
{
    return i->concentration > j->concentration;
}
int cmpfctConcentrationDescending(medicine *i, medicine *j)
{
    return i->concentration < j->concentration;
}
int cmpfctQuantityAscending(medicine* i, medicine *j)
{
    return i->quantity > j->quantity;
}
int cmpfctQuantityDescending(medicine* i, medicine* j)
{
    return i->quantity < j->quantity;
}
void sort(MedRepo* v, int(*f)(medicine*, medicine*))
{
    //qsort(get(vi), v->length, sizeof(medicine*), f);
}

void sortMedicine(MedRepo* v, int(*f)(medicine*, medicine*))
{
    int i, j;
    for (i = 0; i < getLength(v)-1; i++)
        for (j = i + 1; j < getLength(v); j++)
            if (f(getMedicineAtX(v,i), getMedicineAtX(v,j)))
            {
                medicine* aux = getMedicineAtX(v,i);
                set(v, i, getMedicineAtX(v, j));
                //v->meds->elements[i] = v->meds->elements[j];
                set(v, j, aux);
                //v->meds->elements[i] = aux;
            }
}

void initMedRepoForTests(MedRepo* v)
{
    medicine* m = createMedicine("nurofen", 5, 80, 15);
    add(v, m);
}

void testAdd()
{
    MedRepo* v = createRepo();
    initMedRepoForTests(v);
    assert(getLength(v) == 1);
    
    medicine* m = createMedicine("bixtonim", 10, 75, 24);
    assert(add(v,m) == 1);
    assert(getLength(v) == 2);
    // take the medicine from the repo and then do some checks on it.
    m = find(v, "bixtonim", 75);
    // check if the medicine was added successfully.
    assert(m->quantity == 10);
    assert(m->price == 24);
    assert(m->concentration == 75);
    assert(strcmp(m->name, "bixtonim") == 0);
    
    assert(add(v, m) == 0);
    destroyMedicine(m);
    destroyRepo(v);
}


void testUpdate()
{
    MedRepo* v = createRepo();
    initMedRepoForTests(v);
    assert(getLength(v) == 1);
    
    //updates a medicine
    medicine* newMed = createMedicine("nurofen", 10, 80, 20);
    //assert(update(v, newMed,NULL) == 1); // returns 1 which means the update was done successfully.
    // take the medicine from the repo and then do some checks on it.
    medicine* m = find(v, "nurofen", 80);
    // check if the medicine was updated(its quantity and its price only)
    assert(m->quantity == 10);
    assert(m->price == 20);
    // no change on the concentration and name
    assert(m->concentration == 80);
    assert(strcmp(m->name,"nurofen") == 0);
    
    //destroyMedicine(m);
    //destroyMedicine(newMed);
    
    //update a medicine which is not in the list. it shouldn't do any change on the repo.
    newMed = createMedicine("nothing", 10, 80, 20);
    //even if newMed has the same concentration as a medince in the repo it shouldn't match
    //any medicine because its unique keys are the name and the concentration
    //assert(update(v, newMed,NULL) == 0);
    
    //destroyMedicine(newMed);
    
    //update a medicine which is not in the list. it shouldn't do any change on the repo.
    newMed = createMedicine("nurofen", 10, 70, 20);
    //even if the name matches a medicine in the repo, the concentration is diffrent it shouldn't match
    //any medicine because its unique keys are the name and the concentration
    //assert(update(v, newMed,NULL) == 0);
    // take the medicine from the repo and then do some checks on it.
    m = find(v, "nurofen", 80);
    // check if the medicine was not modified at all
    assert(m->quantity == 10);
    assert(m->price == 20);
    assert(m->concentration == 80);
    assert(strcmp(m->name, "nurofen") == 0);
    
    destroyMedicine(m);
    destroyMedicine(newMed);
    
    destroyRepo(v);
}

void testDelete()
{
    MedRepo* v = createRepo();
    initMedRepoForTests(v);
    assert(getLength(v) == 1);
    
    medicine* m = createMedicine("bixtonim", 10, 75, 24);
    assert(add(v, m) == 1);
    assert(getLength(v) == 2);
    assert(find(v, "bixtonim", 75) != NULL);
    delete(v, "bixtonim", 75);
    assert(find(v, "bixtonim", 75) == NULL);
    assert(getLength(v) == 1);
    
    //destroyMedicine(m);
    destroyRepo(v);
}
void testsMedRepo()
{
    //testAdd();
    //testUpdate();
    //testDelete();
}
