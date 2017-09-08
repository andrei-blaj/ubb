#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

#include "repository.h"

Repository::Repository() {
    this -> filename = "/Users/blaj/UNI/SEM 2/OOP/Laboratory/Lab11-12/load.txt";
    this -> readFromFile();;
}

void Repository::addDog(const Dog &d) {
    this -> dogs.push_back(d);
    this -> writeToFile();
}

void Repository::removeDog(const std::string &dog_id) {
    std::cout << atoi(dog_id.c_str());
    this -> dogs.erase(this->dogs.begin() + atoi(dog_id.c_str()) - 1);
    this -> writeToFile();
}

void Repository::updateDog(const std::string &dog_id, const Dog &d) {
    this -> dogs[ atoi(dog_id.c_str()) - 1 ] = d;
    this -> writeToFile();
}

std::vector <Dog> Repository::getDogs() {
    return this -> dogs;
}

void Repository::readFromFile()
{
    std::ifstream fi(this->filename);

    std::string breed, name, photograph;
    int age;

    while (fi >> breed >> name >> age >> photograph)
        this -> dogs.push_back(Dog{breed, name, age, photograph});

    fi.close();
}

void Repository::writeToFile()
{
    std::ofstream fo(this->filename);

    for (auto d: this -> dogs)
        fo << d.getBreed() << " " << d.getName() << " " << d.getAge() << " " << d.getPhotograph() << "\n";

    fo.close();
}
