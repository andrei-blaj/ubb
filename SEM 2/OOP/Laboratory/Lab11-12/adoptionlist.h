#ifndef ADOPTIONLIST_H
#define ADOPTIONLIST_H

#include "dog.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

class AdoptionList {
protected:
    std::vector <Dog> adoptionList;
public:
    AdoptionList();

    std::vector <Dog> getAdoptionList();
    void add(const Dog& d);
};

#endif // ADOPTIONLIST_H
