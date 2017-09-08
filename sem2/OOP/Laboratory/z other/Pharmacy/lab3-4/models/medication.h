#pragma once

typedef struct {
    char name[50];
    double concentration;
    int quantity;
    double price;
} Medication;

/* Method allocates memory for a Medication
 * object and returns a pointer to it.
 */
Medication *medication_create(char name[], double concentration, int quantity, double price);

/* Method displays the table header.
 */
void medication_show_header();

/* Method displays an empty line
 * in the table.
 */
void medication_show_middle();

/* Method displays the table footer.
 */
void medication_show_footer();

/* Method takes a pointer to a Medication
 * and displays it as a row in a table.
 */
void medication_show(Medication *this);

