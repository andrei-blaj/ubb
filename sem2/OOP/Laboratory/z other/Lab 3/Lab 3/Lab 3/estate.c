#include "estate.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

medicine* createMedicine(char* name, int quantity, float concentration, float price)
{
    medicine* m = (medicine*)malloc(sizeof(medicine));
    m->name = (char*)malloc(strlen(name) + 1);
    strcpy(m->name, name);
    m->quantity = quantity;
    m->concentration = concentration;
    m->price = price;
    
    return m;
}

void destroyMedicine(medicine* m)
{
    free(m->name);
    free(m);
}

char* getName(medicine* m)
{
    return m->name;
}
int getQuantity(medicine* m)
{
    return m->quantity;
}
float getConcentration(medicine* m)
{
    return m->concentration;
}
float getPrice(medicine* m)
{
    return m->price;
}

medicine* copyMedicine(medicine* m)
{
    if (m == NULL)
        return NULL;
    medicine* newMedicine = createMedicine(getName(m), getQuantity(m), getConcentration(m), getPrice(m));
    return newMedicine;
}
void toString(medicine* m, char str[])
{
    sprintf(str, "Medicine %s has concentration %.2f, is in stock %d times and its price is %.2f", m->name, m->concentration, m->quantity, m->price);
}
