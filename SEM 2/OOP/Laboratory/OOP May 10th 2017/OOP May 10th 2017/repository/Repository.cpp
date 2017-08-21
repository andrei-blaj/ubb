//
//  Repository.cpp
//  OOP May 10th 2017
//
//  Created by Andrei-Sorin Blaj on 10/05/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#include "Repository.hpp"

vector <Painting> Repository::get_paintings() {
    return this -> paintings;
}

vector <Painting> Repository::get_special_paintings() {
    return this -> special_paintings;
}

void Repository::add_painting(Painting painting) {
    
    this -> paintings = this -> paintings + painting;

}

void Repository::remove_painting(Painting painting) {
    
    this -> paintings = this -> paintings - painting;
    
}

void Repository::add_special_painting(Painting painting) {
    
    this -> special_paintings = this -> special_paintings + painting;
    
}

int Repository::find_painting(Painting painting) {
    for (int i = 0; i < (int) this -> paintings.size(); i++)
        if (this -> paintings[i] == painting)
            return i;
    
    return -1;
}

bool Repository::isSpecial(Painting painting) {
    return painting.isSpecial();
}

vector <Painting> operator+(vector <Painting> &v, const Painting &painting) {
    
    v.push_back(painting);
    
    return v;
}

vector <Painting> operator+(const Painting &painting, vector <Painting> &v) {
    
    v.push_back(painting);
    
    return v;
}

vector <Painting> operator-(vector <Painting> &v, const Painting &painting) {
    
    v.erase( remove(v.begin(), v.end(), painting), v.end());
    return v;
    
}
