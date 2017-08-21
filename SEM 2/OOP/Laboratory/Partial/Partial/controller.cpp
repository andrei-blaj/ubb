//
//  controller.cpp
//  Partial
//
//  Created by Andrei Blaj on 4/12/17.
//  Copyright © 2017 Andrei Blaj. All rights reserved.
//

#include "controller.hpp"
#include "repository.hpp"
#include "domain.hpp"

using namespace std;

Repository Controller::get_repo() {
    return this->repo;
}

// Set the N and M variables int the Room class
void Controller::setNM(int n, int m) {
    this->repo.setNM(n, m);
}

// Check to see if a tile is clean
bool Controller::checkIfClean(Robot r) {
    return this->repo.checkIfClean(r);
}

// Adds a clean tile to the repository
void Controller::addPosition(Robot r) {
    this -> repo.addCleanPos(r);
}

// Updates the robot's coordinates
void Controller::updateRobot(int x, int y) {
    this -> repo.setXY(x, y);
}

// Shows cleaned tiles
void Controller::showCleaned() {
    this -> repo.showCleaned();
}

// returns the number of clean tiles in the left half
int Controller::getLeftTiles(int n, int m) {
    return this -> repo.getLeftTiles(n, m);
}

// returns the number of clean tiles in the right half
int Controller::getRightTiles(int n, int m) {
    return this -> repo.getRightTiles(n, m);
}

// returns the percentage of a half
int Controller::getPercentage(int x, int y) {
    return int(x * 100 / y);
}
