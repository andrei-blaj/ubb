//
//  controller.hpp
//  Partial
//
//  Created by Andrei Blaj on 4/12/17.
//  Copyright © 2017 Andrei Blaj. All rights reserved.
//

#ifndef controller_hpp
#define controller_hpp

#include <stdio.h>
#include "repository.hpp"
#include "domain.hpp"

using namespace std;

class Controller {
private:
    Repository repo;
public:
    Controller() {}
    void setNM(int n, int m);
    Repository get_repo();
    void updateRobot(int x, int y);
    int getLeftTiles(int n, int m);
    int getRightTiles(int n, int m);
    int getPercentage(int x, int y);
    bool checkIfClean(Robot r);
    void addPosition(Robot r);
    void showCleaned();
};

#endif /* controller_hpp */
