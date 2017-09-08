#pragma once
#include "Dog.h"
#include <vector>

class Repository
{
private:
	std::vector<Dog> dogs;
	std::string filename;

public:
	Repository() {}

	/*
	Constructor with parameters.
	Initializes an object of type repository, by reading data from the given file.
	Throws: FileException - if the file cannot be opened.
	*/
	Repository(const std::string& filename);

	/*
	Adds a dog to the repository.
	Input: d - Dog.
	Output: the dog is added to the repository.
	*/
	void addDog(const Dog& d);

	/*
	Finds a dog, by breed and name.
	Input: breed, name - string
	Output: the dog that was found, or an "empty" dog (all fields empty and age 0), if nothing was found.
	*/
	Dog findByBreedAndName(const std::string& breed, const std::string& name);

	std::vector<Dog> getDogs() const { return dogs; }

	int Repository::findPosByBreedAndName(const std::string& breed, const std::string& name);

	void Repository::deleteDog(const Dog& d);

	void Repository::updateDog(const Dog& d1, const Dog& d2);

	//modif
	void Repository::setDogOnPos(int pos, const Dog& d);
	void Repository::sortAscendingByBreed();

private:
	void Repository::readFromFile();
	void Repository::writeToFile();
};

