//
//  domain.hpp
//  Partial
//
//  Created by Andrei Blaj on 4/12/17.
//  Copyright © 2017 Andrei Blaj. All rights reserved.
//

#ifndef domain_hpp
#define domain_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class Robot {
public:
    Robot(int x, int y);
private:
    int x, y;
public:
    Robot() {}
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
};

#endif /* domain_hpp */
