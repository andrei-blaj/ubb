#include "CSVAdoptionList.hpp"
#include <fstream>
#include "RepositoryException.hpp"

using namespace std;

void CSVAdoptionList::writeToFile()
{
    ofstream f(this->filename);
    
    if (!f.is_open())
        throw FileException("The file could not be opened!");

    for (auto d : this -> dogs) {
        f << d.getBreed() << ", " << d.getName() << ", " << d.getAge().getYears() << ", " << d.getPhotograph() << "\n";
    }
    
    f.close();
}

void CSVAdoptionList::displayAdoptionList() const
{
    //string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
    
    string command = "open " + this -> filename;
    system(command.c_str());
    
}
