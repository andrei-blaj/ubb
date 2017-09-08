//
//  CSVFileUser.hpp
//  Keep Calm And Adopt A Pet
//
//  Created by Andrei-Sorin Blaj on 17/05/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#ifndef CSVFileUser_hpp
#define CSVFileUser_hpp

#include "FileUser.hpp"

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class CSVFileUser: public FileUser {
public:
    void writeToFile() override;
    void openFile() override;
};

#endif /* CSVFileUser_hpp */
