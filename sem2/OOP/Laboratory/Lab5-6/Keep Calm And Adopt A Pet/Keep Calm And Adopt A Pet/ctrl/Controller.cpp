//
//  Controller.cpp
//  Keep Calm And Adopt A Pet
//
//  Created by Andrei-Sorin Blaj on 16/04/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#include "Controller.hpp"
#include "../repo/Repository.hpp"
#include "../models/Dog.hpp"
#include "../models/User.hpp"
#include "../models/FileUser.hpp"
#include "../models/CSVFileUser.hpp"
#include "../models/HTMLFileUser.hpp"

#include <iostream>
#include <vector>

using namespace std;

vector <Dog> Controller::get_dogs() {
    // Returns the list of dogs in the repository
    return this -> repository.get_dogs();
}

bool Controller::add_dog(Dog dog) {
    // Adds a dog to the repository
    return this -> repository.add_dog(dog);
}

void Controller::remove_dog(Dog dog) {
    // Removes a dog from the repository
    this -> repository.remove_dog(dog);
}

int Controller::find_dog(Dog dog) {
    // Returns an index of the dog in the repository
    // -1 if the dog does not exist
    return this -> repository.find_dog(dog);
}

bool Controller::update_dog(Dog old_dog, Dog new_dog) {
    // Updates a dog with new information given by the user
    return this -> repository.update_dog(old_dog, new_dog);
}

vector <Dog> Controller::get_user_adoptions() {
    // Returns the adoption list of current user
    return this -> user.get_user_adoptions();
}

void Controller::add_dog_to_adoption(Dog dog) {
    // Adds a new dog to the adoption list
    this -> user.add(dog);
}

int Controller::adopt(int index) {
    
    //  Add the current dog to the adoption list
    Controller::add_dog_to_adoption(Controller::get_dogs()[index]);
    //  Remove the current dog from the list
    this -> Controller::remove_dog(Controller::get_dogs()[index]);
    
    int len = (int) Controller::get_dogs().size();
    
    return len;
    
}

void Controller::openAdoptionlist() const
{
    if (this->adoptionList == nullptr)
        return;
    
    this->adoptionList->writeToFile();
}

void Controller::set_adoption(FileUser adoptionList) {
    this -> adoptionList = &adoptionList;
}
