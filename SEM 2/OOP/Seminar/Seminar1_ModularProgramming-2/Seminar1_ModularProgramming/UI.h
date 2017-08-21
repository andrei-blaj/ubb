#pragma once
#include "Controller.h"

typedef struct
{
	Controller* ctrl;
} UI;

UI createUI(Controller* c);

void startUI(UI* ui);