#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

#include "adoptionlist.h"

AdoptionList::AdoptionList() {}

std::vector <Dog> AdoptionList::getAdoptionList() {
    return this -> adoptionList;
}

void AdoptionList::add(const Dog& d) {
    this -> adoptionList.push_back(d);
}
