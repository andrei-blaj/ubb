//
//  Controller.hpp
//  Keep Calm And Adopt A Pet
//
//  Created by Andrei-Sorin Blaj on 16/04/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include "../repo/Repository.hpp"
#include "../models/Dog.hpp"
#include "../models/User.hpp"
#include "../models/FileUser.hpp"

#include <iostream>
#include <vector>

class Controller {
private:
    Repository repository;
    User user;
    FileUser *adoptionList;
public:
    bool add_dog(Dog dog);
    void remove_dog(Dog dog);
    bool update_dog(Dog old_dog, Dog new_dog);
    
    void set_adoption(FileUser adoptionList);
    
    int find_dog(Dog dog);
  
    vector <Dog> get_dogs();
    vector <Dog> get_user_adoptions();
    
    void add_dog_to_adoption(Dog dog);
    
    void openAdoptionlist() const;
    
    int adopt(int index);
};


#endif /* Controller_hpp */
