//
//  SpecialPainting.hpp
//  OOP May 10th 2017
//
//  Created by Andrei-Sorin Blaj on 10/05/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#ifndef SpecialPainting_hpp
#define SpecialPainting_hpp

#include <iostream>

using namespace std;

class SpecialPainting {
public:
    double temperature;

public:
    double get_temp() { return this -> temperature; };
    
    void set_temp(double temperature) { this -> temperature = temperature; };
    
};

#endif /* SpecialPainting_hpp */
