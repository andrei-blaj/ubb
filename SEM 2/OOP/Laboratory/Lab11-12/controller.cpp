#include "controller.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

Controller::Controller() {}

std::string Controller::addDog(const std::string& breed, const std::string& name, const std::string& age, const std::string& photograph) {

    if (name == "" || breed == "" || age == "" || photograph == "") {
        return "> All fields must be filled!";
    } else if (age > "0" && age < "99") {
        Dog d = Dog{breed, name, atoi(age.c_str()), photograph};
        this -> repo.addDog(d);
        return "> Dog successfully added!";
    } else {
        return "> Invalid age!";
    }

}

std::vector <Dog> Controller::getDogList() {
    return this -> repo.getDogs();
}

std::string Controller::getDogs() {
    std::vector <Dog> dogList = this -> repo.getDogs();
    std::string allDogs;

    for (int i = 0; i < dogList.size(); i++)
        allDogs += std::to_string(i+1) + ". " + dogList[i].getName() + " | " + dogList[i].getBreed() + " | " + std::to_string(dogList[i].getAge()) + " years old.\n";

    return allDogs;
}

std::string Controller::removeDog(const std::string &dog_id) {
    std::vector <Dog> dogList = this -> repo.getDogs();

    if (dog_id == "")
        return "> All fields must be filled!";

    if (atoi(dog_id.c_str()) > dogList.size())
        return "> Inexistent dog, try a different index!";
    else {
        this -> repo.removeDog(dog_id);
        return "> Dog successfully removed!";
    }

}

std::string Controller::updateDog(const std::string& dog_id, const std::string& breed, const std::string& name, const std::string& age, const std::string& photograph) {

    if (dog_id == "" || name == "" || breed == "" || age == "" || photograph == "") {
        return "> All fields must be filled!";
    }

    if (age < "0" || age > "99")
        return "> Age must be between 0 and 99!";

    std::vector <Dog> dogList = this -> repo.getDogs();

    if (atoi(dog_id.c_str()) > dogList.size())
        return "> Inexistent dog, try a different index!";
    else {
        this -> repo.updateDog(dog_id, Dog{breed, name, atoi(age.c_str()), photograph});
        return "> Dog successfully updated!";
    }

}

std::string Controller::filter(const std::string& breed, const std::string& age) {
    std::vector <Dog> dogList = this -> repo.getDogs();
    std::string allDogs;

    int k = 0;

    for (int i = 0; i < dogList.size(); i++)
        if (dogList[i].getBreed() == breed && dogList[i].getAge() < atoi(age.c_str()))
            allDogs += std::to_string(++k) + ". " + dogList[i].getName() + " | " + dogList[i].getBreed() + " | " + std::to_string(dogList[i].getAge()) + " years old.\n";

    if (allDogs == "")
        allDogs = "No results!";

    return allDogs;
}

std::string Controller::addToAdoptionList(const Dog& d) {
    this -> al.add(d);
    return "Adoption complete!";
}

std::vector <Dog> Controller::getAdoptionList() {
    return this -> al.getAdoptionList();
}
