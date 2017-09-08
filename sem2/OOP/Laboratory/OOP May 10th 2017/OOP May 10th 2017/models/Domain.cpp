//
//  Domain.cpp
//  OOP May 10th 2017
//
//  Created by Andrei-Sorin Blaj on 10/05/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#include <iostream>
#include "Domain.hpp"

Painting::Painting(string title, string artist, int year, bool special, double temperature) {
    this -> title = title;
    this -> artist = artist;
    this -> year = year;
    this -> special = special;
    this -> temperature = temperature;
    //this -> preservation_temperature = preservation_temperature;
}

Painting::~Painting() {}

string Painting::get_title() const {
    return this -> title;
}

string Painting::get_artist() const {
    return this->artist;
}

int Painting::get_year() const {
    return this -> year;
}

bool Painting::get_special() const {
    return this -> special;
}

string Painting::toString() {
    ostringstream output;
    
    output << "\\ Title: " << this -> title << "\n";
    output << "> Artist : " << this -> artist << "\n";
    output << "> Year : " << this -> year << "\n";
    //output << "/ Preservation temperature: " << this -> preservation_temperature << "\n";
    
    return output.str();
}

bool Painting::isSpecial() {
    // 1 => it is a special painting
    // 0 => it is a normal paining
    return this -> special;
}
