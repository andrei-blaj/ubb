//
//  DynamicArray.c
//  Real Estate Agency
//
//  Created by Andrei-Sorin Blaj on 25/04/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#include "DynamicArray.h"

DynamicArray* allocate_array(int capacity)
{
    DynamicArray*darray = (DynamicArray*)malloc(sizeof(DynamicArray));
    darray->elems = (TElement*)malloc(sizeof(TElement)*capacity);
    darray->length = 0;
    darray->capacity = capacity;
    return darray;
}

void deallocate_array(DynamicArray* darray)
{
    free(darray->elems);
    free(darray);
}

void grow_capacity(DynamicArray* darray)
{
    darray -> capacity = darray -> capacity * 2;
}

int search_by_address(DynamicArray * darray, char* address)
{
    int i;
    for (i = 0; i < darray->length; i++)
        if (strcmp(address, darray->elems[i]->address) == 0)
            return i; //daca il gasesc sa imi returneze pozitia pe care se afla pointerul la estate-ul respectiv;
    return -1; //daca nu il gasesc sa imi returneze -1
    
}

int get_length(DynamicArray * darray)
{
    return darray->length;
}

void delete_from_array(DynamicArray * darray, int pos)
{
    int i;
    for (i = pos; i < darray->length - 1; i++)
        darray->elems[i] = darray->elems[i + 1];
    darray->length--;
}

void update_array(DynamicArray * darray, int pos, TElement t)
{
    darray->elems[pos] = t;
}

void add_to_array(DynamicArray* darray, TElement t) //elementul t nu este de tip pointer pentru ca la lista DynamicArray vom ?!?!?!
{
    
    if (darray->length == darray->capacity)
        grow_capacity(darray);
    darray->elems[darray->length] = t;//darray este dynamic array-ul si elems este lista de elemente. adaygam elementul general t in lista elementelor apoi crestem lungimea
    darray->length++;
    
}






