//
//  domain.cpp
//  Partial
//
//  Created by Andrei Blaj on 4/12/17.
//  Copyright © 2017 Andrei Blaj. All rights reserved.
//

#include "domain.hpp"
#include <vector>

using namespace std;

Robot::Robot(int x, int y){
    this -> x = x;
    this -> y = y;
}

void Robot::setX(int x) {
    this -> x = x;
}

void Robot::setY(int y) {
    this -> y = y;
}

int Robot::getX() {
    return this -> x;
}

int Robot::getY() {
    return this -> y;
}
