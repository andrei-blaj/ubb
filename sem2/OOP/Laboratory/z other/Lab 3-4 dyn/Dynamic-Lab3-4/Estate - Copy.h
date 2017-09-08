#pragma once
#include <stdlib.h>
#include<string.h>
#include<stdio.h>

typedef struct {
	char* type;
	char* address;
	double surface;
	double price;
}Estate;

Estate* create_estate(char* type, char* address, double surface, double price);

void destroy_estate(Estate* estate);

char* get_type(Estate* estate);

char* get_address(Estate* estate);

double get_surface(Estate* estate);

double get_price(Estate* estate);

void toString(Estate* estate, char str[]);

Estate* copy_estate(Estate* estate);
