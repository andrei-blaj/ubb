#pragma once
#include "Repository.h"
#include "FileAdoptionList.h"
#include "DogValidator.h"
//#include <vector>

class Controller
{
private:
	Repository repo;
	FileAdoptionList* adoptionList;
	DogValidator validator;
	//modif
	int current;
	//

public:
	Controller::Controller();
	Controller(const Repository& r, FileAdoptionList* a, DogValidator v) : repo{ r }, adoptionList{ a }, validator{ v } {}
	/*Controller(const Repository& r, AdoptionList& a, DogValidator v)
	{
		this->repo = r;
		this->adoptionList = a;
		this->validator = v;
	}*/
	Repository getRepo() const { return repo; }
	AdoptionList* getAdoptionList() const { return adoptionList; }

	// Adds a dog with the given data to the dog repository.
	int Controller::addDogToRepository(const std::string& breed, const std::string& name, int years, int months, int days, const std::string& photograph);

	int Controller::deleteDogToRepository(const std::string& breed, const std::string& name);

	int Controller::updateDogToRepository(const std::string& breed, const std::string& name, const std::string& newbreed, const std::string& newname, int years, int months, int days, const std::string& newphotograph);

	//modif
	void Controller::sortAscendingByBreedCtrl();

	std::vector<Dog> Controller::filterByBreedAndAge(const std::string& breed, int years);

	//Dog Controller::getCurrentDog();
	Dog Controller::getCurrentDog(std::vector<Dog>& v);
	//void Controller::showFirstDog();
	void Controller::showFirstDog(std::vector<Dog>& v);
	//void Controller::nextDog();
	void Controller::nextDog(std::vector<Dog>& v);

	/*
	Adds a given dog to the current adoptionList.
	Input: d - Dog, the current dog.
	Output: the dog is added to the adoptionList.
	*/
	void Controller::addDogToAdoptionList(const Dog& d);

	/*
	Saves the playlist.
	Throws: FileException - if the given file cannot be opened.
	*/
	void Controller::saveAdoptionlist(const std::string& filename);

	/*
	Opens the playlist, with an appropriate application.
	Throws: FileException - if the given file cannot be opened.
	*/
	void Controller::openAdoptionlist() const;
};



