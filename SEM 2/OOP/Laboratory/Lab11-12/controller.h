#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

#include "repository.h"
#include "adoptionlist.h"

class Controller {
protected:
    Repository repo;
    AdoptionList al;

public:
    Controller();

    std::string addDog(const std::string& breed, const std::string& name, const std::string& age, const std::string& photograph);
    std::string removeDog(const std::string& dog_id);
    std::string updateDog(const std::string& dog_id, const std::string& breed, const std::string& name, const std::string& age, const std::string& photograph);

    std::string addToAdoptionList(const Dog& d);
    std::string filter(const std::string& breed, const std::string& age);

    std::string getDogs();
    std::vector <Dog> getDogList();
    std::vector <Dog> getAdoptionList();
};

#endif // CONTROLLER_H
