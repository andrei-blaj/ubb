#ifndef repository_h
#define repository_h
#include "estate.h"
#include <stdio.h>
typedef struct
{
    Estate estate[100];
    int length;
} EstateRepo;


/// <summary>
/// Creates a EstateRepo.
/// </summary>
EstateRepo createRepo();

/// <summary>
/// Finds the estate with the given address.
/// </summary>
/// <param name="v">Pointer to the EstateRepo.</param>
/// <param name = "symbols">A string, the address combination to search for.</param>
/// <returns>pos - the position on which the estate with the given address is in the EstateRepo; -1 - if the estate does not exist.</returns>
int find(EstateRepo* v, char address[]);

/*
	Adds an estate to the repository of estates.
	Input:	- v - pointer to the EstateRepo
 - x - estate
	Output: 1 - if the estate was sucessfully added
 0 - if the estate could not be added, as another esteate with the same address already exists in the EstateRepo.
 */
int add(EstateRepo* v, Estate x);
int delete(EstateRepo* v, char address[30+1]);
int update(EstateRepo* v, Estate x);


int getLength(EstateRepo* v);


/*
	Returns the estate on the given position in the estate vector.
	Input:	v - the estate repository;
 pos - integer, the position;
	Output: the estate on the given potision, or an "empty" estate.
 */
Estate getEstateOnPos(EstateRepo* v, int pos);

void testEstateRepo();

#endif /* repository_h */
