//
//  Controller.hpp
//  OOP May 10th 2017
//
//  Created by Andrei-Sorin Blaj on 10/05/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include "../repository/Repository.hpp"
#include "../models/Domain.hpp"
#include "../models/SpecialPainting.hpp"

#include <iostream>
#include <vector>

class Controller {
private:
    Repository repository;
public:
    void add_painting(Painting painting);
    void remove_painting(Painting painting);
    void add_special_painting(Painting painting);
    
    int find_painting(Painting painting);
    bool isSpecial(Painting painting);
    
    vector <Painting> get_paintings();
    vector <Painting> get_special_paintings();
    
};


#endif /* Controller_hpp */
