#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../models/medication.h"
#include "../repos/repository.h"
#include "../controllers/controller.h"
#include "ui.h"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */



UI *ui_create() {
    UI *this = malloc(sizeof(UI));
    this->controller = controller_create();
    return this;
}

void ui_run(UI *this) {
    char *command = malloc(50*sizeof(char));

    while(1) {
        printf("State: %d\n", this->controller->index);
        printf("Vector has has %d/%d objects.\n", vector_size(controller_get_current_repo(this->controller)->v), controller_get_current_repo(this->controller)->v->capacity);

        ui_get_command(this, command);
        if(!strcmp(command, "add"))
            ui_show_add_menu(this);
        else if(!strcmp(command, "delete"))
            ui_show_delete_menu(this);
        else if(!strcmp(command, "search"))
            ui_show_search_menu(this);
        else if(!strcmp(command, "sort"))
            ui_show_sort_menu(this);
        else if(!strcmp(command, "update"))
            ui_show_update_menu(this);
        else if(!strcmp(command, "supply"))
            ui_show_short_supply_menu(this);
        else if(!strcmp(command, "undo"))
            controller_undo(this->controller);
        else if(!strcmp(command, "redo"))
            controller_redo(this->controller);
        else if(!strcmp(command, "exit") || !strcmp(command, "quit"))
            exit(0);
        else if(!strcmp(command, "help"))
            ui_show_help(this);
        else if(!strcmp(command, "list"))
            controller_list_medications(this->controller, false);
        else
            printf("Bad command. Try " BOLDWHITE "help" RESET ".\n");
    }
}

void ui_get_command(UI *this, char *command) {
    printf(BOLDWHITE "> ");
    scanf("%s", command);
    printf(RESET);
}

void ui_show_help(UI *this) {
    printf("Commands:\n");
    printf("\t" BOLDWHITE "add"    RESET "\n");
    printf("\t" BOLDWHITE "update" RESET "\n");
    printf("\t" BOLDWHITE "delete" RESET "\n");
    printf("\n");
    printf("\t" BOLDWHITE "list"   RESET "\n");
    printf("\t" BOLDWHITE "search" RESET "\n");
    printf("\t" BOLDWHITE "sort"   RESET "\n");
    printf("\t" BOLDWHITE "supply" RESET "\n");
    printf("\n");
    printf("\t" BOLDWHITE "undo"   RESET "\n");
    printf("\t" BOLDWHITE "redo"   RESET "\n");
    printf("\n");
    printf("\t" BOLDWHITE "help"   RESET "\n");
    printf("\t" BOLDWHITE "exit"   RESET "/" BOLDWHITE "quit" RESET "\n");
}

void ui_show_add_menu(UI *this) {
    printf("You want to add a medication.\n");

    char name[50];
    double concentration;
    int quantity;
    double price = 0;

    printf("Name (str): ");
    scanf("%s", name);

    printf("Concentration (percentage): ");
    scanf("%lf", &concentration);

    printf("Quantity (int): ");
    scanf("%d", &quantity);

    Medication *m = medication_create(name, concentration, quantity, price);

    // if this medication already exists
    // i shouldn't ask again for the price
    if(controller_find_medication(this->controller, m) == NULL) {
        printf("Price (double): ");
        scanf("%lf", &price);
        m->price = price;
    }

    controller_add_medication(this->controller, m, true);
}

void ui_show_delete_menu(UI *this) {
    printf("You want to delete a medication.\n");

    char name[50];
    double concentration;

    printf("Name (str): ");
    scanf("%s", name);

    printf("Concentration (percentage): ");
    scanf("%lf", &concentration);

    Medication *m = medication_create(name, concentration, 0, 0);

    if(controller_delete_medication(this->controller, m))
        printf("Medication deleted.\n");
    else
        printf("Medication does not exist.\n");
}

void ui_show_update_menu(UI *this) {
    printf("You want to update a medication.\n");
    controller_list_medications(this->controller, false);
    printf("\nPlease identify an existing medication: \n");

    char name[50];
    double concentration;
    int quantity = 0;
    double price = 0;

    printf("Name (str): ");
    scanf("%s", name);

    printf("Concentration (percentage): ");
    scanf("%lf", &concentration);

    Medication *m = medication_create(name, concentration, quantity, price);
    Medication *what = controller_find_medication(this->controller, m);

    if(what != NULL) {
        printf("Medication found.\n");

        printf("\nNew name (str): ");
        scanf("%s", name);

        printf("New concentration (percentage): ");
        scanf("%lf", &concentration);

        printf("New quantity (int): ");
        scanf("%d", &quantity);

        printf("New price (double): ");
        scanf("%lf", &price);

        controller_update_medication(this->controller, what, name, &concentration, &quantity, &price);

        printf("Medication updated. :)\n");
    }
    else {
        printf("Medication not found.\n");
    }
}

void ui_show_search_menu(UI *this) {
    char *name = malloc(50 * sizeof(char));
    printf("Term to search: ");
    scanf("%s", name);

    controller_search_medication(this->controller, name);
}

void ui_show_sort_menu(UI *this) {
    char *criteria = malloc(50*sizeof(char));

    printf("Criteria:\n");
    printf("\t" BOLDWHITE "name" RESET "\n");
    printf("\t" BOLDWHITE "concentration" RESET "\n");
    printf("\t" BOLDWHITE "quantity" RESET "\n");
    printf("\t" BOLDWHITE "price" RESET "\n");

    scanf("%s", criteria);

    Repository *r = controller_get_current_repo(this->controller);

    if(!strcmp(criteria, "name"))
        repo_sort(r, repo_cmp_name);
    else if(!strcmp(criteria, "concentration"))
        repo_sort(r, repo_cmp_concentration);
    else if(!strcmp(criteria, "quantity"))
        repo_sort(r, repo_cmp_quantity);
    else if(!strcmp(criteria, "price"))
        repo_sort(r, repo_cmp_price);
    else {
        printf("Invalid criteria.\n");
        return;
    }

    printf("Reverse? (y/n): ");
    scanf("%s", criteria);
    if(!strcmp(criteria, "y"))
        repo_reverse(r);

}

void ui_show_short_supply_menu(UI *this) {
    int quantity;
    printf("Quantity: ");
    scanf("%d", &quantity);

    controller_filter_medication(this->controller, quantity);
}
