#pragma once
#include "Controller.h"

typedef struct {
	EstateController* ctrl;
}UI;

UI* create_allocate_UI(EstateController* ctrl);
void destroy(UI* ui);
void run(UI* ui);