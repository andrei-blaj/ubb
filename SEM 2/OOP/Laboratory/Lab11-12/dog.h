#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <cstring>

class Dog {
protected:
    std::string name;
    std::string breed;
    int age;
    std::string photograph;

public:
    Dog();
    Dog(const std::string& breed, const std::string& name, const int& age, const std::string& photograph);
    Dog(const Dog& d);

    std::string getName() const { return name; }
    std::string getBreed() const { return breed; }
    int getAge() const { return age; }
    std::string getPhotograph() const { return photograph; }

    void setName(const std::string& name);
    void setBreed(const std::string& breed);
    void setAge(const int& age);
    void setPhotograph(const std::string& photograph);

    std::string convert();

};

#endif // DOG_H
