//
//  ui.cpp
//  Partial
//
//  Created by Andrei Blaj on 4/12/17.
//  Copyright © 2017 Andrei Blaj. All rights reserved.
//

#include "ui.hpp"
#include "controller.hpp"
#include <iostream>
#include <cstring>
#include "domain.hpp"

using namespace std;

void printMenu() {
    cout << "> Available commands: \n";
    cout << ">    move up\n";
    cout << ">    move down\n";
    cout << ">    move left\n";
    cout << ">    move right\n";
    cout << ">    show cleaned\n";
    cout << ">    show percentage\n";
    cout << ">    exit\n";
}

Controller UI::get_controller() {
    return this->controller;
}

void UI::run() {
    // Starting the application
    
    int n, m, xr, yr;
    int x, y;
    
    cout << "> Insert n: ";
    cin >> n;
    
    cout << "> Insert m: ";
    cin >> m;
    
    cout << "> Insert xr: ";
    cin >> xr;
    
    cout << "> Insert yr: ";
    cin >> yr;
    
    this->controller.setNM(n, m);
    
    string command;
    
    cout << "> Welcome\n";
    printMenu();
    
    while (1) {
        
        cout << "> ";
        getline(cin, command);
        
        if (command == "move up") {
            
            // get the position of the robot
            x = getXPosition();
            y = getYPosition();
            // check if it can go up and that it has not already cleaned
            // that area
            
            bool ok = this->controller.checkIfClean(Robot(x, y+1));
            
            // in case it can, get the y coord, increase by 1
            
            if (y + 1 > n) {
                cout << "> Robot cannot move up.";
                continue;
            }
            
            if (ok == 1) {
                cout << "> Area already cleaned.";
                continue;
            }
            
            y += 1;
            
            this->controller.addPosition(Robot(x, y+1));
            
            this->controller.updateRobot(x, y+1);
            
            // else display "> Robot cannot move up"
            
        } else if (command == "move down") {
            
            // get the position of the robot
            x = getXPosition();
            y = getYPosition();
            // check if it can go down and that it has not already cleaned
            
            bool ok = this->controller.checkIfClean(Robot(x, y-1));
            
            if (y - 1 < 0) {
                cout << "> Robot cannot move up.";
                continue;
            }
            
            if (ok == 1) {
                cout << "> Area already cleaned.";
                continue;
            }
            
            y -= 1;
            
            this->controller.addPosition(Robot(x, y-1));
            
            this->controller.updateRobot(x, y-1);
            
            // that area
            // in case it can, get the y coord, decrease by 1
            // else display "> Robot cannot move down"
            
        } else if (command == "move right") {
            
            // get the position of the robot
            x = getXPosition();
            y = getYPosition();
            // check if it can go right and that it has not already cleaned
            
            bool ok = this->controller.checkIfClean(Robot(x+1, y));
            
            if (x + 1 > m) {
                cout << "> Robot cannot move up.";
                continue;
            }
            
            if (ok == 1) {
                cout << "> Area already cleaned.";
                continue;
            }
            
            x += 1;
            
            this->controller.addPosition(Robot(x+1, y));
            
            this->controller.updateRobot(x+1, y);
            
            // that area
            // in case it can, get the x coord, increase by 1
            // else display "> Robot cannot move right"
            
        } else if (command == "move left") {
            
            // get the position of the robot
            x = getXPosition();
            y = getYPosition();
            // check if it can go left and that it has not already cleaned
            
            bool ok = this->controller.checkIfClean(Robot(x-1, y));
            
            if (x - 1 < 0) {
                cout << "> Robot cannot move up.";
                continue;
            }
            
            if (ok == 1) {
                cout << "> Area already cleaned.";
                continue;
            }
            
            x -= 1;
            
            this->controller.addPosition(Robot(x-1, y));
            
            this->controller.updateRobot(x-1, y);
            
            // that area
            // in case it can, get the y coord, decrease by 1
            // else display "> Robot cannot move left"
            
        } else if (command == "show cleaned") {
            
            cout << "> Clean tiles:\n";
            this -> controller.showCleaned();
            
        } else if (command == "show percentage") {
            
            // find how many tiles are in the left half (0, n/2), (0, m)
            // find how many tiles are in the right half (n/2+1, n), (0, m)
            
            int leftTiles, rightTiles;
            int leftP, rightP;
            
            leftTiles = this->controller.getLeftTiles(n, m);
            rightTiles = this->controller.getRightTiles(n, m);
            
            leftP = this->controller.getPercentage(leftTiles, m*(n/2));
            rightP = this->controller.getPercentage(rightTiles, m*(n/2));
            
            cout << "> Left half: " + to_string(leftP) + "\n";
            cout << "> Right half: " + to_string(rightP) + "\n";
            
            if (leftP < rightP) {
                cout << "> The Robot has more tiles to clean in the left half";
            } else {
                cout << "> The Robot has more tiles to clean in the right half";
            }
            
        } else if (command == "exit") {
            cout << "> Exiting...\n";
            break;
        } else {
            cout << "> Invalid command.\n";
        }
    }
    
}


