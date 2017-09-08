#pragma once
#pragma once
#include "controller.h"

typedef struct
{
	Controller* ctrl;
} UI;

UI* createUI(Controller* c);
void destroyUI(UI* ui);

void startUI(UI* ui);
