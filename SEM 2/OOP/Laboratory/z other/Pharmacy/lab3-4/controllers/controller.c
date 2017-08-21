#include "../repos/repository.h"
#include "../models/medication.h"
#include "../collections/vector.h"
#include "controller.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Controller *controller_create() {
    Controller *this = malloc(sizeof(Controller));
    this->index = 0;
    this->states = 1;
    this->repo[this->index] = repo_create();
    return this;
}

void controller_prepare_future(Controller *this) {
    if(this->repo[this->index+1] == NULL)
        this->repo[this->index+1] = repo_create();

    this->repo[this->index+1] = repo_create();
    this->repo[this->index+1]->v = vector_create();

    for(int i=0; i<vector_size(this->repo[this->index]->v); i++) {
        Medication *temp = medication_create("", 0, 0, 0);
        memcpy(temp, vector_at_pos(this->repo[this->index]->v, i), sizeof(Medication));
        vector_push_back(this->repo[this->index+1]->v, temp);
    }

    this->index++;
    this->states = this->index + 1;
}

void controller_undo(Controller *this) {
    if(this->index > 0)
        this->index--;
    else
        printf("Already at oldest state.\n");
}

void controller_redo(Controller *this) {
    if(this->index < this->states-1)
        this->index++;
    else
        printf("Already at most recent state.\n");
}

Repository *controller_get_current_repo(Controller *this) {
    return this->repo[this->index];
}

void controller_add_medication(Controller *this, Medication *what, bool verbose) {
    Medication *m = controller_find_medication(this, what);

    controller_prepare_future(this);
    Repository *r = controller_get_current_repo(this);

    //printf("should add medication with name <%s>\n", what->name);

    if(m == NULL) {                                  // medication doesn't exist
        vector_push_back(r->v, what);
        if(verbose)
            printf("Medication added.\n");
    }
    else                                             // medication exists
        m->quantity += what->quantity;               // update its quantity

}

bool controller_delete_medication(Controller *this, Medication *what) {
    Medication *m = controller_find_medication(this, what);

    if(m == NULL)       // doesn't exist
        return false;   // can't delete

    controller_prepare_future(this);
    Repository *r = controller_get_current_repo(this);


    *m = *vector_at_pos(r->v, vector_size(r->v)-1);
    vector_pop_back(r->v);
    return true;
}

void controller_update_medication(Controller *this, Medication *what, char *name, double *concentration, int *quantity, double *price) {

    controller_prepare_future(this);
    Repository *r = controller_get_current_repo(this);

    for(int i=0; i<vector_size(r->v); i++) {
        Medication *elem = vector_at_pos(r->v, i);

        if(!strcmp(elem->name, what->name) && elem->concentration == what->concentration) {
            strcpy(elem->name, name);
            elem->concentration = *concentration;
            elem->quantity = *quantity;
            elem->price = *price;
        }
    }
}


Medication *controller_find_medication(Controller *this, Medication *m) {
    Repository *r = controller_get_current_repo(this);

    for(int i=0; i<vector_size(r->v); i++)
        if(!strcmp(m->name, vector_at_pos(r->v, i)->name) && m->concentration == vector_at_pos(r->v, i)->concentration) {
            //printf("Found this medication on position %d.\n", i);
            return vector_at_pos(r->v, i);
        }
    return NULL;
}


void controller_list_medications(Controller *this, bool indices) {
    Repository *r = controller_get_current_repo(this);

    if(vector_size(r->v) == 0) {
        printf("No medications in stock.\n");
        return;
    }

    printf("There are %d medications in stock.\n", vector_size(r->v));

    medication_show_header();
    for(int i=0; i<vector_size(r->v); i++) {
        if(indices)
            printf("%d. ", i);
        medication_show(vector_at_pos(r->v, i));
    }
    medication_show_footer();
}

void controller_search_medication(Controller *this, char *name) {
    Repository *r = controller_get_current_repo(this);
    bool found = false;

    // printf("Will search for %s.\n", name);

    medication_show_header();
    for(int i=0; i<vector_size(r->v); i++)
        if(strstr(vector_at_pos(r->v, i)->name, name) != NULL) {
            medication_show(vector_at_pos(r->v, i));
            found = true;
        }
    if(!found)
        medication_show_middle();
    medication_show_footer();
}

void controller_filter_medication(Controller *this, int quantity) {
    Repository *r = controller_get_current_repo(this);
    bool found = false;

    medication_show_header();
    for(int i=0; i<vector_size(r->v); i++)
        if(r->v->arr[i]->quantity < quantity) {
            medication_show(vector_at_pos(r->v, i));
            found = true;
        }
    if(!found)
        medication_show_middle();
    medication_show_footer();
}

