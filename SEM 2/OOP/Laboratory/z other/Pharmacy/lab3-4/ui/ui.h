#pragma once
#include "../controllers/controller.h"

typedef struct {
    Controller *controller;
} UI;

/* Method allocates memory for a UI
 * and returns a pointer to it.
 */
UI *ui_create();

/* Method runs the main loop of the UI.
 */
void ui_run(UI *this);

/* Method prompts the user for a command
 * and reads it into the location pointed
 * by the `*command`.
 */
void ui_get_command(UI *this, char *command);

/* Method displays the available commands.
 */
void ui_show_help(UI *this);

/* Method displays the add medication menu.
 */
void ui_show_add_menu(UI *this);

/* Method displays the delete medication
 * menu.
 */
void ui_show_delete_menu(UI *this);

/* Method displays the update medication
 * menu.
 */
void ui_show_update_menu(UI *this);

/* Method displays the search medication
 * menu.
 */
void ui_show_search_menu(UI *this);

/* Method displays the sort medication menu.
 */
void ui_show_sort_menu(UI *this);

/* Method displays the short supply menu.
 */
void ui_show_short_supply_menu(UI *this);
