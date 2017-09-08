#include "Controller.hpp"
#include <string>
#include <algorithm>
#include <iterator>
#include "FileAdoptionList.hpp"

Controller::Controller()
{
    this->current = 0;
}

int Controller::addDogToRepository(const std::string& breed, const std::string& name, int years, int months, int days, const std::string& photograph)
{
    Dog d{ breed, name, Age{ years, months, days }, photograph };
    Dog dd = this->repo.findByBreedAndName(breed, name);
    if (dd.getBreed() != "" || dd.getName() != "")
        return 0;
    
    this->validator.validate(d);
    this->repo.addDog(d);
    return 1;
}

int Controller::deleteDogToRepository(const std::string& breed, const std::string& name)
{
    int pos = this->repo.findPosByBreedAndName(breed, name);
    if (pos != -1)
    {
        Dog dd = this->repo.findByBreedAndName(breed, name);
        Age a = dd.getAge();
        Dog d{ breed, name, Age{ a.getYears(), a.getMonths(), a.getDays() }, dd.getPhotograph() };
        this->repo.deleteDog(d);
        return 1;
    }
    return -1;
}

int Controller::updateDogToRepository(const std::string& breed, const std::string& name, const std::string& newbreed, const std::string& newname, int years, int months, int days, const std::string& newphotograph)
{
    int pos = this->repo.findPosByBreedAndName(breed, name);
    int pos2 = this->repo.findPosByBreedAndName(newbreed, newname);
    if (pos != -1 && pos2 == -1)
    {
        Dog d1 = this->repo.findByBreedAndName(breed, name);
        Age a = d1.getAge();
        Dog dOld{ breed, name, Age{ a.getYears(), a.getMonths(), a.getDays() }, d1.getPhotograph() };
        Dog dNew{ newbreed, newname, Age{ years, months, days }, newphotograph };
        this->repo.updateDog(dOld, dNew);
        return 1;
    }
    return -1;
}

void Controller::sortAscendingByBreedCtrl()
{
    this->repo.sortAscendingByBreed();
}

//filter Repository for user mode
std::vector<Dog> Controller::filterByBreedAndAge(const std::string& breed, int years)
{
    std::vector<Dog> dogs = this->repo.getDogs();
    std::vector<Dog> q(dogs.size());
    auto it = std::copy_if(dogs.begin(), dogs.end(), q.begin(), [breed, years](Dog d) {return d.getBreed() == breed && d.getAge().getYears() < years; });
    q.resize(std::distance(q.begin(), it));
    return q;
}

///Manage the AdoptionList
Dog Controller::getCurrentDog(std::vector<Dog>& v)
{
    if (v.size() == 0)
        return Dog{};
    if (this->current == v.size())
        this->current = 0;
    return v[this->current];
}

void Controller::showFirstDog(std::vector<Dog>& v)
{
    if (v.size() == 0)
        return;
    Dog currentDog = v[this->current];
    currentDog.showPhotograph();
}

void Controller::nextDog(std::vector<Dog>& v)
{
    this->current++;
    if (v.size() == 0)
        return;
    if (this->current == v.size())
        this->current = 0;
    Dog currentDog = v[this->current];
    currentDog.showPhotograph();
}

void Controller::addDogToAdoptionList(const Dog& d)
{
    this->adoptionList->add(d);
    this->repo.deleteDog(d);
    this->current = 0;
}

void Controller::saveAdoptionlist(const std::string& filename)
{
    if(this->adoptionList==nullptr)
        return;
    this->adoptionList->setFileName(filename);
    this->adoptionList->writeToFile();
}

void Controller::openAdoptionlist() const
{
    if (this->adoptionList == nullptr)
        return;
    
    this->adoptionList->displayAdoptionList();
}
