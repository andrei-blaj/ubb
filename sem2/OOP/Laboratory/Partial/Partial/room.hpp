//
//  room.hpp
//  Partial
//
//  Created by Andrei Blaj on 4/12/17.
//  Copyright © 2017 Andrei Blaj. All rights reserved.
//

#ifndef room_hpp
#define room_hpp

#include <stdio.h>
#define nmax 10001
#define mmax 10001

class Room {
public:
    Room(int n, int m);
private:
    int n, m;
public:
    Room() {}
    int getN();
    int getM();
    void setN(int n);
    void setM(int m);
};

#endif /* room_hpp */
