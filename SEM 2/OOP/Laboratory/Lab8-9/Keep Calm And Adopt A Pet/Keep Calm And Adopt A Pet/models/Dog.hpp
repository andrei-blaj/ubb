//
//  Dog.hpp
//  Keep Calm And Adopt A Pet
//
//  Created by Andrei-Sorin Blaj on 16/04/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#ifndef Dog_hpp
#define Dog_hpp

#include <iostream>
#include <cstring>

using namespace std;

class Dog {
    
public:
    Dog(string breed, string name, int age, string photograph);
    Dog();

private:
    string breed;
    string name;
    int age;
    string photograph;
    
public:
    string get_breed() const;
    string get_name() const;
    string get_photograph() const;
    int get_age() const;
    
    void set_breed(string breed);
    void set_name(string name);
    void set_photograph(string photograph);
    void set_age(int age);
    
    string convert();
    
};

inline bool operator==(const Dog &a, const Dog &b) {
    
    bool equal = a.get_breed() == b.get_breed();
    equal &= a.get_age() == b.get_age();
    equal &= a.get_photograph() == b.get_photograph();
    equal &= a.get_name() == b.get_name();
    
    return equal;
}

#endif /* Dog_hpp */
