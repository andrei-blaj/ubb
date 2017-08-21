//
//  Ui.hpp
//  Keep Calm And Adopt A Pet
//
//  Created by Andrei-Sorin Blaj on 16/04/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#ifndef Ui_hpp
#define Ui_hpp

#include "../ctrl/Controller.hpp"
#include "../models/Dog.hpp"

#include <iostream>
#include <vector>

class Ui {
private:
    Controller controller;
public:
    void run();
    void load_file();
    
    void run_admin();
    void run_user();
    
    void admin_menu();
    void user_menu();
    
    void add();
    void remove();
    void update();
    void list_all();
    
    void load_csv();
    void load_html();
    
    void adopt();
    void filter();
    void list_adoptions();
    
    void csv_format(int len);
    void html_format(int len);
    
};

#endif /* Ui_hpp */
