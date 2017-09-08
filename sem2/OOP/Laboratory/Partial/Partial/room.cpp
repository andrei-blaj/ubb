//
//  room.cpp
//  Partial
//
//  Created by Andrei Blaj on 4/12/17.
//  Copyright © 2017 Andrei Blaj. All rights reserved.
//

#include "room.hpp"

Room::Room(int n, int m) {
    this -> n = n;
    this -> m = m;
}

int Room::getN() {
    return this -> n;
}

int Room::getM() {
    return this -> m;
}

void Room::setM(int m) {
    this -> m = m;
}

void Room::setN(int n) {
    this -> n = n;
}



