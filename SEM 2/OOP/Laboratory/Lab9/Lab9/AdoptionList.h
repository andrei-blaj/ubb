#pragma once
#include "Dog.h"
#include <vector>

class AdoptionList
{
protected:
	std::vector<Dog> dogs;
	int current;

public:
	AdoptionList();

	///Add dog to the AdoptionList User
	void AdoptionList::add(const Dog& dog);

	///Checks if the AdoptionList is empty.
	bool AdoptionList::isEmpty();

	///Return the list of dogs that one user adopted.
	//std::vector<Dog> getAdoptedDogs() const { return dogs; }

	virtual ~AdoptionList(){}
};
