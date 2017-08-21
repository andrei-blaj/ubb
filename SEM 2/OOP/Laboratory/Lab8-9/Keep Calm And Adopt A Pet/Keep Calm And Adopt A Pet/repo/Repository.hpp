//
//  Repository.hpp
//  Keep Calm And Adopt A Pet
//
//  Created by Andrei-Sorin Blaj on 16/04/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#ifndef Repository_hpp
#define Repository_hpp

#include "../models/Dog.hpp"

#include <iostream>
#include <vector>

using namespace std;

class Repository {
private:
    vector <Dog> dogs;
public:
    bool add_dog(Dog dog);
    bool remove_dog(Dog dog);
    bool update_dog(Dog old_dog, Dog new_dog);
    
    int find_dog(Dog dog);
    int get_population();
    
    vector <Dog> get_dogs();
    vector <Dog> get_user_adoptions();
    
};

vector <Dog> operator+(vector <Dog> &v, const Dog &dog);
vector <Dog> operator+(const Dog &dog, vector <Dog> &v);
vector <Dog> operator-(vector <Dog> &v, const Dog &dog);

#endif /* Repository_hpp */
