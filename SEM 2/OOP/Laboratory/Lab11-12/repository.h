#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <iostream>
#include <vector>

#include "dog.h"

class Repository {
protected:
    std::vector <Dog> dogs;
    std::string filename;

public:
    Repository();

    void addDog(const Dog& d);
    void removeDog(const std::string& dog_id);
    void updateDog(const std::string& dog_id, const Dog& d);
    std::vector <Dog> getDogs();

private:
    void readFromFile();
    void writeToFile();
};

#endif // REPOSITORY_H
