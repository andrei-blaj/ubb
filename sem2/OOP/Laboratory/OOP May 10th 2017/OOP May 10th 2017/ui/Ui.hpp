//
//  Ui.hpp
//  OOP May 10th 2017
//
//  Created by Andrei-Sorin Blaj on 10/05/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#ifndef Ui_hpp
#define Ui_hpp

#include "../controller/Controller.hpp"

#include <iostream>
#include <vector>

class Ui {
private:
    Controller controller;
public:
    void run();
    
    void show_menu();
    
    void add();
    void remove();
    void move();
    void save();
    
};

#endif /* Ui_hpp */
