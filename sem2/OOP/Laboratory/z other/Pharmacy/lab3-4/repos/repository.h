#pragma once
#include <stdbool.h>
#include "../models/medication.h"
#include "../collections/vector.h"


typedef struct {
    vector *v;
} Repository;

/* Method allocates memory for a Repository
 * and returns a pointer to it.
 */
Repository *repo_create();

/* Method takes two pointers to Medication
 * objects, and returns true if the first
 * one must precede the second one when
 * sorted.
 *
 * Criteria: name, alphabetically.
 */
bool repo_cmp_name(Medication *a, Medication *b);

/* Method takes two pointers to Medication
 * objects, and returns true if the first
 * one must precede the second one when
 * sorted.
 *
 * Criteria: concentration.
 */
bool repo_cmp_concentration(Medication *a, Medication *b);

/* Method takes two pointers to Medication
 * objects, and returns true if the first
 * one must precede the second one when
 * sorted.
 *
 * Criteria: quantity.
 */
bool repo_cmp_quantity(Medication *a, Medication *b);

/* Method takes two pointers to Medication
 * objects, and returns true if the first
 * one must precede the second one when
 * sorted.
 *
 * Criteria: price.
 */
bool repo_cmp_price(Medication *a, Medication *b);

/* Method takes a pointer to a Repository
 * and a pointer to a comparison function.
 *
 * It then (slowly) sorts in place all
 * objects in the the Repository based
 * on that criteria.
 */
void repo_sort(Repository *this, bool (*cmp)(Medication *, Medication *));

/* Method takes a pointer to a Repository
 * and reverses the objects in place.
 */
void repo_reverse(Repository *this);
