//
//  Repository.hpp
//  OOP May 10th 2017
//
//  Created by Andrei-Sorin Blaj on 10/05/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#ifndef Repository_hpp
#define Repository_hpp

#include <iostream>
#include <vector>
#include "../models/Domain.hpp"

class Repository {
private:
    vector <Painting> paintings;
    vector <Painting> special_paintings;
    
public:
    void add_painting(Painting painting);
    void remove_painting(Painting painting);
    void add_special_painting(Painting painting);
    
    void move_painting(Painting painting);
    
    int find_painting(Painting painting);
    bool isSpecial(Painting painting);
    
    vector <Painting> get_paintings();
    vector <Painting> get_special_paintings();
    
};

vector <Painting> operator+(vector <Painting> &v, const Painting &painting);
vector <Painting> operator+(const Painting &painting, vector <Painting> &v);
vector <Painting> operator-(vector <Painting> &v, const Painting &painting);

#endif /* Repository_hpp */
