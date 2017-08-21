//
//  Domain.hpp
//  OOP May 10th 2017
//
//  Created by Andrei-Sorin Blaj on 10/05/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#ifndef Domain_hpp
#define Domain_hpp

#include <iostream>
#include <sstream>
#include <cstring>

#include "SpecialPainting.hpp"

using namespace std;

class Painting : public SpecialPainting {
public:
    Painting(string title, string artist, int year, bool special, double temperature);
    Painting();
    ~Painting();
private:
    string title;
    string artist;
    int year; // Year that it was finished
    bool special;
    
public:
    string get_title() const;
    string get_artist() const;
    int get_year() const;
    bool get_special() const;
    //int get_preservation_temperature() { return this-> preservation_temperature; };
    
    void set_title(string title) { this -> title = title; };
    void set_artist(string artist) { this -> artist = artist; };
    void set_year(int year) { this -> year = year; };
    void set_special(bool special) { this -> special = special; };
    //void set_preservation_temperature(int preservation_temperature) { this -> preservation_temperature = preservation_temperature; };
    
    string toString();
    bool isSpecial();
    
};

inline bool operator==(const Painting &a, const Painting &b) {
    
    bool equal = a.get_title() == b.get_title();
    equal &= a.get_artist() == b.get_artist();
    equal &= a.get_year() == b.get_year();
    equal &= a.get_special() == b.get_special();
    
    return equal;
}

#endif /* Domain_hpp */
