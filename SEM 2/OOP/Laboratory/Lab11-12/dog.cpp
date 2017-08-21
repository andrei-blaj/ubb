#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>

#include "dog.h"

Dog::Dog() : breed(""), name(""), age(0), photograph("") {}

Dog::Dog(const std::string &breed, const std::string &name, const int &age, const std::string &photograph)
{
    this -> breed = breed;
    this -> name = name;
    this -> age = age;
    this -> photograph = photograph;
}

Dog::Dog(const Dog &d)
{
    this -> breed = d.breed;
    this -> name = d.name;
    this -> age = d.age;
    this -> photograph = d.photograph;
}

void Dog::setName(const std::string &name)
{
    this -> name = name;
}

void Dog::setBreed(const std::string &breed)
{
    this -> breed = breed;
}

void Dog::setAge(const int &age)
{
    this -> age = age;
}

void Dog::setPhotograph(const std::string &photograph)
{
    this -> photograph = photograph;
}

std::string Dog::convert() {
    std::ostringstream output;

    output << "Breed: " << this -> breed;
    output << "\nName: " << this -> name;
    output << "\nAge: " << this -> age;
    //output << "\nPhoto: " << this -> photograph << "\n";

    return output.str();
}

/*
LOAD.TXT

Sharpei Max 4 http://2t4y703efn992y2nurahx0pb.wpengine.netdna-cdn.com/wp-content/uploads/2017/01/SharPei-1.jpg
German_Shepherd Rocky 6 http://cdn2-www.dogtime.com/assets/uploads/gallery/german-shepherd-dog-breed-pictures/standing-7.jpg
Pug Oscar 2 http://www.petwave.com/~/media/Images/Center/Breed/Dogs/Toy-Group/Pug/Pug-face-closeup.ashx
Husky Storm 10 https://vetstreet.brightspotcdn.com/dims4/default/81a2e35/2147483647/crop/0x0%2B0%2B0/resize/645x380/quality/90/?url=https%3A%2F%2Fvetstreet-brightspot.s3.amazonaws.com%2Fa9%2Ff54ad0a80611e0a0d50050568d634f%2Ffile%2FSiberian-Husky-4-645mk062811.jpg

*/
