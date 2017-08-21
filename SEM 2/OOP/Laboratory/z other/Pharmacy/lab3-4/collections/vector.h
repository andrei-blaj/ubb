#pragma once
#include "../models/medication.h"

typedef struct {
    Medication **arr;       // pointer to an array of pointers
    int size, capacity;
} vector;

/* Method allocates memory for a vector
 * and initializes it with default values.
 * Returns a pointer to the vector.
 */
vector *vector_create();

/* Method takes a pointer to a vector and a pointer
 * to a medication, and appends it to the end of the
 * vector.
 */
void vector_push_back(vector *this, Medication *m);

/* Method takes a pointer to a vector and returns
 * its size.
 */
int vector_size(vector *this);

/* Method takes a pointer to a vector and removes
 * the last element. If empty, nothing happens.
 */
void vector_pop_back(vector *this);

/* Method takes a pointer to a vector and a position
 * and returns the Medication pointer at that position.
 * Position must be valid!
 */
Medication *vector_at_pos(vector *this, int pos);
