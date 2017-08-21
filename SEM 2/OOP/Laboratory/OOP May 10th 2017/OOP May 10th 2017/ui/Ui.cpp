//
//  Ui.cpp
//  OOP May 10th 2017
//
//  Created by Andrei-Sorin Blaj on 10/05/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#include "Ui.hpp"



void Ui::run() {
    
    string command;
    
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
            
            Ui::move();
            
        } else if (command == "list") {
            // List all the dogs in the database
            
            Ui::save();
            
        } else if (command == "exit") {
            
            cout << "Exiting...\n";
            return;
            
        } else {
            // invalid command
            cout << "> Invalid command.\n";
        }
        
    }
    
    
}

void Ui::add() {
    
    string title;
    string artist;
    int year;
    bool special;
    double temperature = 0;
    
    cout << "> Adding a new painting...\n";
    cout << "> Insert title: ";
    cin >> title;
    cout << "> Insert artist: ";
    cin >> artist;
    cout << "> Insert year: ";
    cin >> year;
    cout << "> Is the painting special (1/0): ";
    cin >> special;
    
    if (special) {
        cout << "> Insert temperature: ";
        cin >> temperature;
    }

    controller.add_painting(Painting(title, artist, year, special, temperature));
    
}

void Ui::remove() {
    
    string title;
    string artist;
    int year;
    bool special;
    double temperature = 0;
    
    cout << "> Removing a new painting...\n";
    cout << "> Insert title: ";
    cin >> title;
    cout << "> Insert artist: ";
    cin >> artist;
    cout << "> Insert year: ";
    cin >> year;
    cout << "> Is the painting special (1/0): ";
    cin >> special;
    
    if (special) {
        cout << "> Insert temperature: ";
        cin >> temperature;
    }

    controller.remove_painting(Painting(title, artist, year, special, temperature));
    
}

void Ui::move() {
    
}

void Ui::save() {
    
}


















