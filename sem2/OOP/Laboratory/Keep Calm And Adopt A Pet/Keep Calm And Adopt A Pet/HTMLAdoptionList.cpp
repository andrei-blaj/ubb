#include "HTMLAdoptionList.hpp"
#include <fstream>
#include <iostream>
#include "RepositoryException.hpp"

using namespace std;

void HTMLAdoptionList::writeToFile()
{
    ofstream f(this->filename);
    
    if (!f.is_open())
        throw FileException("The file could not be opened!");
    f << "<!DOCTYPE html><html><head><title>AdoptionList</title></head><body><table border=1>";
    for (auto d : this->dogs)
    {
        f<< "<tr>" << "<td>" << d.getBreed() << "</td>" << "<td>" << d.getName() << "</td>" << "<td><a href =" << d.getPhotograph() << ">Link</a></td>" << "</tr>";
    }
    f << "</table></body></html>";
    f.close();
}

void HTMLAdoptionList::displayAdoptionList() const
{
    //string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
   
    string command = "open " + this -> filename;
    system(command.c_str());
    
}
