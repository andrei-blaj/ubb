#pragma once
#include "Dog.hpp"
#include <vector>

class AdoptionList
{
public:
    std::vector<Dog> dogs;
    int current;
    
public:
    AdoptionList();
    
    ///Add dog to the AdoptionList User
    void add(const Dog& dog);
    
    ///Checks if the AdoptionList is empty.
    bool isEmpty();
    
    ///Return the list of dogs that one user adopted.
    //std::vector<Dog> getAdoptedDogs() const { return dogs; }
    
    virtual ~AdoptionList(){}
};
