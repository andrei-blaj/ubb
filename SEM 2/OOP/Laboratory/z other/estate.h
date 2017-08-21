/*
 Evelyn owns a real estate agency. Being also the single employee,
 she needs an application to help her manage all the real estates of
 her clients. Each Offer has a type (can be house, apartment or
 penthouse), an address, a surface and a price. Evelyn needs the
 application to help her in the following ways:
*/
#ifndef estate_h
#define estate_h

#include <stdio.h>

typedef struct
{
    char type[12 + 1];
    char address[30 + 1];
    double surface;
    double price;
} Estate;

Estate createEstate(char type[], char address[], double surface, double price);

char* getType(Estate* x);
char* getAddress(Estate* x);
double getSurface(Estate* x);
double getPrice(Estate* x);

void toString(Estate x, char str[]);


#endif /* domain_h */
