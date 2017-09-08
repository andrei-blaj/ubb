//
//  repository.hpp
//  Partial
//
//  Created by Andrei Blaj on 4/12/17.
//  Copyright © 2017 Andrei Blaj. All rights reserved.
//

#ifndef repository_hpp
#define repository_hpp

#include <stdio.h>
#include "domain.hpp"
#include "room.hpp"
#include <vector>

using namespace std;

class Repository {
private:
    Robot robot;
    Room room;
    vector <Robot> postitions;
public:
    
    Repository() {}
    void setNM(int n, int m);
    void setXY(int x, int y);
    void addCleanPos(Robot pos);
    bool checkIfClean(Robot pos);
    int getLeftTiles(int n, int m);
    int getRightTiles(int n, int m);
    void showCleaned();
    vector <Robot> get_pos();
    Robot get_robot();
    Room get_room();
};

#endif /* repository_hpp */
