#include "DynamicArray.h"
#include <stdlib.h>
#include <assert.h>

DynamicArray* createDynamicArray(int capacity)
{
	DynamicArray* da = (DynamicArray*)malloc(sizeof(DynamicArray));
	// make sure that the space was allocated
	if (da == NULL)
		return NULL;

	da->capacity = capacity;
	da->length = 0;

	// allocate space for the elements
	da->elems = (TElement*)malloc(capacity * sizeof(TElement));
	if (da->elems == NULL)
		return NULL;

	return da;
}

void destroy(DynamicArray* arr)
{
	if (arr == NULL)
		return;

	// free the space allocated for the planets
	free(arr->elems);
	arr->elems = NULL;

	// free the space allocated for the dynamic array
	free(arr);
	arr = NULL;
}

// Resizes the array, allocating more space.
void resize(DynamicArray* arr)
{
	if (arr == NULL)
		return;

	arr->capacity *= 2;
	arr->elems = (TElement*)realloc(arr->elems, arr->capacity * sizeof(TElement));
}

void add(DynamicArray* arr, TElement t)
{
	if (arr == NULL)
		return;
	if (arr->elems == NULL)
		return;

	// resize the array, if necessary
	if (arr->length == arr->capacity)
		resize(arr);
	arr->elems[arr->length] = t;
	arr->length++;
}

void testsDynamicArray()
{
	DynamicArray* da = createDynamicArray(2);
	if (da == NULL)
		assert(0);

	assert(da->capacity == 2);
	assert(da->length == 0);

	Planet p1 = createPlanet("UV$O*~1", "Gallifrey", "Kasterborous", 250000);
	add(da, p1);
	assert(da->length == 1);

	Planet p2 = createPlanet("V^E$9L@", "Abydos", "Sol", 583);
	add(da, p2);
	assert(da->length == 2);

	// capacity must double
	Planet p3 = createPlanet("A&V$9+Q", "Cimmeria", "Asgard", 1058);
	add(da, p3);
	assert(da->length == 3);
	assert(da->capacity == 4);

	destroy(da);
}
