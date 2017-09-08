//
//  repository.cpp
//  Partial
//
//  Created by Andrei Blaj on 4/12/17.
//  Copyright © 2017 Andrei Blaj. All rights reserved.
//

#include "repository.hpp"
#include "domain.hpp"
#include "room.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <Robot> Repository::get_pos() {
    return this->postitions;
}

Robot Repository::get_robot() {
    return this->robot;
}

Room Repository::get_room() {
    return this->room;
}

void Repository::setNM(int n, int m) {
    this->room.setN(n);
    this->room.setM(m);
}

void Repository::setXY(int x, int y) {
    this->robot.setX(x);
    this->robot.setY(y);
}

void Repository::addCleanPos(Robot pos) {
    this->postitions.push_back(pos);
}

bool Repository::checkIfClean(Robot pos) {
    if(find(this->postitions.begin(), this->postitions.end(), pos) != this->postitions.end()) {
        // is clean
        return 1;
    } else {
        return 0;
    }
}

void Repository::showCleaned() {
    for (int i = 0; i < this->postitions.size(); i++) {
        int x = this->postitions[i].getX();
        int y = this->postitions[i].getY();
        
        cout << "> " + to_string(x) + ", " + to_string(y) + "\n";
    }
}

int Repository::getLeftTiles(int n, int m) {
    
    int leftTiles = 0;
    
    for (int i = 0; i < this->postitions.size(); i++) {
        int x = this->postitions[i].getX();
        
        if (x <= n/2) {
            leftTiles += 1;
        }
    }
    
    return leftTiles;
    
}

int Repository::getRightTiles(int n, int m) {
    
    int rightTiles = 0;
    
    for (int i = 0; i < this->postitions.size(); i++) {
        int x = this->postitions[i].getX();
        
        if (x <= n/2) {
            rightTiles += 1;
        }
    }
    
    return rightTiles;
    
}


