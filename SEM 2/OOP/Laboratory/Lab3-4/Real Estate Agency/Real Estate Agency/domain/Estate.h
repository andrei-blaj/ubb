//
//  Estate.h
//  Real Estate Agency
//
//  Created by Andrei-Sorin Blaj on 25/04/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#ifndef Estate_h
#define Estate_h

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    char* type;
    char* address;
    double surface;
    double price;
} Estate;

Estate* create_estate(char* type, char* address, double surface, double price);

void destroy_estate(Estate* estate);

Estate* copy_estate(Estate* estate);

char* get_type(Estate* estate);

char* get_address(Estate* estate);

double get_surface(Estate* estate);

double get_price(Estate* estate);

void toString(Estate* estate, char str[]);

Estate* copy_estate(Estate* estate);


#endif /* Estate_h */
