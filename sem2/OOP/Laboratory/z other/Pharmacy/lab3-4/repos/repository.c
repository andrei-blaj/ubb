#include "../models/medication.h"
#include "../collections/vector.h"
#include "repository.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

Repository *repo_create() {
    Repository *ret = malloc(sizeof(Repository));
    ret->v = vector_create();
    return ret;
}

bool repo_cmp_name(Medication *a, Medication *b) {
    return (strcmp(a->name, b->name) <= 0);
}

bool repo_cmp_concentration(Medication *a, Medication *b) {
    return (a->concentration < b->concentration);
}

bool repo_cmp_quantity(Medication *a, Medication *b) {
    return (a->quantity < b->quantity);
}

bool repo_cmp_price(Medication *a, Medication *b) {
    return (a->price <= b->price);
}

void repo_sort(Repository *this, bool (*cmp)(Medication *, Medication *)) {
    for(int i=0; i<vector_size(this->v); i++)
        for(int j=i+1; j<vector_size(this->v); j++)
            if(!cmp(vector_at_pos(this->v, i), vector_at_pos(this->v, j))) {
                Medication *temp = vector_at_pos(this->v, i);
                this->v->arr[i] = vector_at_pos(this->v, j);
                this->v->arr[j] = temp;
            }
}

void repo_reverse(Repository *this) {
    for(int i=0; i*2<vector_size(this->v); i++) {
        Medication *temp = this->v->arr[i];
        this->v->arr[i] = this->v->arr[vector_size(this->v)-i-1];
        this->v->arr[vector_size(this->v)-i-1] = temp;
    }
}
