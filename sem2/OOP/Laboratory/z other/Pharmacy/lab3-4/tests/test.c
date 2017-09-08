#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../controllers/controller.h"
#include "../repos/repository.h"
#include "../models/medication.h"


void test_parse_line(char *line, char *name, double *concentration, int *quantity, double *price) {
    char *buffer;

    buffer = strtok(line, ",");
    //printf("Buffer is %s\n", buffer);
    strcpy(name, buffer);

    buffer = strtok(NULL, ",");
    //printf("Buffer is %s\n", buffer);
    *concentration = atof(buffer);

    buffer = strtok(NULL, ",");
    //printf("Buffer is %s\n", buffer);
    *quantity = atoi(buffer);

    buffer = strtok(NULL, ",");
    //printf("Buffer is %s\n", buffer);
    *price = atof(buffer);
}

void test_populate(Controller *this, char *filename) {
    FILE *f = fopen(filename, "r");

    if(f == NULL) {
        printf("Could not open %s. :(\n", filename);
        return;
    }

    printf("File opened :).\n");

    char line[100];
    char name[50];
    double concentration;
    int quantity;
    double price;

    while(fscanf(f, "%s", line) != EOF) {
        test_parse_line(line, name, &concentration, &quantity, &price);

        Medication *m = medication_create(name, concentration, quantity, price);
        controller_add_medication(this, m, false);
    }

    fclose(f);
}

void test_medication() {
    char name[50] = "Lemon";
    double concentration = 99.9;
    int quantity = 2;
    double price = 1.2;

    Medication *m = medication_create(name, concentration, quantity, price);

    assert(!strcmp(m->name, "Lemon"));
    assert(99.8 < m->concentration && m->concentration < 100.0);
    assert(m->quantity == 2);
    assert(m->price == 1.2);
}

void test_controller() {
    Controller *c = controller_create();

    Medication *m1 = medication_create("vin_fiert", 14, 1, 20);
    Medication *m2 = medication_create("apa_calda", 0, 100, 5);
    Medication *m3 = medication_create("vitamina_c", 100, -1, 15);

    controller_add_medication(c, m1, false);
    controller_add_medication(c, m2, false);

    assert(controller_find_medication(c, m1) != NULL);
    assert(controller_find_medication(c, m2) != NULL);
    assert(controller_find_medication(c, m3) == NULL);

    controller_delete_medication(c, m2);

    assert(controller_find_medication(c, m2) == NULL);

    double *new_concentration = malloc(sizeof(double));
    int *new_quantity = malloc(sizeof(int));
    double *new_price = malloc(sizeof(double));
    *new_concentration = 0;
    *new_quantity = 0;
    *new_price = 0;

    controller_update_medication(c, m3, "tiramisu", new_concentration, new_quantity, new_price);

}

void test_everything() {
    test_medication();
    test_controller();

    printf("All tests passed :).\n");
}

