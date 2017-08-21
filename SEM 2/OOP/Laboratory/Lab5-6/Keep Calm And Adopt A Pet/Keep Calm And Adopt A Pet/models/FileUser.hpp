//
//  FileUser.hpp
//  Keep Calm And Adopt A Pet
//
//  Created by Andrei-Sorin Blaj on 17/05/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#ifndef FileUser_hpp
#define FileUser_hpp

#include "User.hpp"

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class FileUser: public User {
public:
    virtual void writeToFile() = 0;
    virtual void openFile() = 0;
};

#endif /* FileUser_hpp */
