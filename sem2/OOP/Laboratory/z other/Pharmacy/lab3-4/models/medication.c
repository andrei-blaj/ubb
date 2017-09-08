#include "medication.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Medication *medication_create(char name[], double concentration, int quantity, double price) {
    Medication *ret = malloc(sizeof(Medication));

    strcpy(ret->name, name);
    ret->concentration = concentration;
    ret->quantity = quantity;
    ret->price = price;

    return ret;
}

void medication_show_header() {
    printf("+------------------------+---------------+-------------+-------------+\n");
    printf("|         Name           | Concentration |   Quantity  |    Price    |\n");
    printf("+------------------------+---------------+-------------+-------------+\n");
}
void medication_show_middle() {
    printf("|                        |               |             |             |\n");
}

void medication_show_footer() {
    printf("+------------------------+---------------+-------------+-------------+\n");
}


void medication_show(Medication *this) {
    printf("|%23s |%9.2lf%%     |%5d units  |%7.2lf leva |\n", this->name, this->concentration, this->quantity, this->price);
}
