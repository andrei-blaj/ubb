#include "AdoptionList.hpp"

//using namespace std;
AdoptionList::AdoptionList()
{
    this->current = 0;
}

void AdoptionList::add(const Dog& dog)
{
    this->dogs.push_back(dog);
}

bool AdoptionList::isEmpty()
{
    return this->dogs.size() == 0;
}

