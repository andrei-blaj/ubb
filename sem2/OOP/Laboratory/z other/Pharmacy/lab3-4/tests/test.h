#pragma once
#include "../controllers/controller.h"

void test_populate(Controller *this, char *filename);

void test_parse_line(char *line, char *name, double *concentration, int *quantity, double *price);

void test_medication();
void test_controller();
void test_everything();

