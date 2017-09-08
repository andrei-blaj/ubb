#ifndef controller_h
#define controller_h

#include <stdio.h>
#include "repository.h"
typedef struct
{
    EstateRepo* repo;
} Controller;

Controller createController(EstateRepo* r);

/// <summary>
/// Adds a estate to the repository of estates.
/// </summary>
/// <param name="c">Pointer to theController.</param>
/// <param name = "address">A string, the address combination for the estate to be added.</param>
/// <param name = "name">A string, the name of the estate.</param>
/// <param name = "type">A string, the type of the estate .</param>
/// <param name = "surface">Double, the surface of the estate in square meters.</param>
/// <returns>1 - if the estate was sucessfully added; 0 - if the estate could not be added, as another estate with the same address already exists.</returns>
int addEstate(Controller* c, char type[], char address[], double surface, double price);
int deleteEstate(Controller* c, char address[30+1]);
int updateEstate(Controller* c, char type[], char address[], double surface, double price);


EstateRepo* getRepo(Controller* c);

/// <summary>
/// Searches for the estates containing a given address combination.
/// </summary>
/// <param name="c">Pointer to theController.</param>
/// <param name = "symbols">A string, the searched address combination; "null" - for all the estates in ascending order after the price.</param>
/// <returns>A repository of estates, that have the given address combinaton.</returns>
EstateRepo filterByAddressCombination(Controller* c, char address[],int CMD);
EstateRepo filterByTypeSurface(Controller* c, char type[12+1], double surface);
EstateRepo filterByPrice(Controller* c, double price, int CMD);



#endif /* controller_h */
