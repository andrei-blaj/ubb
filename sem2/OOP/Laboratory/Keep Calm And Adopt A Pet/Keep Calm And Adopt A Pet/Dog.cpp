#include "Dog.hpp"
#include <iostream>
#include <vector>
#include "Utils.hpp"

using namespace std;

Dog::Dog() : breed(""), name(""), age(Age()), photograph("") {}

Dog::Dog(const std::string& breed, const std::string& name, const Age& age, const std::string& photograph)
{
    this->breed = breed;
    this->name = name;
    this->age = age;
    this->photograph = photograph;
}

Dog::Dog(const Dog& d)
{
    this->breed = d.breed;
    this->name = d.name;
    this->age = d.age;
    this->photograph = d.photograph;
}

void Dog::showPhotograph()
{
    string command = "open " + this->getPhotograph();
    system(command.c_str());
}

istream & operator >> (istream & is, Dog & d)
{
    string line;
    getline(is, line);
    
    vector<string> tokens = tokenize(line, ',');
    if (tokens.size() != 4) // make sure all the starship data was valid
        return is;
    
    d.breed = tokens[0];
    d.name = tokens[1];
    
    // get Age
    vector<string> ageTokens = tokenize(tokens[2], ' ');
    if (ageTokens.size() != 3)
        return is;
    d.age = Age{stoi(ageTokens[0]), stoi(ageTokens[1]), stoi(ageTokens[2]) };
    
    d.photograph = tokens[3];
    
    return is;
}

ostream & operator<<(ostream & os, const Dog & d)
{
    os << d.breed << "," << d.name << "," << d.age.getYears() << " " << d.age.getMonths() << " " << d.age.getDays() << "," << d.photograph << "\n";
    return os;
}
