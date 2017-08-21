//
//  Ui.h
//  Real Estate Agency
//
//  Created by Andrei-Sorin Blaj on 25/04/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#ifndef Ui_h
#define Ui_h

#include <stdio.h>
#include <stdlib.h>
#include "../controller/Controller.h"

typedef struct {
    EstateController* ctrl;
} UI;

UI* create_allocate_UI(EstateController* ctrl);
void destroy(UI* ui);
void run(UI* ui);

#endif /* Ui_h */
