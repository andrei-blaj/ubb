#pragma once

typedef struct medicine_s
{
    char* name;
    int quantity;
    float concentration, price;
}medicine;

medicine* createMedicine(char* name, int quantity, float concentration, float price);
void destroyMedicine(medicine* m);


char* getName(medicine* m);
int getQuantity(medicine* m);
float getConcentration(medicine* m);
float getPrice(medicine* m);
medicine* copyMedicine(medicine* m);
void toString(medicine* m, char str[]);

