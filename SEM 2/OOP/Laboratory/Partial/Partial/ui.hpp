//
//  ui.hpp
//  Partial
//
//  Created by Andrei Blaj on 4/12/17.
//  Copyright © 2017 Andrei Blaj. All rights reserved.
//

#ifndef ui_hpp
#define ui_hpp

#include <stdio.h>
#include "controller.hpp"
#include "domain.hpp"

using namespace std;

class UI {
private:
    Controller controller;
    
public:
    UI() {}
    void run();
    int getXPosition();
    int getYPosition();
    Controller get_controller();
};

#endif /* ui_hpp */
