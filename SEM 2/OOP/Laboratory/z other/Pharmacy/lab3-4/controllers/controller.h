#pragma once
#include "../repos/repository.h"
#include <stdbool.h>

typedef struct {
    Repository *repo[1000];
    int index;
    int states;
} Controller;

/* Method allocates memory for a Controller object
 * and returns a pointer to it.
 */
Controller *controller_create();

/* Method takes a pointer to a Controller and a
 * pointer to a Medication, and adds it to the
 * current Repository. The `verbose` argument
 * can be set to true if extra debug information
 * is preferred.
 */
void controller_add_medication(Controller *this, Medication *what, bool verbose);

/* Method takes a pointer to a Controller and a
 * pointer to a Medication, and removes said
 * Medication from the Repository. If it doesn't
 * exist, nothing happens.
 *
 * Returns true if Medication was removed, false
 * otherwise.
 */
bool controller_delete_medication(Controller *this, Medication *what);

/* Method takes a pointer to a Controller, a
 * pointer to a Medication, and pointers to the
 * pieces of information that characterize such
 * an object. It then overwrites the Medication
 * data with the new values.
 */
void controller_update_medication(Controller *this, Medication *what, char *name, double *concentration, int *quantity, double *price);

/* Method takes a pointer to a Controller and
 * a pointer to a Medication, and searches for
 * said Medication in the Repository.
 *
 * If found, it returns the pointer to the
 * actual Repository entry.
 * Otherwise, returns NULL.
 */
Medication *controller_find_medication(Controller *this, Medication *m);

/* Method takes a pointer to a Controller and
 * prints to stdout an ASCII table containing
 * all Medication objects in the current
 * Repository. The `indices` argument allows
 * for transforming the list into an ordered
 * one.
 *
 * TODO: This should probably be moved to the
 * UI module.
 */
void controller_list_medications(Controller *this, bool indices);

/* Method takes a pointer to a Controller and
 * a pointer to a string. It then lists all
 * Medication objects in the current Repository
 * that contain the given string in their name.
 *
 * TODO: This should probably be moved to the
 * UI module.
 */
void controller_search_medication(Controller *this, char *name);

/* Method takes a pointer to a Controller and
 * a quantity. It then lists all Medication
 * objects in the current Repository that have
 * a lower quantity than the specified one.
 *
 * TODO: This should probably be moved to the
 * UI module.
 */
void controller_filter_medication(Controller *this, int quantity);

/* Method takes a pointer to a Controller.
 * It tries to create a new repo (if one
 * doesn't exist already) and populates it
 * with the same data as the current
 * Repository. Then it moves forward in time
 * (increments Controller->index) so that
 * the current time points to the newly
 * prepared Repository. The next user
 * alteration will be applied on this Repo.
 */
void controller_prepare_future(Controller *this);

/* Goes back in time one step. If at oldest
 * state, nothing happens.
 *
 * TODO: remove output and use a return code
 * instead.
 */
void controller_undo(Controller *this);

/* Goes forward in time one step. If at most
 * recent state, nothing happens.
 *
 * TODO: remove output and use a return code
 * instead.
 */
void controller_redo(Controller *this);

/* Method returns a pointer to the Repository
 * indicated by the current time.
 */
Repository *controller_get_current_repo(Controller *this);
