//
//  CSVFileUser.cpp
//  Keep Calm And Adopt A Pet
//
//  Created by Andrei-Sorin Blaj on 17/05/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#include "CSVFileUser.hpp"
#include <fstream>
#include <cstring>

void CSVFileUser::writeToFile() {
    
    ofstream fo("data/adoptions.csv");
    
    string breed, name, photograph;
    int age;
    
    int len = (int) this->get_user_adoptions().size();
    
    for (int i = 0; i < len; i++) {
        breed = this->get_user_adoptions()[i].get_breed();
        name = this->get_user_adoptions()[i].get_name();
        age = this->get_user_adoptions()[i].get_age();
        photograph = this->get_user_adoptions()[i].get_photograph();
        
        fo << breed + ", " + name + ", " + to_string(age) + ", " + photograph + "\n";
        
    }
    
    fo.close();
    
    openFile();
    
}

void CSVFileUser::openFile() {
    
    string command = "open data/adoptions.csv";
    
    system(command.c_str());
}
