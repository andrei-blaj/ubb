#ifndef ui_h
#define ui_h

#include <stdio.h>
#include "controller.h"
typedef struct
{
    Controller* ctrl;
} UI;

UI createUI(Controller* c);

void startUI(UI* ui);

#endif /* ui_h */

