#include "../models/medication.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

vector *vector_create() {
    vector *ret = malloc(sizeof(vector));
    ret->size = 0;
    ret->capacity = 1;

    ret->arr = (Medication **) malloc(ret->capacity * sizeof(Medication*));
    return ret;
}

void vector_push_back(vector *this, Medication *m) {
    if(this->size >= this->capacity) {
        this->capacity *= 2;
        this->arr = realloc(this->arr, this->capacity * sizeof(Medication*));
    }

    this->arr[this->size++] = m;
}

int vector_size(vector *this) {
    return this->size;
}

void vector_pop_back(vector *this) {
    if(this->size > 0)
        this->size--;
}

Medication *vector_at_pos(vector *this, int pos) {
    return this->arr[pos];
}
