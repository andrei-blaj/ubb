//
//  Controller.cpp
//  OOP May 10th 2017
//
//  Created by Andrei-Sorin Blaj on 10/05/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#include "Controller.hpp"

vector <Painting> Controller::get_paintings() {
    return this -> repository.get_paintings();
}

vector <Painting> Controller::get_special_paintings() {
    return this -> repository.get_special_paintings();
}

void Controller::add_painting(Painting painting) {
    
    if (find_painting(painting) != -1)
        return;
    
    if (isSpecial(painting))
        repository.add_special_painting(painting);
    else
        repository.add_painting(painting);
    
}

void Controller::remove_painting(Painting painting) {
    
    if (find_painting(painting) == -1)
        return;
    
    repository.remove_painting(painting);
    
}


bool Controller::isSpecial(Painting painting) {
    return repository.isSpecial(painting);
}
