//
//  User.cpp
//  Keep Calm And Adopt A Pet
//
//  Created by Andrei-Sorin Blaj on 18/04/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#include "User.hpp"

vector <Dog> User::get_user_adoptions() {
    return this -> adoption_list;
}

void User::add(Dog dog) {
    // Adds a new dog to the adotion list
    this -> adoption_list.push_back(dog);
}
