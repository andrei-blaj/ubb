#include "Repository.hpp"
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>
#include "Utils.hpp"
#include "RepositoryException.hpp"

using namespace std;

Repository::Repository(const std::string& filename)
{
    this->filename = filename;
    this->readFromFile();
}

void Repository::addDog(const Dog& d)
{
    this->dogs.push_back(d);
    this->writeToFile();
}

Dog Repository::findByBreedAndName(const std::string& breed, const std::string& name)
{
    if (this->dogs.size() == 0)
        return Dog{};
    auto it = std::find_if(this->dogs.begin(), this->dogs.end(), [breed, name](Dog d) {return d.getBreed() == breed && d.getName() == name; });
    if (it == this->dogs.end())
        return Dog{};
    else return *it;
}

int Repository::findPosByBreedAndName(const std::string& breed, const std::string& name)
{
    if (this->dogs.size() == 0)
        return -1;
    auto it = std::find_if(this->dogs.begin(), this->dogs.end(), [breed, name](Dog d) {return d.getBreed() == breed && d.getName() == name; });
    if (it == this->dogs.end())
        return -1;
    else {
        auto index = std::distance(this->dogs.begin(), it);
        return int(index);
    }
}

void Repository::deleteDog(const Dog& d)
{
    // find the position of the dog in the repository
    int pos = this->findPosByBreedAndName(d.getBreed(), d.getName());
    this->dogs.erase(this->dogs.begin() + pos);
    this->writeToFile();
}

void Repository::updateDog(const Dog& d1, const Dog& d2)
{
    // first search for a dog with the same name and breed as Dog d1;
    Dog q = this->findByBreedAndName(d1.getBreed(), d1.getName());
    if (q.getBreed() != "" || q.getName() != "")
    {
        int pos = this->findPosByBreedAndName(q.getBreed(), q.getName());
        this->dogs[pos] = d2;
        this->writeToFile();
    }
}

void Repository::setDogOnPos(int pos, const Dog& d)
{
    this->dogs[pos] = d;
}

//Lab activity:Sorts
void Repository::sortAscendingByBreed()
{
    sort(this->dogs.begin(), this->dogs.end(), [](const Dog& d1, const Dog& d2) { return d1.getBreed() < d2.getBreed(); });
}

void Repository::readFromFile()
{
    ifstream file(this->filename);
    if (!file.is_open())
        throw FileException("The file could not be open!");

    string breed, name, photograph;
    int age;
    
    while (file >> breed >> name >> age >> photograph)
        this->dogs.push_back(Dog{breed, name, Age{age, 0, 0}, photograph});
            
    file.close();
}

void Repository::writeToFile()
{
    ofstream file(this->filename);
    if (!file.is_open())
        throw FileException("The file could not be open!");
    for (auto d : this->dogs)
    {
        file << d.getBreed() << " " << d.getName() << " " << d.getAge().getYears() << " " << d.getPhotograph() << "\n";
    }
    file.close();
}
