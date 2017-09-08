//
//  Ui.cpp
//  Keep Calm And Adopt A Pet
//
//  Created by Andrei-Sorin Blaj on 16/04/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#include "Ui.hpp"
#include "../ctrl/Controller.hpp"
#include "../models/Dog.hpp"
#include "../models/User.hpp"
#include "../models/FileUser.hpp"
#include "../models/CSVFileUser.hpp"
#include "../models/HTMLFileUser.hpp"

#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

void Ui::load_file() {
    // Adding elements into the repository
    // from the text file located in data/dogs.txt
    
    ifstream fi("data/dogs.txt");
    
    string breed, name, photograph;
    int age;
    
    bool returnKey;
    
    while (fi >> breed >> name >> age >> photograph) {
        //fi >> breed >> name >> age >> photograph;
        returnKey = this -> controller.add_dog(Dog(breed, name, age, photograph));
    }
    
    // Done
}

void Ui::run() {
    
    load_file();
    
    string command = "";
    
    while (command != "admin" && command != "user") {
        cout << "> Run as (admin/user): ";
        getline(cin, command);
    }
    
    if (command == "admin") {
        // admin
        run_admin();
    } else {
        // user
        run_user();
    }
    
}

void Ui::admin_menu() {
    cout << "> Welcome to admin mode! \n";
    cout << "> You may choose to: \n";
    cout << ">     Add a dog. (add) \n";
    cout << ">     Remove a dog. (remove) \n";
    cout << ">     Update a dog. (update) \n";
    cout << ">     List dogs. (list) \n";
    cout << ">     Exit the applicaion. (exit) \n";
}

void Ui::user_menu() {
    cout << "> Welcome to user mode! \n";
    cout << "> You may choose to: \n";
    cout << ">     See dogs one by one and may choose to adopt. (adopt) \n";
    cout << ">     See your adoption list. (list) \n";
    cout << ">     See dogs of a given breed having the age less than a given number. (filter) \n";
    cout << ">     Exit the applicaion. (exit) \n";
}

void Ui::run_admin() {
    // admin mode
    
    string command;
    
    admin_menu();
    
    while (1) {
    
        // Admin may choose to:
        //      - Add dog
        //      - Remove dog
        //      - Update dog
        //      - List all dogs
    
        cout << "> ";
        cin >> command;
    
        if (command == "add") {
            // Adding a new dog
            
            Ui::add();
            
        } else if (command == "remove") {
            // Remove a dog
            
            Ui::remove();
        
        } else if (command == "update") {
            // Update a dog
            
            Ui::update();
            
        } else if (command == "list") {
            // List all the dogs in the database
            
            Ui::list_all();
            
        } else if (command == "exit") {
        
            cout << "Exiting...\n";
            return;
            
        } else {
            // invalid command
            cout << "> Invalid command.\n";
        }
        
    }
    
}

void Ui::run_user() {
    // user mode
    
    string command;
    
    user_menu();
    
    while (1) {
        
        // User may choose to:
        //      - Adopt a dog (Go through the database dog by dog and for each one
        //        the user may choose to adopt, skip or exit
        //      - See the adoption list
        //      - Filter dogs of a given breed with an age less than a given number
        
        cout << "> ";
        cin >> command;
        
        if (command == "adopt") {
            // Adding a new dog
            
            Ui::adopt();
            
        } else if (command == "filter") {
            // Remove a dog
            
            Ui::filter();
            
        } else if (command == "list") {
            // List all the dogs in the database
            
            Ui::list_adoptions();
            
        } else if (command == "exit") {
            
            cout << "> Exiting...\n";
            return;
            
        } else {
            // invalid command
            cout << "> Invalid command.\n";
        }
        
    }

}

void Ui::add() {
    // Adds a dog to the repository if no such a dog exists
    // Confirimation messages will be displayed
    
    string breed;
    string name;
    string photograph;
    int age;
    
    cout << "> Adding a new dog...\n";
    cout << "> Insert breed: ";
    cin >> breed;
    cout << "> Insert name: ";
    cin >> name;
    cout << "> Insert age: ";
    cin >> age;
    cout << "> Insert photograph: ";
    cin >> photograph;
    
    bool returnKey = this->controller.add_dog(Dog(breed, name, age, photograph));
    
    //cout << this->controller.find_dog(Dog(breed, name, age, photograph));
    
    if (returnKey == 1)
        cout << "> Addition successful!\n";
    else
        cout << "> Dog already exists!\n";

}

void Ui::remove() {
    // Removing a dog from the repository if such a dog exists
    // Confirimation messages will be displayed
    
    
    string breed;
    string name;
    string photograph;
    int age;
    
    cout << "> Removing a dog...\n";
    cout << "> Insert breed: ";
    cin >> breed;
    cout << "> Insert name: ";
    cin >> name;
    cout << "> Insert age: ";
    cin >> age;
    cout << "> Insert photograph: ";
    cin >> photograph;
    
    try {
        this->controller.remove_dog(Dog(breed, name, age, photograph));
        cout << "> Removal successful!\n";
    }
    catch(runtime_error &e) {
        cout << e.what() << "\n";
    }
    
    //cout << this->controller.find_dog(Dog(breed, name, age, photograph));
    
}

void Ui::update() {
    
    // Updating a dog from the repository if such a dog exists
    // Confirimation messages will be displayed
    
    string breed;
    string name;
    string photograph;
    int age;
    
    cout << "> Updating a dog...\n";
    cout << "> Insert breed: ";
    cin >> breed;
    cout << "> Insert name: ";
    cin >> name;
    cout << "> Insert age: ";
    cin >> age;
    cout << "> Insert photograph: ";
    cin >> photograph;
    
    bool returnKey = this->controller.find_dog(Dog(breed, name, age, photograph));
    
    if (!returnKey) {
        cout << "> Inexistent dog!\n";
        return;
    }
    
    string new_breed;
    string new_name;
    string new_photograph;
    int new_age;
    
    cout << "> Updating a dog...\n";
    cout << "> Insert new breed: ";
    cin >> new_breed;
    cout << "> Insert new name: ";
    cin >> new_name;
    cout << "> Insert new age: ";
    cin >> new_age;
    cout << "> Insert new photograph: ";
    cin >> new_photograph;
    
    returnKey = this->controller.update_dog(Dog(breed, name, age, photograph), Dog(new_breed, new_name, new_age, new_photograph));
    
    if (returnKey)
        cout << "> Update sucessful!\n";
    else
        cout << "> Update failed.\n";
    
}

void Ui::list_all() {
    // Lists all the dogs in the repository
 
    int len = (int) this->controller.get_dogs().size();
    
    if (len == 0) {
        cout << "> List is empty.\n";
        return;
    }
    
    cout << "> Dog list: \n";
    
    for (int i = 0; i < len; i++) {
        cout << "\n";
        cout << this->controller.get_dogs()[i].convert();
    }
    
    cout << "\n";
    
}

void Ui::adopt() {
    
    // Adopting a dog from the repository
    
    string command;
    string userFilter;
    
    int failsafe = 0;
    
    int len = (int) this -> controller.get_dogs().size();
    int index = 0;
    
    if (len == 0) {
        cout << "> Cannot adopt, no dogs available.\n";
        return;
    }
    
    cout << "> Available commands: \n";
    cout << ">      adopt\n";
    cout << ">      next\n";
    cout << ">      exit\n";
    
    cout << "> Insert the breed that you would like to filter or '.' to filter all: ";
    cin >> userFilter;
    
    while (1) {
        
        Dog d = this -> controller.get_dogs()[index];
        
        if (userFilter != "." && d.get_breed() != userFilter) {
            failsafe += 1;
            
            if (failsafe > len) {
                cout << "> No dogs have the specified breed.\n";
                break;
            }
            
            index += 1;
            index = index % len;
            continue;
        }
        
        failsafe = 0;
        
        cout << "\n";
        
        cout << this -> controller.get_dogs()[index].convert();
        
        cout << "> ";
        cin >> command;
        
        if (command == "adopt") {
            // Adopt a dog
            
            len = this -> controller.adopt(index);
            
            if (len == 0) {
                cout << "> No more available dogs!\n";
                return;
            }
            
            index %= len;
            
        } else if (command == "next") {
            // Next dog
            
            index += 1;
            index = index % len;
            
        } else if (command == "exit") {
            
            return;
            
        } else {
            // invalid command
            cout << "> Invalid command.\n";
        }

    }
    
}

void Ui::filter() {
    
    // Filtering dogs from the repository based on breed and age
    
    int len = (int) this->controller.get_user_adoptions().size();
    
    if (len == 0) {
        cout << "> Nothing to filter.\n";
        return;
    }
    
    string breed;
    int age;
    
    cout << "> Insert breed: ";
    cin >> breed;
    cout << "> Insert age: ";
    cin >> age;
    
    bool ok = true;
    
    for (int i = 0; i < len; i++) {
        string a_breed = controller.get_user_adoptions()[i].get_breed();
        int a_age = controller.get_user_adoptions()[i].get_age();
        if (ok && a_breed == breed && a_age < age) {
            ok = false;
            cout << "> Filtered data: \n";
            cout << "\n";
            cout << controller.get_user_adoptions()[i].convert() << "\n";
        } else if (a_breed == breed && a_age < age) {
            cout << "\n";
            cout << controller.get_user_adoptions()[i].convert() << "\n";
        }
    }
    
    if (ok == true)
        cout << "> No results.\n";
    
}

void Ui::list_adoptions() {
    
    // Printing the adoption list of the current user
    
    int len = (int) this->controller.get_user_adoptions().size();
    
    if (len == 0) {
        cout << "> No adoptions to show.\n";
        return;
    }
    
    cout << "> Please choose the format: \n";
    cout << "> 1. CSV\n";
    cout << "> 2. HTML\n";
    
    string format;
    
    while (format != "1" && format != "2") {
        cout << "> ";
        cin >> format;
    }
    
    FileUser * u = nullptr;
    
    if (format == "1")
        u = new CSVFileUser();
    else
        u = new HTMLFileUser();
    
    this->controller.set_adoption(*u);
    
    this->controller.openAdoptionlist();
   
    
//    cout << "> Adoption list for current user: \n";
//    for (int i = 0; i < len; i++) {
//        cout << "\n";
//        cout << this->controller.get_user_adoptions()[i].convert() << "\n";
//    }
    
}

