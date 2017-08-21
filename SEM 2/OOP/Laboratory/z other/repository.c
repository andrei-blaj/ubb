#include <string.h>
#include "repository.h"
#include <stddef.h>
#include <assert.h>
#include "Log_repo.h"

EstateRepo createRepo()
{
    EstateRepo v;
    v.length = 0;
    
    return v;
}
int find(EstateRepo* v, char address[])
{
    //Estate* x = NULL;
    
    for (int i = 0; i < v->length; i++)
    {
        if (strcmp(v->estate[i].address, address) == 0)
            return i;
    }
    return -1;
}

int add(EstateRepo* v, Estate xs)
{
    // first search for a estate with the same address as the one that is to be added and do not add it if it already exists
    if (find(v, x.address) != -1)
        return 0;
    
    v->estate[v->length] = x;
    v->length++;
    
    
    
    return 1;
}
int delete(EstateRepo* v, char address[30+1])
{
    //first search for a estate with the same address as the one that is to be deleted and do not delete it if it doesn't exist
    int pos = find(v, address);
    if (pos == -1)
        return 0;
    else
    {
        for (int i = pos; i < v-> length; i++)
        {
            v->estate[i]=v->estate[i+1];
        }
    }
    v->length--;
    return 1;
}
int update(EstateRepo* v, Estate x)
{
    //first search for a estate with the same address as the one that is to be updated and do not update it if it doesn't exist
    int pos = find(v, x.address);
    if (pos == -1)
        return 0;
    else
    {
        v->estate[pos] = x;
    }
    return 1;
}


int getLength(EstateRepo* v)
{
    return v->length;
}

Estate getEstateOnPos(EstateRepo* v, int pos)
{
    if (pos < 0 || pos >= v->length)
        return createEstate("", "", -1, -1);
    return v->estate[pos];
}


// Tests
void initEstateRepoForTests(EstateRepo* v)
{
    Estate x = createEstate("house", "calea turzii ", 800,300000 );
    add(v, x);
}

void testAdd()
{
    Estate x = createEstate("penthouse", "dorobanti", 200, 98000);
    
    EstateRepo v = createRepo();
    initEstateRepoForTests(&v);
    assert(getLength(&v) == 1);
    
    assert(add(&v, x) == 1);
    assert(getLength(&v) == 2);
    
    // now try to add the same estate again -> add must return 0
    assert(add(&v, x) == 0);
}

void testEstateRepo()
{
    testAdd();
}
