#include "estate.h"
#include <string.h>

Estate createEstate(char type[], char address[], double surface, double price)
{
    Estate x;
    strcpy(x.type, type);
    strcpy(x.address, address);
    x.surface = surface;
    x.price = price;
    
    return x;
}


char* getType(Estate* x)
{
    return x->type;
}

char* getAddress(Estate* x)
{
    return x->address;
}

double getSurface(Estate* x)
{
    return x->surface;
}

double getPrice(Estate* x)
{
    return x->price;
}

void toString(Estate x, char str[])
{
    sprintf(str, "\tEstate\nType : %s\nAddress : %s\nSurface : %.2lf\nPrice : %.2lf $\n\n",x.type,x.address,x.surface,x.price);
}

