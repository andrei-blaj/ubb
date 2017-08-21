//
//  HTMLFileUser.hpp
//  Keep Calm And Adopt A Pet
//
//  Created by Andrei-Sorin Blaj on 17/05/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#ifndef HTMLFileUser_hpp
#define HTMLFileUser_hpp

#include "FileUser.hpp"

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class HTMLFileUser: public FileUser {
public:
    void writeToFile() override;
    void openFile() override;
};

#endif /* HTMLFileUser_hpp */
