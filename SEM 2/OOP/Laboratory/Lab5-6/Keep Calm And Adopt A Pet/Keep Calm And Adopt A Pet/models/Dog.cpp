//
//  Dog.cpp
//  Keep Calm And Adopt A Pet
//
//  Created by Andrei-Sorin Blaj on 16/04/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#include "Dog.hpp"
#include <iostream>
#include <cstring>
#include <sstream>

Dog::Dog(string breed, string name, int age, string photograph) {
    this -> breed = breed;
    this -> name = name;
    this -> age = age;
    this -> photograph = photograph;
}

Dog::Dog() {
    this -> breed = "";
    this -> name = "";
    this -> age = 0;
    this -> photograph = "";
}

string Dog::get_name() const {
    // Returns the name of the dog
    return this -> name;
}

string Dog::get_breed() const {
    // Returns the breed of the dog
    return this -> breed;
}

string Dog::get_photograph() const {
    // Returns the photograph of the dog
    return this -> photograph;
}

int Dog::get_age() const {
    // Returns the age of the dog
    return this -> age;
}

void Dog::set_breed(string breed) {
    // Sets the breed of the dog
    this -> breed = breed;
}

void Dog::set_name(string name) {
    // Sets the name of the dog
    this -> name = name;
}

void Dog::set_photograph(string photograph) {
    // Sets the photograph of the dog
    this -> photograph = photograph;
}

void Dog::set_age(int age) {
    // Sets the age of the dog
    this -> age = age;
}

string Dog::convert() {
    ostringstream output;
    
    output << "\\ Breed: " << this -> breed << "\n";
    output << "> Name : " << this -> name << "\n";
    output << "> Age  : " << this -> age << "\n";
    output << "/ Photo: " << this -> photograph << "\n";
    
    return output.str();
}



