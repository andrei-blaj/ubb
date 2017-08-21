//
//  User.hpp
//  Keep Calm And Adopt A Pet
//
//  Created by Andrei-Sorin Blaj on 18/04/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#ifndef User_hpp
#define User_hpp

#include "Dog.hpp"

#include <iostream>
#include <vector>

using namespace std;

class User {
protected:
    vector <Dog> adoption_list;
public:
    vector <Dog> get_user_adoptions();
    void add(Dog dog);
};

#endif /* User_hpp */
