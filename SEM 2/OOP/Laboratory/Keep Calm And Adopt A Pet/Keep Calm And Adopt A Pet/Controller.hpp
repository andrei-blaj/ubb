#pragma once
#include "Repository.hpp"
#include "FileAdoptionList.hpp"
#include "DogValidator.hpp"
#include <vector>

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
    Controller();
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
    int addDogToRepository(const std::string& breed, const std::string& name, int years, int months, int days, const std::string& photograph);
    
    int deleteDogToRepository(const std::string& breed, const std::string& name);
    
    int updateDogToRepository(const std::string& breed, const std::string& name, const std::string& newbreed, const std::string& newname, int years, int months, int days, const std::string& newphotograph);
    
    //modif
    void sortAscendingByBreedCtrl();
    
    std::vector<Dog> filterByBreedAndAge(const std::string& breed, int years);
    
    //Dog Controller::getCurrentDog();
    Dog getCurrentDog(std::vector<Dog>& v);
    //void Controller::showFirstDog();
    void showFirstDog(std::vector<Dog>& v);
    //void Controller::nextDog();
    void nextDog(std::vector<Dog>& v);
    
    /*
     Adds a given dog to the current adoptionList.
     Input: d - Dog, the current dog.
     Output: the dog is added to the adoptionList.
     */
    void addDogToAdoptionList(const Dog& d);
    
    /*
     Saves the playlist.
     Throws: FileException - if the given file cannot be opened.
     */
    void saveAdoptionlist(const std::string& filename);
    
    /*
     Opens the playlist, with an appropriate application.
     Throws: FileException - if the given file cannot be opened.
     */
    void openAdoptionlist() const;
};



