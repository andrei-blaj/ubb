//
//  HTMLFileUser.cpp
//  Keep Calm And Adopt A Pet
//
//  Created by Andrei-Sorin Blaj on 17/05/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#include "HTMLFileUser.hpp"

void HTMLFileUser::writeToFile() {
    
    ofstream fo("data/adoptions.html");
    
    string breed, name, photograph;
    int age;
    
    fo << "<!DOCTYPE html>\n";
    fo << "<html>\n";
    fo << "<head>\n";
    fo << "<title>Adoption list</title>\n";
    fo << "</head>\n";
    fo << "<body>\n";
    fo << "<center>\n";
    fo << "<table border='1'>\n";
    
    int len = (int) this->get_user_adoptions().size();
    
    for (int i = 0; i < len; i++) {
        breed = this->get_user_adoptions()[i].get_breed();
        name = this->get_user_adoptions()[i].get_name();
        age = this->get_user_adoptions()[i].get_age();
        photograph = this->get_user_adoptions()[i].get_photograph();
        
        fo << "<tr>\n";
        fo << "<td> " + breed + " </td>\n";
        fo << "<td> " + name + " </td>\n";
        fo << "<td> " + to_string(age) + " </td>\n";
        fo << "<td><a href='" + photograph + "'> Link </a></td>\n";
        fo << "</tr>\n";
    }
    
    fo << "</table>\n";
    fo << "</center>\n";
    fo << "</body>\n";
    fo << "</html>\n";

}

void HTMLFileUser::openFile() {
    
    string command = "open data/adoptions.html";
    
    system(command.c_str());
    
}
