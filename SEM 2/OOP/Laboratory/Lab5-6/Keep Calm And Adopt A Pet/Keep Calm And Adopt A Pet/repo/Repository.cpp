//
//  Repository.cpp
//  Keep Calm And Adopt A Pet
//
//  Created by Andrei-Sorin Blaj on 16/04/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#include "Repository.hpp"
#include "../models/Dog.hpp"

#include <iostream>
#include <vector>

using namespace std;

vector <Dog> Repository::get_dogs() {
    return this -> dogs;
}

int Repository::get_population() {
    // Returns the length of the list of dogs
    return (int) this -> dogs.size();
}

bool Repository::add_dog(Dog dog) {
    // Adds a new dog to the repository
    // Returns 1 in case of success, 0 otherwise
    
    // 1. check to see if the dog already exists
    // 2. In case it does, return 0
    // 3. Otherwise add it to the repository
    
    if (find_dog(dog) != -1)
        return 0;
    
    this -> dogs = this -> dogs + dog;
    
    return 1;
}

void Repository::remove_dog(Dog dog) {
    // Removes a dog from the repository
    // Returns 1 in case of success, 0 otherwise
    
    // 1. check to see if the dog exists
    // 2. In case it doesn't, return 0
    // 3. Otherwise remove it from the repository
    
    if (find_dog(dog) == -1)
        throw std::runtime_error("> Inexitent Dog. ");
    
    this -> dogs = this -> dogs - dog;
    
}

int Repository::find_dog(Dog dog) {
    // Returns the index of a dog in the repository
    // -1 if such a dog does not exist
    
    for (int i = 0; i < (int)this->dogs.size(); i++)
        if (this->dogs[i] == dog)
            return i;
    
    return -1; // in case the dog is not in the repository
    
}

bool Repository::update_dog(Dog old_dog, Dog new_dog) {
    // Updates a dog's information in the repository
    // Returns 1 in case of success, 0 otherwise
    
    int index = find_dog(old_dog);
    
    if (index == -1)
        return 0;
    
    this -> dogs[index].set_breed(new_dog.get_breed());
    this -> dogs[index].set_name(new_dog.get_name());
    this -> dogs[index].set_age(new_dog.get_age());
    this -> dogs[index].set_photograph(new_dog.get_photograph());
    
    return 1;
    
}

vector <Dog> operator+(vector <Dog> &v, const Dog &dog) {
    
    v.push_back(dog);
    
    return v;
}

vector <Dog> operator+(const Dog &dog, vector <Dog> &v) {
    
    v.push_back(dog);
    
    return v;
}

vector <Dog> operator-(vector <Dog> &v, const Dog &dog) {
    
    v.erase( remove(v.begin(), v.end(), dog), v.end());
    return v;
    
}
