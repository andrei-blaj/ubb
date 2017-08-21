//
//  Tests.cpp
//  Keep Calm And Adopt A Pet
//
//  Created by Andrei-Sorin Blaj on 20/04/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

#include "Tests.hpp"
#include "../models/Dog.hpp"
#include "../repo/Repository.hpp"

#include <iostream>
#include <cassert>

using namespace std;

void Test::test_models() {
    
    Dog *a = new Dog("Beagle", "Lucky", 5, "no_photograph");
    
    assert(a->get_breed() == "Beagle");
    assert(a->get_name() == "Lucky");
    assert(a->get_age() == 5);
    assert(a->get_photograph() == "no_photograph");
    
    a->set_breed("Pitbull");
    
    assert(a->get_breed() != "Beagle");
    assert(a->get_breed() == "Pitbull");
    
    Dog *b = a;
    
    b->set_age(1);
    
    assert(b->get_age() == 1);  // a and b point to the same object
    assert(a->get_age() == 1);  // so both ages should be 1
    
    Dog c = *a;
    
    c.set_age(100);
    
    assert(c.get_age() == 100); // this should change the age of c
    assert(a->get_age() == 1);  // but not the age of a
    
    
    Dog *d = new Dog();
    *d = *a;                    // this should be a copy
    
    d->set_age(99);
    
    assert(d->get_age() == 99); // the copy should be 99
    assert(a->get_age() == 1);  // the original should stay the same
    
    d->set_photograph("some_photograph");
    
    assert(a->get_photograph() == "no_photograph");
    assert(d->get_photograph() == "some_photograph");
    
}

void Test::test_repository() {
    Repository repo;
    
    Dog a{"Labrador", "Lucky", 5, "http://cdn2-www.dogtime.com/assets/uploads/gallery/labrador-retriever-dog-breed-pictures/labrador-retriever-dog-pictures-6.jpg"};
    
    Dog b{"Husky", "Buddy", 9, "https://siberianhusky.com/wp-content/uploads/2016/09/husky-pictures-4.jpg"};
    
    assert(repo.get_population() == 0);
    
    repo.add_dog(a);
    repo.add_dog(b);
    
    assert(repo.get_population() == 2);
    
    // REMOVE VALID / INVALID
 
    repo.remove_dog(a);
    
    assert(repo.get_population() == 1);
    
    assert(repo.find_dog(a) == -1);
    assert(repo.find_dog(b) == 0);
    
    repo.update_dog(b, a);
    
    assert(repo.find_dog(a) == 0);
    
}

void Test::test_everything() {
    this->test_models();
    this->test_repository();
}
